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
	int a;	//���������� ���������� 'a' ���� 'int'
	Point A;//���������� ���������� 'A' ���� 'Point'
			//���������� ������� 'A' ��������� 'Point'
			//�������� ���������� 'A' ��������� 'Point'
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
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
-------------------------------------------------------
*/