#include "Tourner.h"
#include <Arduino.h>
#include <Servo.h>

Tourner::Tourner(){}

Tourner::~Tourner(){}

//Nous avons décidé de tourner de manière progressivement en modifiant progressivement l'angle dans le but d'avoir un mouvement plus fluide en pratique

void Tourner::tourneradroite(int &angle, Servo servo1, int i) //rotation vers la droite
{
  Serial.println("vers la droite");
  angle-=i; //Pour aller vers la droite, nous pensons qu'il faut réduire l'angle du servomoteur, cela changera en fonction de l'orientation finale du servomoteur
  Serial.print("angle ");
  Serial.println(angle);
  servo1.write(angle);
}

void Tourner::tourneragauche(int &angle, Servo servo1, int i) //rotation vers la gauche
{
  Serial.println("vers la gauche");
  angle +=i; //Pour aller vers la gauche, nous pensons qu'il faut augmenter l'angle du servomoteur, cela changera en fonction de l'orientation finale du servomoteur
  Serial.print("angle ");
  Serial.println(angle);
  servo1.write(angle);
}

void Tourner::toutdroit(int &angle, Servo servo1) //le robot avance sans tourner
{
  Serial.println("RAS");
  //angle = 95;  En théorie, s'il n'y a pas d'obstacles, le robot devrait se remettre droit, en pratique, le servomoteur se comporte bizarrement quand il est remis à la position par défaut brutalement
  //servo1.write(angle);  // cette partie reste pour l'instant en commentaire le temps que l'on trouve une alternative
  //delay(10);
}

void Tourner::controle_angles_limites(int &angle) // fonction présente pour éviter que le servomoteur dépasse ses positions limites (0 et 180°)
{
  if (angle > 180) {angle = 180;}
  else if (angle < 0) {angle = 0;}
}
