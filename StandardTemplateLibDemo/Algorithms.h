#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <functional>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class EmployeeForAlgs {
	std::string m_Name;
	int m_Id;
	std::string m_ProgLang;
public :
	EmployeeForAlgs(const std::string& name, int id, const std::string& pl) : m_Name(name), m_Id(id), m_ProgLang(pl) {}
	const std::string& GetName() const {
		return m_Name;
	}
	int GetId() const {
		return m_Id;
	}
	const std::string& GetProgrammingLanguage() const {
		return m_ProgLang;
	}
	bool operator < (const EmployeeForAlgs& e) const {
		return m_Id < e.m_Id; // try change sign to >, and see magic
	}
};

// to provide sorting ability for st, multiset and multimap
// fo unordered containers implement the hash function and override comparison
struct EmployeeForAlgsCompare {
	bool operator () (const EmployeeForAlgs& e1, const EmployeeForAlgs& e2)const {
		return e1.GetId() < e2.GetId();
	}
};

void UserDefinedSets() {
	std::vector<EmployeeForAlgs> v{
		EmployeeForAlgs{"andersson", 1, "C++"}
		,EmployeeForAlgs{"chikuse", 2, "Java"}
	};

	std::set<EmployeeForAlgs, EmployeeForAlgsCompare> s{
		EmployeeForAlgs{"andersson", 1, "C++"}
		,EmployeeForAlgs{"chikuse", 2, "Java"}
	};

	struct EmpIds {
		std::vector<int> m_Ids;
		// override the () for this to be a func object
		void operator() (const EmployeeForAlgs& emp) {
			m_Ids.push_back(emp.GetId());
		}
	};
	// sort 
	std::sort(v.begin(), v.end());
	// sorting using lambda predicate
	std::sort(v.begin(), v.end(), [](const EmployeeForAlgs & e1, const EmployeeForAlgs& e2) -> bool {
		
		return e1.GetName() < e2.GetName();

   });

	int cppCount{};
	for (const auto& e : v) {
		if (e.GetProgrammingLanguage() == "C++")
			++cppCount;
	}
	// using stl count
	// cppCount = std::count(v.begin(), v.end(), EmployeeForAlgs{ "", 0, "C++" }); // to use this you need to override the equality operator == in EmployeeForAlgs
	cppCount = std::count_if(v.begin(), v.end(), [](const auto& e) -> bool {
		return e.GetProgrammingLanguage() == "C++";

		});
	// search for a java programmer
	auto iterator = std::find_if(v.begin(), v.end(), [](const auto& e) -> bool {
		
		return e.GetProgrammingLanguage() == "Java";

		});
	if (iterator != v.end())
	{
		std::cout << "Java programmer found. " << iterator->GetName() << std::endl;
	}


	// The ForEach Algorithm
	auto foundIds = std::for_each(v.begin(), v.end(), EmpIds());
	for (int id : foundIds.m_Ids) {
		std::cout << "Id: " << id << std::endl;
	}

}