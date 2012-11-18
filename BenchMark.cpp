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
BenchMark::BenchMark(){ // no argument, pick an array size
  int ary [10] = {0,1,2,3,4,5,6,7,8,9};
  testarray = & ary; // point to our newly created array
    
}
