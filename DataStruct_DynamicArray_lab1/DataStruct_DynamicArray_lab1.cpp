#include <iostream>
using namespace std;

struct DynamicArray
{
	int* Array;
	int Capacity;
	int Length;
};

void CreateDynamicArray(DynamicArray* dynamicArray)
{
	int capacity = 8;
	dynamicArray->Capacity = capacity;
	dynamicArray->Length = 0;
	dynamicArray->Array = new int[dynamicArray->Capacity];
}

void ResizeArray(DynamicArray* dynamicArray)
{
	dynamicArray->Capacity += dynamicArray->Capacity;
	int* tempArray = new int[dynamicArray->Capacity];
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		tempArray[i] = dynamicArray->Array[i];
	}
	delete[] dynamicArray->Array;
	dynamicArray->Array = tempArray;
	delete[] tempArray;
}

void AddNewElement(DynamicArray* dynamicArray, int element)
{
	dynamicArray->Length++;
	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		ResizeArray(dynamicArray);
	}
	dynamicArray->Array[dynamicArray->Length - 1] = element;
}

void BubbleSort(DynamicArray* dynamicArray)
{
	int length = dynamicArray->Length;
	while (length--)
	{
		bool swapped = false;
		for (int i = 0; i < length; i++)
		{
			if (dynamicArray->Array[i] > dynamicArray->Array[i + 1])
			{
				swap(dynamicArray->Array[i], dynamicArray->Array[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
}

void BinarySearch(DynamicArray* dynamicArray, int element)
{
	int left = 0;
	int right = dynamicArray->Length - 1;
	int middle;
	bool flag = false;
	while ((left <= right) && (flag != true))
	{
		middle = (left + right) / 2;

		if (dynamicArray->Array[middle] == element)
		{
			flag = true;
			cout << "Element which you search  " << element << " in index: " << middle << endl;
		}
		else if (dynamicArray->Array[middle] < element)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	if (flag == false)
	{
		cout << "There is no such value in the array." << endl;
	}
}

void Push_back(DynamicArray* dynamicArray, int value)
{
	int* newArray = new int[dynamicArray->Length + 1];
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		newArray[i] = dynamicArray->Array[i];
	}
	newArray[dynamicArray->Length] = value;
	dynamicArray->Length++;
	delete[] dynamicArray->Array;

	dynamicArray->Array = newArray;
}

void Push_forward(DynamicArray* dynamicArray, int value)
{
	int* newArray = new int[dynamicArray->Length + 1];
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		newArray[i + 1] = dynamicArray->Array[i];
	}
	newArray[dynamicArray->Length - dynamicArray->Length] = value;
	dynamicArray->Length++;
	delete[] dynamicArray->Array;

	dynamicArray->Array = newArray;
}

void InsertElement(DynamicArray* dynamicArray, int element, int index)
{
	dynamicArray->Length++;

	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		ResizeArray(dynamicArray);
	}

	for (int i = dynamicArray->Length - 1; i > index; i--)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i - 1];
	}

	dynamicArray->Array[index] = element;
}

int* LinearSearch(DynamicArray* dynamicArray, int value)
{
	bool flag = false;
	int length = dynamicArray->Length;
	for (int i = 0; i < length; i++)
	{
		if (dynamicArray->Array[i] == value)
		{
			cout << "Index of " << value << ":\t" << i << endl;
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "There is no such value in the array." << endl;
	}
	return dynamicArray->Array;
}

void FillArray(DynamicArray* dynamicArray, int length)
{
	srand(time(0));
	for (int i = 0; i < length; i++)
	{
		Push_back(dynamicArray, rand());
	}
}

void ShowArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		cout << dynamicArray->Array[i] << "\t";
	}
	cout << endl;
}

//void Pop_back(int*& arr, int& size)
//{	
//	size--;
//	int* newArray = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		newArray[i] = arr[i];
//	}
//	delete[] arr;
//	 
//	arr = newArray;
//}

////void pop_forward(int*& arr, int& size) // переписать 
////{
////	size--;
////	int* newArray = new int[size];
////	for (int i = 0; i < size; i++)
////	{
////		newArray[i+1] = arr[i];
////	}
////	delete[] arr;
////
////	arr = newArray;
////}

int main()
{
	DynamicArray* array = new DynamicArray;
	while (true)
	{
		cout << "1. Create Dynamic Array\n"
			"2. Initializing an array with random numbers\n"
			"3. Show array\n4. Bubble sort\n"
			"5. Push back\n"
			"6. Push forward\n"
			"7. Insert element in some index\n"
			"8. Linear Search\n"
			"9. Binary Search\n";
			
		int taskNumber;
		cout << "Enter task number: ";
		cin >> taskNumber;
		cout << endl;

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
			ShowArray(array);
			cout << "\n";
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
			Push_back(array, element);
			cout << "\n";
			break;
		}
		case 6:
		{
			int element;
			cout << "Enter element which u want push forward: ";
			cin >> element;
			Push_forward(array, element);
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

		}
		case 8:
		{
			int element;
			cout << "Enter element which u want find with Linear Search: ";
			cin >> element;
			LinearSearch(array, element);
			cout << "\n";
			break;
		}
		case 9:
		{
			int element;
			cout << "Enter element which u want find with Binary Search: ";
			cin >> element;
			BinarySearch(array, element);
			cout << "\n";
			break;
		}

		default:
		{
			cout << "Incorrect task, try enter number of task again !" << endl;
			break;
		}
		}
	}
	/*FillArray(array);
	ShowArray(array);
	Push_forward(arr, size, value);
	ShowArray(array);

	Pop_back(arr, size);
	ShowArray(array);*/
	/*BubbleSort(array);*/
	/*cout << "Sorted array:" << endl;
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << "Enter value of number which you want find:\t";
	cin >> value;
	LinearSearch(arr, size, value);*/
	/*delete[] arr;	*/

}