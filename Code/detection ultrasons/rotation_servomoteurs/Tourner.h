#ifndef Tourner_h
#define Tourner_h
#include <Servo.h>
class Tourner
{
private:
  

public:
  Tourner();
  ~Tourner();
  void tourneradroite(int &angle, Servo servo1, int i);
  void tourneragauche(int &angle, Servo servo1, int i);
  void toutdroit(int &angle, Servo servo1);
  void controle_angles_limites(int &angle);
  
};

#endif
