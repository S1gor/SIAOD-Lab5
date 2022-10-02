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

void selectionSort(int* mas, int len)
{
	int iter = len * 2;
	int tmp = -1;
	for (int i = 0; i < iter; i++)
	{
		tmp++;
		for (int j = tmp + 1; j < len; j++)
			if (mas[tmp] > mas[j])
			{
				swap(mas[tmp], mas[j]);
				break;
			}
		if (tmp == len)	tmp = -1;
	}
}

void printMas(int* mas, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d", mas[i]);
	printf("\n\n");
}

int selectSort()
{
	int choice;
	printf("Choose: 1 - bubble sort; 2 - selection sort.\nChoice:");
	do {
		scanf_s("%d", &choice);
	} while (choice > 2 || choice < 1);
	printf("\n");
	return choice;
}

int main()
{
	const int len = 9;
	int mas[len] = { 0,1,2,0,1,2,0,1,2 };

	printf("Before sorting:\t");
	printMas(mas, len);

	switch (selectSort())
	{
	case 1:								// Сложность в лучшем случае				O(n)
		bubbleSort(mas, len);			// Сложность в среднем и худшем случаях		O(n^2)
		break;							
	case 2:
		selectionSort(mas, len);		// Сложность в любом случае O(n^2)
		break;
	}

	printf("After sorting:\t");
	printMas(mas, len);

	return 0;
}