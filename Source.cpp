//РК1
//Вариант 4
//

#include<iostream>
#include <cstring>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int num = 0;
	//кол-во товаров
	cout << "Введите кол-во товаров: ";
	cin >> num;
	char** names = new char*[num];
	//имена товаров
	int* quant = new int[num];
	//кол-во единиц товара
	float* prices = new float[num];
	//цены за единицу товара

	cin.ignore();
	for (int i = 0; i < num; i++) {
		char buffer[100];
		cout << "Введите латиницей название товара: ";
		cin.getline(buffer, 100);
		names[i] = new char[strlen(buffer)];
		strcpy(names[i], buffer);
		cout << "Введите кол-во единиц товара: ";
		cin >> quant[i];
		cout << "Введите цену за единицу товара  ";
		cin >> prices[i];
		cout << "Стоимость заказа : " <<( quant[i] * prices[i]) << endl;
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
		cout << "Товар " << names[i] << ": кол-во " << quant[i] << ", цена за единицу: " << prices[i] << "\n";
	}
	cout << "Общая стоимость товаров: " << sum << endl;

	delete names;
	delete prices;
	delete quant;
	return 0;
}