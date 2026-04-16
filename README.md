# Raspberry Pi Low-Level Development

This repository contains C projects for the Raspberry Pi using the Freenove kit and the wiringPi library.

## Project Structure

* src: Contains all C source files.
* build: Directory for compiled executables.

## Hardware Configuration

Most projects in this repository utilize an Active Low configuration. In this setup, the 3.3V power source is connected directly to the components, and the Raspberry Pi GPIO pins act as the ground.

* Logic LOW: LED turns ON
* Logic HIGH: LED turns OFF

## Building and Running

To compile a project, use the provided Makefile. Replace filename with the name of the C file in the src directory:

make build/filename

To execute the program, use sudo:

sudo ./build/filename

## Requirements

* Raspberry Pi with GPIO headers
* wiringPi library installed
* Freenove starter kit or equivalent components
