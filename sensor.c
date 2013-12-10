/*sensor.c

//Robot Sensor
//Author: Christopher Boulanger
//Created: 5 December 2013
//Description: This programs implements Analog to digital conversion.
 * Serves as implementation for my robot's sensors
 */
//Documentation: Used Captain Branchflower's Lesson 36 Example code as as starting point.
//Worked with C2C Mossing

#include "sensor.h"

void initializeADC10(){
	ADC10CTL0=ADC10SHT_3+ADC10ON+ADC10IE;  	// ADC10ON, interrupt enabled
	ADC10CTL1=ADC10DIV_7;

	ADC10AE0 |= BIT3|BIT4|BIT5;				//interrupt pins
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;		// Select SMCLK
}

unsigned int getLeftSensorVoltage(){
	ADC10CTL0 &= ~ENC;						//disable interrupts to change stuff
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_3; 					//input channel # A3

	ADC10CTL0 |= ENC + ADC10SC;				//sampling
	__bis_SR_register(CPUOFF+GIE);			//set interrupts back on

	return ADC10MEM;
}

unsigned int getRightSensorVoltage(){
		ADC10CTL0 &= ~ENC;						//disable interrupts to change stuff
		ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
		ADC10CTL1 |= INCH_4; 					//input channel # A4

		ADC10CTL0 |= ENC + ADC10SC;				//sampling
		__bis_SR_register(CPUOFF+GIE);			//set interrupts back on

		return ADC10MEM;
}

unsigned int getMiddleSensorVoltage(){
		ADC10CTL0 &= ~ENC;						//disable interrupts to change stuff
		ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
		ADC10CTL1 |= INCH_5; 					//input channel # A4

		ADC10CTL0 |= ENC + ADC10SC;				//sampling
		__bis_SR_register(CPUOFF+GIE);			//set interrupts back on

		return ADC10MEM;
}
//initialize ADC10
   // ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
    //ADC10CTL1 = INCH_4;                       	// input A4
    //ADC10AE0 |= BIT4;                         	// PA.1 ADC option select
    //ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;         // Select SMCLK

    //set output pins for LED
    //P1DIR |= 0x01;                           	 // Set P1.0 to output direction
    //P1DIR |= BIT6;								// Set P1.6 to output direction



