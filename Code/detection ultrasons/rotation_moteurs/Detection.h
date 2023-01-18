#ifndef Detection_h
#define Detection_h
#include "Tourner.h"
#include <Servo.h>
class Detection
{
private:
  Tourner tourner;
public:
  Detection();
  ~Detection();
  void mesure_distance(int trig, int echo, int trig2, int echo2, int &distance_droite, int &distance_gauche);
  void detection_obstacle(int &distance_droite, int &distance_gauche, int &vitesse_droite, int &vitesse_gauche, int i, int M1A, int M2A);




};
#endif
