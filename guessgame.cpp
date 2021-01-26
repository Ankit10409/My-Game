#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

void clrscr() //function to clear screen
{
    system("cls");
}

void sleep(float seconds) //For time delays to make game look professional(chutiya banane ki ninja technique)
{
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.

    while (clock() < startClock + secondsAhead)
        ;

    return;
}

class intro_outro //all the common variables about user and functions for all modes to be used
{
public:
    string username;  //to store player's user name
    string username2; //for second player in friends mode
    int mode;         //to store the mode in which user will play

    void inputusername() //takes username and calls welcome function
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

        string s[] = {"H", "E", "L", "L", "0", " ", "W", "E", "L", "C", "O", "M", "E", " ", "T", "O", " ", "T", "H", "E", " ", "G", "A", "M", "E", " ", "O", "F", " ", "G", "U", "E", "S", "S", "E", "S"};

        sleep(1.0);
        clrscr();

        cout << "\n\n\t\t\t\t\t";

        for (int i = 0; i < 36; i++)
        {
            cout << s[i];
            sleep(0.06);
        }

        sleep(1.0);

        cout << "\n\nWhat would you like me to call you? :-) ";
        getline(cin, username);

        sleep(1.0);
    }

    void welcome() //welcomes user after 1 second
    {
        clrscr();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

        cout << endl
             << endl
             << "Welcome!! " << username << endl
             << endl;

        sleep(0.08);

        cout << "LOADING PLEASE WAIT" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        for (int j = 0; j < 120; j++)
        {
            cout << '*';
            sleep(0.03);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        clrscr();
    }

    void modechoose() //for the user to choose which mode to play in
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << endl
             << "What do you want to play ";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << endl
             << "1.Campaign Mode";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        cout << endl
             << "2.Against Friend";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << endl
             << "3.Challenge Mode";
        cout << endl
             << endl
             << "Enter 1,2 or 3 : ";

        cin >> mode;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

        while (mode != 1 && mode != 2 && mode != 3)
        { //ensures that the player has entered the correct value
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Gawar samajh aata tereko ki number 1,2,3 mein se koi daalna hai?\n";
            cin >> mode;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        sleep(1);
    }

    void creditscreen() // to give the credits in the ending
    {
        clrscr();
        cout << endl
             << endl
             << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
        cout << "***********************************************************" << endl;

        cout << "      CODE CREDITS        :            NAME" << endl;

        cout << "***********************************************************" << endl;

        sleep(0.5);
        cout << "      Back end            :            Ankit" << endl;

        sleep(0.5);
        cout << "      Front end           :     Divya Deept Pandey G" << endl;

        sleep(0.5);
        cout << "      Debugging           : Divya Deept Pandey G & Gaurav " << endl;
        sleep(0.5);

        cout << "***********************************************************" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        sleep(10);
    }

} userdetails;

class campaign //all the functions and variables specific to the campaign mode
{
public:
    int iniscore = 0;
    int score = 0;
    int difficulty;
    int target;
    int uservalue;
    int userscore;
    int guessno = 0;

    void difficultylevel() //takes input for difficulty level : 1 for easy 2 for medium 3 for difficult
    {

        clrscr();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << "Choose a difficulty level(Enter 1, 2 or 3 to select level)\n";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "\t\t1.)Easy\t(Maximum 100 points)\n";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        cout << "\t\t2.)Medium\t(Maximum 500 points)\n";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\t\t3.)Hard\t(Maximum 1000 points)\n"
             << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << "The computer will generate a number" << endl
             << "From 1-50 \t In Easy Level" << endl
             << "From 1-75 \t In Medium Level" << endl
             << "From 1-100 \t In Hard Level" << endl;
        cin >> difficulty;

        while (difficulty != 1 && difficulty != 2 && difficulty != 3)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Gawar samajh aata tereko ki number 1,2,3 mein se koi daalna hai?\n"
                 << endl;
            cin >> difficulty;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
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

        clrscr();
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
            score = score - (iniscore / 20);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\nYou are a little above the target ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            return 1;
        }

        else
        {
            score = score - (iniscore / 20);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "\nYou are a little below the target ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            return 1;
        }
    }

    int scorechecker() //player loses if the score becomes less than 0
    {
        if (score <= 0)
            return 0;

        else
            return 1;
    }

    void modeintro() //tells what to do in campaign mode
    {
        clrscr();

        cout << "\n\nIn this game I will generate a random number for you" << endl
             << "You have to guess the number\n\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        for (int j = 0; j < 120; j++)
        {
            cout << '*';
            sleep(0.04);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    }
} campaignplayer;

void campaignplayerfunction() //to play the campaign mode if user wants to play campaign mode
{
    campaignplayer.modeintro();       //give  intro
    campaignplayer.difficultylevel(); //difficulty gets player difficulty level
    campaignplayer.targetgenerator();

    clrscr();

    do
    {
        if (campaignplayer.scorechecker())
            campaignplayer.takeinput(); // input is taken from user
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "You lost ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            return;
        }

    } while (campaignplayer.uservaluechecker()); //take inputs until user guesses correct answer

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    cout << "Congratulations " << userdetails.username;
    cout << "\nYou guessed correct in " << campaignplayer.guessno << " guesses\n";
    cout << "Your score is " << campaignplayer.userscore << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    sleep(5.0);
    clrscr();
}

class friends
{
public:
    char secret[2];
    int num[2] = {0, 0}; //each digit to be converted seperately
    int secretnumber;
    int player2value = 0;
    int player2guessno = 0;
    int iniscore = 1000;
    int p1score = 500;
    int p2score = 1000;

    void chartonum() //converts the character input to integer form to make it usable
    {
        for (int i = 0; i < 2; i++)
        {
            if (secret[i] == '0')
                num[i] = 0;
            else if (secret[i] == '1')
                num[i] = 1;
            else if (secret[i] == '2')
                num[i] = 2;
            else if (secret[i] == '3')
                num[i] = 3;
            else if (secret[i] == '4')
                num[i] = 4;
            else if (secret[i] == '5')
                num[i] = 5;
            else if (secret[i] == '6')
                num[i] = 6;
            else if (secret[i] == '7')
                num[i] = 7;
            else if (secret[i] == '8')
                num[i] = 8;
            else if (secret[i] == '9')
                num[i] = 9;
        }

        secretnumber = num[0] * 10 + num[1];
    }

    void modeintro() //Tells the player what is in this mode
    {
        clrscr();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

        cout << endl
             << "In this mode one player will enter a number secretely and second player will guess the number\n\n";
        sleep(1);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

        cout << userdetails.username << " is Player 1" << endl
             << "Player 2 please enter your name : ";
        getline(cin, userdetails.username2);
        getline(cin, userdetails.username2); // gives problem in one time

        sleep(2.0);
        clrscr();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

        cout << endl
             << "\n\nPlayer 1 : " << userdetails.username << " will enter the number secretely(a two digit number only)" << endl
             << "Player 2 : " << userdetails.username2 << " will guess the number\n\n " << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        for (int j = 0; j < 120; j++)
        {
            cout << '*';
            sleep(0.06);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    }

    void secretinput() //Takes the user's number secretely
    {
        clrscr();
        cout << "Enter the number :";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        secret[0] = getch();
        cout << "*";
        secret[1] = getch();
        cout << "*" << endl;

        chartonum();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        sleep(1);
    }

    void inputguess()
    {
        cout << endl;
        player2guessno++;

        sleep(1.0);
        if (player2guessno == 1)
            cout << "\nEnter your " << player2guessno << "st guess\n";
        if (player2guessno == 2)
            cout << "\nEnter your " << player2guessno << "nd guess\n";
        if (player2guessno == 3)
            cout << "\nEnter your " << player2guessno << "rd guess\n";
        if (player2guessno > 3)
            cout << "\nEnter your " << player2guessno << "th guess\n";

        cin >> player2value;
        cout << endl;

        clrscr();
    }

    int player2guesscheck()
    {
        if (player2value == secretnumber)
        {
            return 0;
        }

        else if (player2value > secretnumber)
        {
            p2score = p2score - (iniscore / 20);
            p1score = p1score + (iniscore / 20);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\nYou are a little above the target ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

            return 1;
        }

        else
        {
            p2score = p2score - (iniscore / 20);
            p1score = p1score + (iniscore / 20);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "\nYou are a little below the target ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

            return 1;
        }
    }

    int scorechecker() //player2 loses if his/her score becomes less than 0
    {
        if (p2score <= 0)
        {
            p1score = 1000;
            return 0;
        }

        else
            return 1;
    }

} friendsplayer;

void playagainstfriendfunction()
{
    friendsplayer.modeintro();
    friendsplayer.secretinput();

    do
    {
        if (friendsplayer.scorechecker())
            friendsplayer.inputguess();
        else
        {
            cout << "Player 2 " << userdetails.username2 << " Lost " << endl;
            cout << "Player 1 " << userdetails.username << " score " << friendsplayer.p1score << endl
                 << "Congratulations!! " << userdetails.username << endl
                 << "You Won" << endl;
        }

    } while (friendsplayer.player2guesscheck());

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    cout << "Congratulations!! " << userdetails.username2;
    cout << "\nYou guessed correct in " << friendsplayer.player2guessno << " guesses" << endl
         << "Your score is " << friendsplayer.p2score << endl
         << "Player 1 " << userdetails.username << " score is " << friendsplayer.p1score << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    sleep(5.0);
    clrscr();
}

class Challenge
{
public:
    int iniscore = 0;
    int score = 0;
    int target;
    int beg, end;
    int uservalue;
    int userscore = 1;
    int guessno;

    void inputrange()
    {
        clrscr();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "Enter the beginning : ";
        cin >> beg;

        clrscr();
        cout << "Enter the ending Number : ";
        cin >> end;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        clrscr();
    }

    void targetgenerator()
    {
        srand(time(NULL));
        target = rand() % (end - beg) + beg;
    }

    void scoregenerator() //generate score for target
    {
        if (end - beg <= 50)
        {
            iniscore = 100;
            score = 100;
        }
        else if (end - beg <= 75)
        {
            iniscore = 500;
            score = 500;
        }
        else if (end - beg <= 100)
        {
            iniscore = 1000;
            score = 1000;
        }
        else
        {
            iniscore = 2000;
            score = 2000;
        }
    }

    void takeinput() //take input
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

        clrscr();
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
            score = score - (iniscore / 20);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\nYou are a little above the target ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            return 1;
        }

        else
        {
            score = score - (iniscore / 20);

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "\nYou are a little below the target ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            return 1;
        }
    }

    int scorechecker() //player loses if the score becomes less than 0
    {
        if (userscore <= 0)
            return 0;

        else
            return 1;
    }

    void modeintro() //tells what to do in campaign mode
    {
        clrscr();

        cout << "\n\nIn this game you will enter a range within which computer will generate a random number for you" << endl
             << "You have to guess the number\n\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        for (int j = 0; j < 120; j++)
        {
            cout << '*';
            sleep(0.04);
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
    }

} challengeplayer;

void challengeplayerfunction()
{
    challengeplayer.modeintro();
    challengeplayer.inputrange();
    challengeplayer.targetgenerator();
    challengeplayer.scoregenerator();

    clrscr();

    do
    {
        if (challengeplayer.scorechecker())
            challengeplayer.takeinput(); // input is taken from user
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "You lost ";

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
            return;
        }
    } while (challengeplayer.uservaluechecker()); //take inputs until user guesses correct answer

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

    cout << "Congratulations " << userdetails.username;
    cout << "\nYou guessed correct in " << challengeplayer.guessno << " guesses\n";
    cout << "Your score is " << challengeplayer.userscore << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    sleep(5.0);
    clrscr();
}

int GameRunsHere() //this is where the game runs2
{
    char n;
    userdetails.inputusername(); //username gets username
    userdetails.welcome();       //user is welcomed

    do
    {
        campaignplayer.guessno = 0;
        friendsplayer.player2guessno = 0;
        userdetails.modechoose();

        switch (userdetails.mode)
        {
        case 1:
            campaignplayerfunction(); //campaign mode
            break;
        case 2:
            playagainstfriendfunction(); //friends mode (under bug fixing)
            break;
        case 3:
            clrscr();
            challengeplayerfunction();
            break;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        cout << "Do you Want To Play Again?" << endl;
        cout << "Press 1 for Yes or 2 for No" << endl;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        n = getch();

        if (n != '2')
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << n;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << n;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
        sleep(1);
        clrscr();

    } while (n != '2');

    return 0;
}

int main()
{
    GameRunsHere();

    clrscr();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << "Ciao!";

    sleep(2);
    clrscr();

    userdetails.creditscreen(); //Give us some credits please share this game and make us popular

    system("pause");
    clrscr();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    return 0;
}
