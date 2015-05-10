#include "reloj.h"

static long int hora;

void RELOJ_actualizar(void){		
	hora++;
}

void RELOJ_run(void){
	RTCSC_RTIE=1; 	//habilito las interrupciones
}

void RELOJ_detener(){
	RTCSC_RTIE=0; 	//deshabilito las interrupciones
}

void RELOJ_resetear(void){
	RELOJ_detener();
	hora=0;
}

long int RELOJ_getHora(void){
	return hora;
}

void RELOJ_init(void){
	RTCSC_RTCPS=11;	//pongo el preescaler para que el contador llegue a 10ms
	RTCSC_RTCLKS=0; //selecciono el LPO como fuente de reloj
	RTCSC_RTIE=0;
	hora=0;
}
