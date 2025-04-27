#include <iostream>
#include <ctime>
#include <cctype>
#include <map>

const int min = 1;

int guess_randomize()
{
    int max = 0;
    int count = 0;
    std::string difficult;
    std::string yes_or_no;
    std::cout << "Choice diff -> easy, medium, hard -> ";
    std::cin >> difficult;
    for (char& c : difficult)
    {
        c = std::tolower(c);
    }
    if (difficult == "hard") { max = 10; }
    else if (difficult == "medium") { max = 5; }
    else { max = 3; }

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
            count++;
            int random_number = rand() % (max - min + 1) + min;
            std::cout << "Random number(from 1 to " << max << ") was created.Try to guess : ";
            std::cin >> x;
            if (x != random_number)
            {
                std::cout << "Nice try, but u are wrong. Random number is " << random_number << std::endl;
            }
            else
            {
                std::cout << "Good job. U are right." << std::endl;
                std::cout << "It took you " << count << " attempts\n";
                count = 0;
            }
            std::cout << "Wanna to continue? Type y/n: ";
            std::cin >> yes_or_no;
        } while (yes_or_no == "y" || yes_or_no == "Y");
    }
    else
    {
        std::cout << "Incorrect input. Code canceled." << std::endl;
        return 1;
    }
    return 0;
}

int main()
{
    srand(time(0));
    guess_randomize();
    return 0;
}
