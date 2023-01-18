const int trig = 2; //ports associés au premier capteur à ultrasons
const int echo = 4;
const int trig2 = 7; //ports associés au deuxième capteur à ultrasons
const int echo2 = 6;

int M1B = 6; //ports associés au premier moteur placé sur la droite du robot
int M1A = 5;
int M2A = 9; //ports associés au deuxième moteur placé sur la gauche du robot
int M2B = 10;
int i = 5;
int distance_droite = 0;
int distance_gauche = 0;
int vitesse_droite = 100; //vitesse par défaut du moteur de droite, la valeur est choisie arbitrairement pour l'instant
int vitesse_gauche = 100; //vitesse par défaut du moteur de gauche, la valeur est choisie arbitrairement pour l'instant
#include <Servo.h>
#include "Tourner.h"
#include "Detection.h"
Servo servo1;

void setup() {
  servo1.attach(9);
  pinMode(M1B, OUTPUT);
  pinMode(M1A, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
  digitalWrite(M1B, LOW);
  digitalWrite(M2B, LOW);
  analogWrite(M1A, vitesse_droite); // Les ports M1A et M2A sont sur des ports PWD de la carte Arduino, nous pouvons donc faire varier leur vitesse à une valeur précise (entre 0 et 255)
  analogWrite(M2A, vitesse_gauche);
  
}
void loop() {
  Detection detecter;
  Tourner tourne;
  tourne.controle_vitesses_limites(vitesse_droite,vitesse_gauche);
  detecter.mesure_distance(trig, echo, trig2, echo2, distance_droite, distance_gauche);
  detecter.detection_obstacle(distance_droite, distance_gauche, vitesse_droite, vitesse_gauche, i, M1A, M2A);

}
