#include <iostream>

using namespace std;

int main() {

  /* By default compiles with -m64 */
  /* If you like to compile with -m32,
  sudo apt-get install gcc-multilib g++-multilib libc6-dev-i386
  Then use; g++ -m32 */
  cout << "Integral Types:\n";                               // 32 bit // 64 bit
  cout << "sizeof(bool) = " << sizeof(bool) << endl;         // 1     // 1
  cout << "sizeof(char) = " << sizeof(char) << endl;         // 1     // 1
  cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;   // 4     // 4
  cout << "sizeof(char16_t) = " << sizeof(char16_t) << endl; // 2     // 2
  cout << "sizeof(char32_t) = " << sizeof(char32_t) << endl; // 4     // 4
  cout << "sizeof(short) = " << sizeof(short) << endl;       // 2     // 2
  cout << "sizeof(int) = " << sizeof(int) << endl;           // 4     // 4
  cout << "sizeof(long) = " << sizeof(long) << endl;         // 4     // 8

  cout << "Floating Point Types:\n";
  cout << "sizeof(float) = " << sizeof(float) << endl;   // 4     // 4
  cout << "sizeof(double) = " << sizeof(double) << endl; // 8     // 8

  /*
  In 32-bit mode (-m32), a pointer is 4 bytes. Bcz: Address is 32 bit i.e. 4
  bytes In 64-bit mode (-m64), a pointer is 8 bytes. Bcz: Address is 64 bit i.e.
  8 bytes
  */

  cout << "sizeof(int*) = " << sizeof(int *) << endl; // 4     // 8
                                                      /* Size of std::string:
                                                    
                                                      In 32-bit mode:
                                                      Pointer to heap-allocated string data (4 bytes).
                                                      Size of the string (4 bytes).
                                                      Capacity (4 bytes).
                                                      Other members (e.g., SSO, control bytes) might add up to 24 bytes total,
                                                      accounting for alignment and padding.
                                                    
                                                      In 64-bit mode:
                                                      Pointer to heap-allocated string data (8 bytes).
                                                      Size of the string (8 bytes).
                                                      Capacity (8 bytes).
                                                      Additional space for SSO or other members may make the size grow to 32 bytes.
                                                       */

  cout << "sizeof(std::string) = " << sizeof(std::string)
       << endl; // 24    // 32
  return 0;
}
