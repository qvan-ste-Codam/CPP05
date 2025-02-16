#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#define NUM_OF_TESTS 5

int main() {
    const char *tests[NUM_OF_TESTS] = {"foo", "shrubbery creation",
                                       "robotomy request",
                                       "presidential pardon", "bar"};
    auto intern = Intern{};
    auto bureaucrat = Bureaucrat{"Jan", 1};

    for (size_t i = 0; i < NUM_OF_TESTS; i++) {
        try {
            AForm *form = intern.makeForm(tests[i], "bar");
            form->beSigned(bureaucrat);
            form->execute(bureaucrat);
            delete form;
        } catch (std::exception &ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
}
