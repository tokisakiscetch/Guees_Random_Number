#include <iostream>
#include <ctime>

const int min{ 1 };
const int max{ 10 };

int guess_randomize()
{
	std::string yes_or_no;
	std::cout << "Ready to start? Type y/n: ";
	std::cin >> yes_or_no;

	if (yes_or_no == "n" || yes_or_no == "N")
	{
		std::cout << ":(" << std::endl;
		return 1;
	}

	else if (yes_or_no == "y" || yes_or_no == "Y")
	{
		std::cout << "Lets start our game!" << std::endl;
		do
		{
			int x;
			int random_number{ rand() % (max - min + 1) + min };
			std::cout << "Random number(from 1 to 10) was created. Try to guess: ";
			std::cin >> x;
			if (x != random_number)
			{
				std::cout << "Nice try, but u are wrong. Random number is " << random_number << std::endl;
			}
			else
			{
				std::cout << "Good job. U are right." << std::endl;
			}
			std::cout << "Wanna to continue? Type y/n: ";
			std::cin >> yes_or_no;
		}			
		while (yes_or_no == "y" || yes_or_no == "Y");
	}

	else
	{
		std::cout << "Incorrect input. Code canceled." << std::endl;
		return 1;
	}

}

int main()
{
	srand(time(0));
	guess_randomize();
}
