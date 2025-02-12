#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
   public:
    AForm(const std::string &name = "Default Form",
          const std::string &target = "Default target",
          int minSigningGrade = 150, int minExecutingGrade = 150);
    AForm(const AForm &other);
    virtual ~AForm() = default;
    AForm &operator=(const AForm &other);

    const std::string &getName() const;
    bool getSigned() const;
    int getSigningGrade() const;
    int getExecutingGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    void printInfo() const;
    void assertCanExecute(const Bureaucrat &bureaucrat) const;
    virtual void execute(Bureaucrat const &executor) = 0;

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

   protected:
    const std::string target;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
