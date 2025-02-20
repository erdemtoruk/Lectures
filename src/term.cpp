#include "../include/term.hpp"

term::term(string _name)
    : name(_name) {}

string term::get_name(){ return this->name; }

lecture* term::get_lecture(string name){
    for(int i = 0; i < lectures.size(); i++){
        if(name == lectures.at(i).get_name()){
            return &lectures.at(i);
        }
    }
    cout << "Lecture Not Found!" << endl;
    return NULL;
}

lecture* term::get_lecture(int index){
    if(index < lectures.size()){
        return &lectures.at(index);
    }
    cout << "Lecture Not Found!" << endl;
    return NULL;
}

void term::add_lecture(string name, string day, float start_time, float end_time){
    lectures.push_back(lecture(name, day, start_time, end_time));
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
            //tmp.calculate_average();
            file<< tmp.get_name() << ","
                << tmp.get_day() << ","
                << tmp.get_start_time() << ","
                << tmp.get_end_time() << ","
                << tmp.get_average() << ","
                << tmp.get_degree() << "\n";

            
            for(int j = 0; j < tmp.get_exam_number(); j++){
                exam* exam = tmp.get_exam(j);
                file<< exam->get_name() << ","
                    << exam->get_score() << ","
                    << exam->get_percentage() << ","
                    << exam->get_date() << "\n";
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
        lecture l(name, day, start_time, end_time);

        // Sınavları ekle
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

void term::interface(){
    while(true){
        cout << "Select the action you want to take: " << endl;
        cout << "0- Exit \n1- Get Lecture \n2- Add Lecture \n3- Delete Lecture \n";

        int choose = -1;
        string str_input;
        float float_input;
        cin >> choose;

        if(choose == 0)
            break;

        else if(choose == 1){
            cout << "Enter lecture name: ";
            cin >> str_input;
            cout << endl;
            lecture* lec = this->get_lecture(str_input);

            if(lec){
                while(true){
                    cout << "Select the action you want to take: " << endl;
                    cout << "0- Back \n11- Show name \n12- Show date \n13- Show degree \n14- Show exam number\n"
                         << "21- Change name \n22- Change day \n23- Change start time \n24- Change end time \n"
                         << "31- Get exam \n32- Add exam \n33-Delete exam \n";

                    cin >> choose;

                    if(choose == 0)
                        break;

                    else if(choose == 11)
                        cout << "Lecture name: " << lec->get_name() << endl;
                    
                    else if(choose == 12)
                        cout << lec->get_day() << " " << lec->get_start_time() << "-" << lec->get_end_time() << endl;

                    else if(choose == 13)
                        cout << "Cumulative average: " << lec->get_average() << "Expected degree: " << lec->get_degree() << endl;
                    
                    else if(choose == 14)
                        cout << "Exam number is " << lec->get_exam_number() << endl;

                    else if(choose == 21){
                        cout << "Enter new name: ";
                        cin >> str_input;
                        cout << endl;

                        lec->change_name(str_input);
                    }
                    else if(choose == 22){
                        cout << "Enter new day: ";
                        cin >> str_input;
                        cout << endl;

                        lec->change_day(str_input);
                    }
                    else if(choose == 23){
                        cout << "Enter new start time: ";
                        cin >> float_input;
                        cout << endl;

                        lec->change_start_time(float_input);
                    }
                    else if(choose == 24){
                        cout << "Enter new end time: ";
                        cin >> float_input;
                        cout << endl;

                        lec->change_end_time(float_input);
                    }
                    else if(choose == 31){
                        cout << "Enter exam name: ";
                        cin >> str_input;
                        cout << endl;
                        exam* ex = lec->get_exam(str_input);

                        if(ex){
                            while(true){
                                cout << "Select the action you want to take: " << endl;
                                cout << "0- Back \n11- Show name \n12- Show date \n13- Show percentage \n14- Show score\n"
                                     << "21- Change name \n22- Change date \n23- Change percentage \n24- Change score \n";

                                cin >> choose;

                                if(choose == 0)
                                    break;
                                
                                else if(choose == 11)
                                    cout << "Exam name is " << ex->get_name() << endl;

                                else if(choose == 12)
                                    cout << "Exam date is " << ex->get_date() << endl;
                                    
                                else if(choose == 13)
                                    cout << "Exam percentage is " << ex->get_percentage() << endl;

                                else if(choose == 14)
                                    cout << "Exam score is " << ex->get_score() << endl;

                                else if(choose == 21){
                                    cout << "Enter new name: ";
                                    cin >> str_input;
                                    cout << endl;

                                    ex->change_name(str_input);
                                }
                                else if(choose == 22){
                                    cout << "Enter new date: ";
                                    cin >> str_input;
                                    cout << endl;

                                    ex->change_date(str_input);
                                }
                                else if(choose == 23){
                                    cout << "Enter new percentage: ";
                                    cin >> float_input;
                                    cout << endl;

                                    ex->change_percentage(float_input);
                                }
                                else if(choose == 24){
                                    cout << "Enter new score: ";
                                    cin >> float_input;
                                    cout << endl;

                                    ex->change_score(float_input);
                                }
                                else
                                    cout << "Invalid number!" << endl;
                            }
                        }
                        else
                            cout << "This exam not exist!" << endl;
                    }
                    else if(choose == 32){
                        string name;
                        string date;
                        float percentage;
                        float score;

                        cout << "Enter exam name: ";
                        cin >> name;
                        cout << endl;
                        
                        cout << "Enter exam date: ";
                        cin >> date;
                        cout << endl;

                        cout << "Enter exam percentage: ";
                        cin >> percentage;
                        cout << endl;

                        cout << "Enter exam score: ";
                        cin >> score;
                        cout << endl;

                        if(lec->add_exam(name, date, percentage, score) == 0)
                            cout << "Exam added!" << endl;
                        else
                            cout << "Exam can not added!" << endl;
                    }
                    else if(choose == 33){
                        cout << "Enter exam name to delete: ";
                        cin >> str_input;
                        cout << endl;

                        if(lec->delete_exam(str_input) == 0)
                            cout << "Exam deleted!" << endl;
                        else
                            cout << "Exam can not deleted!" << endl;
                    }
                    else
                        cout << "Invalid number!" << endl;
                }
            }
            else{
                cout << "This lecture not exist!" << endl;
            }
        }
        else if(choose == 2){
            string name;
            string day;
            float start_time;
            float end_time;

            cout << "Enter lecture name: ";
            cin >> name;
            cout << endl;
                        
            cout << "Enter lecture day: ";
            cin >> day;
            cout << endl;

            cout << "Enter lecture start time: ";
            cin >> start_time;
            cout << endl;

            cout << "Enter lecture end time: ";
            cin >> end_time;
            cout << endl;

            this->add_lecture(name, day, start_time, end_time);
            cout << "Lecture added!" << endl;
        }
        else if(choose == 3){
            cout << "Enter name of lecture to delete: ";
            cin >> str_input;
            cout << endl;

            if(this->delete_lecture(str_input) == 0)
                cout << "Lecture deleted!" << endl;
            else
                cout << "Lecture can not deleted!" << endl;
        }
        else
            cout << "Invalid number!" << endl;
    }
}