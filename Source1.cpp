// ���� 3 �����
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
		cout << "����� ������ �������?" << endl;
		cin >> n;
		cout << lines[n - 1].name << " " << lines[n - 1].cost << " " << lines[n - 1].quant << " " << endl;
	}
	// ������ ������ ���������� ������
	void findprod(Myline* lines, int n)
	{
		char prod[20];
		cout << "����� ������� �� ������ �����?" << endl;
		cin >> prod;
		for (int i = 0; i < n; i++) {
			if (strcmp(prod, lines[i].name)==0) {
				cout << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
			}
		}
	}
	//����� �������� �� ��������
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
	// ��������� �������
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
	// ��������� �������
	void printall(Myline* lines, int n) {
		cout << endl;
		for (int i = 0; i < n;i++) {
			cout << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
		}
		cout << endl;
	}
	//������ ������� �������� ����� (�� ������ �����!)
	void printless(Myline* lines, int n)
	{
		cout << endl;
		int num;
		cout << "������� ������������ ����: ";
		cin >> num;
		for (int i = 0; i < n ; i++) {
			if (lines[i].cost <= num) {
				cout << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
			}
		}
		cout << endl;
	}
	// ������ ������ ���������� ��������
	Myline initnewline(char *name,int cost,int quant) {
		Myline newline = { *name, cost, quant };
		return newline;
	}
	//������������� ���������
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
	//���������� ����� ������

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
		// ������� ������ ����
		
		for (int i = 0; i < items; i++) {
			cout << "������� " << i+1 << ": " << endl;
			cout << "������������ (��������� �� 20 ��������): ";
			cin.getline(lines[i].name,20);
			cout << "���������: ";
			cin >> lines[i].cost;
			cout << "���-��: ";
			cin >> lines[i].quant;
			// ������������ ��������� ��� ������
			infile << lines[i].name << " " << lines[i].cost << " " << lines[i].quant << " " << endl;
			// �������� ��������� ��� ������ � ����
			cin.ignore();
		}
		infile.close();
	}
	else {
		cerr << "Failed to open the file." << endl;
	}

	int choice;
	do {
		cout << "1. ������ ������� �� ��������" << endl;
		cout << "2. ���������� �� ����" << endl;
		cout << "3. ���������� �� ����������" << endl;
		cout << "4. ����� �� ���������� ������������� ��������" << endl;
		cout << "5. �������� ������ � ����" << endl;
		cout << "0. �������� ������" << endl;
		cin >> choice;

		switch(choice) {
		case 1:
			findprod(lines, items);
			break;
		case 2:
			sortcost(lines,items);
			cout << endl << "������������� �� ����:" << endl;
			printall(lines, items);
			break;
		case 3:
			sortquant(lines, items);
			cout << endl << "������������� �� ���-��:" << endl;
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
			cout << "����� �������: (��� ��������� ������� ��� !) " << endl;
			cout << "������������ (��������� �� 20 ��������): ";
			cin.getline(newname, 20);
			if (newname == "!") {
				cout << "���� �������" << endl;
				break;
			}
			cout << "���������: ";
			cin >> newcost;
			cout << "���-��: ";
			cin >> newquant;
			cin.ignore();
			addline(initnewline(newname, newcost, newquant));
			break;
		case 0:
			cout << "���������� ���������." << endl;
			break;
		default:
			cout << "�������� �����. ���������� �����." << endl;
		}
	} while (choice!=0);

	return 0;
}
