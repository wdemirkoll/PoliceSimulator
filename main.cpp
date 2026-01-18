#include <iostream>
#include <string>

std::string NickName;
std::string MyRank;

// Rank list (from lowest to highest)
std::string Rank[10]{
    "Police Officer",
    "Senior Officer",
    "Corporal",
    "Detective",
    "Sergeant",
    "Lieutenant",
    "Captain",
    "Major",
    "Chief",
    "Chief Police"
};

double Money = 0;
double XP = 5;
double Salary = 0;

// Base multipliers (will be RESET every work)
double SalaryMultiplier = 1.0;
double XPMultiplier = 1.0;

int Hunger = 100;
int Energy = 100;

int TotalWork = 0;
int Choose;

// Rank is determined by XP amount
void Rank_XP_Logic(){
    if (XP >= 50000) MyRank = Rank[9];
    else if (XP >= 45000) MyRank = Rank[8];
    else if (XP >= 40000) MyRank = Rank[7];
    else if (XP >= 35000) MyRank = Rank[6];
    else if (XP >= 30000) MyRank = Rank[5];
    else if (XP >= 20000) MyRank = Rank[4];
    else if (XP >= 10000) MyRank = Rank[3];
    else if (XP >= 5000) MyRank = Rank[2];
    else if (XP >= 2000) MyRank = Rank[1];
    else MyRank = Rank[0];
}

// Base salary depending on rank
void Rank_Salary_Logic(){
    if (MyRank == Rank[9]) Salary = 5000;
    else if (MyRank == Rank[8]) Salary = 4500;
    else if (MyRank == Rank[7]) Salary = 4000;
    else if (MyRank == Rank[6]) Salary = 3500;
    else if (MyRank == Rank[5]) Salary = 3000;
    else if (MyRank == Rank[4]) Salary = 2500;
    else if (MyRank == Rank[3]) Salary = 2000;
    else if (MyRank == Rank[2]) Salary = 1500;
    else if (MyRank == Rank[1]) Salary = 1000;
    else Salary = 500;
}

// Salary multiplier depending on rank
void Rank_Salary_Multiplier_Logic(){
    SalaryMultiplier = 1.0; // reset every work

    if (MyRank == Rank[9]) SalaryMultiplier = 4.0;
    else if (MyRank == Rank[8]) SalaryMultiplier = 3.5;
    else if (MyRank == Rank[7]) SalaryMultiplier = 3.0;
    else if (MyRank == Rank[6]) SalaryMultiplier = 2.5;
    else if (MyRank == Rank[5]) SalaryMultiplier = 2.0;
    else if (MyRank == Rank[4]) SalaryMultiplier = 1.7;
    else if (MyRank == Rank[3]) SalaryMultiplier = 1.4;
    else if (MyRank == Rank[2]) SalaryMultiplier = 1.3;
    else if (MyRank == Rank[1]) SalaryMultiplier = 1.1;
    else SalaryMultiplier = 1.0;
}

// XP multiplier depending on rank
void Rank_XP_Multiplier_Logic(){
    XPMultiplier = 1.0; // reset every work

    if (MyRank == Rank[9]) XPMultiplier = 3.5;
    else if (MyRank == Rank[8]) XPMultiplier = 3.0;
    else if (MyRank == Rank[7]) XPMultiplier = 2.5;
    else if (MyRank == Rank[6]) XPMultiplier = 2.0;
    else if (MyRank == Rank[5]) XPMultiplier = 1.5;
    else if (MyRank == Rank[4]) XPMultiplier = 1.4;
    else if (MyRank == Rank[3]) XPMultiplier = 1.3;
    else if (MyRank == Rank[2]) XPMultiplier = 1.2;
    else if (MyRank == Rank[1]) XPMultiplier = 1.1;
    else XPMultiplier = 1.0;
}

// Player statistics menu
void Statistics_Menu(){
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Name: " << NickName << std::endl;
    std::cout << "Rank: " << MyRank << std::endl;
    std::cout << "Fixed Salary: $" << Salary << std::endl;
    std::cout << "Money: $" << Money << std::endl;
    std::cout << "Total Work: " << TotalWork << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Hunger: " << Hunger << std::endl;
    std::cout << "Energy: " << Energy << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "XP: " << XP << std::endl;
    std::cout << "Salary Multiplier: " << SalaryMultiplier << "x" << std::endl;
    std::cout << "XP Multiplier: " << XPMultiplier << "x" << std::endl;
    std::cout << "----------------------------------------" << std::endl << std::endl;
}

// Main menu
void Main_Menu(){
    std::cout << "[1] - Work" << std::endl;
    std::cout << "[2] - Eat" << std::endl;
    std::cout << "[3] - Rest" << std::endl;
    std::cout << "[4] - Exit Game" << std::endl;
}

// Player name input
void Entry(){
    std::cout << "Enter your name: ";
    std::getline(std::cin, NickName);
    std::cout << "Thank you for trying my project :)" << std::endl << std::endl;
}

// Menu choice input
void ChooseFunction(){
    std::cout << "Choose: ";
    std::cin >> Choose;
}

int main(){
    Entry();

    while(true){
        Statistics_Menu();
        Main_Menu();
        ChooseFunction();

        switch (Choose){
        case 1:
            if (Hunger >= 10 && Energy >= 10){
                Hunger -= 10;
                Energy -= 10;

                // Gain XP
                XP += 100 * XPMultiplier;

                // Update rank and salary
                Rank_XP_Logic();
                Rank_Salary_Logic();
                Rank_Salary_Multiplier_Logic();
                Rank_XP_Multiplier_Logic();

                // Earn money
                Money += Salary * SalaryMultiplier;
                TotalWork++;

                std::cout << "You Worked!" << std::endl << std::endl;
            }
            else{
                std::cout << "Low hunger or energy!" << std::endl << std::endl;
            }
            break;

        case 2:
            if (Money >= 50){
                Money -= 50;
                Hunger += 10;
                if (Hunger > 100) Hunger = 100;

                std::cout << "You ate a meal for $50!" << std::endl << std::endl;
            }
            else{
                std::cout << "You need $50 to eat!" << std::endl << std::endl;
            }
            break;

        case 3:
            Energy += 10;
            if (Energy > 100) Energy = 100;

            std::cout << "You Rested!" << std::endl << std::endl;
            break;

        case 4:
            return 0;

        default:
            std::cout << "Invalid Selection!" << std::endl << std::endl;
            break;
        }
    }
}
