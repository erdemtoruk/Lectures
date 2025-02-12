#include "../include/lecture.hpp"

string notes[] = {"FF", "FF", "FF", "FF", "DD", "DD+", "DC", "DC+", "CC", "CC+", "CB", "CB+", "BB", "BB+", "BA", "BA+", "AA"};

lecture::lecture(string _name, string _day, float _start_time, float _end_time, float _average = 0, float _degree = 0)
    : name(_name), day(_day), start_time(_start_time), end_time(_end_time), average(_average), degree(_degree){

    this->num_exams = 0;
    if(_start_time < 8.3 || _start_time < _end_time || _end_time > 18){
        cout << "Invalid time!" << endl;
    }
}

string lecture::get_name(){
    return this->name;
}

string lecture::get_day(){
    return this->day;
}

float lecture::get_start_time(){
    return this->start_time;
}

float lecture::get_end_time(){
    return this->end_time;
}

int lecture::get_lecture_duration(){
    return this->end_time - this->start_time;
}

string lecture::get_degree(){
    return notes[int(this->degree / 0.25)];
}

void lecture::change_name(string new_name){
    this->name = new_name;
}

void lecture::change_day(string new_day){
    this->day = new_day;
}

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

void lecture::calculate_average(){
    if(this->num_exams == 0){
        cout << "No exams found!" << endl;
        return;
    }

    float total = 0;
    for(int i = 0; i < num_exams; i++){
        total += (float(exams[i].get_score()) * exams[i].get_percentage()) / 100;
    }

    this->average = total;
}