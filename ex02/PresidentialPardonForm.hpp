#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm(const std::string &name = "Default target");
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm() = default;
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void execute(Bureaucrat const &executor) override;
};

#endif
