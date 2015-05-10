#include "competidores.h"
#include "reloj.h"
#include "formato.h"

#define MAXCOMPETIDORES 5
static long int lista[MAXCOMPETIDORES];
static short int indice=0;
//static char cadena_hora[11];

void competidores_registrar(void){
	if(indice<MAXCOMPETIDORES){
		lista[indice]=RELOJ_getHora();
		indice++;
		
		//imprimirtiempo
		//imprimirdiferencia
	}
}

long int competidores_getHora(short int pos){//pos es el numero de competidor y el indice es la cantidad de participantes
	if(pos<=indice){
		return lista[pos-1];//Para que en el llamado de la funcion llame como primera posicion a la posicion 1
	}
	return 0;
}

long int competidores_getDiferencia(short int pos){// el parametro seria "pos" no? estaba "indice" pero es static short int
	if(pos<indice){//No seria mejor "if (indice!=0)" ??
		return lista[pos]-lista[pos-1];
	}else
		return lista[pos];//Es decir la diferencia del tiempo del primero con 0
}


short int competidores_cant(void){
	return indice;
}

void competidores_resetear(void){
	indice=0;
}


