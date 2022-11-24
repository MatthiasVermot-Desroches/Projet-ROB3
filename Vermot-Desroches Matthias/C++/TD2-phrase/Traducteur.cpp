#include "Traducteur.h"
#include <string.h>
#include <Arduino.h>
traducteur::traducteur(int pin)
{
    mor = morse(pin);
}

traducteur::~traducteur()
{
  strcpy(trad, "");
}

traducteur::traducteur()
{
    mor = morse();
}

void traducteur::traduire(char c) // remplace chaque lettre par son équivalent en morse
{   
    switch (c)
    {
    case 'a':
        strcat(trad,".-");
        strcat(trad," "); // je rajoute le code morse d'un espaceentre 2 lettres dans chaque cas
        break;
    default:
        break;
    case 'b':
        strcat(trad,"-...");
        strcat(trad," ");
        break;
    case 'c':
        strcat(trad,"-.-.");
        strcat(trad," ");
        break;
    case 'd':
        strcat(trad,"-..");
        strcat(trad," ");
        break;
    case 'e':
        strcat(trad,".");
        strcat(trad," ");
        break;
    case 'f':
        strcat(trad,"..-.");
        strcat(trad," ");
        break;
    case 'g':
        strcat(trad,"--.");
        strcat(trad," ");
        break;
    case 'h':
        strcat(trad,"....");
        strcat(trad," ");
        break;
    case 'i':
        strcat(trad,"..");
        strcat(trad," ");
        break;
    case 'j':
        strcat(trad,".---");
        strcat(trad," ");
        break;
    case 'k':
        strcat(trad,"-.-");
        strcat(trad," ");
        break;
    case 'l':
        strcat(trad,".-..");
        strcat(trad," ");
        break;
    case 'm':
        strcat(trad,"--");
        strcat(trad," ");
        break;
    case 'n':
        strcat(trad,"-.");
        strcat(trad," ");
        break;
    case 'o':
        strcat(trad,"---");
        strcat(trad," ");
        break;
    case 'p':
        strcat(trad,".--.");
        strcat(trad," ");
        break;
    case 'q':
        strcat(trad,"--.-");
        strcat(trad," ");
        break;
    case 'r':
        strcat(trad,".-.");
        strcat(trad," ");
        break;
    case 's':
        strcat(trad,"...");
        strcat(trad," ");
        break;
    case 't':
        strcat(trad,"-");
        strcat(trad," ");
        break;
    case 'u':
        strcat(trad,"..-");
        strcat(trad," ");
        break;
    case 'v':
        strcat(trad,"...-");
        strcat(trad," ");
        break;
    case 'w':
        strcat(trad,".--");
        strcat(trad," ");
        break;
    case 'x':
        strcat(trad,"-..-");
        strcat(trad," ");
        break;
    case 'y':
        strcat(trad,"-.--");
        strcat(trad," ");
        break;
    case 'z':
        strcat(trad,"--..");
        strcat(trad," ");
        break;
    case '0':
        strcat(trad,"-----");
        strcat(trad," ");
        break;
    case '1':
        strcat(trad,".----");
        strcat(trad," ");
        break;
    case '2':
        strcat(trad,"..---");
        strcat(trad," ");
        break;
    case '3':
        strcat(trad,"...--");
        strcat(trad," ");
        break;
    case '4':
        strcat(trad,"....-");
        strcat(trad," ");
        break;
    case '5':
        strcat(trad,".....");
        strcat(trad," ");
        break;
    case '6':
        strcat(trad,"-....");
        strcat(trad," ");
        break;
    case '7':
        strcat(trad,"--...");
        strcat(trad," ");
        break;
    case '8':
        strcat(trad,"---..");
        strcat(trad," ");
        break;
    case '9':
        strcat(trad,"----.");
        strcat(trad," ");
        break;
    case ' ':
        strcat(trad,"!"); // Un espace entre 2 mots est de 7 points, mais je concatène déjà 3 points pour l'espace entre 2 lettres, donc 4 en plus suffisent.
        break;
    }
}

void traducteur::action() //lance les clignotements de la LED
{
    for (int i = 0; i < strlen(trad); i++)
    {
        if (trad[i] == '.')
        {
            mor.point();
        }
        else if (trad[i] == '-')
        {
            mor.trait();
        }
        else if (trad[i] == ' ')
        {
            mor.espace();
        }
        else if (trad[i] == '!')
        {
            mor.grandespace();
        }
        else
        {
            break;
        }
    }
}

void traducteur::traduiremot(char mot[]) //traduction d'un mot
{
    for (int i = 0; i < strlen(mot); i++)
    {
        traduire(mot[i]);
    }
}

void traducteur::rafraichir_trad()
{
  strcpy(trad, "");
}
