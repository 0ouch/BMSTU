//��1
//������� 4
//

#include<iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int num = 0;
	//���-�� �������
	cout << "������� ���-�� �������: ";
	cin >> num;
	char** names = new char*[num];
	//����� �������
	int* quant = new int[num];
	//���-�� ������ ������
	float* prices = new float[num];
	//���� �� ������� ������

	cin.ignore();
	for (int i = 0; i < num; i++) {
		char buffer[100];
		cout << "������� ��������� �������� ������: ";
		cin.getline(buffer, 100);
		names[i] = new char[strlen(buffer)];
		strcpy(names[i], buffer);
		cout << "������� ���-�� ������ ������: ";
		cin >> quant[i];
		cout << "������� ���� �� ������� ������  ";
		cin >> prices[i];
		cout << "��������� ������ : " <<( quant[i] * prices[i]) << endl;
		cin.ignore();
	}
	for (int i = 0; i < num - 1; i++)               
	{
		for (int j = 0; j < num - i - 1; j++)          
		{
			if (strcmp(names[j], names[j + 1]) > 0)   
			{
				swap(names[j], names[j + 1]);     
				swap(quant[j], quant[j + 1]);   
				swap(prices[j], prices[j + 1]);   
			}
		}
	}

	double sum = 0;
	double sum1=0;
	double sum2=0;
	for (int i = 0; i < num; ++i) 
	{
		double c;
		double b;
		b = double(quant[i]);                        
		c = double(b * prices[i]);                   
		sum += c;                                    
		sum1 += double(prices[i]);                   
		sum2 += double(quant[i]);                    
	}

	for (int i = 0; i < num; ++i)             
	{
		cout << "����� " << names[i] << ": ���-�� " << quant[i] << ", ���� �� �������: " << prices[i] << "\n";
	}
	cout << "����� ��������� �������: " << sum << endl;

	delete names;
	delete prices;
	delete quant;
	return 0;
}