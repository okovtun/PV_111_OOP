#include"String.h"

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