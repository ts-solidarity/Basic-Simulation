#include <iostream>
#include <random>
#include "Game.h"
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


Game::Game(uint64_t population)
	: m_turnCount(1), m_globalPersonId(1), m_globalAccountId(1)
{
	for (size_t i = 0; i < population; i++)
	{
		CreatePersonWithAccount();
	}
}

std::shared_ptr<Person> Game::CreatePerson()
{
	std::shared_ptr<Person> newPerson = std::make_shared<Person>(m_globalPersonId);
	m_people.push_back(newPerson);
	m_globalPersonId++;
	return newPerson;
}

std::shared_ptr<Person> Game::CreatePersonWithPersonality(uint64_t personality)
{
	std::shared_ptr<Person> newPerson = std::make_shared<Person>(m_globalPersonId, personality);
	m_people.push_back(newPerson);
	m_globalPersonId++;
	return newPerson;
}

std::shared_ptr<Account> Game::CreateAccount()
{
	std::shared_ptr<Account> newAccount = std::make_shared<Account>(m_globalAccountId);
	m_accounts.push_back(newAccount);
	m_globalAccountId++;
	return newAccount;
}

void Game::CreatePersonWithAccount()
{
	uint64_t personality = (uint64_t)generateRandomNumber(0, 2);
	std::shared_ptr<Person> newPerson = CreatePersonWithPersonality(personality);
	std::shared_ptr<Account> newAccount = CreateAccount();
	
	newPerson->SetAccount(newAccount);
	newAccount->SetPerson(newPerson);
}

void Game::Print() const
{
	std::cout << "Turn: " << m_turnCount << std::endl << std::endl;
}

void Game::PrintEveryPerson() const
{
	for (auto& person : m_people)
	{
		person->Print();
	}
}


void Game::Update()
{
	for (auto& person : m_people)
	{
		person->Update();
	}

	for (auto& account : m_accounts)
	{
		account->Update();
	}

	m_turnCount++;

}