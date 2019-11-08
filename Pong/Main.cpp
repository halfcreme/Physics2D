#include "game.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception & e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}