#include "Person.h"

Person::Person(const std::string& name, Type personType) : name(name), personType(personType) {}

// Getters
std::string Person::getName() const {
    return name;
}

Person::Type Person::getType() const {
    return personType;
}

// Setters
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::displayInfo() const {
    std::cout << "Name: " << name << ", Type: "
              << (personType == Type::Borrower ? "Borrower" : "Lender") << std::endl;
}
