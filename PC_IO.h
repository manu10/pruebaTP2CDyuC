#ifndef _PC_IO_H
#define _PC_IO_H 1

#include "mc9s08sh8.h"
/*funcion para inicializar*/
void PC_IO_Init ();
/* FUNCION PRODUCTURA DE ESCRITURA DE STRING*/
void PC_IO_Write_String_To_Buffer(  const char* STR_PTR );
/* FUNCION PRODUCTURA DE ESCRITURA DE CHAR*/
void PC_IO_Write_Char_To_Buffer  ( const char Data );
/* * FUNCION CONSUMIDORA DE  LA ESCRITURA y productura de LA LECTURA
 * llama a las funciones que interactuan con el hardware */
void PC_IO_Update(void);
/*FUNCION CONSUMIDORA DE LA LECTURA */
char PC_IO_Get_Char_From_Buffer (char * ch);
/*FUNCIONES QUE INTERACTUAN CON EL HARDWARE DEL PERIFERICO:*/
/*ENVIA UN CARACTER POR EL PUERTO SERIE */
void PC_IO_Send_Char (char dato);
/*RECIBE UN CARACTER POR EL PUERTO SERIE*/
char PC_IO_Receive_data  (char *dato);

#endif
