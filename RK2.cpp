//РК2
//вариант 5
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>


class MusicalInstrument {
public:
    MusicalInstrument(const std::string& name, const std::string& material)
        : name(name), material(material){}

    ~MusicalInstrument() {}

    void setname(const std::string& newname) {
        name = newname;
    }

    void setmaterial(const std::string& newmaterial) {
        material = newmaterial;
    }


    virtual void displayInfo() const {
        std::cout << "Инструмент: " << name << ", материал: " << material;
    }

protected:
    std::string name;
    std::string material;
};

class StringInstrument : public MusicalInstrument {
public:
    StringInstrument(const std::string& name, const std::string& material, const int stringquant) : MusicalInstrument(name, material), 
        stringquant(stringquant) {}

    void displayInfo() const override {
        std::cout << "Инструмент: " << name << ", материал: " << material << ", кол-во струн: " << stringquant << std::endl;
    }
    ~StringInstrument() {};
private:
    int stringquant;
};

class BrassInstrument : public MusicalInstrument {
public:
    BrassInstrument(const std::string& name, const std::string& material, const std::string& brasstype) : MusicalInstrument(name, material),
        brasstype(brasstype) {}

    void displayInfo() const override {
        std::cout << "Инструмент: " << name << ", материал: " << material << ", тип латуни: " << brasstype << std::endl;
    }
    ~BrassInstrument() {};
private:
    std::string brasstype;
};


void modifyInstrument(MusicalInstrument* instrument, const std::string& newname, const std::string& newmaterial) {
    instrument->setname(newname);
    instrument->setmaterial(newmaterial);
}


int main() {
    setlocale(LC_ALL, "Russian");
    MusicalInstrument instr1("drum", "wood");
    StringInstrument* string1 = new StringInstrument("guitar", "oak", 6);
    BrassInstrument* brass1 = new BrassInstrument("sax", "brass", "shinybrass");
    std::list<MusicalInstrument*> instruments = { string1, brass1};

    modifyInstrument(string1, "violin", "cocobolo");

    for (const auto it : instruments) {
        it->displayInfo();
    }
    return 0;
}
