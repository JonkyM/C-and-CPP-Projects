// My class is CSE 130 and my Lab number is no. 1 
// with the Section letter A
// This program was crated using OOP concepts and derived classes learned in class
// it allows you to play a game of 3D tic tac toe against the computer

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class TicTacToe
{
private:
	
	int randNum;                                                       //used to set fturn to false or true randomly
	char grid[10] = {'0','1','2','3','4','5','6','7','8','9'};         //used to store x's and o's
	
public:
	
	TicTacToe();          //public contains the constructor 
	bool fturn;           //and multiple methods used to run the game
	void displayBoard();  //fturn determines if its the players turn (true == yes, false == no)
	int checkwin();
	void cpuPlay();
	void resetBoard();
	void placeX();
	void changeTurn();
	
};

class TicTacToe2D : public TicTacToe //derived class for the second board
{
};

class TicTacToe3D : public TicTacToe2D //derived class for the third board
{
};

	TicTacToe Game1;       //declares the TicTacToe object called Game1
	TicTacToe2D Game2;     //declares the TicTacToe2D object called Game2
	TicTacToe3D Game3;     //declares the TicTacToe3D object called Game 3
	
	// I know I shouldnt but I had to declare the objects in global so I could access their specific grid
	// in the win condition function, couldnt think of a better solution to this
	// (there is definitely a better way to do all of this)
	
int main()
{
	int boardSelection;    //variable used to store which board the player or cpu will play
	
	char rematch = 'y';    //declares and assigns value to the char that is used to check if rematch is wanted
	cout << "\n\t    Welcome to TicTacToe\n"
	     << "        ============================\n"
	     << "            (X) You      (O) Cpu\n"; 
	do //This do while loop will run untill the player decides they dont want a rematch
	{
		while(Game1.checkwin() == 0 || Game2.checkwin() == 0 || Game3.checkwin() == 0) //this while loop will run untill a win condition is met
		{
			if(Game1.fturn == true)
			{
				Game1.displayBoard(); cout << "\t\t   Board 1"; //displays all 3 boards
				Game2.displayBoard(); cout << "\t\t   Board 2";
				Game3.displayBoard(); cout << "\t\t   Board 3";
				cout << "\n\n     Which board do you want to place your X on: ";
				cin >> boardSelection;
				if(boardSelection == 1)
				{
					Game1.placeX();
				}
				else if(boardSelection == 2)
				{
					Game2.placeX();
				}
				else if(boardSelection == 3)
				{
					Game3.placeX();
				}
				
				if(Game1.checkwin() != 0 || Game2.checkwin() != 0 || Game3.checkwin() != 0)
				{
					break;
				}
				else
				Game1.changeTurn();
			}
			else if(Game1.fturn == false)
			{
				boardSelection = (rand() % 3) + 1; //generates random number between 1 and 3 to choose what board to place in
				
				if(boardSelection == 1)
				{
					Game1.cpuPlay();
				}
				else if(boardSelection == 2)
				{
					Game2.cpuPlay();
				}
				else if(boardSelection == 3)
				{
					Game3.cpuPlay();
				}
				
				if(Game1.checkwin() != 0 || Game2.checkwin() != 0 || Game3.checkwin() != 0)
				{
					break;
				}
				else
				Game1.changeTurn();
			}
		}
		
		Game1.displayBoard(); //this is used to display how the final board looks like
		Game2.displayBoard();
		Game3.displayBoard();
		
		if(Game1.checkwin() == 1 || Game2.checkwin() == 1 || Game3.checkwin() == 1) //this if-else statement tree prints out the result of the match
		{
			cout << "\n      :)========| YOU WON! |========(:\n";
		}
		else if(Game1.checkwin() == 2 || Game2.checkwin() == 2 || Game3.checkwin() == 2)
		{
			cout << "\n      :(========| YOU LOST |========):\n";
		}
		else if(Game1.checkwin() == 3 || Game2.checkwin() == 3 || Game3.checkwin() == 3)
		{
			cout << "\n      :|=======| IT\'S A TIE |=======|:\n";
		}
		Game1.resetBoard(); //this clears out the boards for the next match
		Game2.resetBoard();
		Game3.resetBoard();
		cout << "\n           Want a rematch? (y/n): ";
		cin >> rematch; //this checks if the user wants a rematch
		
	}
	while(rematch == 'y');
	cout << "\n      |========| GOOD BYE!!! |========|\n";
}

TicTacToe::TicTacToe() //constructor
{
	srand(time(0));           //seeds randomness for the game
	randNum = rand() % 2;     //generates 0 or 1 at random
	if(randNum == 0)          //if 0 is generated 
	{
		fturn = false;
	}
	else if(randNum == 1)
	{
		fturn = true;
	}
}

void TicTacToe::resetBoard() //this resets the board by assigning the array with its default starting values
{
	grid[0] = '0'; //the 0 part is unecessary but ill put it here just in case
	grid[1] = '1';
	grid[2] = '2';
	grid[3] = '3';
	grid[4] = '4';
	grid[5] = '5';
	grid[6] = '6';
	grid[7] = '7';
	grid[8] = '8';
	grid[9] = '9';
}

void TicTacToe::displayBoard() //displays the board with the current X and O positions
{
	cout << "\n"
	     << "\n\t\t    |   |   "
	     << "\n\t\t  "<< grid[1] <<" | "<< grid[2] <<" | "<< grid[3] <<" "
	     << "\n\t\t ___|___|___"
	     << "\n\t\t    |   |   "
	     << "\n\t\t  "<< grid[4] <<" | "<< grid[5] <<" | "<< grid[6] <<" "
	     << "\n\t\t ___|___|___"
	     << "\n\t\t    |   |   "
	     << "\n\t\t  "<< grid[7] <<" | "<< grid[8] <<" | "<< grid[9] <<" "
	     << "\n\t\t    |   |   \n";
}

void TicTacToe::placeX()
{
	int gridCoord;
	cout << "\n"
	     << "    Enter the number you want to place your X on: ";

	cin >> gridCoord;
	
	if(grid[gridCoord] == 'X' || grid[gridCoord] == 'O') //If statement checks if cell is occupied 
	{                                                    // and if it is it will repeatedly ask user to input another cell
	    do
	    {
			cout << "\n         This spot is already taken!\n";
			cout << "\n    Choose another place to place your X: ";
			cin >> gridCoord;
		}
		while(grid[gridCoord] == 'X' || grid[gridCoord] == 'O');
	}
	grid[gridCoord] = 'X';
}

void TicTacToe::cpuPlay() //cpu play is the same as placeX with some tweaks so it can run automatically
{
	int gridCoord;
	cout << "\n"
	     << "\t\tCPU playing... ";

	gridCoord = rand() % 9 + 1;
	
	if(grid[gridCoord] == 'X' || grid[gridCoord] == 'O') //If statement checks if cell is occupied 
	{                                                    // and if it is it will repeatedly ask user to input another cell
	    do
	    {
			gridCoord = rand() % 9 + 1;
		}
		while(grid[gridCoord] == 'X' || grid[gridCoord] == 'O');
	}
	grid[gridCoord] = 'O';
}

int TicTacToe::checkwin() //checkwin will return 0 if no win condition is met (there is definitely a better way to do this)
{                         // 1 if X wins, 2 if O wins, or 3 if its a tie
	if (grid[1] == 'X' && grid[2] == 'X' && grid[3] == 'X')
	{
		return 1;
	}
	else if (grid[1] == 'O' && grid[2] == 'O' && grid[3] == 'O')
	{
		return 2;
	}
	else if (grid[4] == 'X' && grid[5] == 'X' && grid[6] == 'X')
	{
		return 1;
	}
	else if (grid[4] == 'O' && grid[5] == 'O' && grid[6] == 'O')
	{
		return 2;
	}
	else if (grid[7] == 'X' && grid[8] == 'X' && grid[9] == 'X')
	{
		return 1;
	}
	else if (grid[7] == 'O' && grid[8] == 'O' && grid[9] == 'O')
	{
		return 2;
	}
	else if (grid[1] == 'X' && grid[4] == 'X' && grid[7] == 'X')
	{
		return 1;
	}
	else if (grid[1] == 'O' && grid[4] == 'O' && grid[7] == 'O')
	{
		return 2;
	}
	else if (grid[2] == 'X' && grid[5] == 'X' && grid[8] == 'X')
	{
		return 1;
	}
	else if (grid[2] == 'O' && grid[5] == 'O' && grid[8] == 'O')
	{
		return 2;
	}
	else if (grid[3] == 'X' && grid[6] == 'X' && grid[9] == 'X')
	{
		return 1;
	}
	else if (grid[3] == 'O' && grid[6] == 'O' && grid[9] == 'O')
	{
		return 2;
	}
	else if (grid[1] == 'X' && grid[5] == 'X' && grid[9] == 'X')
	{
		return 1;
	}
	else if (grid[1] == 'O' && grid[5] == 'O' && grid[9] == 'O')
	{
		return 2;
	}
	else if (grid[3] == 'X' && grid[5] == 'X' && grid[7] == 'X')
	{
		return 1;
	}
	else if (grid[3] == 'O' && grid[5] == 'O' && grid[7] == 'O')
	{
		return 2;
	}
	else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3'
	         && grid[4] != '4' && grid[5] != '5' && grid[6] != '6'
			 && grid[7] != '7' && grid[8] != '8' && grid[9] != '9') //this conditional checks for ties
	{
		return 3;
	}
	
	//From here on out I declare the extra win conditions added for 3D TicTacToe which is a LONG list
	//Win conditions for 3D straight lines for X
	
	else if (::Game1.grid[1] == 'X' && ::Game2.grid[1] == 'X' && ::Game3.grid[1] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[2] == 'X' && ::Game2.grid[2] == 'X' && ::Game3.grid[2] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[3] == 'X' && ::Game2.grid[3] == 'X' && ::Game3.grid[3] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[4] == 'X' && ::Game2.grid[4] == 'X' && ::Game3.grid[4] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[5] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[5] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[6] == 'X' && ::Game2.grid[6] == 'X' && ::Game3.grid[6] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[7] == 'X' && ::Game2.grid[7] == 'X' && ::Game3.grid[7] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[8] == 'X' && ::Game2.grid[8] == 'X' && ::Game3.grid[8] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[9] == 'X' && ::Game2.grid[9] == 'X' && ::Game3.grid[9] == 'X')
	{
		return 1;
	}
	
	//Win conditions for 3D straight lines for O
	
	else if (::Game1.grid[1] == 'O' && ::Game2.grid[1] == 'O' && ::Game3.grid[1] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[2] == 'O' && ::Game2.grid[2] == 'O' && ::Game3.grid[2] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[3] == 'O' && ::Game2.grid[3] == 'O' && ::Game3.grid[3] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[4] == 'O' && ::Game2.grid[4] == 'O' && ::Game3.grid[4] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[5] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[5] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[6] == 'O' && ::Game2.grid[6] == 'O' && ::Game3.grid[6] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[7] == 'O' && ::Game2.grid[7] == 'O' && ::Game3.grid[7] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[8] == 'O' && ::Game2.grid[8] == 'O' && ::Game3.grid[8] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[9] == 'O' && ::Game2.grid[9] == 'O' && ::Game3.grid[9] == 'O')
	{
		return 2;
	}
	
	// Win conditions for 3D diagonals for X
	
	else if (::Game1.grid[1] == 'X' && ::Game2.grid[2] == 'X' && ::Game3.grid[3] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[4] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[6] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[7] == 'X' && ::Game2.grid[8] == 'X' && ::Game3.grid[9] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[1] == 'X' && ::Game2.grid[4] == 'X' && ::Game3.grid[7] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[2] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[8] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[3] == 'X' && ::Game2.grid[6] == 'X' && ::Game3.grid[9] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[3] == 'X' && ::Game2.grid[2] == 'X' && ::Game3.grid[1] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[6] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[4] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[9] == 'X' && ::Game2.grid[8] == 'X' && ::Game3.grid[7] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[7] == 'X' && ::Game2.grid[4] == 'X' && ::Game3.grid[1] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[8] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[2] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[9] == 'X' && ::Game2.grid[6] == 'X' && ::Game3.grid[3] == 'X')
	{
		return 1;
	}
	
	// Win conditions for 3D diagonals for O
	
	else if (::Game1.grid[1] == 'O' && ::Game2.grid[2] == 'O' && ::Game3.grid[3] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[4] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[6] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[7] == 'O' && ::Game2.grid[8] == 'O' && ::Game3.grid[9] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[1] == 'O' && ::Game2.grid[4] == 'O' && ::Game3.grid[7] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[2] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[8] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[3] == 'O' && ::Game2.grid[6] == 'O' && ::Game3.grid[9] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[3] == 'O' && ::Game2.grid[2] == 'O' && ::Game3.grid[1] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[6] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[4] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[9] == 'O' && ::Game2.grid[8] == 'O' && ::Game3.grid[7] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[7] == 'O' && ::Game2.grid[4] == 'O' && ::Game3.grid[1] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[8] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[2] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[9] == 'O' && ::Game2.grid[6] == 'O' && ::Game3.grid[3] == 'O')
	{
		return 2;
	}
	
	// Win conditions for 3D corner diagonals for X
	
	else if (::Game1.grid[1] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[9] == 'X')
	{
		return 1;
	}
	else if (::Game1.grid[3] == 'X' && ::Game2.grid[5] == 'X' && ::Game3.grid[7] == 'X')
	{
		return 1;
	}

	// Win conditions for 3D corner diagonals for O
	
	else if (::Game1.grid[1] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[9] == 'O')
	{
		return 2;
	}
	else if (::Game1.grid[3] == 'O' && ::Game2.grid[5] == 'O' && ::Game3.grid[7] == 'O')
	{
		return 2;
	}
	
	else
	{
		return 0;
	}
}

void TicTacToe::changeTurn() //Change turn swaps whos turn it is by assigning fturn with the oposite 
{                            //of fturn's current boolean value 
	fturn = !(fturn);
}

//TicTacToe kinda mid, connect 4 better
