void swap(int arr[], int l, int r) {
  int tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}

void quick_sort(int arr[], int l, int r) {

}

int main(int argc, char const *argv[]) {
  int arr[] = {
    55.,  2., 71., 49., 22., 31., 26., 55., 78., 48., 54., 63., 58.,
    95.,  2., 67., 93., 53., 72., 72., 31., 63., 91., 27., 69., 21.,
    2., 51., 14., 49., 11., 33., 13.,  5., 10., 82., 38., 89., 81.,
    64., 37., 76., 39., 81.,  4., 23., 69., 48., 26., 22.
  };

  quick_sort(arr, 0, 49);

  return 0;
}

