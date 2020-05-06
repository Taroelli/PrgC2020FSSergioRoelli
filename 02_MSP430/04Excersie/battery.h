/*
 * battery.h
 *
 *  Created on: 06.05.2020
 *      Author: sergio
 */
// Define Status of Battery empty-> full
#include "driverlib.h"

#ifndef BATTERY_H_
#define BATTERY_H_

#define noLine      0   //empty Battery
#define oneLine      1   //empty Battery
#define twoLine      2   //empty Battery
#define threeLine      3   //empty Battery
#define fourLine      4   //empty Battery
#define fiveLine      5   //empty Battery
#define sixLine      6   //empty Battery


void batteryStatusChange(char batteryStatus);


#endif /* BATTERY_H_ */
