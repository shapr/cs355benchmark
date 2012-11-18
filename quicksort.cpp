#include <iostream>
using namespace std;

void quicksort(int *& a, int left, int right);
int main(){
    int n;
    cout << "How many values there would be in the list?" << endl;
    cin >> n;
    int * array;
    array = new int[n];
    cout << "Please input the values." << endl;
    for(int i = 0; i < n; i++){
            cin >> array[i];
    }
    quicksort(array, 0, n - 1);
    cout << "list after sort" << endl;
    for(int i = 0; i < n; i++){
            cout<< array[i] << endl;
    }
    delete [] array;
    system("pause");
    return 0;
}

void quicksort(int *& a, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = a[(left + right) / 2];
      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quicksort(a, left, j);
      if (i < right)
            quicksort(a, i, right);
}
