/*
 *   Copyright (C) 2022 by Jim KI6ZUM, Lauren KJ6KDZ
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define FSSB9  &FreeSansBold9pt7b
#define FSSB18 &FreeSansBold18pt7b
#define GFXFF 1

// Below are tables of the info on where and how to display the text on the background
// for each mode.  It includes the font, color, size, x/y position and background color
// It matches that info to the specific message coming from mmdvmhost. 

typedef struct {
char name[20];
const GFXfont * font;
uint16_t max_width;
uint16_t x;
uint16_t y;
uint16_t color_font;
uint16_t color_background;
} element;

element pageMMDVM[] {
 {"t0", FSSB18, 280, 19, 116, WHITE, 0x11ac},  // callsign/DMR ID
 {"t1", FSSB9, 285, 20, 85, WHITE, 0x11ac}, // status
 {"t2", FSSB9, 150, 56, 213, WHITE, 0x11ac}, // time/date
 {"t3", FSSB9, 175, 35, 185, WHITE, 0x11ac}, // IP address
 {"t30", FSSB9, 100, 45, 159, WHITE, 0x11ac},  // RX
 {"t32", FSSB9, 100, 205, 159, WHITE, 0x11ac},  // TX
 {"", 0, 0, 0, 0}
};

element pageDMR[] {
 {"t0", FSSB18, 280, 19, 105, WHITE, 0x11ac},  // callsign/DMR ID
 {"t2", FSSB18, 280, 19, 105, WHITE, 0x11ac}, // callsign
 {"t3", FSSB9, 80, 40, 146, WHITE, 0x11ac}, // TG
 {"t5", FSSB9, 60, 215, 170, WHITE, 0x11ac}, // RSSI
 {"t7", FSSB9, 60, 55, 170, WHITE, 0x11ac}, // BER
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"rx", FSSB9, 80, 160, 45, WHITE, 0x11ac}, // rx frequency
 {"country", FSSB9, 285, 18, 74, WHITE, 0x11ac}, // t1000 is country name
 {"onair", FSSB9, 65, 252, 45, RED, 0x8E3C}, // t1001 is on air flag ( #8EC5E7/0x8E3C is background color)
 {"ip", FSSB9, 175, 40, 193, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 40, 100, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
 };

element pageDSTAR[] {
 {"t0", FSSB18, 280, 19, 105, WHITE, 0x11ac},  // callsign
 {"t1", FSSB9, 80, 50, 146, WHITE, 0x11ac}, // YR
 {"t2", FSSB9, 80, 195, 146, WHITE, 0x11ac}, // RT
 {"t3", FSSB9, 60, 215, 170, WHITE, 0x11ac}, // RSSI
 {"t4", FSSB9, 60, 55, 170, WHITE, 0x11ac}, // BER
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"rx", FSSB9, 80, 160, 45, WHITE, 0x11ac}, // rx frequency
 {"country", FSSB9, 285, 18, 74, WHITE, 0x11ac}, // t1000 is country name
 {"onair", FSSB9, 65, 252, 45, RED, 0x8E3C}, // t1001 is on air flag
 {"ip", FSSB9, 175, 40, 193, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 40, 100, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
 };

element pageP25[] {
 {"t0", FSSB18, 280, 19, 105, WHITE, 0x11ac},  // callsign
 {"t1", FSSB9, 80, 50, 146, WHITE, 0x11ac}, // DST
 {"t2", FSSB9, 60, 215, 170, WHITE, 0x11ac}, // RSSI
 {"t3", FSSB9, 60, 55, 170, WHITE, 0x11ac}, // BER
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"rx", FSSB9, 80, 160, 45, WHITE, 0x11ac}, // rx frequency
 {"country", FSSB9, 285, 18, 74, WHITE, 0x11ac}, // t1000 is country name
 {"onair", FSSB9, 65, 252, 45, RED, 0x8E3C}, // t1001 is on air flag
 {"ip", FSSB9, 175, 40, 193, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 40, 100, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
};

element pageNXDN[] {
 {"t0", FSSB18, 280, 19, 105, WHITE, 0x11ac},  // callsign
 {"t1", FSSB9, 80, 50, 146, WHITE, 0x11ac}, // TG
 {"t2", FSSB9, 60, 215, 170, WHITE, 0x11ac}, // RSSI
 {"t3", FSSB9, 60, 55, 170, WHITE, 0x11ac}, // BER
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"rx", FSSB9, 80, 160, 45, WHITE, 0x11ac}, // rx frequency
 {"country", FSSB9, 285, 18, 74, WHITE, 0x11ac}, // t1000 is country name
 {"onair", FSSB9, 65, 252, 45, RED, 0x8E3C}, // t1001 is on air flag
 {"ip", FSSB9, 175, 40, 193, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 40, 100, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
};

element pageYSF[] {
 {"t0", FSSB18, 280, 19, 105, WHITE, 0x11ac},  // callsign
 {"t1", FSSB9, 80, 200, 146, WHITE, 0x11ac}, // DST
 {"t2", FSSB9, 80, 50, 146, WHITE, 0x11ac}, // SRC
 {"t3", FSSB9, 60, 215, 170, WHITE, 0x11ac}, // RSSI
 {"t4", FSSB9, 60, 55, 170, WHITE, 0x11ac}, // BER
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"rx", FSSB9, 80, 160, 45, WHITE, 0x11ac}, // rx frequency
 {"country", FSSB9, 285, 18, 74, WHITE, 0x11ac}, // t1000 is country name
 {"onair", FSSB9, 65, 252, 45, RED, 0x8E3C}, // t1001 is on air flag
 {"ip", FSSB9, 175, 40, 193, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 40, 100, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
};

element pageM17[] {
 {"t0", FSSB18, 280, 19, 105, WHITE, 0x11ac}, // SRC
 {"t1", FSSB9,  80, 50, 146, WHITE, 0x11ac}, // DST
 {"t2", FSSB9, 60, 215, 170, WHITE, 0x11ac}, // RSSI
 {"t3", FSSB9, 60, 55, 170, WHITE, 0x11ac}, // BER
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"rx", FSSB9, 80, 160, 45, WHITE, 0x11ac}, // rx frequency
 {"country", FSSB9, 285, 18, 74, WHITE, 0x11ac}, // t1000 is country name
 {"onair", FSSB9, 65, 252, 45, RED, 0x8E3C}, // t1001 is on air flag
 {"ip", FSSB9, 175, 40, 193, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 80, 100, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
};

element pagePOCSAG[] {
 {"t0", FSSB9, 280, 19, 43, WHITE, 0x11ac},  // ric
 {"t1", FSSB9, 285, 17, 75, WHITE, 0x11ac}, // Message
 {"tx", FSSB9, 80, 160, 13, WHITE, 0x11ac}, // tx frequency
 {"ip", FSSB9, 175, 40, 191, WHITE, 0x11ac}, // IP address
 {"time", FSSB9, 80, 56, 218, WHITE, 0x11ac}, // timeout is 3:00 minute timer
 {"", 0, 0, 0, 0}
};

