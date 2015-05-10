#include "menu.h"
#include "PC_IO.h"
#include "competidores.h"
#include "formato.h"
#include "reloj.h"
#include "manejoLed.h"
void menu_main(char opcion){
	
	PC_IO_Write_Char_To_Buffer(opcion);
	PC_IO_Write_Char_To_Buffer('\n');
	switch (opcion) {
	case 'w':
	case 'W':{
		
		PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(RELOJ_getHora()));
		break;
	}
	case 'l':
	case 'L':{
		short int i;
		for(i=1;i<=competidores_cant();i++){
			PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(competidores_getHora(i)));
			PC_IO_Write_Char_To_Buffer('\n');
			PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(competidores_getDiferencia(i)));
			PC_IO_Write_Char_To_Buffer('\n');
		}
		break;
	}
	case 'i':
	case 'I':{
		RELOJ_run();
		break;
	}
	case 's':
	case 'S':{
		RELOJ_detener();
		MANEJOLED_prenderLed();
		break;
	}
	case 'r':
	case 'R':{
		RELOJ_resetear();
		MANEJOLED_apagarLed();
		competidores_resetear();
		break;
	}
	case 'a':
	case 'A':{
		competidores_registrar();
		PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(competidores_getHora(competidores_cant())));
		break;
	}
	}
}
