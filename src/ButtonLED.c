/**********************************************************************
* Filename    : ButtonLED.c
* Description : Control led by button.
* Author      : www.freenove.com, mcprog
* modification: 2026/04/17
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define ledPin    0  	//define the ledPin
#define buttonPin 1		//define the buttonPin

void  main(void)
{
	printf("Program is starting ... \n");
	
	wiringPiSetup();	//Initialize wiringPi.	
	
	pinMode(ledPin, OUTPUT); //Set ledPin to output
	pinMode(buttonPin, INPUT);//Set buttonPin to input

	pullUpDnControl(buttonPin, PUD_UP);  //pull up to HIGH level
	
	unsigned long startTime = millis();
	unsigned long interval = 2000;
	
	while(1){
		if(digitalRead(buttonPin) == LOW){ //button is pressed 
			digitalWrite(ledPin, HIGH);  //Make GPIO output HIGH level
			if (millis() - startTime >= interval) {
				printf("Button is pressed, led turned on >>>\n");		//Output information on terminal
				startTime = millis();
			}
		}
		else {							//button is released 
			digitalWrite(ledPin, LOW);  //Make GPIO output LOW level
			if (millis() - startTime >= interval) {
				printf("Button is released, led turned off <<<\n");		//Output information on terminal
				startTime = millis();
			}
		}
	}
}

