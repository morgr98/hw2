
#ifndef MAIN_CPP_EXAMDETAILS_H
#define MAIN_CPP_EXAMDETAILS_H
#include <string>
#include <ostream>
using std::string;
namespace mtm {
    class ExamDetails {
    private:
        double id_course;
        double month;
        double day;
        double hour;
        double length;
        std::string link;
        static constexpr const char* LINK_MTM="https://tinyurl.com/59hzps6m";
        static constexpr const char* HOUR=":00";
        static constexpr const char* HALF_HOUR=":30";
        static const int DAY_MAX=30;
        static const int MONTH_MAX=12;
        static const int LIMIT_DAY=0;
        static const int MAX_HOUR=23;
        static constexpr double HALF=0.5;
        bool operator==(const ExamDetails &exam);
        void checkHour(double hour);
        void checkNum(double num);
        void checkDate(double date);


    public:
        ExamDetails(double id_course, double month, double day, double hour, double length, std::string link = "");

        ExamDetails(const ExamDetails &exam)=default;

        ExamDetails &operator=(const ExamDetails &exam)=default;

        ~ExamDetails()=default;

        std::string getLink() const;

        void setLink(const std::string new_link);

        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &exam);

        static ExamDetails makeMatamExam();

        friend double operator-(const ExamDetails &exam1, const ExamDetails &exam2);

        friend int operator<(const ExamDetails &exam1, const ExamDetails &exam2);

        class InvalidTimeException {
        };

        class InvalidArgsException {
        };

        class InvalidDateException {
        };
    };

}
#endif //MAIN_CPP_EXAMDETAILS_H
