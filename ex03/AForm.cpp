#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const std::string& target,
             int minSigningGrade, int minExecutingGrade)
    : name{name},
      minSigningGrade{minSigningGrade},
      minExecutingGrade{minExecutingGrade},
      target{target} {
    if (minSigningGrade > 150 || minExecutingGrade > 150) {
        throw AForm::GradeTooLowException();
    }
    if (minSigningGrade < 1 || minExecutingGrade < 1) {
        throw AForm::GradeTooHighException();
    }
};

AForm::AForm(const AForm& other)
    : name{other.name},
      isSigned{other.isSigned},
      minSigningGrade{other.minSigningGrade},
      minExecutingGrade{other.minExecutingGrade},
      target(other.target) {}

AForm& ::AForm::operator=(const AForm & other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const { return this->name; };

bool AForm::getSigned() const { return this->isSigned; };

int AForm::getSigningGrade() const { return this->minSigningGrade; };

int AForm::getExecutingGrade() const { return this->minExecutingGrade; };

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (this->isSigned) {
        throw std::runtime_error("the form is already signed");
    }
    if (bureaucrat.getGrade() > minSigningGrade) {
        throw AForm::GradeTooLowException(
            "the bureaucrats grade is too low to sign this form");
    }
    this->isSigned = true;
}

void AForm::assertCanExecute(const Bureaucrat& bureaucrat) const {
    if (!this->isSigned) {
        throw std::runtime_error("the form is not signed yet");
    }
    if (this->minExecutingGrade < bureaucrat.getGrade()) {
        throw AForm::GradeTooLowException(
            "the bureaucrats grade is too low to execute this form");
    }
}

void AForm::printInfo() const { std::cout << *this << std::endl; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    std::cout << f.getName() << "\nSigned: " << f.getSigned()
              << "\nSigning grade: " << f.getSigningGrade()
              << "\nExecuting grade grade: " << f.getExecutingGrade()
              << std::endl;
    return os;
}
