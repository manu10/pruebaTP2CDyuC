#include "menu.h"
#include "competidores.h"
#include "formato.h"
#include "reloj.h"
#include "PC_IO.h"

void menu_main(char opcion){
	PC_IO_Write_Char_To_Buffer(opcion);
	PC_IO_Write_Char_To_Buffer('\n');
	switch (opcion) {
	case 'w':
	case 'W':{
		PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(RELOJ_getHora()));
		break;
	}
	case 'a':
	case 'A':{
		competidores_registrar();
		PC_IO_Write_String_To_Buffer(competidores_getHora(competidores_cant()));
		break;
	}
	case 'l':
	case 'L':{
		
		short int i;
				for(i=1;i<=competidores_cant();i++){
					PC_IO_Write_String_To_Buffer(competidores_getHora(i));
					PC_IO_Write_Char_To_Buffer('\n');
					PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(competidores_getDiferencia(i)));
					PC_IO_Write_Char_To_Buffer('\n');
				}
		break;
	}
	case 'd'://Detener
		case 'D':{
			RELOJ_detener();
			MANEJOLED_prenderLed();
			break;
		}
	case 'i':
	case 'I':{
		RELOJ_run();
		break;
	}
	case 'r':
	case 'R':{
		RELOJ_resetear();
		competidores_resetear();
		MANEJOLED_apagarLed();
		break;
	}

	default:
		// Code
		break;

	}

}
