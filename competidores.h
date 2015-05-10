#ifndef _COMPETIDORES_H
#define _COMPETIDORES_H 1

#include "MC9S08SH8.h"


void competidores_registrar(void);
long int competidores_getHora(short int indice);
long int competidores_getDiferencia(short int indice);
short int competidores_cant(void);
void competidores_resetear(void);


#endif

