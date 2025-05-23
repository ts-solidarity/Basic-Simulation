#pragma once
#include <stdint.h>
#include <memory>

class Account;

class Person
{

public:

	enum Personalities
	{
		Lazy = 0, MiddleGround, Disciplined
	};

public:

	Person(uint64_t id);
	Person(uint64_t id, uint64_t personality);
	Person(uint64_t id, double money);
	Person(uint64_t id, double money, double energy);
	Person(uint64_t id, double money, double energy, double experience);
	Person(uint64_t id, double money, double energy, double experience, std::weak_ptr<Account> account);

	uint64_t GetId() const;
	double GetMoney() const;
	double GetEnergy() const;
	double GetExperience() const;
	std::shared_ptr<Account> GetAccount() const;
	double GetAccountMoney() const;

	void SetId(uint64_t id);
	void SetMoney(double money);
	void SetEnergy(double energy);
	void SetExperience(double experience);
	void SetAccount(std::weak_ptr<Account> account);

	void IncreaseMoney(double amount);
	void DecreaseMoney(double amount);
	void IncreaseEnergy(double amount);
	void DecreaseEnergy(double amount);
	void IncreaseExperience(double amount);
	void DecreaseExperience(double amount);

	void Work();
	void Deposit(double amount);
	void Sleep();
	void TakeLoan(double amount);
	void PayLoan(double amount);

	double CalculateMoneyGain() const;
	double CalculateEnergyLoss() const;
	double CalculateEnergyGain() const;
	double CalculateMaxEnergy() const;
	double CalculateExperienceGain() const;

	void Print() const;

	bool CanWork() const;
	bool WillingToWork() const;

	void WorkLoop();

	void Update();

private:

	uint64_t m_id;
	double m_money;
	double m_energy;
	double m_experience;
	std::weak_ptr<Account> m_account;
	uint64_t m_personality;

	double m_maxEnergy;
};