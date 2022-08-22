//BinaryTree
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define DEBUG

#define tab "\t"
#define delimiter "\n------------------------------------------\n"

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :
			Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor\t" << this << endl;
#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()const
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			insert(*it, Root);
		}
	}
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void insert(int Data)
	{
		insert(Data, Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	int count()const
	{
		return count(Root);
	}
	int Sum()const
	{
		return Sum(Root);
	}
	double Avg()const
	{
		return (double)Sum(Root) / count(Root);
	}
	int depth()const
	{
		return depth(Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}

private:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	int minValue(Element* Root)const
	{
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		/*if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);*/
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int count(Element* Root)const
	{
		/*if (Root == nullptr)return 0;
		else return count(Root->pLeft) + count(Root->pRight) + 1;*/
		return Root == nullptr ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
	}
	int Sum(Element* Root)const
	{
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	int depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return
			depth(Root->pLeft) + 1 > depth(Root->pRight) + 1 ?
			depth(Root->pLeft) + 1 :
			depth(Root->pRight) + 1;
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
};

class UniqueTree :public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		int number = rand() % 100;
		//cout << number << tab;
		tree.insert(number);
	}
	cout << endl;
	tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
	cout << "Количество элементов в дереве: " << tree.count() << endl;
	cout << "Сумма элементов дерева: " << tree.Sum() << endl;
	cout << "Среднее-арифметическое элементов дерева: " << tree.Avg() << endl;
	cout << "Глубина дерева: " << tree.depth() << endl;

	UniqueTree unique_tree;
	for (int i = 0; i < n; i++)
	{
		int number = rand() % 100;
		//cout << number << tab;
		unique_tree.insert(number);
	}
	cout << endl;
	unique_tree.print();
	cout << endl;
	cout << "Минимальное значение в дереве: " << unique_tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << unique_tree.maxValue() << endl;
	cout << "Количество элементов в дереве: " << unique_tree.count() << endl;
	cout << "Сумма элементов дерева: " << unique_tree.Sum() << endl;
	cout << "Среднее-арифметическое элементов дерева: " << unique_tree.Avg() << endl;
	cout << "Глубина дерева: " << unique_tree.depth() << endl;

	Tree deep_tree = { 50, 25, 75, 16, 32, 64, 85, 48, 49 };
	deep_tree.print();
	cout << "Глубина дерева: " << deep_tree.depth() << endl;
}