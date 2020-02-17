#include <iostream>
#include <fstream>
#include "Huffman.h"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

const int SIZE = 256;

int main()
{
	ifstream fin;
	fin.open("input_text.txt");
	if (!check_open_file(fin)) exit(EXIT_FAILURE);
	
	int *arr = new int [SIZE];


	std::cout << "Hello world" << std::endl;
	return 0;
}