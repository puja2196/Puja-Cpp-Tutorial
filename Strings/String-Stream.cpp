#include <iostream>
#include <sstream>

using namespace std;

int main() {
  int a{3}, b{4};
  // cout << "Sum of " << a << "&" << b  << " is: "<< sum << endl;
  /* The above gives the output in C- console, to give the output in a text-box,
  we need to add this into a string stream and use that */
  // string s = "Sum of " + a + "&" + b + " is: " + (a+b) + "\n";
  /* + operator won't work for int when used with integer */
  stringstream ss;
  // istringstream iss; => iss is an istream object used for inserting into the
  // string stream ostringstream oss; => oss is an istream object used for
  // output into the string stream

  // Inserting into a string-stream
  ss << "Sum of " << a << " & " << b << " is: " << (a + b) << "\n";

  /* ss.str() has 2 overloads */
  // 1st Overload:
  string s1 = ss.str(); // Returns the copy of the buffer as std string object
  cout << s1 << endl;

  // 2nd Overload: Used to copy anything/ initialize the buffer
  ss.str("12 13 14");
  ss.str("");

  /* To Convert a integer to a std::string object */
  int i = 2;
  ss << i;
  s1 = ss.str();
  cout << "Integer is " << s1 << endl;

  /* Cpp11 introduced to_string(any primitive type) to convert them into string
   * object */
  s1 = to_string(i);
  cout << "Integer is " << s1 << endl;

  /* Extracting Integers from a string stream */
  string data{"12 13 14"};
  ss.str(data);
  int d;
  cout << "Extracting integers one by one from a string: --->\n";
  while (!ss.fail()) {
    ss >> d;
    cout << d << endl;
  }

  /* CPP11 provides function to convert a primitive data in the form of string
   * to their original type Eg. stoi */
  data = "12";
  int j = stoi(data);
  cout << "stoi(\"12\") = " << j << endl;
  return 0;
}
