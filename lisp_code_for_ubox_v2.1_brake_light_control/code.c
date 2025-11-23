/*
	Copyright 2022 Benjamin Vedder	benjamin@vedder.se

	This file is part of the VESC firmware.

	The VESC firmware is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The VESC firmware is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "st_types.h"
#include "vesc_c_if.h"

#include <math.h>

HEADER

static lbm_value ext_GPIOB_3_4_init(lbm_value *args, lbm_uint argn) {
	//if (argn != 1 || !VESC_IF->lbm_is_number(args[0])) {
	//	return VESC_IF->lbm_enc_sym_eerror;
	//}
	
	VESC_IF->set_pad_mode(GPIOB, 3, PAL_STM32_MODE_OUTPUT | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
	VESC_IF->set_pad_mode(GPIOB, 4, PAL_STM32_MODE_OUTPUT | PAL_STM32_OTYPE_PUSHPULL | PAL_STM32_OSPEED_HIGHEST);
	
	return VESC_IF->lbm_enc_sym_true;
}


static lbm_value ext_set_GPIOB_3(lbm_value *args, lbm_uint argn) {
	//if (argn != 1 || !VESC_IF->lbm_is_number(args[0])) {
	//	return VESC_IF->lbm_enc_sym_eerror;
	//}
	
	VESC_IF->set_pad(GPIOB, 3);
	
	return VESC_IF->lbm_enc_sym_true;
}


static lbm_value ext_reset_GPIOB_3(lbm_value *args, lbm_uint argn) {
	//if (argn != 1 || !VESC_IF->lbm_is_number(args[0])) {
	//	return VESC_IF->lbm_enc_sym_eerror;
	//}
	
	VESC_IF->clear_pad(GPIOB, 3);
	
	return VESC_IF->lbm_enc_sym_true;
}


static lbm_value ext_set_GPIOB_4(lbm_value *args, lbm_uint argn) {
	//if (argn != 1 || !VESC_IF->lbm_is_number(args[0])) {
	//	return VESC_IF->lbm_enc_sym_eerror;
	//}
	
	VESC_IF->set_pad(GPIOB, 4);
	
	return VESC_IF->lbm_enc_sym_true;
}


static lbm_value ext_reset_GPIOB_4(lbm_value *args, lbm_uint argn) {
	//if (argn != 1 || !VESC_IF->lbm_is_number(args[0])) {
	//	return VESC_IF->lbm_enc_sym_eerror;
	//}
	
	VESC_IF->clear_pad(GPIOB, 4);
	
	return VESC_IF->lbm_enc_sym_true;
}


INIT_FUN(lib_info *info) {
	INIT_START

	(void)info;
	VESC_IF->lbm_add_extension("ext-gpiob-3-4-init", ext_GPIOB_3_4_init);
	VESC_IF->lbm_add_extension("ext-set-gpiob-3", ext_set_GPIOB_3);
	VESC_IF->lbm_add_extension("ext-reset-gpiob-3", ext_reset_GPIOB_3);
	VESC_IF->lbm_add_extension("ext-set-gpiob-4", ext_set_GPIOB_4);
	VESC_IF->lbm_add_extension("ext-reset-gpiob-4", ext_reset_GPIOB_4);
		
	return true;
}

