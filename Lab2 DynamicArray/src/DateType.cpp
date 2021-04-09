#include "DateType.h"
#include <iostream>

using namespace std;

/*
DateType::DateType()
{
    //ctor
}

DateType::~DateType()
{
    //dtor
}
*/

void DateType::Initialize(int m, int d, int y)\
{
    year = y;
    month = m;
    day = d;
}

int DateType::GetDay() const
{
    return year;
}
int DateType::GetMonth() const
{
    return month;
}
int DateType::GetYear() const
{
    return day;
}
void DateType::Print()
{
    cout<<"DD:MM:YYYY - "<<day<<" : "<<month<<" : "<<year;
}


RelationType DateType::compareTo(DateType a)
{
    if(year<a.year) return Less;
    else if(year > a.year) return Greater;
    else if(month < a.month) return Less;
    else if(month > a.month) return Greater;
    else if(day < a.day) return Less;
    else if(day > a.day) return Greater;
    else return Equal;
}
