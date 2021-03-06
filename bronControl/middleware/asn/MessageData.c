/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "OTACommProtocolModule"
 * 	found in "../BronComm.asn"
 */

#include "MessageData.h"

static asn_TYPE_member_t asn_MBR_MessageData_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct MessageData, choice.mgi),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"mgi"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MessageData, choice.mgs),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NULL,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"mgs"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MessageData, choice.ms),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MessageSetParameter,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"ms"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MessageData, choice.mr),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MessageResult,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"mr"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct MessageData, choice.me),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MessageError,
		0,	/* Defer constraints checking to the member type */
		0,	/* PER is not compiled, use -gen-PER */
		0,
		"me"
		},
};
static asn_TYPE_tag2member_t asn_MAP_MessageData_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* mgi at 13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mgs at 14 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ms at 15 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* mr at 16 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* me at 18 */
};
static asn_CHOICE_specifics_t asn_SPC_MessageData_specs_1 = {
	sizeof(struct MessageData),
	offsetof(struct MessageData, _asn_ctx),
	offsetof(struct MessageData, present),
	sizeof(((struct MessageData *)0)->present),
	asn_MAP_MessageData_tag2el_1,
	5,	/* Count of tags in the map */
	0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_MessageData = {
	"MessageData",
	"MessageData",
	CHOICE_free,
	CHOICE_print,
	CHOICE_constraint,
	CHOICE_decode_ber,
	CHOICE_encode_der,
	CHOICE_decode_xer,
	CHOICE_encode_xer,
	0, 0,	/* No PER support, use "-gen-PER" to enable */
	CHOICE_outmost_tag,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	0,	/* No PER visible constraints */
	asn_MBR_MessageData_1,
	5,	/* Elements count */
	&asn_SPC_MessageData_specs_1	/* Additional specs */
};

