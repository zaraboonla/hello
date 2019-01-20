#include <iostream>
#include "learn.h"

using namespace std;

int main(int argc, char *argv[]){
  int x1 = 10;
  int x2 = 20;
  std::cout << "Hello World!" << add(x1, x2) << std::endl;

  printSize();
  printInfNan();
  printBool();
  printChar();
  printBitwise();
  std::cout << getRandomNumber() << std::endl;
  std::cout << getRandomNumber(1, 6) << std::endl;
  std::cout << getRandom() << std::endl;
  printVector();
  
  return 0;
}
