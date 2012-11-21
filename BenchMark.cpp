#include "BenchMark.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/*
  arrays to sort for testing:
  sorted
  reverse sorted
  random
  all same item
  zero size
 */

int BenchMark::loopcounter = 0;
int BenchMark::swapcounter = 0;

BenchMark::BenchMark(){ // set the array size

}

void BenchMark::generateArrays(int size){
  // create the arrays
  arraysize = size;
  revarray = new int [arraysize];
  sortarray = new int [arraysize];
  randarray = new int [arraysize];
  duparray = new int [arraysize];
  zeroarray = new int [0];
  onearray = new int [1]; // does this work?

  // generate the arrays
  for(int i = 0; i < arraysize; i++){
    sortarray[i] = i;
    duparray[i] = i; // will add duplicates later
    randarray[i] = i; // will randomize later
    revarray[arraysize - 1 - i] = i;
  }

  // duparray is half count up, half count down
  for (int i = 0; i < arraysize/2; i++){
    duparray[arraysize - 1 - i] = i;
  }

  // for our random array, copy the ascending array and then randomly swap items
  // for at least half the number of items, let's hope that works!
  for (int i = 0; i < arraysize/2; i++){
    int a = rand() % arraysize;
    int b = rand() % arraysize;
    if (a != b){
      int temp = randarray[a];
      randarray[a] = randarray[b];
      randarray[b] = temp;
    }
  }

  if(size < 101){
          cout<< "Random array before sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
}
void BenchMark::clearStats(){
  loopcounter = 0;
  swapcounter = 0;
}

// void BenchMark::printResults(){
//   // reportStats(); // is this right?
//   cout <<

// }

void BenchMark::reportStats(string arraytype, string sorttype){
  cout << "----------------------------------------------------------" << endl;
  cout << "for an array of type " << arraytype ;
  cout << " the sort of type" << sorttype ;
  cout << " had results:\n";
  cout << loopcounter << " times through the loop\n";
  cout << swapcounter << " swaps were required\n";
  cout << "This gives a loop ratio of " << arraysize << "/" << loopcounter << ".\n";
  cout << "and a swap ratio of " << arraysize << "/" << swapcounter << ".\n" << endl;
  cout << "----------------------------------------------------------" << endl;
}

void BenchMark::runSelectionSorts(int size){
  // generate arrays of the size we want
  generateArrays(size);


  // run it all!
  clearStats();
  SelectionSortHelper(randarray, size);
  if(size < 101){
          cout<< "Random array after sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
  reportStats("random","selection");

  clearStats();
  SelectionSortHelper(sortarray, size);
  reportStats("sorted","selection");

  clearStats();
  SelectionSortHelper(revarray, size);
  reportStats("reverse","selection");

  clearStats();
  SelectionSortHelper(duparray, size);
  reportStats("duplicates","selection");

/*  clearStats();
  SelectionSortHelper(zeroarray, 0);
  reportStats("zero size","selection");

  clearStats();
  SelectionSortHelper(onearray, 1);
  reportStats("one element","selection");*/

}


void BenchMark::SelectionSort(){
  // loop through the vector, pick up the next size, run the sort with that size
  //for(int i = 0;i < sortsizes.size();i++){
    // generate the arrays of that size
    // call SelectionSort on each of those arrays?
    // no, we should already have our arrays of certain sizes, and then we just pass them in here
    //  }
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runSelectionSorts(10);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runSelectionSorts(100);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runSelectionSorts(1000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runSelectionSorts(10000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
}

void BenchMark::SelectionSortHelper(int *& a, int size){
  // do we need to copy the array ourselves?

  // void selectsort(int *& a,int n){
  int minindex = 0;
  int min;
  for(int i = 0; i < size; i++){
    min = a[i];
    for(int j = i + 1; j < size; j++){
      loopcounter++;
      if(a[j] < min){
        min = a[j];
        minindex = j;
      }
    }
    if(a[i] != min){
      swapcounter++;
      a[minindex] = a[i];
      a[i] = min;
    }
  }
}
void BenchMark::InsertionSort(){
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runInsertionSorts(10);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runInsertionSorts(100);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runInsertionSorts(1000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runInsertionSorts(10000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
}
void BenchMark::runInsertionSorts(int size){
  generateArrays(size);
  clearStats();
  SelectionSortHelper(randarray, size);
  if(size < 101){
          cout<< "Random array after sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
  reportStats("random","Insertion");

  clearStats();
  InsertionSortHelper(sortarray, size);
  reportStats("sorted","Insertion");

  clearStats();
  InsertionSortHelper(revarray, size);
  reportStats("reverse","Insertion");

  clearStats();
  InsertionSortHelper(duparray, size);
  reportStats("duplicates","Insertion");

/*  clearStats();
  InsertionSortHelper(zeroarray, 0);
  reportStats("zero size","Insertion");

  clearStats();
  InsertionSortHelper(onearray, 1);
  reportStats("one element","Insertion");*/

}
void BenchMark::InsertionSortHelper(int *& a, int size){
  int key,i;
  for(int j = 1; j < size; j++)
  {
     key = a[j];
     i = j - 1;
     while(a[i] > key && i >= 0)
     {
               a[i+1] = a[i];
         i--;
         loopcounter++;
     }
     a[i+1] = key;
     swapcounter++;
  }
}
void BenchMark::BubbleSort(){
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runBubbleSorts(10);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runBubbleSorts(100);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runBubbleSorts(1000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runBubbleSorts(10000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
}
void BenchMark::runBubbleSorts(int size){
  generateArrays(size);
  clearStats();
  BubbleSortHelper(randarray, size);
  if(size < 101){
          cout<< "Random array after sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
  reportStats("random","Bubble");

  clearStats();
  BubbleSortHelper(sortarray, size);
  reportStats("sorted","Bubble");

  clearStats();
  BubbleSortHelper(revarray, size);
  reportStats("reverse","Bubble");

  clearStats();
  BubbleSortHelper(duparray, size);
  reportStats("duplicates","Bubble");

/*  clearStats();
  BubbleSortHelper(zeroarray, 0);
  reportStats("zero size","Bubble");

  clearStats();
  BubbleSortHelper(onearray, 1);
  reportStats("one element","Bubble");*/

}
void BenchMark::BubbleSortHelper(int *& a, int size){
    int i,j,temp;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < i; j++)
        {
              loopcounter++;
            if(a[i] < a[j])
            {
                    swapcounter++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void BenchMark::MergeSort(){
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runMergeSorts(10);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runMergeSorts(100);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runMergeSorts(1000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runMergeSorts(10000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
}
void BenchMark::runMergeSorts(int size){
  generateArrays(size);
  clearStats();
  MergeSortHelper(randarray, 0, size - 1);
  if(size < 101){
          cout<< "Random array after sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
  reportStats("random","Merge");

  clearStats();
  MergeSortHelper(sortarray, 0, size - 1);
  reportStats("sorted","Merge");

  clearStats();
  MergeSortHelper(revarray, 0, size - 1);
  reportStats("reverse","Merge");

  clearStats();
  MergeSortHelper(duparray, 0, size - 1);
  reportStats("duplicates","Merge");

/*  clearStats();
  MergeSortHelper(zeroarray,0 , 0);
  reportStats("zero size","Merge");

  clearStats();
  MergeSortHelper(onearray,0 , 0);
  reportStats("one element","Merge");*/

}
void BenchMark::MergeSortHelper(int *& a,int left, int right){
  int mid;
  if (right > left)
  {
    mid = (right + left) / 2;
    MergeSortHelper(a, left, mid);
    MergeSortHelper(a, (mid+1), right);
    merge(a, left, (mid+1), right);
  }
}
void BenchMark::merge(int *& a, int left, int mid, int right){
  int * temp;
  temp = new int[right + 1];
  int i, left_end, num_elements, tmp_pos;
  left_end = (mid - 1);
  tmp_pos = left;
  num_elements = (right - left + 1);
  while ((left <= left_end) && (mid <= right)){
    loopcounter++;
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
  while (left <= left_end){
    loopcounter++;
    temp[tmp_pos] = a[left];
    left++;
    tmp_pos++;
  }
  while (mid <= right){
    loopcounter++;
    temp[tmp_pos] = a[mid];
    mid++;
    tmp_pos++;
  }
  for (i=0; i < num_elements; i++){
    swapcounter++;
    a[right] = temp[right];
    right--;
  }
}
void BenchMark::QuickSort(){
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runQuickSorts(10);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runQuickSorts(100);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runQuickSorts(1000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
  runQuickSorts(10000);
  cout<<endl;
  cout<<"*************************************************************"<<endl;
  cout<<endl;
}
void BenchMark::runQuickSorts(int size){
  generateArrays(size);
  clearStats();
  QuickSortHelper(randarray,0, size - 1);
  if(size < 101){
          cout<< "Random array after sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
  reportStats("random","Quick");

  clearStats();
  QuickSortHelper(sortarray,0, size - 1);
  reportStats("sorted","Quick");

  clearStats();
  QuickSortHelper(revarray,0, size - 1);
  reportStats("reverse","Quick");

  clearStats();
  QuickSortHelper(duparray,0, size - 1);
  reportStats("duplicates","Quick");

/*  clearStats();
  QuickSortHelper(zeroarray,0, 0);
  reportStats("zero size","Quick");

  clearStats();
  QuickSortHelper(onearray, 0, 0);
  reportStats("one element","Quick");*/

}
void BenchMark::QuickSortHelper(int *& a,int left, int right){
      int i = left, j = right;
      int tmp;
      int pivot = a[(left + right) / 2];
      while (i <= j) {
            while (a[i] < pivot){
                  loopcounter++;
                  i++;
            }
            while (a[j] > pivot){
                  loopcounter++;
                  j--;
            }
            if (i <= j) {
                  swapcounter++;
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            QuickSortHelper(a, left, j);
      if (i < right)
            QuickSortHelper(a, i, right);
}

void BenchMark::generateRadixArrays(size){
  // create the arrays
  // for radix, all elements must have the same length
  // thus size 10 is 0-9 and size 100 is 00-99, etc

  arraysize = size;
  revarray = new string [arraysize];
  sortarray = new string [arraysize];
  randarray = new string [arraysize];
  duparray = new string [arraysize];
  // zeroarray = new int [0];
  // onearray = new int [1]; // does this work?

  // generate the numbers, then turn them into a string
  for(int i = 0; i < arraysize; i++){
    sortarray[i] = i;
    duparray[i] = i; // will add duplicates later
    randarray[i] = i; // will randomize later
    revarray[arraysize - 1 - i] = i;
  }

  // duparray is half count up, half count down
  for (int i = 0; i < arraysize/2; i++){
    duparray[arraysize - 1 - i] = i;
  }

  // for our random array, copy the ascending array and then randomly swap items
  // for at least half the number of items, let's hope that works!
  for (int i = 0; i < arraysize/2; i++){
    int a = rand() % arraysize;
    int b = rand() % arraysize;
    if (a != b){
      int temp = randarray[a];
      randarray[a] = randarray[b];
      randarray[b] = temp;
    }
  }

  if(size < 101){
          cout<< "Random array before sort"<<endl;
          for(int i = 0; i < size; i++){
                  cout<<randarray[i]<<"\t";
          }
          cout<<endl;
  }
}

void BenchMark::runRadixSort(int size){
  generateRadixArrays(size);
}
