#include <iostream>
#include <ctime>
#include <string>
using namespace std;
void clrscr() //function to clear screen
{
    cout << "\033[2J\033[1;1H";
}
void sleep(float seconds) //Foe time delay
{
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while (clock() < startClock + secondsAhead)
        ;
    return;
}
class Player
{
public:
    string username;
    int score = 0;
    int difficulty;
    int target;
    void inputusername()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHello \n";
        cout << "Enter the username : ";
        getline(cin, username);
        welcome();
    }
    void welcome()
    {
        sleep(1.0);
        clrscr();
        cout << "Welcome " << username << endl
             << endl;
    }
    void difficultylevel() //1for easy 2 for medium 3 for difficult
    {
        cout << "Choose a difficulty level \n";
        cout << "\t\t\t\t\t\t\t\t1.)Easy(Maximum 100 points)\n";
        cout << "\t\t\t\t\t\t\t\t2.)Medium(Maximum 500 points)\n";
        cout << "\t\t\t\t\t\t\t\t3.)Hard(Maximum 1000 points)\n";
        cin >> difficulty;
    }
    void targetgenerator() // only considers 1,2,3 as input
    {
        if (difficulty == 1) //range of 1 to 100 in easy level
        {
            target = rand() % 100 + 1;
        }
        else if (difficulty == 2) //range of 1 to 200 in medium level
        {
            target = rand() % 200 + 1;
        }
        else if (difficulty == 3) //range of 1 to 300 in hard level
        {
            target = rand() % 300 + 1;
        }
    }
};

main()
{

    Player player1;
    player1.inputusername();
    player1.difficultylevel();
    player1.targetgenerator();
    cout << "Target is : " << player1.target; //Only tells the target to the user
    return 0;
}
