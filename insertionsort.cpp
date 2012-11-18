#include <iostream>
using namespace std;

void insertionsort(int *& a, int n);
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
    insertionsort(array, n);
    cout << "list after sort" << endl;
    for(int i = 0; i < n; i++){
            cout<< array[i] << endl;
    }
    delete [] array;
    system("pause");
    return 0;
}
void insertionsort(int *& a, int length)
{
  int key,i;
  for(int j = 1; j < length; j++)
  {
     key = a[j];
     i = j - 1;
     while(a[i] > key && i >= 0)
     {
               a[i+1] = a[i];
         i--;
     }
     a[i+1] = key;
  }
}
