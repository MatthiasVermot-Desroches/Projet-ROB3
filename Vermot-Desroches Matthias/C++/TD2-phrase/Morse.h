#ifndef Morse_h
#define Morse_h

class morse
{
private:
    int _pin;
    unsigned long time_now;
public:
    morse(int pin);
    morse();
    ~morse();
    void point();
    void trait();
    void espace();
    void grandespace();
};


#endif
