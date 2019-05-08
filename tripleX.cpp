#include <iostream>
#include<ctime>

void PrintIntroduction(int Difficulty)
{
    //Print ASCII ART (Possibly)
       

    // Output welcome messages to the game in the terminal
    std::cout << "\n\nYou're a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nYou need to enter the correct codes to contine...\n\n";
}

bool PlayGame(int Difficulty)
{
   PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print Codesum and CodeProduct to the terminal
    std::cout << std::endl;
    std::cout << "+There are three numbers in the code";
    std::cout << "\n+The code adds up to: " << CodeSum;
    std::cout << "\n+The codes multiply to give: " << CodeProduct << std::endl;

    // Store Player Guesses
    int GuessA, GuessB, GuessC; 

    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player code is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***You win! You're moving to the next level!***\n\n";
        return true;
    }
    else{
        std::cout << "\n***You Lose! PLease retry this level***\n\n";
        return false;

    } 
}

int main()  
{
    srand(time(NULL)); //create new random sequence based on the time of day

    int LevelDifficulty = 1;

    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //loop the game untill all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any erros with non numerical values being entered
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;

         }
        
    }

    std::cout << "\n***Congratulations! You're a master hacker!***";
    return 0;
}