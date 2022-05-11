//IntroductionToOOP
#include<iostream>
using namespace std;

struct Point
{
	double x;
	double y;
};

void main()
{
	setlocale(LC_ALL, "");
	//type name;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
			//Объявление объекта 'A' структуры 'Point'
			//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;

	cout << sizeof(Point) << endl;
	cout << typeid(A).name() << endl;
}

/*
-------------------------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
-------------------------------------------------------
*/