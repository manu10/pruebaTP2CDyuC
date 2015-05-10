#include "manejoLed.h"

void MANEJOLED_controlLed(int centesimoDeSeg)
{
	if(!centesimoDeSeg){
		MANEJOLED_prenderLed();
	}

	else if (centesimoDeSeg==FIN){
		MANEJOLED_apagarLed();
	}
}
void MANEJOLED_apagarLed(void)
{
	PTCD_PTCD0=0;
}
void MANEJOLED_prenderLed(void)
{
	PTCD_PTCD0=1;		
}
void MANEJOLED_init(void){
	PTCDD_PTCDD0=1;
	PTBDS=1;
}
