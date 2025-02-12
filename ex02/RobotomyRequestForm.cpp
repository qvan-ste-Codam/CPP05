#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm{"Robotomy Request Form", target, 72, 45} {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm{other} {}

RobotomyRequestForm& ::RobotomyRequestForm::operator=(
    const RobotomyRequestForm & other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) {
    this->assertCanExecute(executor);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    int num = dis(gen);
    std::cout << "brrrrrrr\n";
    if (num == 0) {
        std::cout << this->target << " robotomized" << std::endl;
    } else {
        std::cout << "robotomization failed" << std::endl;
    }
}
