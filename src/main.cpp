#include "../include/term.hpp"
//#include <iostream>

using namespace std;

int main(){

	term t = term::read_file("Spring_2025");

	t.add_lecture("BLG_312", "Monday", 8.30, 11.30, 0, 0);
	lecture tmp = t.get_lecture("BLG_312");
	tmp.add_exam("Midterm_1", "23-04-2025", 30, 0);
	

	t.save_file();

    return 0;
}
