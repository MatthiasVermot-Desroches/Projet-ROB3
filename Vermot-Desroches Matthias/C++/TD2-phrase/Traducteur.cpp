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
    case 'A':
        strcat(trad,".-"); //Je concatène chaque traduction dans un tableau.
        strcat(trad," "); // Je rajoute le code morse d'un espace entre 2 lettres dans chaque cas.
        break;
    default:
        break;
    case 'b':
    case 'B':
        strcat(trad,"-...");
        strcat(trad," ");
        break;
    case 'c':
    case 'C':
        strcat(trad,"-.-.");
        strcat(trad," ");
        break;
    case 'd':
    case 'D':
        strcat(trad,"-..");
        strcat(trad," ");
        break;
    case 'e':
    case 'E':
        strcat(trad,".");
        strcat(trad," ");
        break;
    case 'f':
    case 'F':
        strcat(trad,"..-.");
        strcat(trad," ");
        break;
    case 'g':
    case 'G':
        strcat(trad,"--.");
        strcat(trad," ");
        break;
    case 'h':
    case 'H':
        strcat(trad,"....");
        strcat(trad," ");
        break;
    case 'i':
    case 'I':
        strcat(trad,"..");
        strcat(trad," ");
        break;
    case 'j':
    case 'J':
        strcat(trad,".---");
        strcat(trad," ");
        break;
    case 'k':
    case 'K':
        strcat(trad,"-.-");
        strcat(trad," ");
        break;
    case 'l':
    case 'L':
        strcat(trad,".-..");
        strcat(trad," ");
        break;
    case 'm':
    case 'M':
        strcat(trad,"--");
        strcat(trad," ");
        break;
    case 'n':
    case 'N':
        strcat(trad,"-.");
        strcat(trad," ");
        break;
    case 'o':
    case 'O':
        strcat(trad,"---");
        strcat(trad," ");
        break;
    case 'p':
    case 'P':
        strcat(trad,".--.");
        strcat(trad," ");
        break;
    case 'q':
    case 'Q':
        strcat(trad,"--.-");
        strcat(trad," ");
        break;
    case 'r':
    case 'R':
        strcat(trad,".-.");
        strcat(trad," ");
        break;
    case 's':
    case 'S':
        strcat(trad,"...");
        strcat(trad," ");
        break;
    case 't':
    case 'T':
        strcat(trad,"-");
        strcat(trad," ");
        break;
    case 'u':
    case 'U':
        strcat(trad,"..-");
        strcat(trad," ");
        break;
    case 'v':
    case 'V':
        strcat(trad,"...-");
        strcat(trad," ");
        break;
    case 'w':
    case 'W':
        strcat(trad,".--");
        strcat(trad," ");
        break;
    case 'x':
    case 'X':
        strcat(trad,"-..-");
        strcat(trad," ");
        break;
    case 'y':
    case 'Y':
        strcat(trad,"-.--");
        strcat(trad," ");
        break;
    case 'z':
    case 'Z':
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
