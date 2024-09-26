#include <iostream>

using namespace std;

class Animal {
public:
  void Eat() { cout << "Animal Eating" << endl; }
  void Run() { cout << "Animal Running" << endl; }
  void Speak() { cout << "Animal Speaking" << endl; }
};

class Dog : public Animal {
public:
  void Eat() { cout << "Dog Eating Meat" << endl; }
  void Speak() { cout << "Dog Barking" << endl; }
};

int main() {
  Dog d; /* As Dog is inherited from Animal, Dog can uses Animal's member
            function */
  d.Eat();
  d.Run();
  d.Speak();
  /* When the class Dog has no methods implemented, then the output is:
  Animal Eating
  Animal Running
  Animal Speaking
  */
  /* As behaviour of Eating and Speaking is different than other Animal, we can
   * implement those methods in Dog Class */
  /* Now the output is:
  Dog Eating Meat
  Animal Running
  Dog Barking

  Now Eat() and Speak() are called from Dog Class.
  */
  return 0;
}
