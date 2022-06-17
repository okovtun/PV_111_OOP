#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//					Consnructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//					Methods:
	virtual std::ostream& print(std::ostream& os/* = std::cout*/)const
	{
		return os << last_name << " " << first_name << " " << age << " years.\n";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(20);
		ofs << std::left;
		ofs << last_name + " " + first_name;
		ofs.width(4);
		ofs << std::right;
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		std::string buffer;
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}
std::istream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, year, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_year()const
	{
		return year;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//			Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	//					Methods:
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << "Специальность: " << speciality + " " + "Группа: " + group << " " << "Курс: " << year << " " << "Рейтинг: " << rating << " " << "Посещаемость: " << attendance << endl;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs) << " ";
		ofs.width(20);
		ofs << std::left;
		ofs << speciality;
		ofs.width(8);
		ofs << group << " " << year;
		ofs.width(8);
		ofs << std::right;
		ofs << std::setprecision(2) << std::fixed;
		ofs << rating << " " << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		ifs >> speciality;
		ifs >> group;
		ifs >> year;
		ifs >> rating;
		ifs >> attendance;
		return ifs;
	}
};

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//			Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//					Methods:
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << "Специальность: " << speciality + " " << "Опыт: " << experience << endl;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs) << " ";
		ofs.width(25);
		ofs << std::left;
		ofs << speciality;
		ofs.width(5);
		ofs << std::right;
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		//ifs >> speciality;
		const int n = 25;
		char speciality[n] = {};
		ifs.read(speciality, n);
		for (int i = n - 1; speciality[i] == ' '; i--)speciality[i] = 0;
		set_speciality(speciality);
		ifs >> experience;
		return ifs;
	}
};
class Graduate :public Student
{
	std::string diplom;
public:
	const std::string& get_diplom()const
	{
		return diplom;
	}
	void set_diplom(const std::string& diplom)
	{
		this->diplom = diplom;
	}

	//			Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, unsigned int year, double rating, double attendance,
		const std::string& diplom
	) :Student
	(
		last_name, first_name, age,
		speciality, group, year, rating, attendance
	)
	{
		set_diplom(diplom);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//					Methods:
	std::ostream& print(std::ostream& os)const
	{
		//Student::print(os);
		return Student::print(os) << "Тема диплома: " << diplom << endl;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Student::print(ofs) << " " << diplom;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, this->diplom);
		return ifs;
	}
};

Human* HumanFactory(const std::string& type)
{
	if (type.find("class Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0, 0);
	if (type.find("class Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, 0, "");
	if (type.find("class Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
}

Human** load(const std::string& filename, int& n)
{
	Human** group;	//массив
	//int n = 0;	//размер массива
	std::ifstream fin(filename);

	if (fin.is_open())
	{
		std::string buffer;
		//1) Определяем размер массива:
		while (!fin.eof())
		{
			std::getline(fin, buffer);
			n++;
		}
		n--;
		//2) Выделяем память для участников группы (создаем массив)
		group = new Human*[n] {};

		//3) Возвращаемся в начало файла:
		//cout << "Текущая позиция: " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		//cout << "Текущая позиция: " << fin.tellg() << endl;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin >> *group[i];
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
		return nullptr;
	}

	fin.close();
	return group;
}

//#define INHERITANCE_CHECK
//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK
	Human human("Montana", "Antonio", 25);
	human.print();

	Student pinkman("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 85);
	pinkman.print();

	Teacher teacher("Ivanov", "Ivan", 43, "Chemistry", 20);
	teacher.print();

	Graduate graduate("Sidorov", "Alexey", 22, "Programming", "WW_420", 4, 90, 45, "С++");
	graduate.print();
#endif // INHERITANCE_CHECK

#ifdef WRITE_TO_FILE
	//			Polymorphism
//(poly - много, morphis - форма) - 
//Ad-hoc polymorphism

//Inclusion polymorphism 
//(Runtime polymorphism) - Полиморфизм подтипов.

//Generalisation:
//Upcast - приведение к базовому типу
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 91.2, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistics", "WW_220", 5, 87.22, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Theft", "Vice", 3, 90, 85),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 20),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 100),
		new Teacher("Montana", "Antonio", 30, "Criminalistics", 3)
	};
	std::ofstream fout("Academy.txt");
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		//RTTI - Runtime Type Information
		cout << typeid(*group[i]).name() << endl;
		//group[i]->print();
		cout << *group[i] << endl;
		cout << "-------------------------------------------------\n";

		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;

	}
	fout.close();
	system("start notepad Academy.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
}
#endif // WRITE_TO_FILE

	int n = 0;
	Human** group = load("Academy.txt", n);

	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}

	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;
}