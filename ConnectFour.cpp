#include<iostream>

using namespace std;
char grid[6][7];
char player = 'O';


bool HOWTOWIN(int x, int y) //WIN CONDITION
{
	int horizontal = 1;
	int straight = 1;
	player = grid[x][y];
	int a;
	int b;
		   
	for (a = x + 1; grid[a][y] == player && a < 6; a++, straight++);
	for (a = x - 1; grid[a][y] == player && a >= 0; a--, straight++);
	if (straight >= 4) return 1;
	
	for (b = y - 1; grid[x][b] == player && b >= 0; b--, horizontal++);
	for (b = y + 1; grid[x][b] == player && b <= 6; b++, horizontal++);
	if (horizontal >= 4) return 1;
	
	
	return 0;
}


int gravity(int y, char player) //MAKES PIECES DROP TO THE BOTTOM
{
	if (y >= 0 && y <= 6)
	{
		if (grid[0][y] == ' ') 
		{
			int i;
			for (i = 0; grid[i][y] == ' '; i++)
			{
				if (i == 5)
				{
					grid[i][y] = player;
					return i;
				}
			}
			i--;
			grid[i][y] = player;
			return i;
		}
		else 
		{
			return -1;
		}
	}
	else 
	{
		return -1;
	}
}


void PRINTBOARD() //BOARD
{
	cout << " 1 2 3 4 5 6 7\n";
	for (int x = 0; x <= 5; x++)
	{
		for (int y = 0; y <= 6; y++)
		{
			cout << char(179) << grid[x][y];
		}
		cout << char(179);
		cout << '\n';


		for (int y = 0; y <= 6; y++)
		{
			cout << char(45) << char(45);
		}
		cout << '\n';
	}
}



int main()
{
	for (int x = 0; x <= 5; x++) //WHITESPACING MY BOARD
	{		
		for (int y = 0; y <= 6; y++)
		{
			grid[x][y] = ' ';
		}
	}
	cout << "Connect Four Game\n";

	PRINTBOARD(); //PRINT BOARD
	
	int check = 0;
	int row;
	char v;
	int charsPlaced = 0;
	bool winlose = false;
	
	while (!winlose) 
	{
		if (charsPlaced == 42)    cout << "Game tied!\n";
		
		if (check != 1) //SWITCHES PLAYERS
		{
			if (player == 'O')
			{
				cout << "Player X, enter a column: ";
				player = 'X';
			}
			else
			{
				cout << "Player O, enter a column: ";
				player = 'O';
			}
		}

		while (true)
		{
			cin >> row; //ENTER ROW
			row--;

			if (row <= 6 && row >= 0) 
			{
				break;
			}
			else cout << "\nplease enter a value between 1 and 7 :";


			if (cin.fail())	//CATCH A NON NUMBER
			{						
				cin.clear();		
				cin >> v;			
			}	
			
		} 


		if (charsPlaced == 42)
		{
			break;
		}

		check = gravity(row, player);//CALLS FUNCTION TO DROP TO THE BOTTOM OF THE ROW


		if (check == -1) 
		{
			cout << "\n";
			PRINTBOARD();
			cout <<"Column is full\nPlease enter another number between 1 and 7:\n";
		}
		else
		{
			winlose = HOWTOWIN(check, row);
			PRINTBOARD();
		}
	
		charsPlaced++;
	}

	
	if (player == 'O')        cout << "Player O connects four!\n";
	else                      cout << "Player X connects four!\n";

	return 0;
}                                                                                       