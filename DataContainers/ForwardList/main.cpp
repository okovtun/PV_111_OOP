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
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
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
		//2) Присоединяем новый элемент к началу списка:
		New->pNext = Head;
		//3) Говорим, что новый элемент является головой списка:
		Head = New;
	}
	void push_back(int Data)
	{
		
	}

	//				Methods:
	void print()const
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого 
		//можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	int arr[5];
	ForwardList list;	//Односвязный список list
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}