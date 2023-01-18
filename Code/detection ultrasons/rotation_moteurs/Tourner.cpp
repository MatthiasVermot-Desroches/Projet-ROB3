#include "Tourner.h"
#include <Arduino.h>
#include <Servo.h>

Tourner::Tourner(){}

Tourner::~Tourner(){}

//Nous avons décider de tourner de manière progressive en modifiant progressivement les vitesses dans le but d'avoir un mouvement plus fluide en pratique

void Tourner::tourneradroite(int &vitesse_gauche, int &vitesse_droite,int M2A, int i) //rotation vers la droite
{
  Serial.println("vers la droite");
    vitesse_gauche -= i; //Pour touner vers la droite, il faut réduire la vitesse du moteur de gauche
    Serial.print("vitesse droite ");
    Serial.println(vitesse_droite);
    Serial.print("vitesse gauche ");
    Serial.println(vitesse_gauche);
    analogWrite(M2A, vitesse_gauche);
}

void Tourner::tourneragauche(int &vitesse_droite, int &vitesse_gauche, int M1A, int i) //rotation vers la gauche
{
  Serial.println("vers la gauche");
    vitesse_droite -= i; //Pour tourner vers la gauche, il faut réduire la vitesse du moteur de droite
    Serial.print("vitesse droite ");
    Serial.println(vitesse_droite);
    Serial.print("vitesse gauche ");
    Serial.println(vitesse_gauche);
    analogWrite(M1A, vitesse_droite);
}

void Tourner::toutdroit(int &vitesse_droite,int &vitesse_gauche, int M1A, int M2A) //le robot avance sans tourner
{
  Serial.println("RAS");
  vitesse_droite = 100; //Comme le robot n'a pas besoin de tourner, les moteurs peuvent en théorie revenir à leurs vitesses par défaut
  vitesse_gauche = 100; //Nous n'avons cependant pas encore fait d'essais en pratique, donc cette fonction changera peut-être plus tard
  analogWrite(M1A, vitesse_droite);
  analogWrite(M2A, vitesse_gauche);
}

void Tourner::controle_vitesses_limites(int &vitesse_droite, int &vitesse_gauche) 
{ //Nous ne voulons pas qu'un moteur tourne trop lentement pour l'instant, nous limitons donc leurs vitesses
  if (vitesse_droite < 20) {vitesse_droite = 20;}
  else if (vitesse_gauche < 20) {vitesse_gauche = 20;}
}
