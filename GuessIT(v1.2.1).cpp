#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int getRandomNumber(int minNumber, int maxNumber);
char takeTheHint(int computerNumber);
int updateMaxNumber(int maxNumber, int number, char hint);
int updateMinNumber(int minNumber, int number, char hint);
int updateGuessNumber(int minNumber, int maxNumber);
bool checkTheNumber(char hint);
void printResult(int Number, int turn);
int getMinNumber();
int getMaxNumber();
void playGame();
void replayGame();

int main()
{
    playGame();
    replayGame();

    return 0;
}

void playGame()
{
    int minNumber = getMinNumber();
    int maxNumber = getMaxNumber();
    cout << "I can guess your number after max " << (int)log2(maxNumber - minNumber) + 1 << " turns" << endl;
    int computerNumber = getRandomNumber(minNumber, maxNumber);
    int computerTurn = 0;
    bool found = false;

    do{
        char hint = takeTheHint(computerNumber);
        found = checkTheNumber (hint);
        minNumber = updateMinNumber(minNumber, computerNumber, hint);
        maxNumber = updateMaxNumber(maxNumber, computerNumber, hint);
        computerNumber = updateGuessNumber(minNumber, maxNumber);
        computerTurn ++;
    }while(!found);

    printResult(computerNumber, computerTurn);

}

void replayGame()
{
    char answer;
    do{
        cout << "Do you want play it again(Y/N): ";
        cin >> answer;
    }while(answer != 'Y' && answer != 'N');

    if (answer == 'Y') playGame();
    else cout << "Hope you be happy after played it!!";
}

int getRandomNumber(int minNumber, int maxNumber)
{
    srand(time(NULL));
    return rand()%(maxNumber - minNumber) + minNumber;
}
char takeTheHint(int computerNumber)
{
    char hint;
    do{
        cout << computerNumber << " is your number ?, give me the hint, your number smaller or bigger or equal (<, >, =): ";
        cin >> hint;
    }while(hint != '<' && hint != '>' && hint != '=');

    return hint;
}

int updateMaxNumber(int maxNumber, int number, char hint)
{
    if (hint == '<') return number;
    else return maxNumber;
}

int updateMinNumber(int minNumber, int number, char hint)
{
    if (hint == '>') return number;
    else return minNumber;
}

int updateGuessNumber(int minNumber,int maxNumber)
{
    int guessNumber = (maxNumber + minNumber) / 2;
    return guessNumber;
}

bool checkTheNumber(char hint)
{
    if (hint == '=') return true;
    else return false;
}

void printResult(int Number, int turn)
{
    cout << Number << " is your number" << endl;
    cout << "I can guess it by " << turn << " turns!!" << endl;
}

int getMinNumber()
{
    cout << "Enter your range you want me guess(min, max): ";
    int minNumber;
    cin >> minNumber;
    return minNumber;
}

int getMaxNumber()
{
    int maxNumber;
    cin >> maxNumber;
    return maxNumber;
}







