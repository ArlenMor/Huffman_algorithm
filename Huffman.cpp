#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

int main()
{
	ifstream fin;
	fin.open("input_text.txt");
	if(!fin.is_open())
	{
		cout << "Файл не найден. Выход.." << endl;
		exit(EXIT_FAILURE); 
	}
	

	std::cout << "Hello world" << std::endl;
	return 0;
}