#include <iostream>

/*Вдоль линии расположены лунки.В каждой лунке лежит красный, белый или синий шар.Одним ходом разрешается менять местами два любых шара.
Добиться того, чтобы все красные шары шли первыми, все синие – последними, а белые – посередине.*/

enum { RED, WHITE, BLUE };

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int* mas, int len)
{
	int iter = len * 3;
	for (int i = 0; i < iter; i++)
	{
		bool flag = true;
		for (int j = 0; j < len; j++)
		{
			if (mas[j] == WHITE && mas[j + 1] == RED)
			{
				swap(mas[j], mas[j + 1]);
				flag = false;
				break;
			}
			if (mas[j] == BLUE && mas[j + 1] == RED)
			{
				swap(mas[j], mas[j + 1]);
				flag = false;
				break;
			}
			if (mas[j] == BLUE && mas[j + 1] == WHITE)
			{
				swap(mas[j], mas[j + 1]);
				flag = false;
				break;
			}
		}
		if (flag)	break;
	}
}

/*void selectionSort(int* mas, int number)
{
	int iter = number * 3;
	for (int i = 0; i < iter; i++)
	{
		int smallestPosition = i;
		for (int j = 0; j < number; j++)
		{
			if (mas[j] < mas[smallestPosition])
			{
				swap(mas[j], mas[smallestPosition]);
				break;
			}
		}
	}
}*/

void selectionSort(int* mas, int len)
{
	int iter = len * 3;
	int j = -1;
	for (int i = 0; i < iter; i++)
	{
		j++;
		for (int k = j + 1; k < len; k++)
		{
			if (mas[j] > mas[k])
			{
				swap(mas[j], mas[k]);
				break;
			}
		}
		if (j == len)
			j = 0;
	}
}

void printMas(int* mas, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d", mas[i]);
	printf("\n");
}

int main()
{
	const int len = 9;
	int mas[len] = { 0,1,2,0,1,2,0,1,2 };
	//int mas[len] = { 2,2,2,1,1,1,0,0,0};

	//bubbleSort(mas, len);	
	/*Сложность в лучшем случае		O(n)
	  Сложность в среднем случае	O(n^2)
	  Сложность в худшем случае		O(n^2)*/

	selectionSort(mas, len);
	// Сложность в любом случае O(n^2)

	printMas(mas, len);
		
	return 0;
}