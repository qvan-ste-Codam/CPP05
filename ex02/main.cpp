#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    auto sf = ShrubberyCreationForm{"Diamondtrap"};
    auto pf = PresidentialPardonForm{"Claptrap"};
    auto rf = RobotomyRequestForm{"Scavtrap"};
    auto b1 = Bureaucrat{"B1", 10};
    auto b2 = Bureaucrat{"B2", 100};
    auto b3 = Bureaucrat{"B3", 150};
    auto b4 = Bureaucrat{"B4", 1};

    std::cout << "Testing ShrubberyCreationForm:" << std::endl;
    sf.execute(b1);
    b1.signForm(sf);
    b2.signForm(sf);
    sf.execute(b1);

    std::cout << "\nTesting PresidentialPardonForm:" << std::endl;
    pf.execute(b1);
    b1.signForm(pf);
    pf.execute(b1);
    pf.execute(b4);

    std::cout << "\nTesting RobotomyRequestForm:" << std::endl;
    rf.execute(b1);
    b1.signForm(rf);
    rf.execute(b1);

    std::cout << "\nTesting other" << std::endl;
    b3.signForm(sf);
    sf.execute(b3);

    return 0;
}
