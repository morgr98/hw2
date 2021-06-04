
#ifndef MAIN_CPP_EXAMDETAILS_H
#define MAIN_CPP_EXAMDETAILS_H
#include <string>
#include <ostream>
using std::string;

class examDetails {
private:
    int id_course;
    int month;
    int day;
    double hour;
    int length;
    std :: string link;
    bool operator==(const examDetails& exam);
    friend int getMonth(const examDetails& exam);

public:
    examDetails(int id_course, int month, int day, double hour, int length , std :: string link);
    examDetails(const examDetails& exam);
    examDetails& operator=(const examDetails& exam);
    ~examDetails();
    std::string getLink() const;
    void setLink(const std::string new_link);
    friend void operator<<(std::ostream& os ,const examDetails& exam);
    static examDetails makeMatamExam();

};

int operator-(const examDetails exam1,const examDetails exam2);
int operator<(const examDetails exam1,const examDetails exam2);



#endif //MAIN_CPP_EXAMDETAILS_H
