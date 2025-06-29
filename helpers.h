#include <iostream>
#include <set>
#include <ctime>
#include <iomanip>
#include <cassert>

#include "/Users/swaraj/Documents/Coding/date.h"

// Returns true if the day is Tuesday, Thursday or Saturday
bool isWeeklyRestricted(int wday);

// Check if date is in Saavan or Kartik (approx = August, November)
bool isRestrictedMonth(int month);
