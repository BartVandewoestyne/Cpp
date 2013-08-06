#include <iostream>
#include <string>

int main()
{
    std::string previous;
    std::string current;
    std::string winner;
    unsigned int maxNbOccurences = 0;
    unsigned int nbOccurences = 0;

    while (std::cin >> current)
    {
        if (current == previous)
        {
            nbOccurences++;
            if (nbOccurences > maxNbOccurences)
            {
                winner = current;
                maxNbOccurences = nbOccurences;
            }
        }
        else
        {
            previous = current;
            nbOccurences = 1;
        }
    }

    if (!winner.empty())
    {
        std::cout << winner << " occurs " << maxNbOccurences << " times." <<
        std::endl;
    }
    else
    {
        std::cout << "No word was repreated." << std::endl;
    }
}
