#pragma once
#include <stdint.h>
#include <memory>

class Person;

class Account
{

public:

	Account(const uint64_t& id);
	Account(const uint64_t& id, const double& money);
	Account(const uint64_t& id, const double& money, const double& interest);
	Account(const uint64_t& id, const double&money, const double& interest, const std::shared_ptr<Person>& person);

	uint64_t GetId() const;
	double GetMoney() const;
	double GetDepositInterest() const;
	std::shared_ptr<Person> GetPerson() const;
	uint64_t GetPeriod() const;
	double GetLoan() const;
	double GetLoanInterest() const;
	uint64_t GetLoanPeriod() const;

	void SetId(const uint64_t& id);
	void SetMoney(const double& money);
	void SetDepositInterest(const double& interest);
	void SetPerson(const std::shared_ptr<Person>& person);
	void SetPeriod(const uint64_t& period);
	void SetLoan(const double& loan);
	void SetLoanInterest(const double& interest);
	void SetLoanPeriod(const uint64_t& period);

	void IncreaseMoney(const double& amount);
	void DecreaseMoney(const double& amount);
	void IncreaseDepositInterest(const double&amount);
	void DecreaseDepositInterest(const double&amount);
	void IncreaseLoan(const double& amount);
	void DecreaseLoan(const double& amount);
	void IncreaseLoanInterest(const double& amount);
	void DecreaseLoanInterest(const double& amount);

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

