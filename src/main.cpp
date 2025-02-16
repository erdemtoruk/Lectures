#include "../include/term.hpp"
//#include <iostream>

using namespace std;

int main(){

	term t = term::read_file("Spring_2025");

	

	t.save_file();
    return 0;
}
