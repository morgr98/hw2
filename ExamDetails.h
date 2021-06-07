
#ifndef MAIN_CPP_EXAMDETAILS_H
#define MAIN_CPP_EXAMDETAILS_H
#include <string>
#include <ostream>
using std::string;
namespace mtm {
    class ExamDetails {
    private:
        int id_course;
        int month;
        int day;
        double hour;
        int length;
        std::string link;

        bool operator==(const ExamDetails &exam);

    public:
        ExamDetails(int id_course, int month, int day, double hour, int length, std::string link = " ");

        ExamDetails(const ExamDetails &exam);

        ExamDetails &operator=(const ExamDetails &exam);

        ~ExamDetails();

        std::string getLink() const;

        void setLink(const std::string new_link);

        friend std::ostream &operator<<(std::ostream &os, const ExamDetails &exam);

        static ExamDetails makeMatamExam();

        friend int operator-(const ExamDetails &exam1, const ExamDetails &exam2);

        friend int operator<(const ExamDetails& exam1, const ExamDetails& exam2);

        class InvalidTimeException {
        };

        class InvalidArgsException {
        };

        class InvalidDateException {
        };
    };


#endif //MAIN_CPP_EXAMDETAILS_H
}