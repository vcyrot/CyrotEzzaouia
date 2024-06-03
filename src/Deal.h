#ifndef DEAL_H
#define DEAL_H

#include <string>
#include <vector>
#include "Person.h"

class Deal {
public:
    Deal(const std::string& contractNumber, const std::string& agent, const std::vector<std::string>& pool,
         const Person& borrower, double amount, const std::string& currency,
         const std::string& startDate, const std::string& endDate, const std::string& status);

    void displayDealInfo() const;

    // Getters
    std::string getContractNumber() const;
    std::string getAgent() const;
    std::vector<std::string> getPool() const;
    Person getBorrower() const;
    double getAmount() const;
    std::string getCurrency() const;
    std::string getStartDate() const;
    std::string getEndDate() const;
    std::string getStatus() const;

    // Setters
    void setContractNumber(const std::string& contractNumber);
    void setAgent(const std::string& agent);
    void setPool(const std::vector<std::string>& pool);
    void setBorrower(const Person& borrower);
    void setAmount(double amount);
    void setCurrency(const std::string& currency);
    void setStartDate(const std::string& startDate);
    void setEndDate(const std::string& endDate);
    void setStatus(const std::string& status);

private:
    std::string contractNumber;
    std::string agent;
    std::vector<std::string> pool;
    Person borrower;
    double amount;
    std::string currency;
    std::string startDate;
    std::string endDate;
    std::string status;
};

#endif // DEAL_H
