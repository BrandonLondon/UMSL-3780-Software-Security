#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <stdlib.h>
signed int add(int, int);
signed int divide(int, int);
signed int multiply(int, int);
int main() {
  signed int a, b, c, d, m  = 0;
  std::cout << "Please enter the first Integer: ";
  std::cin >> a;

  if ((a <= INT_MIN) || (a >= INT_MAX)) {
    std:: cout << "Overflow Error " <<std::endl;
    exit (EXIT_SUCCESS);
  }
  std:: cout << "Please enter in the second Integer:";
  std::cin >> b;
  if ((b <= INT_MIN) || (b >= INT_MAX)) {
    std:: cout << "Overflow Error " <<std::endl;
    exit (EXIT_SUCCESS);
  }

  //addition
  try{
    c = add(a, b);
    std::cout << " The first added to the second is: " << c << std::endl;
  } catch(std::runtime_error & e) {
    std::cout << "EXCEPTION WHEN ADDING" << std::endl << e.what();
  }
  // multiplication
  try{
    m = multiply(a, b);
    std::cout << "The first multiplied by the second is: " << m << std::endl;
  } catch (std::runtime_error & e) {
    std::cout << "EXCEPTION WHEN MULTIPLIED" << std::endl;
  }
  //divide
  try {
    d = divide(a, b);
    std::cout<< "The first divided by the second is: " << d << std::endl;
  } catch (std::runtime_error & e) {
    std::cout << "EXCEPTION WHEN DIVIDED" << std::endl << e.what();
  }

  std::cout << "ALL ARITHMETIC COMPLETED SUCCESSFULLY" << std::endl;
}

signed int add(int a, int b){
  // overflow handler
  if (((b > 0) && (a > (INT_MAX -b))) || ((b < 0) && (a < (INT_MIN - b))))  {
    throw std:: runtime_error("RESULTS IN OVERFLOW WHEN ADDED!\n");
  }
  else{ 
    return a + b;
  }
}

signed int multiply(int a, int b){
  if ((b > INT_MAX / a) || (b < INT_MIN / a)){
    throw std::runtime_error("EXCEPTION ERROR\n");
  }
  else {
    return a * b;
  }
}

signed int divide(int a, int b) {
  if ((b == 0)|| ((a == INT_MIN && (b == -1)))) {
    throw std::runtime_error("EXCEPTION ERROR\n");
  }
  else {
    return a / b;
  }
}
