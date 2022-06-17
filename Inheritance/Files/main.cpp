#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	const int SIZE = 256;
	char sz_filename[SIZE] = {};	//sz_ - String Zero
	cout << "Введите имя файла: ";
	cin.getline(sz_filename, SIZE);

	//strcmp() - String compare (сравнение строк)
	//int strcmp(char* str1, char* str2);
	//Если функция вернула 0, значит строки идентичны, 
	//значение отличное от нуля - строки разные
	if (strcmp(sz_filename + strlen(sz_filename) - 4, ".txt"))
		//strlen() - возвращает размер строки в символах.
		strcat(sz_filename, ".txt");
	std::ofstream fout;		//1) Создаем поток
	fout.open(sz_filename, std::ios_base::app);	//2) Открываем поток
	char sz_contents[SIZE] = {};
	cout << "Введите содержимое файла: ";
	cin.getline(sz_contents, SIZE);
	//fout << "Hello World!\n";	//3) Выводим в поток
	fout << sz_contents;	//3) Выводим в поток
	fout.close();			//4) Закрываем поток
	//Потоки обязательно нужно закрывать, это так же важно, как удалять память.
	//Сколко раз был вызван метод open(), столько же раз нужно вызвать метод close();
	char sz_command[SIZE] = "notepad ";
	strcat(sz_command, sz_filename);
	//Функция strcat(char* str1, char* str2) выполняет конкатенацию строк (слияние строк)
	//К содержимому первой строки добавляется содержимое второй строки.
	system(sz_command);
#endif // WRITE_TO_FILE

	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		//TODO: read file
		const int n = 256;
		char buffer[n] = {};
		while (!fin.eof())	//eof() - end of file
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	system("notepad File.txt");
}