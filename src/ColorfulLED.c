/**********************************************************************
* Filename    : ColorfulLED.c
* Description : Random color change ColorfulLED
* Author      : www.freenove.com, mcprog
* modification: 2026/04/17
**********************************************************************/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>

#define ledPinRed    0
#define ledPinGreen  1
#define ledPinBlue   2
#define COLOR_DELAY     350
#define RESET_DELAY     1000
#define EXIT_DELAY      200

typedef struct {
	int r;
	int g;
	int b;
} Color;

Color palette[24] = {
    {100, 0, 0},    // 0: Pure Red
    {100, 40, 0},   // 1: Orange
    {100, 70, 0},   // 2: Amber/Gold
    {100, 100, 0},  // 3: Yellow
    {60, 100, 0},   // 4: Chartreuse
    {30, 100, 0},   // 5: Lime
    {0, 100, 0},    // 6: Pure Green
    {0, 100, 30},   // 7: Spring Green
    {0, 100, 60},   // 8: Aquamarine
    {0, 100, 100},  // 9: Cyan
    {0, 70, 100},   // 10: Azure
    {0, 35, 100},   // 11: Sky Blue
    {0, 0, 100},    // 12: Pure Blue
    {25, 0, 100},   // 13: Indigo
    {50, 0, 100},   // 14: Violet
    {75, 0, 100},   // 15: Purple
    {100, 0, 100},  // 16: Magenta
    {100, 0, 50},   // 17: Raspberry
    {100, 20, 40},  // 18: Rose
    {100, 50, 60},  // 19: Light Pink
    {80, 0, 20},    // 20: Crimson
 
    // Whites and Special States
    {90, 100, 100}, // 21: Cold White (Blue-tinted)
    {100, 85, 45},  // 22: Warm White (Yellow/Red-tinted)
    {0, 0, 0}       // 23: Off
};

void setupLedPin(void)
{
	softPwmCreate(ledPinRed,  0, 100);	//Creat SoftPWM pin for red
	softPwmCreate(ledPinGreen,0, 100);  //Creat SoftPWM pin for green
	softPwmCreate(ledPinBlue, 0, 100);  //Creat SoftPWM pin for blue
}

void setLedColor(Color c)
{
	softPwmWrite(ledPinRed,   100 - c.r);	//Set the duty cycle 
	softPwmWrite(ledPinGreen, 100 - c.g);   //Set the duty cycle 
	softPwmWrite(ledPinBlue,  100 - c.b);   //Set the duty cycle 
}

void handleExit(int sig) {
	printf("Turning led off\n");
	setLedColor(palette[23]);
	delay(EXIT_DELAY);
	
	exit(0);
}

int main(void)
{
	
	printf("Program is starting ...\n");
	
	wiringPiSetup();	//Initialize wiringPi.
	
	signal(SIGINT, handleExit);
	
	setupLedPin();
	while(1){
		for (int i = 0; i < 24; i++) {
            setLedColor(palette[i]);
            delay(COLOR_DELAY);
		}
        delay(RESET_DELAY);
	}
	return 0;
}
