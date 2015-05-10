#ifndef _COMPETIDORES_H
#define _COMPETIDORES_H 1

#include "MC9S08SH8.h"
#include "reloj.h"


void competidores_registrar(void);
tiempo competidores_getHora(char indice);
tiempo competidores_getDiferencia(char indice);
char competidores_cant(void);
void competidores_resetear(void);


#endif

