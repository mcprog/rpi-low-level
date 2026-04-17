/**********************************************************************
* Filename    : Alertor.c
* Description : Make Alertor with buzzer and button.
* Author      : www.freenove.com, mcprog
* modification: 2026/04/17
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <softTone.h>
#include <math.h>
#include <signal.h>
#include <stdlib.h>

#define buzzerPin    0  	//define the buzzerPin
#define buttonPin 	 1		//define the buttonPin

void handleExit(int sig) {
	softToneWrite(buzzerPin, 0);
	printf("\nSilencing buzzer and exiting.\n");
	exit(0);
}

void siren(int pin) {
	int x;
	double sinVal, toneVal;
	for(x=0;x<360;x++){ // frequency of the alertor is consistent with the sine wave 
		sinVal = sin(x * (M_PI / 180));		//Calculate the sine value
		toneVal = 2000 + sinVal * 500;		//Add the resonant frequency and weighted sine value 
		softToneWrite(pin,toneVal);			//output corresponding PWM
		delay(1);
	}
}
void doorbell(int pin) {
	softToneWrite(pin, 880);
	delay(500);
	softToneWrite(pin, 660);
	delay(500);
}

void chirp(int pin) {
	int x;
	int startFreq = 1000;
	int endFreq = 4000;
	int steps = 250;
	
	for (x = 0; x < steps; x++) {
		int toneVal = startFreq + (x * (endFreq - startFreq) / steps);
		softToneWrite(pin, toneVal);
		delay(2);
	}
}

void stopAlertor(int pin){
	softToneWrite(pin,0);
}
int main(int argc, char *argv[])
{
	printf("Program is starting ... \n");
	
	wiringPiSetup();
	
	signal(SIGINT, handleExit);
	
	pinMode(buzzerPin, OUTPUT); 
	pinMode(buttonPin, INPUT);
	softToneCreate(buzzerPin); //set buzzerPin
	pullUpDnControl(buttonPin, PUD_UP);  //pull up to HIGH level
	
	int choice = (argc > 1) ? atoi(argv[1]) : 0;
	printf("Starting buzzer with mode: %d\n", choice);
	
	while(1){	
		switch (choice) {
			case 1:				
				if(digitalRead(buttonPin) == LOW){ //button is pressed
					siren(buzzerPin);   // turn on buzzer
					printf("siren turned on >>> \n");
					//delay(750);
				}
				else {				//button is released 
					stopAlertor(buzzerPin);   // turn off buzzer
					printf("siren turned off <<< \n");
				}
				delay(750);
				break;
			case 2:
				if(digitalRead(buttonPin) == LOW){ //button is pressed
					doorbell(buzzerPin);   // turn on buzzer
					printf("doorbell turned on >>> \n");
					//delay(750);
				}
				else {				//button is released 
					stopAlertor(buzzerPin);   // turn off buzzer
					printf("doorbell turned off <<< \n");
				}
				delay(750);
				break;
			case 0:
			default:
				if(digitalRead(buttonPin) == LOW){ //button is pressed
					chirp(buzzerPin);   // turn on buzzer
					printf("chirp turned on >>> \n");
					//delay(750);
				}
				else {				//button is released 
					stopAlertor(buzzerPin);   // turn off buzzer
					printf("chirp turned off <<< \n");
				}
				delay(750);
				break;
		}
				
			
	}
	return 0;
}

