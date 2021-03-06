/*
 * Created by Thomas Linner
 * 
 * This file is part of the LED - Library
 * This library is used for better and easier control of LEDs
 * 
 * For more information take a look at: https://github.com/Linner-Thomas/Arduino_LED
 */

///////////////////////////////////////////////////
///////           PRE - PROCESSOR           ///////
///////////////////////////////////////////////////

// Check if Class is allready included
#ifndef LED_h
#define LED_h

// Include Arduino.h
#include <Arduino.h>

// Define constants for states
#define LED_STATE_ON  HIGH
#define LED_STATE_OFF LOW

///////////////////////////////////////////////////
///////                CLASS                ///////
///////////////////////////////////////////////////

class LED
{
  private:
    uint8_t pin;
    boolean state;

  public:
    LED(uint8_t pin = 0);
    
    void setPin(uint8_t pin);

    void on();
    void off();
    void toggle();

    void flash(uint16_t duration);
    void flash(uint16_t duration, uint8_t pulses);
};

#endif
