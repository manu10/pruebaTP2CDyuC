#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "SCI_Functions.h"
#include "reloj.h"
#include "menu.h"
#include "PTA0_INT.h"
#include "PC_IO.h"

#ifdef __cplusplus
extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */

unsigned char opcion;

void main(void) {
  MCU_init();	/* call Device Initialization */
  /* include your code here */
  //SCI_Init();
  PC_IO_Init();
  RELOJ_init();
  PTA0_INT_init();  
  

  for(;;) {
	  	  
    /* __RESET_WATCHDOG(); By default COP is disabled with device init. When enabling, also reset the watchdog. */
  } /* loop forever */
  /* please make sure that you never leave main */
}
