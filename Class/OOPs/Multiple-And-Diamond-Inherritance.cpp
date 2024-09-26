#include <iostream>
#include <string>

using namespace std;

class Stream {
  string m_filename;

public:
  Stream(const string &file) : m_filename{file} {
    cout << "Stream(const string &)\n";
  }
  const string &Getfilename() const { return m_filename; }
  ~Stream() { cout << "~Stream()\n"; }
};

/* Ostream inherited from Stream */
// Case 1: class Ostream : public Stream{...}
// case 2:
class Ostream : virtual public Stream {
  ostream &out;

public:
  Ostream(const string &file, ostream &ou) : Stream{file}, out{ou} {
    cout << "Outputstream\n";
  }
  ostream &operator<<(const string &data) {
    out << data;
    return out;
  }
  ~Ostream() { cout << "~Outputstream\n"; }
};

/* Istream inherited from Stream */
// Case 1: class Istream : public Stream{...}
// case 2:
class Istream : virtual public Stream {
  istream &in;

public:
  Istream(const string &file, istream &i) : Stream{file}, in{i} {
    cout << "Inputstream\n";
  }
  istream &operator>>(string &data) {
    in >> data;
    return in;
  }
  ~Istream() { cout << "~Inputstream\n"; }
};

/* Multiple Inheritance: Iostream is inherited from multiple classes: Ostream
and Istream. So It can lead to Diamond problem. If both of the base class
inherits from same class i.e. Stream here. */

class Iostream : public Ostream, public Istream {
public:
  Iostream(const string &file)
      : Ostream{file, cout}, Istream{file, cin}, Stream{file} {
    cout << "I/O-stream\n";
  }
  ~Iostream() { cout << "~I/O-stream\n"; }
};

int main() {
  Iostream io{"doc.txt"};
  /*
  Case 1:
  The output is:

  Stream(const string &)
  Outputstream
  Stream(const string &)
  Inputstream
  I/O-stream
  ~I/O-stream
  ~Inputstream
  ~Stream()
  ~Outputstream
  ~Stream()

  Stream class constructor is called twice as while creating Ostream and
  Istream. Now if you want to call method "Getfilename()" on this, it wont work
  cout << io.Getfilename() << endl; // request for member ‘Getfilename’ is
  ambiguous

  Case 2:
    Inherit Ostream and Istream virtually from Stream.
  */
  cout << io.Getfilename() << endl;
  /* The output is:
  Stream(const string &)
  Outputstream
  Inputstream
  I/O-stream
  doc.txt
  ~I/O-stream
  ~Inputstream
  ~Outputstream
  ~Stream()
  */
  return 0;
}
