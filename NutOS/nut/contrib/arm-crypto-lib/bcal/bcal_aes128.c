/* bcal_aes128.c */
/*
    This file is part of the ARM-Crypto-Lib.
    Copyright (C) 2006-2010  Daniel Otte (daniel.otte@rub.de)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * \file     bcal_aes128.c
 * \email    daniel.otte@rub.de
 * \author   Daniel Otte 
 * \date     2009-01-08
 * \license  GPLv3 or later
 * 
 */

#include <stdlib.h>
#include <crypto/blockcipher_descriptor.h>
#include <crypto/aes.h>
#include <crypto/aes128_enc.h>
#include <crypto/aes128_dec.h>
#include <crypto/aes_keyschedule.h>
#include <crypto/keysize_descriptor.h>

const char aes128_str[]  = "AES-128";

const uint8_t aes128_keysize_desc[]  = { KS_TYPE_LIST, 1, KS_INT(128),
                                         KS_TYPE_TERMINATOR    };

const bcdesc_t aes128_desc = {
	BCDESC_TYPE_BLOCKCIPHER,
	BC_INIT_TYPE_1,
	aes128_str,
	sizeof(aes128_ctx_t),
	128,
	{(void_fpt)aes128_init},
	{(void_fpt)aes128_enc},
	{(void_fpt)aes128_dec},
	(bc_free_fpt)NULL,
	aes128_keysize_desc
};

