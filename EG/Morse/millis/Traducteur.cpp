#include "Traducteur.h"

Traducteur::Traducteur(int ledPin) : _ledPin(ledPin) {}

Traducteur::~Traducteur() {}

void Traducteur::flash(String sentence) { _sentence = sentence; }

void Traducteur::run() {
  unsigned long t = millis();
  unsigned long elasped = t - _t;

  if (_space) {
    if (elasped >= 2000) {
      _space = false;
      _t = t;
      _oselector += 1;
      if (_oselector >= _sentence.length()) {
        _oselector = 0
      }
    }
  } else {
    String codes = letters[_sentence[_oselector] - 'a'];
    String code = codes[_iselector];

    digitalWrite(_ledPin, HIGH);

    elasped_req = (code == '.') ? 300 : 1000;
    if (elasped >= elasped_req) {
      _iselector += 1;
      if (_iselector >= codes.length()) {
        _iselector = 0;
        _oselector += 1;
        if (_oselector >= _sentence.length()) {
          _oselector = 0
        }
      }
      _t = t;
      _space = true;
      digitalWrite(_ledPin, LOW);
    }
  }
}
