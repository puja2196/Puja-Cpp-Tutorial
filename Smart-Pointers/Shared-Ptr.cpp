#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Project {
  string m_name;

public:
  void SetName(const string &s) { m_name = s; }
  void ShowProject() const { cout << "Project Name " << m_name << endl; }
};

class Employee {
  shared_ptr<Project> m_pProject{};

public:
  void SetProject(const shared_ptr<Project> &prj) { m_pProject = prj; }
  const shared_ptr<Project> &GetProject() const { return m_pProject; }
};

void showProjectInfo(const shared_ptr<Employee> &e) {
  e->GetProject()->ShowProject();
}

int main() {
  shared_ptr<Project> prj{new Project{}};
  prj->SetName("Video Decoder");
  shared_ptr<Employee> e1{new Employee{}};
  e1->SetProject(prj);
  shared_ptr<Employee> e2{new Employee{}};
  e2->SetProject(prj);
  shared_ptr<Employee> e3{new Employee{}};
  e3->SetProject(prj);

  // Getting Project Info through employee object
  showProjectInfo(e1);
  showProjectInfo(e2);
  prj->ShowProject();
  /* How does Shared Ptr know howmany copies it has?
     Keeps track of reference count */
  cout << "Reference Count = " << prj.use_count()
       << endl; // 4 => For debug its used
                /* When the underlying pointer gets deleted ?
                   => When reference count becomes zero, the underlying pointers get deleted.
                */
  /* you can use all the operations: boolean and logical over shared_ptr like
   * unique_ptr */
  if (e3) {
    cout << "e3 is Valid\n";
  }

  /* If I dont want e3 to point its underlying pointer, we can do it by "reset"
     method
     => reset(new Employee{}) => decrease the reference count, check if the ref
     count is Zero, if so, delete the underlying pointers, otherwise leave and
     assign a new Employee object to e3
     => reset() => decrease the reference count, check if the ref count is Zero,
     if so, delete the underlying pointers otherwise leave
  */
  e3.reset();
  cout << "After reseting e3, Reference Count of prj = " << prj.use_count()
       << endl; // 3

  e2.reset(new Employee{});
  cout << "After reseting e2 and assigning a new Employee to e2, Reference "
          "Count of prj = "
       << prj.use_count() << endl; // 2

  e2->SetProject(prj);
  cout << "After setting prj for e2, Reference Count of prj ="
       << prj.use_count() << endl; // 3
  return 0;
}
