#include <iostream>
using namespace std;

void triSome(int* arr, int n) {
  int i, j, k;
  bool flag = false;
  for (i = 0; i < n - 2; ++i) {
    if (flag) break;
    for (j = i + 1; j < n - 1; ++j) {
      if (flag) break;
      for (k = j + 1; k < n; ++k) {
        if (arr[i] + arr[j] == arr[k]) {
          cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
          flag = true;
          break;
        }
        if (arr[k] > (arr[i] + arr[j])) break;
      }
    }
  }
  if (!flag) cout << "No sequence found\n";
}

int main() {
  int t, n, i;
  cin >> t;
  while (t > 0) {
    cin >> n;
    int* arr = new int[n];
    for (i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    triSome(arr, n);
    --t;
  }
  return 0;
}