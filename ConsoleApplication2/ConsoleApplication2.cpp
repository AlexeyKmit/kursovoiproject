#include <iostream>
#include<random>
#include<chrono>
using namespace std;

void MainMenu();
int BinarySearch(int*, int, int, int);
int LinearSearch(int*, int, int);
int main()
{
	system("chcp 1251 & cls");
	MainMenu();
	system("pause");
	return 0;
}

void MainMenu()
{
	int menuParam;

	do
	{
		cout << "1. ����� �������� � ��������� �������" << endl;
		cout << "2. ����� �������� � �������� �������" << endl;
		cout << "3. �����" << endl;
		cin >> menuParam;
		switch (menuParam)
		{
		case 1: 
		{
			using clock = chrono::system_clock;
			system("cls");
			int arrSize;
			cout << "������� ����������� �������: ";
			cin >> arrSize;
			int* array = new int[arrSize];
			system("cls");

			for (int i = 0; i < arrSize;i++)
			{
				array[i] =rand();
				cout << "������� " << i <<": " << array[i] << endl;
			}

			int numberToFind;
			cout << "������� ����� ��� ������: ";
			cin >> numberToFind;

			auto start = clock::now();
			int numberCell = BinarySearch(array, 0, arrSize, numberToFind);
			auto end = clock::now();

			if (numberCell >= 0)
				cout << "������� ����� ��������� � ������ " << numberCell << endl;
			else
				cout << "������� ����� ��� � �������" << endl;

			cout << "�������� ��������� ������ �������� " << (chrono::duration<double, milli>(end - start)).count() << " ������" << endl;

			start = clock::now();
			numberCell = LinearSearch(array, numberToFind, arrSize);
			end = clock::now();

			if (numberCell >= 0)
				cout << "������� ����� ��������� � ������ " << numberCell << endl;
			else
				cout << "������� ����� ��� � �������" << endl;

			cout << "�������� ��������� ������ �������� " << (chrono::duration<double, milli>(end - start)).count() << " ������" << endl;
			system("pause");
			system("cls");

		}
			break;

		case 2: 
		{
			using clock = chrono::system_clock;
			system("cls");
			system("cls");
			int arrSize;
			cout << "������� ����������� �������: ";
			cin >> arrSize;
			int* array = new int[arrSize];
			system("cls");
			for (int i = 0; i < arrSize;i++)
			{
				cout << "������� ������� " << i << ": ";
				cin >> array[i];
			}
			system("cls");
			for (int i = 0; i < arrSize;i++)
			{
				cout << "������� " << i << ": " << array[i] << endl;
			}
			int numberToFind;
			cout << "������� ����� ��� ������: ";
			cin >> numberToFind;

			auto start = clock::now();
			int numberCell = BinarySearch(array, 0, arrSize, numberToFind);
			auto end = clock::now();

			if (numberCell >= 0)
				cout << "������� ����� ��������� � ������ " << numberCell << endl;
			else
				cout << "������� ����� ��� � �������" << endl;

			cout << "�������� ��������� ������ �������� " << (chrono::duration<double, milli>(end - start)).count() << " ������" << endl;

			start = clock::now();
			numberCell = LinearSearch(array, numberToFind, arrSize);
			end = clock::now();

			if (numberCell >= 0)
				cout << "������� ����� ��������� � ������ " << numberCell << endl;
			else
				cout << "������� ����� ��� � �������" << endl;

			cout << "�������� ��������� ������ �������� " << (chrono::duration<double, milli>(end - start)).count() << " ������" << endl;
			system("pause");
			system("cls");
		}
			break;

		case 3: 
			break;

		default:
			system("cls");
			cout << "������� �������� ��������!"<< endl;
			system("pause");
			system("cls");
			break;
		}
	} 
	while (menuParam != 3);

}

int BinarySearch(int* array, int left, int right, int numberToFind)
{
	
	int mid = 0;
	while (1)
	{
		mid = (left + right) / 2;

		if (numberToFind < array[mid])       
			right = mid - 1;      
		else if (numberToFind > array[mid])  
			left = mid + 1;   
		else                       
			return mid;           

		if (left > right)         
			return -1;
	}
}

int LinearSearch(int* array, int numberToFind, int arraySize)
{
	for (int i = 0;i < arraySize;i++)
		if (array[i] == numberToFind)
			return i;

	return -1;
}