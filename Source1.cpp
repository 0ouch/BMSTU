// Лаба 3 файлы
//

#include <iostream>
#include <fstream>
#include <cstring>
#include<string>
using namespace std;

	struct Myline {
		char name[20];
		int cost;
		int quant;
	};
	const int items = 3;
	Myline lines[items];

	void swap(int* a, int* b) {	
		int z;
		z = *a;
		*a = *b;
		*b = *a;
	}

	void printline(Myline* lines)
	{
		int n;
		cout << "Какую строку вывести?" << endl;
		cin >> n;
		cout << lines[n - 1].name << " " << lines[n - 1].cost << " " << lines[n - 1].quant << " " << endl;
	}
	// печать строки указанного номера
	void findprod(Myline* lines, int n)
	{
		char prod[20];
		cout << "Какой продукт вы хотите найти?" << endl;
		cin >> prod;
		for (int i = 0; i < n; i++) {
			if (strcmp(prod, lines[i].name)==0) {
				cout << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
			}
		}
	}
	//поиск продукта по названию
	void sortcost(Myline* lines, int n)
	{
		for (int i = 0; i < n; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (lines[min].cost > lines[j].cost)
					min = j;
			}
			swap(lines[i], lines[min]);
		}
	}
	// сортируем выбором
	void sortquant(Myline* lines, int n)
	{
		for (int i = 0; i < n; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (lines[min].quant > lines[j].quant)
					min = j;
			}
			swap(lines[i], lines[min]);
		}
	}
	// сортируем выбором
	void printall(Myline* lines, int n) {
		cout << endl;
		for (int i = 0; i < n;i++) {
			cout << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
		}
		cout << endl;
	}
	//печать МАССИВА СТРУКТУР файла (не самого файла!)
	void printless(Myline* lines, int n)
	{
		cout << endl;
		int num;
		cout << "Введите максимальную цену: ";
		cin >> num;
		for (int i = 0; i < n ; i++) {
			if (lines[i].cost <= num) {
				cout << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
			}
		}
		cout << endl;
	}
	// печать меньше указанного значения
	Myline initnewline(char *name,int cost,int quant) {
		Myline newline = { *name, cost, quant };
		return newline;
	}
	//инициализация структуры
	void addline(Myline line)
	{
		ofstream newinfile("testfile1.txt", ios::app);
		if (newinfile.is_open())
		{
			newinfile << line.name << " " << line.cost << " " << line.quant << " " << endl;
			newinfile.close();
		}
		else {
			cerr << "Failed to open the file." << endl;
		}
	}
	//добавление новой строки

int main()
{
	setlocale(LC_ALL, "rus");

	const int size = 100;
	char buff[size];


	ofstream infile("testfile1.txt");
	if (!infile.is_open()) {
		cerr << "File not found." << endl;
	}
	if (infile.is_open()) {
		// Успешно открыт файл
		
		for (int i = 0; i < items; i++) {
			cout << "Продукт " << i+1 << ": " << endl;
			cout << "Наименование (латиницей до 20 символов): ";
			cin.getline(lines[i].name,20);
			cout << "Стоимость: ";
			cin >> lines[i].cost;
			cout << "Кол-во: ";
			cin >> lines[i].quant;
			// сформировали структуру для строки
			infile << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
			// записали структуру как строку в файл
			cin.ignore();
		}
		infile.close();
	}
	else {
		cerr << "Failed to open the file." << endl;
	}

	int choice;
	do {
		cout << "1. Искать продукт по названию" << endl;
		cout << "2. Сортировка по цене" << endl;
		cout << "3. Сортировка по количеству" << endl;
		cout << "4. Вывод до указанного максимального значения" << endl;
		cout << "5. Добавить данные в файл" << endl;
		cout << "0. Окончить работу" << endl;
		cin >> choice;

		switch(choice) {
		case 1:
			findprod(lines, items);
			break;
		case 2:
			sortcost(lines,items);
			cout << endl << "Отсортировано по цене:" << endl;
			printall(lines, items);
			break;
		case 3:
			sortquant(lines, items);
			cout << endl << "Отсортировано по кол-ву:" << endl;
			printall(lines, items);
			break;
		case 4:
			sortcost(lines, items);
			printless(lines,items);
			break;
		case 5:
			cin.ignore();
			char newname[20];
			int newcost, newquant;
			cout << "Новый продукт: (для окончания введите имя !) " << endl;
			cout << "Наименование (латиницей до 20 символов): ";
			cin.getline(newname, 20);
			if (newname == "!") {
				cout << "Ввод прерван" << endl;
				break;
			}
			cout << "Стоимость: ";
			cin >> newcost;
			cout << "Кол-во: ";
			cin >> newquant;
			cin.ignore();
			addline(initnewline(newname, newcost, newquant));
			break;
		case 0:
			cout << "Завершение программы." << endl;
			break;
		default:
			cout << "Неверный выбор. Попробуйте снова." << endl;
		}
	} while (choice!=0);

	return 0;
}
