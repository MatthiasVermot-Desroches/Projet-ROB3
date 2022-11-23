#include "Traducteur.h"

Traducteur::Traducteur(int ledPin) : _ledPin(ledPin) {}

Traducteur::~Traducteur() {}

void Traducteur::flash(String sentence) { _sentence = sentence; }

void Traducteur::run() {
  unsigned long t = millis();
  unsigned long elasped = t - _t;

  if (_space || _temp) {
    int elasped_req = (_temp) ? 300 : 2100;
    if (elasped >= elasped_req) {
      _space = false;
      _temp = false;
      _t = t;
      _oselector += 1;
      if (_oselector >= _sentence.length()) {
        _oselector = 0;
      }
    }
  } else {
    int c = _sentence[_oselector];

    String codes;
    if (c >= 48 && c <= 57) {
      codes = numbers[c - '0'];
    } else if (c >= 65 && c <= 90) {
      codes = letters[c - 'A'];
    } else if (c >= 97 && c <= 122) {
      codes = letters[c - 'a'];
    } else if (c == 32) { 
      _space = true;
    } else {
      exit(-1);
    }
    
    char code = codes[_iselector];

    digitalWrite(_ledPin, HIGH);

    int elasped_req = (code == '.') ? 300 : 900;
    if (elasped >= elasped_req) {
      _iselector += 1;
      if (_iselector >= codes.length()) {
        _iselector = 0;
        _oselector += 1;
        if (_oselector >= _sentence.length()) {
          _oselector = 0;
        }
      }
      _t = t;
      _temp = true;
      digitalWrite(_ledPin, LOW);
    }
  }
}
