#include "examDetails.h"
#include <string>
#include <ostream>
using std::string;

examDetails::examDetails(int id_course, int month, int day, double hour, int length , std :: string link){
    this->id_course=id_course;
    this->month=month;
    this->day=day;
    this->hour=hour;
    this->length=length;
    this->link.operator=(link);
}

examDetails::examDetails(const examDetails& exam)
{
    this->id_course=exam.id_course;
    this->month=exam.month;
    this->day=exam.day;
    this->hour=exam.hour;
    this->length=exam.length;
    this->link.operator=(exam.link);
}

examDetails& examDetails::operator=(const examDetails &exam) {
    if(this == &exam)
    {
        return *this;
    }
    this->id_course=exam.id_course;
    this->month=exam.month;
    this->day=exam.day;
    this->hour=exam.hour;
    this->length=exam.length;
    this->link.operator=(exam.link);
    return *this;
}

examDetails::~examDetails() {
    this->link.clear();
}

bool examDetails::operator==(const examDetails &exam) {
    if(length != exam.length)
    {
        return false;
    }
    if(hour != exam.hour)
    {
        return false;
    }
    if(month != exam.month)
    {
        return false;
    }
    if(id_course != exam.id_course)
    {
        return false;
    }
    if(day != exam.day)
    {
        return false;
    }
    if(link== exam.link)
    {
        return true;
    }
    return false;
}

std::string examDetails::getLink() const {
    return link;
}

void examDetails::setLink(const std::string new_link) {
    link.clear();
    link.operator=(new_link);
}

examDetails examDetails::makeMatamExam() {
examDetails exam(234124,7,28,13,3,"59hzps6m/com.tinyurl://https.");
    return exam;
}

int operator-(const examDetails exam1,const examDetails exam2)
{

}


int operator<(const examDetails exam1,const examDetails exam2){


}




