#include "DynamicArray.h"
#include <xmemory>
#include <time.h>

using namespace std;

void ResizeArray(DynamicArray* dynamicArray)
{
	if (dynamicArray->Length >= dynamicArray->Capacity) 
	{
		dynamicArray->Capacity = dynamicArray->Capacity * dynamicArray->GrowthFactor;
	}
	else
	{
		dynamicArray->Capacity -= dynamicArray->Capacity / dynamicArray->GrowthFactor;
	}

	int* tempArray = new int[dynamicArray->Capacity];

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		tempArray[i] = dynamicArray->Array[i];
	}

	delete[] dynamicArray->Array;
	dynamicArray->Array = tempArray;
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

int BinarySearch(DynamicArray* dynamicArray, int element)
{
	int left = 0;
	int right = dynamicArray->Length;
	int middle;
	bool flag = false;
	int index = -1;

	while ((left <= right) && (flag != true))
	{
		middle = (left + right) / 2;

		if (dynamicArray->Array[middle] == element)
		{
			flag = true;
			index = middle;
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
	return index;
}

int LinearSearch(DynamicArray* dynamicArray, int value)
{
	int index = -1;
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == value)
		{
			index = i;
			break;
		}
	}
	return index;
}

void PushBack(DynamicArray* dynamicArray, int element)
{
	dynamicArray->Length++;
	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		ResizeArray(dynamicArray);
	}
	dynamicArray->Array[dynamicArray->Length - 1] = element;
}

void PushForward(DynamicArray* dynamicArray, int value)
{
	dynamicArray->Length++;
	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		ResizeArray(dynamicArray);
	}
	for (int i = dynamicArray->Length; i >= 1; i--)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i-1];
	}
	dynamicArray->Array[dynamicArray->Length - dynamicArray->Length] = value;
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

bool RemoveElement(DynamicArray* dynamicArray, int index)
{
	bool flag = true;

	if (index > dynamicArray->Length - 1 || index < 0)
	{
		flag = false;
	}
	else
	{
		for (int i = index; i < dynamicArray->Length - 1; i++)
		{
			dynamicArray->Array[i] = dynamicArray->Array[i + 1];
		}

		dynamicArray->Length--;

		if (dynamicArray->Length < dynamicArray->Capacity)
		{
			ResizeArray(dynamicArray);
		}

		flag = true;
	}
	return flag;
}

void FillArray(DynamicArray* dynamicArray, int length)
{
	srand(time(nullptr));
	if (dynamicArray->Length == 0)
	{
		for (int i = 0; i < length; i++)
		{
			PushBack(dynamicArray, rand());
		}
		if (dynamicArray->Length >= dynamicArray->Capacity)
		{
			ResizeArray(dynamicArray);
		}
	}
}