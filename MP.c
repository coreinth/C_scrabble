/*
	Description:		Scrabble game that can be played with a minimum of 2 players and a maximum of 4 players.
						Winner is determined by the amount of points per word acccumulated.
	Programmed by:		Xian Bernardo and Aila Manlangit, S14
	Last modified:		12-05-2022
	Version:			24
	Acknowledgements:	stackoverflow.com, geeksforgeeks.org, http://patorjk.com/software/taag/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

typedef char String4[4];
typedef char String5[5];
typedef char String7[7];
typedef char String10[10];
typedef char String20[20];
typedef char String100[100];

/*=====================================================================================
Function: PrintWelcome
	-> prints welcome screen
[Acknowledgements: http://patorjk.com/software/taag/]
=======================================================================================*/
void PrintWelcome()
{
	system("COLOR 0A");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t\t  _ _ _ _____ __    _____ _____ _____ _____ \n"); //1
	printf("\t\t\t\t | | | |   __|  |  |     |     |     |   __|\n"); //2
	printf("\t\t\t\t | | | |   __|  |__|   --|  |  | | | |   __|\n");//3
	printf("\t\t\t\t |_____|_____|_____|_____|_____|_|_|_|_____|\n");//4
	
}

/*=====================================================================================
Function: PrintLetsPlay
	-> prints welcome screen
[Acknowledgements: http://patorjk.com/software/taag/]
=======================================================================================*/
void PrintLetsPlay ()
{
	char enter;
	printf("\n");
	printf("\t\t\t\t    _        _   _         ___ _           \n");
	printf("\t\t\t\t   | |   ___| |_( )___    | _ \\ |__ _ _  _ \n");
	printf("\t\t\t\t   | |__/ -_)  _|/(_-<    |  _/ / _` | || |\n");
	printf("\t\t\t\t   |____\\___|\\__| /__/    |_| |_\\__,_|\\_, |\n");
	printf("\t\t\t\t                                      |__/ \n");
	
	printf("\n");
	
	printf("\t\t\t\t     ___  ___ ___    _   ___ ___ _    ___ \n");
	printf("\t\t\t\t    / __|/ __| _ \\  /_\\ | _ ) _ ) |  | __|\n");
	printf("\t\t\t\t    \\__ \\ (__|   / / _ \\| _ \\ _ \\ |__| _| \n");
	printf("\t\t\t\t    |___/\\___|_|_\\/_/ \\_\\___/___/____|___|\n");
	printf("\n");
	printf("\t\t\t============================================================\n");
	
	printf("\n");
	printf("\t\t\t\tP R E S S   A N Y   K E Y   T O   C O N T I N U E");
	enter = getch();
	if (enter != 0)
		system("cls");
}

/*=====================================================================================
Function: PrintMenu
	-> prints Main Menu
[Acknowledgements: http://patorjk.com/software/taag/]
=======================================================================================*/
void PrintMenu()
{
	system("cls");
	system("COLOR 0C");
	printf("\n");
	printf("\t\t\t\t __  __          _____ _   _   __  __ ______ _   _ _    _ \n");
	printf("\t\t\t\t|  \\/  |   /\\   |_   _| \\ | | |  \\/  |  ____| \\ | | |  | |\n");
	printf("\t\t\t\t| \\  / |  /  \\    | | |  \\| | | \\  / | |__  |  \\| | |  | |\n");
	printf("\t\t\t\t| |\\/| | / /\\ \\   | | | . ` | | |\\/| |  __| | . ` | |  | |\n");
	printf("\t\t\t\t| |  | |/ ____ \\ _| |_| |\\  | | |  | | |____| |\\  | |__| |\n");
	printf("\t\t\t\t|_|  |_/_/    \\_\\_____|_| \\_| |_|  |_|______|_| \\_|\\____/ \n");

	printf("\n");
	printf("\t\t\t\t\t Options: 1-Start new game || 2-Exit console");
}

/*=====================================================================================
Function: PrintWinner
	-> prints winner
Pre-Condition: 
	-> winner is already calculated
@param name		prints winner of game
[Acknowledgements: http://patorjk.com/software/taag/]
=======================================================================================*/
void PrintWinner(char name[])
{
	printf(" __      _____ _  _ _  _ ___ ___\n");
	printf(" \\ \\    / /_ _| \\| | \\| | __| _ \\\n");
	printf("  \\ \\/\\/ / | || .` | .` | _||   /\n");
	printf("   \\_/\\_/ |___|_|\\_|_|\\_|___|_|_\\\n");
	printf("\n");
	printf("\t\t%s\n", name);
}


/*=====================================================================================
Function: PrintExitScreen
	-> prints before exiting console
[Acknowledgements: http://patorjk.com/software/taag/]
=======================================================================================*/
void PrintExitScreen()
{
	system("cls");
	system("COLOR 0A");
	printf("\n");
    printf(" _____            __   __\n");
    printf("/  ___|           \\ \\ / /\n");
    printf("\\ `--.  ___  ___   \\ V /___  _   _ \n");
    printf(" `--. \\/ _ \\/ _ \\   \\ // _ \\| | | |\n");
    printf("/\\__/ /  __/  __/   | | (_) | |_| |\n");
    printf("\\____/ \\___|\\___|   \\_/\\___/ \\__,_|\n");
    printf("\n");
    printf("   ___              _\n");
	printf("  / _ \\            (_)\n"); 
	printf(" / /_\\ \\ __ _  __ _ _ _ __\n");
	printf(" |  _  |/ _` |/ _` | | '_ \\\n");
	printf(" | | | | (_| | (_| | | | | |\n");
	printf(" \\_| |_/\\__, |\\__,_|_|_| |_|\n");
	printf("         __/ |\n");
	printf("        |___/\n");
}

/*=====================================================================================
Function: PrintBoard
	-> prints 11 x 11 board of scrabble
Pre-Condition: 
	-> BoardArray is not empty
@param BoardArray	gets contents of BoardArray to be printed
=======================================================================================*/
void PrintBoard (char BoardArray[][11])
{
	system("cls");
	system("COLOR 0A");
	printf("\n");
	int h;
	int i;
	for (h = 0; h < 11; h++)
	{
		if (h == 0)
		{
			printf("      1   2   3   4   5   6   7   8   9  10   11 \n");
			printf("    +---+---+---+---+---+---+---+---+---+---+---+\n");
		}
		if (h < 9)
			printf ("  %d ", h+1);
		else
			printf (" %d ", h+1);
		for (i = 0;  i < 11; i++)
		{
		
			if (i == 0)
			{
				printf("|");
			}
				
			printf(" %c |", BoardArray[h][i]);
		}
		printf("\n");
		printf("    +---+---+---+---+---+---+---+---+---+---+---+\n");
	}
}

/*=====================================================================================
Function: MainMenyOptions
	-> asks input for main menu
@return main on to start new game or exit console
=======================================================================================*/
int MainMenuOptions ()
{
	int option; /*option 1 - start game
				option 2 - Exit Desktop*/
	
	do
	{
		printf("\n\nChoose an option: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: printf("\nA new game will start\n\n");
					break;
			case 2: printf("The Program will now exit\n");
					printf("Press any key to continue..\n");
					//system("pause");
					break;
			default: printf("Please choose a valid option in the main menu\n\n");
					break;
		}

	}while (option != 1 && option != 2);
	
	return option; //returns back in main on what to do
}

/*=====================================================================================
Function: UpdateLetter
	-> Updates the char from ' ' to input letter
Pre-Condition: 
	-> xAxis and yAxis is exisitng index in board
	-> letter is a valid letter
@param BoardArray	2D array of board
@param Letter 		input letter
@param xAxis		column index
@param yAxis		row index
=======================================================================================*/
void UpdateLetter (char BoardArray[][11], char Letter, int xAxis, int yAxis)
{
	BoardArray[yAxis][xAxis] = Letter;
}

/*=====================================================================================
Function: initializeArray
	-> function initializes the BoardArray to spaces 
Pre-Condition: 
	-> BoardArray is called
	-> called only at the start of game/s
@param BoardArray	2D array of board
=======================================================================================*/
void initializeArray (char BoardArray[][11])
{
	int i;
	int j;
	for (i = 0; i < 11; i++)
	{
		for(j = 0; j < 11; j++)
		{
			BoardArray[i][j] = ' ';
		}
	}
}

/*=====================================================================================
Function: dispWordOnBoard
	-> function updates the letters on board based on the input word
	-> skips index where it is connected to another word
Pre-Condition: 
	->input word is valid
	->needed inputs are valid and checked (i.e. index of x, y, length of word, etc.)
	->selected indices are connected to an existing word on the board
	->index where it is connected on board is the same letter
	
@param BoardArray	2D array of board
@param word 		valid input word
@param len			length of word
@param x			starting x index (column)
@param y			starting y index (row)
@param pos			across or downward
=======================================================================================*/
void dispWordOnBoard (char BoardArray [][11], String10 word, int len, int x, int y, int pos)
{
	//x = row; y = column;
	int j;
	j = 0;
	
	while(j < len)
	{
		word[j] = toupper(word[j]);
		j++;
	}
	
	j = 0;
	if (pos == 1) //across
	{
		while (j < len)
		{
			UpdateLetter (BoardArray, word[j], x+j, y);
			j++;
		}
	}
	else if (pos == 2) //downward
	{
		while (j < len)
		{
			UpdateLetter (BoardArray, word[j], x, y+j);
			j++;
		}
	}
}

/*=====================================================================================
Function: DisplayMenuInG
	-> Opt 1 - make a move
	-> Opt 2 - Start new game, asks for input again
	-> Opt 3 - returns to main menu
@return option to main
=======================================================================================*/
int DisplayMenuInG () 
{
	int option; /*option 1 - Make a move
				option 2 - start new game
				option 3 - exit to main menu*/
	
	printf("\nOption 1: Make a move\n");
	printf("Option 2: Start a new game\n");
	printf("Option 3: Exit to main menu\n\n");
	
	do
	{
		printf("What would you like to do: ");
		scanf("%d", &option);
		
		if (option < 1 || option > 3)
			printf("Please choose a valid option in the menu\n\n");
		
	}while (option < 1 || option > 3);
	
	return option; //returns back in main on what to do
}


struct inGPlayerData //structure to be used for storing a player in game's data
{
	String5 name;
	String7 lettersAvailable;
	int words; //Word count
	int points; //Accumulated Points in Game
};

typedef struct inGPlayerData InGPlayerData;

struct storePlayerData //structure to be used for the stored players data overall
{
	String10 name;
	String10 LWord; //Longest Word
	int HScore; //Highest Score
	int GameNo; //Accumulated Games
	int AvgScore; //Average Score
};

typedef struct storePlayerData StorePlayerData;
typedef struct storePlayerData LoadData;

struct gameData // structure for current Game information
{
	String100 letterSet;
	int validWordCount;
};

typedef struct gameData GameData;

/*=====================================================================================
Function: initStorePlayerData
	-> initializes assigned struct StorePlayerData of player to null or 0 before reading for text file
Pre-Condition: 
	-> Player struct is empty
@param Player	struct of StorePlayerData
=======================================================================================*/
void initStorePlayerData (StorePlayerData* Player)
{
	strcpy(Player->name, " ");
	strcpy(Player->LWord," ");
	Player->HScore = 0;
	Player->GameNo = 0;
	Player->AvgScore = 0;
}

/*=====================================================================================
Function: initInGPlayerData
	-> initializes assigned struct InGPlayerData of player to 0 before starting a game
Pre-Condition: 
	-> Player is an array of struct
	-> called only during start of new game
@param Player		array of struct InGPlayerData
@param playernum	specific player being accessed\initialized
=======================================================================================*/
void initInGPlayerData(InGPlayerData Player[], int playernum)
{
	Player[playernum].words = 0;
	Player[playernum].points = 0;
}

/*=====================================================================================
Function: updatePlayerScore
	-> increases player score based on points per letter.
Pre-Condition: 
	-> Player is an array of struct
	-> inputtedWord is valid
@param inputtedWord			word to be scored
@param playernum			player who submited word
@param len					length of inputed word
@param InGPlayerTag			array of struct InGPlayerData
=======================================================================================*/
void updatePlayerScore(char inputtedWord[], int playernum, InGPlayerData InGPlayerTag[])
{
	int i = 0, len;
	
	len = strlen(inputtedWord);
	
	while(i < len)
	{
		inputtedWord[i] = toupper(inputtedWord[i]);
		i++;
	}
	
	i = 0;
	
	printf("here");
	while(i < len)
	{
		switch(inputtedWord[i])
		{
			case 'A':
			case 'E':
			case 'I':
			case 'L':
			case 'N':
			case 'O':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
				InGPlayerTag[playernum].points += 1;
				break;
			case 'D':
			case 'G':
				InGPlayerTag[playernum].points += 2;
				break;
			case 'B':
			case 'C':
			case 'M':
			case 'P':
				InGPlayerTag[playernum].points += 3;
				break;
			case 'F':
			case 'H':
			case 'V':
			case 'W':
			case 'Y':
				InGPlayerTag[playernum].points += 4;
				break;
			case 'K':
				InGPlayerTag[playernum].points += 5;
				break;
			case 'J':
			case 'X':
				InGPlayerTag[playernum].points += 8;
				break;
			case 'Q':
			case 'Z':
				InGPlayerTag[playernum].points += 10;
			default:
				InGPlayerTag[playernum].points += 0;
		}
		i++;
	}
}

/*=====================================================================================
Function: updateBoardValidWords
	-> increases global valid wordcount
@param *GameDataTag 	struct of GameData, count will be stored here
=======================================================================================*/
void updateBoardValidWords(GameData *GameDataTag)
{
	GameDataTag->validWordCount++;
}

/*=====================================================================================
Function: updatePlayerVallidWords
	-> increases player's valid word count
@param playernum 		player who will get their words increased
@param InGPlayerTag		array of struct InGPlayerData
=======================================================================================*/
void updatePlayerValidWords(int playernum, InGPlayerData InGPlayerTag[])
{
	InGPlayerTag[playernum].words++;
}

/*=====================================================================================
Function: getPlayerLetters
	-> initializes letterSet to contain all valid letters for the game.
Pre-Condition: 
	-> letters will come from a file 
@param GameDataTag	struct of GameData, where data will be stored
@param playernum	specific player being accessed\initialized
@param *fp			file pointer
@param tempset		temporary set to place letters in before leterSet
=======================================================================================*/
void getPlayerLetters(GameData *GameDataTag) 
{
	FILE *fp;
	String100 tempSet;
	int i = 0;
	
	fp = fopen("availableletters.txt", "r");
	while (fgets(tempSet, 3, fp)) 
	{
		GameDataTag->letterSet[i] = tempSet[0];
		i++;
	}
	
	fclose(fp);
}

/*=====================================================================================
Function: displayLetters
	-> displays current player's available letters
Pre-Condition: 
	-> InGPlayerTag is an array of struct
@param InGPlayerTag		array of struct InGPlayerData
@param playernum		specific player being accessed
=======================================================================================*/
void displayLetters(InGPlayerData InGPlayerTag[], int playernum)
{
	int i = 0;
	
	printf("Your available letters:\n");
	
	while(i < 7)
	{
		printf("%d-%c ", i, InGPlayerTag[playernum].lettersAvailable[i]);
		i++;	
	}
	printf("\n\n");
}

/*=====================================================================================
Function: removeLetter
	-> removes used letter from letterSet
@param *GameDataTag		contains letterSet data
=======================================================================================*/
void removeLetter(GameData *GameDataTag, int i) 
{
	while(GameDataTag->letterSet[i] != '\0')
	{
		GameDataTag->letterSet[i] = GameDataTag->letterSet[i+1];
		i++;
	}	
}

/*=====================================================================================
Function: getRandomIndex
	-> returns a random number from 0 to how many letters are remaining
@param *availableLetters	global count of how many letters remain in letterSet

@returns pseudo-randomly generated number
=======================================================================================*/
int getRandomIndex(int *availableLetters) 
{
	int j;
	
	j = rand() % *availableLetters;	
	return j;
}

/*=====================================================================================
Function: removeLettersInHand
	-> removes player letters used that turn
Pre-Condition: 
	-> InGPlayerTag is and array of struct
@param inputtedWord		word whose letters will be checked
@param playerno			specific player being accessed\initialized
@param InGPlayerTag		array of struct InGPlayerData, contains player letters available
@param len				length of inputtedWord
=======================================================================================*/
void removeLettersInHand(char inputtedWord[], int playerno, InGPlayerData InGPlayerTag[])
{
	int i = 0, j = 0, len;
	len = strlen(inputtedWord);
	
	while(i < len)
	{
		j = 0;
		while(j < 7)
		{
			if(inputtedWord[i] == InGPlayerTag[playerno].lettersAvailable[j])
			{
				InGPlayerTag[playerno].lettersAvailable[j] = '\0';
				j = 6;
			}
			j++;
		}
		i++;
	}
}

/*=====================================================================================
Function: refreshlettersInHand
	-> refreshes letters in player hand back to seven every end of turn
Pre-Condition: 
	-> InGPlayerTag is and array of struct
@param inputtedWord		word whose letters will be checked
@param playernum		specific player being accessed\initialized
@param InGPlayerTag		array of struct InGPlayerData, contains player letters available
@param rNum				pseudo-random number generated
=======================================================================================*/
void refreshLettersInHand(InGPlayerData InGPlayerTag[], GameData *GameDataTag, int playernum, int *availableLetters) 
{
	int rNum, i = 0;
	
	while(i < 7)
	{
		if(InGPlayerTag[playernum].lettersAvailable[i] == '\0')
		{	
			rNum = getRandomIndex(availableLetters);
			InGPlayerTag[playernum].lettersAvailable[i] = GameDataTag->letterSet[rNum];
			*availableLetters = *availableLetters - 1;
			removeLetter(GameDataTag, rNum);
		}
		i++;
	}
}

/*=====================================================================================
Function: swapLetter
	-> swaps 1 letter between player's hand and letterSet
Pre-Condition: 
	-> InGPlayerTag is and array of struct
@param InGPlayerTag			array of struct InGPlayerData, contains player letters available
@param *GameDataTag			array of struct GameData, contains letterSet
@param playernum			specific player being accessed\initialized
@param swap					index of letter in player hand
@param *availableletters	global count of how many letters are left in letterSet
@param rNum					pseudo-random number generated
@param tempLetter			temporarily stores player letter for swapping
=======================================================================================*/
void swapLetter(InGPlayerData InGPlayerTag[], GameData *GameDataTag, int playernum, int swap, int *availableLetters) 
{
	int rNum;
	char tempLetter;
	
	rNum = getRandomIndex(availableLetters);
	tempLetter = InGPlayerTag[playernum].lettersAvailable[swap];
	InGPlayerTag[playernum].lettersAvailable[swap] = GameDataTag->letterSet[rNum];
	GameDataTag->letterSet[rNum] = tempLetter;
}

/*=====================================================================================
Function: giveStartingLetters
	-> gives player seven letters at the start of the game
Pre-Condition: 
	-> InGPlayerTag is and array of struct
@param InGPlayerTag			array of struct InGPlayerData, contains player letters available
@param *GameDataTag			array of struct GameData, contains letterSet
@param playernum			specific player being accessed\initialized
@param *availableletters	global count of how many letters are left in letterSet
@param rNum					pseudo-random number generated
=======================================================================================*/
void giveStartingLetters(InGPlayerData InGPlayerTag[], GameData *GameDataTag, int playernum, int *availableLetters)
{
	int rNum;
	int i = 0;
	
	while (i < 7)
	{
		rNum = getRandomIndex(availableLetters);
		InGPlayerTag[playernum].lettersAvailable[i] = GameDataTag->letterSet[rNum];
		removeLetter(GameDataTag, rNum);
		*availableLetters = *availableLetters - 1;
		i++;
	}
}

/*=====================================================================================
Function: checkValidLetters
	-> checks if the letters that will be used is part of player's hand
Pre-Condition: 
	-> InGPlayerTag is and array of struct
@param usedLetters		user input of what letters player used that turn
@param playernum 		specific player being accessed\initialized
@param InGPlayerTag		array of struct InGPlayerData, contains player letters available
@param len				length of usedLetters

@returns 1 if used letters match available letters, 0 if not
=======================================================================================*/
int checkValidLetters(char usedLetters[], int playernum, InGPlayerData InGPlayerTag[])
{
	int i = 0, j = 0, len, check = 0;

	len = strlen(usedLetters);
	
	while(i < len)
	{
		usedLetters[i] = toupper(usedLetters[i]);
		i++;
	}
	
	i = 0;
	while(i < len)
	{
		j = 0;
		while(j < 7)
		{
			if(usedLetters[i] == InGPlayerTag[playernum].lettersAvailable[j] || usedLetters[i] == '*')
			{
				j = 6;
				check++;
			}
			j++;	
		}
		i++;
	}
	
	if(check == len)
		return 1;
	else
		return 0;
}

/*=====================================================================================
Function: checkValidConnectedLetter
	-> checks if letter on board matches inputted word
@param BoardArray		contains letters on board
@param x				column index
@param y				row index
@param inputtedWord		word to be checked
@param len				length of inputted word
@param check			1 if letter is valid, 0 if not found

@returns 1 if word matches board, 0 if not
=======================================================================================*/
int checkValidConnectedLetter(char BoardArray[][11], int x, int y, char inputtedWord[])
{
	int len, i = 0, j = 0, check = 0;
	len = strlen(inputtedWord);
	
	while(j < len && check == 0)
	{
		i = 0;
		while(i < len && check == 0)
		{
			if(inputtedWord[j] == BoardArray[y + i][x])
			{
				if(inputtedWord[i] == BoardArray[y + i][x])	
					check = 1;
				else
					check = 0;	
			}
			else
				check = 0;
			i++;
		}
		j++;
	}
	
	printf("\n");
	i = 0;
	j = 0;
		
	while(j < len && check == 0)
	{
		i = 0;
		while(i < len && check == 0)
		{
			if(inputtedWord[j] == BoardArray[y][x + i])
			{
				if(inputtedWord[i] == BoardArray[y][x + i])	
					check = 1;
				else
					check = 0;	
			}
			else
				check = 0;
			i++;
		}
		j++;
	}

	return check;
}

/*=====================================================================================
Function: checkValidConnectedLetter
	-> checks if inputted word is part of the dictionary file
@param inputtedWord		word to be checked
@param dictname			dictionary file, file name
@param *fp				file pointer
@param validWord		stores words from dictionary to compare to inputted word
@param flag				0 if word is found, 1 if not

@returns 1 if word is found in dictionary, 0 if not
=======================================================================================*/
int checkValidWord(char inputtedWord[], char dictname[])
{
	FILE *fp;
	String10 validWord;
	int flag = 1;
	
	fp = fopen(dictname, "r");
	
	while(flag && fgets(validWord, sizeof(validWord), fp))
	{
		validWord[strcspn(validWord, "\n")] = 0;
		if ((stricmp(validWord, inputtedWord)) == 0) 
			flag = 0;
	}
	
	fclose(fp);
	
	if (flag == 0)
		return 1;
	else
		return 0;
	
}

/*=====================================================================================
Function: dispPlayerRecord
	-> displays accessed player record from text file
Pre-Condition: 
	-> displays record for loading player record
@param Player		struct StorePlayerData 
@param PlayerNo		specific player being accessed
=======================================================================================*/
void dispPlayerRecord (LoadData Player, int PlayerNo)
{
	printf("Player %d Name: %s\n", PlayerNo, Player.name);
	printf("\tLongest word placed: %s\n", Player.LWord);
	printf("\tHighest Score: %d\n", Player.HScore);
	printf("\tTotal games played: %d\n", Player.GameNo);
	printf("\tAverage Score: %d\n", Player.AvgScore);
}

/*=====================================================================================
Function: RetrievePlayerData
	-> Loads text file for reading
Pre-Condition: 
	-> filename is exisiting text file
@param filename		filename of text file to be access
@param PlayerData	array of struct of StorePlayerData to be used to store the read file

@return count of how many player records were read
=======================================================================================*/
int RetrievePlayerData(String20 filename, LoadData PlayerData[])
{
	FILE* fp;
	int x; //checks how many data is read from scanf
	int idx; //index of data stored
	
	//dumpvalues
	String4 dname;
	String10 dLW;
	int dHS;
	int dGN;
	int dAVGS;
	
	idx = -1;
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("\nERROR: File not found.\n");
	}
	else
	{
		do
		{
			x = fscanf(fp, "%s%s%d%d%d", dname, dLW, &dHS, &dGN, &dAVGS);
			//printf ("%d", x);
			
			if (x == 5)
			{
				idx++;
				
				/*Store Data*/
				initStorePlayerData(&PlayerData[idx]);
				strcpy(PlayerData[idx].name, dname);
				strcpy(PlayerData[idx].LWord, dLW);
				PlayerData[idx].HScore = dHS;
				PlayerData[idx].GameNo = dGN;
				PlayerData[idx].AvgScore = dAVGS;
				
				/*Display Data*/
				dispPlayerRecord(PlayerData[idx], idx+1);
			}
		}while (idx < 9 && x == 5);
		
		fclose (fp);
		
		if (idx == 9)
		{
			printf("Max no. of storage has been reached");
		}
		printf ("%d player data loaded. Load complete\n", idx+1);
	}
	
	return idx+1;
}

/*=====================================================================================
Function: DisplayPlayerData
	-> displays current player data
Pre-Condition: 
	-> PlayerNo is in index form
@param Player[]		array of InGPlayerData
@param PlayerNo		index of array to access
=======================================================================================*/
void DisplayPlayerData (InGPlayerData Player[], int PlayerNo) //display current words and points
{
	printf("Player %d: %s\n", PlayerNo+1, Player[PlayerNo].name);
	printf("\tPlayer points: %d\n", Player[PlayerNo].points);
	printf("\tPlayer words: %d\n", Player[PlayerNo].words);
}

/*=====================================================================================
Function: NoOfPlayers
	-> asks integer input of how many are playing

@return how many are playing
=======================================================================================*/
int NoOfPlayers () //Asks how many are playing
{
	int TotalPlayers;
	printf("How many are playing?: ");
	scanf("%d", &TotalPlayers);
	
	return TotalPlayers;
}

/*=====================================================================================
Function: AskPlayerNames
	-> asks if returning player or not, if yes load from text file, if no create new record - ask for name
Pre-Condition: 
	-> PlayerData is where to store loaded data, MAX of 10 is loaded
	-> Player is MAX of 4
@param PlayerData[]		array of struct of StorePlayerData to be used to store the read file
@param PlayerData		array of struct of InGPlayerData to be used to store player's data
@param PlayerNo			index of player
=======================================================================================*/
void AskPlayerNames (StorePlayerData PlayerData[], InGPlayerData Player[], int PlayerNo)
{
	char ans;
	int access; 
	int count;
	
	char filename[21];
	
	do
	{
		printf("\nReturning player?(Y or N): ");
		scanf(" %c", &ans);
	}while ((ans != 'y' && ans != 'Y') && (ans != 'n' && ans != 'N'));
	
	
	if (ans == 'y' || ans == 'Y')
	{
		printf("Player record filename: ");
		scanf("%s", filename);
		count = RetrievePlayerData(filename, PlayerData);
		if (count > 0)
		{
			printf("\nWhich player data would you like to access?: ");
			scanf("%d", &access);
			access--;
			strcpy(Player[PlayerNo].name, PlayerData[access].name);
		}
		else
			ans = 'n';
	}
	if (ans == 'n' || ans == 'N')
	{
		printf("\nPlayer %d: Input your Player Name (Max. 4 char)\n", PlayerNo+1);
		printf("PLAYER NAME (Ex. XXXX): ");
		scanf("%s", Player[PlayerNo].name);
	}
}

/*=====================================================================================
Function: validIndex
	-> checks if existing index on board
Pre-Condition: 
	-> int i - is in index form (if player inputted col 1, idx is 0)
@param i	integer input from user

@return i if valid; -1 if not valid
=======================================================================================*/
int validIndex (int i) //return i if valid; 0 if change piece; -1 if not valid
{
	if (i > -1 && i < 11)
		return i;
	else
	{
		printf("ERROR: Input not an index in board.\n");
		return -1;	
	}
}

/*=====================================================================================
Function: validPos
	-> checks if string is valid
Pre-Condition: 
	-> input is string
@param input	string input from user

@return 1 - across
		2 - downward
		0 - not a valid input
=======================================================================================*/
int validPos (char input[]) //return 1 if across; 2 if down; 0 if not valid
{
	if (stricmp(input, "ACROSS") == 0)
		return 1;
	if (stricmp(input, "DOWNWARD") == 0)
		return 2;
	return 0;
}

/*=====================================================================================
Function: checkCenter
	-> checks if desired input is in the center
Pre-Condition: 
	-> only called if its the first word input on board
	-> all input is validated
@param pos	integer of position of word (1: across, 2: downward)
@param x	integer input of starting column index
@param y 	integer input of starting row index
@param len	integer input of length of word

@return 1 if in center 0 if not in center
=======================================================================================*/
int checkCenter (int pos, int x, int y, int len)
{
	int flag = 0; // 0 if not center; 1 if center
	int j;
	
	if (pos == 2) //downward
	{
		if (x == 5)
		{
			j = 0;	
			while (flag == 0 && j < len)
			{
				if ((j+y) == 5)
					flag = 1;
				j++;
			}
		}
	}
	else
	{
		if (y == 5)
		{
			j = 0;	
			while (flag == 0 && j < len)
			{
				if ((j+x) == 5)
					flag = 1;
				j++;
			}
		}
	}	
	return flag;
}

/*=====================================================================================
Function: checkConnected
	-> checks if desired input is connected to an existing letter on the board
Pre-Condition: 
	-> called if 2nd+ input of word
	-> all input is validated
@param BoardArray	char array of board to check if occupied
@param pos			integer of position of word (1: across, 2: downward)
@param x			integer input of starting column index
@param y 			integer input of starting row index
@param len			integer input of length of word

@return index on board if connected, returns -1 otherwise
=======================================================================================*/
int checkConnected (char BoardArray[][11], int pos, int x, int y, int len)
{
	int flag = 0; // 0 if not connected; index if connected
	int j;
	
	if (pos == 2) //downward
	{
		j = 0;
		while (flag == 0 && j < len)
		{
			if ((BoardArray[y+j][x]) != ' ')
				flag = 1;
			j++;
		}
		if (flag == 1)
		{
			//printf("Connected at y: %d\n", y+j);
			return y+j;
		}
	}
	else
	{
		j = 0;
		while (flag == 0 && j < len)
		{
			if ((BoardArray[y][x+j]) != ' ')
				flag = 1;
			j++;
		}
		if (flag == 1)
		{
			//printf("Connected at x: %d\n", x+j);
			return x+j;
		}	
	}
	return -1;
}

/*=====================================================================================
Function: checkWinner
	-> checks winner of game
	-> accesses array of struct trhough idx(count) and compares points
Pre-Condition: 
	-> called if there are 12 valid words inp on board
@param InGPlayers	array of struct of InGPlayerData for accessing
@param noOfPlayers	How many players were playing

@return index of array of who had the most points
=======================================================================================*/
int checkWinner (InGPlayerData InGPlayers[], int noOfPlayers)
{
	int count;
	int highestPts;
	
	count = 0;
	highestPts = 0;
	while (count < noOfPlayers)
	{
		if (InGPlayers[highestPts].points < InGPlayers[count].points)
			highestPts = count;
		count++;
	}
	
	return highestPts;
}

/*=====================================================================================
Function: convSwapChoice
	-> converts char into int
Pre-Condition: 
	-> choice is a character
@param choice	char input from user

@return int equivalent; -1 if not a valid choice
=======================================================================================*/
int convSwapChoice (char choice)
{
	if (choice == '0')
		return 0;
	else if (choice == '1')
		return 1;
	else if (choice == '2')
		return 2;
	else if (choice == '3')
		return 3;
	else if (choice == '4')
		return 4;
	else if (choice == '5')
		return 5;
	else if (choice == '6')
		return 6;
	else
		return -1;
}

/*=====================================================================================
Function: convLen
	-> converts char into int
Pre-Condition: 
	-> choice is a character
@param choice	char input from user

@return int equivalent; -1 if not a valid choice
=======================================================================================*/
int convLen (char choice)
{
	if (choice == '3')
		return 3;
	else if (choice == '4')
		return 4;
	else if (choice == '5')
		return 5;
	else if (choice == '6')
		return 6;
	else if (choice == '7')
		return 7;
	else if (choice == '8')
		return 8;
	else if (choice == '9')
		return 9;
	else
		return -1;
}

/*=====================================================================================
Function: PlayerTurn
	-> main function of choices during making a move
	-> player can choose whether to swap their current letters or input a word on the board
Pre-Condition: 
	-> dictname is a valid text file for dictionary
@param InGPlayerTag	array of struct of InGPlayerData
@param PlayerNo		Player being accessed
@param BoardArray	char array of board of letters stored
@param RoundNo		for checking if connected or in center
@param GameDataTag	where game data is stored
@param availableletters	accessing which letters are still available for use
@param dictname[]	dictionary text file

@return choice of player
=======================================================================================*/
int PlayerTurn (InGPlayerData InGPlayerTag[], int PlayerNo, char BoardArray[][11], int RoundNo, GameData *GameDataTag, int *availableLetters, char dictname[])
{
	bool ValidInp = false;
	bool errorCheck = false;
	char choice;
	int swap;
	char retChoice = 'X';
	int len;
	int x;
	int y;
	int validPosition;
	int invalidWord = 0;
	

	while (retChoice == 'X' || retChoice == 'x')
	{
		PrintBoard(BoardArray);
		printf("%s 's Turn\n", InGPlayerTag[PlayerNo].name);
		DisplayPlayerData(InGPlayerTag, PlayerNo);
		printf("\n");
		displayLetters(InGPlayerTag, PlayerNo);
		
		printf("Select:\n1. Swap Letters \n2. Input a Word\n");
		choice = getch();
		if (choice != '1' && choice != '2')
			printf("Not a valid choice.\n");
		printf("\n");

		if (choice == '1')
		{
			printf("Press [X] to return to turn choices.\n");
			printf("Select number to swap: ");
			retChoice = getch();
			if (retChoice != 'X' && retChoice != 'x')
			{
				printf("%c", retChoice);
				printf("\n");
				swap = convSwapChoice(retChoice);
				char doswap = '1';
				while(doswap == '1')
				{
					while (swap == -1)
					{
						printf("Not a valid choice.\n");
						printf("Select number to swap: ");
						scanf("%d", &swap);
					}
					swapLetter(InGPlayerTag, GameDataTag, PlayerNo, swap, availableLetters);
					printf("\n");
					displayLetters(InGPlayerTag, PlayerNo);
					
					do
					{
						printf("Swap another letter?\n 1 - Yes \n 2 - No");
						doswap = getch();
						
						if (doswap != '1' && doswap != '2')
							printf("\nNot a valid choice.\n\n");
					}while (doswap != '1' && doswap != '2');
					
					if (doswap == '1')
					{
						printf("\n");
						printf("Select number to swap: ");
						scanf("%d", &swap);
					}
					printf("\n");
				}
			}
		}
		else if (choice == '2')
		{
			printf("Press [X] to return to turn choices.\n");
			printf("Input the length of your word: ");
			retChoice = getch();
			if (retChoice != 'X' && retChoice != 'x')
			{
				while (invalidWord < 2 && ValidInp == false)
				{
					if (errorCheck == true)
					{
						PrintBoard(BoardArray);
						printf("%s 's Turn\n", InGPlayerTag[PlayerNo].name);
						DisplayPlayerData(InGPlayerTag, PlayerNo);
						printf("\n");
						displayLetters(InGPlayerTag, PlayerNo);
						
						if (RoundNo == 1)
						{
							if ((checkCenter (validPosition, x, y, len)) == 0)
								printf("ERROR: One included index must be in the center.\n\n");
						}
						else
						{
							if (checkConnected(BoardArray, validPosition, x, y, len) == -1)
								printf("ERROR: One included index must be connected to an existing letter\n\n");
						}
						
						if (((x+len) > 12) || ((y+len) > 12))
						{
							printf("ERROR: Desired input is out of bounds.\n\n");
						}
					}
					
					//--------------INPUT LENGTH OF WORD---------------------------------------------
					// length of word
					PrintBoard(BoardArray);
					printf("%s 's Turn\n", InGPlayerTag[PlayerNo].name);
					DisplayPlayerData(InGPlayerTag, PlayerNo);
					printf("\n");
					displayLetters(InGPlayerTag, PlayerNo);
					printf("Input the length of your word: ");
					printf("%c", retChoice);
					printf("\n");
					len = convLen(retChoice);
					while (len < 3 || len > 9)
					{
						printf("Input the length of your word: ");
						scanf("%d", &len);
						
						if (len < 3 || len > 9)
						printf("\nWords are at least 3 characters long\nand at most 9 characters long\n\n");
					}
					//--------------INPUT LENGTH OF WORD---------------------------------------------
						
					//-------------INPUT X and Y Axis------------------------------------------------
					bool validXY = false;
					do
					{
						//X and Y are reversed
						int validX;
						do
						{
							printf("Input starting column: ");
							scanf("%d", &x);
							x--;
							validX = validIndex(x);
						}while (validX < 0);
						
						int validY;
						do
						{
							printf("Input starting row: ");
							scanf("%d", &y);
							y--;
							validY = validIndex(y);
						}while(validY < 0);
						
						if (validX > -1 && validY > -1)
							validXY = true;
						
					}while(validXY==false);
					//-------------INPUT X and Y Axis------------------------------------------------
					
					
					//-------------ACROSS OR DOWNWARD------------------------------------------------
					//1 = across; 2 = downward;
					char pos[11];
					
					do
					{
						printf("ACROSS or DOWNWARD: ");
						scanf("%s", pos);
						validPosition = validPos(pos);
					}while(validPosition == 0);
					//-------------ACROSS OR DOWNWARD------------------------------------------------
					
					//------------checkCenter if Round 1---------------------------------------------
					if (RoundNo == 1)
					{
						if ((checkCenter (validPosition, x, y, len)) == 1)
						{
							ValidInp = true;
						}	
					}
					//------------checkCenter if Round 1---------------------------------------------
					
					//------------checkConnected-----------------------------------------------------
					if (RoundNo > 1)
					{
						if (checkConnected(BoardArray, validPosition, x, y, len) > -1)
						{
							ValidInp = true;
						}
					}
					//------------checkConnected-----------------------------------------------------
					
					//------------------checkInBoard-------------------------
					if (ValidInp == true)
					{	//x = column; y = row
						if (validPosition == 1) //across
						{
							if ((x+len) > 12)
							{
								ValidInp = false;
							}
						}
						
						if (validPosition == 2) //downward
						{
							if ((y+len) > 12)
							{
								ValidInp = false;
							}
						}
					}
					//------------------checkInBoard-------------------------
					
					if (ValidInp == false)
					{
						errorCheck = true;
					}
					
					String10 inputtedWord;
					String10 usedLetters;
					int j;
					bool ValidInp1 = false, ValidInp2 = false, ValidInp3 = false;
					
					do 
					{
						printf("What letters will you use? (Example: HC*IR): ");
						scanf("%s", usedLetters);
						printf("Input Word (Example: CHAIR): ");
						scanf("%s", inputtedWord);
						printf("\n");
						
						j = 0;
						while(j < len)
						{
							inputtedWord[j] = toupper(inputtedWord[j]);
							j++;
						}
						
						//check if valid word-----------------------------------
						if((checkValidWord(inputtedWord, dictname)) == 0)
						{	
							ValidInp = false;
							printf("ERROR: This word is not part of the dictionary.\n");
							invalidWord++;	
						}
						else
							ValidInp = true;
							
						//check if word matches with board letters
						if(GameDataTag->validWordCount > 0 && (checkValidConnectedLetter(BoardArray, x, y, inputtedWord)) == 0)
						{
							ValidInp1 = false;
							printf("ERROR: Letter on board does not match inputted word.\n");
						}
						else
							ValidInp1 = true;
						
						//check if user has valid letters-------------------------------	
						if((checkValidLetters(usedLetters, PlayerNo, InGPlayerTag)) == 0)
						{
							ValidInp2 = false;
							printf("ERROR: You do not have the right letters for this word.\n");
						}
						else
							ValidInp2 = true;
						
						if((strlen(inputtedWord)) != len)
						{
							ValidInp3 = false;
							printf("ERROR: Word lengths do not match.\n");
						}
						else
							ValidInp3 = true;
						printf("\n");
					}while(invalidWord < 2 && (ValidInp == false || ValidInp1 == false || ValidInp2 == false || ValidInp3 == false));
					
					if(invalidWord < 2)
					{
						dispWordOnBoard(BoardArray, inputtedWord, len, x, y, validPosition);
						updatePlayerScore(inputtedWord, PlayerNo, InGPlayerTag);
						removeLettersInHand(inputtedWord, PlayerNo, InGPlayerTag);
						refreshLettersInHand(InGPlayerTag, GameDataTag, PlayerNo, availableLetters);	
						updatePlayerValidWords(PlayerNo, InGPlayerTag);
						updateBoardValidWords(GameDataTag);
					}
				}
			}
		}
	}

	if (choice == '1')
		return 1;
	else
		return 2;
}

/*=====================================================================================
Function: RunGame
	-> main function of running a game
	-> displays menu in game
	-> player may choose to make a move, start a brand new game, or exit to main menu
Pre-Condition: 
	-> available letters were loaded correctly
@param BoardArray	char array of board of letters stored
@param PlayerData	array of struct of storePlayerData where to store loaded text file
@param GameDataTag	where game data is stored
@param availableletters accessing which letters are available for use

@return choice of menu option
=======================================================================================*/
int RunGame (char BoardArray[][11], StorePlayerData PlayerData[], GameData *GameDataTag, int *availableLetters)
{
	
	int option;
	int GameExit = 0;
	InGPlayerData PlayersInG[4];
	int turnchoice;
	int inpword;
	String100 dictname;
	FILE *fp;
	
	//--------START GAME-----------------------------------------------------------
	int p; //which player is playing
	p = 0; // start from player 1
	int RoundNo = 1;
	inpword = 1;
	int Players;
	int count;
	char CurrentPlayer[5];
	do
	{
		if (RoundNo == 1)
		{
			//--------------ASK NO. OF PLAYERS---------------------------------------------
			
			printf("Minimum no. of players: 2\nMaximum no. of players: 4\n\n");
			do //ask how many are playing
			{
				Players = NoOfPlayers();
				
				if (!(Players > 1 && Players < 5))
				{
					printf("\nError: Invalid no. of players\n");
					printf("Minimum no. of players: 2\nMaximum no. of players: 4\n\n");
				}		
			}while (!(Players > 1 && Players < 5));

			//--------------ASK NO. OF PLAYERS---------------------------------------------			
			
			//---------STORE PLAYER NAMES & Initialize points and word count---------------
			
			count = 0;
			while (count < Players)
			{
				AskPlayerNames(PlayerData, PlayersInG, count);
				initInGPlayerData(PlayersInG, count);
				giveStartingLetters(PlayersInG, GameDataTag, count, availableLetters);
				count++;
			}
			
			system("cls");
			initializeArray(BoardArray);
			//---------STORE PLAYER NAMES & Initialize points and word count---------------
			
			//---------SELECT WORDSET#-----------//
			printf("Input dictionary filename (EXAMPLE: wordset1.txt): ");
			scanf("%s", dictname);
			
			fp = fopen(dictname, "r");
			
			while (fp == NULL)
			{
				printf("ERROR: File not found.\n");
				fclose(fp);
				
				printf("Input dictionary filename (EXAMPLE: wordset1.txt): ");
				scanf("%s", dictname);
				
				fp = fopen(dictname, "r");
			}
			
			fclose(fp);
		
			printf("\n\n");
			system("cls");
			//---------SELECT WORDSET#-----------//
		}
		
		strcpy(CurrentPlayer, PlayersInG[p].name);
		printf("%s 's Turn\n", PlayersInG[p].name);
		option = DisplayMenuInG();
		while (option < 1 || option > 3)
		{
			printf("Not a valid option.\n");
			option = DisplayMenuInG();
		}
		switch (option)
		{
			case 1: //RunGame
					turnchoice = PlayerTurn(PlayersInG, p, BoardArray, inpword, GameDataTag, availableLetters, dictname);
					PrintBoard(BoardArray);
					p++;
					RoundNo++;
					if (turnchoice == 2)
						inpword++;
					if (p == Players) // reset to player 1
						p = 0;
					if(PlayersInG[p].points >= 88 || GameDataTag->validWordCount >= 12)
					{
						if (PlayersInG[p].points >= 88)
						{PrintWinner(PlayersInG[p].name);}
						else if (GameDataTag->validWordCount >= 12)
						{
						printf("Valid words on board has reached 12.\n");
						p = checkWinner(PlayersInG, Players);
						PrintWinner(PlayersInG[p].name);
						}
						GameExit = 1;
					}
					break;
			case 2: //StartNewGame
					p = 0;
					RoundNo = 1;
					break;
			case 3: GameExit = 1;
					break;
		}
	}while(GameExit != 1);
	
	return GameExit;
}

int main ()
{
	srand(time(NULL));
	int GameStop = 0;
	
	StorePlayerData PlayerData[10];
	GameData GameDataTag;
	char BoardArray[11][11];
	int availableLetters = 100; 
	char inp;
	
	PrintWelcome();
	PrintLetsPlay();
	
	do
	{
		PrintMenu();
		switch(MainMenuOptions())
		{
			case 1: initializeArray (BoardArray);
					getPlayerLetters(&GameDataTag);
					RunGame(BoardArray, PlayerData, &GameDataTag, &availableLetters);
					break;
			case 2: GameStop = 1;
					break; 
		}
		if (GameStop == 1)
		{
			inp = getch();
			if (inp != 0)
				PrintExitScreen();
		}
	}while (!GameStop);
	
	return 0;
}
