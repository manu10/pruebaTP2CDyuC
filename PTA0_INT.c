#include "PTA0_INT.h"
/*
 * Teniendo en cuanta que en MCUinit.c se habilió el pin 0 del puerto A para que
 */
void PTA0_INT_Handler(void){
	 //registrar
	 	
}

void PTA0_INT_init(void){
	PTAPE_PTAPE0=1;	//haibilita el pull up del porta0
	PTADD_PTADD0=0;	//SETEA EL PORTA0 COMO INPUT;
}
