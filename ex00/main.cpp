#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
    try {
        auto b = Bureaucrat{};
        auto b1 = Bureaucrat{"B1", 55};
        auto b2 = Bureaucrat{"B2", 100};
        auto b3 = Bureaucrat{"B3", 1};
        b.printInfo();
        b1.printInfo();
        b2.printInfo();
        b3.printInfo();
        b1.incrementGrade(1);
        b1.printInfo();
        b1.decrementGrade(10);
        b1.printInfo();
        b2.incrementGrade(1);
        b2.printInfo();
        b3.incrementGrade(1);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    try {
        auto b4 = Bureaucrat{"B4", 150};
        b4.printInfo();
        b4.decrementGrade(1);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    try {
        auto b5 = Bureaucrat{"B5", 0};
        b5.printInfo();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }

    try {
        auto b6 = Bureaucrat{"B6", 151};
        b6.printInfo();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
