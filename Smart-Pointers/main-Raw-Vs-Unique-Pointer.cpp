#include "Integer.h"
#include <iostream>
#include <memory>

using namespace std;

Integer *Getptr(int i) {
  Integer *i1 = new Integer{i}; // => calls Integer(int)
  return i1;
}

void Display(Integer *i) {
  if (!i)
    return;
  cout << "i = " << i->get() << endl;
}

void operate(int i) {
  Integer *p = Getptr(i);
  if (p == nullptr) {
    p = new Integer{i};
  }
  p->set(100);
  Display(p);
  delete p;
  p = nullptr;
  p = new Integer{}; // calls Integer()
  *p = __LINE__;     /*
      *p is Integer pointer type, so *p = Integer(__LINE__) =>
      so first Integer(int) will be called and then it will assign to *p.
      So Move assignement operator will be called. because: it is assignment
      and argument(__LINE__) is r-value.*/
  Display(p);
  delete p;
}

void Store_pass_by_value(unique_ptr<Integer> p) {
  cout << "Storing the data into m/y : " << p->get() << endl;
}

void Store_pass_by_ref(unique_ptr<Integer> &p) {
  cout << "Storing the data into m/y : " << p->get() << endl;
}

/* With Smart pointers we dont need to deal with delete anymore: same number of
Constructors and Destructors call */
void operate_by_unique_ptr(int i) {
  unique_ptr<Integer> p{Getptr(i)}; // Integer *p = Getptr(i);
  if (p == nullptr) {
    /* p is nullptr here, you can't assign p pointing to a new Integer
    p = new Integer{i}; ==> Error
    */
    p.reset(new Integer{i});
    /* If p is holding anything, it will reset and then
    you can assign new Integer where p can point to*/
  }
  p->set(100);
  /* Display(p); => Here p is a unique_ptr object and Display accepts
     an Integer pointer, so we need to get the underlying Integer pointer
     of unique_ptr using get() method of std::unique_ptr */
  Display(p.get());
  /* delete p; => Error because can't call delete on an object */
  // p = nullptr; => Not needed because reset will be called
  p.reset(new Integer{}); // Need to call reset and then assign
  *p = __LINE__;          /*
           *p is Integer pointer type, so *p = Integer(__LINE__) =>
           so first Integer(int) will be called and then it will assign to *p.
           So Move assignement operator will be called. because: it is assignment
           and argument(__LINE__) is r-value.*/
  Display(p.get());
  // delete p; => No need to call delete
  /* Suppose You can't copy a unique_ptr, Store() is a function where we need
     to pass the unique_ptr p,
     1. you can pass by reference
     2. If Store is last function after which underlying Integer pointer will
     be no longer be used, you can pass by value by doing std::move(p)
     After that you can't use the underlying Integer pointer of p and you
     can re-assign a new Integer to p */

  /* Case 1 */
  Store_pass_by_ref(p);
  *p = 200;
  // Store_pass_by_value(p); ==> Error: we can't copy p.
  Store_pass_by_value(
      move(p)); //==> we can move it to a pointer and then pass by value
  // *p = 300; ==> Segfault bcz already moved from p and so the constructor of p
  // is deleted and we can't assign to *p
  p.reset(new Integer{300}); // It can be done
}

int main() {
  operate(5);
  operate_by_unique_ptr(6);
}
