#include "Traducteur.h"

Traducteur trad(6);

void setup() {
  // put your setup code here, to run once:
  trad.flash("test");
}

void loop() {
  // put your main code here, to run repeatedly:
  trad.run();
}
