#pragma once
#include <vector>
#include <stdint.h>
#include <memory>

class Person;
class Account;

class Game
{

public:

	Game(uint64_t population);

	std::shared_ptr<Person> CreatePerson();
	std::shared_ptr<Person> CreatePersonWithPersonality(uint64_t personality);
	std::shared_ptr<Account> CreateAccount();

	void CreatePersonWithAccount();

	void Print() const;
	void PrintEveryPerson() const;
	
	void Update();

private:
	
	uint64_t m_turnCount;

	uint64_t m_globalPersonId;
	uint64_t m_globalAccountId;

	std::vector<std::shared_ptr<Person>> m_people;
	std::vector<std::shared_ptr<Account>> m_accounts;

};

