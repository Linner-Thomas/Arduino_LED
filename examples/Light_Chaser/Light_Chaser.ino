/*
 * Created by Thomas Linner
 * 
 * This file is a small example for a usage of the LED - Library
 * It shows the implementation of a light chaser
 */

// Include LED - Library
#include "LED.h"

// Define constant for size of array
const uint8_t SIZE = 8;

// Declare LED - Array
LED LEDs[SIZE];

void setup() 
{
  // Initialize LEDs
  for (uint8_t index = 0; index < SIZE; index ++)
    LEDs[index].setPin(index);
}

void loop() 
{
  // Light chaser
  for (LED LED : LEDs)
    LED.flash(500);
}
