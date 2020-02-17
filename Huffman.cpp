#include <iostream>
#include <fstream>
#include "Huffman.h"
#include "Source.cpp"
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

const int SIZE = 128;

int main()
{
	ifstream fin;
	fin.open("input_text.txt");
	if (!check_open_file(fin)) exit(EXIT_FAILURE);

	int *arr = new int [SIZE];
	for (int i = 0; i < SIZE; i++) arr[i] = 0;
	read_text(fin, arr);

	for (int i = 0; i < SIZE; i++)
	{
		cout << "ASCII код индекса [" << i << "]: "<< arr[i] << endl;
	}
	


	delete [] arr;
	fin.close();
	std::cout << "Hello world" << std::endl;
	return 0;
}