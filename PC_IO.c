#include "PC_IO.h"
#define TX_BUFFER_LENGTH 50
#define RX_BUFFER_LENGTH 10 
static unsigned  char TXindice_lectura=0;
static unsigned  char TXindice_escritura=0;
static unsigned  char RXindex_escritura=0;
static unsigned  char RXindice_lectura=0;
static unsigned  char TX_buffer [TX_BUFFER_LENGTH];
static unsigned  char RX_buffer [RX_BUFFER_LENGTH];

/*funcion para inicializar*/
void PC_IO_Init (void)
{
	SCIBD = 52;
	SCIC1  = 0;
	SCIC2  = 0x0C;
}
/*
 * FUNCION PRODUCTURA DE ESCRITURA DE STRING
 */
void PC_IO_Write_String_To_Buffer(const char* STR_PTR )
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
	if (TXindice_escritura < TX_BUFFER_LENGTH)

	{
		TX_buffer[TXindice_escritura] = Data;
		TXindice_escritura ++;
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
	if (TXindice_lectura < TXindice_escritura) // Hay byte en el buffer Tx para transmitir?
	{//entonces lo mando a la salida(me comunico con el hardware
		PC_IO_Send_Char (TX_buffer[TXindice_lectura]); 
		TXindice_lectura++; 
	}
	else
	{// No hay datos disponibles para enviar
		TXindice_lectura = 0;
		TXindice_escritura = 0; 
	}

	/*
	 * productora de la lectura de datos
	 */
	// se ha recibido algún byte?
	if ( PC_IO_Receive_data  ( &dato )  != 0) 
	{  // Byte recibido. Escribir byte en buffer de entrada
		if (RXindex_escritura < RX_BUFFER_LENGTH)
		{
			RX_buffer [ RXindex_escritura ] = dato; // Guardar dato en buffer
			RXindex_escritura++; // Inc sin desbordar buffer
		}
		else
			;//Error_code = ERROR_UART_FULL_BUFF;
	}
}





/*
 * FUNCION CONSUMIDORA DE LA LECTURA 
 */
char PC_IO_Get_Char_From_Buffer (char* ch)
{
	// Hay nuevo dato en el buffer?
	if (RXindice_lectura <RXindex_escritura)
	{
		*ch = RX_buffer [ RXindice_lectura ];
		RXindice_lectura ++;
		return 1; // Hay nuevo dato
	}
	else  {
		
		RXindice_lectura=0;
		RXindex_escritura=0;
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
	//EL "Transmit Data Register Empty Flag" ESTE LLENO
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
char PC_IO_Receive_data  (char* dato)
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
