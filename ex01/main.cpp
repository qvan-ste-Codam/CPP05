#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void) {
    auto b1 = Bureaucrat{"B1", 55};
    auto b2 = Bureaucrat{"B2", 100};
    auto b3 = Bureaucrat{"B3", 1};
    auto f1 = Form{"F1", 100, 100};
    auto f2 = Form{"F2", 1, 1};
    auto f3 = Form{"F3", 10, 10};

    b1.signForm(f1);
    b2.signForm(f1);
    b1.signForm(f2);
    b3.signForm(f2);
    try {
        auto f1 = Form{"F4", -1, 1000};
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
