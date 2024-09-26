#include <iostream>
#include <memory>

using namespace std;

class Employee;

class Project {
public:
  shared_ptr<Employee> emp;
  Project() { cout << "Project()" << endl; }
  ~Project() { cout << "~Project()" << endl; }
};

class Employee {
public:
  shared_ptr<Project> prj;
  /* weak_ptr<Project> prj; ==> Solves the problem */
  Employee() { cout << "Employee()" << endl; }
  ~Employee() { cout << "~Employee()" << endl; }
};

int main() {
  shared_ptr<Employee> e1{new Employee{}}; // Ref-count(e1) = 1
  shared_ptr<Project> p1{new Project{}};   // Ref-count(p1) = 1

  e1->prj = p1; // Ref-count(p1) = 2 if prj is a shared_ptr, but if it is a
                // weak_ptr, it wont increase the ref-count: Ref-count(p1) = 1.
  p1->emp = e1; // Ref-count(e1) = 2 in both the cases
                /* Circular Reference:
                   Now At the end of the program, when e1 gets destroyed, the underlying
                Employee* reference count becomes 1.               when p1 gets destroyed, the underlying
                Project* reference count becomes 1. None of the underlying pointers               reference
                count is not Zero, so No destructor will be called, so memory leak,
              
                Solution: Use weak_ptr for data member of one of the classes.
                   Now At the end of the program, when e1 gets destroyed, the underlying
                Employee* reference count becomes 1.               when p1 gets destroyed, the underlying
                Project* reference count becomes 0. So it will call delete on the               underlying
                pointer(Project*). so Project->emp will be nullptr, by that Employee*
                reference count also becomes 0.
                */
  return 0;
}
