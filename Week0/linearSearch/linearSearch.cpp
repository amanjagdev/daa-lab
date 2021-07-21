#include <fstream>
#include <iostream>
using namespace std;

int linear_search(int* arr, int n, int k) {
  for (int i = 0; i < n; i++)
    if (arr[i] == k) return i;
  return -1;
}

int main() {
  fstream input;
  input.open("input.txt", ios::in);
  if (!input) exit(1);

  int testCases, n, i, k;

  input >> testCases;
  fstream output;
  output.open("output.txt", ios::out);

  for (; testCases > 0; testCases--) {
    input >> n;
    int* arr = new int[n];
    for (i = 0; i < n; i++) {
      input >> arr[i];
    }

    input >> k;
    int res = linear_search(arr, n, k);
    output << res << '\n';
  }

  input.close();
  output.close();
}