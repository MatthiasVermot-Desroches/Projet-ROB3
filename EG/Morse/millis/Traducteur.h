#include <Arduino.h>

class Traducteur
{
private:
    int _ledPin;
    unsigned long _t;
    unsigned int _iselector = 0;
    unsigned int _oselector = 0;
    bool _wordSpace = 0;
    bool _letterSpace = 0;
    bool _temp = 0;
    String _sentence;
    int _timeUnit = 300;
    String letters[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
    };
    String numbers[10] = {
      "-----",".----","..---","...--","....-",".....","-....", // 0-6
      "--...","---..","----." // 7-9
    };

public:
    Traducteur(int ledPin);
    ~Traducteur();
    void flash(String sentence);
    void run();
};
