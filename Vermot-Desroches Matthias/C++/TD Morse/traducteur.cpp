#include "traducteur.h"
#include <string.h>
traducteur::traducteur(int pin)
{
    mor = morse(pin);
}

traducteur::traducteur()
{
    mor = morse();
}

void traducteur::traduire(char) // remplace chaque lettre par son équivalent en morse
{
    switch (char)
    {
    case 'a':
        mot[1024] = ".-"
        break;

    default:
        break;
    case 'b':
       mot[1024]="-...";
        break;
    case 'c':
        mot[1024]="-.-.";
        break;
    case 'd':
        mot[1024]="-..";
        break;
    case 'e':
        mot[1024]=".";
        break;
    case 'f':
        mot[1024]="..-.";
        break;
    case 'g':
        mot[1024]="--.";
        break;
    case 'h':
        mot[1024]="....";
        break;
    case 'i':
        mot[1024]="..";
        break;
    case 'j':
        mot[1024]=".---";
        break;
    case 'k':
        mot[1024]="-.-";
        break;
    case 'l':
        mot[1024]=".-..";
        break;
    case 'm':
        mot[1024]="--";
        break;
    case 'n':
        mot[1024]="-.";
        break;
    case 'o':
        mot[1024]="---";
        break;
    case 'p':
        mot[1024]=".--.";
        break;
    case 'q':
        mot[1024]="--.-";
        break;
    case 'r':
        mot[1024]=".-.";
        break;
    case 's':
        mot[1024]="...";
        break;
    case 't':
        mot[1024]="-";
        break;
    case 'u':
        mot[1024]="..-";
        break;
    case 'v':
        mot[1024]="...-";
        break;
    case 'w':
        mot[1024]=".--";
        break;
    case 'x':
        mot[1024]="-..-";
        break;
    case 'y':
        mot[1024]="-.--";
        break;
    case 'z':
        mot[1024]="--..";
        break;
    }
    return mot[1024]
}

void traducteur::action(char* morse) //lance les clignotements de la LED mais il faut pouvoir séparer la chaîne de caractère
                                     // en plusieurs case d'un tableau
{
    for (int i = 0; i < strlen(morse); i++)
    {
        if (morse[i] == '.')
        {
            mor.point();
        }
        else if (morse[i] == '-')
        {
            mor.trait();
        }
        else
        {
            break;
        }
    }
}

void traducteur::traduiremot(char* mot) //traduction d'un mot
{
    for (int i = 0; i < strlen(mot); i++)
    {
        traduire(mot[i]);
    }
}