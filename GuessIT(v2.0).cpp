#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int getRandomNumber();
int getPlayerNumber();
void printResult(int playerTurn);
void printHint(int randomNumber, int playerNumber);
void replayGame();
void playGuessIT();
void replay();
void clearScreen();

int main()
{
    playGuessIT();
    replay();

    return 0;
}

void playGuessIT(){
   int randomNumber = getRandomNumber();
   int playerNumber;
   int playerTurn = 0;
   do{
        playerNumber = getPlayerNumber();
        printHint(playerNumber, randomNumber);
        playerTurn++;
   }while(randomNumber != playerNumber);

   printResult(playerTurn);


}

int getRandomNumber()
{
    int number;
    cout << "Enter your number you want your friend guess: ";
    cin >> number;
    clearScreen();
    return number;
}

int getPlayerNumber()
{
    int guessNumber;
    cout << endl << "Enter your number you guess: ";
    cin >> guessNumber;
    return guessNumber;

}

void printHint(int playerNumber, int randomNumber)
{
    if(playerNumber < randomNumber){
        cout << "It's bigger than you think";
    }
    if(playerNumber > randomNumber){
        cout << "Nooo, it's smaller than you think";
    }
}

void printResult(int playerTurn)
{
    cout << "Nicee, you got it!";
    cout << "You need " << playerTurn << " turns to guess it" << endl;
    cout << "You have " << 100 - playerTurn << " points";
}

void replay()
{
    char answer;
    do{
    cout << endl << "Do you want to play this game again? (Y/N) ";
    cin >> answer;
    }while(answer != 'Y' && answer != 'N');

    if (answer == 'Y') playGuessIT();
    else cout << "Nice to make you happy!";

}
void clearScreen() {
    const int PATCH_LINES = 30;
	for (int i = 0; i < PATCH_LINES; i++) cout << endl;
}


