//StringConstructorsDelegation
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

//////////////////////////////////////////////////////////////////////////////
//////////			CLASS DECLARATION - ОБЪЯВЛЕНИЕ КЛАССА			//////////
//////////////////////////////////////////////////////////////////////////////

class String
{
	int size;	//Размерстроки в Байтах
	char* str;	//Указатель на строку
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();


	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:
	String& operator=(const String& other);
	String& operator=(String&& other);
	const char& operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};

//////////////////////////////////////////////////////////////////////////////
//////////		CLASS DECLARATION END - КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА		//////////
//////////////////////////////////////////////////////////////////////////////

//--------------------------------------------------------------------------//

//////////////////////////////////////////////////////////////////////////////
//////////			CLASS DEFINITION - ОПРЕДЕЛЕНИЕ КЛАССА			//////////
//////////////////////////////////////////////////////////////////////////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}


//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "Def1aConstruct:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//CopyConstrutor должен выполнять DeepCopy (Побитовое копирование),
	//т.е., выделить новую память, и скопировать в нее содержимое другого объекта
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//MoveConstructor выполнет ShellowCopy (Повершностное копирование)
	other.size = 0;
	other.str = nullptr;	//Зануляем адрес памяти в другом объекте, чтобы эту память НЕ удалил деструктор
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//				Operators:
String& String::operator=(const String& other)
{
	/*int a = 2;
	int b = 3;
	a = b;*/
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
//Global scope - Глобальное пространство имен
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	//Левую строку копируем соответственно:
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
//Правую строку копируем со смещением вправо на размер левой строки
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////////////////////////////////////////////////////////////////////
//////////		CLASS DEFINITION END - КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА		//////////
//////////////////////////////////////////////////////////////////////////////

//#define CONSTRUCTORS_CHECK
#define MOVE_METHODS_CHECK
//#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;	//Default constructor
	str1.print();

	String str2(5);	//explicit Single-argument constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3;	//CopyConstructor
	str4.print();

	String str5;
	str5.print();
	str5 = str4;		//CopyAssignment
	str5.print();
#endif // CONSTRUCTORS_CHECK

#ifdef MOVE_METHODS_CHECK
	String str1 = "Hello";
	cout << str1 << endl;
	String str2("World");
	cout << str2 << endl;
	String str3 = str1 + str2;	//MoveConstructor
	//String str3;
	//str3 = str1 + str2;
	//str3.print();
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;
#endif // MOVE_METHODS_CHECK
	//StringHeaderInitialising
#ifdef CALLING_CONSTRUCTORS
	String str1;			//Default constructor
	str1.print();
	String str2(55);		//Single-argument constructor (int)
	String str3 = "Hello";	//Single-argument constructor (const char* || const char[])
	String str4 = str3;		//Copy constructor
	String str5;
	str5 = str4;			//Copy assignment
	str5.print();
	String str6();	//Здесь НЕ вызывается никаких конструкторов, \
					  и следовательно НЕ создается объект
					//Здесь объявляется функция str6(), \
					  которая ничего не принимает, \
					  и возвращает объек класса String
	String str7{};	//Явный вызов конструктора по умолчанию
	str7.print();
#endif // CALLING_CONSTRUCTORS

}

/*
--------------------------------------------------------------------
MoveMethods:
MoveConstructor
MoveAssignment
=, +=, prefix++
+

CopyMethods - DeepCopy		const reference: const Class& other
MoveMethods - ShellowCopy	r-value reference:	  Class&& other
--------------------------------------------------------------------
*/