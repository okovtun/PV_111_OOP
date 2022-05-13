//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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

	//				Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Methods
	double distance(Point other)
	{
		//this - точка, для которой вызвался метод 
		//		 (от которой нужно найти расстояние)
		//other - точка, до которой нужно найти расстояние.
		//this - эта точка
		//other - другая точка
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define DISTANCE

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

#ifdef DISTANCE
	Point A;
	double x = 2, y = 3;
	//cout << "Введите координаты точки: "; cin >> x >> y;
	A.set_x(x);
	A.set_y(y);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
#endif // DISTANCE

	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	//cout << i << endl;
	cout << endl;*/
	int a;
	//cout << a << endl;

	Point A;	//Default constructor
	A.print();
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

/*
-------------------------------------------------------
~ - Tilda

1. С параметрами;
2. Без параметров;
3. По умолчанию (Default contructor) - это конструктор, который может быть вызван без параметров;
4. Конструктор копирования;
5. Конструктор переноса;
-------------------------------------------------------
*/