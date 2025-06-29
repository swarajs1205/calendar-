#include <iostream>
#include <set>
#include <ctime>
#include <iomanip>

#include "/Users/swaraj/Documents/Coding/helpers.cpp"

using namespace std;

// Check fixed major Hindu festivals in 2026 (Gregorian calendar)
bool isFestival(int month, int day) {
    set<pair<int, int>> festivals = {
        {3, 3},   // Maha Shivratri
        {3, 14},  // Holi
        {4, 5},   // Ram Navami
        {4, 17},  // Hanuman Jayanti
        {8, 15},  // Raksha Bandhan
        {8, 26},  // Janmashtami
        {10, 20}, // Dussehra
        {11, 8},  // Diwali
        {11, 9},  // Govardhan Puja
        {11, 10}  // Bhai Dooj
    };
    return festivals.count({month, day}) > 0;
}

// Poornima dates in 2026 (Full moon days)
set<string> getPoornimaDates() {
    return {
        "2026-01-13", "2026-02-12", "2026-03-13", "2026-04-12", "2026-05-11", "2026-06-10",
        "2026-07-09", "2026-08-08", "2026-09-06", "2026-10-06", "2026-11-04", "2026-12-04"
    };
}

// Ekadashi dates in 2026
set<string> getEkadashiDates() {
    return {
        "2026-01-07", "2026-01-21", "2026-02-05", "2026-02-19",
        "2026-03-06", "2026-03-20", "2026-04-04", "2026-04-18",
        "2026-05-04", "2026-05-18", "2026-06-02", "2026-06-17",
        "2026-07-02", "2026-07-16", "2026-07-31", "2026-08-14",
        "2026-08-28", "2026-09-12", "2026-09-26", "2026-10-11",
        "2026-10-25", "2026-11-09", "2026-11-23", "2026-12-08"
    };
}

int main() {
    set<string> restrictedDays;
    set<string> poornimas = getPoornimaDates();
    set<string> ekadashis = getEkadashiDates();

    for (int month = 1; month <= 12; ++month) {
        for (int day = 1; day <= 31; ++day) {
            struct tm timeinfo = {};
            timeinfo.tm_year = 2026 - 1900;
            timeinfo.tm_mon = month - 1;
            timeinfo.tm_mday = day;

            // Normalize date
            if (mktime(&timeinfo) == -1 || timeinfo.tm_mon != month - 1)
                continue; // Invalid date

            string formatted = formatDate(timeinfo);
            int wday = timeinfo.tm_wday; // 0=Sun, 1=Mon, ..., 6=Sat

            // Check all restrictions
            bool restrict = false;
            if (isWeeklyRestricted(wday)) restrict = true;
            if (isRestrictedMonth(month)) restrict = true;
            if (isFestival(month, day)) restrict = true;
            if (poornimas.count(formatted)) restrict = true;
            if (ekadashis.count(formatted)) restrict = true;

            if (restrict) {
                restrictedDays.insert(formatted);
            }
        }
    }
    void suffix(){
        int 
    }
    int totalDays = 365; // Not a leap year
    int nonVegDays = totalDays - restrictedDays.size();

    cout << "👉 Non-veg eating days in 2026: " << nonVegDays << endl;
    cout << "❌ Restricted days: " << restrictedDays.size() << endl;

    return 0;
}
