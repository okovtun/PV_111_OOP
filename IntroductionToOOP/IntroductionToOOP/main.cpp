//IntroductionToOOP
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
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
#endif // STRUCT_POINT

	Point A;
	double x=2, y=3;
	//cout << "Введите координаты точки: "; cin >> x >> y;
	A.set_x(x);
	A.set_y(y);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
}

/*
-------------------------------------------------------
.  - Оператор прямого доступа (Point operator)
-> - Оператор косвенного доступа (Arrow operator)
-------------------------------------------------------
*/

/*
-------------------------------------------------------
1. Encapsulation;
2. Inheritance;
3. Polymorphism;
-------------------------------------------------------
*/

/*
-------------------------------------------------------
					ENCAPSULATION
Модификаторы доступа:
	private:	закрытые поля, доступные только внутри класса
	public:		открытые поля, доступные из любого места программы
	protected:	защищенные поля. 
				Этот модификатор доступа используется лишь при наследовании.
				protected поля доступны внутри этого класса, и его дочерних классов.

Get/Set-методы:
	get (взять/получить) - позволяют получать значения закрытых (private) переменных.
	get-методы открывают доступ к переменным класса на чтение.

	set (задать/установить) - позволяют задавать значения переменных членов класса.
	set-методы открывают доступ к переменным членам класса на запись.
-------------------------------------------------------
*/