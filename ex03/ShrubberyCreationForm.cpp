#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm{"Shrubbery Creation Form", target, 145, 137} {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm{other} {}

ShrubberyCreationForm& ::ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm & other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) {
    try {
        this->assertCanExecute(executor);

        std::ostringstream filename;
        filename << this->target << "_shrubbery";

        std::ofstream file;

        file.open(filename.str(), std::ios_base::app);

        file << "my-app/\n"
             << "|-- node_modules/\n"
             << "|-- public/\n"
             << "|   |-- favicon.ico\n"
             << "|   |-- index.html\n"
             << "|   |-- robots.txt\n"
             << "|-- src/\n"
             << "|   |-- index.css\n"
             << "|   |-- index.js\n"
             << "|-- .gitignore\n"
             << "|-- package.json\n"
             << "|-- README.md\n";
        file.close();
        std::cout << executor.getName() << " executed " << this->getName()
                  << std::endl;

    } catch (std::runtime_error& ex) {
        std::cerr << executor.getName()
                  << " could not execute the form because " << ex.what()
                  << std::endl;
    }
}
