#include <fstream>
#include <iostream>
#include <string>

class Address {
    std::string city;
    std::string street;
    int house;
    int flat;

public:
    Address(std::string city, std::string street, int house, int flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    };
    std::string address_output() {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
    }
};

void sort(Address** addresses, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (addresses[j]->address_output() > addresses[j + 1]->address_output()) {
                Address* temp = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = temp;
            };
        }
    }
};

int main() {
    setlocale(0, "");
    
    int address_count = 0;

    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    if (fin.is_open() == false) {
        std::cout << "File not found!\n";
        return 1;
    }

    fin >> address_count;

    Address** addresses = new Address * [address_count]();

    while (fin.eof() == false) {

        for (int i = 0; i < address_count; i++) {
            std::string city;
            std::string street;
            int house;
            int flat;
            fin >> city >> street >> house >> flat;
            addresses[i] = new Address(city, street, house, flat);
        }

        fout << address_count << "\n";

        sort(addresses, address_count);

        for (int i = 0; i < address_count - 1; i++) {
            if (i < address_count - 2) {
                fout << addresses[i]->address_output() << "\n";
            }
            else {
                fout << addresses[i]->address_output();
            }
        }
    }

    delete[] addresses;
    fin.close();
    fout.close();

    return 0;
}