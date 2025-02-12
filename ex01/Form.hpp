#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>

class Bureaucrat;

class Form {
   public:
    Form(const std::string &name = "Base Form", int minSigningGrade = 150,
         int minExecutingGrade = 150);
    Form(const Form &other);
    ~Form() = default;
    Form &operator=(const Form &other);

    const std::string &getName() const;
    bool getSigned() const;
    int getSigningGrade() const;
    int getExecutingGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    void printInfo() const;

   private:
    const std::string name;
    bool isSigned = false;
    const int minSigningGrade;
    const int minExecutingGrade;

    class GradeTooHighException : public std::runtime_error {
       public:
        GradeTooHighException(const std::string &message = "Grade is too high")
            : std::runtime_error(message){};
    };

    class GradeTooLowException : public std::runtime_error {
       public:
        GradeTooLowException(const std::string &message = "Grade is too low")
            : std::runtime_error(message){};
    };
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
