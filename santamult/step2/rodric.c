#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXGUESSES 6 //Macro contains maximum guesses count
#define SIZE 20 //Macro contains maximum size of the words...
void rules(void); //display rules of the game
void maskWord (char starword[], int size); //mask the word with stars to display
int playRound(char starword[], char answer[]); //play a round of hangman
int occurancesInWord(char userguess, char answer[]); //number of times letter occurs in word
void updateStarWord(char starword[], char answer[], char userguess); //replace respective *
void playAgain(int *play); //ask user if to play again. 1 is yes 2 is no


int main()
{
char answer[SIZE]; //Array which stores the word to be guessed
char secretword[SIZE]; //Array which stores the secret word contains dashes
char letterGuessed[SIZE]; //Array which stores the word contains guessed letters
char guess[SIZE]; //Array to store the final guessing word
char userguess;
char letterPtr; //Pointer to get the letter from user

int numPtr = 0; //Stores the total number of guesses

FILE *fptr;
char fname[] = "textfile3.txt";//File contains the words to be gueesed
fptr = fopen(fname, "r"); //Opening file...
if (!fptr)
{ //File validation...
printf("\nError opening the file!!\n");

return 0;
}

do {
system("@cls||clear");
printf("\n <----------------- GUESS THE WORD ------------------>\n");

rules(); //Prints the game rules...

printf("Game started");
numPtr = 0; //Make numPtr to '0' at every new game (iteration..)
strcpy(answer, "\0"); //Clear all the words before every new game
strcpy(letterGuessed, "\0");
strcpy(secretword, "\0");

fgets(answer, SIZE, fptr); //Reads the data from file line by line...
//Since file containd '\n at end of the every line..'
int size = strlen(answer[SIZE]);

if (oneGame == 'y') {
PlayOneGame(answer, secretword);
printf("\n\t<----------------- GAME EXITED ---------------->\n\n");
fclose(fptr);
return 0;



CreateSecretWord(answer, secretword);

do {
for (i = 0; answer[i] != '\0'; i++)
printf("%c ", answer[i]);
printf("\n The word to be guessed : [ ");
for (i = 0; secretword[i] != '\0'; i++)
printf("%c ", secretword[i]);
printf("] Remaining Guesses : [%d]\n\n", (MAXGUESSES - wrongGuess));
GetTheLetterGuess(letterGuessed, letterPtr, &numPtr);
ReplaceDash(answer, secretword, letterPtr);
if(DidYouWin(answer, secretword))
break;
} while (wrongGuess < MAXGUESSES);

if(wrongGuess==MAXGUESSES)
printf("\n\t<---------- Maximum Guesses count reached, You lose the Game :( ---------->\n");
PlayAgain(play);
wrongGuess=0;
} while (play == 1);

printf("\n\t<------------------ GAME EXITED ----------------->\n\n");
fclose(fptr);
return 0;
}
}
   
void rules(void) //Prints the game rules
{
    printf("Welcome to the Hangman Game!\n");
    printf("Here are the rules.\n");
    printf("I will provide you a set of Each You must figure out each letter of the missing word.\n");
    printf("For every correct letter guessed, I will reveal its place in the word.\n");
    printf("Each mistake will result in a strike.\n");
    printf("6 strikes will result in a loss that round.\n");
   
}

//an integer that represents the number of characters for a particular solution in the round of hangman.
void maskWord(char starword[], int size) //mask the word with stars to display
{
    int i;
    for (i = 0; i < size; i++)
    starword[i] = '*'; //Initializing secretword by dashes..
    starword[i] = '\0'; //Make end as null...
}

int playRound(char starword[], char answer[]) //play a round of hangman
{
 int i = 0;
char guess[SIZE];
char letterPtr;
int numPtr = 0;
char letterGuessed[SIZE];

//LowerCaseWord(answer);
CreateSecretWord(starword, size);

do {
printf("\n The word to be guessed : [ ");
for (i = 0; secretword[i] != '\0'; i++)
printf("%c ", secretword[i]);

printf("] Remaining Guesses : [%d]\n\n", (MAXGUESSES - numPtr));

GetTheLetterGuess(letterGuessed, &letterPtr, &numPtr);

ReplaceDash(starword, answer, char userguess);

} while (numPtr < MAXGUESSES);

printf("\n\t<---------- Maximum Guesses count reached ---------->\n");
//Displaying the guessed words to the user..
printf("\n\t Find the word : [ ");
for (i = 0; starword[i] != '\0'; i++)
printf("%c ", starword[i]);

printf("]\n\n Please Guess the word by seeing the above clues : ");
scanf("%s", guess);
DidYouWin(answer, guess);

}


int occurancesInWord(char userguess, char answer[]) //number of times letter occurs in word
{
   
}

void updateStarWord(char starword[], char answer[], char userguess) //replace respective *
{
int FLAG = 1;
int i;
//Replacing the dash in the secret word by the user guessed letter
for (i = 0; answer[i] != '\0'; i++) {
//Checking whether the user entered character is present or not..
if (answer[i] == letter)
{
if (starword[i] != letter) { //Checking if already replaced..
starword[i] = letter; //Replacin dash by guessed letter..
FLAG = 0; //Conditional variable to display proper notification
}
else
FLAG = 2; //Conditional variable to display proper notification
}
}
if(FLAG==0)
printf("\n\t\t<------- Great.. Character present -----> \n");
else if (FLAG == 1)
{printf("\n\tEntered character not present..!! \n");
wrongGuess++;
}

else if (FLAG == 2)
printf("\n <--- You guessed this already/Try again ---> \n");
}


void playAgain(int *play) //ask user if to play again. 1 is yes 2 is no
{
    printf("\nDo you want to continue the game?\n");
    printf("1) Play again\n");
    printf("2) To exit\n");
    scanf(" %d", &(*play)); //Stores 1 or 2..
}
