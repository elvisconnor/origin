#pragma once

#include <string>

class Figure {
protected:
    std::string name;
public:
    Figure();
    virtual void print_info();
    virtual void print_in_one_line();
};