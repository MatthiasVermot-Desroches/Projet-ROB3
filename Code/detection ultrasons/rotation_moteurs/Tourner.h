#ifndef Tourner_h
#define Tourner_h
#include <Servo.h>
class Tourner
{
private:
  

public:
  Tourner();
  ~Tourner();
  void tourneradroite(int &vitesse_gauche, int &vitesse_droite, int M2A, int i);
  void tourneragauche(int &vitesse_droite, int &vitesse_gauche, int M1A, int i);
  void toutdroit(int &vitesse_droite,int &vitesse_gauche, int M1A, int M2A);
  void controle_vitesses_limites(int &vitesse_droite, int &vitesse_gauche);
  
};

#endif
