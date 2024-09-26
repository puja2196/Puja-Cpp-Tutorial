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
  unique_ptr<Project> m_pProject{};

public:
  void SetProject(unique_ptr<Project> &prj) { m_pProject = std::move(prj); }
  const unique_ptr<Project> &GetProject() const { return m_pProject; }
};

void showProjectInfo(const unique_ptr<Employee> &e) {
  e->GetProject()->ShowProject();
}

int main() {
  unique_ptr<Project> prj{new Project{}};
  prj->SetName("Video Decoder");
  unique_ptr<Employee> e1{new Employee{}};
  e1->SetProject(
      prj); // After you do SetProject(prj), you move the prj from Project to
            // Employee, now you can't access prj any more.
  unique_ptr<Employee> e2{new Employee{}};
  e2->SetProject(prj);
  unique_ptr<Employee> e3{new Employee{}};
  e3->SetProject(prj);

  // Getting Project Info through employee object
  showProjectInfo(e1);
  showProjectInfo(e2);
  prj->ShowProject(); // Seg-Fault
  /*delete e1;
  delete e2;
  delete e3;
  delete prj; ==> Not needed as unique pointer is used */
  return 0;
}
