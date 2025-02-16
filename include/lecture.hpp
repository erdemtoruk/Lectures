#include <vector>

#include "exam.hpp"

using namespace std;

class lecture{
    private:
        string name;
        float average;
        float degree;

        string day;
        float start_time;
        float end_time;

        vector<exam> exams;

    public:
        lecture(string _name, string _day, float _start_time, float _end_time, float _average, float _degree);

        string get_name();
        string get_degree();
        float get_average();

        int get_exam_number();
        exam get_exam(int index);

        string get_day();
        float get_start_time();
        float get_end_time();
        int get_lecture_duration();

        void change_name(string new_name);
        void change_day(string new_day);
        void change_start_time(float new_start_time);
        void change_end_time(float new_end_time);
        
        int add_exam(string name, string date, float percentage, float score);

        int delete_exam(string name);
        int delete_exam(int index);

        void calculate_average();     
};
