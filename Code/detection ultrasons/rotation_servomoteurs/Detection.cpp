#include <Arduino.h>
#include "Detection.h"
#include <Servo.h>

Detection::Detection(){}

Detection::~Detection(){}

void Detection::mesure_distance(int trig, int echo, int trig2, int echo2, int &distance_droite, int &distance_gauche) //fonction ayant pour but d'utiliser les capteurs à ultrasons
// afin de mesurer les distances entre le robot et un obstacle à gauche et à droite
{
  digitalWrite(trig,HIGH); //le port trig du capteur lance un ultrason
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  distance_droite = pulseIn(echo,HIGH)/2*0.034; // echo prends le temps de l'aller-retour de l'ultrason, on convertit ce temps en distance en mm.
  digitalWrite(trig2,HIGH);// même opération pour le second capteur
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  distance_gauche = pulseIn(echo2,HIGH)/2*0.034;
  Serial.print("Distance à gauche :");
  Serial.println(distance_gauche);
  Serial.print("Distance à droite :");
  Serial.println(distance_droite);
}

void Detection::detection_obstacle(int &distance_droite, int &distance_gauche, int &angle, int i, Servo servo1)
{
  if (distance_droite > 10 and distance_gauche > 10){
    tourner.toutdroit(angle, servo1); //si les obstacles sont trop loins; il n'y a pas besoin de tourner
  }
  else if (distance_droite > distance_gauche or distance_droite <=10 and distance_gauche <=10){
    tourner.tourneradroite(angle, servo1, i); // si la distance du capteur de gauche est inférieure à celle de droite, l'obstacle est proche et à gauche, il faut donc tourner à droite
  }                                           // Nous avons aussi décidé qu'en cas de distance égale, le robot tournerai à droite.
                                              // De manière arbitraire, nous avons décidé qu'un obstacle est proche à partir d'une distance de 10mm, mais cette valeur changera après les tests en pratique
  else if (distance_droite < distance_gauche){
    tourner.tourneragauche(angle, servo1, i); // si la distance du capteur de droite est inférieure à celle de gauche, l'obstacle est proche et à droite, il faut donc tourner à gauche
  }
}
