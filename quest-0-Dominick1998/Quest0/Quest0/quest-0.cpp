/*
        (Was getting errors on the original hangman code 
        so I implemented my own. I apologize for this 
        not being exactly like the directions.)
        HANGMAN
        Dominick Ferro
        Programming 2
        Alex Jaeger 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//The maximum amount of tries allowed is 4
const int MAX_TRIES=4;

int letterFill (char, string, string&);

//main body code 
int main ()
{
string name;
char letter;
//number of wrong guesses starts at 0
int num_of_wrong_guesses=0;

string word;
string words[] =
{
//30 countries that can be played
    "senegal",
    "serbia",
    "seychelles",
    "singapore",
    "slovakia",
    "slovenia",
    "somalia",
    "spain",
    "sudan",
    "suriname",
    "swaziland",
    "sweden",
    "switzerland",
    "syria",
    "taiwan",
    "tajikistan",
    "tanzania",
    "thailand",
    "togo",
    "tonga",
    "tunisia",
    "turkey",
    "turkmenistan",
    "tuvalu",
    "uganda",
    "ukraine",
    "uruguay",
    "uzbekistan",
    "vanuatu",
    "venezuela",
};

//choose word from array of words and copy randomly
srand(time(NULL));
int n=rand()% 10;
word=words[n];

// The hidden country is shown with the * character.
string unknown(word.length(),'*');
cout<<"+-----------+"<<endl;
cout<<"|***********|"<<endl;
cout<<"|***********|"<<endl;
cout<<"+-----------+"<<endl;

// Greet the user
cout << "\n\nWelcome to hangman...in order to begin, please guess a letter!";
cout << "\n\nEach letter is represented by a star and the letter is lowercase.";
cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

// Loop until there are no more guesses
while (num_of_wrong_guesses < MAX_TRIES)
{
cout << "\n\n" << unknown;
cout << "\n\nGuess a letter: ";
cin >> letter;

// Fill secret country with letter if the guess is correct,
// otherwise add to number of wrong guesses.
if (letterFill(letter, word, unknown)==0)
{
cout << endl << "Incorrect!" << endl;
num_of_wrong_guesses++;
}
else
{
cout << endl << "Correct!" << endl;
}
// Tell user how many guesses there are left.
cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
cout << " guesses left." << endl;

// Check if user guessed the correct word.
if (word==unknown)
{
cout << word << endl;
cout << "You win!";
break;
}

}
if(num_of_wrong_guesses == MAX_TRIES)
{
cout << "\nYou lose." << endl;
cout << "The word was : " << word << endl;
}
cin.ignore();
cin.get();
return 0;
}

/* Take one char guess and the secret word, fill in the
guessword. Returns the number of chars matched as well as 
returns zero if the character is already guessed. */
int letterFill (char guess, string secretword, string &guessword)
{
int i;
int matches=0;
int len=secretword.length();
for (i = 0; i< len; i++)
{
//Was this letter matched already in a previous guess?
if (guess == guessword[i])
return 0;

// Is the letter guessed a part of the secret word?
if (guess == secretword[i])
{
guessword[i] = guess;
matches++;
}
}
return matches;
}
//end of code
