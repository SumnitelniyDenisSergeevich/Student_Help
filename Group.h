#pragma once
#include <unordered_set>
#include "Student.h"
class Group
{
public:
	Group();
	Group(int group_id);
	Group(int group_id, std::initializer_list<Student> list);

	Group operator+(const Student& st);

	size_t CalcAverageMark() const;
	size_t CalcAverageMark(std::string subject_name) const;
	void PrintHonorStudents() const;
	void PrintDebtorStudents() const;
	void AddStudent(const Student& st);
	friend std::ostream& operator<<(std::ostream& out, const Group& gr);
private:
	size_t group_id_;
	std::unordered_set<Student, StudentHasher> students_;
};

