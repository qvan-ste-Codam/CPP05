#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int minSigningGrade, int minExecutingGrade)
    : name{name},
      minSigningGrade{minSigningGrade},
      minExecutingGrade{minExecutingGrade} {
    if (minSigningGrade > 150 || minExecutingGrade > 150) {
        throw Form::GradeTooLowException();
    }
    if (minSigningGrade < 1 || minExecutingGrade < 1) {
        throw Form::GradeTooHighException();
    }
};

Form::Form(const Form& other)
    : name{other.name},
      isSigned{other.isSigned},
      minSigningGrade{other.minSigningGrade},
      minExecutingGrade{other.minExecutingGrade} {}

Form& ::Form::operator=(const Form & other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string& Form::getName() const { return this->name; };

bool Form::getSigned() const { return this->isSigned; };

int Form::getSigningGrade() const { return this->minSigningGrade; };

int Form::getExecutingGrade() const { return this->minExecutingGrade; };

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (this->isSigned) {
        throw std::runtime_error("the form is already signed");
    }
    if (bureaucrat.getGrade() > minSigningGrade) {
        throw Form::GradeTooLowException("the bureaucrats grade is too low");
    }
    this->isSigned = true;
}

void Form::printInfo() const { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream& os, const Form& f) {
    std::cout << f.getName() << "\nSigned: " << f.getSigned()
              << "\nSigning grade: " << f.getSigningGrade()
              << "\nExecuting grade grade: " << f.getExecutingGrade()
              << std::endl;
    return os;
}
