#include <iostream>
using namespace std;

void bubblesort(int *& a, int n);
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
    bubblesort(array, n);
    cout << "list after sort" << endl;
    for(int i = 0; i < n; i++){
            cout<< array[i] << endl;
    }
    delete [] array;
    system("pause");
    return 0;
}
void bubblesort(int *& a, int n){
    int i,j,temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

        }

    }

}
