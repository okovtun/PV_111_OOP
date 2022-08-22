https://github.com/okovtun/PV_111_OOP.git
https://www.youtube.com/watch?v=4j0QYNF-NX0&list=PLeqyOOqxeiIMQgDDO6Ps9bU9cLghpFJ69
https://meet.google.com/mho-khdw-fhj
https://teams.microsoft.com/l/meetup-join/19:XqhHr8twtYoW9Bo7-N21Z3u7jSrTMMmUamvEavmMkiY1@thread.tacv2/1657728221886?context=%7B%22Tid%22:%22d3512d16-6dc5-41bd-be00-0069618327b7%22,%22Oid%22:%2245d60748-def7-49b6-8150-73158be99dc5%22%7D

Book:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing

Absences:
2022/08/17
2022/08/19	DONE
2022/08/26

//////////////////////////////////////////////////////////////////////////
//////////					DATA CONTAINERS						//////////
//////////////////////////////////////////////////////////////////////////

TODO:
1. В Бинарное дерево добавить следующие методы:
	int minValue()const;							DONE
	int maxValue()const;							DONE
	int Count()const;	//Вычисляет количество элементов дерева	DONE
	int Sum()const;		//Сумма элементов дерева	DONE
	int Avg()const;		//Среднее-арифметическое элементов дерева	DONE
	int depth()const;	//Определяет глубину дерева	DONE
	void clear();		//Очищает дерево (удаляет из него все элементы)	DONE
	void erase(???);	//Удаляет заданное значение из дерева		DONE
	~Tree();			DONE
2. Объеспечить вызов методов из main() без необходимости передавать в них корень Дерева,
   например, чтобы вместо tree.print(tree.getRoot()) можно было написать просто tree.print();	DONE
3. Tree tree = { 3, 5, 8, 13, 21 };
4. CopyMethods;
5. MoveMethods;

DONE:
1. На базе класса ForwardList создать класс Stack.
   Stack - это модель памяти, из которой последний записанный элемент считывается первым.
   LIFO - Last-In First Out;
   Stack top - вершина стека;
   Stack bottom - дно стека;
2. На базе класса List, реализовать класс Queue (очередь)
   Queue - это модель памяти из которой последний записанный элемент считывается последним.
   FIFO - First-In First-Out;

DONE:
1. От ветки InheritIteratorInList2 cоздать ветку MyTemplatedList2, и в ней шаблонизировать двусвязный список;
2. От ветки MyTemplatedList2 создать ветку MyTemplatedList2separate, и в ней разделить шаблонный List2 на файлы;

DONE:
Создать ветку InheritIteratorsInList2, и в ней оптимизировать Итераторы двусвязного списка
при помощи наследования.

DONE:
Реализовать двусвязный список.

DONE:
Вывести список на экран при помощи range-based for.

DONE:
В класс ForwardList добавить следующие методы:
	void push_back(int Data);	DONE
	void pop_front();			DONE
	void pop_back();			DONE

	void insert(int Data, int index);	DONE
	void erase(int index);
--------------------------------------------------------------------
	Destructor();	DONE
	CopyMethods;	DONE
	MoveMethods;	DONE
	operator+, который выполняет конкатенацию двух списков	DONE
--------------------------------------------------------------------
Необходимо обеспечить возможность создания списков следующим образом:
	ForwardList list = { 3, 5, 8, 13, 21 };

//////////////////////////////////////////////////////////////////////////
//////////						Inheritance						//////////
//////////////////////////////////////////////////////////////////////////


TOREAD:
https://cplusplus.com/doc/tutorial/polymorphism/
https://cplusplus.com/doc/tutorial/files/

TODO:
В проект AbstractGeometry добавить иерархию классов треугольников.
Все треугольники нужно нарисовать используя WinGDI.

DONE:
В проект AbstractGeometry добавить класс Circle и нарисовать его исползуя WinGDI;

DONE:
Реализовать иерархию геометрических фигур: Квадрат, Прямоугольник, Круг, Треугольник, ....
Для каждой фигуры нужно вывести ее особые свойства (длина стороны, радиус, высота....),
а так же ее площадь и периметр. Каждую фигуру нужно нарисовать.
Фигуры должны генерироваться в случайном порядке, 
и их особые свойства так же будут присваиваться в случайном порядке.

DONE:
Обеспечить выравнивание в классах Teacher и Graduate.

DONE:
1. В проекте Files имя файла должно вводиться пользователем с клавиатуры;
2. В проекте Academy сохранить группу в файл;

DONE:
Создать ветку AcademySeparated, и в ней вынести классы 
в отдельные файлы.

DONE:
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