#include <iostream>
#include <ctime>
using namespace std;

void randomArray(int size, int *array) {
	int varRand;

	for (int i = 0; i < size; i++) {
	A:
		varRand = rand();
		for (int j = 0; j < i; j++) {
			if (array[j] == varRand) {
				goto A;
			}
		}
		array[i] = varRand;
		cout << array[i] << " ";
	}
	cout << endl;
}

void searchForCommonItems(int *array1, int *array2, int size1, int size2) {
	int tempSize = size1;
	int *tempArray = array1;
	if (size2 > size1) {
		size1 = size2;
		array1 = array2;
		size2 = tempSize;
		array2 = tempArray;
	}
	int countCommonItems=0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (array1[i] == array2[j]) {
				countCommonItems++;
				break;
			}
		}
	}
	cout <<"Кол-во общих эл = "<<countCommonItems<<endl;
}

void main() {
	setlocale(0, "RUS");
	srand(time(NULL));
	int sizeA, sizeB;
	sizeA = rand() % 1000;
	sizeB = rand() % 1000;
	int *array1 = new int[sizeA];
	int *array2 = new int[sizeB];
	cout << "Массив 1: ";
	randomArray(sizeA, array1);
	cout << "Массив 2: ";
	randomArray(sizeB, array2);
	searchForCommonItems(array1, array2, sizeA, sizeB);
	system("pause");
}
