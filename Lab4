// пользуйтесь латиницей при вводе продуктов
// вариант 1
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

template <typename T1, typename T2>
class Pair {
public:
    Pair() {}
    Pair(const T1& first, const T2& second) : first(first), second(second) {}

    void displayPair() const {
        std::cout << first << ": " << second << std::endl;
    }

    void savePairToFile(std::ofstream& outFile) const {
        outFile << first << " " << second << " ";
    }

private:
    T1 first;
    T2 second;
};

class Product {
public:
    Product(const std::string& name, const double& price, const int quantity)
        : name(name), price(price), quantity(quantity) {}

    ~Product() {}

    const std::string& getname() const {
        return name;
    }

    const double& getprice() const {
        return price;
    }

    const int getquantity() const {
        return quantity;
    }

    void displayInfo() const {
        std::cout << "Продукт: " << name << ", цена: " << price << ", количество: " << quantity;
    }

    void saveToFile(std::ofstream& outFile) const {
        outFile << name << " " << price << " " << quantity << " ";
    }

    static bool compareByName(const Product* product1, const Product* product2) {
        return product1->getname() < product2->getname();
    }

private:
    std::string name;
    double price;
    int quantity;
};

void saveProductsToFile(const std::vector<Product*>& products, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    for (const auto* product : products) {
        product->saveToFile(outFile);
    }

    outFile.close();
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<Product*> products;

    int choice;
    std::string filename;

    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить продукт" << std::endl;
        std::cout << "2. Найти продукт" << std::endl;
        std::cout << "3. Вывести список продуктов" << std::endl;
        std::cout << "4. Сохранить в файл" << std::endl;
        std::cout << "5. Сортировать по наименованию" << std::endl;
        std::cout << "6. Выход" << std::endl;

        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string name;
            double price;
            int quantity;

            std::cout << "Введите данные продукта:" << std::endl;
            std::cout << "Наименование: ";
            std::cin >> name;
            std::cout << "Цена: ";
            std::cin >> price;
            std::cout << "Количество: ";
            std::cin >> quantity;

            products.push_back(new Product(name, price, quantity));

            break;
        }
        case 2: {
            std::string name;
            double price;
            int quantity;
            std::cout << "Введите наименование продукта для поиска:" << std::endl;
            std::cin >> name;

            auto it = std::find_if(products.begin(), products.end(), [&](const Product* product) {
                return product->getname() == name;
                });

            if (it != products.end()) {
                (*it)->displayInfo();
            }
            else {
                std::cout << "Продукт не найден." << std::endl;
            }

            break;
        }
        case 3: {
            std::cout << "Список продуктов:" << std::endl;
            for (const auto* product : products) {
                product->displayInfo();
            }
            break;
        }
        case 4: {
            std::cout << "Введите имя файла для сохранения данных: ";
            std::cin >> filename;
            saveProductsToFile(products, filename);
            break;
        }
        case 5: {
            std::sort(products.begin(), products.end(), Product::compareByName);
            std::cout << "Список продуктов отсортирован по наименованию." << std::endl;
            break;
        }
        case 6:
            std::cout << "Выход." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
        }
    } while (choice != 6);

    for (const auto* product : products) {
        delete product;
    }

    return 0;
}
