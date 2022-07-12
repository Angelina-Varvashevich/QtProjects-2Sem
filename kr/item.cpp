#include "item.h"



int Coin::GetYearOfWork()
{
    return yearOfWork;
}

void Coin::SetYearOfWork(int year_of_work)
{
    yearOfWork=year_of_work;
}

int Painting::GetCodeOfAuthor()
{
    return codeOfAuthor;
}

void Painting::SetCodeOfAuthor(int code)
{
    codeOfAuthor=code;
}

Museum::Museum()
{
    Item *coin = new Coin("coin", 1105, 2000);
    items.push_back(coin);
    Painting *paint= new Painting("paint", 2002, 11111);
    items.push_back(paint);
    Statuette* statuette= new Statuette("stat", 1067, 202020, 11111);
    items.push_back(statuette);

}
