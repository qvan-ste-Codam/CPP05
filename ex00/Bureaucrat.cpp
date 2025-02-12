#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name{name}, grade{grade} {
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name{other.name}, grade{other.grade} {}

Bureaucrat& ::Bureaucrat::operator=(const Bureaucrat & other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade(const unsigned int amount) {
    if (this->grade - amount < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade -= amount;
}

void Bureaucrat::decrementGrade(const unsigned int amount) {
    if (this->grade + amount > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade += amount;
}

void Bureaucrat::printInfo() const { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    std::cout << b.getName() << ", bureaurat grade " << b.getGrade();
    return os;
}
