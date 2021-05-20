#pragma once
#include <unordered_set>
#include <unordered_map>
#include <iostream>
void UnOrderedSet() {
	std::unordered_set<std::string> coll{};
	//inserting elements
	coll.insert("My");
	coll.insert("Name");
	coll.insert("Anderson");
	// loop print
	for (const auto &x : coll) {
		std::cout << "Bucket #: " << coll.bucket(x) << " contains: " << x << std::endl;
	}
	// print bucket properties
	std::cout << "Bucket count: " << coll.bucket_count() << std::endl;
	std::cout << "Number of elements: " << coll.size() << std::endl;
	std::cout << "Load factor : " << coll.load_factor() << std::endl;
	std::cout << "Load factor : " << coll.max_load_factor() << std::endl;

}

void UnorderedMultimap() {
	std::unordered_map<std::string, std::string> coll;
	coll.insert(std::make_pair("Name", "Anderson"));
	coll.insert(std::make_pair("surname", "Chikuse"));
	coll.insert(std::pair<std::string, std::string>("Age", "28"));
	for (const auto& x : coll) {
		std::cout << "Bucket #:" << coll.bucket(x.first) << " -> " << x.first << ":" << x.second << std::endl;
	}
}
// for storing user defined type override comparion operator: <>==

class Employee {
	std::string m_Name;
	int m_Id;
public :
	Employee(const std::string& name, int id) : m_Name(name), m_Id(id) {}
	const std::string& GetName() const {
		return m_Name;
	}
	int GetId() const {
		return m_Id;
	}
};
// value object for Hashing and Comparator: they have to be created separately
struct EmployeeHash {
	size_t operator()(const Employee& emp) const  {
		auto s1 = std::hash<std::string>{}(emp.GetName());
		auto s2 = std::hash<int>{}(emp.GetId());
		return s1 ^ s2;
	}
};

struct EmployeeEquality {
	bool operator () (const Employee& e1, const Employee& e2) const {
		return e1.GetId() == e2.GetId();
	}
};

//
void HushFunctions() {
	std::hash<std::string> h;
	auto hellpHash = h("Hello");
	// hash of user defined types
	std::unordered_set<Employee, EmployeeHash, EmployeeEquality> coll;
	coll.insert(Employee("Anderson", 1));
	coll.insert(Employee("Chikuse", 2));
	coll.insert(Employee("Chikuse1", 3));
	coll.insert(Employee("Chikuse2", 4));
	for (const auto& emp : coll) {
		std::cout << emp.GetId() << ":" << emp.GetName() << std::endl;
	}
}