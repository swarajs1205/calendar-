#include "/Users/swaraj/Documents/Coding/helpers.h"

bool isWeeklyRestricted(Date date) {
    const int day = date.getDay();
    if ((day == Tuesday) || (day == Thursday) || (day == Saturday)) {
        return true;
    }

    return false;
}

bool isRestrictedMonth(Date date) {
   int month = date.getMonth();
   if (month == 7 || month == 10) {
    return true;
   }
    return false;
}

void test_month_restriction(std::string test_string, bool expected_output) {
    Date userinput(test_string);
    bool x = isRestrictedMonth(userinput);
    assert(x == expected_output);

}

void test_week_restriction(std::string test_String, bool expected_Output) {
    Date userinput(test_String);
    bool y = isWeeklyRestricted(userinput);
    assert(y == expected_Output);

}

int main() {
    // Date date("22/6/2025");
    // std::cout << "Date: " << date;

    std::string user_input;
    std::cout << "Please enter a date in DD/MM/YYYY format: ";
    // std::cin  >> user_input;
    // Date date(user_input);
    
    // std::cout << "Your date is: " << date;

    //test case 1; test months;
    test_month_restriction("22/08/2026", true);
    
    //test case 2; test months;
    test_month_restriction("22/11/2026", true);
    
    //test case 3; test months;
    test_month_restriction("22/07/2026", false);

    //test case 1; test week;
    test_week_restriction("01/01/2026", true);
 
     //test case 2; test week;
    test_week_restriction("02/01/2026", false);

     //test case 3; test week;
    test_week_restriction("03/01/2026", true);

    Date d1("30/06/2025");
    Date result1 = d1.addDays(2);
    std::cout << result1 << std::endl;
    assert(result1.getDate() == 2);
    assert(result1.getMonth() == July);
    assert(result1.getYear() == 2025);

    Date d2("01/01/2000");
    Date result2 = d2.addDays(-7);
    assert(result2.getDate() == 25);
    assert(result2.getMonth() == December);
    assert(result2.getYear() == 1999);

    Date d3("28/02/2025");
    Date result3 = d3.addDays(1);
    assert(result3.getDate() == 1);
    assert(result3.getMonth() == March);
    assert(result3.getYear() == 2025);

    std::cout << "yayyyy hullaa" << std::endl;
    return 0;
}

  

    // HW

    // 1. Write Unit Test for Weekly Restricted

    // 2. Make a public member function of class Date to output Month NAME, rather than enum

    // 3. Re-write the friend function overriding the cout << operator to output date in "22/06/2025 (Monday)" format

    // 4. In the string constructor of class Date, setDate() is called. Implement the TODO in that function.

    // 5. Implement a method to add/subtract an integer amount of days. eg. June 30, 2025 + 2 days = July 2, 2025. Also handle subtract!
    // Hint: Convert any date into an integer, and handle conversion back. Eg. Starting 2000, 25th Jan 2000 is Day 25. 25th Dec 1999 is Day -7.
    // Write Unit test. Use Google to check.

    // 5 (a) rename helpers.cpp and helpers.h to GregorianFasts.cpp

    // 6. Write new files for Vikram Samvat, eg. Tithi.cpp Tithi.h

    /*
        Instead of Months Jan, Feb -> Chait, Bhado etc etc - Handle Adhik Maas
        Instead of Date 1, 2, 3, 4. create enums for Ekadashi etc
        Handle Shukla Paksh, Krishna Paksh.
    */
