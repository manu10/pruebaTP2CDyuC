//#include "SCI_Functions.h"
//
//
///**
// * SPI_PutChar:   This function sends a character through the SPI. 
// *
// * Parameters:    character to be sent
// *
// * Subfunctions:  none.
// *
// * Return:        void
// */ 
//void SCI_PutChar(char send) 
//{
//  
//  while(!SCIS1_TDRE);
//  SCID  = send;    
//}//end SPI_PutChar
//
///**
// * SPI_GetChar:   This function receives a character through the SPI 
// *
// * Parameters:    none
// *
// * Subfunctions:  none.
// *
// * Return:        character recieved
// */ 
//
//char SCI_GetChar(void) 
//{
//  char dummy;
//  
//  while(!SCIS1_RDRF);
//  dummy = SCIS1;
//  return SCID;  
//} //end SPI_GetChar 
//
///**
// * SCI_Init_20M_115200: This function initial the terminal. 
// *
// * Parameters:             void
// *
// * Subfunctions:           none.
// *
// * Return:                 void
// */ 
////void SCI_Init_20M_115200(void) 
////{
////  SCIBDH = 0;
////  SCIBDL = 0xB;
////  SCIC1  = 0;
////  SCIC2  = 0x0C;   
////}//end SCI_Init_20M_115200
//
///**
// * SCI_Init_16M_115200: This function initial the terminal. 
// *
// * Parameters:             void
// *
// * Subfunctions:           none.
// *
// * Return:                 void
// */ 
//void SCI_Init(void) 
//{
//  SCIBD = 52;
//  SCIC1  = 0;
//  SCIC2  = 0x0C;   
//}//end SCI_Init_16M_115200
//
//void SCI_enviar_cadena (const char* cadena){
//	char aux[13];
//	aux[0]=cadena[0];
//	aux[1]=cadena[1];
//	aux[2]=cadena[2];
//	aux[3]=cadena[3];
//	aux[4]=cadena[4];
//	aux[5]=cadena[5];
//	aux[6]=cadena[6];
//	aux[7]=cadena[7];
//	aux[8]=cadena[8];
//	aux[9]=cadena[9];
//	aux[10]=cadena[10];
//	aux[11]=cadena[11];
//	aux[12]=cadena[12];
//	
//	while(*cadena!=0){
//		SCI_PutChar(*cadena);
//		++cadena;
//	}
//	SCI_PutChar('\n');
//}
//
//
//
//
