#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
public:
    enum class Type {
        Borrower,
        Lender
    };

    Person(const std::string& name, Type personType);

    // Getters
    std::string getName() const;
    Type getType() const;

    // Setters
    void setName(const std::string& name);

    void displayInfo() const;

private:
    std::string name;
    Type personType;
};

#endif // PERSON_H
