#include <iostream>
using namespace std;

int bianrySearch(int* arr, int st, int en, int k) {
  if (st > en) {
    return -1;
  }
  int mid = (st + en) / 2;
  if (arr[mid] == k) {
    return mid;
  }
  if (arr[mid] < k) {
    return bianrySearch(arr, mid + 1, en, k);
  } else
    return bianrySearch(arr, st, mid - 1, k);
}

int repeatingElementCount(int* arr, int n, int k) {
  int i, c = 1;
  int pos = bianrySearch(arr, 0, n - 1, k);
  if (pos == -1) return -1;
  for (i = pos - 1; i >= 0; --i) {
    if (arr[i] == k)
      ++c;
    else
      break;
  }
  for (i = pos + 1; i < n; ++i) {
    if (arr[i] == k)
      ++c;
    else
      break;
  }
  return c;
}

int main() {
  int t, n, i, k;
  cin >> t;
  while (t > 0) {
    cin >> n;
    int* arr = new int[n];
    for (i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    cin >> k;
    int res = repeatingElementCount(arr, n, k);
    if (res != -1) {
      cout << k << " - " << res << '\n';
    } else {
      cout << "Not Present" << '\n';
    }
    --t;
  }
  return 0;
}