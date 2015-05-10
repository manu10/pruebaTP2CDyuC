#include "formato.h" 

char* FORMATO_pasar_a_str(long int hora){
	//TESTEADO EN CODEBLOCK 
	char hora_str[13];
	hora_str[0]=(char) (hora/3600000) ; //"+48 para convertir a ASCII
	hora=hora-hora_str[0]*3600000;//Para restar las decenas de hora
	hora_str[1]=(char) (hora/360000);
	hora_str[2]=':';
	hora=hora-hora_str[1]*360000;//Para restar las decenas de hora
	hora_str[3]=(char) (hora/60000); //"+48 para convertir a ASCII
	hora=hora-hora_str[3]*60000;//Para restar las decenas de hora
	hora_str[4]=(char) (hora/6000);
	hora=hora-hora_str[4]*6000;//Para restar las decenas de hora
	hora_str[5]=':';
	hora_str[6]=(char) (hora/1000); //"+48 para convertir a ASCII
	hora=hora-hora_str[6]*1000;//Para restar las decenas de hora
	hora_str[7]=(char) (hora/100);
	hora=hora-hora_str[7]*100;//Para restar las decenas de hora
	hora_str[8]='.';
	hora_str[9]=(char) (hora/10); //"+48 para convertir a ASCII
	hora_str[10]=hora-hora_str[9]*10;//Porque lo que quedan son unidades 	
	hora_str[0]=hora_str[0]+48;
	hora_str[1]=hora_str[1]+48;
	hora_str[3]=hora_str[3]+48;
	hora_str[4]=hora_str[4]+48;
	hora_str[6]=hora_str[6]+48;
	hora_str[7]=hora_str[7]+48;
	hora_str[9]=hora_str[9]+48;
	hora_str[10]=hora_str[10]+48;
	hora_str[11]=0;
	hora_str[12]=0;
	return hora_str;

}
