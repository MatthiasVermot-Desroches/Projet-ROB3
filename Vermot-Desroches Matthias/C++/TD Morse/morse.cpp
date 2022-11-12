//morse class definition


#include "morse.h"
#include <Arduino.h>

morse::morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

morse::morse()
{
  pinMode(LED_BUILTIN, OUTPUT);
  _pin = LED_BUILTIN;
}

void morse::point() //clignotement pour un point
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);
}

void morse::trait() // clignotement pour un trait/tiret
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

void morse::espace() // temps d'arrêt entre deux lettres 
{
  digitalWrite(_pin, LOW);
  delay(2000);
}
