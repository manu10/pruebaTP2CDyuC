#include "reloj.h"
static tiempo reloj;
unsigned char funcionando;//Pq no podiamos deshabilitar las interrupciones.. No nos hacia caso
void RELOJ_actualizar(void){
	if (funcionando){
		MANEJOLED_controlLed(reloj.cent++);
		if(reloj.cent==100){
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
}
void RELOJ_run(void){
	funcionando=1;
	RTCSC_RTIE=1; 	//habilito las interrupciones
}
void RELOJ_detener(){
	funcionando=0;
	RTCSC_RTIE=0; 	//deshabilito las interrupciones
}
void RELOJ_resetear(void){
	RELOJ_detener();
	reloj.hora=0;
	reloj.min=0;
	reloj.seg=0;
	reloj.cent=0;

}
tiempo RELOJ_getHora(void){
	return reloj;
}
void RELOJ_init(void){
	RTCSC_RTCPS=11;	//pongo el preescaler para que el contador llegue a 10ms
	RTCSC_RTCLKS=0; //selecciono el LPO como fuente de reloj
	RTCSC_RTIE=0;
	funcionando=1;
}
