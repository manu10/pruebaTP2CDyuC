#ifndef _COMPETIDORES_H
#define _COMPETIDORES_H 1

#include "MC9S08SH8.h"
#include "reloj.h"
#include "formato.h"
#include "PC_IO.h"

void competidores_registrar(void);
char* competidores_getHora(short int indice);
tiempo competidores_getDiferencia(short int indice);
char competidores_cant(void);
void competidores_resetear(void);


#endif

