/*
 * LOS COMENTARIOS DEBEN IR EN EL .C
 */
#ifndef _RELOJ_H
#define _RELOJ_H 1
#include "MC9S08SH8.h"
#include "manejoLed.h"
typedef struct tiempoStruct{
	unsigned short int hora;
	unsigned short int min;
		unsigned short int seg;
		unsigned short int cent;
//	unsigned char hora;
//	unsigned char min;
//	unsigned char seg;
//	unsigned char cent;
}tiempo;
void RELOJ_actualizar(void);
void RELOJ_run(void);
void RELOJ_resetear(void);
tiempo RELOJ_getHora(void);
void RELOJ_detener(void);
void RELOJ_init(void);
#endif
