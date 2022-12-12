#include <iostream>
#include "DynamicArray.h"
using namespace std;

int CheckingForDigit(string outputString)
{
	if (outputString != "")
	{
		cout << outputString;
	}

	int value;

	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nError has been detected. Try again! \nEnter task number: ";
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (cin.gcount() > 1)
		{
			cout << "\nError has been detected. Try again! \nEnter task number: ";
			continue;
		}

		break;
	}

	return value;
}

int main()
{
	DynamicArray* array = new DynamicArray;
	cout << "1. Create Dynamic Array\n"
			"2. Initializing an array with random numbers\n"
			"3. Show array\n4. Bubble sort\n"
			"5. Push back\n"
			"6. Push forward\n"
			"7. Insert element in some index\n"
			"8. Linear Search\n"
			"9. Binary Search\n"
			"10. Remove Element\n";
	while (true)
	{	
		//TODO: input sanitizing                        ,          duplication is fixed
		int taskNumber = CheckingForDigit("Enter task number: ");
		cout << endl;
		if (taskNumber <=10 && taskNumber >= 1)
		{
			switch (taskNumber)
			{
				case 1:
				{
					CreateDynamicArray(array);
					cout << "Array is created.\n" << endl;
					break;
				}
				case 2:
				{
					int length = CheckingForDigit("Enter length of your dynamic array: ");
					FillArray(array, length);
					cout << "\n";
					break;
				}
				case 3:
				{
					for (int i = 0; i < array->Length; i++)
					{
						cout << array->Array[i] << "\t";
					}

					cout << endl;
					break;
				}
				case 4:
				{
					BubbleSort(array);
					cout << "Array is sorted.\n" << endl;
					break;
				}
				case 5:
				{
					int element = CheckingForDigit("Enter element which u want push back: ");
					PushBack(array, element);
					cout << "\n";
					break;
				}
				case 6:
				{
					int element = CheckingForDigit("Enter element which u want push forward: ");
					PushForward(array, element);
					cout << "\n";
					break;
				}
				case 7:
				{
					int element = CheckingForDigit("Enter element which u want add: ");
					int index = CheckingForDigit("Enter index of element which u want add: ");
					InsertElement(array, element, index);
					break;
				}
				case 8:
				{
					int element = CheckingForDigit("Enter element which u want find with Linear Search: ");;
					int index;
					index = LinearSearch(array, element);
					if (index == -1)
					{
						cout << "There os no such value in the arrray." << endl;
					}
					else
					{
						cout << "Index of this element: " << index << endl;
					}
					cout << "\n";
					break;
				}
				case 9:
				{
					int element = CheckingForDigit("Enter element which u want find with Binary Search: ");;
					int index;
					index = BinarySearch(array, element);
					if (index != -1)
					{
						cout << "Element which you search " << element << " in index: " << index << endl;
					}
					else
					{
						cout << "There is no such value in the array." << endl;
					}
					cout << "\n";
					break;
				}
				case 10: 
				{
					int index = CheckingForDigit("Enter index which you want to remove: ");;
					bool flag;
					flag = RemoveElement(array, index);
					if (flag == false)	
					{
						cout << "Enter incorrect index!" << endl;
					}
					break;
				}
				default:
				{
					cout << "Incorrect task, try enter number of task again !" << endl;
					break;
				}
			}
		}
		else
		{
		cout << "Enter correct number!" << endl;
		break;
		}
	}
}