#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <cstdlib>
#include <cmath>

int up (int a, int b);
int down(int a, int b);

void quickSort(int list[], int n, int (*comp)(int a, int b) = up );

void  selectionSort(int list[], int n, int (*comp)(int a, int b) = up );

void insertionSort(int *list, int n, int (*comp)(int a, int b) = up );

void bubbleSort(int *list, int n, int (*comp)(int a, int b) = up );

#endif
