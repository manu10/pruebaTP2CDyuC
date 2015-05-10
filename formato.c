#include "formato.h" 


char* FORMATO_pasar_a_str(tiempo tiempo1){
	char hora_str[13];
	hora_str[0]=tiempo1.hora/10+48;
	hora_str[1]=tiempo1.hora%10+48;
	hora_str[2]=':';
	hora_str[3]=tiempo1.min/10+48;
	hora_str[4]=tiempo1.min%10+48;
	hora_str[5]=':';
	hora_str[6]=tiempo1.seg/10+48;
	hora_str[7]=tiempo1.seg%10+48;
	hora_str[8]='.';
	hora_str[9]=tiempo1.cent/10+48;
	hora_str[10]=tiempo1.cent%10+48;	
	hora_str[11]=0;
	return hora_str;

}
