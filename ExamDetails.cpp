#include "ExamDetails.h"
#include <string>
#include <ostream>
#include <cmath>
using std::string;
using std::endl;
using std::modf;

namespace mtm {

    ExamDetails::ExamDetails(double id_course, double month, double day, double hour, double length, std::string link):
    link(link){
        if (month <= LIMIT_DAY || month > MONTH_MAX || day <= LIMIT_DAY || day > DAY_MAX) {
            throw ExamDetails::InvalidDateException();
        }
        checkHour(hour);
        checkDate(month);
        checkNum(length);
        checkDate(day);
        checkNum(id_course);
        if(id_course<=0 || length<=0)
        {
            throw ExamDetails::InvalidArgsException();
        }
        this->id_course = id_course;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->length = length;
    }

    void ExamDetails::checkNum(double num)  {
        double p;
        if(modf(num,&p)< pow(10,-6))
        {
            return;
        }
        throw ExamDetails::InvalidArgsException();
    }


    void ExamDetails::checkDate(double date)  {
        double p;
        if(modf(date,&p)< pow(10,-6))
        {
            return;
        }
        throw ExamDetails::InvalidDateException();
    }


    void ExamDetails::checkHour(double hour) {
        if(hour<0 || hour > MAX_HOUR)
        {
            throw ExamDetails::InvalidTimeException();
        }
        double check_hour= hour-(int)hour;
        if(check_hour==0 || check_hour == HALF) {
            return;
        }
        throw ExamDetails::InvalidTimeException();
    }

    bool ExamDetails::operator==(const ExamDetails &exam) {
        if (length != exam.length) {
            return false;
        }
        if (hour != exam.hour) {
            return false;
        }
        if (month != exam.month) {
            return false;
        }
        if (id_course != exam.id_course) {
            return false;
        }
        if (day != exam.day) {
            return false;
        }
        if (link == exam.link) {
            return true;
        }
        return false;
    }

    std::string ExamDetails::getLink() const {
        return link;
    }

    void ExamDetails::setLink(const std::string new_link) {
        link.clear();
        link.operator=(new_link);
    }

    ExamDetails ExamDetails::makeMatamExam() {
        ExamDetails exam(234124, 7, 28, 13, 3, LINK_MTM);
        return exam;
    }


    double operator-(const ExamDetails &exam1, const ExamDetails &exam2) {
        double month_sub = exam1.month - exam2.month;
        double day_sub = exam1.day - exam2.day;
        return month_sub * 30 + day_sub;
    }

    int operator<(const ExamDetails& exam1, const ExamDetails& exam2) {
        if((exam2- exam1)==0)
        {
            if(exam1.hour<exam2.hour)
            {
                return true;
            } else{
                return false;
            }
        }
        if ((exam2 - exam1) > 0)
            return true;
        return false;
    }

    std::ostream &operator<<(std::ostream &os, const ExamDetails &exam) {
        int minute = exam.hour * 10;
        string minutes;
        if (minute % 2 == 0) {
            minutes =ExamDetails::HOUR ;
            minute = int(exam.hour);
        } else {
            minutes =ExamDetails::HALF_HOUR;
            minute = int(exam.hour - ExamDetails::HALF);
        }
        return os << "Course Number: " << exam.id_course << endl <<
                  "Time: " << exam.day << "." << exam.month << " at " << minute << minutes << endl <<
                  "Duration: " << exam.length << ":00" << endl <<
                  "Zoom Link: " << exam.link<<endl;
    }


}