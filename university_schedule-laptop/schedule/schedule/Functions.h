#include "Structs.h"
#include "iomanip"
/*************************************************************************
*                                                                        *
*           КУРСОВАЯ РАБОТА по дисциплине ПРОГРАММИРОВАНИЕ               *
*                                                                        *
**************************************************************************
*Project type : Visual Studio Solution                                   *
*Project name : Курсач                                                   *
*File name    : main.cpp                                                 *
*Language     : CPP, MSVS 2022                                           *
*Programmer   : Чиняков Игорь Павлович, М3О-210Б-22                      *
*Modified by  :                                                          *
*Created      : 20.12.2023                                               *
*Last revision: 26.12.2023                                               *
*Comment      : Списочные базы данных    					             *
*************************************************************************/

//Элементы для построения таблицы
const char VerticalLine = (char)186;//"║" - ВЕРТИКАЛЬНАЯ ЛИНИЯ
const char HorizontalLine = (char)205;//"═" - ГОРИЗОНТАЛЬНАЯ ЛИНИЯ
const char TopLeftCorner = (char)201;//"╔" - ЛЕВЫЙ ВЕРХНИЙ УГОЛ
const char TopRightCorner = (char)187;//"╗" - ПРАВЫЙ ВЕРХНИЙ УГОЛ
const char BottomLeftCorner = (char)200;//"╚" - ЛЕВЫЙ НИЖНИЙ УГОЛ
const char BottomRightCorner = (char)188;//"╝" - ПРАВЫЙ НИЖНИЙ УГОЛ
const char LeftJunction = (char)185;//"╣" - ПОВОРОТ ВЛЕВО
const char RightJunction = (char)204;//"╠" - ПОВОРОТ ВПРАВО
const char BottomJunction = (char)203;//"╦" - ПОВОРОТ ВНИЗ
const char TopJunction = (char)202;//"╩" - ПОВОРОТ ВВЕРХ
const char CrossJunction = (char)206;//"╬" - ПЕРЕКРЕСТОК
const char Space = (char)32;//Пробел

//************************************************************************
//*                     ПРОТОТИПЫ ФУНКЦИЙ                                *
//************************************************************************

//Функция считывания кафедр из файла
void read_departments(string file_name, //имя файла
	int& error_code, //код ошибки
	Department*& begin_department, //указатель на первый элемент кафедр
	Department*& end_department); //указатель на последний элемент кафедр

//Функция считывания групп из файла
void read_groups(string file_name, //имя файла
	int& error_code, //код ошибки
	Group*& begin_group, //указатель на первый элемент групп
	Group*& end_group,//указатель на последний элемент кафедр
	Department*& begin_department); //указатель на первый элемент кафедр

//Функция считывания преподавателей из файла
void read_lecturers(string file_name, //имя файла
	int& error_code,//код ошибки
	Lecturer*& begin_lecturer,//указатель на первый элемент преподавателей
	Lecturer*& end_lecturer,//указатель на последний элемент преподавателей
	Department*& begin_department);//указатель на первый элемент кафедр

//Функция считывания расписаний из файла
void read_schedules(string file_name, //имя файла
	int& error_code, //код ошибки
	Schedule*& begin_schedule, //указатель на первый элемент расписаний
	Schedule*& end_schedule, //указатель на последний элемент расписаний
	Group*& begin_group, //указатель на первый элемент групп
	Lecturer*& begin_lecturer,//указатель на первый элемент преподавателей
	Subject* begin_subject,//указатель на первый элемент предметов
	ClassRoom*& begin_class_room);//указатель на первый элемент аудиторий

//Функция считывания предметов из файла
void read_subjects(string file_name, //имя файла
	int& error_code, //код ошибки
	Subject*& begin_subject, //указатель на первый элемент предметов
	Subject*& end_subject);//указатель на последний элемент предметов

//Функция считывания аудиторий из файла
void read_class_rooms(string file_name, //имя файла
	int& error_code, //код ошибки
	ClassRoom*& begin_class_room, //указатель на первый элемент аудиторий
	ClassRoom*& end_class_room);//указатель на последний элемент аудиторий

//Функция проверки полей даты
void check_date_fields(int year_int, //год 
	int& error_code, //код ошибки
	int minute_int, //минута
	int hour_int, //час
	int month_int, //месяц
	int day_int);//день

//Функция проверки файла 
void check_file(string file_name, //название файла
	int& error_code); //код ошибки

//Функция вставки кафедры
void insert_department(string name, //название
	int& error_code, //код ошибки
	Department*& begin_department, //указатель на первый элемент кафедр
	Department*& end_department); //указатель на последний элемент кафедр

//Функция вставки преподавателя
void insert_lecturer(string name, //имя
	int department_id, //id кафедры
	int& error_code, //код ошибки
	Lecturer*& begin_lecturer, //указатель на первый элемент преподавателей
	Lecturer*& end_lecturer, //указатель на последний элемент преподавателей
	Department*& begin_department); //указатель на первый элемент кафедр

//Функция вставки группы
void insert_group(int department_id, //id кафедры
	int id, //номер группы
	int& error_code, // код ошибки
	Group*& begin_group, //указатель на первый элемент групп
	Group*& end_group, //указатель на последний элемент преподавателей
	Department*& begin_department); //указатель на первый элемент кафедр

//Функция вставки расписания
void insert_schedule(Subject* subject, //название предмета
	int group_id, //id группы
	int lecturer_id, //id преподавателя
	int class_room_id, //id класса
	int& error_code, //код ошибки
	Date date, //дата
	Schedule*& begin_schedule, //указатель на первый элемент расписаний
	Schedule*& end_schedule, //указатель на последний элемент расписаний
	Group*& begin_group, //указатель на первый элемент групп
	Lecturer*& begin_lecturer, //указатель на первый элемент преподавателей
	Subject*& begin_subject,//указатель на первый элемент предметов
	ClassRoom*& begin_class_room); //указатель на первый элемент аудиторий

//Функция вставки предмета
void insert_subject(string name, //название
	int& error_code, //код ошибки
	Subject*& begin_subject, //указатель на первый элемент предметов
	Subject*& end_subject);//указатель на последний элемент предметов

//Функция вставки аудитории
void insert_class_room(int id, //номер
	int& error_code, //код ошибки
	ClassRoom*& begin_class_room, //указатель на первый элемент аудиторий
	ClassRoom*& end_class_room);//указатель на последний элемент аудиторий

//Функция поиска кафедры по id
Department* find_department_by_id(int id, //id
	Department*& begin_department); //указатель на первый элемент кафедр

//Функция поиска кафедры по имени
Department* find_department_by_name(string name, //название
	Department*& begin_department); //указатель на первый элемент кафедр

//Функция поиска предмета по имени
Subject* find_subject_by_name(string name, //название
	Subject*& begin_subject);//указатель на первый элемент предметов

//Функция поиска предмета по id
Subject* find_subject_by_id(int subject_id,  //id предмета
	Subject*& begin_subject); //указатель на первый элемент предметов

//Функция поиска аудитории по id
ClassRoom* find_class_room_by_id(int class_room_id, //id аудитории
	ClassRoom*& begin_class_room);//указатель на первый элемент аудиторий

//Функция поиска группы по id
Group* find_group_by_id(int id, //id
	Group*& begin_group); //указатель на первый элемент групп

//Функция поиска групп по id кафедры
Group* find_groups_by_department_id(int department_id, //id кафедры
	Group*& begin_group); //указатель на первый элемент групп

//Функция поиска преподавателя по id
Lecturer* find_lecturer_by_id(int id, //id
	Lecturer*& begin_lecturer); //указатель на первый элемент преподавателей

//Функция поиска преподавателей по имени
Lecturer* find_lecturers_by_name(string name, //имя
	Lecturer*& begin_lecturer); //указатель на первый элемент преподавателей

//Функция поиска преподавателей по id кафедры
Lecturer* find_lecturers_by_department_id(int department_id, //id кафедры
	Lecturer*& begin_lecturer); //указатель на первый элемент преподавателей

//Функция поиска расписания по id
Schedule* find_schedule_by_id(int id, //id
	Schedule*& begin_schedule); //указатель на первый элемент расписаний

//Функция поиска расписания по дате
Schedule* find_schedule_by_date(string hour, //час
	string minute, //минута
	string day, //день
	string month, //месяц
	string year,  //год
	Schedule*& begin_schedule); //год

//Функция проверки символа на цифру
bool is_digit(char symbol); //символ

//Функция печати кафедр
void print_departments(Department* department); //кафедра

//Функция печати групп
void print_groups(Group* group); //группа

//Функция печати преподавателей
void print_lecturers(Lecturer* lecturer); //преподаватель

//Функция печати расписаний
void print_schedules(Schedule* schedule, //расписание
	Lecturer*& begin_lecturer, //указатель на первый элемент преподавателей
	Subject* begin_subject);  //указатель на первый элемент предметов

void print_subjects(Subject* subject);//указатель на первый элемент предметов

void print_class_rooms(ClassRoom* class_room);//указатель на первый элемент аудиторий

//Функция получения id группы рапсиания
int get_schedule_group_id(Schedule* schedule);//указатель на первый элемент расписаний

//Функция получения id преподавателя расписания
int get_schedule_lecturer_id(Schedule* schedule);//указатель на первый элемент расписаний

//Функция получения id класса расписания
int get_schedule_class_room_id(Schedule* schedule);//указатель на первый элемент расписаний

//Функция получения названия предмета расписания
int get_schedule_subject_id(Schedule* schedule);//указатель на первый элемент расписаний

//Функция проверки даты
void check_date(string str_date, //параметры даты
	int& error_code, //код ошибки
	int& hour_int, //час в формате int
	int& minute_int, //минута в формате int
	int& day_int, //день в формате int
	int& month_int, //месяц в формате int
	int& year_int,//год в формате int
	string& year, //год в формате string
	string& minute, //минута в формате string
	string& hour, //час в формате string
	string& month, //месяц в формате string
	string& day);//день в формате string

//Функция перезаписи файла с кафедрами
void write_departments(string file_name, //имя файла
	Department*& begin_department);//указатель на первый элемент кафедр

//Функция перезаписи файла с группами
void write_groups(string file_name, //имя файла
	Group*& begin_group);//указатель на первый элемент групп

//Функция перезаписи файла с преподавателями
void write_lecturers(string file_name, //имя файла
	Lecturer*& begin_lecturer);//указатель на первый элемент преподавателей

//Функция перезаписи файла с рапсианиями
void write_schedules(string file_name, //имя файла
	Schedule*& begin_schedule);//указатель на первый элемент расписаний

void write_subjects(string file_name, //имя файла
	Subject* begin_subject);//указатель на первый элемент предметов

void write_class_rooms(string file_name, //имя файла
	ClassRoom* begin_class_room);//указатель на первый элемент аудиторий

//Функция удаления всех расписаний по заданным параметрам
void remove_all_schedules_by_parameter(int parameter, //параметр
	int(*function)(Schedule*), //функция получения параметра расписания
	Schedule*& begin_schedule, //указатель на первый элемент расписаний
	Schedule*& end_schedule);  //указатель на последний элемент расписаний

//Функция удаления всех расписаний по id кафедры
void remove_all_lecturers_by_department_id(int department_id, //id кафедры
	Lecturer*& begin_lecturer, //указатель на первый элемент преподавателей
	Lecturer*& end_lecturer, //указатель на последний элемент преподавателей
	Schedule*& begin_schedule, //указатель на первый элемент расписаний
	Schedule*& end_schedule);//указатель на последний элемент расписаний

//Функция удаления всех групп по id кафедры
void remove_all_groups_by_department_id(int department_id, //id кафедры
	Group*& begin_group, //указатель на первый элемент групп
	Group*& end_group, 	 //указатель на последний элемент групп
	Schedule*& begin_schedule, //указатель на первый элемент расписаний
	Schedule*& end_schedule);  //указатель на последний элемент расписаний

//Функция очистки списка задданного типа
template<typename T>
void clear_list(T*& start, //начальный элемент
	T*& end)//конечный элемент
{
	//проверка на пустоту списка
	if (start == nullptr)
	{
		cout << "Список пуст." << endl;
		return;
	}
	T* current = start;
	T* previous = end;

	//проверка, имеется ли в списке только один элемент
	if (current == previous)
	{
		delete start;
		start = nullptr;
		end = nullptr;
		return;
	}

	//цикл, пока начальный элемент не удален
	do
	{
		//удаление первого элемента
		current = start;
		start->previous->next = start->next;
		start->next->previous = start->previous;
		start = start->next;
		if (current == start)
			start = nullptr;
		delete current;
	} while (start != nullptr);
}

//Функция удаления элемента из списка
template<typename T>
void remove_element_from_list(T*& start, //начальный элемент
	T*& end, //конечный элемент
	int id)//id элемента
{
	//проверка на пустоту списка
	if (start == nullptr)
	{
		cout << "Список пуст." << endl;
		return;
	}

	T* current = start;
	T* previous = end;

	//проверка, имеется ли в списке только один элемент
	if (current == previous)
	{
		//проверка, является ли этот элемент искомым
		if (current->id == id)
		{
			delete start;
			start = nullptr;
			end = nullptr;
			cout << "Элемент удален из списка." << endl;
			return;
		}
	}

	//цикл, пока не перебраны все элементы списка 
	do
	{
		//проверка, является ли элемент искомым
		if (current->id == id)
		{
			//проверка, является ли этот элемент начальным
			if (current == start)
			{
				start = current->next;
				end->next = current->next;
				delete current;
				cout << "Элемент удален из списка." << endl;
				current = nullptr;
				return;
			}
			//проверка, является ли этот элемент конечным
			if (current == end)
			{
				end = current->previous;
				end->next = current->next;
				delete current;
				cout << "Элемент удален из списка." << endl;
				current = nullptr;
				return;
			}

			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete current;
			cout << "Элемент удален из списка." << endl;
			return;
		}

		current = current->next;
	} while (current != start || current != nullptr);

	cout << "Элемент не найден." << endl;
}

//Функция нахождения расписания по заданным параметрам
template<typename T>
Schedule* find_schedule_by_parameters(T parameter, //параметр
	T(*function)(Schedule*), Schedule*& begin_schedule, Schedule*& end_schedule)//функция получения поля структуры
{
	//Объявление переменных
	Schedule* schedule = begin_schedule;

	if (schedule == nullptr)
		return nullptr;

	Schedule* temp = new Schedule(schedule->subject_id,
		schedule->id,
		schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
	temp->next = nullptr;
	temp->previous = nullptr;
	Schedule* begin_temp = temp;

	//Цикл, пока не перебраны все элементы списка
	do
	{
		//проверка, является ли элемент искомым
		if (function(schedule) == parameter)
		{
			//добавление нового элемента в новый список
			temp->next = new Schedule(schedule->subject_id,
				schedule->id,
				schedule->group_id, schedule->lecturer_id, schedule->class_room_id, schedule->date_of_lesson);
			begin_temp->previous = temp->next;
			temp->next->previous = temp;
			temp = temp->next;
		}
		//переход к следующему элменту списка
		schedule = schedule->next;
	} while (schedule != begin_schedule);

	//Проверка, если не найден ни один элемент
	if (temp->next == nullptr)
	{
		//Удаление первого элемента нового списка
		delete temp;
		return nullptr;
	}
	//Удаление первого элемента нового списка
	temp->next = begin_temp->next;
	begin_temp->next->previous = temp;
	begin_temp = begin_temp->next;

	return begin_temp;
}