#include "PC_IO.h"
#define TX_BUFFER_LENGTH 50
#define RX_BUFFER_LENGTH 10 
static unsigned  char TXIndice_lectura=0, TXIndice_escritura=0,RXIndex_escritura,RXIndex_lectura ;
static unsigned  char TX_Buffer [ TX_BUFFER_LENGTH],RX_Buffer [ RX_BUFFER_LENGTH];

/*funcion para inicializar*/
void PC_IO_Init ()
{
  SCIBD = 52;//Inicializa el baud rate en 9600
  SCIC1  = 0;
  SCIC2  = 0x0C;   //habilita Tx y Rx 
  TXIndice_lectura=0;
  TXIndice_escritura=0;
  RXIndex_escritura=0;
  RXIndex_lectura=0;
}
/*
 * FUNCION PRODUCTURA DE ESCRITURA DE STRING
 */
void PC_IO_Write_String_To_Buffer(  const char* STR_PTR )
{
	char i = 0;
	while  ( STR_PTR [i] != '\0')
	{
		PC_IO_Write_Char_To_Buffer  ( STR_PTR [ i ] );
		i++;
	}
}

/*
 * FUNCION PRODUCTURA DE ESCRITURA DE CHAR
 */
void PC_IO_Write_Char_To_Buffer  ( const char Data )
{
	// Write to the buffer *only* if there is space
	if (TXIndice_escritura < TX_BUFFER_LENGTH)
	
	{
		TX_Buffer[TXIndice_escritura] = Data;
		TXIndice_escritura ++;
	}
	else
	{
		// Write buffer is full
//		Error_code = ERROR_UART_FULL_BUFF;
	}
}
/*
 * FUNCION CONSUMIDORA DE  LA ESCRITURA y productura de LA LECTURA
 * llama a las funciones que interactuan con el hardware   
 */


void PC_IO_Update(void)
{
	char dato;
	
	/*
		 * consumidora de la escritura
		 */
	if (TXIndice_lectura < TXIndice_escritura) // Hay byte en el buffer Tx para transmitir?
	{//entonces lo mando a la salida(me comunico con el hardware
		PC_IO_Send_Char ( TX_Buffer [ TXIndice_lectura ] ); 
		TXIndice_lectura++; 
	}
	else
	{// No hay datos disponibles para enviar
		TXIndice_lectura = 0;
		TXIndice_escritura = 0; 
	}
	
	/*
	 * productora de la lectura de datos
	 */
	// se ha recibido algún byte?
	if ( PC_IO_Receive_data  ( &dato )  != 0) 
	{  // Byte recibido. Escribir byte en buffer de entrada
		if (RXIndex_escritura < RX_BUFFER_LENGTH)
		{
			RX_Buffer [ RXIndex_escritura ] = dato; // Guardar dato en buffer
			RXIndex_escritura++; // Inc sin desbordar buffer
		}
		else
			;//Error_code = ERROR_UART_FULL_BUFF;
	}
}





/*
 * FUNCION CONSUMIDORA DE LA LECTURA 
 */
char PC_IO_Get_Char_From_Buffer (char * ch)
{
	// Hay nuevo dato en el buffer?
	if (RXIndex_lectura <RXIndex_escritura)
	{
		*ch = RX_Buffer [ RXIndex_lectura ];
		RXIndex_lectura ++;
		return 1; // Hay nuevo dato
	}
	else  {
		RXIndex_lectura=0;
		RXIndex_escritura=0;
		return 0; // No Hay
	}
}




 

/*
 * FUNCIONES QUE INTERACTUAN CON EL HARDWARE DEL PERIFERICO:
 */
/*
 * ENVIA UN CARACTER POR EL PUERTO SERIE
 */
void PC_IO_Send_Char (char dato)
{
	long Timeout1 = 0;
	while  ( (++Timeout1) && (SCIS1_TDRE==0) );// ESPERA MIENTRAS
	//EL "Transmit Data Register Empty Flag" ESTE en 0 es decir
	//mientras el buffer esta vacio
	if (Timeout1 == 0)
	{
		// UART  did not respond – error
		return;
	}
	SCID = dato;
}
/*
 * RECIBE UN CARACTER POR EL PUERTO SERIE
 */
char PC_IO_Receive_data  (char *dato)
{
	if (SCIS1_RDRF==1) //SIE EL "Receive Data Register Full Flag" ESTA ACTIVO 
		//QUIERE DECIR QUE HAY DATO POR LO TANTO COPIA EL DATO EN LA VARIABLE
	{//Si hay dato para recibir  guarda el valor
		*dato=SCID;
		return 1;
	}
	else
		return 0;
}
