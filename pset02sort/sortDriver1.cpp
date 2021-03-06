/*

On my honor, I pledge that I have neither received nor provided improper assistance in
the completion of this assignment.
Signed: 김예찬 Section: 2 Studentn Number: 21600120



* Lecture Note by idebtor@gmail.com
*
* This program is written to run the sort algorithms.
* It takes the number of data samples to sort from the user.
* Then, the int array is created and filled with random numbers.
* User may selection one of sort functions to be used. Then
* execution time and its output is displayed.
*
* History:
* 02/10/19:		Created in C++
*
* Before Compilation, you must have some files (static library and
* include file) ready as shown below:
*   src/selection.cpp, bubble.cpp ...
*   include/nowic.h
*	lib/libnowic.a        (nowic.lib for Visual Studio)
* Compilation:
*	g++ selection.cpp insertion.cpp quicksort.cpp bubble.cpp
*       sortDriver.cpp -I../include -L../lib -lnowic -o sort
*/

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

void bubbleSort(int *list, int n);
void insertionSort(int *list, int n);
void quickSort(int *list, int n);
void selectionSort(int *list, int n);

void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);


void swap(int &a, int &b){
	int temp;
	temp = a;
	a =b;
	b = temp;
}
// Randomize: shuffle the sequence
// For every sample, starting from the first element in the list,
// it is swapped with the element randomly selected by the index
// generated by a 'real' (not pseudo) random number out of from
// 0 to N - 1.
// Hint: Refer to rand() and srand() function document.
void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	srand((unsigned)time(NULL));

	for(int i = 0; i < n ; i++ ){
		swap(list[rand()%n], list[rand()%(n-1)]);
	}

	DPRINT(cout << "<randomize" << endl;)
}

// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max+print specifies the number of samples in either front
// or rear part of the list.  The per_line determines how many
// samples prints per line.
//
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only.
// For example:
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and
// the rear part.
// Observe the sample runs using sortx.exe provided with you.

// Optionally, you may have this kind of a help function.
// void _printList(int *list, int start, int end, int per_line)


   void printList(int *list, int N, int max_print, int per_line) {
      DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)


			if( max_print >= N && per_line >= N/2 ){
				int i=0;
				for( i; i < N/2; i ++){
				cout<< "\t" << list[i];
				}
			  cout << endl;
				for(i ; i < N ; i++  ){
				cout<< "\t" << list[i];
				}

			}

			else if( max_print >= N && per_line < N/2 ){
			// 한 줄당 per_ine 만큼 출력하고 endl까지  마지막(N/2) 은 딱 맞게
				int i=0;
			while(i < N/2 ){
				for(int j=0 ; j < per_line ; j++){
					if (i < N/2  ) {
				cout<< "\t" << list[i];
					i++;
					}
				}
			cout << endl;
			}

			while(i < N ) {
				for(int j=0 ; j < per_line ; j++){
					if (i < N  ){
				cout<< "\t" << list[i];
					i++;
							}
						}
				cout << endl;
				}
			}


			else if(max_print < N && max_print  < per_line ){

			 for(int i =0; i < max_print ; i++){
				cout<< "\t" << list[i];
			 }
				cout << endl;
			 for(int i =0; i< max_print ; i++){
				cout<< "\t" << list[N-max_print+i];
			 }
				cout << endl;
			}

			else {
				int i=0;
			while(i < max_print ){
				for(int j=0 ; j < per_line ; j++){
					if (i < max_print ) {
				cout<< "\t" << list[i];
					i++;
					}
				}
			cout << endl;
			}

			i=0;
			while(i < max_print ) {
				for(int j=0 ; j < per_line ; j++){
					if (i < max_print  ){
				cout<< "\t" << list[N-max_print+i];
					i++;
						}
					}
				cout << endl;
				}
			}
			DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosen
	DPRINT(cout << ">main...N=" << N << endl;)

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) samples\n"
			"\ta - algorithm to run\n"
			"\ts - sort()\n"
			"\tm - max samples to display at front or rear\n"
			"\td - max samples to display per line\n";


		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)

		enum algorithm_enum b, i, s, q;

			b = BUBBLE;
			i = INSERTION;
			s = SELECTION;
			q = QUICKSORT;


			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {

				 case 'b' : DPRINT(cout << "case = " << option_char << endl;)
						algorithm_chosen = BUBBLE;
						break;
				 case 'i' : DPRINT(cout << "case = " << option_char << endl;)
						algorithm_chosen = INSERTION;
						break;
				 case 's' : DPRINT(cout << "case = " << option_char << endl;)
						algorithm_chosen = SELECTION;
						break;
				 case 'q' : DPRINT(cout << "case = " << option_char << endl;)
						algorithm_chosen = QUICKSORT;
						break;


			default: { cout << "\tNo such an algorithm available. Try it again.\n"; break; }
			}

			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

		 keyin = GetInt("\tEnter input sample size: ");
	  if (keyin < 1) {
	    cout << "\tExpecting a number larger than 0";
	  }

	  // set N with the new keyin value
	  // before allocating the new list, free the old list if not NULL
	  // allocate memory for new data samples
	  // Fill the list with numbers from 0 to n - 1.

	 else  if (keyin > 0) {
	    delete[] list;
	    list = new int[keyin];
	    for(int i= 0; i < keyin ; i ++){
				list[i] = i;
				}
				N = keyin;
				printList(list, N, max_print, per_line);
  	}

		else {
			 keyin = GetInt("Retry ");
		}
			break;


		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}

		if (N > 1 ) {
				randomize(list, N);
				printList(list, N, max_print, per_line);
		}

			break;


		case 's': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}
			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";
			start = clock();

			switch(algorithm_chosen)
			{
				case BUBBLE:
				bubbleSort(list, N);
				printList(list, N, max_print, per_line);
				break;
				case INSERTION:
				insertionSort(list, N);
				printList(list, N, max_print, per_line);
					break;
				case QUICKSORT:
				quickSort(list, N);
				printList(list, N, max_print, per_line);
					break;
				case SELECTION:
				selectionSort(list, N);
				printList(list, N, max_print, per_line);
					break;
			}

			end = clock();
			cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			break;



			case 'm': { DPRINT(cout << "case = " << option_char << endl;)
			 string m1;
			 int m2;
			 cout << "Enter max sample size to display: ";
			 getline(cin, m1);
			 m2 = stoi(m1);
			 max_print = m2;
			 printList(list, N, max_print, per_line);

			 break;
}
		case 'd': DPRINT(cout << "case = " << option_char << endl;)
			 string d1;
			 int d2;
			 cout << "Enter max sample per line to display: ";
			 getline(cin, d1);
			 d2 = stoi(d1);
			 per_line = d2;
			 printList(list, N, max_print, per_line);
			 break;


		}
	} while (option_char != 'q');

	if (list != NULL) free(list);
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}
