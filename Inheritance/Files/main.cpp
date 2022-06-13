#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	std::ofstream fout;		//1) Создаем поток
	fout.open("File.txt", std::ios_base::app);	//2) Открываем поток
	fout << "Hello World!\n";	//3) Выводим в поток
	fout.close();			//4) Закрываем поток
	//Потоки обязательно нужно закрывать, это так же важно, как удалять память.
	//Сколко раз был вызван метод open(), столько же раз нужно вызвать метод close();
	system("notepad File.txt");
}