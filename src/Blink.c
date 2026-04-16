/**********************************************************************
* Filename    : Blink.c
* Description : Basic usage of GPIO. Let led blink.
* auther      : www.freenove.com
* modification: 2019/12/26
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#define  ledPin     0	//define the led pin number
#define DOT         60
#define DASH        120
#define SPACE       200

void handleExit(int sig) {
    printf("Handling program interrupt (%d)\n", sig);
    
    digitalWrite(ledPin, LOW);
    
    exit(0);
}

void blinkLong(void) {
    printf("Blinking long\n");
    fflush(stdout);
    digitalWrite(ledPin, HIGH);  //Make GPIO output HIGH level
    delay(DASH);
    digitalWrite(ledPin, LOW);  //Make GPIO output LOW level
    delay(SPACE);	
}

void blinkShort(void) {
    printf("Blinking short\n");
    fflush(stdout);
    digitalWrite(ledPin, HIGH);  //Make GPIO output HIGH level
    delay(DOT);
    digitalWrite(ledPin, LOW);  //Make GPIO output LOW level
    delay(SPACE);	
}

void main(void)
{	
	printf("Custom Program is starting ... \n");
	
	wiringPiSetup();	//Initialize wiringPi.
    
    signal(SIGINT, handleExit);
	
	pinMode(ledPin, OUTPUT);//Set the pin mode
	printf("Using pin%d\n",ledPin);	//Output information on terminal
	while(1){
		blinkLong();
        blinkLong();
        blinkLong();
        blinkShort();
        blinkShort();
        blinkShort();
        blinkLong();
        blinkLong();
        blinkLong();
        printf("Sequence complete\n");
        fflush(stdout);
        delay(2000);
	}
}



