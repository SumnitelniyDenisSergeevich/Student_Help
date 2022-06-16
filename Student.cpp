#include "Student.h"

Student::Student(const std::string& st_name) : name_(st_name), age_(18) {
}

Student::Student(const std::string& st_name, int age) : name_(st_name), age_(age) {
}

Student::Student(const std::string& st_name, int age, std::initializer_list<Progress> list) : name_(st_name), age_(age) {
	for (auto it = list.begin(); it != list.end(); ++it) {
		AddProgress(*it);
	}
}

bool Student::operator<(const Student& other) const {
	return true;
}

bool Student::operator==(const Student& other) const {
	return true;
}

Student Student::operator+(const Progress& pr) {
	this->progress_.push_back(pr);
	return *this;
}

double Student::CalcAverageMark() const {
	double result = 0.;
	for (const Progress& pr : progress_) {
		result += pr.CalcAverageMark();
	}
	return result/(progress_.size()*1.);
}

double Student::CalcAverageMark(std::string subject_name) const {
	double result = 0.;

	for (const Progress& pr : progress_) {
		if (pr.GetName() == subject_name) {
			result += pr.CalcAverageMark();
		}
	}
	return result ;
}

void Student::AddProgress(const Progress& pr) {
	progress_.push_back(pr);
}

bool Student::CheckHonorStudent() const {
	for (const Progress& pr : progress_) {
		if (static_cast<size_t>(std::round(pr.CalcAverageMark())) != 5) {
			return false;
		}
	}
	return true;
}

bool Student::CheckDebtorStudent() const {
	for (const Progress& pr : progress_) {
		if (static_cast<size_t>(std::round(pr.CalcAverageMark())) == 2) {
			return true;
		}
	}
	return false;
}

int Student::Hash() const {
	return std::hash<std::string>{}(name_) + std::hash<size_t>{}(age_);
}

size_t StudentHasher::operator()(const Student& st) const {
	return static_cast<size_t>(st.Hash());
}

std::ostream& operator<<(std::ostream& out, const Student& st) {
	out << st.name_ << " " << st.age_ << ':' << "\n";
	for (Progress grade : st.progress_) {
		out << grade;
	}
	out << std::endl;
	return out;
}