#include <iostream>

using namespace std;

/* With final keyword, you make the class non-inheritable */
class Image final {};

/* error: cannot derive from ‘final’ base ‘Image’ in derived type ‘CarImage’
class CarImage : public Image {
}
*/

class Document {
public:
  virtual void Serialize(float version) { cout << "Document::Serialize\n"; }
};

class Text : public Document {
public:
  void Serialize(int version) { cout << "Text::Serialize\n"; }
};

class Pdf : public Document {
public:
  /* Case 1 :
      void Serialize(int version) override {
          cout << "Pdf::Serialize\n";
      }
  */
  // Case 2:

  void Serialize(float version) override { cout << "Pdf::Serialize\n"; }

  // Case 3:
  /*
      void Serialize(float version) override final{
          cout << "Pdf::Serialize\n";
      }
  */
};

class RichPdf : public Pdf {
  /* If you don't want to override Serialize method from Pdf, you can mark the
  method as final like Case - 3: In this case the following will give error:
  error: virtual function ‘virtual void RichPdf::Serialize(float)’ overriding
  final function
  */

public:
  void Serialize(float version) override { cout << "RichPdf::Serialize\n"; }
};

int main() {
  Document *d1 = new Text{};
  d1->Serialize(10); /* It will call Document::Serialize(); As the method is not
overrided due to mismatch in the function signature,  it will match with the
Document::Serialize() To catch the error, override keyword can be used with the
methods overridden For eg: in Pdf::Serialize()

This will catch the error:
Case - 1: Error:
  ‘void Pdf::Serialize(int)’ marked ‘override’, but does not override
So now author will modify the method to match the signature: Serialize(float
version) of Pdf :

Case - 2:
*/
  Document *d2 = new Pdf{};
  d2->Serialize(10.1f); // Pdf::Serialize because now its correctly overridden.
  return 0;
}
