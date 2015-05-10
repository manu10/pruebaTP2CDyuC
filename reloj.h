/*
 * LOS COMENTARIOS DEBEN IR EN EL .C
 */
#ifndef _RELOJ_H
#define _RELOJ_H 1

#include "MC9S08SH8.h"
typedef struct tiempoStruct{
	int hora;
	int min;
	int seg;
	int cent;
}tiempo;

void RELOJ_actualizar(void);
void RELOJ_run(void);
void RELOJ_resetear(void);
tiempo RELOJ_getHora(void);
void RELOJ_detener(void);
void RELOJ_init(void);
char RELOJ_getState(void);

#endif
