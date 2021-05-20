
#include<memory>
#include <iostream>
class Project {

};

class EmployeeForHash
{
public:
	void SetProject(std::shared_ptr<Project> p) {
		m_pProject = p;
	}
	std::shared_ptr<Project> GetProject() const {
		return m_pProject;
	}

private:
	std::shared_ptr<Project> m_pProject;
};

std::shared_ptr<EmployeeForHash> AssignProject() {
	std::shared_ptr<Project> p{ new Project };
	EmployeeForHash* e1 = new EmployeeForHash();
	e1->SetProject(p);
	return std::shared_ptr<EmployeeForHash>{e1};
}

void TestSharedPointers() {
	auto sp = AssignProject();
}
