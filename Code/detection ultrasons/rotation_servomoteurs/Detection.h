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
  void detection_obstacle(int &distance_droite, int &distance_gauche, int &angle, int i, Servo servo1);




};
#endif
