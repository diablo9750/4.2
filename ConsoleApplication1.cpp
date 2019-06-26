// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "struct.h"
#include "Source.cpp"

using namespace std;
using namespace types;

namespace types {
	// Сигнатуры требуемых внешних функций

	void Init(container& b);
	void Clear(container& b);
	game* InGame(game& g, ifstream& ifst);
	void OutGame(game* g, ofstream& ofst);
	cartoon* InCartoon(cartoon& c, ifstream& ifst);
	void OutCartoon(cartoon* c, ofstream& ofst);
	doc* InDoc(doc& d, ifstream& ifst);
	void OutDoc(doc* d, ofstream& ofst);
	void Out(film* f, ofstream& ofst);
	film* In(ifstream& ifst);
	int addlist(container& b, ifstream& ifst);
	void InContainer(container& b, ifstream& ifst);
	void Out(container& b, ofstream& ofst);
	int Vowel(game* g);
	int Vowel(cartoon* c);
	int Vowel(doc* d);
	int Vowel(film* f);
	bool Compare(film* first, film* second);
	void OutFilter(container& b, ofstream& ofst);
}

void main(int argc, char* argv[])
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода 
	setlocale(LC_ALL, "Russian"); // вызов функции настройки локали

	ifstream ifst("in.txt");
	if (!ifst)
	{
		cout << "Wrong file input!" << endl;
		system("pause");
		exit(1);
	}
	ofstream ofst("out.txt", ios::trunc);

	/*if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);*/
	cout << "Старт!" << endl;
	container c;
	c.In(ifst);
	ofst << "Контейнер полон." << endl;
	c.Out(ofst);
	c.OutGame(ofst);
	c.Clear();
	ofst << "Контейнер пуст." << endl;
	c.Out(ofst);
	cout << "Стоп!" << endl;
	system("pause");
}

