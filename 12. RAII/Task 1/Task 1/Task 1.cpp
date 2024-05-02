#include <iostream>

class smart_array {
private:
    int* arr;
    int size;
    int elementsAdded;

public:
    smart_array(int size) {
        arr = new int[size];
        this->size = size;
        elementsAdded = 0;
    };

    void add_element(int element) {
        if (elementsAdded < size) {
            arr[elementsAdded] = element;
            elementsAdded++;
        }
        else {
            throw std::logic_error("Array is full");
        }
    }

    int get_element(int index) {
        if (index < size) {
            return arr[index];
        }
        else {
            throw std::logic_error("Index out of range");
        }
    }

    ~smart_array() { delete[] arr; }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        std::cout << arr.get_element(0) << "\n";
        std::cout << arr.get_element(1) << "\n";
        std::cout << arr.get_element(2) << "\n";
        std::cout << arr.get_element(3) << "\n";
        std::cout << arr.get_element(4) << "\n";

        //Получение элемента за пределами массива
        std::cout << arr.get_element(5) << "\n";
    }
    catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}