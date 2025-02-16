#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include <string>

#include "AForm.hpp"
class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm(const std::string &name = "Default target");
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm() = default;
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    void execute(Bureaucrat const &executor) override;
};

#endif
