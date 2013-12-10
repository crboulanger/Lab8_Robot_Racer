/*sensor.h

//Robot Sensor Header File
//Author: Christopher Boulanger
//Created: 5 December 2013
//Description: This programs displays the functions used in the sensor program.
 * */

#include <msp430.h>

#ifndef SENSOR_H_
#define SENSOR_H_

#define LEFTDISTANCE 0x150			//Larger numbers relate to closer distances.
#define RIGHTDISTANCE 0x150			//Smaller numbers relate to further distances.

void initializeADC10();

unsigned int getLeftSensorVoltage();

unsigned int getRightSensorVoltage();

unsigned int getMiddleSensorVoltage();


#endif /* SENSOR_H_ */
