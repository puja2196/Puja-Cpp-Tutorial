#include <iostream>
#include <string>

using namespace std;

enum class Case { SENSITIVE, INSENSITIVE };

std::string ToUpper(const std::string &str) {
  string result{""};
  for (char c : str) {
    result += toupper(c);
  }
  return result;
}

size_t Find(const std::string &source,        // Source string to be searched
            const std::string &search_string, // The string to search for
            Case searchCase =
                Case::INSENSITIVE, // Choose case sensitive/insensitive search
            size_t offset = 0) {   // Start the search from this offset
  // Implementation
  string src{source}, search{search_string};
  if (searchCase == Case::INSENSITIVE) {
    src = ToUpper(source);
    search = ToUpper(search_string);
  }

  // Search
  return src.find(search,
                  offset); // search for search in src from offset position
                           /*
                           return position of the first character
                           of the substring, else std::string::npos
                           */
}

int main() {

  string s1;
  string s2;
  int i, j;

  cout << "Enter Source String: ";
  getline(cin, s1);
  cout << "Enter Search String: ";
  getline(cin, s2);
  cout << "Enter the starting offset: ";
  cin >> i;
  cout << "Enter the way you want to search: 1. case-sensitive  2. "
          "case-insensitive  : ";
  cin >> j;
  Case c = static_cast<Case>(j - 1);
  auto pos = Find(s1, s2, c, i);

  if (pos != string::npos) {
    cout << "Found in " << pos << endl;
  } else
    cout << "Not Found\n";
  return 0;
}
