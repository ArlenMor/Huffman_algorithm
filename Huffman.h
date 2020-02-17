#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

/*
		Функции:
check_open_file - 


*/

bool check_open_file(std::ifstream &fin)
{
	if(!fin.is_open()) return false;
	else return true; 
}