#ifndef BENCHMARK_H
#define BENCHMARK_H

class BenchMark{
 public:
  BenchMark();
  // getStats();
  void Print();
  // sorts go here
  void BubbleSort();
  void RadixSort();
  void QuickSort();
  void SelectionSort();
  void InsertionSort();
  void MergeSort();

 private:
  int counter;
  int * randarray; // pointer to a randomized array where each item is different
  int * sortarray; // pointer to a ascending order sorted array where each item is different
  int * revarray; //  pointer to a descending order sorted array where each item is different
  int * zeroarray; // pointer to a size zero array
  int * onearray; // pointer to a size one array
  int * duparray; // pointer to an array where
};

#endif
