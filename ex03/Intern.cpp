#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define NUM_OF_FORMS 3

Intern::Intern() {}

// Nothing to copy for interns
Intern::Intern(const Intern& other) { *this = other; }

Intern& ::Intern::operator=(const Intern & other) {
    if (this != &other) {
        return *this;
    }
    return *this;
}

AForm* Intern::makeForm(const std::string& name,
                        const std::string& target) const {
    const char* forms[NUM_OF_FORMS] = {
        "robotomy request", "presidential pardon", "shrubbery creation"};
    size_t form = -1;

    for (size_t i = 0; i < NUM_OF_FORMS; i++) {
        if (name == forms[i]) {
            form = i;
        }
    }
    switch (form) {
        case 0:
            return new RobotomyRequestForm{target};
        case 1:
            return new PresidentialPardonForm{target};
        case 2:
            return new ShrubberyCreationForm{target};
        default:
            throw std::runtime_error("Form not found");
    }
}
