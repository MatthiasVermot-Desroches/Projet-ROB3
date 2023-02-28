#include "Traducteur.h"

Traducteur::Traducteur(int ledPin) : _ledPin(ledPin) {}

Traducteur::~Traducteur() {}

void Traducteur::flash(String sentence) {
  for (int i = 0; i < sentence.length(); i++) {
    String code = letters[sentence[i] - 'a'];

    for (int j = 0; j < code.length(); j++) {
      digitalWrite(_ledPin, HIGH);
      (code[j] == '.') ? delay(300) : delay(1000);
      digitalWrite(_ledPin, LOW);
    }
    delay(2000);
  }
}
