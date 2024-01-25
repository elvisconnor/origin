#include <iostream>

struct address
{
    std::string city;
    std::string street;
    int house_num;
    int apartment_num;
    int index;
};

void print_address(address& address)
{
    std::cout << "Город: " << address.city << "\n";
    std::cout << "Улица: " << address.street << "\n";
    std::cout << "Номер дома: " << address.house_num << "\n";
    std::cout << "Номер квартиры: " << address.apartment_num << "\n";
    std::cout << "Индекс: " << address.index << "\n";
}

int main()
{
    setlocale(0, "");

    address ad1 = { "Москва", "Арбат", 12, 8, 123456 };

    address ad2 = { "Ижевск", "Пушкина", 59, 143, 953769 };

    print_address(ad1);
    std::cout << "\n";
    print_address(ad2);

    return 0;
}