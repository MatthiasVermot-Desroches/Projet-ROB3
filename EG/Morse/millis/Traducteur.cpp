#include "Traducteur.h"

Traducteur::Traducteur(int ledPin) : _ledPin(ledPin) {}

Traducteur::~Traducteur() {}

void Traducteur::flash(String sentence) { _sentence = sentence; }

void Traducteur::run() {
  unsigned long t = millis();
  unsigned long elasped = t - _t;

  if (_space) {
    if (elasped >= 7*_timeUnit) {
      _space = false;
      _t = t;
      _oselector += 1;
      if (_oselector >= _sentence.length()) {
        _oselector = 0;
      }
    }
  } else if (_temp) {
    if (elasped >= _timeUnit) {
      _temp = false;
      _t = t;
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
      exit(0);
    } else {
      exit(-1);
    }
    
    char code = codes[_iselector];

    digitalWrite(_ledPin, HIGH);

    int elasped_req = (code == '.') ? _timeUnit : 3*_timeUnit;
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
