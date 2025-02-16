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

        string get_name();
        string get_date();
        float get_percentage();
        float get_score();

        void change_name(string new_name);
        void change_date(string new_date);
        void change_percentage(int new_percentage);
        void change_score(int new_score);
};
