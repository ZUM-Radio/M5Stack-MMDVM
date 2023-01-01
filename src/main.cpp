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

#include <Arduino.h>
#include <M5Stack.h>

extern void testModes(void);
extern void changePage(uint8_t * newPage);
extern void displayField(uint8_t * newPage);
extern void screenInit(void);
void testCountries(void);

void setup() 
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  //Serial.println("usb start");
  
  // // serial port on M5Stack is 16 (RX_PIN) and 17 (TX_PIN
  #define RX_PIN 16
  #define TX_PIN 17
  Serial2.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  //Serial port 2 initialization
  //Serial.println("start");

  screenInit();

//  testCountries();

//  testModes();

}

void loop()
{

char rxbuf[100];
bool packet;
int index;

index=0;
packet=false;
  while (1) {
    if (Serial2.available()>0) {
      rxbuf[index++]=Serial2.read();
      if (index>4) {
        // if last 3 bytes are 0xff then that is the end of the packet found
        if ((rxbuf[index-3] == 0xff) && (rxbuf[index-2] == 0xff) && (rxbuf[index-1] == 0xff) ) {
          packet=true;
        }
      } else if (index > 99) {
        // reset to begining looking for packet because of overflow?
        index=0; 
        packet=false;
      }
      
      // packet will look something like this:  t2.txt="2 Listening"  or  page DMR
      if (packet==true) {
        rxbuf[index-3] = 0;
        if ((strncmp(rxbuf, "click", 5) == 0) || 
            (strncmp(rxbuf, "dim", 3) == 0) ||
            (strncmp(rxbuf, "MMDVM", 5) == 0)) {
          // found click/dim/status
          // for now ignore these packets
        }
        else if (strncmp(rxbuf, "page ", 5) == 0) { // found page change
          //Serial.print("|");
          //Serial.println(rxbuf);
          changePage((uint8_t *)rxbuf);
        }
        else { // found text field data to display
//          //Serial.print('~');
//          //Serial.println(rxbuf);
          displayField((uint8_t *)rxbuf);
        }

        index=0; 
        packet=false;
      }
    }
  } // end loop forever

}
