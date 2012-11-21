#ifndef BENCHMARK_H
#define BENCHMARK_H

using namespace std;
#include <string>
#include <vector>

class BenchMark{
 public:
  BenchMark();
  void runSelectionSorts(int size);
  void runBubbleSorts(int size);
  void runRadixSorts(int size);
  void runQuickSorts(int size);
  void runInsertionSorts(int size);
  void runMergeSorts(int size);
  void printResults();
  void clearStats();
  void reportStats(string arraytype, string sorttype);
  void Setup(); // this makes a copy of the arrays before sorting
  // sorts go here
  void BubbleSort();
  void BubbleSortHelper(int *& a, int size);
  void RadixSort();
  void QuickSort();
  void QuickSortHelper(int *& a, int left, int right);
  void SelectionSort();
  void SelectionSortHelper(int *& a, int size);
  void InsertionSort();
  void InsertionSortHelper(int *& a, int size);
  void MergeSort();
  void MergeSortHelper(int *& a,int left, int right);
  void merge(int *& a, int left, int mid, int right);
  void setSortSizes(); // setSortSizes(1024,2048,4096);
 protected:
  void generateArrays(int size);

 private:
  vector<int> sortsizes;
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
