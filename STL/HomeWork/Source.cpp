#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<list>
#include<algorithm>
#include<Windows.h>

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------\n"

const std::map<size_t, std::string> crimes =
{
	{1, "ïðîåçä íà êðàñíûé"},
	{2, "ïðåâûøåíèå ñêîðîñòè"},
	{3, "åçäà ïî âñòðå÷íîé ïîëîñå"},
	{4, "äðèôò íà ïåðåêðåñòêå"},
	{5, "ïàðêîâêà â íåïîëîæåííîì ìåñòå"},
	{6, "îñêîðáëåíèå îôèöåðà"},
};

class Crime
{
	size_t id;
	std::string place;
public:
	size_t get_id()const
	{
		return id;
	}
	const std::string& get_place()const
	{
		return place;
	}
	Crime(size_t id, const std::string& place) :id(id), place(place) {}
	~Crime() {}

	bool operator==(const Crime& other)const
	{
		return this->id == other.id && this->place == other.place;
	}
	bool operator!=(const Crime& other)const
	{
		return this->id != other.id && this->place != other.place;
	}

};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	return os << crimes.at(obj.get_id()) << ", " << obj.get_place();
	//return os << crimes[obj.get_id()] << ", " << obj.get_place();
	//out_of_range exception
}

std::ofstream& operator<<(std::ofstream& ofs, const Crime& obj)
{
	ofs << obj.get_id() << " " << obj.get_place();
	return ofs;
}

void add(std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate);
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename);

void main()

{
	setlocale(LC_ALL, "");
	std::map<std::string, std::list<Crime>> base;
	load(base, "base.txt");
	load(base, "base.txt");
	load(base, "base.txt");
	print(base);

	std::string first_plate, last_plate;
	cout << "Ââåäèòå íà÷àëüíûé íîìåðíîé çíàê: "; cin >> first_plate;
	cout << "Ââåäèòå êîíå÷íûé íîìåðíîé çíàê: "; cin >> last_plate;
	print(base, first_plate, last_plate);
}

void add(std::map<std::string, std::list<Crime>>& base)
{
	std::string licence_plate;
	int id;
	std::string place;
	cout << "Ââåäèòå íîìåð àâòîìîáèëÿ: "; cin >> licence_plate;
	cout << "Ââåäèòå ïðàâîíàðóøåíèå (íîìåð ñòàòüè): "; cin >> id;
	cout << "Ââåäèòå ìåñòî ïðîèøåñòâèÿ: ";
	cin.clear();
	cin.ignore();
	std::getline(cin, place);
	std::map<std::string, std::list<Crime>>::iterator it = base.find(licence_plate);
	if (it != base.end())
	{
		it->second.push_back(Crime(id, place));
	}
	else
	{
		base.insert(std::pair<std::string, std::list<Crime>>(licence_plate, { Crime(id, place) }));
	}
}
void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
	{
		cout << it->first + ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << "\t" << *jt << ";\n";
		}
		cout << delimiter;
	}
}
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& licence_plate)
{
	try
	{
		cout << licence_plate << ":\n";
		for (
			std::list<Crime>::const_iterator it = base.at(licence_plate).begin();
			it != base.at(licence_plate).end();
			++it
			)
			cout << *it << endl;
	}
	catch (...)
	{
		std::cerr << "Â áàçå íåò òàêîãî íîìåðà" << endl;
	}
}
void print(const std::map<std::string, std::list<Crime>>& base, const std::string& first_plate, const std::string& last_plate)
{
	for (
		std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(first_plate);
		it != base.upper_bound(last_plate);
		++it
		)
	{
		cout << it->first << ":\n";
		for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			cout << *jt << endl;
		}
		cout << delimiter;
	}
}
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::pair<std::string, std::list<Crime>> i : base)
	{
		fout << i.first << ":\t";
		for (Crime j : i.second)
		{
			fout << j << ", ";
		}
		fout.seekp(-2, std::ios::cur);	//ñäâèãàåì êóðñîð íà 2 ïîçèöèè âëåâî
		fout << ";\n";
	}
	fout.close();
	std::string command = std::string("start notepad ") + filename;
	system(command.c_str());
	//c_str() âîçâðàùàåò C-string (NULL Terminated Line)
}
void load(std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			std::string licence_plate;
			int id;
			std::string place;
			std::string crimes;
			std::getline(fin, licence_plate, ':');
			std::getline(fin, crimes);
			if (crimes.empty())continue;
			char* sz_crimes = new char[crimes.size() + 1]{};
			std::strcpy(sz_crimes, crimes.c_str());
			char sz_delimiters[] = ",;";
			for (char* pch = strtok(sz_crimes, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
			{
				while (*pch == ' ')pch++;//Ïîêà ñòðîêà íà÷èíàåòñÿ ñ ñèìâîëà ' ', ñìåùàåì íà÷àëî ñòðîêè íà 1 ñèìâîë âðàâî.
				id = std::atoi(pch);	 //Áåðåì íîìåð ïðàâîíàðóøåíèÿ, ïðåîáðàçóåì åãî â öåëî÷èñëåííûé ôîðìàò (int), è ñîõðàíÿåì â id.
				pch = std::strchr(pch, ' ') + 1;
				if
					(
						std::find
						(
							base[licence_plate].begin(),
							base[licence_plate].end(),
							Crime(id, pch)
						) == base[licence_plate].end()
						)
					base[licence_plate].push_back(Crime(id, pch));
			}
			delete[] sz_crimes;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
}