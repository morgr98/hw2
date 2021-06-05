#include <iostream>
#include "ExamDetails.h"
using std::cout;
using std::endl;
using std::string;
//using namespace mtm;
#define TEST(num) cout << endl << "TEST " << (num) << endl;

int main() {
    TEST("1.1")
    ExamDetails exam1 = ExamDetails::makeMatamExam();
    ExamDetails exam2(104032, 7, 11, 9.5, 3);
    ExamDetails exam3 = exam1;
    cout << "the difference between MATAM and infi 2m is " << (exam1-exam2) << " days";

    TEST("1.2")
    ExamDetails& closest = (exam1 < exam2) ? exam1 : exam2;
    cout << "your closest exam is:" << endl << closest << endl;

    TEST("1.3")
    closest.setLink("https://tinyurl.com/ym8wf46t");
    cout << closest << endl;

    TEST("1.4")
    try {
        ExamDetails exam4(236506, 42, 0, 13, 3, "https://tinyurl.com/ym8wf46t");
        cout << exam4 << endl;
    }
    catch (ExamDetails::InvalidDateException& e) {
        cout << "invalid date" << endl;
    }
}
