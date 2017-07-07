#include "ethaddress.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QStringList>
#include <QStringListIterator>
#include <QTimer>

static QRegularExpression rx("\\b([[:xdigit:]]{1,2}[:.-]+){5}[[:xdigit:]]{1,2}\\b");
static QRegularExpression rxnl("\n|\r\n|\r");
static QRegularExpression rxip("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");


ethAddress::ethAddress(QHostAddress ip, QObject *parent)
      : QObject(parent)
      , m_ethAddress()
      , m_arp(new QProcess())
      , m_ip(ip.toString()){
      connect(m_arp, &QProcess::readyReadStandardOutput, this, &ethAddress::readStandardOutput);
      connect(m_arp, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &ethAddress::onfinished);
      m_arp->setProcessChannelMode(QProcess::MergedChannels);
      m_arp->start("arp -a");// + ip.toString());
}

ethAddress::~ethAddress(){
    if(m_arp->state() != QProcess::ProcessState::NotRunning){
        disconnect(m_arp, &QProcess::readyReadStandardOutput, this, &ethAddress::readStandardOutput);
        disconnect(m_arp, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), this, &ethAddress::onfinished);
        m_arp->kill();
        QTimer::singleShot(2000, m_arp, SLOT(deleteLater()));
    }
}

void ethAddress::readStandardOutput(){
    QString response(m_arp->readAllStandardOutput());
    QStringList query = response.split(rxnl);
    QStringListIterator si(query);
    while(si.hasNext()){
        QString line = si.next();
        QRegularExpressionMatch match = rxip.match(line);
        if(match.hasMatch()){
            QString cip = match.captured();
            if(m_ip == match.captured()){
                QRegularExpressionMatch ematch = rx.match(line);
                if(ematch.hasMatch()){
                    m_ethAddress = ematch.captured();
//                    qDebug() << "readStandardOutput kill arp " << m_ethAddress;
                    m_arp->terminate();
                    return;
                }
            }
        }
    }
}

void ethAddress::onfinished(int exitCode, QProcess::ExitStatus exitStatus){
//    qDebug() << "arp finished " << exitStatus << " exitCode " << exitCode;
    Q_UNUSED(exitCode);
    Q_UNUSED(exitStatus);
    emit ethResolved(this);
}
