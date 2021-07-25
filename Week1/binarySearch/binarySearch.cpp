#include <fstream>
#include <iostream>
using namespace std;

int c = 0;

bool binarySearch(int* arr, int st, int en, int k) {
  if (st > en) return false;
  ++c;
  int mid = (st + en) / 2;
  if (arr[mid] == k) return true;

  if (arr[mid] < k)
    return binarySearch(arr, mid + 1, en, k);
  else
    return binarySearch(arr, st, mid - 1, k);
}

int main() {
  fstream input;
  input.open("input.txt", ios::in);
  if (!input) {
    cout << "Unable to open file";
    exit(1);
  }

  int t, n, i, k;
  input >> t;
  fstream output;
  output.open("output.txt", ios::out);

  while (t > 0) {
    input >> n;
    int* arr = new int[n];
    for (i = 0; i < n; ++i) {
      input >> arr[i];
    }
    input >> k;
    c = 0;
    bool res = binarySearch(arr, 0, n - 1, k);
    if (res) {
      output << "Present " << c << '\n';
    } else {
      output << "Not Present " << c << '\n';
    }
    --t;
  }

  input.close();
  output.close();
}