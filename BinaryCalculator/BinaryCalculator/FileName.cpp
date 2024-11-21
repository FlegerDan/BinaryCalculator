// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Fleger Dan
// notes in case you have problems with scanf you have to properties->C/C++->General->SDL Check switch to no sdl checks No (/sdl-)

/*** to do: check for more bugs that means testing manually or automatically*/
/*** to do: check if you can implement more operations like add, sub and so on */

#include <stdio.h>
#include <stdlib.h>


void string_allocation(char** string, int length);
void write_binary_string(char* string, bool which);
void write_binary_string(char* string);
bool binary_validation_string(char* string,int length);
int size_binary_string(char* string);
void print_binary_string(char* string);
void and2numbers();
void or2numbers();
void xor2numbers();
void ones_complement();
void second_complement();
void set_bit();
void clear_bit();
void toggle_bit();
void shift_left();
void shift_right();

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
		printf("4. ones complement\n");
		printf("5. second complement\n");
		printf("6. set a bit for a number\n");
		printf("7. clear a bit for a number\n");
		printf("8. toggle a bit for a number\n");
		printf("9. shifting a number to the left by n bits (logic shifting)\n");
		printf("10. shifting a number to the right by n bits (logic shifting)\n");
		printf("0: exit\n");
		printf("YourInput:");

		scanf("%d", &option);
		switch (option)
		{
		case 1:
			and2numbers();
			system("pause");
			break;
		case 2:
			or2numbers();
			system("pause");
			break;
		case 3:
			xor2numbers();
			system("pause");
			break;
		case 4:
			ones_complement();
			system("pause");
			break;
		case 5:
			second_complement();
			system("pause");
			break;
		case 6:
			set_bit();
			system("pause");
			break;
		case 7:
			clear_bit();
			system("pause");
			break;
		case 8:
			toggle_bit();
			system("pause");
			break;
		case 9:
			shift_left();
			system("pause");
			break;
		case 10:
			shift_right();
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
void write_binary_string(char* string)
{
	int length;
	do
	{
		system("cls");
		printf("please insert a maximum 32 bit number for example: 11010\n");
		printf("please insert a number:");
		scanf("%s", string);
		length = size_binary_string(string);
		binary_validation_string(string, length);
		//printf("\n %d \n", size_binary_string(string));
	} while (length > 32 || (false == binary_validation_string(string, length)));

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
void print_binary_string(char* string)
{
	int hold = 0;
	for (int i = 0; i < 32; i++)
	{
		if (string[i] == '1')
		{
			hold = i;
			break;
		}
	}
	for (int i = hold; i < 32; i++)
	{
		if (string[i] == '1' or string[i] == '0') // can make problems if the random char are 1 or 0 
		{
			printf("%c", string[i]);
		}
		
	}
}
void and2numbers()
{
	char* number1;
	char* number2;
	char* result;
	int length_number1 = 0;
	int length_number2 = 0;
	string_allocation(&number1, 33);
	string_allocation(&number2, 33);
	string_allocation(&result, 32);
	write_binary_string(number1,false);
	write_binary_string(number2,true);
	number1[32] = '\0';
	number2[32] = '\0';
	
	length_number1 = size_binary_string(number1)-1;
    length_number2 = size_binary_string(number2)-1;
	
	for (int i = 31; i >= 0; i--)
	{
		if (length_number1 >= 0)
		{
			number1[i] = number1[length_number1];
			length_number1--;
		}
		else
		{
			number1[i] = '0';
		}

		if (length_number2 >= 0)
		{
			number2[i] = number2[length_number2];
			length_number2--;
		}
		else
		{
			number2[i] = '0';
		}
	}
	number1[32] = '\0';
	number2[32] = '\0';

	for (int i = 0; i < 32; i++)
	{
		if (number1[i] == '0' && number2[i] == '0')
		{
			result[i] = '0';
		}
		if (number1[i] == '1' && number2[i] == '0')
		{
			result[i] = '0';
		}
		if (number1[i] == '0' && number2[i] == '1')
		{
			result[i] = '0';
		}
		if (number1[i] == '1' && number2[i] == '1')
		{
			result[i] = '1';
		}
	}

	printf("the result of ");
	print_binary_string(number1);
	printf(" in and with ");
    print_binary_string(number2);
	printf(" is ");
	print_binary_string(result);
	printf("\n");
	free(number1);
	free(number2);
	free(result);
}
void or2numbers()
{
	char* number1;
	char* number2;
	char* result;
	int length_number1 = 0;
	int length_number2 = 0;
	string_allocation(&number1, 33);
	string_allocation(&number2, 33);
	string_allocation(&result, 32);
	write_binary_string(number1, false);
	write_binary_string(number2, true);

	length_number1 = size_binary_string(number1) - 1;
	length_number2 = size_binary_string(number2) - 1;

	for (int i = 31; i >= 0; i--)
	{
		if (length_number1 >= 0)
		{
			number1[i] = number1[length_number1];
			length_number1--;
		}
		else
		{
			number1[i] = '0';
		}

		if (length_number2 >= 0)
		{
			number2[i] = number2[length_number2];
			length_number2--;
		}
		else
		{
			number2[i] = '0';
		}
	}
	number1[32] = '\0';
	number2[32] = '\0';

	for (int i = 0; i < 32; i++)
	{
		if (number1[i] == '0' && number2[i] == '0')
		{
			result[i] = '0';
		}
		if (number1[i] == '1' && number2[i] == '0')
		{
			result[i] = '1';
		}
		if (number1[i] == '0' && number2[i] == '1')
		{
			result[i] = '1';
		}
		if (number1[i] == '1' && number2[i] == '1')
		{
			result[i] = '1';
		}
	}

	printf("the result of ");
	print_binary_string(number1);
	printf(" in or with ");
	print_binary_string(number2);
	printf(" is ");
	print_binary_string(result);
	printf("\n");
	free(number1);
	free(number2);
	free(result);
}
void xor2numbers()
{
	char* number1;
	char* number2;
	char* result;
	int length_number1 = 0;
	int length_number2 = 0;
	string_allocation(&number1, 33);
	string_allocation(&number2, 33);
	string_allocation(&result, 32);
	write_binary_string(number1, false);
	write_binary_string(number2, true);

	length_number1 = size_binary_string(number1) - 1;
	length_number2 = size_binary_string(number2) - 1;

	for (int i = 31; i >= 0; i--)
	{
		if (length_number1 >= 0)
		{
			number1[i] = number1[length_number1];
			length_number1--;
		}
		else
		{
			number1[i] = '0';
		}

		if (length_number2 >= 0)
		{
			number2[i] = number2[length_number2];
			length_number2--;
		}
		else
		{
			number2[i] = '0';
		}
	}
	number1[32] = '\0';
	number2[32] = '\0';

	for (int i = 0; i < 32; i++)
	{
		if (number1[i] == '0' && number2[i] == '0')
		{
			result[i] = '0';
		}
		if (number1[i] == '1' && number2[i] == '0')
		{
			result[i] = '1';
		}
		if (number1[i] == '0' && number2[i] == '1')
		{
			result[i] = '1';
		}
		if (number1[i] == '1' && number2[i] == '1')
		{
			result[i] = '0';
		}
	}

	printf("the result of ");
	print_binary_string(number1);
	printf(" in xor with ");
	print_binary_string(number2);
	printf(" is ");
	print_binary_string(result);
	printf("\n");
	free(number1);
	free(number2);
	free(result);
}
void ones_complement()
{
	char* number;
	int length_number = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	printf("\n here is the questions should I do only for the entire 32 bits or only for the length of the number, like if it's only 1100 should be 0011\n");
	printf("\n so the number that you introduced is:");
	print_binary_string(number);
	printf("\n first result:");
	for (int i = 0; i <= length_number; i++)
	{
		if (number[i] == '1')
		{
			number[i] = '0';
		}
		else
		{
			number[i] = '1';
		}
	}
	print_binary_string(number);
	printf("\n second result:");
	for (int i = 0; i <= length_number; i++)
	{
		if (number[i] == '1')
		{
			number[i] = '0';
		}
		else
		{
			number[i] = '1';
		}
	}
	for (int i = 31; i >= 0; i--)
	{
		if (length_number >= 0)
		{
			number[i] = number[length_number];
			length_number--;
		}
		else
		{
			number[i] = '0';
		}
	}
	number[32] = '\0';
	for (int i = 0; i < 32; i++)
	{
		if (number[i] == '1')
		{
			number[i] = '0';
		}
		else
		{
			number[i] = '1';
		}
	}
	print_binary_string(number);
	printf("\n yep I did both \n");
	free(number);

}
void second_complement()
{
	char* number;
	int length_number = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	printf("\n so two's complement, well if the number is positive the two's complement is the positive number and for negative number well we have to calculate\n");
	printf("\n for a 32 bits we will consider the following format: 1 sign bit|the rest of them will be the value, so basically the first bit is the sign bit so for positive you will have to write like this:0101\n");
	if (number[0] == '0')
	{
		printf("the result:");
		print_binary_string(number);
	}
	else
	{
		for (int i = 1; i <= length_number; i++)
		{
			if (number[i] == '1')
			{
				number[i] = '0';
			}
			else
			{
				number[i] = '1';
			}
		}
		char overload = '0';
		for (int i = length_number; i >= 1; i--)
		{
			if (i == length_number)
			{
				overload = number[i] + 1; // that means you will make '1' or '2' 
				if (overload == '2')
				{
					overload = '1';
					number[i] = '0';
				}
				else
				{
					overload = '0';
					number[i] = '1';
				}
			}
			else
			{
				
				if (overload == '1')
				{
					overload = number[i] + (overload - 48);
					if (overload == '2')
					{
						overload = '1';
						number[i] = '0';
					}
					else
					{
						overload = '0';
						number[i] = '1';
					}
				}
			}
		}
		printf("the result:");
		print_binary_string(number);
	}
	printf("\n");
	free(number);
}
void set_bit()
{
	char* number;
	int length_number = 0;
	int n_bit = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	// so normally to set the n bit is (number | (1<<n))
	for (int i = 31; i >= 0; i--)
	{
		if (length_number >= 0)
		{
			number[i] = number[length_number];
			length_number--;
		}
		else
		{
			number[i] = '0';
		}
	}
	number[32] = '\0';
	
	do
	{
		system("cls");
		printf("another important thing if you write let's say 0, like you want to set the bit 0 the array is basically left to right, so I will consider 0 as 31\n");
		printf("please insert a number between 0 and 31, is to decide which bit to set:");
		scanf("%d", &n_bit);
	} while (n_bit > 31);
	printf("the number before the operation:");
	print_binary_string(number);
	n_bit = 31 - n_bit;
	number[n_bit] = '1';
	printf("\nand the result:");
	print_binary_string(number);
	printf("\n");
	free(number);
}
void clear_bit()
{
	char* number;
	int length_number = 0;
	int n_bit = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	// so normally to clear the n bit is (number & ~(1<<n))
	for (int i = 31; i >= 0; i--)
	{
		if (length_number >= 0)
		{
			number[i] = number[length_number];
			length_number--;
		}
		else
		{
			number[i] = '0';
		}
	}
	number[32] = '\0';

	do
	{
		system("cls");
		printf("another important thing if you write let's say 0, like you want to clear the bit 0 the array is basically left to right, so I will consider 0 as 31\n");
		printf("please insert a number between 0 and 31, is to decide which bit to clear:");
		scanf("%d", &n_bit);
	} while (n_bit > 31);
	printf("the number before the operation:");
	print_binary_string(number);
	n_bit = 31 - n_bit;
	number[n_bit] = '0';
	printf("\nand the result:");
	print_binary_string(number);
	printf("\n");
	free(number);
}
void toggle_bit()
{
	char* number;
	int length_number = 0;
	int n_bit = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	// so normally to toggle the n bit is (number ^ (1<<n))
	for (int i = 31; i >= 0; i--)
	{
		if (length_number >= 0)
		{
			number[i] = number[length_number];
			length_number--;
		}
		else
		{
			number[i] = '0';
		}
	}
	number[32] = '\0';

	do
	{
		system("cls");
		printf("another important thing if you write let's say 0, like you want to toggle the bit 0 the array is basically left to right, so I will consider 0 as 31\n");
		printf("please insert a number between 0 and 31, is to decide which bit to toggle:");
		scanf("%d", &n_bit);
	} while (n_bit > 31);
	printf("the number before the operation:");
	print_binary_string(number);
	n_bit = 31 - n_bit;
	if (number[n_bit] == '0')
	{
		number[n_bit] = '1';
	}
	else
	{
		number[n_bit] = '0';
	}
	printf("\nand the result:");
	print_binary_string(number);
	printf("\n");
	free(number);
}
void shift_left()
{
	char* number;
	int length_number = 0;
	int n_bit = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	// normally the shifting is number<<k_pos or >> 
	do
	{
		system("cls");
		printf("please insert a number between 0 and 31, is to decide with how many bits to shift:");
		scanf("%d", &n_bit);
	} while (n_bit > 31);
	for (int i = 31; i >= 0; i--)
	{
		if (length_number >= 0)
		{
			number[i] = number[length_number];
			length_number--;
		}
		else
		{
			number[i] = '0';
		}
	}
	number[32] = '\0';
	printf("the number before shifting:");
	print_binary_string(number);
	for (int i = 0; i < n_bit; i++)
	{
		for (int i = 1; i < 32; i++)
		{
			number[i - 1] = number[i];
		}
		number[31] = '0';
	}
	printf("\nand the result:");
	print_binary_string(number);
	printf("\n");
	free(number);
}
void shift_right()
{
	char* number;
	int length_number = 0;
	int n_bit = 0;
	string_allocation(&number, 33);
	write_binary_string(number);
	length_number = size_binary_string(number) - 1;
	// normally the shifting is number<<k_pos or >> 
	do
	{
		system("cls");
		printf("please insert a number between 0 and 31, is to decide with how many bits to shift:");
		scanf("%d", &n_bit);
	} while (n_bit > 31);
	for (int i = 31; i >= 0; i--)
	{
		if (length_number >= 0)
		{
			number[i] = number[length_number];
			length_number--;
		}
		else
		{
			number[i] = '0';
		}
	}
	number[32] = '\0';
	printf("the number before shifting:");
	print_binary_string(number);
	for (int i = 0; i < n_bit; i++)
	{
		for (int i = 30; i >=0; i--)
		{
			number[i + 1] = number[i];
		}
		number[0] = '0';
	}
	printf("\nand the result:");
	print_binary_string(number);
	printf("\n");
	free(number);
}