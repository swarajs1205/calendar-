#include "/Users/swaraj/Documents/Coding/date.h"
#include <ctime>

void Date::setDate(int year, int month, int day) {
    // Validate range
    // TODO: Include Leap Years and 29th Feb, 31st June etc as invalid dates.
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::out_of_range("Date components out of valid range");
    }
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        if (month == 2 && day > 29) {
            throw std::out_of_range("Date components out of valid range");
        }
    }
    else if (month == 2 && day > 28) {
        throw std::out_of_range("Date components out of valid range");
    }
    
    if (month == 4 || month == 6  || month == 9 || month == 11 ) {
        if (day > 30) {
            throw std::out_of_range("Date components out of valid range");
        }
    }
    day_ = day;
    month_ = static_cast<Month>(month - 1);
    year_ = year;
};

Date::Date(int year, int month, int day) {
    setDate(year, month, day);
}

Date::Date(std::string DateInput) {
    // Expected format: "DD/MM/YYYY"
    int day, month, year;
    char sep1, sep2;
    std::istringstream iss(DateInput);
    
    if (!(iss >> day >> sep1 >> month >> sep2 >> year) || sep1 != '/' || sep2 != '/') {
        throw std::invalid_argument("Invalid date format. Use DD/MM/YYYY");
    }

    setDate(year, month, day);
}

std::string Date::dateSuffix() const {
        if (day_ % 10 == 1) {
            return "st";
        }
        else if (day_ % 10 == 2) {
            return "nd";
        }
        else if (day_ % 10 == 3) {
            return "rd";
        }
        else {
            return "th";
        }
    }

std::string Date::getMonthName() const {
    std::string monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[static_cast<int>(month_)];
}


int Date::getDate() {
    return day_;
}

Month Date::getMonth() {
    // TODO: Change this to Strings eg. January etc
    return month_;
}

int Date::getYear() {
    return year_;
}

Day Date::getDay() const {
    // Get the Day of the week given a date.
    std::tm timeinfo = {};
    timeinfo.tm_year = year_ - 1900;
    timeinfo.tm_mon = static_cast<int>(month_);
    timeinfo.tm_mday = day_;

    std::mktime(&timeinfo);  // Normalize

    int wday = timeinfo.tm_wday;  // 0 = Sunday ... 6 = Saturday

    // Adjust tm_wday (Sunday=0) to Day enum (Monday=0)
    if (wday == 0) return Sunday;
    return static_cast<Day>(wday - 1);
}

std::string Date::getDayName() const {
    std::string day_names[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" 
    };
    return day_names[static_cast<int>(getDay())];
}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int year, int month) {
    static const int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

int Date::toDayNumber() {
    int y = year_, m = static_cast<int>(month_) + 1, d = day_;
    int days = 0;

    // Count full years
    // This is Linear. O(N). Change this to Constant Time. O(1)
    for (int year = 2000; year < y; ++year)
        days += isLeapYear(year) ? 366 : 365;
    for (int year = y; year < 2000; ++year)
        days -= isLeapYear(year) ? 366 : 365;

    // Count full months
    int start_month = (y >= 2000) ? 1 : 12;
    int end_month   = (y >= 2000) ? m : m + 1;
    int dir         = (y >= 2000) ? 1 : -1;

    for (int month = start_month; month != end_month; month += dir) {
        days += dir * daysInMonth(y, month);
    }

    // Add days
    days += (y >= 2000) ? d - 1 : -(daysInMonth(y, m) - d + 1);

    return days;
}

Date Date::fromDayNumber(int day_number) {
    int y = 2000;

    // Forward
    while (day_number >= (isLeapYear(y) ? 366 : 365)) {
        day_number -= isLeapYear(y) ? 366 : 365;
        ++y;
    }

    // Backward
    while (day_number < 0) {
        --y;
        day_number += isLeapYear(y) ? 366 : 365;
    }

    int m = 1;
    while (true) {
        int dim = daysInMonth(y, m);
        if (day_number < dim) break;
        day_number -= dim;
        ++m;
    }

    int d = day_number + 1;
    return Date(y, m, d);
}

Date Date::addDays(int n) {
    int current_day = toDayNumber();
    return fromDayNumber(current_day + n);
}

std::ostream& operator<<(std::ostream& os, const Date& dt) {
    // TODO: Make this readable like 26th July 2025, Monday.
    os << dt.day_ << dt.dateSuffix() << " " << dt.getMonthName() << " " << dt.year_ << ", " << dt.getDayName() << std::endl;
    return os;
};
