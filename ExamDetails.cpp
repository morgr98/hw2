#include "ExamDetails.h"
#include <string>
#include <ostream>
using std::string;
using std::endl;

namespace mtm {

    ExamDetails::ExamDetails(int id_course, int month, int day, double hour, int length, std::string link) {
        if (month < 0 || month > 12 || day < 0 || day > 30) {
            throw ExamDetails::InvalidDateException();
        }
        this->id_course = id_course;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->length = length;
        this->link.operator=(link);
    }

    ExamDetails::ExamDetails(const ExamDetails &exam) {
        this->id_course = exam.id_course;
        this->month = exam.month;
        this->day = exam.day;
        this->hour = exam.hour;
        this->length = exam.length;
        this->link.operator=(exam.link);
    }

    ExamDetails &ExamDetails::operator=(const ExamDetails &exam) {
        if (this == &exam) {
            return *this;
        }
        this->id_course = exam.id_course;
        this->month = exam.month;
        this->day = exam.day;
        this->hour = exam.hour;
        this->length = exam.length;
        this->link.operator=(exam.link);
        return *this;
    }

    ExamDetails::~ExamDetails() {
        this->link.clear();
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
        ExamDetails exam(234124, 7, 28, 13, 3, "59hzps6m/com.tinyurl://https.");
        return exam;
    }


    int operator-(const ExamDetails &exam1, const ExamDetails &exam2) {
        int month_sub = exam1.month - exam2.month;
        int day_sub = exam1.day - exam2.day;
        return month_sub * 30 + day_sub;
    }

    int operator<(const ExamDetails exam1, const ExamDetails exam2) {
        if ((exam2 - exam1) > 0)
            return true;
        return false;
    }

    std::ostream &operator<<(std::ostream &os, const ExamDetails &exam) {
        int minute = exam.hour * 10;
        string minutes;
        if (minute % 2 == 0) {
            minutes = ":00";
            minute = int(exam.hour);
        } else {
            minutes = ":30";
            minute = int(exam.hour - 0.5);
        }
        return os << "Course Number: " << exam.id_course << endl <<
                  "Time: " << exam.day << "." << exam.month << "at" << minute << minutes << endl <<
                  "Duration: " << exam.length << ":00" << endl <<
                  "Zoom Link:" << exam.link;
    }


}