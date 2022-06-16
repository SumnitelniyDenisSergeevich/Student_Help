#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <initializer_list>

class Progress
{
public:
	Progress(std::string subject_name);
	Progress(std::string subject_name, std::initializer_list<int> list);
	void AddGrade(int grade);
	double CalcAverageMark() const;
	std::string GetName() const;
	friend std::ostream& operator<<(std::ostream& out, const Progress& pr);
private:
	std::string subject_name_;
	std::vector<size_t> grades_;
};
