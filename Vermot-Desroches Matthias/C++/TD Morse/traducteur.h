#include "morse.h"

class traducteur
{
private:
    morse mor;
    void action(char*);
public:
    traducteur(int pin);
    traducteur();
    ~traducteur();
    void traduire(char);
    void traduiremot(char*);
};

traducteur::~traducteur()
{
}
