// include input output stream standard library of c++
// Minh Truong 
#include <iostream>

// namespace for c++ standard library to avoid using prefix std
using namespace std;

// declare signature of fibo function to be used in main, no need to include the body
double fibo(int n);

// entry point of every c++ program
int main(int argc, char *argv[])
{

  // call fibo function and assign returning value to variable p
  int p = fibo(10);

  // print the value of p into output stream, flush everything out
  cout << p << endl;
}

// definition of fibo function
double fibo(int n) {

  // declaration of variables of the function
  unsigned int i = 0, j = 1, t, k;

  // for loop from 0 to n inclusively
  for (k=0; k <= n; ++k)
  {

    // sum i , j and assign to t
    t = i + j;

    // assign to i value of j
    i = j;

    // assign to j value of t
    j = t;
  }

  // return value of j
  return j;
}
