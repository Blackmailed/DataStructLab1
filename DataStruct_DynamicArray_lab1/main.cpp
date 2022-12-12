#include <iostream>
#include "DynamicArray.h"
using namespace std;

void TaskNumber(int&  taskNumber)
{
	cout << "Enter task number: ";
	cin >> taskNumber;
	cout << endl;
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
			"9. Binary Search\n";
			"10. Remove Element\n";
	while (true)
	{	
		//TODO: input sanitizing                        ,          duplication is fixed
		int taskNumber;
		TaskNumber(taskNumber);
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
					int length;
					cout << "Enter length of your dynamic array: ";
					cin >> length;
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
					int element;
					cout << "Enter element which u want push back: ";
					cin >> element;
					PushBack(array, element);
					cout << "\n";
					break;
				}
				case 6:
				{
					int element;
					cout << "Enter element which u want push forward: ";
					cin >> element;
					PushForward(array, element);
					cout << "\n";
					break;
				}
				case 7:
				{
					int element;
					int index;
					cout << "Enter element which u want add: ";
					cin >> element;
					cout << "Enter index of element which u want add: ";
					cin >> index;
					InsertElement(array, element, index);
					break;
				}
				case 8:
				{
					int element;
					int index;
					cout << "Enter element which u want find with Linear Search: ";
					cin >> element;
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
					int element;
					int index;
					cout << "Enter element which u want find with Binary Search: ";
					cin >> element;
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
					int index;
					bool flag;
					cout << "Enter index which you want to remove: ";
					cin >> index;
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