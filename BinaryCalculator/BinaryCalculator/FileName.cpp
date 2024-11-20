// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Fleger Dan
// notes in case you have problems with scanf you have to properties->C/C++->General->SDL Check switch to no sdl checks No (/sdl-)



#include <stdio.h>
#include <stdlib.h>



void and2numbers();
void or2numbers();
void xor2numbers();
void complement1st();
void complement2nd();
void set_bit();
void clear_bit();
void toggle_bit();

int main()
{

	int option = 1u;
	while (option != 0u)
	{
		printf("BinaryCalculator\n\n");
		printf("Choose an option:\n");
		printf("1. & between 2 numbers (and)\n");
		printf("2. | between 2 numbers (or)\n");
		printf("3. ^ between 2 numbers (xor)\n");
		printf("4. 1st complement\n");
		printf("5. 2nd complement\n");
		printf("6. set a bit for a number\n");
		printf("7. clear a bit for a number\n");
		printf("8. toggle a bit for a number\n");
		printf("0: exit\n");
		printf("YourInput:");

		scanf("%d", &option);
		switch (option)
		{
		case 1:
			break;
		}
		system("cls");
	}

}

void and2numbers()
{

}
void or2numbers()
{

}
void xor2numbers()
{

}
void complement1st()
{

}
void complement2nd()
{

}
void set_bit()
{

}
void clear_bit()
{

}
void toggle_bit()
{

}
