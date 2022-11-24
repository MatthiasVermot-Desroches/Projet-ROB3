
#include <Arduino.h>
#include "Morse.h"
#include "Traducteur.h"

morse m(LED_BUILTIN);
char mot[50]= "je programme avec plaisir";
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  traducteur traducteur(LED_BUILTIN); //13=ledbuilting
  traducteur.rafraichir_trad(); 
  //Cette commande sert dans le cas où l'on change de phrase à traduire.
  //Si l'on change de phrase sans la faire, la LED fera d'abord le code morse de la phrase précédente une fois avant de vider correctement le tableau avec le detructeur
  //Ce problème "pourrait" être éviter si la carte était déconnectée à l'instant exact où la traduction se termine, c'est-à-dire à l'instant où le tableau trad est vidé (probablement à la millisecondes près...).
  traducteur.traduiremot(mot);
  traducteur.action();
  Serial.println(traducteur.trad);
}
