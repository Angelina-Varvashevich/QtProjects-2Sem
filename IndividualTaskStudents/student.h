#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include <string>
#include <QVector>


class Student
{
public:
    Student();
    Student(QString spec_, int group_, QString Surname_, QVector<double> marks_);
    QString GetSpecialization();
    int GetGroupNumber();
    QString GetSurname();
    QVector<double> GetMarks();
    double GetMark(int index);
    double CalculateAverageMark();
    Student ParseString( const std::string& studentString);
private:
    QString specialization;
    int groupNumber;
    QString Surname;
    QVector<double> marks;
    double averageMark=0;
};


#endif // STUDENT_H
