#include "expresion_regular.h"

int esAbierto(const char simbolo){

    switch(simbolo){
        case '{':
        case '(':
        case '[':
            return 1;
            break;
    }

    return 0;
}

int esCerrado(const char simbolo){

    switch(simbolo){
        case '}':
        case ')':
        case ']':
            return 1;
            break;
    }

    return 0;
}

int coinciden(const char abierto, const char cerrado){
    if(abierto == '{' && cerrado == '}'){
        return 1;
    }

    if(abierto == '(' && cerrado == ')'){
        return 1;
    }

    if(abierto == '[' && cerrado == ']'){
        return 1;
    }

    return 0;
}
