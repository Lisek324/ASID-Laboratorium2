/*
* Autor: Jakub Brzozowski 235_IC A1
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
int* array_pop(int* arr,int &size)
{
	int* newArr;
	for (int i = 0; i < size-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	newArr = (int*)realloc(arr, (size-1) * sizeof(int));
	size--;
	return newArr;
}
void print_arr(int* arr, int &size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void swapDown(int* &heap, int i, int &size)
{
	std::cout << "Kopiec:";
	print_arr(heap, size);
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int max = i;
	int temp;
	std::cout << "lewy: "<<left<<"\nprawy: "<<right<<"\n"<<"max: "<<max << "\n";
	std::cout << "Czy heap[left]: "<<heap[left]<<" >heap[max]: "<< heap[max] << "";
	if (left < size && heap[left]>heap[max]) 
	{
		
		max = left;
		std::cout << " TAK \nmax = left -> " << max << "\n";
	}else std::cout << " NIE\n";
	std::cout << "Czy heap[right]: " << heap[right] << " >heap[max]: " << heap[max] << "";
	if (right < size && heap[right]> heap[max])
	{

		max = right;
		std::cout << " TAK \nmax = right-> " << right;
	}else std::cout << " \nNIE\n";
	std::cout << "Czy max-> " << max << " != i->" << i;
	if (max != i) {
		std::cout << "\nTAK ";
		std::cout << "zamien " << heap[i] << " z " << heap[max] << "\n";
		temp = heap[i];
		heap[i] = heap[max];
		heap[max] = temp;
		swapDown(heap, max, size);
	}
	else {
		std::cout << "\nNIE ";
	}
	std::cout << "\n";
}
void heapify(int* &heap, int& size)
{
	for (int i = size / 2 - 1; i >= 0; i--) {
		swapDown(heap, i, size);
	}
}
void heap_insert(int* &heap, int& size, int element) {
	int temp;
	size++; 
	std::cout << "Kopiec ";
	print_arr(heap, size);
	int* newHeap = new int[size]; 
	for (int i = 0; i < size - 1; i++) {
		newHeap[i] = heap[i];
	}
	
	
	std::cout << "Dodaj do kopca: " << element<<"\n";
	newHeap[size - 1] = element;
	delete[] heap; 
	heap = newHeap; 

	int i = size - 1;
	heap[i] = element;

	while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
		std::cout << "zamien " << heap[i] << " z " << heap[(i - 1) / 2] << "\n";
		temp = heap[i];
		heap[i] = heap[(i - 1) / 2];
		heap[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
		std::cout << "\nKopiec po zamianie:";
		print_arr(heap, size);
	}
	
}
void heap_pop(int* &heap, int& size) 
{
	//std::cout << "Usuwanie elementu z ";
	heapify(heap, size);
	heap[0] = heap[size-1];
	size--;
	int* newHeap = (int*)realloc(heap, (size) * sizeof(int));
	heap = newHeap;
}
void heap_sort(int* &heap, int& size)
{
	int temp;
	for (int i = size / 2 - 1; i >= 0; i--) {
		swapDown(heap, i, size);
	}

	for (int i = size - 1; i >= 0; i--) {
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;

		swapDown(heap,0 , i);
	}
}
int main()
{
	srand(time(NULL));
	int size = 6;
	int elem = 15;
    int* arr = new int[size];
	int r;
	for (int i = 0; i < size; i++)
	{
		r = rand() % 11;
		arr[i] = r;
	}
	std::cout << "Tablica: ";
	print_arr(arr, size);
	array_pop(arr, size);
	std::cout << "Tablica po array_pop: ";
	print_arr(arr, size);
	std::cout << "Tablica przed kopcowaniem: ";
	print_arr(arr, size);

	heapify(arr, size);
	std::cout << "Tablica po kopcowaniu: ";
	print_arr(arr, size);
	std::cout << "------------------------------------\n";
	
	heap_insert(arr,size,elem);
	std::cout << "Tablica po dodaniu elementu '" << elem << "':";
	print_arr(arr, size);
	std::cout << "------------------------------------\n";
	
	heap_pop(arr, size);
	std::cout << "Tablica po skasowaniu: ";
	print_arr(arr, size);
	std::cout << "------------------------------------\n";
	
	heap_sort(arr, size);
	std::cout << "Tablica po posortowaniu: ";
	print_arr(arr, size);
	std::cout << "------------------------------------\n";
}

