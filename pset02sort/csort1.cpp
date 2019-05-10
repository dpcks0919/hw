
/*
On my honor, I pledge that I have neither received nor provided improper assistance in
the completion of this assignment.
Signed: 김예찬 Section: 2 Studentn Number: 21600120
* This brute force version of Selection Sort that takes O(n^2).
*
*  Lab - Using C++, rewrite lab02a.cpp and name the file as lab03.cpp.
*		- <iostream>, <cstdlib>, <cmath>, <cassert>
*		- using namespace std
*		- cin, cout, endl
*		- use new and delete operators instead of malloc() and free()
*/
#include <ctime>
#include <iostream>
#include <cmath>
#include <cassert>
#include "nowic.h"
#include "sort.h"
using namespace std;

void print_list(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

void (*fn[])(int*, int, int (*comp)(int a, int b) ) = {bubbleSort, insertionSort, quickSort, selectionSort };


#if 1
int main() {


	int*	list = NULL;
	int N;
	N = GetInt("\t Enter input sample size : ");
	if (N < 1) {
		cout << "\tExpecting a number larger than 0";
	}

 else  if (N > 0) {

		list = new (nothrow) int [N];
  	assert(list != NULL);
		for (int i = 0; i < N; i++)
				list[i] = rand() % N;


		cout << "Test Case: NOT passing a defalt argument : quickSort(list, N)"<< endl;
		cout << "-------------------------------------------------------------"<< endl;
		cout << "NOTSORTED: " << endl;
		print_list(list, N);
		quickSort(list, N, up);
		cout << "\tSORTED: " << endl;
		print_list(list, N);


		cout << "Test Case: NOT passing a defalt argument : quickSort(list, N, up)"<< endl;
		cout << "-----------------------------------------------------------------"<< endl;
		cout << "NOTSORTED: " << endl;
		print_list(list, N);
		quickSort(list, N, up);
		cout << "UP SORTED: " << endl;
		print_list(list, N);

		cout << "Test Case: NOT passing a defalt argument : quickSort(list, N, down)"<< endl;
		cout << "-----------------------------------------------------------------"<< endl;
		cout << "NOTSORTED: " << endl;
		print_list(list, N);
		quickSort(list, N);
		cout << "DOWN SORTED: " << endl;
		print_list(list, N);

		cout << "Test Case: Using an array of function pointers"<< endl;
		cout << "----------------------------------------------"<< endl;


		char str[4][20] = {"Bubble", "Insert", "Quick","Select"};
	 	srand((unsigned)time(NULL));

for(int k=0;k <4; k++){


			for(int i = 0; i < N ; i++ ){
			list[i] = rand() % N;
		}
		cout << "NOTsorted["<< str[k] <<"]:";
		print_list(list, N);
		cout << "UPsorted["<< str[k] <<"]:";
		fn[k](list, N, up);
		print_list(list, N);
		cout << "DOWNsorted["<< str[k] <<"]:";
		fn[k](list, N, down);
		print_list(list, N);
		cout << endl;

}



	}




	else {
		 cout << "Your input(0) cannot be processed " << endl;
		 cout << "Usage : sort [N]" << endl;
	}

delete[] list;



}
#endif
