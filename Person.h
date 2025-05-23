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

	Person(const uint64_t& id);
	Person(const uint64_t& id, const uint64_t& personality);
	Person(const uint64_t& id, const double& money);
	Person(const uint64_t& id, const double& money, const double& energy);
	Person(const uint64_t& id, const double& money, const double& energy, const double& experience);
	Person(const uint64_t& id, const double& money, const double& energy, const double& experience, const std::weak_ptr<Account>& account);

	uint64_t GetId() const;
	double GetMoney() const;
	double GetEnergy() const;
	double GetExperience() const;
	std::shared_ptr<Account> GetAccount() const;
	double GetAccountMoney() const;

	void SetId(const uint64_t& id);
	void SetMoney(const double& money);
	void SetEnergy(const double& energy);
	void SetExperience(const double& experience);
	void SetAccount(const std::weak_ptr<Account>& account);

	void IncreaseMoney(const double& amount);
	void DecreaseMoney(const double& amount);
	void IncreaseEnergy(const double& amount);
	void DecreaseEnergy(const double& amount);
	void IncreaseExperience(const double& amount);
	void DecreaseExperience(const double& amount);

	void Work();
	void Deposit(const double& amount);
	void Sleep();
	void TakeLoan(const double& amount);
	void PayLoan(const double& amount);

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