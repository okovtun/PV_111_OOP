//STL
#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<iterator>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//#define ARRAY
//#define VECTOR
//#define DEQUE

void main()
{
	setlocale(LC_ALL, "");

	typedef int DataType;

#ifdef ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	const int n = 5;
	std::array<int, n> arr = { 3,5,8,13,21 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // ARRAY

#ifdef VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	std::vector<DataType> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	try
	{
		for (int i = 0; i < vec.size() * 2; i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	vec.front() = 1024;
	for (std::vector<DataType>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	for (std::vector<DataType>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	cout << vec.front() << endl;
	cout << vec.back() << endl;

	cout << *(vec.data() + 4) << endl;
	cout << "\n ------------------ Vector capacity ------------------ \n";
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	vec.push_back(55);

	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	//vec.shrink_to_fit();	//уменьшает capacity до фактического размера
	vec.resize(8);			//принужительно задает размер вектора
	vec.reserve(55);		//задает capacity вектора, работает только на увеличение
	//vec.assign({ 1024, 2048, 3072, 4096, 5120 });
	for (int i : vec)cout << i << tab; cout << endl;
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	//std::vector<int>::iterator position = vec.begin() + index;
	if (index <= vec.size())
		vec.insert(vec.begin() + index, 3, value);
	for (int i : vec)cout << i << tab; cout << endl;
	cout << *(vec.end() - 1) << endl;
	//vec.insert(vec.begin() + 2, vec.end() - 2, vec.end());
	//for (int i : vec)cout << i << tab; cout << endl;
#endif // VECTOR

#ifdef DEQUE
	//deque - это контейнер, который хранит данные в виде списка векторов, 
	//это позволяет избежать переопределения памяти, и следовательно уведичить производительность
	//при добавлении/удалении элементов, но это так же снижает незначительно производительность 
	//при доступе к элементам контейнера.
	//В отличие от vector, deque позвлдяет добавлять элементы не только в конец, но и в начало контейнера.
	std::deque<DataType> deque = { 3,5,8,13,21 };
	for (std::deque<DataType>::iterator it = deque.begin(); it != deque.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i : deque)cout << i << tab; cout << endl;
	for (std::deque<DataType>::reverse_iterator it = deque.rbegin(); it != deque.rend(); ++it)
		cout << *it << tab;
	cout << endl;
#endif // DEQUE

	std::list<int> list = { 3,5,8,13,21 };
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		cout << *it << tab;
	cout << endl;
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position++;
	std::advance(position, index);
	list.insert(position, value);
	for (int i : list)cout << i << tab; cout << endl;
}