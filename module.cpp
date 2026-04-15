# include "Header.h"

void task_1() {
	using namespace std;
	int menu = 1, menuNames, menuTime;
	vector<names> all;
	vector<timer> clock;
	vector<names> testNames;
	vector<timer> testTime;

	names Kleopatra("Клеопатра");
	names Pushkin("Пушкин", "Александр", "Сергеевич");
	names Mayakovski("Маяковский", "Владимир");
	testNames.push_back(Kleopatra);
	testNames.push_back(Pushkin);
	testNames.push_back(Mayakovski);

	timer ten(10);
	timer tenThousand(10000);
	timer AHundredThousand(100000);
	testTime.push_back(ten);
	testTime.push_back(tenThousand);
	testTime.push_back(AHundredThousand);

	while (menu > 0){
		cout << "\n====== Менюшка ======\n";
		cout << " 1 - хочу создать имена ^-^\n";
		cout << " 2 - хочу создать время ^_^\n";
		cout << " 3 - хочу посмотреть тестовые имена\n";
		cout << " 4 - хочу посмотреть тестовое время\n";
		cout << " 0 - выход\n";

		menu = getNumber();
		while (menu < 0 || menu > 4) {
			cout << "\nОшибка!\n";
			menu = getNumber();
		}

		switch (menu) {
		case 1:
			all = names::input();

			cout << "\n====== Менюшка для имён ======\n";
			cout << " 1 - вернуться в основное меню ^-^\n";
			cout << " 2 - хочу вывод всех имен ^_^\n";
			cout << " 3 - хочу посмотреть тестовые имена\n";

			menuNames = getNumber();
			while (menuNames < 0 || menuNames > 3) {
				cout << "\nОшибка!\n";
				menuNames = getNumber();
			}

			switch (menuNames) {
			case 1:
				break;
			case 2:
				showNames(all);
				break;
			case 3:
				showNames(testNames);
				break;
			}
			break;
		case 2:
			clock = timer::input();

			cout << "\n====== Менюшка для времени ======\n";
			cout << " 1 - вернуться в основное меню ^-^\n";
			cout << " 2 - хочу вывод времени ^_^\n";
			cout << " 3 - хочу посмотреть тестовое время\n";

			menuTime = getNumber();
			while (menuTime < 0 || menuTime > 3) {
				cout << "\nОшибка!\n";
				menuTime = getNumber();
			}

			switch (menuTime) {
			case 1:
				return;
				break;

			case 2:
				showTimes(clock);
				break;
			case 3:
				showTimes(testTime);
				break;
			}

			break;
		case 0:
			return;
			break;
		
		case 3:
			showNames(testNames);
			break;
		
		case 4:
			showTimes(testTime);
			break;
		}
	}
		
}


void task_2_and_3(){
	using namespace std;
	int num, output, N, dep, st, cnt = 0, menu = 1;
	string b, d;
	vector<stuff> STUFF = stuff::input(), testStuffFor2;
	set<string> allDepartments;
	
	while (menu > 0){
		cout << "\n====== Менюшка ======\n";
		cout << " 1 - хочу выбрать начальника какого-нибудь отдела\n";
		cout << " 2 - хочу посмотреть всех сотрудников ^_^\n";
		cout << " 3 - хочу посмотреть всех сотрудников определенного отдела  -_-\n";
		cout << " 4 - хочу посмотреть тестовых сотрудников для 2 задания\n";
		cout << " 0 - выход\n";

		menu = getNumber();
		while (menu < 0 || menu > 4) {
			cout << "\nОшибка!\n";
			menu = getNumber();
		}
		switch (menu) {
		case 1:
			N = 1;
			cnt = 0;

			for (stuff i : STUFF) {
				allDepartments.insert(i.getDepartment());
			}

			cout << "\nВыберите отдел: \n";
			for (string i : allDepartments) {
				cout << N << " - " << i << endl;
				N++;
			}
			cout << endl;

			dep = getNumber();
			while (dep > N - 1) {
				cout << "\nОшибка!\n";
				dep = getNumber();
			}
			for (string i : allDepartments) {
				cnt++;
				if (cnt == dep) {
					d = i;
					break;
				}
			}

			N = 1;
			cout << "\nВыберите сотрудника, который будет начальником отдела: \n";

			for (stuff i : STUFF) {
				if (i.getDepartment() == d) {
					cout << N << " - " << i.getName() << endl;
					N++;
				}
			}

			st = getNumber();
			while (st > N - 1) {
				cout << "Ошибка!\n";
				st = getNumber();
			}

			N = 0;
			for (stuff i : STUFF) {
				if (i.getDepartment() == d) {
					N++;
					if (N == st) {
						b = i.getName();
						break;
					}
				}
			}

			for (stuff& i : STUFF) {
				if (i.getDepartment() == d) {
					i.chooseBoss(b);
				}
			}
			break;

		case 2:
			show1(STUFF);
			break;

		case 3:{
			int number = 0, worker;
			cout << "\n==== Выбор сотрудника ====\n";
			for (stuff i : STUFF) {
				number++;
				cout << " " << number << " - " << i.getName() << endl;
			}

			worker = getNumber();
			while (worker > number || worker < 0) {
				cout << "\nОшибка!\n";
				worker = getNumber();
			}

			int cnt = 1;
			stuff yourWorker;
			for (stuff i : STUFF) {
				if (cnt == worker) {
					yourWorker = i;
				}
				cnt++;
			}

			show(STUFF, yourWorker);
			break;
		}

		case 4:{
			stuff f("Петров", "IT");
			stuff f1("Козлов", "IT");
			stuff f2("Сидоров", "IT");

			testStuffFor2.push_back(f);
			testStuffFor2.push_back(f1);
			testStuffFor2.push_back(f2);

			for (stuff& i : testStuffFor2) {
				i.chooseBoss("Козлов");
			}

			show1(testStuffFor2);
			break;
		}

		case 0:
			return;
			break;
		}
	}
}

void task_3() {
	using namespace std;
	cout << endl << "Вообще-то 3 задание объединено со 2-ым, потому что так нада\nИщи эту задачу в меню 2-ой.\n";
}

void task_4(){
	using namespace std;
	int output, num, choice;

	vector<timer2> clock = timer2::input(), testTime;

	timer2 tenThousand(10000);
	timer2 timing(5, 2, 3);

	testTime.push_back(tenThousand);
	testTime.push_back(timing);

	cout << "\n\n====== Меню ======";
	cout << "\n 1 - хочу посмотреть тестовое время";
	cout << "\n 2 - хочу посмотреть введенное время";
	cout << "\n 0 - выйти\n";

	choice = getNumber();
	while (choice < 0 || choice>2) {
		cout << "Ошибка! Нужна цифра 1-2 или 0!\n";
		choice = getNumber();
	}

	while (choice > 0) {
		switch (choice) {
		case 1:
			for (timer2 i : testTime) {
				i.print();
			}
			break;
		case 2:
			cout << "\n======= Вывод =======" << endl;
			cout << "Доступные способы:\n 1 - в консоль\n 2 - в файл" << endl;
			output = getNumber();

			while (output < 1 || output>2) {
				cout << "Ошибка! Нужна цифра 1-2!\n";
				output = getNumber();
			}

			switch (output) {
			case 1:
				for (timer2 i : clock) {
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
					for (timer2 i : clock) {
						file << "Время: " << i.toStr() << endl;
					}
				}
				else {
					cout << "\nОшибка открытия файла!\n";
				}
				file.close();

				break;
			}
			break;

		case 0:
			return;
			break;
		}		

		cout << "\n\n====== Меню ======";
		cout << "\n 1 - хочу посмотреть тестовое время";
		cout << "\n 2 - хочу посмотреть введенное время";
		cout << "\n 0 - выйти\n";

		choice = getNumber();
		while (choice < 0 || choice>2) {
			cout << "Ошибка! Нужна цифра 1-2 или 0!\n";
			choice = getNumber();
		}
	}
	
}


void task_5(){
	using namespace std;

	int output, num, inf, ye, cnt= 1;
	vector<timer2> clock, pupupu, testTime;
	clock = timer2::input();
	pupupu = clock;

	timer2 one(0, 0, 34056);
	timer2 two(0, 0, 4532);
	timer2 three(0, 0, 123);
	testTime.push_back(one);
	testTime.push_back(two);
	testTime.push_back(three);

	menu5(clock, pupupu, testTime);

	cout << "\n======= Вывод =======" << endl;
	cout << "Доступные способы:\n 1 - в консоль\n 2 - в файл" << endl;
	output = getNumber();

	while (output < 1 || output>2) {
		cout << "Ошибка! Нужна цифра 1-2!\n";
		output = getNumber();
	}

	switch (output) {
	case 1:
		for (timer2 i : clock) {
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
			for (timer2 i : clock) {
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
