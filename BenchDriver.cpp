#include "BenchMark.h"
#include <iostream>

using namespace std;
void PrintMenu();
int main () {
    BenchMark bm = BenchMark();
    PrintMenu();
    char choice;
    cin >> choice;
    while(choice != 'E' && choice != 'e'){
        switch(choice){
             case 'H':
             case 'h':
                    PrintMenu();
                    break;
             case 'B':
             case 'b':
                  bm.BubbleSort();
                  break;
             case 'S':
             case 's':
                  bm.SelectionSort();
                  break;
             case 'I':
             case 'i':
                  bm.InsertionSort();
                  break;
             case 'M':
             case 'm':
                  bm.MergeSort();
                  break;
             case 'Q':
             case 'q':
                  bm.QuickSort();
                  break;
             case 'R':
             case 'r':
                  break;
             default:
                     cout << "INVALID CHOICE, Choose Again" << endl;
        }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"READY FOR NEXT TEST"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cin >> choice;
    cout<<endl;
    }

    // system("pause");
  return 0;
}
void PrintMenu(){
     cout << "  Command Line Options" << endl;
	 cout << "  H\tHelp: Show Comman Line Options" << endl;
	 cout << "  B:  Test Bubble sort" << endl;
	 cout << "  S:  Test Selection sort" << endl;
	 cout << "  I:  Test Insertion sort" << endl;
	 cout << "  M:  Test Merge sort" << endl;
	 cout << "  Q:  Test Quick sort" << endl;
	 cout << "  R:  Test Radix sort" << endl;
     cout << "  E:  Exit the test program" << endl;
	 cout << endl;
}
