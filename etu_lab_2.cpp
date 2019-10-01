﻿#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

void print_array(short int amount_of_elements, short int *arr)
//Процедура для вывода массива arr длины amount_of_elements в консоль, 10 элементов на строку.
//Если количество элементов в массиве больше 200, печатает по 20 элементов в строке.
//Если количество элементов в массиве больше 600, печатает по 40 элементов в строке.
//Если значение элемента массива меньше 10 (у числа только 1 разряд), перед ним в консоль печатается дополнительный пробел.
//После выполнения процедуры курсор переводится на две строки вниз.
{
	short int counter = 0;
	if (amount_of_elements <= 200)
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 10 == 0 and counter != 0)
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << "\n";
				else
					cout << " " << arr[counter] << "\n";
			}
			else
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << " ";
				else
					cout << " " << arr[counter] << " ";
			}
		}
		if (amount_of_elements % 10 != 0)
		{
			cout << "\n";
		}
	}
	else if (amount_of_elements <= 600)
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 20 == 0 and counter != 0)
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << "\n";
				else
					cout << " " << arr[counter] << "\n";
			}
			else
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << " ";
				else
					cout << " " << arr[counter] << " ";
			}
		}
		if (amount_of_elements % 20 != 0)
		{
			cout << "\n";
		}
	}
	else
	{
		for (counter; counter < amount_of_elements; counter++)
		{
			if ((counter + 1) % 40 == 0 and counter != 0)
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << "\n";
				else
					cout << " " << arr[counter] << "\n";
			}
			else
			{
				if (arr[counter] >= 10)
					cout << arr[counter] << " ";
				else
					cout << " " << arr[counter] << " ";
			}
		}
		if (amount_of_elements % 40 != 0)
		{
			cout << "\n";
		}
	}
	cout << "\n";
}

void randomize_array(short int amount_of_elements, short int *arr)
//Процедура заполняет массив arr длины amount_of_elements случайными значениями [srand(time(NULL))] в диапазоне от 0 до 99 (int).
{
	srand(time(NULL));
	short int counter = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		arr[counter] = rand() % 100;
	}
}

void bubble_sort(short int amount_of_elements, short int *arr)
{
	short int exchange;
	short int i = 0; //Переменная-счетчик для цикла for.
	short int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;

		for (i; i < amount_of_elements - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = exchange;
				early_exit += 1;
			}
		}
		amount_of_elements -= 1;
		i = 0;
	} while (early_exit != 0);
	unsigned int end_time = clock();
	cout << float(end_time - start_time) / 1000 << " sec\n\n";
}

void shaker_sort(short int amount_of_elements, short int *arr)
{
	short int left_border = 0;
	short int right_border = 0;
	short int exchange;
	long int early_exit; //Отвечает за досрочный выход из цикла при завершении сортировки.
	short int i; //Переменная-счетчик для цикла for.
	unsigned int start_time = clock();
	do
	{
		early_exit = 0;
		i = left_border;
		for (i; i < amount_of_elements - right_border - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = exchange;
				early_exit += 1;
			}
		}
		right_border += 1;
		i = amount_of_elements - right_border - 1; //Т.к. в массивах индексы нумеруются с нуля.
		for (i; i > left_border - 1; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				exchange = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = exchange;
				early_exit += 1;
			}
		}
		left_border += 1;
	} while (early_exit != 0);
	unsigned int end_time = clock();
	cout << float(end_time - start_time) / 1000 << " sec\n\n";
}

void number_of_averages(short int amount_of_elements, short int *arr) //between the minimum and maximum values ​​in the array.
//Требует на вход уже отсортированый в порядке возрастания массив!
{
	short int averages = (arr[0] + arr [amount_of_elements - 1]) / 2;
	short int counter = 0;
	short int for_return = 0;
	for (counter; counter < amount_of_elements; counter++)
	{
		if (arr[counter] == averages)
		{
			for_return += 1;
			if (arr[counter + 1] > arr[counter] and counter != amount_of_elements - 1)
			{
				break;
			}
		}
	}
	cout << "Averages = " << averages << "\n\n";
	cout << "Number of averages between the minimum and maximum values in the array = " << for_return << "\n\n";
}

void less_than_a(short int amount_of_elements, short int* arr)
//Требует на вход уже отсортированый в порядке возрастания массив!
{
	short int counter = amount_of_elements - 1;
	short int a;
	cout << "Enter the number 'a'(from -32767 before 32767 and only integer!)\n";
	cout << "The number of elements less than 'a' will be displayed\n";
	cin >> a;
	for (counter; 0 <= counter; counter--)
	{
		if (arr[counter] < a)
		{
			cout << "Answer: " << counter + 1 << "\n\n";
			return;
		}
	}
	cout << "There are no such elements in the array!\n\n";
}

void more_than_b(short int amount_of_elements, short int* arr)
//Требует на вход уже отсортированый в порядке возрастания массив!
{
	short int counter = 0;
	short int b;
	cout << "Enter the number 'b'(from -32767 before 32767 and only integer!)\n";
	cout << "The number of elements more than 'b' will be displayed\n";
	cin >> b;
	for (counter; counter < amount_of_elements; counter++)
	{
		if (arr[counter] > b)
		{
			cout << "Answer: " << amount_of_elements - counter << "\n\n";
			return;
		}
	}
	cout << "There are no such elements in the array!\n\n";
}

int main()
{
	char end = 'y';
	while (end == 'y')
	{
		const short int N = 32767; //Размер массива (Натуральные числа до 32767 включая, "0" не включен).
		short int *random_array = new short int[N]; //Массив помещается в "кучу", для стабильной работы стека.
		
		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);


		//Bubble sort
		bubble_sort(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Bubble sort:\n\n";
		print_array(N, random_array);

		//Заполняем массив random_array случайными элементами и выводим его в консоль.
		randomize_array(N, random_array);
		cout << "random_array before sorting:\n\n";
		print_array(N, random_array);


		//Shaker sort
		shaker_sort(N, random_array);
		//Распечатываем отсортированный массив.
		cout << "Shaker sort:\n\n";
		print_array(N, random_array);

		//Вывод в консоль мин. и макс. элемента из сортированого random_array.
		cout << "Minimum = " << random_array[0] << "\n";
		cout << "Maximum = " << random_array[N - 1] << "\n\n";

		//Выводит количество элементов, равных среднему значения max и min.
		number_of_averages(N, random_array);

		//Выводит количество элементов в массиве, меньше "a"
		less_than_a(N, random_array);
		//Выводит количество элементов в массиве, больше "b"
		more_than_b(N, random_array);

		//Проверка на повторный запуск программы
		cout << "Run this program again now? (y/n)(one lowercase letter and 'Enter')\n\n";
		cin >> end;
	}
	return 0;
}