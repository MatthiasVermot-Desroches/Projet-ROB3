#include "Traducteur.h"

Traducteur::Traducteur(int ledPin) : _ledPin(ledPin) {
  pinMode(ledPin, OUTPUT);  
}

Traducteur::~Traducteur() {}

void Traducteur::flash(String sentence) { 
  _sentence = sentence; 
}

void Traducteur::run() {
  unsigned long t = millis();
  unsigned long elasped = t - _t;

  if (_wordSpace) {
    if (elasped >= 7*_timeUnit) {
      _wordSpace = false;
      _t = t;
      _oselector += 1;
      if (_oselector >= _sentence.length()) {
        _oselector = 0;
      }
    }
  } else if (_letterSpace) {
    if (elasped >= 3*_timeUnit) {
      _letterSpace = false;
      _t = t;
    }
  } else if (_temp) {
    if (elasped >= _timeUnit) {
      _temp = false;
      _t = t;
    }
  } else {
    int c = _sentence[_oselector];

    if (c == 32) {
      _wordSpace = true;
    } else {
      String codes;
      if (c >= 48 && c <= 57) {
        codes = numbers[c - '0'];
      } else if (c >= 65 && c <= 90) {
        codes = letters[c - 'A'];
      } else if (c >= 97 && c <= 122) {
        codes = letters[c - 'a'];
      } else {
        _oselector += 1;
        return;
      }
      
      char code = codes[_iselector];
  
      digitalWrite(_ledPin, HIGH);
  
      int elasped_req = (code == '.') ? _timeUnit : 3*_timeUnit;
      if (elasped >= elasped_req) {
        _iselector += 1;
        if (_iselector >= codes.length()) {
          _iselector = 0;
          _oselector += 1;
          _letterSpace = true;
          if (_oselector >= _sentence.length()) {
            _oselector = 0;
          }
        } else {
          _temp = true;
        }
        _t = t;
        digitalWrite(_ledPin, LOW);
      }
    }
  }
}
