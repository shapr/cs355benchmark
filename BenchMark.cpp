#include "BenchMark.h"
#include <stdlib.h>
#include <stdio.h>

/*
  arrays to sort for testing:
  sorted
  reverse sorted
  random
  all same item
  zero size
 */
BenchMark::BenchMark(int size){ // set the array size
  arraysize = size;

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

void BenchMark::reportStats(){
  printResults(); // is this right?
}

void BenchMark::printResults(string arraytype, string sorttype){
  cout << "for an array of type" << arraytype ;
  cout << " the sort of type" << sorttype ;
  cout << " had results:\n";
  cout << loopcounter " times through the loop\n";
  cout << swapcounter " swaps were required\n";
  cout << "This gives a loop ratio of " << arraysize << "/" << loopcounter << ".\n";
  cout << "and a swap ratio of " << swapcounter "/" arraysize << ".\n";
}

void BenchMark::runSorts(){
  clearStats();
  SelectionSort(randarray);
  reportStats("random","selection");
}

void BenchMark::SelectionSort(int * arraytosort){
  int * a = new int [arraysize];
  for (int i = 0; i < arraysize; i++){
    myarray[i] = arraytosort[i];
  }

  // void selectsort(int *& a,int n){
  int minindex;
  int min;
  for(int i = 0; i < n; i++){
    min = a[i];
    for(int j = i + 1; j < n; j++){
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
