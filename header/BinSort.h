#pragma once
#include <string>
#include <iostream>
// sutdentRecord
struct studentRecord 
{
	int score;
	std::string* name;

	int operator !=(const studentRecord& x) const {
		return (score != x.score);
	}
	// TYPE CONVERSION FUNCTION:
	// convert the type from "studentRecord" to "int",
	// so +, -, !=, etc. is all available
	operator int() const {
		return score;
	}

};
std::ostream& operator<<(std::ostream out, const studentRecord& x) {
	out << x.score << ' ' << *x.name << std::endl;
	return out;
}
class BinSort
{
private:
	studentRecord stu;
public:
	void binSort(chain)
};

