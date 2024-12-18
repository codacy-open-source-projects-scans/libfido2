/*
 * Copyright (c) 2018-2024 Yubico AB. All rights reserved.
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FIDO_PARAM_H
#define _FIDO_PARAM_H

/* Authentication data flags. */
#define CTAP_AUTHDATA_USER_PRESENT	0x01
#define CTAP_AUTHDATA_USER_VERIFIED	0x04
#define CTAP_AUTHDATA_ATT_CRED		0x40
#define CTAP_AUTHDATA_EXT_DATA		0x80

/* CTAPHID command opcodes. */
#define CTAP_CMD_PING			0x01
#define CTAP_CMD_MSG			0x03
#define CTAP_CMD_LOCK			0x04
#define CTAP_CMD_INIT			0x06
#define CTAP_CMD_WINK			0x08
#define CTAP_CMD_CBOR			0x10
#define CTAP_CMD_CANCEL			0x11
#define CTAP_KEEPALIVE			0x3b
#define CTAP_FRAME_INIT			0x80

/* CTAPHID CBOR command opcodes. */
#define CTAP_CBOR_MAKECRED		0x01
#define CTAP_CBOR_ASSERT		0x02
#define CTAP_CBOR_GETINFO		0x04
#define CTAP_CBOR_CLIENT_PIN		0x06
#define CTAP_CBOR_RESET			0x07
#define CTAP_CBOR_NEXT_ASSERT		0x08
#define CTAP_CBOR_BIO_ENROLL		0x09
#define CTAP_CBOR_CRED_MGMT		0x0a
#define CTAP_CBOR_LARGEBLOB		0x0c
#define CTAP_CBOR_CONFIG		0x0d
#define CTAP_CBOR_BIO_ENROLL_PRE	0x40
#define CTAP_CBOR_CRED_MGMT_PRE		0x41

/* Supported CTAP PIN/UV Auth Protocols. */
#define CTAP_PIN_PROTOCOL1		1
#define CTAP_PIN_PROTOCOL2		2

/* U2F command opcodes. */
#define U2F_CMD_REGISTER		0x01
#define U2F_CMD_AUTH			0x02

/* U2F command flags. */
#define U2F_AUTH_SIGN			0x03
#define U2F_AUTH_CHECK			0x07

/* ISO7816-4 status words. */
#define SW1_MORE_DATA			0x61
#define SW_WRONG_LENGTH			0x6700
#define SW_CONDITIONS_NOT_SATISFIED	0x6985
#define SW_WRONG_DATA			0x6a80
#define SW_NO_ERROR			0x9000

/* HID Broadcast channel ID. */
#define CTAP_CID_BROADCAST		0xffffffff

#define CTAP_INIT_HEADER_LEN		7
#define CTAP_CONT_HEADER_LEN		5

/* Maximum length of a CTAP HID report in bytes. */
#define CTAP_MAX_REPORT_LEN		64

/* Minimum length of a CTAP HID report in bytes. */
#define CTAP_MIN_REPORT_LEN		(CTAP_INIT_HEADER_LEN + 1)

/* Randomness device on UNIX-like platforms. */
#ifndef FIDO_RANDOM_DEV
#define FIDO_RANDOM_DEV			"/dev/urandom"
#endif

/* Maximum message size in bytes. */
#ifndef FIDO_MAXMSG
#define FIDO_MAXMSG	2048
#endif

/* CTAP capability bits. */
#define FIDO_CAP_WINK	0x01 /* if set, device supports CTAP_CMD_WINK */
#define FIDO_CAP_CBOR	0x04 /* if set, device supports CTAP_CMD_CBOR */
#define FIDO_CAP_NMSG	0x08 /* if set, device doesn't support CTAP_CMD_MSG */

/* Supported COSE algorithms. */
#define COSE_UNSPEC	0
#define COSE_ES256	-7
#define COSE_EDDSA	-8
#define COSE_ECDH_ES256	-25
#define COSE_ES384	-35
#define COSE_RS256	-257
#define COSE_RS1	-65535

/* Supported COSE types. */
#define COSE_KTY_OKP	1
#define COSE_KTY_EC2	2
#define COSE_KTY_RSA	3

/* Supported curves. */
#define COSE_P256	1
#define COSE_P384	2
#define COSE_ED25519	6

/* Supported extensions. */
#define FIDO_EXT_HMAC_SECRET	0x01
#define FIDO_EXT_CRED_PROTECT	0x02
#define FIDO_EXT_LARGEBLOB_KEY	0x04
#define FIDO_EXT_CRED_BLOB	0x08
#define FIDO_EXT_MINPINLEN	0x10

/* Supported credential protection policies. */
#define FIDO_CRED_PROT_UV_OPTIONAL		0x01
#define FIDO_CRED_PROT_UV_OPTIONAL_WITH_ID	0x02
#define FIDO_CRED_PROT_UV_REQUIRED		0x03

/* Supported enterprise attestation modes. */
#define FIDO_ENTATTEST_VENDOR	1
#define FIDO_ENTATTEST_PLATFORM	2

#ifdef _FIDO_INTERNAL
#define FIDO_EXT_ASSERT_MASK	(FIDO_EXT_HMAC_SECRET|FIDO_EXT_LARGEBLOB_KEY| \
				 FIDO_EXT_CRED_BLOB)
#define FIDO_EXT_CRED_MASK	(FIDO_EXT_HMAC_SECRET|FIDO_EXT_CRED_PROTECT| \
				 FIDO_EXT_LARGEBLOB_KEY|FIDO_EXT_CRED_BLOB| \
				 FIDO_EXT_MINPINLEN)
#endif /* _FIDO_INTERNAL */

/* Recognised UV modes. */
#define FIDO_UV_MODE_TUP	0x0001	/* internal test of user presence */
#define FIDO_UV_MODE_FP		0x0002	/* internal fingerprint check */
#define FIDO_UV_MODE_PIN	0x0004	/* internal pin check */
#define FIDO_UV_MODE_VOICE	0x0008	/* internal voice recognition */
#define FIDO_UV_MODE_FACE	0x0010	/* internal face recognition */
#define FIDO_UV_MODE_LOCATION	0x0020	/* internal location check */
#define FIDO_UV_MODE_EYE	0x0040	/* internal eyeprint check */
#define FIDO_UV_MODE_DRAWN	0x0080	/* internal drawn pattern check */
#define FIDO_UV_MODE_HAND	0x0100	/* internal handprint verification */
#define FIDO_UV_MODE_NONE	0x0200	/* TUP/UV not required */
#define FIDO_UV_MODE_ALL	0x0400	/* all supported UV modes required */
#define FIDO_UV_MODE_EXT_PIN	0x0800	/* external pin verification */
#define FIDO_UV_MODE_EXT_DRAWN	0x1000	/* external drawn pattern check */

#endif /* !_FIDO_PARAM_H */
