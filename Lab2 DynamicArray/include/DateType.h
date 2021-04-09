#ifndef DATETYPE_H_INCLUDED
#define DATETYPE_H_INCLUDED

enum RelationType {Less, Equal, Greater};

class DateType
{
    public:
        //DateType();
        //~DateType();
        void Initialize (int newMonth, int newDay, int newYear);
        int GetYear() const;    //Returns year
        int GetMonth() const;  // Returns  month
        int GetDay() const;  // Returns day
        RelationType compareTo(DateType);
        void Print();

    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATETYPE_H_INCLUDED
