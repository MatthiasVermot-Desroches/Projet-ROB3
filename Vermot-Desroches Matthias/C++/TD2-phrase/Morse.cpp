//morse class definition


#include "Morse.h"
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

morse::~morse(){}

void morse::point() //clignotement pour un point
{
  time_now = millis();
  while(millis() < time_now + 250){digitalWrite(_pin, HIGH);} 
  time_now = millis();
  while(millis() < time_now + 250){digitalWrite(_pin, LOW);} 
}

void morse::trait() // clignotement pour un trait/tiret
{
  time_now = millis();
  while(millis() < time_now + 1000){digitalWrite(_pin, HIGH);} 
  time_now = millis();
  while(millis() < time_now + 250){digitalWrite(_pin, LOW);} 
}
void morse::espace() //espace entre 2 lettres
{
  time_now = millis();
  while(millis() < time_now + 750){digitalWrite(_pin, LOW);} //un espace entre 2 lettre corresponds à 3 fois le délai entre 2 symboles
}
void morse::grandespace()//espace entre 2 mots
{
  time_now = millis();
  while(millis() < time_now + 1750){digitalWrite(_pin, LOW);} //un espace entre 2 mots corresponds à 7 fois le délai entre 2 symboles
}
