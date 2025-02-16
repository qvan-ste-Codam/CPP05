#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm{"Presidential Pardon Form", target, 25, 5} {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm{other} {}

PresidentialPardonForm& ::PresidentialPardonForm::operator=(
    const PresidentialPardonForm & other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) {
    try {
        this->assertCanExecute(executor);
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."
                  << std::endl;
        std::cout << executor.getName() << " executed " << this->getName()
                  << std::endl;
    } catch (std::runtime_error& ex) {
        std::cerr << executor.getName()
                  << " could not execute the form because " << ex.what()
                  << std::endl;
    }
}
