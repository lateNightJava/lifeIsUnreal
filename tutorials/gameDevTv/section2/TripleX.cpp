#include <iostream>
#include <ctime> 

void PrintIntroduction(int LevelDifficulty)
{
    std::cout << "You are a person trying to play a game.\n";
    std::cout << "Current diffuculty level: " << LevelDifficulty << std::endl;
    std::cout << "Enter correct codes to continue...\n\n";
}

int GenerateNumber(int LevelDifficulty) 
{
    return rand() % LevelDifficulty + LevelDifficulty;
}

bool PlayGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);
    
    // note this follows Unreal naming convention
    const int CodeNumA = GenerateNumber(LevelDifficulty);
    const int CodeNumB = GenerateNumber(LevelDifficulty); 
    const int CodeNumC = GenerateNumber(LevelDifficulty);
    const int CodeSum = CodeNumA + CodeNumB + CodeNumC;
    const int CodeProduct = CodeNumA * CodeNumB * CodeNumC;

    std::cout << "+ There are 3 numbers in the code.\n";
    std::cout << "+ The numbers add up to: " << CodeSum << std::endl;
    std::cout << "+ The numbers multiply to: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct && CodeProduct) 
    {
        std::cout << "\nNice you got it.\n\n\n";
        return true;
    } 
    else 
    {
        std::cout << "\nYou were wrong.\n\n\n";
        return false;
    }
}

int main() 
{
    // changes seed of rand
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;

    while  (LevelDifficulty <= MaxDifficulty) 
    {
        bool LevelComplete = PlayGame(LevelDifficulty);
        // clears cin errors
        std::cin.clear();
        // discard input buffer
        std::cin.ignore();

        if (LevelComplete) 
        {
            LevelDifficulty++;  
        }
    } 

    std::cout << "You win the game." << std::endl;

    return 0;
}