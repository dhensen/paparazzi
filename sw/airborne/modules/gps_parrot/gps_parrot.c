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

#include "gps_parrot.h"
#include "mcu_periph/uart.h"
#include <stdio.h>
#include <string.h>

#define GpsParrotSwitchToSirf() gps_parrot_switch_to_sirf()

//A0 A2 00 0E 88 00 00 04 04 00 00 00 00 00 00 00 0F 02 00 A1 B0 B3
#define GpsParrotSendSwitch5Hz() { \
  UART1Transmit(0xa0);\
  UART1Transmit(0xa2);\
  UART1Transmit(0x00);\
  UART1Transmit(0x0e);\
  UART1Transmit(0x88);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x04);\
  UART1Transmit(0x04);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x00);\
  UART1Transmit(0x0f);\
  UART1Transmit(0x02);\
  UART1Transmit(0x00);\
  UART1Transmit(0xa1);\
  UART1Transmit(0xb0);\
  UART1Transmit(0xb3);\
}

void gps_parrot_init(void)
{
  // switch to 5Hz mode
//  GpsParrotSendSwitch5Hz();
  gps_parrot_switch_to_5hz();

  // switch to SiRF binary
  GpsParrotSwitchToSirf();

  // set baudrate 57600
  UART1SetBaudrate(B57600);
}

void gps_parrot_switch_to_5hz(void)
{
  char msg[] = "$PSRF103,00,6,00,0*23\r\n";
  int length = strlen(msg);
  for (int i = 0; i < length; i++) {
    UART1Transmit(msg[i]);
    printf("[%X]\n", msg[i]);
  }

}

void gps_parrot_switch_to_sirf(void)
{
  char msg[] = "$PSRF100,0,57600,8,1,0*37\r\n";
  int length = strlen(msg);
  for (int i = 0; i < length; i++) {
    UART1Transmit(msg[i]);
    printf("[%X]\n", msg[i]);
  }

}

