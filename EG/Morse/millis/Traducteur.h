#include <Arduino.h>

class Traducteur
{
private:
    int _ledPin;
    unsigned long _t;
    unsigned int _iselector = 0;
    unsigned int _oselector = 0;
    bool _space = 0;
    String _sentence;
    String letters[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
    };

public:
    Traducteur(int ledPin);
    ~Traducteur();
    void flash(String sentence);
    void run();
};
