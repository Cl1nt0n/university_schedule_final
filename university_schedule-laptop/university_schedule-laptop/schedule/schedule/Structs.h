/*************************************************************************
*                                                                        *
*           �������� ������ �� ���������� ����������������               *
*                                                                        *
**************************************************************************
*Project type : Visual Studio Solution                                   *
*Project name : ������                                                   *
*File name    : main.cpp                                                 *
*Language     : CPP, MSVS 2022                                           *
*Programmer   : ������� ����� ��������, �3�-210�-22                      *
*Modified by  :                                                          *
*Created      : 20.12.2023                                               *
*Last revision: 26.12.2023                                               *
*Comment      : ��������� ���� ������    					             *
*************************************************************************/
#include "fstream"
#include "iostream"
#include "string"
using namespace std;

//************************************************************************
//*                           ���������                                  *
//************************************************************************
//��������� �������
struct Department
{
	int id;			// ����� �������
	string name;    // �������� �������
	Department* next;//��������� �� ��������� �������
	Department* previous;//��������� �� ���������� �������

	//������������
	Department(string name)
	{
		this->name = name;
	}
};

//��������� ������
struct Group
{
	int id;//����� ������
	int department_id;//id �������
	Group* next;//��������� �� ��������� ������
	Group* previous;//��������� �� ���������� ������

	//�����������
	Group(int department_id, int id)
	{
		this->id = id;
		this->department_id = department_id;
	}
};

//���������� ����
struct Date
{
	string hour;//���
	string minute;//������
	string day;//����
	string month;//�����
	string year;//���
};

//��������� ����������
struct Schedule
{
	int id;//id ����������
	int group_id;//����� ������
	int lecturer_id;//id �������������
	int class_room_id;//����� ���������
	int subject_id;//�������� ��������
	Date date_of_lesson;//���� ����������
	Schedule* next;//��������� �� ��������� ����������
	Schedule* previous;//��������� �� ���������� ����������

	//�����������
	Schedule(int subject_id, int group_id, int lecturer_id, int class_room_id, Date date)
	{
		date_of_lesson = date;
		this->subject_id = subject_id;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
	}

	//�����������
	Schedule(int subject_id, int id, int group_id, int lecturer_id, int class_room_id, Date date)
	{
		date_of_lesson = date;
		this->subject_id = subject_id;
		this->group_id = group_id;
		this->lecturer_id = lecturer_id;
		this->class_room_id = class_room_id;
		this->id = id;
	}
};

//��������� �������������
struct Lecturer
{
	int id;//id �������
	int department_id;//id �������
	string name;//��� �������������
	Lecturer* next;
	Lecturer* previous;

	//�����������
	Lecturer(string name, int department_id)
	{
		this->name = name;
		this->department_id = department_id;
	}

	//�����������
	Lecturer(string name, int department_id, int id)
	{
		this->name = name;
		this->department_id = department_id;
		this->id = id;
	}
};

struct Subject
{
	int id;
	string name;
	Subject* next;
	Subject* previous;

	Subject(string name)
	{
		this->name = name;
	}
};

struct ClassRoom
{
	int id;
	ClassRoom* next;
	ClassRoom* previous;

	ClassRoom(int id)
	{
		this->id = id;
	}
};

