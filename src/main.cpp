#include "../include/term.hpp"
#include <iomanip>

using namespace std;

int main(){
	cout << fixed << setprecision(2); // Set output to fixed-point notation with 2 decimal places
	term t = term::read_file("Spring_2025");

	t.interface();

	t.save_file();
    return 0;
}
