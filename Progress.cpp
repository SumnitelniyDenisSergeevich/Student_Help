#include "Progress.h"
#include <stdexcept>

Progress::Progress(std::string subject_name) : subject_name_(subject_name) {
}

Progress::Progress(std::string subject_name, std::initializer_list<int> list) : subject_name_(subject_name) {
	for (auto it = list.begin(); it != list.end(); ++it) {
		AddGrade(*it);
	}
}

double Progress::CalcAverageMark() const {
	double result = 0.;
	for (const size_t mark: grades_) {
		result += mark;
	}
	return result/(grades_.size()*1.);
}

void Progress::AddGrade(int grade) {
	if (grade > 5 || grade < 1) {
		throw std::invalid_argument("invalid value of grade");
	}
	grades_.push_back(static_cast<size_t>(grade));
}

std::string Progress::GetName() const {
	return subject_name_;
}

std::ostream& operator<<(std::ostream& out, const Progress& progress) {
	out << progress.subject_name_ << "\n\t";
	for (size_t grade : progress.grades_) {
		out << grade << " ";
	}
	out << std::endl;
	return out;
}
