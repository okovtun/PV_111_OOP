//Project:	ForwardList
//Solution:	DataContainers
#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;		//Значение элемента
	Element* pNext;	//Адрес следующего элементна
public:
	Element(int Data, Element* pNext) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
};

class ForwardList
{
	Element* Head;	//Голова списка
public:
	ForwardList()
	{
		Head = nullptr; //Когда Голова списка указывает на 0 - список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//				Adding Elements:
	void push_front(int Data)
	{
		//1) Создаем новый элемент:
		Element* New = new Element(Data);

	}
};

void main()
{
	setlocale(LC_ALL, "");

}