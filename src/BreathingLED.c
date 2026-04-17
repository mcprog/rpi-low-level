/**********************************************************************
* Filename    : BreathingLED.c
* Description : Make breathing LED with PWM
* Author      : www.freenove.com
* modification: 2019/12/27
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <signal.h>
#include <stdlib.h>

#define ledPin    	1 
#define maxStep		10

void handleExit(int sig) {
	digitalWrite(ledPin, LOW);
	
	exit(0);	
}

void main(void)
{
	int i;
	int step = 1;
	
	
	printf("Program is starting ... \n");
	
	wiringPiSetup();	//Initialize wiringPi.
	
	signal(SIGINT, handleExit);
	
	softPwmCreate(ledPin,  0, 100);//Creat SoftPWM pin
	
	while(1){
		
		for(i=0;i<100;i+=step){  //make the led brighter
			softPwmWrite(ledPin, i); 
			delay(20);
		}
		delay(300);
		for(i=100;i>=0;i-=step){  //make the led darker
			softPwmWrite(ledPin, i);
			delay(20);
		}
		delay(300);
		if (step > maxStep) {
			step = 1;
		} else {
			step++;
		}
	}
}

