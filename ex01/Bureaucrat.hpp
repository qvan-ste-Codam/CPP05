#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat {
   public:
    Bureaucrat(const std::string &name = "Base bureaucrat",
               const int grade = 150);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat() = default;
    Bureaucrat &operator=(const Bureaucrat &other);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade(const unsigned int amount);
    void decrementGrade(const unsigned int amount);
    void signForm(Form &form);
    void printInfo() const;

   private:
    const std::string name;
    int grade;

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
#endif
