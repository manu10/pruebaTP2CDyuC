#include "competidores.h"


#define MAXCOMPETIDORES 5
static tiempo lista[MAXCOMPETIDORES];
static short int indice=0;
//static char cadena_hora[11];

void competidores_registrar(void){
	if(indice<MAXCOMPETIDORES){
		lista[indice]=RELOJ_getHora();
		
		PC_IO_Write_String_To_Buffer(FORMATO_pasar_a_str(lista[indice]));
		indice++;
		//imprimirtiempo
		//imprimirdiferencia
	}
}

char* competidores_getHora(short int pos){//pos es el numero de competidor y el indice es la cantidad de participantes
	if(pos<=indice){
		return FORMATO_pasar_a_str(lista[pos-1]);//Para que en el llamado de la funcion llame como primera posicion a la posicion 1
	}
	return "00:00:00.00";
}

tiempo competidores_getDiferencia(short int pos){// el parametro seria "pos" no? estaba "indice" pero es static short int
	
			if(pos<indice){//No seria mejor "if (indice!=0)" ??
			tiempo diferencia;
			diferencia.cent=lista[pos].cent-lista[pos-1].cent;
			diferencia.seg=lista[pos].seg-lista[pos-1].seg;
			diferencia.min=lista[pos].min-lista[pos-1].min;
			diferencia.hora=lista[pos].hora-lista[pos-1].hora;
			if(diferencia.cent<0){
				diferencia.cent=diferencia.cent+100;
				diferencia.seg--;
				if(diferencia.seg<0){
					diferencia.seg=diferencia.seg+60;
					diferencia.min--;
					if(diferencia.min<0){
						diferencia.min=diferencia.min+60;
						diferencia.hora--;
					}
				}
			}
			return diferencia;
		}else
			return lista[pos];//Es decir la diferencia del tiempo del primero con 0
	}
//	if(pos<indice){//No seria mejor "if (indice!=0)" ??
//		//FORMATO_pasar_a_str(lista[pos]-lista[pos-1]);
//	}else
//		return FORMATO_pasar_a_str(lista[pos]);//Es decir la diferencia del tiempo del primero con 0
//}


char competidores_cant(void){
	return indice;
}

void competidores_resetear(void){
	indice=0;
}


