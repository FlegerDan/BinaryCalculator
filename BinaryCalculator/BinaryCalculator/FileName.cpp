// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Fleger Dan
// notes in case you have problems with scanf you have to properties->C/C++->General->SDL Check switch to no sdl checks No (/sdl-)



#include <stdio.h>
#include <stdlib.h>


void string_allocation(char** string, int length);
void write_binary_string(char* string, bool which);
bool binary_validation_string(char* string,int length);
int size_binary_string(char* string);
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
			and2numbers();
			system("pause");
			break;
		}
		system("cls");
	}

}
void string_allocation(char** string, int length)
{
	*string = (char*)(malloc(sizeof(char) * length));
}
void write_binary_string(char* string,bool which)
{
	int length;
	do
	{
		system("cls");
		printf("please insert a maximum 32 bit number for example: 11010\n");
		if (false == which)
		{
			printf("please insert first number:");
		}
		else
		{
			printf("please insert second number:");
		}
		scanf("%s", string);
		length = size_binary_string(string);
		binary_validation_string(string, length);
		//printf("\n %d \n", size_binary_string(string));
	} while (length > 32 || (false==binary_validation_string(string, length)));
	

}
bool binary_validation_string(char* string,int length)
{
	bool ok = true;
	for (int i = 0; i < length; i++)
	{
		if (string[i] != '1' and string[i] != '0')
		{
			ok = false;
		}
	}
	return ok;
}
int size_binary_string(char* string)
{
	int length=0;
	while (string[length] != NULL)
	{
		length++;
	}
	return length;
}
void and2numbers()
{
	char* number1;
	char* number2;
	string_allocation(&number1, 32);
	string_allocation(&number2, 32);
	
	write_binary_string(number1,false);
	write_binary_string(number2,true);
	
	printf("%s", number1);
	printf("%s", number2);
	/*
	int number1 = 0u;
	int number2 = 0u;
	system("cls");
	printf("Option & between 2 numbers ( the input will be integer (int) and the result also integer but printed in binary )\n");
	printf("Please introduce the first number:");
	scanf("%d", &number1);
	printf("\n");
	printf("Please introduce the second number:");
	scanf("%d", &number2);
	printf("\n");
	number1 = number1 & number2;
	printf("%b", number1);
	*/
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
