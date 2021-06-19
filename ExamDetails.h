
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

        /**
        * operator==: a function that check if two exam are equal
         * @param exam- an exam to compare
         *
         * @return
         * true if the two exams are the same otherwise false
        */

        bool operator==(const ExamDetails &exam);

        /**
        * checkHour: a function that check if the hour is by the condition
         * @param hour- an hour of the test
         *
         * @return
         * the hour if the hour is good
         * @errors
         * InvalidTimeException- if the hour isnt stand with the condition
        */

        double checkHour(double hour);
        int checkNum(double num);
        int checkDate(double date);


    public:
        ExamDetails(double id_course, double month, double day, double hour, double length, std::string link = "");

        ExamDetails(const ExamDetails &exam)=default;

        ExamDetails &operator=(const ExamDetails &exam)=default;

        ~ExamDetails()=default;

        /**
        * getLink: a function that return the link of the zoom
        * @return link
        */

        std::string getLink() const;

        /**
        * setLink: a function that update the  link of the zoom
        */

        void setLink(const std::string new_link);

        /**
        * operator<<: a function that print the details of the exam
        */

        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &exam);

        /**
        * makeMatamExam: a function that create an exam by specific details
        */

        static ExamDetails makeMatamExam();

        /**
        * operator-: a function that calculate how much days are between two exams
         * @param
         * exam1, exam2- two exams to compare the day
         *
         * @return
         * the number of days between the first exam to the second exam
        */

        friend double operator-(const ExamDetails &exam1, const ExamDetails &exam2);

        /**
        * operator<: a function that check if the first exam occurred first than  the second exam
         * @param
         * exam1, exam2- two exams to compare the day
         *
         * @return
         * true if the first exam is first otherwise false
        */

        friend bool operator<(const ExamDetails &exam1, const ExamDetails &exam2);

        /**
        * InvalidTimeException<: an error that send when the time we get is invalid
        */

        class InvalidTimeException {
        };

        /**
        * InvalidArgsException<: an error that send when we get an wrong variable
        */

        class InvalidArgsException {
        };

        /**
        * InvalidDateException<: an error that send when the date we get is invalid
        */

        class InvalidDateException {
        };
    };

}
#endif //MAIN_CPP_EXAMDETAILS_H
