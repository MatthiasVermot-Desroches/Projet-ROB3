//morse code blink on the LED_BUILTIN

#include <Arduino.h>
#include "morse.h"
#include "traducteur.h"

morse m=morse(LED_BUILTIN);
char mot[1024]
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cout<<"entrez un mot ou une lettre";
  cin>>mot;
  traducteur::traduiremot(mot);
  traducteur::action(mot);
}