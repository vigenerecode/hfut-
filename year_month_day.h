#ifndef YEAR_MONTH_DAY_H
#define YEAR_MONTH_DAY_H
// #include <time.h>
#include <QObject>
#include <QDateTime>
#include "util_calendar.h"
class year_month_day : public QObject
{
    Q_OBJECT
public:
    explicit year_month_day(QObject *parent = nullptr);
    int input_year;
    int currentYear;
    int currentMonth;
    int currentDay;
    int months[12];
    int max_dayys[12];
    int count;
    year_month_day(int year)
    {
        this->input_year = year;
        // this->currentMonth=month;
        // this->currentDay=day;
    }
    ~year_month_day(){

    }
    void get_current_date(){
        // auto currentDate = std::chrono::system_clock::now();
        // auto date = std::chrono::floor<std::chrono::days>(currentDate);

        // // 将日期转换为 year_month_day
        // auto ymd = std::chrono::year_month_day(date);

        // auto time = std::chrono::system_clock::to_time_t(currentDate);
        // std::tm* tm = std::localtime(&time);

        // // 使用 std::chrono::year_month_day 获取年、月、日
        // auto ymd2 = std::chrono::year_month_day(std::chrono::year(tm->tm_year + 1900),
        //                                        std::chrono::month(tm->tm_mon + 1),
        //                                        std::chrono::day(tm->tm_mday));


        // this->currentYear = ymd.year();
        // this->currentMonth = ymd.month();
        // this->currentDay = ymd.day();

        // 获取当前日期时间
        QDateTime currentDateTime = QDateTime::currentDateTime();

        // 获取年、月、日
        int year = currentDateTime.date().year();
        int month = currentDateTime.date().month();
        int day = currentDateTime.date().day();

        this->currentYear = year;
        this->currentMonth = month;
        this->currentDay = day;

    }
    void initialymd(){
        if(judge_is_leap_year(this->input_year)){
            int totalDays = 366;
            for(int m=0;m<12;m++){

                this->max_dayys[m] = sumDays(this->input_year,m+1);

            }
        }else{
            int totalDays = 365;

            for(int m=0;m<12;m++){

                this->max_dayys[m] = sumDays(this->input_year,m+1);

            }
        }
    }


signals:
};

#endif // YEAR_MONTH_DAY_H
