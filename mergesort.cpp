#include <iostream>
using namespace std;

void mergesort(int *& a, int *& temp, int left, int right);
void merge(int *& a, int *& temp, int left, int mid, int right);
int main(){
    int n;
    cout << "How many values there would be in the list?" << endl;
    cin >> n;
    int * array;
    array = new int[n];
    int * temp;
    temp = new int[n];
    cout << "Please input the values." << endl;
    for(int i = 0; i < n; i++){
            cin >> array[i];
    }
    mergesort(array, temp, 0, n - 1);
    delete [] temp;
    cout << "list after sort" << endl;
    for(int i = 0; i < n; i++){
            cout<< array[i] << endl;
    }
    delete [] array;
    system("pause");
    return 0;
}
void mergesort(int *& a, int *& temp, int left, int right)
{
  int mid;
 
  if (right > left)
  {
    mid = (right + left) / 2;
    mergesort(a, temp, left, mid);
    mergesort(a, temp, (mid+1), right);
    merge(a, temp, left, (mid+1), right);
  }
}
 
void merge(int *& a, int *& temp, int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;
 
  left_end = (mid - 1);
  tmp_pos = left;
  num_elements = (right - left + 1);
 
  while ((left <= left_end) && (mid <= right))
  {
    if (a[left] <= a[mid])
    {
      temp[tmp_pos] = a[left];
      tmp_pos++;
      left++;
    }
    else
    {
      temp[tmp_pos] = a[mid];
      tmp_pos++;
      mid++;
    }
  } 
  while (left <= left_end)
  {
    temp[tmp_pos] = a[left];
    left++;
    tmp_pos++;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = a[mid];
    mid++;
    tmp_pos++;
  }
  for (i=0; i < num_elements; i++)
  {
    a[right] = temp[right];
    right--;
  }
}
