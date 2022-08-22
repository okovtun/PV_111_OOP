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
1. � �������� ������ �������� ��������� ������:
	int minValue()const;							DONE
	int maxValue()const;							DONE
	int Count()const;	//��������� ���������� ��������� ������	DONE
	int Sum()const;		//����� ��������� ������	DONE
	int Avg()const;		//�������-�������������� ��������� ������	DONE
	int depth()const;	//���������� ������� ������	DONE
	void clear();		//������� ������ (������� �� ���� ��� ��������)	DONE
	void erase(???);	//������� �������� �������� �� ������		DONE
	~Tree();			DONE
2. ����������� ����� ������� �� main() ��� ������������� ���������� � ��� ������ ������,
   ��������, ����� ������ tree.print(tree.getRoot()) ����� ���� �������� ������ tree.print();	DONE
3. Tree tree = { 3, 5, 8, 13, 21 };
4. CopyMethods;
5. MoveMethods;

DONE:
1. �� ���� ������ ForwardList ������� ����� Stack.
   Stack - ��� ������ ������, �� ������� ��������� ���������� ������� ����������� ������.
   LIFO - Last-In First Out;
   Stack top - ������� �����;
   Stack bottom - ��� �����;
2. �� ���� ������ List, ����������� ����� Queue (�������)
   Queue - ��� ������ ������ �� ������� ��������� ���������� ������� ����������� ���������.
   FIFO - First-In First-Out;

DONE:
1. �� ����� InheritIteratorInList2 c������ ����� MyTemplatedList2, � � ��� ��������������� ���������� ������;
2. �� ����� MyTemplatedList2 ������� ����� MyTemplatedList2separate, � � ��� ��������� ��������� List2 �� �����;

DONE:
������� ����� InheritIteratorsInList2, � � ��� �������������� ��������� ����������� ������
��� ������ ������������.

DONE:
����������� ���������� ������.

DONE:
������� ������ �� ����� ��� ������ range-based for.

DONE:
� ����� ForwardList �������� ��������� ������:
	void push_back(int Data);	DONE
	void pop_front();			DONE
	void pop_back();			DONE

	void insert(int Data, int index);	DONE
	void erase(int index);
--------------------------------------------------------------------
	Destructor();	DONE
	CopyMethods;	DONE
	MoveMethods;	DONE
	operator+, ������� ��������� ������������ ���� �������	DONE
--------------------------------------------------------------------
���������� ���������� ����������� �������� ������� ��������� �������:
	ForwardList list = { 3, 5, 8, 13, 21 };

//////////////////////////////////////////////////////////////////////////
//////////						Inheritance						//////////
//////////////////////////////////////////////////////////////////////////


TOREAD:
https://cplusplus.com/doc/tutorial/polymorphism/
https://cplusplus.com/doc/tutorial/files/

TODO:
� ������ AbstractGeometry �������� �������� ������� �������������.
��� ������������ ����� ���������� ��������� WinGDI.

DONE:
� ������ AbstractGeometry �������� ����� Circle � ���������� ��� �������� WinGDI;

DONE:
����������� �������� �������������� �����: �������, �������������, ����, �����������, ....
��� ������ ������ ����� ������� �� ������ �������� (����� �������, ������, ������....),
� ��� �� �� ������� � ��������. ������ ������ ����� ����������.
������ ������ �������������� � ��������� �������, 
� �� ������ �������� ��� �� ����� ������������� � ��������� �������.

DONE:
���������� ������������ � ������� Teacher � Graduate.

DONE:
1. � ������� Files ��� ����� ������ ��������� ������������� � ����������;
2. � ������� Academy ��������� ������ � ����;

DONE:
������� ����� AcademySeparated, � � ��� ������� ������ 
� ��������� �����.

DONE:
� ������� Academy ����������� ������ Teacher � Graduate.

TOREAD:
http://cplusplus.com/doc/tutorial/typecasting/

MoveSemanthic:
https://cplusplus.com/doc/tutorial/classes2/
https://www.youtube.com/watch?v=ehMg6zvXuMY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=89

TODO:
� ��������� ����� ��������� ����� Fraction �� �����.

DONE:
� ��������� ������� � Solution IntroductionToOOP ����������� ����� String,
����������� ������. ���������� ��������� �������� �������� �����:
	String str1;	//��������� ������ ������ �������� 80 Byte
	String str2(8);	//��������� ������ ������ �������� 8 Byte
	String str3 = "Hello";
	String str4 = "World";
	String str5 = str3 + str4;	//������������ (�������) �����
	cout << str5 << endl;
-------------------------------------------------------------
	cout << "������� ������: "; cin >> str1;
	cout << str1 << endl;
-------------------------------------------------------------
	����������� �������� +=
	String str1 = "Hello";
	String str2("World");
	str1 += str2;
	cout << str1 << endl;
=============================================================

DONE:
����������� ��� ������ ����������:
	Fraction A = 2.75;
	cout << A << endl;

DONE:
����������� ��� ������ ����������:
	Fraction A;
	cout << "������� ������� �����: ";
	cin >> A;
	cout << A << endl;
�������� �����:
	1/2
	5
	2(3/4)
	2 3/4

DONE:
��� ������ Fraction �����������
1. ��� �������������� ���������: +, -, *, /;		DONE
2. Increment/Decrement (++/--);						DONE
3. ��������� ������������ (Compound assignments): +=, -=, *=, /=;	DONE
4. ��������� ���������: ==, !=, >, <, >=, <=;		DONE

DONE:
� ��������� ������� ����������� ����� Fraction, ����������� ������� �����.
� ������ ����������� ��� ����������� ������ � ���������.
1/2;
2(3/4);

DONE:
0. ������� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
1. �������� ����� ??? distance(???), ������� ���������� ���������� �� ��������� �����;		DONE
2. �������� ������� ??? distance(???), ������� ���������� ���������� ����� ����� �������;