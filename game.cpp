#include <iostream>
#include <string>
#include <ctime>

std::string GetPlayerName()
{   
    
    std::string NamePlayer;
    std::cout << std::endl;
    std::cout << "WELCOME! Insert your name to continue:\n";
    
    std::getline(std::cin, NamePlayer); // to read until the end of line
    /*
    std::cin.clear(); //Clear any errors
    std::cin.ignore(); //Discards the buffer
    */
    std::cout << std::endl;

    return NamePlayer;

}

void PrintIntroduction(int Difficulty, std::string NamePlayer)
{

    // Explaining task to player
    std::cout << "HEY THERE " << NamePlayer << "!" << std::endl;
    std::cout << std::endl;
    std::cout << "You are a secret agent on a mision. You will hack GOOGLE's level " << Difficulty << " server to steal some data that we need." << std::endl;
    std::cout << "Difficulty of levels will raise if you get each one." << std::endl;
    std::cout << std::endl;
    std::cout << "For this mission, you will get access by hacking the backdoor of the bussiness center." << std::endl;
    std::cout << std::endl;
    std::cout << "You have a lens eye microcomputer, and will guide you and will give you some advices and INFO. " << std::endl;

}

void CallingIntro(int Difficulty)
{
    std::string NamePlayer = GetPlayerName();
    PrintIntroduction(Difficulty, NamePlayer);
}

void PrintFingerPrints(int Difficulty, int ResultSum, int ResultProduct)
{

    /*Let's gonna explain a little bit more...
    We just can print out a few lines giving some advices to complete the game...
    */ 
    std::cout << std::endl;
    std::cout << " + New INFO availiable from OculusLens:\n";
    std::cout << std::endl;
    std::cout << "    + It's always a combination of three numbers. Enter them ONE BY ONE.";
    std::cout << std::endl;
    std::cout << "    + You're on level " << Difficulty << ".";
    std::cout << std::endl;
    std::cout << "    + The result of sum these numbers are: " << ResultSum << std::endl;
    std::cout << "    + The result of the product of these numbers are: " << ResultProduct << std::endl;
}

bool PlayGame(int Difficulty, int RemainingAttempts)
{

    const int a = rand() % Difficulty +  Difficulty;
    const int b = rand() % Difficulty +  Difficulty;
    const int c = rand() % Difficulty +  Difficulty;

    const int sum = a + b + c;
    const int product = a * b * c;

    // Calling the intro function
    PrintFingerPrints(Difficulty, sum, product);

    //Redirecting the user to cin
    int GuessA, GuessB, GuessC;
    std::cout << std::endl;
    std::cout << "Insert the first number: " << std::endl;
    std::cin >> GuessA;
    std::cout << "Insert the second number: " << std::endl;
    std::cin >> GuessB;
    std::cout << "Insert the third number: " << std::endl;
    std::cin >> GuessC;
    std::cout << std::endl;
    std::cout << "Combination: " << GuessA << GuessB << GuessC;

    //Saving in new variables
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;


    //We just check if guessed numbers are the right ones!
    if (GuessSum == sum && GuessProduct == product)
    {
        std::cout << " are correct."; 
        if (Difficulty + 2 == 6)
        {             
            return true;
        }   
        else (Difficulty + 2 != 6)
        {
            std::cout << " Accesing to level " << Difficulty + 1 << " server.\n";
            return true;
        }
        return true;
    }  

    else
    {
        if (RemainingAttempts > 0)
        {
            std::cout << " it's wrong. \nYou've failed! " << RemainingAttempts << " attemps remaing, be careful!" << std::endl;
            return false;
        }
        else
        {
            std::cout << " it's wrong. \n\n\nCops already come and got you. 30 years on jail... Good luck next time!";
            return false;
        }

    }

}

int main()
{   

    srand(time(NULL)); //Creates a new random sequence based on the time of the day

    int LevelDifficulty = 1;
    int const MaxLevelDifficulty = 5;
    int FailedAttempsBackCounter = 2;

    CallingIntro(LevelDifficulty);

    while (LevelDifficulty <= MaxLevelDifficulty)
    {   
        bool bLevelComplete = PlayGame(LevelDifficulty, FailedAttempsBackCounter);
        
        std::cin.clear(); //Clear any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            FailedAttempsBackCounter == 2;
        }
        else if (bLevelComplete == false) 
        {
            if (FailedAttempsBackCounter > 0)
            {
                --FailedAttempsBackCounter;
            }
            else
            {
                break;
            }
        }
        
    }
   
    std::cout << std::endl;
    std::cout << std:: endl;
    
    if (LevelDifficulty - 1 == MaxLevelDifficulty){

        std::cout << "*** Great job agent! Go back to base and prepare for the next mision! ***" << std::endl;
    }
    
    return 0;
    
}
