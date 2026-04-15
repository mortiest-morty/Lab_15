#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <set>
#include <sstream> 


// проверка ввода числа и строки
int getNumber();
bool getText(std::string str);


// =========== Класс: Имена ===========
class names {
private:
	std::string secondname;
	std::string name;
	std::string surname;

public:
	// Конструкторы 
	names(const std::string& s = "", const std::string& n = "", const std::string& sn = "") : secondname(s), name(n), surname(sn) {};
	names(const names& other) : secondname(other.secondname), name(other.name), surname(other.surname) {};
	

	//создание строки из имени, фамилии и отчества
	std::string toStr() const{
		std::string fullName;
		if (!isEmpty(secondname)) fullName += secondname + " ";
		if (!isEmpty(name)) fullName += name + " ";
		if (!isEmpty(surname)) fullName += surname + " ";
		
		return fullName;
	}


	// геттеры
	std::string getSecondName() const { return secondname;};
	std::string getName() const { return name;};
	std::string getSurname() const { return surname;};


	// проверка на пустоту
	bool isEmpty(std::string s) const {
		return s == "";
	}

	// ввод 2 способами
	static std::vector<names> input();

	// вывод
	void print() const {
		std::cout << toStr();
	};

};

// вывод всех имен
void showNames(std::vector<names> all);



// =========== Класс: Время ===========
class timer {
private:
	int seconds;
public:
	// Конструкторы 
	timer(int s = 0) : seconds(s) {};
	timer(const timer& other) : seconds(other.seconds) {};


	//создание строки 
	std::string toStr() const{
		int second = seconds;

		while (second > 86400) {
			second -= 86400;
		}

		std::string showTime;
		std::string hour = std::to_string(second / 3600);
		std::string minutes = std::to_string(second % 3600 / 60);
		std::string sec = std::to_string(second % 3600 % 60);

		if (!isEmpty(hour)) showTime += hour + ":";
		else showTime += "00:";
		if (!isEmpty(minutes)) showTime += minutes + ":";
		else showTime += "00:";
		if (!isEmpty(hour)) showTime += sec;
		else showTime += "00";

		return showTime;
	}


	// геттеры
	int getSeconds() const { return seconds; };


	// проверка на пустоту
	bool isEmpty(std::string s) const{
		return s == "";
	}

	// ввод 2 способами
	static std::vector<timer> input();

	// вывод
	void print() const {
		std::cout << "\nВремя: " << toStr();
	};

};

// вывод всего времени
void showTimes(std::vector<timer> clock);

// =========== Класс: Сотрудники и отделы ===========
class stuff {
private:
	std::string name;
	std::string department;
	std::string boss;

public:
	// Конструкторы 
	stuff(const std::string& n = "", const std::string& d = "", const std::string& b = "") : name(n), department(d), boss(b) {};
	stuff(const stuff& other) = default;


	//создание строки
	std::string toStr() const {
		std::string job;
		if (!isEmpty(name) && !isEmpty(boss) && name == boss) job += name + " является начальником отдела "+ department;
		else if (!isEmpty(name) && !isEmpty(boss) && name != boss) job += name + " работает в отделе " + department + ", начальник которого " + boss;
		else if (isEmpty(boss)) job += name + " работает в отделе " + department;
		return job;
	}

	//выбор начальника 
	void chooseBoss(std::string b) {
		boss = b;
	}

	// геттеры
	std::string getName() const { return name; };
	std::string getDepartment() const { return department; };
	std::string getBoss() const { return boss; };

	// сеттеры
	

	// проверка на пустоту
	bool isEmpty(std::string s) const {
		return s == "";
	}

	// ввод 2 способами
	static std::vector<stuff> input();

	// вывод 1 сотрудника
	void print() const {
		std::cout << toStr() << std::endl;
	};

};

void show1(std::vector<stuff> STUFF);			// вывод всех сотрудников для задания 2
void show(std::vector<stuff> STUFF, stuff shh); // вывод всех сотрудников для задания 3


// =========== Класс: Время 2.0 ===========
class timer2 {
private:
	int hours;
	int min;
	int seconds;
public:
	// Конструкторы 
	timer2(int s = 0, int h = 0, int m = 0) : hours(h), min(m), seconds(s) {};
	timer2(const timer2& other) : seconds(other.seconds), hours(other.hours), min(other.min) {};


	//создание строки 
	std::string toStr() const {
		int second = seconds, minute = min, hour = hours;
		std::string showTime;

		if (hours == 0 && min == 0) {
			while (second > 86400){
				second -= 86400;
			}

			std::string hour = std::to_string(second / 3600);
			std::string minutes = std::to_string(second % 3600 / 60);
			std::string sec = std::to_string(second % 3600 % 60);

			if (!isEmpty(hour)) showTime += hour + ":";
			else showTime += "00:";
			if (!isEmpty(minutes)) showTime += minutes + ":";
			else showTime += "00:";
			if (!isEmpty(hour)) showTime += sec;
			else showTime += "00";
		}

		else{
			while (second > 59) {
				second -= 60;
				minute += 1;
			}
			while (minute > 59) {
				minute -= 60;
				hour += 1;
			}
			while (hour > 23) {
				hour -= 24;
			}
			showTime += std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
		}

		return showTime;
	}

	//преобразование времени в нормальный вид
	void normalizeTime() {
			while (seconds > 86400) {
				seconds -= 86400;
			}

			while (seconds > 59) {
				min += 1;
				seconds -= 60;
			}

			while (min > 59) {
				min -= 60;
				hours += 1;
			}
			while (hours > 23) {
				hours -= 24;
			}
	}


	// геттеры
	int getSeconds() const{ return seconds; };
	int getHours() const { return hours; };
	int getMin() const { return min; };


	// проверка на пустоту
	bool isEmpty(std::string s) const {
		return s == "";
	}

	// ввод 2 способами
	static std::vector<timer2> input();


	void print() const {	// вывод
		std::cout << "\nВремя: " << toStr();
	};
	void print2() const {	// вывод 2.0
		std::cout << toStr(); 
	};

	// вывод текущего времени для задания 5
	void whatTimeIsIt();
};

//меню для задания 5
void menu5(std::vector<timer2> clock, std::vector<timer2> pupupu, std::vector<timer2> test);

// Задачи
void task_1();
void task_2_and_3();
void task_3();
void task_4();
void task_5();


#endif
