
// This is a sample code that runs okay, has a bad coding style.
// Reference: Fundamentals of Data Structures by Horowitz, Sahni
//
// When you compile the following code in Visual Studio, you may
// get the warning about scanf() or others. Then enter an addtional
// compiler option /wd4996 in the following:
// Project Properties -> C/C++ -> Command Line -> Additonal Options

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
void swap(int &a, int &b);
void selectionSort(int[], int);

int main(void) {
	int i, n, m;
	string str, str1;
	string::size_type sz, sz1;
	cout << "Enter the size of array: "  ;
	getline(cin, str);
	m = stoi(str, &sz);
	int* list = new int[m];
	cout <<"Enter the number of samples: ";
	getline(cin, str1);
	n = stoi(str1, &sz1);

while( n < 0 || n >= m ){
	cout <<"The num should be smaller than the size of array " << endl;
	cout <<"Enter the number of samples: ";
	getline(cin, str1);
	n = stoi(str1, &sz1);
	}

if (n == 0) {
		cout << "Improper value of n" ;
		exit(1);
	}

	cout <<"\nUnSorted array:\n" ;
	for (i = 0; i < n; i++) {       // randomly generate numbers
		list[i] = rand() % 1000;
		cout << list[i] <<" " ;
	}

	 selectionSort(list, n);

	cout <<"\nSorted array:\n";
	for (i = 0; i < n; i++) {
		cout << list[i] <<" " ;
	}
	cout << "\n";
	delete[] list;
	return EXIT_SUCCESS;
}

void  selectionSort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min])
				min = j;
			}
		swap(list[i], list[min]);
	}
}

void swap(int &a, int &b){
	int temp;
	temp = a;
	a =b;
	b = temp;
}
