#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int up (int a, int b);
int down (int a, int b);


void  selectionSort(int list[], int n, int (*comp)(int a, int b)) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (comp(list[min], list[j] ) > 0)
				min = j;
			}
		swap(list[i], list[min]);
	}
}


#if 0
int main() {
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	int N = sizeof(list) / sizeof(list[0]);

	cout << "UNSORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	selectionSort(list, N, down);

	cout << "SORTED: " << endl;
	for (int i = 0; i < N; i++) cout << list[i] << " "; cout << endl;

	system("pause");
}
#endif
