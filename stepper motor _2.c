/***********************************************************************/
/* Author : Prasanna */
/* Date   : 07-12-2022 */
/* Filename: STEPPER_MOTOR_FORWARD_1/2_REVERS_1_AND_FORWARD_1_REVERS_1*/
/* Description :STEPPER_MOTOR_ROTATE  */
/***********************************************************************/
#include<htc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_ON & LVP_OFF);

char arr[]={0x07,0x03,0x0B,0x09,0x0D,0x0C,0x0E,0x06}; //FOR STEPPER MOTOR CODE
int i,j;
int main()	
{
    TRISC =0;          //FOR STEPPER MOTOR INPUT PIN
    PORTC=0x00;
    TRISB0 =0;			//FOR BLINK LED 
    TRISB1 =0;			//FOR BLINK LED 
    TRISB2 =0;			//FOR BLINK LED
    TRISB3 =0;			//FOE BLINK LED 
    
    while(1)
  {
	for(i=0; i<25; i++)		//FOR MOTOR ROTATE HOW MUCH WE NEED 
	{
		for(j=0; j<8; j++)	//FOR COIL ROTATE FORWARD
		{
			PORTC =arr[j];	//FOR COIL CODE
			__delay_ms(20);
			PORTB =0x01;   	//FOR BLINK LED
			__delay_ms(10);
		}	
	 }  
   __delay_ms(1000); 		 //FOE DELAY FEW SECOND
	for(i=25; i>=0; i--) 	 //FOR MOTOR ROTATE HOW MUCH WE NEED 
	{
		for(j=8; j>=0; j--)	 //FOR COIL ROTATE REVERS
		{
			PORTC =arr[j];	//FOR COIL CODE
			__delay_ms(20);
			PORTB =0x02;	//FOR BLINK LED
			__delay_ms(10);	
		}	
	 }  
	   __delay_ms(1000); 	//FOE DELAY FEW SECOND
	for(i=0; i<50; i++)		//FOR MOTOR ROTATE HOW MUCH WE NEED 
	{
		for(j=0; j<7; j++)	//FOR COIL ROTATE FORWARD
		{
			PORTC =arr[j];	//FOR COIL CODE
			__delay_ms(20);
			PORTB =0x04;	//FOR BLINK LED
			__delay_ms(10);	
		}	
	 }
	 __delay_ms(1000);   	//FOE DELAY FEW SECOND
	 	for(i=50; i>=0; i--)//FOR MOTOR ROTATE HOW MUCH WE NEED 
	{
		for(j=8; j>=0; j--)	//FOR COIL ROTATE REVERS
		{
			PORTC =arr[j];	//FOR COIL CODE
			__delay_ms(20);
			PORTB =0x08;	//FOR BLINK LED
			__delay_ms(10);	
		}	
	 }
	  __delay_ms(1000);   //FOE DELAY FEW SECOND
  }					
	
}

	
