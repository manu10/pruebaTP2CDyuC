
#ifndef _MANEJOLED_H
#define _MANEJOLED_H 1

#include <mc9s08sh8.h>                 /* I/O map for MC9S08SH8CPJ */

#define INICIO 0	//se prende cuando las centesimas de segundos sean igual a 0
#define FIN 20		//se apaga a las 20 centesimas de segundo

void MANEJOLED_controlLed(int centesimoDeSeg);
void MANEJOLED_apagarLed(void);
void MANEJOLED_prenderLed(void);

#endif
