#include <Arduino.h>

class Traducteur
{
private:
    int _ledPin;
    unsigned long _time;
    String letters[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
    };

public:
    Traducteur(int ledPin);
    ~Traducteur();
    void flash(String sentence);
};
