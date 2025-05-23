#include "Account.h"
#include "Person.h"


Account::Account(uint64_t id)
	: m_id(id), m_money(0), 
	m_depositInterest(2), m_person(nullptr), 
	m_depositInterestPeriod(5), m_loan(0), 
	m_loanInterest(5), m_loanInterestPeriod(10)
{
}

Account::Account(uint64_t id, double money)
	: m_id(id), m_money(money), 
	m_depositInterest(2), m_person(nullptr), 
	m_depositInterestPeriod(5), m_loan(0),
	m_loanInterest(5), m_loanInterestPeriod(10)
{
}

Account::Account(uint64_t id, double money, double interest)
	: m_id(id), m_money(money),
	m_depositInterest(interest), m_person(nullptr), 
	m_depositInterestPeriod(5), m_loan(0), 
	m_loanInterest(5), m_loanInterestPeriod(10)
{
}

Account::Account(uint64_t id, double money, double interest, std::shared_ptr<Person> person)
	: m_id(id), m_money(money), 
	m_depositInterest(interest), m_person(person), 
	m_depositInterestPeriod(5), m_loan(0), 
	m_loanInterest(5), m_loanInterestPeriod(10)
{
}

uint64_t Account::GetId() const
{
	return m_id;
}

double Account::GetMoney() const
{
	return m_money;
}

double Account::GetDepositInterest() const
{
	return m_depositInterest;
}

std::shared_ptr<Person> Account::GetPerson() const
{
	return m_person;
}

uint64_t Account::GetPeriod() const
{
	return m_depositInterestPeriod;
}

double Account::GetLoan() const
{
	return m_loan;
}

double Account::GetLoanInterest() const
{
	return m_loanInterest;
}

uint64_t Account::GetLoanPeriod() const
{
	return m_loanInterestPeriod;
}


void Account::SetId(uint64_t id)
{
	m_id = id;
}

void Account::SetMoney(double money)
{
	m_money = money;
}

void Account::SetDepositInterest(double interest)
{
	m_depositInterest = interest;
}

void Account::SetPerson(std::shared_ptr<Person> person)
{
	m_person = person;
}

void Account::SetPeriod(uint64_t period)
{
	m_depositInterestPeriod = period;
}

void Account::SetLoan(double loan)
{
	m_loan = loan;
}

void Account::SetLoanInterest(double interest)
{
	m_loanInterest = interest;
}

void Account::SetLoanPeriod(uint64_t period)
{
	m_loanInterestPeriod = period;
}


void Account::IncreaseMoney(double amount)
{
	m_money += amount;
}

void Account::DecreaseMoney(double amount)
{
	m_money -= amount;
}

void Account::IncreaseDepositInterest(double amount)
{
	m_depositInterest += amount;
}

void Account::DecreaseDepositInterest(double amount)
{
	m_depositInterest -= amount;
}

void Account::IncreaseLoan(double amount)
{
	m_loan += amount;
}

void Account::DecreaseLoan(double amount)
{
	m_loan -= amount;
}

void Account::IncreaseLoanInterest(double amount)
{
	m_loanInterest += amount;
}

void Account::DecreaseLoanInterest(double amount)
{
	m_loanInterest -= amount;
}

double Account::CalculateDepositInterest() const
{
	double personExperience = GetPerson()->GetExperience();
	double depositInterest = 2 + personExperience / 5000;
	return depositInterest;
}

double Account::CalculateLoanInterest() const
{
	double personExperience = GetPerson()->GetExperience();
	double loanInterest = 5 - personExperience / 10000;
	return loanInterest;
}


void Account::ApplyDepositInterest()
{
	double depositInterestRate = m_depositInterest / 100;
	double gain = m_money * depositInterestRate;
	IncreaseMoney(gain);
}

void Account::ApplyLoanInterest()
{
	double loanInterestRate = m_loanInterest / 100;
	double extraLoan = m_loan * loanInterestRate;
	IncreaseLoan(extraLoan);
}

void Account::Update()
{
	m_depositInterestPeriod--;
	m_loanInterestPeriod--;

	if (m_depositInterestPeriod == 0)
	{
		ApplyDepositInterest();
		m_depositInterestPeriod = 5;
	}

	if (m_loanInterestPeriod == 0)
	{
		ApplyLoanInterest();
		m_loanInterestPeriod = 10;
	}

	m_depositInterest = CalculateDepositInterest();
	m_loanInterest = CalculateLoanInterest();

}
