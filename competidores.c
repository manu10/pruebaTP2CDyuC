#include "competidores.h"
#include "reloj.h"
#include "formato.h"

#define MAXCOMPETIDORES 5
static tiempo lista[MAXCOMPETIDORES];
static char indice=0;
//static char cadena_hora[11];

void competidores_registrar(void){
	if(indice<MAXCOMPETIDORES){
		lista[indice]=RELOJ_getHora();
		indice++;

		//imprimirtiempo
		//imprimirdiferencia
	}
}

tiempo competidores_getHora(char pos){//pos es el numero de competidor y el indice es la cantidad de participantes
	if(pos<=indice){
		return lista[pos-1];//Para que en el llamado de la funcion llame como primera posicion a la posicion 1
	}
	return lista[0];
}

tiempo competidores_getDiferencia(char pos){// el parametro seria "pos" no? estaba "indice" pero es static short int
	pos--;
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


char competidores_cant(void){
	return indice;
}

void competidores_resetear(void){
	indice=0;
}


