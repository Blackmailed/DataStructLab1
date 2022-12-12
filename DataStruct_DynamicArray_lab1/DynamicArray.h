#pragma once
/// @brief Представляет реализацию по динамическому массиву
struct DynamicArray
{
	/// @brief Массив
	int* Array;

	/// @brief Длина массива
	int Length;

	/// @brief Вместимость массива
	int Capacity;
	
	/// @brief Фактор роста вместимости массива
	const int GrowthFactor = 2;

	/// @brief Конструктор динамического массива
	DynamicArray()
	{
		int capacity = 8;
		Capacity = capacity;
		Length = 0;
		Array = new int[Capacity];
	}
};
///// @brief Создание динамического массива
///// @param Динамический массив 
//void CreateDynamicArray(DynamicArray* dynamicArray);

/// @brief Изменение вместимости массива
/// @param Динамический массив 
void ResizeArray(DynamicArray* dynamicArray);

/// @brief Соритровка пузырьком
/// @param Динамический массив 
void BubbleSort(DynamicArray* dynamicArray);

/// @brief Линейный поиск
/// @param Динамический массив 
/// @param Значение 
/// @return Возвращает индекс
int LinearSearch(DynamicArray* dynamicArray, int value);

/// @brief Бинарный поиск числа
/// @param Динамический массив 
/// @param Элемент 
/// @return Возвращает индекс
int BinarySearch(DynamicArray* dynamicArray, int element);

/// @brief Добавление элемента в конец массива
/// @param Динамический массив  
/// @param Значение
void PushBack(DynamicArray* dynamicArray, int value);

/// @brief Добавление элемента в начало массива
/// @param Динамический массив 
/// @param Значение 
void PushForward(DynamicArray* dynamicArray, int value);

/// @brief Вставка элемента в любую позицию
/// @param Динамический массив 
/// @param Элемент 
/// @param Индекс
void InsertElement(DynamicArray* dynamicArray, int element, int index);

/// @brief Удаление какого-либо элемента из массива
/// @param Динамический массив 
/// @param Индекс 
/// @return Возвращает значение флага
bool RemoveElement(DynamicArray* dynamicArray, int index);

/// @brief Заполение массива рандомными числами
/// @param Динамический массив
/// @param Длина
void FillArray(DynamicArray* dynamicArray, int length);
