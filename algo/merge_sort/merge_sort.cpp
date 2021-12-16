#include <iostream>

using namespace std;

// 0   1   2   3  |   4   5   6   7
// 7  18  24  36  |  15  20  20  21
void merge(int arr[], int s[], int left, int middle, int right) {
  int i = left;
  int j = middle;

  while (i < middle || j < right) {
    if (arr[i] < arr[j]) {
      s[i] = arr[i];
      i++;
    } else {
      s[j] = arr[j];
      j++;
    }
  }
}

void merge_pass(int arr[], int s[], int nb, int length) {
}

int main(int argc, char const *argv[]) {
  int size = 8;
  int arr[] = {7, 18, 24, 36, 15, 20, 20, 21};
  int s[size];
  
  merge(arr, s, 0, 4, size);

  for (int i = 0; i < size; i++) {
    cout << s[i] << " ";
  }

  return 0;
}
