#include <iostream>
#include <set>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>

enum Day {
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

enum Month {
  January,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

class Date {
    /* This class implements creation and manipulation of dates in the Gregorian Calendar.
     */
    private:
        int year_;
        Month month_;
        int day_;

        void setDate(int year, int month, int day);
        std::string dateSuffix() const;
        std::string getMonthName() const;

    public:
        Date(int year, int month, int day);
        Date(std::string DateInput);
        
        friend std::ostream& operator<<(std::ostream& os, const Date& dt);

        int getDate();
        Month getMonth();
        int getYear();
        std::string getDayName() const;
        Day getDay() const;
        int toDayNumber();
        Date fromDayNumber(int day_number);
        Date addDays(int n);

        bool isLeapYear(int year);

        int daysInMonth(int year, int month);

};