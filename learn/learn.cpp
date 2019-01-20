#include <iostream>
#include <bitset>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include <random> // for std::mt19937 //C++11
#include <vector> // for std::vector

int add(int x, int y) {
  return x + y;
}

void printSize()
{
  std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
  std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
  std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << std::endl;
  std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
  std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << std::endl; // C++11, may not be supported by your compiler
  std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
  std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
  std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
  std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl; // C++11, may not be supported by your compiler
  std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
  std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
  std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;

  std::cout << "size_t (32 or 64 bits):\t" << sizeof(size_t) << " bytes" << std::endl;
}

void printInfNan()
{
  double zero = 0.0;
  double posinf = 5.0 / zero; // positive infinity
  std::cout << posinf << std::endl;

  double neginf = -5.0 / zero; // negative infinity
  std::cout << neginf << std::endl;

  double nan = zero / zero; // not a number (mathematically invalid)
  std::cout << nan << std::endl;
}

void printBool()
{
  std::cout << true << std::endl;
  std::cout << false << std::endl;

  std::cout << std::boolalpha; // print bools as true or false

  std::cout << true << std::endl;
  std::cout << false << std::endl;
}

void printChar()
{
  char ch(97);
  std::cout << ch << std::endl;
  std::cout << static_cast<int>(ch) << std::endl;
  std::cout << ch << std::endl;
}

void printBitwise()
{
    // // C++14 Define 8 separate bit flags (these can represent whatever you want)
    // const unsigned char option0 = 0b0000'0001; // represents bit 0
    // const unsigned char option1 = 0b0000'0010; // represents bit 1
    // const unsigned char option2 = 0b0000'0100; // represents bit 2
    // const unsigned char option3 = 0b0000'1000; // represents bit 3
    // const unsigned char option4 = 0b0001'0000; // represents bit 4
    // const unsigned char option5 = 0b0010'0000; // represents bit 5
    // const unsigned char option6 = 0b0100'0000; // represents bit 6
    // const unsigned char option7 = 0b1000'0000; // represents bit 7

    // // C++11 Define 8 separate bit flags (these can represent whatever you want)
    // const unsigned char option0 = 0x1; // hex for 0000 0001
    // const unsigned char option1 = 0x2; // hex for 0000 0010
    // const unsigned char option2 = 0x4; // hex for 0000 0100
    // const unsigned char option3 = 0x8; // hex for 0000 1000
    // const unsigned char option4 = 0x10; // hex for 0001 0000
    // const unsigned char option5 = 0x20; // hex for 0010 0000
    // const unsigned char option6 = 0x40; // hex for 0100 0000
    // const unsigned char option7 = 0x80; // hex for 1000 0000

    // // Define 8 separate bit flags (these can represent whatever you want)
    // const unsigned char option0 = 1 << 0; // 0000 0001
    // const unsigned char option1 = 1 << 1; // 0000 0010
    // const unsigned char option2 = 1 << 2; // 0000 0100
    // const unsigned char option3 = 1 << 3; // 0000 1000
    // const unsigned char option4 = 1 << 4; // 0001 0000
    // const unsigned char option5 = 1 << 5; // 0010 0000
    // const unsigned char option6 = 1 << 6; // 0100 0000
    // const unsigned char option7 = 1 << 7; // 1000 0000

    // Note that with std::bitset, our options correspond to bit indices, not bit patterns
    const int option0 = 0;
    const int option1 = 1;
    const int option2 = 2;
    const int option3 = 3;
    const int option4 = 4;
    const int option5 = 5;
    const int option6 = 6;
    const int option7 = 7;

    std::bitset<8> bits(0x2); // we need 8 bits, start with bit pattern 0000 0010
    bits.set(option4); // set bit 4 to 1 (now we have 0001 0010)
    bits.flip(option5); // flip bit 5 (now we have 0011 0010)
    bits.reset(option5); // set bit 5 back to 0 (now we have 0001 0010)

    std::cout << "Bit 4 has value: " << bits.test(option4) << '\n';
    std::cout << "Bit 5 has value: " << bits.test(option5) << '\n';
    std::cout << "All the bits: " << bits << '\n';
}

int getRandomNumber()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
    return std::rand();
}

// Generate a random number between min and max (inclusive)
// Assumes std::srand() has already been called
// Assumes max - min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int getRandom()
{
	// Initialize our mersenne twister with a random seed based on the clock
	std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	// std::uniform_int_distribution<> die(1, 6);

	// // Print a bunch of random numbers
	// for (int count = 1; count <= 48; ++count)
	// {
	// 	std::cout << die(mersenne) << "\t"; // generate a roll of the die here
  //
	// 	// If we've printed 6 numbers, start a new row
	// 	if (count % 6 == 0)
	// 		std::cout << "\n";
	// }
  std::uniform_int_distribution<> die(1, 32767);
	return die(mersenne);
}

void printVector()
{
  std::vector<int> myvector{ 1, 2, 3, 4, 5 };
  myvector.push_back(6);
  // Vector becomes 1, 2, 3, 4, 5, 6

  for (auto it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;

  // Note get N "4" and then next line "1 2 3 4" to A
  // int N,i=0;
  // cin>>N;
  // int *A = new int[N];
  // while(std::cin>>A[i++]);
  // while(std::cout<<A[--N]<<' ' && N);
  // delete[] A;
}
