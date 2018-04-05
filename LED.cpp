/*
 * Created by Thomas Linner
 * 
 * This file is part of the LED - Library
 * This library is used for better and easier control of LEDs
 * 
 * For more information take a look at: https://github.com/Linner-Thomas/Arduino_LED
 */

// Include Header - File
#include "LED.h"

///////////////////////////////////////////////////
///////             CONSTRUCTOR             ///////
///////////////////////////////////////////////////

/*
 * Constructor
 *  - set Pin to given pin (default: 0)
 *  - configure IO
 *  
 *  @param pin: Pin to set the LED to 
 */
LED::LED(uint8_t pin = 0)
{
  this->setPin(pin);
}

///////////////////////////////////////////////////
///////     GETTER - / SETTER - METHODS     ///////
///////////////////////////////////////////////////

/*
 * Setter - Pin
 *  - set Pin to a given pin
 *  - configure IO
 *  
 *  @param pin: Pin to set the LED to
 */
void LED::setPin(uint8_t pin)
{
  this->pin = pin;

  pinMode(this->pin, OUTPUT);
}

///////////////////////////////////////////////////
///////           STATE - METHODS           ///////
///////////////////////////////////////////////////

/*
 * Switch state to on
 */
void LED::on()
{
  this->state = LED_STATE_ON;

  digitalWrite(this->pin, this->state);
}

/*
 * Switch state to off
 */
void LED::off()
{
  this->state = LED_STATE_OFF;

  digitalWrite(this->pin, this->state);
}

/*
 * Toggle state
 *  - on     ->    off
 *  - off    ->    on
 */
void LED::toggle()
{
  this->state = !this->state;

  digitalWrite(this->pin, this->state);
}

///////////////////////////////////////////////////
///////           FLASH - METHODS           ///////
///////////////////////////////////////////////////

/*
 * Flash the LED for a given period of time
 * 
 * @param duration: The duration of the flash
 */
void LED::flash(uint16_t duration)
{
   this->toggle();

   delay(duration);

   this->toggle();
}

/*
 * Flash the LED a given amount of times for a given period of time
 * 
 * @param duration: The duration of the flash
 * @param pulses:   The amount of pulses
 */
void LED::flash(uint16_t duration, uint8_t pulses)
{
  for (int pulse = 0; pulse < pulses; pulse ++)
  {
    this->flash(duration);

    delay(duration);
  }
}
