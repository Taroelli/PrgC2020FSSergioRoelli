/*
 * battery.c
 *
 *  Created on: 06.05.2020
 *      Author: sergio
 */

#include "battery.h"

void batteryStatusChange(char batteryStatus)
{
    switch(batteryStatus)
        {
            case noLine:
                        LCDM12 = 0x10;
                        LCDM13 = 0x01;
                        break;
            case oneLine:
                        LCDM12 = 0x10;
                        LCDM13 = 0x03;
                        break;
            case twoLine:
                        LCDM12 = 0x30;
                        LCDM13 = 0x03;
                        break;
            case threeLine:
                        LCDM12 = 0x30;
                        LCDM13 = 0x07;
                        break;
            case fourLine:
                        LCDM12 = 0x70;
                        LCDM13 = 0x07;
                        break;
            case fiveLine:
                        LCDM12 = 0x70;
                        LCDM13 = 0x0F;
                        break;
            case sixLine:
                        LCDM12 = 0xF0;
                        LCDM13 = 0x0F;
                        break;
        }
}



