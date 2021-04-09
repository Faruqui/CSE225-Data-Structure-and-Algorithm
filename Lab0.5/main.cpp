#include <iostream>
#include "DateType.h"

using namespace std;

int main()
{
    DateType Today, AnotherDay;

    Today.Initialize(6,4,2018);
    AnotherDay.Initialize(6,5,2017);

    cout<< Today.compareTo(AnotherDay)<<"asaf";

    return 0;
}
