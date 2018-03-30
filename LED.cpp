/*
 * Created by Thomas Linner
 * 
 * This file is part of the LED - Library
 * This library is used for better and easier control of LEDs
 */

// Include Header - File
#include "LED.h"

///////////////////////////////////////////////////
///////             CONSTRUCTOR             ///////
///////////////////////////////////////////////////

 /*
  * Default - Constructor
  *  - set Pin to 0
  *  - configure IO
  */
LED::LED()
{
  LED::setPin(0); 
}

/*
 * Constructor
 *  - set Pin to given pin
 *  - configure IO
 *  
 *  @param pin: Pin to set the LED to 
 */
LED::LED(uint8_t pin)
{
  LED::setPin(pin);
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
  LED::pin = pin;

  pinMode(pin, OUTPUT);
}

///////////////////////////////////////////////////
///////           STATE - METHODS           ///////
///////////////////////////////////////////////////

/*
 * Switch state to on
 */
void LED::on()
{
  LED::state = LED_STATE_ON;

  digitalWrite(LED::pin, LED::state);
}

/*
 * Switch state to off
 */
void LED::off()
{
  LED::state = LED_STATE_OFF;

  digitalWrite(LED::pin, LED::state);
}

/*
 * Toggle state
 *  - on     ->    off
 *  - off    ->    on
 */
void LED::toggle()
{
  LED::state = !LED::state;

  digitalWrite(LED::pin, LED::state);
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
   LED::toggle();

   delay(duration);

   LED::toggle();
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
    LED::flash(duration);

    delay(duration);
  }
}
