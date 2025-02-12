#include <string>
#include <iostream>

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

        int num_exams;
        exam exams[];

    public:
        lecture(string _name, string _day, float _start_time, float _end_time, float _average = 0, float _degree = 0);

        string get_name();
        string get_degree();

        string get_day();
        float get_start_time();
        float get_end_time();
        int get_lecture_duration();

        void change_name(string new_name);
        void change_day(string new_day);
        void change_start_time(float new_start_time);
        void change_end_time(float new_end_time);
        
        void calculate_average();

        
        //int save_file();
};
