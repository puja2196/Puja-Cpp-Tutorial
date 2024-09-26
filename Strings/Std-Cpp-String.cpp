#include <iostream>
#include <string>
using namespace std;

int main() {

  cout << "Size of std::string is: " << sizeof(std::string) << endl;
  /*

  */
  // Initializing & Assignment
  string s1;
  s1 = "Hello"; // Assignment Operator overloading

  string s2 = "Hi"; // Parameterized Constructor Invoking

  // Preferable Initialization : Direct Initialization
  string s3{"Puja"};

  // s is indicative of string type
  auto s4 = "Puja Saha"s;

  // Access
  s1[2] = 'b';
  cout << "String s1 is: " << s1 << endl;

  char ch = s2[0];

  cout << "Enter a new string for s2: ";

  // cin >> s2; // It will only read one word means till first Whitespace
  getline(cin, s2); // No need of count

  cout << "String s2 is: " << s2 << endl;

  // Sizes
  s1.length();

  // Insert & Concatenate
  string s = s1 + s2;

  s += s2; // s = s + s2;

  s.insert(5, "World");

  // Comparison
  /* you can use "==", "!=", "<", ">" etc */
  if (s1 == s2) {
  }

  // Search
  auto pos = s.find("World", 0); // search for "World" from 0th position
  if (pos != string::npos) {
    cout << "World is found in s\n";
  }

  // Return C style null terminated raw string from Cpp String
  printf("s is %s\n", s.c_str());

  // Removal
  s.erase();      // erase the entire string
  s2.clear();     // erase the entire string
  s1.erase(0, 3); // range : It will erase first 3 characters

  return 0;
}
