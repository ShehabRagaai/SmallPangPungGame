#include"STD_TYPES.h"
#include"PORT_interface.h"
#include"DIO_interface.h"
#include"GIE_interface.h"
#include"EXTI_interface.h"
#include<util/delay.h>
#include"CLCD_interface.h"
#include"BIT_MATH.h"
void ISR_INT0(void);
void ISR_INT1(void);


u8 Global_ConterSW1=0;
u8 Global_ConterSW2=0;
u8 Global_PlayerArray[8]={0b00011111,0b00010001,0b00010001,0b00010001,0b00010001,0b00010001,0b00010001,0b00011111};
void main(void)
{

	u8 Local_Flag=0;
	u8 Local_Flag2=0;
	s8 Local_ForCounter;
	u8 counter;


	PORT_voidInit();
	CLCD_voidInit();


	EXIT_u8INT0TakeAddress(ISR_INT0);
	EXIT_u8INT1TakeAddress(ISR_INT1);



	GIE_voidEnable();
	EXTI_Int00Init();
	EXTI_Int1Init();



	CLCD_WriteSpecialCharacter(Global_PlayerArray,0,0,0);
	CLCD_WriteSpecialCharacter(Global_PlayerArray,0,0,15);


	while(1)

	{
		for(counter=0;counter<8;counter++)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,counter,DIO_u8PIN_HIGH);
			_delay_ms(250);
			DIO_u8SetPinValue(DIO_u8PORTA,counter,DIO_u8PIN_LOW);
		}

		if(Local_Flag2==0)
		{
			for(Local_ForCounter=1;Local_ForCounter<=15;Local_ForCounter++)
			{
				if(Local_ForCounter==15&&Global_ConterSW2==1)
				{
					CLCD_GoTOXY(0,Local_ForCounter);
					CLCD_voidSendData('o');
					CLCD_GoTOXY(1,2);
					CLCD_voidSendString("Player1Winer");

					Local_Flag=1;
					break;

				}

				if(Local_ForCounter==15)
				{
					continue;
				}


				CLCD_GoTOXY(0,Local_ForCounter);
				CLCD_voidSendData('o');
				_delay_ms(150);
				CLCD_voidCommand(1);

				if(Global_ConterSW1==1)
				{

					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,1,0);
				}
				else
				{


					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,0,0);
				}
				if(Global_ConterSW2==1)
				{

					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,1,15);

				}

				else
				{

					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,0,15);
				}
			}
		}

		else
		{
			break;
		}





		if(Local_Flag==0)
		{



			for(Local_ForCounter=14;Local_ForCounter>=0;Local_ForCounter--)
			{
				if(Local_ForCounter==0&&Global_ConterSW1==1)
				{
					CLCD_GoTOXY(0,Local_ForCounter);
					CLCD_voidSendData('o');
					CLCD_GoTOXY(1,2);
					CLCD_voidSendString("Player2Winer");

					Local_Flag2=1;
					break;
				}

				if(Local_ForCounter==0)
				{
					continue;
				}

				CLCD_GoTOXY(0,Local_ForCounter);
				CLCD_voidSendData('o');
				_delay_ms(150);
				CLCD_voidCommand(1);

				if(Global_ConterSW1==1)
				{

					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,1,0);
				}

				else
				{
					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,0,0);
				}




				if(Global_ConterSW2==1)
				{
					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,1,15);

				}

				else
				{
					CLCD_WriteSpecialCharacter(Global_PlayerArray,0,0,15);
				}
			}

		}

		else
		{

			break;
		}


	}
	while(1)
	{

	}

}


void ISR_INT0(void)
{


	CLCD_WriteSpecialCharacter(Global_PlayerArray,0,1,15);
	TOGGLE_BIT(Global_ConterSW2,0);

}


void ISR_INT1(void)
{


	CLCD_WriteSpecialCharacter(Global_PlayerArray,0,1,0);
	TOGGLE_BIT(Global_ConterSW1,0);

}

