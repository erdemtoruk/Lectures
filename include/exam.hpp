#include <string>
#include <iostream>

using namespace std;

class exam{
    private:
        string name;
        string date;
        int percentage;
        int score;

    public:
        exam(string _name, string _date, int _percentage, int _score = 0);

        string get_name();
        string get_date();
        int get_percentage();
        int get_score();

        void change_name(string new_name);
        void change_date(string new_date);
        void change_percentage(int new_percentage);
        void change_score(int new_score);
};
