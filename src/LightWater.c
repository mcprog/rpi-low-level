/**********************************************************************
* Filename    : LightWater.c
* Description : Use LEDBar Graph(10 LED) 
* Author      : www.freenove.com, mcprog
* modification: 2026/04/17
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define ledCounts 10
#define DELAY 100
int pins[ledCounts] = {0,1,2,3,4,5,6,8,9,10};

void handleExit(int sig) {
	printf("Interrupt recieved, Turning off all LEDs\n");
	for (int i = 0; i < ledCounts; i++) {
		digitalWrite(pins[i], HIGH);
	}
	exit(0);
}

void updateHardware(int head, int groupSize) {
	for (int i = 0; i < ledCounts; i++) {
		if (i <= head && i > (head - groupSize)) {
			digitalWrite(pins[i], LOW);		// On
		} else {
			digitalWrite(pins[i], HIGH);	// Off
		}
	}
}

void executePingPong(int groupSize) {
	int head;
	
	for (head = groupSize - 1; head < ledCounts; head++) {
		updateHardware(head, groupSize);
		delay(DELAY);
	}
	for (head = ledCounts - 1; head > groupSize; head--) {
		updateHardware(head, groupSize);
		delay(DELAY);
	}
}

void increaseGroup(int *size) {
	while (*size < ledCounts - 1) {
		(*size)++;
		executePingPong(*size);
	}
}

void decreaseGroup(int *size) {
	while (*size > 1) {
		(*size)--;
		executePingPong(*size);
	}
}
	
void main(void)
{
	int i;
	int groupSize = 0;
	printf("Program is starting ... \n");
	
	wiringPiSetup(); //Initialize wiringPi.
	
	signal(SIGINT, handleExit);
	
	for(i=0;i<ledCounts;i++){       //Set pinMode for all led pins to output
		pinMode(pins[i], OUTPUT);
		digitalWrite(pins[i], HIGH);		
	}
	
	while(1){
		increaseGroup(&groupSize);
		decreaseGroup(&groupSize);
	}
}

