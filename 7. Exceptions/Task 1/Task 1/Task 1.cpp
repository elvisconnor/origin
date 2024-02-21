#include <iostream>
#include <string>

int function(std::string str, int forbidden_length) {
      if (forbidden_length == str.length() / 2) {
          throw "bad_length";
      }
      else {
          return str.length() / 2;
      }
}

int main()
{
    setlocale(0, "");

    int forbidden_length = 0, word_length = 0;
    std::string word = "";

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;


    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> word;
        try {
            word_length = function(word, forbidden_length);
            std::cout << "Длина слова \"" << word << "\" равна " << word_length << "\n";
        }
        catch (const char* err) {
            std::cerr << "Вы ввели слово запретной длины! До свидания\n";
            break;
        }
    }
}