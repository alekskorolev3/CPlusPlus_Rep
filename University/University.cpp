#include <iostream>
#include <vector>
#include <string>
using namespace std;
class University
{

public:
	string u_name;
	void setName(string name)
	{
		u_name = name;
	}
};
class Faculty : public University
{
public:
	string f_name;
	void add_faculty(University u)
	{
		u_name = u.u_name;
	}
	void setName(string name)
	{
		f_name = name;
	}
};
class Course : public Faculty
{
public:
	string c_name;
	void setName(string name)
	{
		c_name = name;
	}
	void add_course(Faculty f)
	{
		f_name = f.f_name;
		u_name = f.u_name;
	}
	void getCourse()
	{
		cout << c_name << " " << f_name << " " << u_name << endl;
	}
};
class Group : public Course
{
public:
	string g_name;
	void setName(string name)
	{
		g_name = name;
	}
	void add_group(Course c)
	{
		c_name = c.c_name;
		f_name = c.f_name;
		u_name = c.u_name;
	}
	void getGroup()
	{
		cout << g_name << " " << c_name << " " << f_name << " " << u_name << endl;
	}
};
class Student : public Group
{
public:
	string s_name;
	string s_surname;
	void setName(string name, string surname)
	{
		s_name = name;
		s_surname = surname;
	}
	void add_student(Group g)
	{
		g_name = g.g_name;
		c_name = g.c_name;
		f_name = g.f_name;
		u_name = g.u_name;
	}
	void getStudent()
	{
		cout << s_name << " " << s_surname << endl;
		cout << g_name << " " << c_name << " " << f_name << " " << u_name << endl;
	}

};
class Object : public University
{
public:
	string o_name;
	void setName(string name)
	{
		o_name = name;
	}
	void add_object(University u)
	{
		University::u_name = u.u_name;
	}
};
class Teacher : public Group, public Object
{
public:
	string t_name;
	string t_surname;
	void setName(string name, string surname)
	{
		t_name = name;
		t_surname = surname;
	}
	void add_teacher(Faculty f, Object o, Group g)
	{
		f_name = f.f_name;
		o_name = o.o_name;
		g_name = g.g_name;
	}
};

class Marks : public Student, public Object
{
public:
	string m_value;
	void setValue(string value)
	{
		m_value = value;
	}
	void add_mark(Student s, Object o)
	{
		s_name = s.s_name;
		s_surname = s.s_surname;
		o_name = o.o_name;
	}
	void getMark()
	{
		cout << m_value << " " << s_name << " " << o_name << endl;
	}
};
void printMenu()
{
	cout << endl;
	cout << "1. Добавить университет" << endl;
	cout << "2. Добавить факультет" << endl;
	cout << "3. Добавить курс" << endl;
	cout << "4. Добавить группу" << endl;
	cout << "5. Добавить студента" << endl;
	cout << "6. Добавить предмет" << endl;
	cout << "7. Добавить преподавателя" << endl;
	cout << "8. Добавить оценку" << endl;
	cout << "9. Посмотреть отличников группы" << endl;
	cout << "10. Посмотреть отличников курса" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	string name, surname;
	vector <University> u;
	int u_count = 0;
	vector <Faculty> f;
	int f_count = 0;
	vector <Course> c;
	int c_count = 0;
	vector <Group> g;
	int g_count = 0;
	vector <Student> s;
	int s_count = 0;
	vector <Object> o;
	int o_count = 0;
	vector <Teacher> t;
	int t_count = 0;
	vector <Marks> m;
	int m_count = 0;
	vector <Student> s1;
	int s1_count = 0;
	vector <Student> s2;
	int s2_count = 0;
	do
	{
		printMenu();
		cin >> choice;
		if (choice < 9)
		{
			system("cls");
		}
		switch (choice)
		{
		case 1:
			u.push_back(University());
			cout << "Введите название университета ";
			cin >> name;
			u[u_count].setName(name);
			u_count++;
			break;
		case 2:
			if (u.size())
			{
				for (int i = 0; i < u.size(); i++)
				{
					cout << i + 1 << ". " << u[i].u_name << endl;
				}
				int a;
				cin >> a;
				f.push_back(Faculty());
				cout << "Введите название факультета ";
				cin >> name;
				f[f_count].setName(name);
				a--;
				f[f_count].add_faculty(u[a]);
				f_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте университет " << endl;
				break;
			}
		case 3:
			if (f.size())
			{
				for (int i = 0; i < u.size(); i++)
				{
					cout << i + 1 << ". " << u[i].u_name << endl;
				}
				int a;
				cin >> a;
				for (int i = 0; i < f.size(); i++)
				{
					cout << i + 1 << ". " << f[i].f_name << endl;
				}
				cin >> a;
				a--;
				c.push_back(Course());
				cout << "Введите курс ";
				cin >> name;
				c[c_count].setName(name);
				c[c_count].add_course(f[a]);
				c_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте факультет " << endl;
				break;
			}
		case 4:
			if (c.size())
			{
				for (int i = 0; i < u.size(); i++)
				{
					cout << i + 1 << ". " << u[i].u_name << endl;
				}
				int a;
				cin >> a;
				for (int i = 0; i < f.size(); i++)
				{
					cout << i + 1 << ". " << f[i].f_name << endl;
				}
				cin >> a;
				for (int i = 0; i < c.size(); i++)
				{
					cout << i + 1 << ". " << c[i].c_name << endl;
				}
				cin >> a;
				a--;
				g.push_back(Group());
				cout << "Введите группу ";
				cin >> name;
				g[g_count].setName(name);
				g[g_count].add_group(c[a]);
				g_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте курс " << endl;
				break;
			}
		case 5:
			if (g.size())
			{
				for (int i = 0; i < u.size(); i++)
				{
					cout << i + 1 << ". " << u[i].u_name << endl;
				}
				int a;
				cin >> a;
				for (int i = 0; i < f.size(); i++)
				{
					cout << i + 1 << ". " << f[i].f_name << endl;
				}
				cin >> a;
				for (int i = 0; i < c.size(); i++)
				{
					cout << i + 1 << ". " << c[i].c_name << endl;
				}
				cin >> a;
				for (int i = 0; i < g.size(); i++)
				{
					cout << i + 1 << ". " << g[i].g_name << endl;
				}
				cin >> a;
				a--;
				s.push_back(Student());
				cout << "Введите имя студента ";
				cin >> name;
				cout << "Введите фамилию студента ";
				cin >> surname;
				s[s_count].setName(name, surname);
				s[s_count].add_student(g[a]);
				s_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте группу " << endl;
				break;
			}
		case 6:
			if (u.size())
			{
				for (int i = 0; i < u.size(); i++)
				{
					cout << i + 1 << ". " << u[i].u_name << endl;
				}
				int a;
				cin >> a;
				o.push_back(Object());
				cout << "Введите название предмета ";
				cin >> name;
				o[o_count].setName(name);
				a--;
				o[o_count].add_object(u[a]);
				o_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте университет " << endl;
				break;
			}
		case 7:
			if (f.size() && o.size() && g.size())
			{
				int a, b, c;
				for (int i = 0; i < u.size(); i++)
				{
					cout << i + 1 << ". " << u[i].u_name << endl;
				}
				cin >> a;
				for (int i = 0; i < f.size(); i++)
				{
					cout << i + 1 << ". " << f[i].f_name << endl;
				}
				cin >> a;
				a--;
				for (int i = 0; i < g.size(); i++)
				{
					cout << i + 1 << ". " << g[i].g_name << endl;
				}
				cin >> b;
				b--;
				for (int i = 0; i < o.size(); i++)
				{
					cout << i + 1 << ". " << o[i].o_name << endl;
				}
				cin >> c;
				c--;
				cout << "Введите имя студента ";
				cin >> name;
				cout << "Введите фамилию студента ";
				cin >> surname;
				t.push_back(Teacher());
				t[t_count].setName(name, surname);
				t[t_count].add_teacher(f[a], o[c], g[b]);
				t_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте факультет/предмет/группу " << endl;
				break;
			}
		case 8:
			if (s.size() && o.size())
			{
				int a, b, c;
				for (int i = 0; i < s.size(); i++)
				{
					cout << i + 1 << ". " << s[i].s_name << " " << s[i].s_surname << endl;
				}
				cin >> a;
				a--;
				for (int i = 0; i < o.size(); i++)
				{
					cout << i + 1 << ". " << o[i].o_name << endl;
				}
				cin >> b;
				b--;
				cout << "Введите оценку ";
				cin >> name;
				m.push_back(Marks());
				m[m_count].setValue(name);
				m[m_count].add_mark(s[a], o[b]);
				m_count++;
				break;
			}
			else
			{
				cout << "Ошибка. Сначала добавьте студента/предмет " << endl;
				break;
			}
		case 9:
			if (g.size() && s.size() && m.size())
			{
				int a;
				for (int i = 0; i < g.size(); i++)
				{
					cout << i + 1 << ". " << g[i].g_name << endl;
				}
				cin >> a;
				a--;
				
				int all_marks = 0, good_marks = 0;
				for (int i = 0; i < s.size(); i++)
				{
					if (s[i].g_name == g[a].g_name)
					{
						for (int j = 0; j < m.size(); j++)
						{
							if (m[j].s_name == s[i].s_name && m[j].s_surname == s[i].s_surname && o.size() >= 3)
							{
								all_marks++;
								if (stoi(m[j].m_value) >= 8)
								{
									good_marks++;
								}
							}
						}
						if (all_marks == good_marks)
						{
							s1.push_back(Student());
							s1[i].s_name = s[i].s_name;
							s1[i].s_surname = s[i].s_surname;
							s1_count++;
							all_marks = 0;
							good_marks = 0;
						}
						else
						{
							all_marks = 0;
							good_marks = 0;
						}
					}
				}
				for (int i = 0; i < s1.size(); i++)
				{
					cout << s1[i].s_name << " " << s1[i].s_surname << endl;
				}
				break;
			}
			else
			{
				cout << "Error" << endl;
				break;
			}
		case 10:
			if (c.size() && s.size() && m.size())
			{
				int a;
				for (int i = 0; i < c.size(); i++)
				{
					cout << i + 1 << ". " << c[i].c_name << endl;
				}
				cin >> a;
				a--;

				int all_marks = 0, good_marks = 0;
				for (int i = 0; i < s.size(); i++)
				{
					if (s[i].c_name == c[a].c_name)
					{
						for (int j = 0; j < m.size(); j++)
						{
							if (m[j].s_name == s[i].s_name && m[j].s_surname == s[i].s_surname && o.size() >= 3)
							{
								all_marks++;
								if (stoi(m[j].m_value) >= 8)
								{
									good_marks++;
								}
							}
						}
						if (all_marks == good_marks)
						{
							s2.push_back(Student());
							s2[i].s_name = s[i].s_name;
							s2[i].s_surname = s[i].s_surname;
							s2_count++;
							all_marks = 0;
							good_marks = 0;
						}
						else
						{
							all_marks = 0;
							good_marks = 0;
						}
					}
				}
				for (int i = 0; i < s2.size(); i++)
				{
					cout << s2[i].s_name << " " << s2[i].s_surname << endl;
				}
				break;
			}
			else
			{
				cout << "Error" << endl;
				break;
			}
		case 0:
			return 0;
		}

	} while (choice != 0);
}