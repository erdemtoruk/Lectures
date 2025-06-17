#include <vector>

#include "exam.hpp"

using namespace std;

class lecture{
    private:
        string name;
        float average;

        string day;
        float start_time;
        float end_time;

        vector<exam> exams;

        //Sets average of the lecture
        void calculate_average();
        
    public:
        lecture(string _name, string _day, float _start_time, float _end_time);

        //Returns the name of the lecture
        string get_name();

        //Returns the degree of the lecture
        string get_degree();

        //Returns the average of the lecture
        float get_average();

        //Returns the exam number of the lecture
        int get_exam_number();

        //Returns the exam of the lecture with name of the exam
        exam* get_exam(string name);

        //Returns the name of the lecture with index of exam
        exam* get_exam(int index);

        //Returns the day of the lecture
        string get_day();

        //Returns the start time of the lecture
        float get_start_time();

        //Returns the end time of the lecture
        float get_end_time();

        //Sets the name of the lecture
        void change_name(string new_name);

        //Sets the day of the lecture
        void change_day(string new_day);

        //Sets the start time of the lecture
        void change_start_time(float new_start_time);

        //Sets the end time of the lecture
        void change_end_time(float new_end_time);
        
        //Create exam and insert to the lecture
        int add_exam(string name, string date, float percentage, float score);

        //Delete exam from the lecture with name of the exam
        int delete_exam(string name);

        //Delete exam from the lecture with index of the exam
        int delete_exam(int index);     
};
