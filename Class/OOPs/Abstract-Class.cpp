#include <iostream>

using namespace std;

class Document {
public:
  /* Case - 1 */
  /*
      virtual void Serialize() {
          cout << "Document::Serialize\n";
      }
  */
  // case 2:
  virtual void Serialize() = 0; // No definition, pure virtual function, child
                                // classes need to provide implementation
};

class Text : public Document {
public:
  void Serialize() override final { cout << "Text::Serialize\n"; }
};

class Xml : public Document {
  // Case 3:
public:
  void Serialize() override final { cout << "Xml::Serialize\n"; }
};

void Write(Document *p) { p->Serialize(); }

int main() {

  Xml xml{};
  Write(&xml);
  /* Case 1:
  In Write, xml is passed as reference, but as we dont have any Serialize()
  method for Xml, Document::Serialize will be inherited and invoked */
  /* To catch this error, make the Serialize method in Document class as Pure
  Virtual function, using

  Case 2:
      virtual void Serialize() = 0;
  Xml is a child of abstract class "Document" and doesnt have implementation of
  pure virtual function "Serialize", so Xml becomes an abstract class and you
  can't instantiate from Xml Class.

  Case 3:
  Implement Serialize method in Xml Class:
  */
  return 0;
}
