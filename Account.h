#pragma once
#include <stdint.h>
#include <memory>

class Person;

class Account
{

public:

	Account(uint64_t id);
	Account(uint64_t id, double money);
	Account(uint64_t id, double money, double interest);
	Account(uint64_t id, double money, double interest, std::shared_ptr<Person> person);

	uint64_t GetId() const;
	double GetMoney() const;
	double GetDepositInterest() const;
	std::shared_ptr<Person> GetPerson() const;
	uint64_t GetPeriod() const;
	double GetLoan() const;
	double GetLoanInterest() const;
	uint64_t GetLoanPeriod() const;

	void SetId(uint64_t id);
	void SetMoney(double money);
	void SetDepositInterest(double interest);
	void SetPerson(std::shared_ptr<Person> person);
	void SetPeriod(uint64_t period);
	void SetLoan(double loan);
	void SetLoanInterest(double interest);
	void SetLoanPeriod(uint64_t period);

	void IncreaseMoney(double amount);
	void DecreaseMoney(double amount);
	void IncreaseDepositInterest(double amount);
	void DecreaseDepositInterest(double amount);
	void IncreaseLoan(double amount);
	void DecreaseLoan(double amount);
	void IncreaseLoanInterest(double amount);
	void DecreaseLoanInterest(double amount);

	double CalculateDepositInterest() const;
	double CalculateLoanInterest() const;


	void ApplyDepositInterest();
	void ApplyLoanInterest();

	void Update();

private:

	uint64_t m_id;
	double m_money;
	double m_depositInterest;
	std::shared_ptr<Person> m_person;
	uint64_t m_depositInterestPeriod;
	double m_loan;
	double m_loanInterest;
	uint64_t m_loanInterestPeriod;

};

