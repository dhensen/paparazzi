/*
 * Copyright (C) 2013 The Paparazzi Team
 *
 * This file is part of Paparazzi.
 *
 * Paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * Paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/**
 * @file modules/gps/gps_parrot.h
 * @brief Configure Parrot GPS
 * This is based on gps_ubx_ucenter module
 */

#ifndef GPS_PARROT_H
#define GPS_PARROT_H

extern void gps_parrot_init(void);
void gps_parrot_switch_to_sirf(void);
void gps_parrot_switch_to_5hz(void);
void gps_parrot_send_message(char *msg);

#endif /* GPS_PARROT_H */