//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

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
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
		//pause
		//Paul
		//Shallow copy
		//Deep copy
	}
	//Class(const Class& other);
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
//	type	name		(parameters)
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	//				Methods
	double distance(const Point& other)
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

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	//A.set_x(-10);
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

double operator-(const Point& left, const Point& right)
{
	/*double x_distance = left.get_x() - right.get_x();
	double y_distance = left.get_y() - right.get_y();
	return sqrt(x_distance*x_distance + y_distance * y_distance);*/
	return sqrt(pow(left.get_x() - right.get_x(), 2) + pow(left.get_y() - right.get_y(), 2));
}

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2

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
	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A:   " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
	/*for (int i = 0; i < 10; i++)
{
	cout << i << "\t";
}
//cout << i << endl;
cout << endl;*/
	int a(2);
	cout << a << endl;

	Point A;	//Default constructor
	A.print();

	Point B = 5;//SingleArgumentConstructor
	B.print();

	Point C(8); //SingleArgumentConstructor
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D;//Copy constructor
	E.print();

	Point F(D);	//Copy constructor
	F.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment  
	Point A(2, 3);
	Point B = A;//CopyConstructor потому что объект 'B' создается
	Point C;	//Default constructor
	C = B;		//CopyAssignment потому что объект 'C' уже существует  
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
#endif // ASSIGNMENT_CHECK_2

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	
	Point C = A + B;
	C.print();

	Point D = ++C;
	C.print();
	D.print();

	cout << A - B << endl;	//Неявный вызов оператора - для объектов класса Point
	cout << operator-(A, B) << endl;//Явный вызов оператора
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

/*
-------------------------------------------------------
operator@
1. Перегрузить можно только существующие операторы,
   нельзя создавать новые операторы.
	+	перегружается;
	++	перегружается;
	*	перегружается;
	**	НЕ перегружается;
	/	перегружается;
	//	НЕ перегружается;
2. Не все существующие операторы можно перегрузить.
   НЕ перегружаются:
	?: - Conditional Ternary;
	:: - Scope operator (Оператор разрешения видимости)
	.  - Point operator (Оператор прямого доступа)
	.* - Pointer to member selection
	#
	##
3. Перегруженные операторы сохраняют приоритет;
4. Нельзя переопрделить поведение операторов со встроенными типами данных;
-------------------------------------------------------
*/