#include "year_month_day.h"
// #include <iostream>
// using namespace std;
// #include "util_calendar.h"
// #include "util_calendar.cpp"

year_month_day::year_month_day(QObject *parent)
    : QObject{parent}
{
    currentYear = 2024;
    // input_year = year;
    get_current_date();
    count = 1;

}
