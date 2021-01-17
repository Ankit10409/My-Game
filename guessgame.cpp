#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>
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
        sleep(1.0);
        clrscr();
        cout << "\n\n\n\n\n\t\t\t\tHello \n";
        cout << "Enter the username : ";
        getline(cin, username);
        sleep(1.0);
    }

    void welcome() //welcomes user after 1 second
    {

        clrscr();
        cout << endl
             << endl
             << "Welcome " << username << endl
             << endl;
        sleep(0.08);
        for (int j = 0; j < 165; j++)
        {
            cout << '*';
            sleep(0.02);
        }
        clrscr();
    }

    void modechoose() //for the user to choose which mode to play in
    {
        cout << endl
             << "How do you want to play ";
        cout << endl
             << "1.Campaign Mode";
        cout << endl
             << "2.Against Friend";
        cout << endl
             << "3.Challenge Mode(under construction please do not choose)";
        cout << endl
             << endl
             << "Enter 1,2 or 3 :";
        cin >> mode;
        sleep(1);
    }

    void creditscreen() // to give the credits in the ending
    {
        clrscr();
        {
            cout << "\n\n\n\n"
                 << endl;
            cout << "*************************" << endl;
            cout << "CODE CREDITS     : NAME" << endl;
            cout << "*************************" << endl;
            cout << "PATTERN LOGIC    : Ankit" << endl;
            cout << "DEBUGGING LOGIC  : Gaurav" << endl;
            cout << "*************************" << endl;
        }
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

    void difficultylevel() //takes input for difficulty level :1for easy 2 for medium 3 for difficult
    {

        clrscr();
        cout << "Choose a difficulty level(Enter 1, 2 or 3 to select level)\n";
        cout << "\t\t1.)Easy(Maximum 100 points)\n";
        cout << "\t\t2.)Medium(Maximum 500 points)\n";
        cout << "\t\t3.)Hard(Maximum 1000 points)\n"
             << endl;
        cout << "The computer will generate a number" << endl
             << "From 1-50 \t In Easy Level" << endl
             << "From 1-75 \t In Medium Level" << endl
             << "From 1-100 \t In Hard Level" << endl;
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
            score = score - (iniscore / 20);
            cout << "\nYou are a little above the target ";
            return 1;
        }
        else
        {
            score = score - (iniscore / 20);
            cout << "\nYou are a little below the target ";
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
        cout << "In this game computer will generate a random number for you" << endl
             << "You have to guess the number\n";
        sleep(5.0);
    }
};

void campaignplayerfunction() //to play the campaign mode if user wants to play campaign mode
{
    campaign campaignplayer;
    campaignplayer.modeintro();           //give  intro
    campaignplayer.difficultylevel();     //difficulty gets player difficulty level
    if (campaignplayer.targetgenerator()) //target is generated
    {
        cout << endl
             << "You are a fucking awesome player above our game standards \n\nSo go fuck yourself\n";
        return;
    }
    clrscr();
    do
    {
        if (campaignplayer.scorechecker())
            campaignplayer.takeinput(); // input is taken from user
        else
        {
            cout << "You lost ";
            return;
        }
    } while (campaignplayer.uservaluechecker()); //take inputs until user guesses correct answer

    cout << "Congratulations " << userdetails.username;
    cout << "\nYou guessed correct in " << campaignplayer.guessno << " guesses\n";
    cout << "Your score is " << campaignplayer.userscore << endl;
    sleep(5.0);
}

class friends
{
public:
    char secret[2];
    int num[2] = {0, 0}; //each digit to be converted seperately
    int secretnumber;
    int player2value;
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
        cout << endl
             << "In this mode one player will enter a number secretely and second player will guess the number" << endl
             << userdetails.username << " is Player 1" << endl
             << "Player 2 please enter your name : ";
        cin >> userdetails.username2;
        sleep(2.0);
        clrscr();
        cout << endl
             << "Player 1 : " << userdetails.username << " will enter the number secretely(a two digit number only)" << endl
             << "Player 2 : " << userdetails.username2 << " will guess the number " << endl;
        sleep(7.0);
    }

    void secretinput() //Takes the user's number secretely
    {

        clrscr();
        cout << "Enter the number :";
        secret[0] = getch();
        cout << "*";
        secret[1] = getch();
        cout << "*" << endl;
        chartonum();
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
            cout << "\nYou are a little above the target ";
            return 1;
        }
        else
        {
            p2score = p2score - (iniscore / 20);
            p1score = p1score + (iniscore / 20);
            cout << "\nYou are a little below the target ";
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
};

void playagainstfriendfunction()
{
    friends friendsplayer;
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
                 << "Congratulations " << userdetails.username << endl
                 << "You Won" << endl;
        }
    } while (friendsplayer.player2guesscheck());

    cout << "Congratulations " << userdetails.username2;
    cout << "\nYou guessed correct in " << friendsplayer.player2guessno << " guesses" << endl
         << "Your score is " << friendsplayer.p2score << endl
         << "Player 1 " << userdetails.username << " score is " << friendsplayer.p1score << endl;

    sleep(5.0);
}

main()
{

    userdetails.inputusername(); //username gets username
    userdetails.welcome();       //user is welcomed
    userdetails.modechoose();    //user is prompted to choose which mode to play in

    switch (userdetails.mode) //only campaign mode is made so any input will run campaign mode only till now
    {
    case 1:
        campaignplayerfunction(); //campaign mode
        break;
    case 2:
        playagainstfriendfunction(); //friends mode (under bug fixing)
        break;
    case 3:
        clrscr();
        cout << "Ek baar me baat samajh nahi aati kya jab bol diya ki under construction hai :/"; //challenge mode (not working yet)
        sleep(5.0);
        break;

    default:
        clrscr();
        cout << "YOU WON THE GAME" << endl
             << "NOW GO FUCK YOURSELF";
        sleep(3.0);
        break;
    }

    userdetails.creditscreen(); //Give us some credits please share this game and make us popular
    system("pause");
    clrscr();
    return 0;
}
