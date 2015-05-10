#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "PC_IO.h"
#include "menu.h"
#include "reloj.h"
#include "formato.h"
#include "manejoLed.h"

#ifdef __cplusplus
extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */


char ch;
void main(void) {
	
	MCU_init();	/* call Device Initialization */
	/* include your code here */
	PC_IO_Init();//Inicializa para configurar el baud rate y habilitar los Txy Rx
	RELOJ_init();
	MANEJOLED_init();
	for(;;) {
		PC_IO_Update();//Se fija si hay algo para transmitir y lo transmite y si hay algo para leer y lo lee
		if (PC_IO_Get_Char_From_Buffer(&ch))
			menu_main(ch);

		/* __RESET_WATCHDOG(); By default COP is disabled with device init. When enabling, also reset the watchdog. */
	} /* loop forever */
	/* please make sure that you never leave main */
}
