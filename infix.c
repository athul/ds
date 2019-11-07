//program to perform infix to postfix conversion
#include <stdio.h>
//#include<conio.h>
#include <string.h>
char input[25], stack[25], output[25], ip, prev;
int flag = 0, z = 0, i, ispi, icpi, y = 1, top = 0;
void opcheck()
{
	if ((ip == '+') || (ip == '-') || (ip == '*') || (ip == '/') || (ip == '^'))
		flag = 1;
	else if (ip == ')')
		flag = 3;
	else if (ip == '(')
		flag = 5;
	else
		flag = 0;
}
void isp()
{
	if ((prev == '+') || (prev == '-'))
		ispi = 2;
	else if ((prev == '*') || (prev == '/'))
		ispi = 4;
	else if (prev == '^')
		ispi = 5;
	else
		ispi = 8;
}
void icp()
{
	if ((ip == '+') || (ip == '-'))
		icpi = 1;
	else if ((ip == '*') || (ip == '/'))
		icpi = 3;
	else if (ip == '^')
		icpi = 6;
	else
		icpi = 7;
}
void priority()
{
	prev = stack[top];
	isp();
	icp();
}
void readstring()
{
	printf("\t enter the string:");
	gets(input);
	printf("%s", input);
	//getch();
}
void readsymbol()
{
	stack[0] = 'c';
	for (i = 1; input[i] != '\0'; i++)
	{
		ip = input[i];
		opcheck();
		if (flag == 1)
		{
			priority();
			if (ispi > icpi)
			{

				output[z] = stack[top];
				top = 1;
				z += 1;
			}
			else
			{
				top += 1;
				stack[top] = ip;
			}
		}
		else if (flag == 3)
		{
			do
			{
				output[z] = stack[top];
				z += 1;
				top = top - 1;
			} while (stack[top] != 'c');
			top = top - 1;
		}
		else if(flag == 5)
			{
				stack[top] = ip;
				top = top + 1;
			}
		else // operand
		{
			output[z] = ip;
			z += 1;
		}
	}
	// for loop close
}
// read symbol function close
void main()
{
	//clrscr();
	readstring();
	readsymbol();
	for (i = 0; output[i] != '\0'; i++)
	{
		printf("%c", output[i]);
	}
	//getch();
}
