# Soldering iron firmware

The firmware is written in C++ without any other library than avr-libc. The firmware is splitted in three layers, which are : HAL, Core, and Application. The entry point of the application is main.cpp.

## HAL

This is the hardware abtraction layer. This is the layer where we make direct interfacing with the hardware. We shouldn't tweak any register beyond that layer.
The HAL layers features currently 3 drivers :

 * I2C driver
 * SSD1306 driver, which uses I2C driver
 * I/O driver (**WIP**)

## Core layer

This is the layer where we exploit what the HAL gives. Shouldn't be too low level nor high level. You'll find :

 * Framebuffer (**WIP**)
 * Buttons listener (**WIP**)
 * Thermocouple manager (**WIP**)
 * Heater manager (**WIP**)
 * Timer (**WIP**)

## Application layer

This is basically where we do all the high level stuff : PID, user interface, etc. ; in a nutshell gluing everything together.