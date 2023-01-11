#include "Traducteur.h"

Traducteur trad(LED_BUILTIN);

void setup() {
  trad.flash("Hello word!");
}

void loop() {
  trad.run();
}
