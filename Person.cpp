#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include "Person.h"
#include "Account.h"


static int generateRandomNumber(int min_val, int max_val) {
	if (min_val > max_val) {
		throw std::invalid_argument("Minimum value cannot be greater than maximum value.");
	}

	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(min_val, max_val);
	return distribution(generator);
}

Person::Person(uint64_t id)
	: m_id(id), m_personality(MiddleGround), 
	m_money(1000), m_energy(100),
	m_experience(0), m_maxEnergy(100)
{
}

Person::Person(uint64_t id, uint64_t personality)
	: m_id(id), m_personality(personality), 
	m_money(1000), m_energy(100), 
	m_experience(0), m_maxEnergy(100)
{
}


Person::Person(uint64_t id, double money)
	: m_id(id), m_personality(MiddleGround), 
	m_money(money), m_energy(100), 
	m_experience(0), m_maxEnergy(100)
{
}

Person::Person(uint64_t id, double money, double energy)
	: m_id(id), m_personality(MiddleGround),
	m_money(money), m_energy(energy),
	m_experience(0), m_maxEnergy(100)
{
}

Person::Person(uint64_t id, double money, double energy, double experience)
	: m_id(id), m_personality(MiddleGround), 
	m_money(money), m_energy(energy), 
	m_experience(experience), m_maxEnergy(100)
{
}


Person::Person(uint64_t id, double money, double energy, double experience, std::weak_ptr<Account> account)
	: m_id(id), m_personality(MiddleGround),
	m_money(money), m_energy(energy),
	m_experience(experience), m_maxEnergy(100),
	m_account(account)
{
}

uint64_t Person::GetId() const
{
	return m_id;
}

double Person::GetMoney() const
{
	return m_money;
}

double Person::GetEnergy() const
{
	return m_energy;
}

double Person::GetExperience() const
{
	return m_experience;
}

std::shared_ptr<Account> Person::GetAccount() const
{
	if (const auto& account = m_account.lock())
	{
		return account;
	}

	return nullptr;
}

double Person::GetAccountMoney() const
{
	if (const auto& account = m_account.lock())
	{
		return account->GetMoney();
	}

	return NULL;
}

void Person::SetId(uint64_t id)
{
	m_id = id;
}

void Person::SetMoney(double money)
{
	m_money = money;
}

void Person::SetEnergy(double energy)
{
	m_energy = energy;
}

void Person::SetExperience(double experience)
{
	m_experience = experience;
}

void Person::SetAccount(std::weak_ptr<Account> account)
{
	m_account = account;
}

void Person::IncreaseMoney(double amount)
{
	m_money += amount;
}

void Person::DecreaseMoney(double amount)
{
	m_money -= amount;
}

void Person::IncreaseEnergy(double amount)
{
	if (m_energy + amount > m_maxEnergy)
	{
		SetEnergy(m_maxEnergy);
		return;
	}

	m_energy += amount;
}

void Person::DecreaseEnergy(double amount)
{
	m_energy -= amount;
}

void Person::IncreaseExperience(double amount)
{
	m_experience += amount;
}

void Person::DecreaseExperience(double amount)
{
	m_experience -= amount;
}

void Person::Work()
{
	DecreaseEnergy(CalculateEnergyLoss());
	IncreaseMoney(CalculateMoneyGain());
	IncreaseExperience(CalculateExperienceGain());
}

void Person::Deposit(double amount)
{
	DecreaseMoney(amount);
	GetAccount()->IncreaseMoney(amount);
}

void Person::Sleep()
{
	IncreaseEnergy(CalculateEnergyGain());
}

void Person::TakeLoan(double amount)
{
	IncreaseMoney(amount);
	GetAccount()->IncreaseLoan(amount);
}

void Person::PayLoan(double amount)
{
	DecreaseMoney(amount);
	GetAccount()->DecreaseLoan(amount);
}

double Person::CalculateMoneyGain() const
{
	double gain = 50 + m_experience / 500;
	return gain;
}

double Person::CalculateEnergyLoss() const
{
	double energyLoss = 30 - m_experience / 500;
	return energyLoss;
}

double Person::CalculateEnergyGain() const
{
	double energyGain = 45 + m_experience / 500;
	return energyGain;
}

double Person::CalculateMaxEnergy() const
{
	double maxEnergy = 100 + m_experience / 1000;
	return maxEnergy;
}

double Person::CalculateExperienceGain() const
{
	return (double)generateRandomNumber(20, 50 + (int)m_experience / 1000);
}

void Person::Print() const
{
	std::string personality;
	
	if (m_personality == Disciplined)
		personality = "Disciplined";
	else if (m_personality == MiddleGround)
		personality = "MiddleGround";
	else if (m_personality == Lazy)
		personality = "Lazy";

	std::locale::global(std::locale("en_US.UTF-8"));
	std::cout.imbue(std::locale());
	std::cout << std::showpoint;
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Person ID: " << m_id << "\n";
	std::cout << "Personality type: " << personality << "\n";
	std::cout << "Experience: " << m_experience << "\n";
	std::cout << "Person money: $" << m_money << "\n";
	std::cout << "Account money: $" << GetAccountMoney() << "\n";
	std::cout << "Person energy: E" << m_energy << "\n";
	std::cout << "**********************" << "\n";
}

bool Person::CanWork() const
{
	if (m_energy - 30 > 0)
		return true;
	return false;
}

bool Person::WillingToWork() const
{
	double chance{ 0.5 };

	if (m_personality == Disciplined)
		chance = 0.8;
	else if (m_personality == MiddleGround)
		chance = 0.6;
	else if (m_personality == Lazy)
		chance = 0.25;

	int randomNum = generateRandomNumber(0, 1000);

	if (randomNum < 1000 * chance)
		return true;
	return false;
}

void Person::WorkLoop()
{
	while (CanWork() && WillingToWork())
	{
		Work();
	}
}


void Person::Update()
{
	WorkLoop();
	Sleep();
	Deposit(m_money / 2);
	m_maxEnergy = CalculateMaxEnergy();
}

