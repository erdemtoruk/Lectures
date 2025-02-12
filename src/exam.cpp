#include "../include/exam.hpp"

exam::exam(string _name, string _date, int _percentage, int _score = 0)
    : name(_name), date(_date), percentage(_percentage), score(_score){

}

string exam::get_name(){
    return this->name;
}

string exam::get_date(){
    return this->date;
}

int exam::get_percentage(){
    return this->percentage;
}

int exam::get_score(){
    return this->score;
}

void exam::change_name(string new_name){
    this->name = new_name;
}

void exam::change_date(string new_date){
    this->date = new_date;
}

void exam::change_percentage(int new_percentage){
    this->percentage = new_percentage;
}

void exam::change_score(int new_score){
    this->score = new_score;
}