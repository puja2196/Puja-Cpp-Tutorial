/* Exercise: The std::string function does not provide any function to convert
the underlying string to upper case or lower case. Write two functions that
provide this behavior. Both functions return a copy of the converted string. In
case of error, return an empty string.

std::string ToUpper(const std::string &str) ;
std::string ToLower(const std::string &str) ;
Hint : Use toupper & tolower from C string library. */
#include <iostream>
#include <string>

using namespace std;

std::string ToUpper(const std::string &str) {
  string result{""};
  for (char c : str) {
    result += toupper(c);
  }
  return result;
}

std::string ToLower(const std::string &str);

int main() {
  string s1;
  cout << "Enter a string to convert to Upper case: ";
  getline(cin, s1);
  cout << "After converting to Upper case, the string is: " << ToUpper(s1)
       << endl;
  return 0;
}
