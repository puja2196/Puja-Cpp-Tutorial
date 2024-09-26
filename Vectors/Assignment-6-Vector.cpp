#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Case { SENSITIVE, INSENSITIVE };

std::string ToUpper(const std::string &str) {
  string result{""};
  for (char c : str) {
    result += toupper(c);
  }
  return result;
}

std::vector<int>
FindAll(const std::string &target,        // Target string to be searched
        const std::string &search_string, // The string to search for
        Case searchCase =
            Case::INSENSITIVE, // Choose case sensitive/insensitive search
        size_t offset = 0) {   // Start the search from this offset
  // Implementation
  string targ{target}, search{search_string};
  if (searchCase == Case::INSENSITIVE) {
    targ = ToUpper(target);
    search = ToUpper(search_string);
  }
  /*
  Return indices of found strings,
  else an empty vector
  */
  vector<int> res{};

  auto pos = targ.find(search, offset);
  while (pos != string::npos) { // Found
    res.push_back(pos);
    offset = pos + 1;
    pos = targ.find(search, offset);
  }

  return res;
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
  vector<int> v;
  v = FindAll(s1, s2, c, i);
  cout << "Found in the following offsets: ";
  for (auto x : v) {
    cout << x << ", ";
  }
  cout << endl;
  return 0;
}
