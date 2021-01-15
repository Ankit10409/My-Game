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
    int iniscore = 0;
    int score = 0;
    int difficulty;
    int target;
    int uservalue;
    int userscore;
    int guessno = 0;
    void inputusername() //takes username and calls welcome function
    {
        sleep(1.0);
        clrscr();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHello \n";
        cout << "Enter the username : ";
        getline(cin, username);
        welcome();
    }
    void welcome() //welcomes user after 1 second
    {
        sleep(1.0);
        clrscr();
        cout << "Welcome " << username << endl
             << endl;
        cout << "In this game computer will generate a random number for you \n";
    }
    void difficultylevel() //takes input for difficulty level :1for easy 2 for medium 3 for difficult
    {
        sleep(1.0);
        clrscr();
        cout << "Choose a difficulty level(Enter 1, 2 or 3 to select level)\n";
        cout << "\t\t\t\t\t\t\t\t1.)Easy(Maximum 100 points)\n";
        cout << "\t\t\t\t\t\t\t\t2.)Medium(Maximum 500 points)\n";
        cout << "\t\t\t\t\t\t\t\t3.)Hard(Maximum 1000 points)\n";
        cin >> difficulty;
    }
    int targetgenerator() // only considers 1,2,3 as input and ends program if entered any other value
    {
        if (difficulty == 1) //range of 1 to 50 in easy level
        {
            iniscore = 100;
            score = 100;
            srand(time(NULL));
            target = rand() % 50 + 1;
            return 0;
        }
        else if (difficulty == 2) //range of 1 to 75 in medium level
        {
            score = 500;
            iniscore = 500;
            srand(time(NULL));
            target = rand() % 75 + 1;
            return 0;
        }
        else if (difficulty == 3) //range of 1 to 100 in hard level
        {
            score = 1000;
            iniscore = 1000;
            srand(time(NULL));
            target = rand() % 100 + 1;
            return 0;
        }
        else
            return 1;
    }
    void takeinput() //takes user guess
    {
        cout << endl;
        guessno++;
        sleep(1.0);
        if (guessno == 1)
            cout << "\nEnter your " << guessno << "st guess\n";
        if (guessno == 2)
            cout << "\nEnter your " << guessno << "nd guess\n";
        if (guessno == 3)
            cout << "\nEnter your " << guessno << "rd guess\n";
        if (guessno > 3)
            cout << "\nEnter your " << guessno << "th guess\n";
        cin >> uservalue;
        cout << endl;
    }
    int uservaluechecker() //checks if the input is correct and calculates the score
    {
        if (uservalue == target)
        {
            userscore = score;
            return 0;
        }
        else if (uservalue > target)
        {
            score = score - (iniscore / 10);
            cout << "\nYou are a little above the target ";
            return 1;
        }
        else
        {
            score = score - (iniscore / 10);
            cout << "\nYou are a little below the target ";
            return 1;
        }
    }
    int scorechecker()
    {
        if (score < 0)
            return 0;
        else
            return 1;
    }
};

main()
{

    Player player1;
    player1.inputusername();       //username gets username
    player1.difficultylevel();     //difficulty gets player difficulty level
    if (player1.targetgenerator()) //target is generated
    {
        cout << endl
             << "You are a fucking awesome player above our game standards \n\nSo go fuck yourself\n";
        return 0;
    }
    do
    {
        if (player1.scorechecker())
            player1.takeinput(); // input is taken from user
        else
        {
            cout << "You lost ";
            return 0;
        }
    } while (player1.uservaluechecker()); //take inputs until user guesses correct answer
    cout << "Congratulations " << player1.username;
    cout << "\nYou guessed correct in " << player1.guessno << " guesses\n";
    cout << "Your score is " << player1.userscore;
    return 0;
}
