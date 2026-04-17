# Raspberry Pi Low Level Development

This repository contains C projects for the Raspberry Pi using the Freenove kit and the wiringPi library. It focuses on low level hardware interaction and efficient C programming patterns.

## Project Structure

* src: Contains all C source files.
* build: Directory for compiled executables. This folder is ignored by git.

## Hardware Configuration

Most projects in this repository utilize an Active Low configuration. In this setup, the 3.3V power source is connected directly to the components, and the Raspberry Pi GPIO pins act as the ground. This is typical for the Freenove LED Bar Graph and Common Anode RGB LED modules.

* Logic LOW: Current flows and the LED turns ON.
* Logic HIGH: No voltage difference exists and the LED turns OFF.

## Building and Running

The provided Makefile handles two types of builds depending on the project requirements.

### Standard Build
For projects that do not require multi-threading or software PWM, use the standard build path. Replace filename with the name of the C file in the src directory:

~~~bash
make build/filename
~~~

### Threaded Build
For projects using the pthread library, such as those utilizing softPwm for LED dimming or RGB control, use the thread path:

~~~bash
make thread/filename
~~~

### Execution
To execute the program after building, use sudo to ensure the program has permission to access the GPIO pins:

~~~bash
sudo ./build/filename
~~~

### Cleaning
To remove all compiled binaries and reset the build directory, run:

~~~bash
make clean
~~~

## Requirements

* Raspberry Pi with GPIO headers
* wiringPi library installed
* pthread library (Standard on Raspberry Pi OS)
* Freenove starter kit or equivalent components
