#include "student.h"

#include <fstream>

Student::Student(const std::string& n, int y)
    : name(n), year_of_study(y)
{

}
std::string Student::get_name() const
{
    return name;
}

int Student::get_year_of_study() const
{
    return year_of_study;
}

std::string Student::to_string() const
{
    return name + " - " + std::to_string(year_of_study);
}

std::istream& operator>>(std::istream& in, Student& stud)
{
    std::string n;
    int y;
    in >> n >> y;
    stud = Student(n, y);
    return in;
}

void readFromFile(std::list<Student>& studList, const std::string& fileName)
{
    std::ifstream fin(fileName);
    Student tmp;
    while(fin >> tmp)
    {
        studList.push_back(tmp);
    }
}




