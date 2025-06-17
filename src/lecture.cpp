#include "../include/lecture.hpp"

using namespace std;

string notes[] = {"FF", "DD", "DD+", "DC", "DC+", "CC", "CC+", "CB", "CB+", "BB", "BB+", "BA", "BA+", "AA"};

lecture::lecture(string _name, string _day, float _start_time, float _end_time)
    : name(_name), day(_day), start_time(_start_time), end_time(_end_time), average(0){

    if(this->start_time < 8.0f || this->start_time >= this->end_time || this->end_time > 18.0f){
        cout << "Invalid time!" << endl;
    }
}

string lecture::get_name(){ return this->name; }

string lecture::get_day(){ return this->day; }

float lecture::get_start_time(){ return this->start_time; }

float lecture::get_end_time(){ return this->end_time; }

int lecture::get_exam_number(){ return exams.size(); }

exam* lecture::get_exam(string name){
    for(int i = 0; i < exams.size(); i++){
        if(name == exams.at(i).get_name()){
            return &exams.at(i);
        }
    }
    cout << "Exam Not Found!" << endl;
    return NULL;
}

exam* lecture::get_exam(int index){
    if (index < exams.size()){
        return &exams.at(index);
    }
    else{
        cout << "Invalid index!" << endl;
        return NULL;
    } 
}

string lecture::get_degree(){
    if(this->average >= 88)
        return notes[13];
    else if(this->average < 40)
        return notes[0];

    return notes[(int)(this->average / 4) - 9];
}

float lecture::get_average(){ calculate_average(); return this->average; }

void lecture::change_name(string new_name){ this->name = new_name; }

void lecture::change_day(string new_day){ this->day = new_day; }

void lecture::change_start_time(float new_start_time){
    if(new_start_time < 8.3 || new_start_time > 17){
        cout << "Invalid start time!" << endl;
    }
    else{
        this->start_time = new_start_time;
    }
}

void lecture::change_end_time(float new_end_time){
    if(new_end_time < 9 || new_end_time > 18){
        cout << "Invalid end time!" << endl;
        return;
    }
    
    this->end_time = new_end_time;
}

int lecture::add_exam(string name, string date, float percentage, float score){
    if (percentage < 0){
        cout << "Invalid percentage!" << endl;
        return 1;
    }
    if (score < 0){
        cout << "Invalid score!" << endl;
        return 1; 
    }

    exams.push_back(exam(name, date, percentage, score));
    return 0;
}

int lecture::delete_exam(string name){
    for(int i = 0; i < exams.size(); i++){
        if(name == exams.at(i).get_name()){
            exams.erase(exams.begin() + i);
            return 0;
        }
    }
    cout << "Exam can not deleted!" << endl;
    return 1;
}

int lecture::delete_exam(int index){
    if(index < exams.size()){
        exams.erase(exams.begin() + index);
        return 0;
    }
    cout << "Exam can not deleted!" << endl;
    return 1;
}

void lecture::calculate_average(){
    if(exams.size() == 0){
        cout << "No exams found!" << endl;
        return;
    }

    float total = 0;
    for(int i = 0; i < exams.size(); i++){
        total += exams.at(i).get_score() * exams.at(i).get_percentage() / 100;
    }

    this->average = total;
}


