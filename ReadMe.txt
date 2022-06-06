https://github.com/okovtun/PV_111_OOP.git
https://www.youtube.com/watch?v=4j0QYNF-NX0&list=PLeqyOOqxeiIMQgDDO6Ps9bU9cLghpFJ69
https://meet.google.com/mho-khdw-fhj

Book:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing

//////////////////////////////////////////////////////////////////////////
//////////						Inheritance						//////////
//////////////////////////////////////////////////////////////////////////

TODO:
В проекте Academy реализовать классы Teacher и Graduate.

TOREAD:
http://cplusplus.com/doc/tutorial/typecasting/

MoveSemanthic:
https://cplusplus.com/doc/tutorial/classes2/
https://www.youtube.com/watch?v=ehMg6zvXuMY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=89

TODO:
В отдельной ветке разделить класс Fraction на файлы.

DONE:
В отдельном проекте в Solution IntroductionToOOP реализовать класс String,
описывающий строку. Обеспечить следующие варианты создания строк:
	String str1;	//Создается пустая строка размером 80 Byte
	String str2(8);	//Создается пустая строка размером 8 Byte
	String str3 = "Hello";
	String str4 = "World";
	String str5 = str3 + str4;	//Конкатенация (слияние) строк
	cout << str5 << endl;
-------------------------------------------------------------
	cout << "Введите строку: "; cin >> str1;
	cout << str1 << endl;
-------------------------------------------------------------
	Перегрузить оператор +=
	String str1 = "Hello";
	String str2("World");
	str1 += str2;
	cout << str1 << endl;
=============================================================

DONE:
Проверочный код должен заработать:
	Fraction A = 2.75;
	cout << A << endl;

DONE:
Проверочный код должен заработать:
	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
Варианты ввода:
	1/2
	5
	2(3/4)
	2 3/4

DONE:
Для класса Fraction перегрузить
1. Все арифметические операторы: +, -, *, /;		DONE
2. Increment/Decrement (++/--);						DONE
3. Составные присваивания (Compound assignments): +=, -=, *=, /=;	DONE
4. Операторы сравнения: ==, !=, >, <, >=, <=;		DONE

DONE:
В отдельном проекте реализовать класс Fraction, описывающий простую дробь.
В классе реализовать все необходимые методы и операторы.
1/2;
2(3/4);

DONE:
0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. Написать метод ??? distance(???), который возвращает расстояние до указанной точки;		DONE
2. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками;