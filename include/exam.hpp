#include <string>
#include <iostream>

using namespace std;

class exam{
    private:
        string name;
        string date;
        float percentage;
        float score;

    public:
        exam(string _name, string _date, float _percentage, float _score);

        //Returns the name of the exam
        string get_name();

        //Returns the date of the exam 
        string get_date();

        //Returns the percentage of the exam
        float get_percentage();

        // Returns the score of the exam
        float get_score();

        //Sets the name of the exam
        void change_name(string new_name);

        //Sets the date of the exam
        void change_date(string new_date);
        
        //Sets the percentage of the exam
        void change_percentage(int new_percentage);

        //Sets the score of the exam
        void change_score(int new_score);
};
