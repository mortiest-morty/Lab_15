# include "Header.h"

// ======================= ПРОВЕРКА ВВОДА =======================

// проверка ввода числа 
int getNumber() {
	using namespace std;
	int value;

	while (true) {
		cout << "Введите число: ";
		cin >> value;

		if (cin.fail() || value < 0) {  // Если ввод не является числом
			cout << "Ошибка! Введите натуральное число!" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return value;
		}
	}
}

// проверка ввода строки
bool getText(std::string str) {
	using namespace std;
	string input = str;
	bool hasDigit;

	hasDigit = false;

	for (int i = 0; i < input.length(); i++) {
		if (isdigit(input[i])) {  // если символ - цифра
			hasDigit = true;
			break;
		}
	}

	if (hasDigit) {
		cout << "Ошибка! В тексте не должно быть цифр!" << endl;
		return false;
	}

}


// ======================= КЛАСС: ИМЕНА =======================

// ввод 2 способами
std::vector<names> names::input() {
	using namespace std;
	vector<names> result;
	int inputt = 0;

	cout << "\n===== Ввод ФИО =====" << endl;
	cout << "Доступные способы:\n 1 - c консоли\n 2 - из файла" << endl;
	inputt = getNumber();

	while (inputt < 1 || inputt > 2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		inputt = getNumber();
	}

	switch (inputt) {
	case 1: {
		int num = 0;
		cout << "\nСколько имён хотите ввести?\n";
		num = getNumber();

		for (int i = 0; i < num; i++) {
			string s, n, sn;

			cout << "Введите имя: ";
			getline(cin, n);
			while (n.empty() || !getText(n)) {
				if (n.empty()) {
					cout << "Имя обязательно для ввода!\n";
				}
				else {
					cout << "Ошибка! Имя должно содержать только буквы.\n";
				}
				cout << "Введите имя: ";
				getline(cin, n);
			}

			cout << "Введите фамилию: ";
			getline(cin, s);
			if (!s.empty()) {
				while (!getText(s)) {
					cout << "Ошибка! Фамилия должна содержать только буквы.\n";
					cout << "Введите фамилию: ";
					getline(cin, s);
					if (s.empty()) break;
				}
			}

			cout << "Введите отчество: ";
			getline(cin, sn);
			if (!sn.empty()) {
				while (!getText(sn)) {
					cout << "Ошибка! Отчество должно содержать только буквы.\n";
					cout << "Введите отчество: ";
					getline(cin, sn);
					if (sn.empty()) break;
				}
			}

			result.push_back(names(s, n, sn));
		}
		break;
	}

	case 2: {
		string filename;
		cout << "Введите имя файла: ";
		getline(cin, filename);

		filename.erase(0, filename.find_first_not_of(" \t"));
		filename.erase(filename.find_last_not_of(" \t") + 1);

		while (!getText(filename)) {
			cout << "Ошибка! Введите имя файла: ";
			getline(cin, filename);
		}

		ifstream file(filename);
		if (!file.is_open()) {
			cout << "\nОшибка открытия файла!\n";
			return result;
		}

		string secondname, name, surname;
		while (file >> secondname >> name >> surname) {
			result.push_back(names(secondname, name, surname));
		}

		file.close();
		cout << "\nУспешно загружено " << result.size() << " человек из файла\n";
		break;
	}
	}

	return result;
}

// вывод всех имен
void showNames(std::vector<names> all) {
	using namespace std;
	int output;

	cout << "\n======= Вывод =======" << endl;

	cout << "Доступные способы:\n 1 - в консоль\n 2 - в файл" << endl;
	output = getNumber();

	while (output < 1 || output>2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		output = getNumber();
	}

	switch (output) {
	case 1:
		for (names i : all) {
			cout << "\nПолное имя: ";
			i.print();
			cout << endl;
		}
		break;
	case 2:
		string filename;

		cout << "Введите имя файла: ";
		getline(cin, filename);
		bool t = getText(filename);

		while (!t) {
			cout << "Введите имя файла: ";
			getline(cin, filename);
			t = getText(filename);
		}

		ofstream file(filename);

		if (file.is_open()) {
			for (names i : all) {
				file << "Полное имя: " << i.toStr() << endl;
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}
		file.close();

		break;
	}
}

// ======================= КЛАСС: ВРЕМЯ =======================

// ввод 2 способами
std::vector<timer> timer::input() {
	using namespace std;
	vector<timer> result;  
	int inputt = 0;

	cout << "\n===== Ввод времени =====" << endl;
	cout << "Доступные способы:\n 1 - c консоли\n 2 - из файла" << endl;
	inputt = getNumber();

	while (inputt < 1 || inputt > 2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		inputt = getNumber();
	}

	switch (inputt) {
	case 1: {  
		int num = 0;
		cout << "\nСколько значений времени хотите ввести?\n";
		num = getNumber();

		for (int i = 0; i < num; i++) {
			int seconds = 0;

			cout << "\n===== Ввод времени =====\n";
			seconds = getNumber();

			while (seconds < 0) {
				cout << "Ошибка! Время не может быть отрицательным!\n";
				cout << "Введите время в секундах: ";
				seconds = getNumber();
			}

			result.push_back(timer(seconds));
		}
		break;
	}

	case 2: {  
		string filename;
		cout << "Введите имя файла: ";
		getline(cin, filename);

		filename.erase(0, filename.find_first_not_of(" \t"));
		filename.erase(filename.find_last_not_of(" \t") + 1);

		while (!getText(filename)) {
			cout << "Ошибка! Введите имя файла: ";
			getline(cin, filename);
		}

		ifstream file(filename);
		if (!file.is_open()) {
			cout << "\nОшибка открытия файла!\n";
			return result;
		}

		int seconds;
		while (file >> seconds) {
			if (seconds >= 0) {  
				result.push_back(timer(seconds));
			}
		}

		file.close();
		cout << "\nУспешно загружено " << result.size() << " значений времени из файла\n";
		break;
	}
	}

	return result;
}

// вывод всего времени
void showTimes(std::vector<timer> clock) {
	using namespace std;
	int output;

	cout << "\n======= Вывод =======" << endl;

	cout << "Доступные способы:\n 1 - в консоль\n 2 - в файл" << endl;
	output = getNumber();

	while (output < 1 || output>2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		output = getNumber();
	}

	switch (output) {
	case 1:
		for (timer i : clock) {
			i.print();
		}
		break;
	case 2:
		string filename;

		cout << "Введите имя файла: ";
		getline(cin, filename);
		bool t = getText(filename);

		while (!t) {
			cout << "Введите имя файла: ";
			getline(cin, filename);
			t = getText(filename);
		}

		ofstream file(filename);

		if (file.is_open()) {
			for (timer i : clock) {
				file << "Время: " << i.toStr() << endl;
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}
		file.close();

		break;
	}
}

// ======================= КЛАСС: СОТРУДНИКИ И ОТДЕЛЫ =======================

// ввод 2 способами
std::vector<stuff> stuff::input() {
	using namespace std;
	vector<stuff> result;
	int inputt = 0;

	cout << "===== Ввод сотрудников =====" << endl;
	cout << "Доступные способы:\n 1 - c консоли\n 2 - из файла" << endl;
	inputt = getNumber();

	while (inputt < 1 || inputt > 2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		inputt = getNumber();
	}

	switch (inputt) {
	case 1: {
		int num = 0;
		cout << "\nСколько сотрудников хотите ввести?\n";
		num = getNumber();

		for (int i = 0; i < num; i++) {
			string name, department;

			cout << "Введите имя сотрудника: ";
			getline(cin, name);
			while (!getText(name)) {
				cout << "Ошибка! Введите имя сотрудника: ";
				getline(cin, name);
			}

			cout << "Введите название отдела: ";
			getline(cin, department);
			while (!getText(department)) {
				cout << "Ошибка! Введите название отдела: ";
				getline(cin, department);
			}
			result.push_back(stuff(name, department));
		}
		break;
	}

	case 2: {
		string filename;
		cout << "Введите имя файла: ";
		getline(cin, filename);  

		filename.erase(0, filename.find_first_not_of(" \t"));
		filename.erase(filename.find_last_not_of(" \t") + 1);

		while (!getText(filename)) {
			cout << "Ошибка! Введите имя файла: ";
			getline(cin, filename);
		}

		ifstream file(filename);
		if (!file.is_open()) {
			cout << "\nОшибка открытия файла!\n";
			return result;
		}

		string name, department;
		while (file >> name >> department) {
			result.push_back(stuff(name, department));
		}

		file.close();
		cout << "\nУспешно загружено " << result.size() << " сотрудников из файла\n";
		break;
	}
	}

	return result;  
}

// вывод сотрудников для задания 2
void show1(std::vector<stuff> STUFF) {
	using namespace std;
	int output;

	cout << "\n======= Вывод =======" << endl;
	cout << "Доступные способы:\n 1 - в консоль\n 2 - в файл" << endl;
	output = getNumber();

	while (output < 1 || output>2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		output = getNumber();
	}
	cout << endl;

	switch (output) {
	case 1:
		for (stuff i : STUFF) {
			i.print();
		}
		break;
	case 2:
		string filename;

		cout << "Введите имя файла: ";
		getline(cin, filename);
		bool t = getText(filename);

		while (!t) {
			cout << "Введите имя файла: ";
			getline(cin, filename);
			t = getText(filename);
		}

		ofstream file(filename);

		if (file.is_open()) {
			for (stuff i : STUFF) {
				file << i.toStr() << endl;
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}
		file.close();

		break;
	}
}


// вывод сотрудников для задания 3
void show(std::vector<stuff> STUFF, stuff shh) {
	using namespace std;
	int output;

	cout << "\n======= Вывод =======" << endl;
	cout << "Доступные способы:\n 1 - в консоль\n 2 - в файл" << endl;
	output = getNumber();

	while (output < 1 || output>2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		output = getNumber();
	}

	switch (output) {
	case 1:
		cout << "\n======== Все сотрудники отдела " << shh.getDepartment() << " ========\n";
		for (stuff i : STUFF) {
			if (i.getDepartment() == shh.getDepartment()) {
				i.print();
			}
		}
		break;
	case 2:
		string filename;

		cout << "Введите имя файла: ";
		getline(cin, filename);
		bool t = getText(filename);

		while (!t) {
			cout << "Введите имя файла: ";
			getline(cin, filename);
			t = getText(filename);
		}

		ofstream file(filename);

		if (file.is_open()) {
			file << "\n======== Все сотрудники отдела " << shh.getDepartment() << " ========\n\n";
			for (stuff i : STUFF) {
				if (i.getDepartment() == shh.getDepartment()) {
					file << i.toStr() << endl;
				}
			}
		}
		else {
			cout << "\nОшибка открытия файла!\n";
		}
		file.close();

		break;
	}
}



// ======================= КЛАСС: ВРЕМЯ 2.0 =======================

// ввод 2 способами
std::vector<timer2> timer2::input() {
	using namespace std;
	vector<timer2> result;
	int inputt = 0;

	cout << "\n===== Ввод времени 2.0 =====" << endl;
	cout << "Доступные способы:\n 1 - c консоли\n 2 - из файла" << endl;
	inputt = getNumber();

	while (inputt < 1 || inputt > 2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		inputt = getNumber();
	}

	switch (inputt) {
	case 1: {
		int hour = 0, minutes = 0, seconds = 0, num = 0, menu;

		cout << "\n==== Менюшка ====\n";
		cout << " 1 - хочу ввести только секунды *-*\n";
		cout << " 2 - хочу ввести не только секунды ^-^\n";

		menu = getNumber();
		while (menu > 2 || menu < 1) {
			cout << "\nОшибка!\n";
			menu = getNumber();
		}

		cout << "\nСколько значений времени хотите ввести?\n";
		num = getNumber();

		if (menu == 1) {
			cout << "\n=== секунды ===: \n";
			seconds = getNumber();
		}
		else {
			for (int i = 0; i < num; i++) {
				cout << "\n=== часы ===: \n";
				hour = getNumber();
				
				cout << "\n=== минуты ===: \n";
				minutes = getNumber();
		
				cout << "\n=== секунды ===:\n";
				seconds = getNumber();
			}
		}
		result.push_back(timer2(seconds, hour, minutes));
		break;
	}

	case 2: {
		string filename;
		cout << "\nВведите имя файла: ";
		getline(cin, filename);
		bool t = getText(filename);

		while (!t) {
			cout << "\nВведите имя файла: ";
			getline(cin, filename);
			t = getText(filename);
		}

		filename.erase(0, filename.find_first_not_of(" \t"));
		filename.erase(filename.find_last_not_of(" \t") + 1);


		ifstream file(filename);
		if (!file.is_open()) {
			cout << "\nОшибка открытия файла!\n";
			return result;
		}

		int hour, minutes, seconds;
		while (file >> hour >> minutes >> seconds) {
			result.push_back(timer2(seconds, hour, minutes));
		}

		file.close();
		cout << "\nУспешно загружено " << result.size() << " значений времени из файла\n";
		break;
	}
	}

	return result;
}



// ======================= КЛАСС: ВРЕМЯ 2.0 (задание 5) =======================

// вывод текущего времени для задания 5
void timer2::whatTimeIsIt() {
	using namespace std;
	int c;

	cout << " 1 - Какой сейчас час ?\n 2 - Сколько минут прошло с начала текущего часа ?\n 3 - Сколько секунд прошло с начала текущей минуты ?\n";
	c = getNumber();
	while (c < 1 || c > 3) {
		cout << "Ошибка! Че фигню вводишь. Слепой чтоль\n";
		c = getNumber();
	}

	normalizeTime();

	if (c == 1)	cout << endl << hours << " часов" << endl;
	if (c == 2) cout << endl << min << " минут" << endl;
	if (c == 3) cout << endl << seconds << " секунд" << endl;

}



//меню для задания 5
void menu5(std::vector<timer2> clock, std::vector<timer2> pupupu, std::vector<timer2> test) {
	using namespace std;
	int ye, inf, choice;

	cout << "\n\n^-^ ===== Меню ===== ^-^\n";
	cout << " 1 - посмотреть инфу о каком-то времени\n";
	cout << " 2 - посмотреть, скок щас времени *-*\n";
	cout << " 3 - посмотреть тестовое время *-*\n";
	cout << " 0 - выйти (((\n";

	choice = getNumber();
	while (choice > 3) {
		cout << "Ошибка! Че фигню вводишь. Слепой чтоль\n";
		choice = getNumber();
	}

	while (choice > 0) {
		switch (choice) {
		case 1: {
			int count = 1;
			cout << "\n====== Время ======\n";
			for (timer2 i : pupupu) {
				if (i.getHours() != 0 && i.getMin() == 0 && i.getSeconds() == 0) cout << " " << count << " - " << i.getHours() << " часов\n";
				if (i.getHours() == 0 && i.getMin() != 0 && i.getSeconds() == 0) cout << " " << count << " - " << i.getMin() << " минут\n";
				if (i.getHours() == 0 && i.getMin() == 0 && i.getSeconds() != 0) cout << " " << count << " - " << i.getSeconds() << " секунд\n";
				if(!(i.getHours() != 0 && i.getMin() == 0 && i.getSeconds() == 0) && !(i.getHours() == 0 && i.getMin() != 0 && i.getSeconds() == 0) && !(i.getHours() == 0 && i.getMin() == 0 && i.getSeconds() != 0)){
					cout << " " << count << " - ";
					i.print2();
					cout << endl;
				}
				count++;

			}
			cout << "\nИнформацию о каком времени вы хотели бы посмотреть из " << clock.size() << " имеющихся ?\n";
			inf = getNumber();
			while (inf > clock.size()) {
				cout << "\nОшибка!\n";
				inf = getNumber();
			}
			clock[inf - 1].whatTimeIsIt();
			break;
		}

		case 2:{
			time_t rawtime;
			struct tm timeinfo;
			time(&rawtime);
			errno_t error = localtime_s(&timeinfo, &rawtime);

			if (error != 0) {
				std::cerr << "\nОшибка получения времени!" << std::endl;
				return;
			}
			cout << "\nТекущее время: " << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << endl;
			break;
		}

		case 3:
			for (auto i : test) {
				i.print();
			}
		}

		cout << "\n\n^-^ ===== Меню ===== ^-^\n";
		cout << " 1 - посмотреть инфу о каком-то времени\n";
		cout << " 2 - посмотреть, скок щас времени *-*\n";
		cout << " 3 - посмотреть тестовое время *-*\n";
		cout << " 0 - посмотреть всё времяяя (((\n";

		choice = getNumber();
		while (choice > 3) {
			cout << "Ошибка! Че фигню вводишь. Слепой чтоль\n";
			choice = getNumber();
		}

	}

}
