#include <fstream>
#include <iostream>
using namespace std;

int c = 0;

bool jumpSearch(int* arr, int n, int k) {
  for (int i = 0; i < n; i += 2) {
    ++c;
    if (arr[i] == k) return true;
    if (arr[i] > k) {
      ++c;
      if (arr[i - 1] == k)
        return true;
      else
        return false;
    }
  }
  return false;
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
    bool res = jumpSearch(arr, n, k);
    if (res) {
      output << "Present " << c << '\n';
    } else {
      output << "Not Present " << c << '\n';
    }
    --t;
  }
  
  input.close();
  output.close();
  return 0;
}