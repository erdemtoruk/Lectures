#include <sstream>
#include <fstream>

#include "lecture.hpp"


using namespace std;

class term{
    private:
        string name;
        vector<lecture> lectures;

        string get_name();
        lecture* get_lecture(string name);
        lecture* get_lecture(int index);

        void add_lecture(string name, string day, float start_time, float end_time);
        void add_lecture(lecture& l);

        int delete_lecture(string name);
        int delete_lecture(int index);

        bool is_future_date(string date);
        void get_schedule();
        
    public:
        term(string name);

        void interface();
        
        static term read_file(string name);
        int save_file();
};


