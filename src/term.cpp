#include "../include/term.hpp"

term::term(string _name)
    : name(_name) {}

string term::get_name(){ return this->name; }

lecture term::get_lecture(string name){
    for(int i = 0; i < lectures.size(); i++){
        if(name == lectures.at(i).get_name()){
            return lectures.at(i);
        }
    }
    cout << "Lecture Not Found!" << endl;
    return lecture("NULL", "NULL", 0, 0, 0, 0);
}

lecture term::get_lecture(int index){
    if(index < lectures.size()){
        return lectures.at(index);
    }
    cout << "Lecture Not Found!" << endl;
    return lecture("NULL", "NULL", 0, 0, 0, 0);
}

void term::add_lecture(string name, string day, float start_time, float end_time, float average, float degree){
    lectures.push_back(lecture(name, day, start_time, end_time, average, degree));
}

void term::add_lecture(lecture& l){
    lectures.push_back(l);
}

int term::delete_lecture(string name){
    for(int i = 0; i < lectures.size(); i++){
        if(name == lectures.at(i).get_name()){
            lectures.erase(lectures.begin() + i);
            return 0;
        }
    }
    cout << "Lecture can not deleted!" << endl;
    return 1;
}

int term::delete_lecture(int index){
    if(index < lectures.size()){
        lectures.erase(lectures.begin() + index);
        return 0;
    }
    cout << "Lecture can not deleted!" << endl;
    return 1;
}

int term::save_file(){
    string filename = "../save/" + get_name() + ".csv";
    ofstream file(filename);


    if (file.is_open()) {

        for (int i = 0; i < this->lectures.size(); i++)
        {
            lecture tmp = lectures.at(i);
            file<< tmp.get_name() << ","
                << tmp.get_day() << ","
                << tmp.get_start_time() << ","
                << tmp.get_end_time() << ","
                << tmp.get_average() << ","
                << tmp.get_degree() << "\n";

            
            for(int j = 0; j < tmp.get_exam_number(); j++){
                exam exam = tmp.get_exam(j);
                file<< exam.get_name() << ","
                    << exam.get_score() << ","
                    << exam.get_percentage() << ","
                    << exam.get_date() << "\n";
            }
            file << "--------------------------\n";
        }
        std::cout << "Data saved to file.\n";
    }else {
        std::cout << "Error opening file for writing.\n";
        return 1;
    }

    return 0;
}

term term::read_file(string name){
    term new_term(name);

    string filename = "../save/" + name + ".csv";
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Error opening file for reading.");
    }


    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string name, day;
        float start_time, end_time, average, degree;

        getline(ss, name, ',');
        getline(ss, day, ',');
        ss >> start_time;
        ss.ignore();  // Virgülün atlanması için
        ss >> end_time;
        ss.ignore();  // Virgülün atlanması için
        ss >> average;
        ss.ignore();  // Virgülün atlanması için
        ss >> degree;

        // Yeni bir lecture objesi oluştur
        lecture l(name, day, start_time, end_time, average, degree);

        // Sınavları ekleyelim
        while (getline(file, line) && line != "--------------------------") {
            stringstream ss_exam(line);
            string exam_name, exam_date;
            float score, percentage;

            getline(ss_exam, exam_name, ',');
            ss_exam >> score;
            ss_exam.ignore();  // Virgülün atlanması için
            ss_exam >> percentage;
            ss_exam.ignore();  // Virgülün atlanması için
            getline(ss_exam, exam_date, ',');

            l.add_exam(exam_name, exam_date, percentage, score);
        }

        // Bu dersi term'e ekle
        new_term.add_lecture(l);
    }

    file.close();
    return new_term;
}