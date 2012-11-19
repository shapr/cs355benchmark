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

BenchMark::BenchMark(int size){ // set the array size
  arraysize = size;

  sortsizes = new int {10,100,1000,10000};

  // create the arrays
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
  cout << "for an array of type " << arraytype ;
  cout << " the sort of type" << sorttype ;
  cout << " had results:\n";
  cout << loopcounter << " times through the loop\n";
  cout << swapcounter << " swaps were required\n";
  cout << "This gives a loop ratio of " << arraysize << "/" << loopcounter << ".\n";
  cout << "and a swap ratio of " << arraysize << "/" << swapcounter << ".\n";
}

void BenchMark::runSorts(){
  clearStats();
  SelectionSort(randarray);
  reportStats("random","selection");
  clearStats();
  SelectionSort(revarray);
  reportStats("reverse","selection");
  clearStats();
  SelectionSort(sortarray);
  reportStats("sorted","selection");

}


void BenchMark::SelectionSort(){
  for(int i = 0;i < sortsizelength;i++){
    SelectionSortHelper(
  }
}
void BenchMark::SelectionSortHelper(int * arraytosort){
  // do we need to copy the array ourselves?
  int * a = new int [arraysize];
  for (int i = 0; i < arraysize; i++){
    a[i] = arraytosort[i];
  }

  // void selectsort(int *& a,int n){
  int minindex = 0;
  int min;
  for(int i = 0; i < arraysize; i++){
    min = a[i];
    for(int j = i + 1; j < arraysize; j++){
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
