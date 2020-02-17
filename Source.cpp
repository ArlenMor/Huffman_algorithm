#include "Huffman.h"
using namespace std;

bool check_open_file(ifstream &fin) //проверяет открытие файла
{
	if(!fin.is_open()) return false;
	else return true; 
}

void read_text(ifstream &fin, int *arr) //Считывает элеметны в ассоц. массив
{
	char x;
	do{
		fin >> x;
		arr[int(x)]++;
	}while(!fin.fail());
}