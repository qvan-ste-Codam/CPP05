#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

// Intern::Intern(const Intern& other) {}

// Intern& ::Intern::operator=(const Intern & other) {}

AForm* Intern::makeForm(const std::string& name,
                        const std::string& target) const {
    const char* forms[3] = {"robotomy request", "presidential pardon",
                            "shrubbery creation"};
    size_t form = -1;

    for (size_t i = 0; i < 3; i++) {
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
