#include <cmath>
#include "Group.h"
Group::Group() : group_id_(0) {
}

Group::Group(int group_id) : group_id_(group_id) {
}

Group::Group(int group_id, std::initializer_list<Student> list) : group_id_(group_id) {
	for (auto it = list.begin(); it != list.end(); ++it) {
		AddStudent(*it);
	}
}

Group Group::operator+(const Student& pr) {
	this->students_.insert(pr);
	return *this;
}

size_t Group::CalcAverageMark() const{
	std::cout << "Средняя оценка по группе по всем предметам : ";
	double result = 0.;
	for (const Student& st : students_) {
		result += st.CalcAverageMark();
	}
	return static_cast<size_t>(std::round(result)/students_.size());
}

size_t Group::CalcAverageMark(std::string subject_name) const {
	std::cout << "Средняя оценка по группе по " << subject_name << " :";
	double result = 0.;
	for (const Student& st : students_) {
		result += st.CalcAverageMark(subject_name);
	}
	return static_cast<size_t>(std::round(result) / students_.size());
}

void Group::PrintHonorStudents() const {
	std::cout << "Отличники: " << std::endl;
	for (const Student& st : students_) {
		if (st.CheckHonorStudent()) {
			std::cout << st << std::endl;
		}
	}
}

void Group::PrintDebtorStudents() const {
	std::cout << "Задолженники: " << std::endl;
	for (const Student& st : students_) {
		if (st.CheckDebtorStudent()) {
			std::cout << st << std::endl;
		}
	}
}

void Group::AddStudent(const Student& st) {
	students_.insert(st);
}

std::ostream& operator<<(std::ostream& out, const Group& gr) {
	std::cout << "Группа " << gr.group_id_ << " :" << std::endl;
	for (const Student& st : gr.students_) {
		std::cout << st << std::endl;
	}
	return out;
}