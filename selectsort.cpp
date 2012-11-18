#include <iostream>
using namespace std;

void selectsort(int *& a, int n);
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
    selectsort(array, n);
    cout << "list after sort" << endl;
    for(int i = 0; i < n; i++){
            cout<< array[i] << endl;
    }
    delete [] array;
    system("pause");
    return 0;
}
void selectsort(int *& a,int n){
     int minindex;
     int min;
     for(int i = 0; i < n; i++){
             min = a[i];
             for(int j = i + 1; j < n; j++){
                     if(a[j] < min){
                             min = a[j];
                             minindex = j;
                     }
             }
             if(a[i] != min){
                     a[minindex] = a[i];
                     a[i] = min;
             }
     }
} 
