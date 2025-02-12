#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include <string>

#include "AForm.hpp"
class ShrubberyCreationForm : public AForm {
   public:
    ShrubberyCreationForm(const std::string &name = "Default target");
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm() = default;
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    void execute(Bureaucrat const &executor) override;

   private:
    static const std::string &makeTree();
};

#endif
