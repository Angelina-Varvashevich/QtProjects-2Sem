#include "student.h"
#include <sstream>
#include <string>

Student::Student()
{
}

Student::Student(QString spec_, int group_, QString Surname_, QVector<double> marks_):
    specialization(spec_), groupNumber(group_), Surname(Surname_), marks(std::move(marks_)){
}

QString Student::GetSpecialization()
{
    return specialization;
}

int Student::GetGroupNumber()
{
    return groupNumber;
}

QString Student::GetSurname()
{
    return Surname;
}

QVector<double> Student::GetMarks()
{
    return marks;
}

double Student::GetMark(int index)
{
    return marks[index];
}

double Student::CalculateAverageMark()
{
    double sum=0;
    for (int i=0; i<marks.size(); ++i ){
        sum+=marks[i];
    }
    averageMark= sum/marks.size();
    return averageMark;

}

Student Student::ParseString( const std::string& studentString)
{
    std::stringstream str;
    str<< studentString;// ввод строки в поток
    std::string spec;
    str>>spec;// чтение по слову из строки
    specialization= QString::fromUtf8(spec.data(), int(spec.size()));
    std::string number;
    str>> number;
    groupNumber= /*std::stoi(number)*/std::atoi(number.c_str());
    std::string surnm;
    str>> surnm;
    Surname= QString::fromUtf8(surnm.data(), int(surnm.size()));
    std::string mrk;
    for(int i=0; i<4; i++){
        str>>mrk;
        marks.push_back((double) /*std::stoi(mrk)*/ std::atoi(mrk.c_str()));
    }
    return Student(specialization,groupNumber, Surname, marks);
}




