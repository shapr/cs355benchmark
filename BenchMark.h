#ifndef BENCHMARK_H
#define BENCHMARK_H

using namespace std;
#include <string>

class BenchMark{
 public:
  BenchMark(int size);
  void runSorts();
  void printResults();
  void clearStats();
  void reportStats(string arraytype, string sorttype);
  void Setup(); // this makes a copy of the arrays before sorting
  // sorts go here
  void BubbleSort();
  void RadixSort();
  void QuickSort();
  void SelectionSort(int * arraytosort);
  void InsertionSort();
  void MergeSort();
  void setSortSizes(); // setSortSizes(1024,2048,4096);

 private:
  int sortsizelength;
  int * sortsizes; // currently 10,100,1000,10000
  static int loopcounter;
  static int swapcounter;
  int arraysize; // the size of our arrays
  int * randarray; // the random array the sort algorithm should use
  int * sortarray; // pointer to a ascending order sorted array where each item is different
  int * revarray; //  pointer to a descending order sorted array where each item is different
  int * zeroarray; // pointer to a size zero array
  int * onearray; // pointer to a size one array
  int * duparray; // pointer to an array where
};

#endif
