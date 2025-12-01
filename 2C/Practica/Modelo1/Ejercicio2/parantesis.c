#include "parentesis.h"

int esCerrado(const char ch){
    switch(ch){
        case ']':
            return 1;
            break;

        case ')':
            return 1;
            break;

        case '}':
            return 1;
            break;

        default:
            return 0;
    }
}

int esAbierto(const char ch){
    switch(ch){
        case '(':
            return 1;
            break;

        case '{':
            return 1;
            break;

        case '[':
            return 1;
            break;

        default:
            return 0;
    }
}

int cierran(const char ch1, const char ch2){
    if(
       ((ch1 == '[' && ch2 == ']') || (ch2 == '[' && ch1 == ']')) ||
       ((ch1 == '(' && ch2 == ')') || (ch2 == '(' && ch1 == ')')) ||
       ((ch1 == '{' && ch2 == '}') || (ch2 == '{' && ch1 == '}'))
       )
    {
       return 1;
    }

    return 0;
}
