
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

char start;
char choose;
int wrongTurn = 0;
int topicNumber;
string topic;
void playGame();
void endGame();
string chooseTopic();
string correctWord; //the word you need to guess
string correctChoice = ""; //your correct choice will be updated here
vector <char> incorrectChoice;
vector <string> wordsToGuess;
void greeting(); //welcome to this game
void introduction(string); //introduce about the game
void printLine();
string chooseWord(); //the computer will choose a word
char enterChoice(); //enter the letter you guess
void updateResult(char); //to check the letter you guess, true or false??
void printHangman(int); //I will draw the hang-man figure here
void outOfScreen();

int main(){

	srand(time(0));
	greeting();
	if (start == 'N' || start == 'n'){
		cout << "Oh!! Good bye!!";
		return 0;
	}
	else{
		topic = chooseTopic();
		introduction(topic);
	}

	playGame();

	endGame();

	return 0;
}

void playGame(){
	correctWord = chooseWord();
	do{
		printLine();
		cout << "Please enter your guess: ";
		choose = enterChoice();
		outOfScreen();
		updateResult(choose);
		printHangman(wrongTurn);
	} while (correctChoice!=correctWord && wrongTurn<8);
}

void endGame(){
	printLine();
	if (wrongTurn==8){
		cout << "You lose!!!! Good luck next time!!! \n";
	}
	else if (correctChoice == correctWord){
		cout << "Congratulations!!! You win!!! \n";
	}
	cout << "The correct word is " << correctWord << "\n";
	cout << "Hope you be happy with this game!!! See ya!!!\n";
}


void printLine(){
	cout << "===================================\n";
}

void outOfScreen(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void greeting(){
	cout << "Welcome to Hangman Game !!! \n";
	cout << "............................\n";
	cout << "Play game ? (Y/N): \n";
	do{
		cin >> start;
	} while (start != 'Y' && start != 'N' && start != 'y' && start != 'n');
}

string chooseTopic(){
	string topic;
	cout << "You will choose topic to guess from: \n";
	cout << "1. Instruments\n";
	cout << "2. Colors\n";
	cout << "3. Characters From Movie\n";
	cout << "What is your choice? (1/2/3): ";
	cin >> topicNumber;
	switch(topicNumber){
		case 1:
			topic = "instrument";
			break;
		case 2:
			topic = "color";
			break;
		case 3:
			topic = "character";
			break;
	}
	return topic;
}

void introduction(string){
	printLine();
	cout << "You will guess word from topic: " << topic << "\n";
	cout << "If you have 8 wrong choices, you'll lose the game\n";
	cout << "Good luck!!! Try to survive!!!\n";
}

string chooseWord(){
	string fileName = topic + ".txt";
	ifstream file(fileName);
	string name;
	while(!file.eof()){
		if(!file) break;
		file >> name;
		wordsToGuess.push_back(name);
	}
	int wordCount = wordsToGuess.size();
	int randomIndex = rand() % wordCount;
	string result = wordsToGuess[randomIndex];
	int n = result.length();
	for(int i=0; i<n; i++){
		correctChoice += '_';
	}
	cout << "................................................\n";
	cout << "Your word will have " << n << " letters" << "\n";
	return result;
}

char enterChoice(){
	cin >> choose;
	return choose;
}

void updateResult(char choose){
	bool check = false;
	int n = correctWord.length();
	for(int i=0; i<n; i++){
		if (correctWord[i]==choose || correctWord[i]==(choose+32)){
			check = true;
			if(choose>='A' && choose<='Z') correctChoice[i] = choose+32;
			else correctChoice[i] = choose;
		}
	}
	if (check==false){
		wrongTurn++;
		cout << "Oh no!! That's wrong!!!\n";
		incorrectChoice.push_back(choose);
	}
	else cout << "Bingo!! That's right!!!\n";
	int m = incorrectChoice.size();
	cout << "Your correct choices: \n";
	for(int i=0; i<n; i++){
		cout << correctChoice[i] << " ";
	}
	cout << "\nYour incorrect choices: \n";
	if (m!=0){
		for(int i=0; i<m; i++){
			cout << incorrectChoice[i] << " ";
		}
	}
	cout << "\n";
}

void printHangman(int x){
	if (x==1){
        cout << "  ----------  \n";
        cout << "  |           \n";
        cout << "  |           \n";
        cout << "  |           \n";
        cout << "  |           \n";
        cout << "  |           \n";
        return;
    }
    if (x==2){
        cout << "  ----------  \n";
        cout << "  |        |  \n";
        cout << "  |           \n";
        cout << "  |           \n";
        cout << "  |           \n";
        cout << "  |           \n";
        return;
    }
    if (x==3){
        cout << "  ----------  \n";
        cout << "  |        |  \n";
        cout << "  |        o  \n";
        cout << "  |           \n";
        cout << "  |           \n";
        cout << "  |           \n";
        return;
    }
    if (x==4){
        cout << "  ----------  \n";
        cout << "  |        |  \n";
        cout << "  |        o  \n";
        cout << "  |        |  \n";
        cout << "  |           \n";
        cout << "  |           \n";
        return;
    }
    if (x==5){
        cout << "  ----------  \n";
        cout << "  |        |  \n";
        cout << "  |        o  \n";
        cout << "  |       /|  \n";
        cout << "  |           \n";
        cout << "  |           \n";
        return;
    }
    if (x==6){
        cout << "  ----------  \n";
        cout << "  |        |   \n";
        cout << "  |        o   \n";
        cout << "  |       /|\\ \n";
        cout << "  |            \n";
        cout << "  |            \n";
        return;
    }
    if (x==7){
        cout << "  ----------   \n";
        cout << "  |        |   \n";
        cout << "  |        o   \n";
        cout << "  |       /|\\ \n";
        cout << "  |       /    \n";
        cout << "  |            \n";
        return;
    }
    if (x==8){
        cout << "  ----------   \n";
        cout << "  |        |   \n";
        cout << "  |        o   \n";
        cout << "  |       /|\\ \n";
        cout << "  |       / \\ \n";
        cout << "  |            \n";
        return;
    }
}
