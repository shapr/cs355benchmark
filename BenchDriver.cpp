#include "BenchMark.h"
#include <iostream>

using namespace std;

int main () {
  BenchMark b10 = BenchMark(10);
  b10.runSorts();
  // b10.printResults();

  BenchMark b100 = BenchMark(100);
  b100.runSorts();
  // b100.printResults();

  BenchMark b1000 = BenchMark(1000);
  b1000.runSorts();
  // b1000.printResults();

  BenchMark b10000 = BenchMark(10000);
  b10000.runSorts();
  // b10000.printResults();

  cout << "That's all folks!";
  return 0;
}
