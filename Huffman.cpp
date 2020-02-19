#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

vector <bool> code; //Вектор кодов
map <char, vector<bool> > table; //Ассоциативный массив символ - код

class Node
{
public:
	int frequency;  //частота
	char symbol;  
	Node *left, *right;  //левый и правый потомок

	Node(Node *L, Node *R)
	{
		left = L;
		right = R;
		frequency = L->frequency + R->frequency;
	}
	Node(){};
};

struct MyCompare //Для корректной сортировки
{
	bool operator()(Node *l, Node *r) const
	{	return l->frequency < r->frequency;	}
};

void build_table(Node *root) //Постройка таблицы кода
{
	if(root->left!=NULL)
	{
		code.push_back(0);
		build_table(root->left);
	}
	if (root->right!=NULL)
	{
		code.push_back(1);
		build_table(root->right);
	}
	if (root->symbol) table[root->symbol] = code;

	code.pop_back();	

}

int main()
{
	ifstream fin("input_text.txt");
	fstream out("output_text.bin");

	int count = 0;
	char buf = 0;
	map <char, int> arr; //Ассоциативный массив символ - частота
	map <char, int>::iterator i;
	map <char, vector<bool> >::iterator ii;
	list <Node*> node_list; //Список вершин

	while(!fin.eof()) //считали частоту
	{
		char c;
		c = fin.get();
		arr[c]++;
	}
	fin.clear();
	fin.seekg(0);

	for (i = arr.begin(); i != arr.end() ; ++i) //заполнили список вершин
	{
		Node *p = new Node;
		p->symbol = i->first;
		p->frequency = i->second;
		node_list.push_back(p);
	}

	while (node_list.size()!=1) //Отсортировали список вершин
	{
		node_list.sort(MyCompare());

		Node *SonL = node_list.front();
		node_list.pop_front();
		Node *SonR = node_list.front();
		node_list.pop_front();

		Node *parent = new Node (SonL, SonR);
		node_list.push_back(parent); 
	}

	Node *root = node_list.front(); //Определили вершину

	build_table(root); //Построили таблицу символ - код

	for(ii = table.begin(); ii != table.end(); ii++) //вывели символ - код
	{
		cout << ii->first << ":";
		vector <bool> x = table[ii->first];
		for (int n = 0; n < int(x.size()); n++)
		{
			cout << x[n];
		}
		cout << endl;
	}

	while(!fin.eof()) //записали побайтово в файл для закодированного текста
	{
		char c;
		c = fin.get();
		vector<bool> x = table[c];

		for (int n = 0; n < int(x.size()); n++)
		{
			buf = buf | x[n] << (7-count);
			count++;
			if (count == 8)
			{
				count = 0;
				out << buf;
				buf=0;
			}
		}
	}
	cout << endl;

	ifstream F("output_text.bin");

	Node *p = root;
	count = 0; char byte;
	byte = F.get();
	while(!F.eof()) //разкодировка
	{
		bool b = byte & (1 << (7 - count));
		if (b)	p = p->right;	else p = p->left;
		if (p->left==NULL && p->right==NULL) 
		{
			cout << p->symbol; 
			p=root;
		}
		count++;
		if(count==8)
		{
			count=0; byte = F.get();
		}
	}
	cout << endl;

	F.close();
	out.close();
	fin.close();
	return 0;
}