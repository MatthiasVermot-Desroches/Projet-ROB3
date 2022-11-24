#ifndef Traducteur_h
#define Traducteur_h

#include "Morse.h"
#include <string.h>
class traducteur
{
private:
    morse mor;
public:
    traducteur(int pin);
    traducteur();
    ~traducteur();
    void traduire(char c);
    void traduiremot(char mot[]);
    char trad[1024];
    void action();
    void rafraichir_trad();
};


#endif
