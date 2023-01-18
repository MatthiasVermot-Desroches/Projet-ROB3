const int trig = 2; //ports associés au premier capteur à ultrasons placé sur la droite du robot
const int echo = 4;
const int trig2 = 7; //ports associés au deuxième capteur à ultrasons placé sur la gauche du robot
const int echo2 = 6;

int M1B = 6; //ports associés au moteur pas encore utilisés ici
int M1A = 5;
int i = 1;
int angle = 95; //angle du servomoteur, le servomoteur va de 0 à 180° avec une erreur de précision d'environ 5°, donc l'angle par défaut est 95°
int distance_droite = 0;
int distance_gauche = 0;
#include <Servo.h>
#include "Tourner.h"
#include "Detection.h"
Servo servo1;

void setup() {
  servo1.attach(9);
  pinMode(M1B, OUTPUT);
  pinMode(M1A, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
  digitalWrite(M1B, LOW);
  analogWrite(M1A, 100);
  servo1.write(angle); //le servomoteur va à la position de l'angle par défaut
}
void loop() {
  Detection detecter;
  detecter.mesure_distance(trig, echo, trig2, echo2, distance_droite, distance_gauche);
  detecter.detection_obstacle(distance_droite, distance_gauche, angle, i, servo1);

}
