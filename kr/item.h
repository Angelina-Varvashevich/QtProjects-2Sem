#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include <QVector>
#include <QList>
#include <iostream>


class Item
{
public:
   /* Item(QString name_, int year_): name(name_), year(year_){};
    QString name;

    int year;
    virtual std::string Print() const =0;*/

    Item(const char * name_, int year_){
        year=year_;
        int size =strlen(name_);
        c_name= new char[size+1];
        for(int i=0; i<size; ++i) {
            c_name[i]=name_[i];
        }
        c_name[size]='\0';

    };
    char* c_name=nullptr;

    int year;
    virtual std::string Print() const =0;

};

std::ostream& operator<<(std::ostream& out, const Item & item){


    return out<< (&item)->Print();
}

class Coin: public Item
{
public:
    int GetYearOfWork();
    void SetYearOfWork(int year_of_work);
    Coin(QString name_, int year_, int yearOfWork_):Item(name_, year_){
        yearOfWork=yearOfWork_;
    }

    std::string Print()override{
        return name.toStdString()+" "+ QString::number(year).toStdString()+" "+ QString::number(yearOfWork).toStdString();

    }

private:
    int yearOfWork;

};

class Painting: public Item
{
public:
    int GetCodeOfAuthor();
    void SetCodeOfAuthor(int code);
    Painting(QString name_, int year_, int codeOfAuthor_):Item(name_, year_){
       codeOfAuthor=codeOfAuthor_ ;
    }
    std::string Print() override{
        return name.toStdString()+" "+ QString::number(year).toStdString()+" "+ QString::number(codeOfAuthor).toStdString();
    }
    int codeOfAuthor;

};

class Statuette: public Painting
{
public:
    int material;
    Statuette(QString name_, int year_, int codeOfAuthor_, int material_ ):Painting(name_, year_, codeOfAuthor_){
       material= material_;
    }

    std::string Print() override{
        return name.toStdString()+" "+ QString::number(year).toStdString()+" "+ QString::number(codeOfAuthor).toStdString()
                +" "+ QString::number(material).toStdString();
    }

};



class Museum{
public:

    Museum();
    QList<Item*> items;
};




#endif // ITEM_H
