#pragma once
#include <string>

#include "Progress.h"

class Student
{
public:
	Student(const std::string& st_name);
	Student(const std::string& st_name, int age);
	Student(const std::string& st_name, int age, std::initializer_list<Progress> list);

	bool operator<(const Student& other) const;
	bool operator==(const Student& other) const;
	Student operator+(const Progress& pr);

	double CalcAverageMark() const;
	double CalcAverageMark(std::string subject_name) const;
	void AddProgress(const Progress& pr);

	bool CheckHonorStudent() const;
	bool CheckDebtorStudent() const;

	int Hash() const;
	friend std::ostream& operator<<(std::ostream& out, const Student& st);
private:
	std::string name_;
	size_t age_;
	std::vector<Progress> progress_;
};

class StudentHasher {
public:
	size_t operator()(const Student& st) const;
};

