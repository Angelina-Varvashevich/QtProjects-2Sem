#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <istream>
#include <list>


class Student
{
public:
    Student() = default;
    Student(const std::string&, int);
    std::string get_name() const;
    int get_year_of_study() const;
    std::string to_string() const;

private:
    std::string name;
    int year_of_study;
};

std::istream& operator>>(std::istream&, Student&);

void readFromFile(std::list<Student>&, const std::string&);


#endif // STUDENT_H
