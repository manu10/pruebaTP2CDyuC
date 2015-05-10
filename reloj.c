#include "reloj.h"

static tiempo reloj;
static char state;
void RELOJ_actualizar(void){		
	if(++reloj.cent==100){
		reloj.cent=0;
		if(++reloj.seg==60){
			reloj.seg=0;
			if(++reloj.min==60){
				reloj.min=0;
				if(++reloj.hora==100){
					reloj.hora=0;
				}
			}
		}
	}
}

char RELOJ_getState(void){
	return state;
}

void RELOJ_run(void){
	state=0;
}

void RELOJ_detener(){
	state=1;
}

void RELOJ_resetear(void){
	state=1;
	reloj.hora=0;
	reloj.min=0;
	reloj.seg=0;
	reloj.cent=0;
}

tiempo RELOJ_getHora(void){
	return reloj;
}

void RELOJ_init(void){
	state=0;
	RTCSC_RTCPS=11;	//pongo el preescaler para que el contador llegue a 10ms
	RTCSC_RTCLKS=0; //selecciono el LPO como fuente de reloj
}
