#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main() {
  int x = 31232;
  double pw;
  double result = log10(x);
  result = floor(result);
  pw = pow(10,result);
  cout <<result <<endl;
  cout << pw;
}
