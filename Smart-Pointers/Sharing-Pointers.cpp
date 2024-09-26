#include <iostream>
#include <string>
using namespace std;

class Project {
  string m_name;

public:
  void SetName(const string &s) { m_name = s; }
  void ShowProject() const { cout << "Project Name " << m_name << endl; }
};

class Employee {
  Project *m_pProject;

public:
  void SetProject(Project *prj) { m_pProject = prj; }
  const Project *GetProject() const { return m_pProject; }
};

void showProjectInfo(Employee *e) { e->GetProject()->ShowProject(); }

int main() {
  Project *prj = new Project{};
  prj->SetName("Video Decoder");
  Employee *e1 = new Employee{};
  e1->SetProject(prj);
  Employee *e2 = new Employee{};
  e2->SetProject(prj);
  Employee *e3 = new Employee{};
  e3->SetProject(prj);
  prj->ShowProject();

  // Getting Project Info through employee object
  showProjectInfo(e1);
  delete e1;
  delete e2;
  delete e3;
  delete prj;
  return 0;
}
