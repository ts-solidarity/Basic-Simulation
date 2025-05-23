#include <iostream>
#include <stdint.h>
#include <memory>
#include <vector>
#include <string>
#include "Game.h"


int main()
{
	Game game{ 100 };
	
	std::string command;
	
	while (command != "exit" && command != "quit")
	{
		
		game.Print();
		
		std::cout << "Your command? : ";
		std::getline(std::cin, command);

		if (command == "print")
		{
			game.PrintEveryPerson();
			continue;
		}

		system("cls");
		game.Update();
	}
	
}
