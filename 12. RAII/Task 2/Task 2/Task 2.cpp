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

    smart_array& operator=(smart_array& other) {
        delete[] arr;
        arr = new int[other.size];
        size = other.size;
        elementsAdded = other.elementsAdded;
        for (int i = 0; i < other.elementsAdded; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }

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

    ~smart_array() {
        delete[] arr;
    }
};

int main() {
    try {

        int size_for_arr = 5;
        int size_for_new_arr = 4;

        smart_array arr(size_for_arr);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(size_for_new_arr);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (std::logic_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}