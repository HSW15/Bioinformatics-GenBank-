#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

class Cell
{
private:
	char ident;  //Registers the character and stores the state of the cell in vec
	unsigned int x; //registers the row
	unsigned int y; //registers the column

public:
	Cell(); //constructor
	Cell(unsigned int x_in, unsigned int y_in);
	~Cell(); //destructor
	
	void update(unsigned int x_in, unsigned int y_in); //updates the size of the board
	virtual void death_birth(vector< vector<Cell> >&copy, char identity); //Has the birth, death and stasis condition
	Cell(char ident) { this->ident = ident; }; //reassigning the character of ident
	char getIdent() { return this->ident; }; //Returns the character stored whenever the vector of 'cell' is called

};
Cell::Cell() //constructor
{
	unsigned int x = 0; 
	unsigned int y = 0;
}

Cell::~Cell() {}; //destructor

void Cell::death_birth(vector< vector<Cell> >&copy, char identity) //This void function contains the birth death and stasis condition. "copy" is vector<vector<Cell>vec
{	
	vector< vector<char> >vec2; //this vector was created as a template for the next state of the board. It is then assigned to the main vector after going through all the conditions
	for (unsigned int a = 0; a < x; a++) //this double for loop initialises a board based on the size set by x and y. Which in our case is [20][75]
	{
		vector<char> grid; 
		for (unsigned int b = 0; b < y; b++)
		{
			grid.push_back(' '); //Initialises and sets to blank space
		}
		vec2.push_back(grid); 
	}
	
	
	int count = 0; // THIS COUNT IS VERY IMPORTANT AS IT IS SET TO 0 AFTER EVERY SET OF CONDITIONS APPLIED TO SPECIFIC PARTS OF THE VECTOR
	for(int i = 0; i<2; i++) //FOR TOP LEFT CORNER
	{
		for(int j = 0; j<2; j++)
		{
			if(copy[i][j].getIdent() == identity) //identity stores the char 'O' & 'X'
				count++;	//records the number of like characters 
		}
	}
	if(copy[0][0].getIdent() == identity) //This if statement is quite important as it test whether the element in the vector of concern is the same as its neighbours
		count--; //And if it is, it would have got looped in the last 'for' loop so we need to -1 to get the number of 'like' neighbours.
	if(count == 3) //BIRTH SITUATION
		vec2[0][0] = identity; //THE TEMPLATE VECTOR IS UPDATED AT A PARTICULAR ELEMENT
	if(count == 2) //STASIS SITUATION
		vec2[0][0] = copy[0][0].getIdent(); //Maps the existing character(whatever it is) and put in on our template
	if(count <= 1 || count >= 4) //DEATH Situation
		vec2[0][0] = ' '; //Put deadcell in our template
	
	count = 0; //AS MENTIONED THIS IS RESET TO 0 AFTER THE SET OF CONDITIONS ARE APPLIED TO DIFFERENT LOCATIONS ON THE BOARD.
	//----------------------------------------------------------------------
	for(int i = 0; i<2; i++) //FOR TOP RIGHT CORNER (0 to 1)
	{
		for(int j = y - 2; j < y ; j++) //y =73 to 74
		{
			if(copy[i][j].getIdent() == identity)
				count++;
		}
	}
	if(copy[0][y-1].getIdent() == 'O')
		count--;
	if(count == 3)
		vec2[0][y-1] = identity;
	if(count == 2)
		vec2[0][y-1] = copy[0][y-1].getIdent();
	if(count <= 1 || count >= 4)
		vec2[0][y-1] = ' ';
	count = 0;
	
	//------------------------------------------------------------------------------------------------------------------------
	for(int i = x-2; i < x ; i++) //FOR bottom LEFT (18 to 19)
	{
		for(int j = 0; j< 2 ; j++) //(0 to 2)
		{
			if(copy[i][j].getIdent() == identity)
				count++;
		}
	}
	if(copy[x-1][0].getIdent() == identity)
		count--;
	if(count == 3)
		vec2[x-1][0] = identity;
	if(count == 2)
		vec2[x-1][0] = copy[x-1][0].getIdent();
	if(count <= 1 || count >= 4)
		vec2[x-1][0] = ' ';
	count = 0;
	//----------------------------------------------------------------------------------------------------------------
	for(int i = x-2; i<x; i++) //BOTTOM RIGHT (18 to 19)
	{
		for(int j = y-2; j< y ; j++) //73 to 74
		{
			if(copy[i][j].getIdent() == identity)
			count++;
		}
	}
	if(copy[x-1][y-1].getIdent() == identity)
		count--;
	if (count == 3)
		vec2[x-1][y-1] = identity;
	if (count == 2)
		vec2[x-1][y-1] = copy[x-1][y-1].getIdent();
	if(count <= 1 || count >= 4)
		vec2[x-1][y-1] = ' ';
	count = 0;
	//------------------------------------------------------------------------------------------

	for (unsigned int a = 1; a < y-1; a++) //TOP ROW. Starts at 1 until 73
	{
		for(unsigned int i = 0; i < 2; i++)  //loop first and 2nd row
		{
			for(unsigned int j = a-1; j < a+2 ; j++)  //loop 1 place before and 1 after //loops 3 places
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[0][a].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[0][a] = identity;
		if(count == 2)
			vec2[0][a] = copy[0][a].getIdent();
		if(count <= 1 || count >= 4)
			vec2[0][a] = ' ';
		count = 0;
	}
	//-----------------------------------------------------------------------------------------------
	for (unsigned int a = 1; a < y-1; a++) //BOTTOM ROW. Starts at column 1. size-1 returns 74 
	{
		for(unsigned int i = x-2; i < x; i++)  //loop first and 2nd row
		{
			for(unsigned int j = a-1; j < a+2 ; j++)  //loop 1 place before and 1 after
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[x-1][a].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[x-1][a] = identity;
		if(count == 2)
			vec2[x-1][a] = copy[x-1][a].getIdent();
		if(count <= 1 || count >= 4)
			vec2[x-1][a] = ' ';
		count = 0;
	}
	//-------------------------------------------------------------------------------------------
	for (unsigned int a = 1; a < x-1; a++) //LEFT ROW. Starts at column 1. size-1 returns 74 
	{
		for(unsigned int i = a-1; i < a+2; i++)  //loop first and 2nd row
		{
			for(unsigned int j = 0; j < 2 ; j++)  //loop 1 place before and 1 after
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[a][0].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[a][0] = identity;
		if(count == 2)
			vec2[a][0] = copy[a][0].getIdent();
		if(count <= 1 || count >= 4)
			vec2[a][0] = ' ';
		count = 0;
	}
	//-------------------------------------------------------------------------------
	for (unsigned int a = 1; a < x-1; a++) //RIGHT ROW
	{
		for(unsigned int i = a-1; i < a+2; i++) // 0 to 19
		{
			for(unsigned int j = y-2; j < y ; j++)  //73 to 74
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[a][y-1].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[a][y-1] = identity;
		if(count == 2)
			vec2[a][y-1] = copy[a][x-1].getIdent();
		if(count <= 1 || count >= 4)
			vec2[a][y-1] = ' ';
		count = 0;
	}
	//--------------------------------------------------------------------------------------------------------
	for (unsigned int a = 1; a < x-1; a++) //MAIN SECTION OF BOARD (1 to 18)
	{
		for (unsigned int b = 1; b < y-1; b++) //correct 1-73
		{
			for(unsigned int i = a-1; i < a+2; i++) // 0 to 2
			{
				for(unsigned int j = b-1; j < b+2 ; j++)  //0 to 2
				{
					if(copy[i][j].getIdent() == identity) 
						count++;
				}
			}
			if(copy[a][b].getIdent() == identity)
				count--;
			if(count == 3)
				vec2[a][b] = identity;
			if(count == 2)
				vec2[a][b] = copy[a][b].getIdent();
			if(count <= 1 || count >= 4)
				vec2[a][b] = ' ';
			count = 0;
		}
	}
	
	for (unsigned int a = 0; a < copy.size(); a++) //correct 1-18
	{
		for (unsigned int b = 0; b < copy[a].size(); b++) //correct 1-73
		{
				copy[a][b] = vec2[a][b]; //PUTS THE TEMPLATE VECTOR(WHICH IS THE NEXT UPDATE OF THE BOARD AND ASSIGN TO COPY)
		}
	}
}

void Cell::update(unsigned int x_in,unsigned int y_in) //This stores the size of the board in class Cell
{
	x = x_in;
	y = y_in;
}

class Board
{
private:
	unsigned int x; //stores row
	unsigned int y; //stores column
	vector< vector<Cell> >vec; //vector of cell
	int t; //counts the time
	double NoOfCells; //counts the number of cells
	char identity; //stores whether 'X', 'O' was selected

public:
	Board();
	~Board();
	Board(unsigned int x_in, unsigned int y_in);
	void seed_cells(int selection, int confluence); //Randomises the board initially
	void display(); //display the board constantly
	void next_state(); //display the next state
	
	int get_time() { return t; }; 
	void set_time(int t_in) { t = t_in; };

	double get_num_cells() { return NoOfCells; };
	void set_num_cells(double places) { NoOfCells = places; };
};

Board::Board()
{
	x = 0;
	y = 0;
	t = 0;
	NoOfCells = 0;
}

Board::Board(unsigned int x_in, unsigned int y_in)
{
	x = x_in; //20
	y = y_in; //75

	for (unsigned int a = 0; a < x_in; a++)
	{
		vector<Cell> grid; //this vector represent rows
		for (unsigned int b = 0; b < y_in; b++)
		{
			Cell deadCell(' ');   //stores whitespace in Ident
			grid.push_back(deadCell); //stores that whitespace into grid
		}
		vec.push_back(grid);
	}
}

Board::~Board() {}; //destructor for board

void Board::display() //General display for board whenever is needed
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		for (unsigned int j = 0; j < vec[i].size(); j++)
			cout << vec[i][j].getIdent();
		cout << endl;
	}
}

void Board::seed_cells(int selection, int confluence)
{
	srand(1); 
	int elementTotal = 1500; //Total number of elements is 1500 (20x75)
	int places = 0; //stores number of 'O' or 'X' initialised into board
	t = 0; //time initially at 0
	double confluency = (static_cast<double>(confluence) / 100); //so the value of confluence entered Ex. 15 is converted to a double to prevent truncation and then assigned to confluency

	for (unsigned int i = 0; i < vec.size(); i++) //loops the vector of rows
	{
		for (unsigned int j = 0; j < vec[i].size(); j++) //loops the vector of columns in each row
		{
			if (selection == 1) //if 'O'
			{
				if (confluency > rand() / double(RAND_MAX))
				{
					identity = 'O'; //Stores the choice of cell you are using and is used in the cell situation later
					vec[i][j] = 'O'; //when the confluency decimal is compared to the random number generated. A larger confluency would mean a 'O' or 'X' thats not whitespace is assigned at that position
					places++; //counting the number of cells not ' '
					NoOfCells = places;
				}
			}
			if (selection == 2)
			{
				if (confluency > rand() / double(RAND_MAX))
				{
					identity = 'X';
					vec[i][j] = 'X';
					places++;
					NoOfCells = places;
				}
			}
		}
		cout << endl;
	}
}

class Cancer : public Cell
{
	private:
	
	public:
	Cancer();
	~Cancer();
	void death_birth(vector< vector<Cell> >&vec3, char identity, unsigned int x, unsigned int y);
};

void Board::next_state()
{
	Cell cell; //create a cell of Cell class type
	Cancer cancer; //create a cancer of Cancer cell type
	cell.update(x, y); //updates the size of board into class cell
	if(identity == 'O') //if 'O' then it executes the cell conditions in class cell
		cell.death_birth(vec, identity); //pass by reference vec to it
	if(identity == 'X') //if 'X' then executes the code in derived class Cancer
		cancer.death_birth(vec, identity,x,y);
	t = t+1; //everytime this function is called, t+1 to an existing t stored in private
	NoOfCells = 0; //reset the no of cells

	for(unsigned int i = 0; i< vec.size(); i++) //Cell 'O' or 'X' counter
	{
		for (unsigned int j = 0; j< vec[i].size(); j++)
		{
			if (vec[i][j].getIdent()!= ' ')
				NoOfCells = NoOfCells + 1;
		}
	}
}

Cancer::Cancer():Cell(){}; //constructor for cancer
Cancer::~Cancer(){}; //destructor for cancer

void Cancer::death_birth(vector< vector<Cell> >&copy, char identity, unsigned int x, unsigned int y) //WARNING: THIS SECTION OF CODE IS SIMILAR TO THE ONE BEFORE EXCEPT FOR THE OVERPOPULATION CONDITION WITH THE ARROWS
{
	vector< vector<char> >vec2; //creates the template vec like in death
	for (unsigned int a = 0; a < x; a++)
	{
		vector<char> grid; 
		for (unsigned int b = 0; b < y; b++)
		{
			grid.push_back(' ');
		}
		vec2.push_back(grid);
	}
	
	int count = 0;
	for(int i = 0; i<2; i++) //FOR TOP LEFT CORNER
	{
		for(int j = 0; j<2; j++)
		{
			if(copy[i][j].getIdent() == identity)
				count++;	
		}
	}
	if(copy[0][0].getIdent() == identity)
		count--;
	if(count == 3)
		vec2[0][0] = identity;
	if(count == 2 || count == 4) //<----------2 and 4 neighbours => stasis
		vec2[0][0] = copy[0][0].getIdent();
	if(count <= 1 || count >= 5) //1 or 5 neighbours means death
		vec2[0][0] = ' ';
	
	count = 0;
	//----------------------------------------------------------------------
	for(int i = 0; i<2; i++) //FOR TOP RIGHT CORNER
	{
		for(int j = y - 2; j < y ; j++)
		{
			if(copy[i][j].getIdent() == identity)
				count++;
		}
	}
	if(copy[0][y-1].getIdent() == 'O')
		count--;
	if(count == 3)
		vec2[0][y-1] = identity;
	if(count == 2 || count == 4)//<------------------------------------
		vec2[0][y-1] = copy[0][y-1].getIdent();
	if(count <= 1 || count >= 5)//<------------------------------------
		vec2[0][y-1] = ' ';
	count = 0;
	
	//------------------------------------------------------------------------------------------------------------------------
	for(int i = x-2; i < x ; i++) //FOR bottom LEFT
	{
		for(int j = 0; j< 2 ; j++)
		{
			if(copy[i][j].getIdent() == identity)
				count++;
		}
	}
	if(copy[x-1][0].getIdent() == identity)
		count--;
	if(count == 3)
		vec2[x-1][0] = identity;
	if(count == 2 || count == 4)//<------------------------------------
		vec2[x-1][0] = copy[x-1][0].getIdent();
	if(count <= 1 || count >= 5)//<------------------------------------
		vec2[x-1][0] = ' ';
	count = 0;
	//----------------------------------------------------------------------------------------------------------------
	for(int i = x-2; i<x; i++) //BOTTOM RIGHT
	{
		for(int j = y-2; j< y ; j++)
		{
			if(copy[i][j].getIdent() == identity)
			count++;
		}
	}
	if(copy[x-1][y-1].getIdent() == identity)
		count--;
	if (count == 3)
		vec2[x-1][y-1] = identity;
	if (count == 2|| count == 4)//<------------------------------------
		vec2[x-1][y-1] = copy[x-1][y-1].getIdent();
	if(count <= 1 || count >= 5)//<------------------------------------
		vec2[x-1][y-1] = ' ';
	count = 0;
	//------------------------------------------------------------------------------------------

	for (unsigned int a = 1; a < y-1; a++) //TOP EDGE. Starts at 1 until 73
	{
		for(unsigned int i = 0; i < 2; i++)  //looop first and 2nd row
		{
			for(unsigned int j = a-1; j < a+2 ; j++)  //loop 1 place before and 1 after //loops 3 places
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[0][a].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[0][a] = identity;
		if(count == 2 || count == 4)//<------------------------------------
			vec2[0][a] = copy[0][a].getIdent();
		if(count <= 1 || count >= 5)//<------------------------------------
			vec2[0][a] = ' ';
		count = 0;
	}
	//-----------------------------------------------------------------------------------------------
	for (unsigned int a = 1; a < y-1; a++) //BOTTOM EDGE. Starts at column 1. size-1 returns 74 
	{
		for(unsigned int i = x-2; i < x; i++)  //looop first and 2nd row
		{
			for(unsigned int j = a-1; j < a+2 ; j++)  //loop 1 place before and 1 after
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[x-1][a].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[x-1][a] = identity;
		if(count == 2 || count == 4)//<------------------------------------
			vec2[x-1][a] = copy[x-1][a].getIdent();
		if(count <= 1 || count >= 5)//<------------------------------------
			vec2[x-1][a] = ' ';
		count = 0;
	}
	//-------------------------------------------------------------------------------------------
	for (unsigned int a = 1; a < x-1; a++) //LEFT EDGE. Starts at column 1. size-1 returns 74 
	{
		for(unsigned int i = a-1; i < a+2; i++)  //looop first and 2nd row
		{
			for(unsigned int j = 0; j < 2 ; j++)  //loop 1 place before and 1 after
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[a][0].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[a][0] = identity;
		if(count == 2 || count == 4)//<------------------------------------
			vec2[a][0] = copy[a][0].getIdent();
		if(count <= 1 || count >= 5)//<------------------------------------
			vec2[a][0] = ' ';
		count = 0;
	}
	//-------------------------------------------------------------------------------
	for (unsigned int a = 1; a < x-1; a++) //1 to 18
	{
		for(unsigned int i = a-1; i < a+2; i++) // 0 to 19
		{
			for(unsigned int j = y-2; j < y ; j++)  //73 to 74
			{
				if(copy[i][j].getIdent() == identity) 
					count++;
			}
		}
		if(copy[a][y-1].getIdent() == identity)
			count--;
		if(count == 3)
			vec2[a][y-1] = identity;
		if(count == 2 || count == 4) //<-------------------------------------
			vec2[a][y-1] = copy[a][x-1].getIdent();
		if(count <= 1 || count >= 5) //<------------------------------------
			vec2[a][y-1] = ' ';
		count = 0;
	}
	//--------------------------------------------------------------------------------------------------------
	for (unsigned int a = 1; a < x-1; a++) //1 to 18
	{
		for (unsigned int b = 1; b < y-1; b++) //correct 1-73
		{
			for(unsigned int i = a-1; i < a+2; i++) // 0 to 2
			{
				for(unsigned int j = b-1; j < b+2 ; j++)  //0 to 2
				{
					if(copy[i][j].getIdent() == identity) 
						count++;
				}
			}
			if(copy[a][b].getIdent() == identity)
				count--;
			if(count == 3)
				vec2[a][b] = identity;
			if(count == 2 || count == 4)//<------------------------------------
				vec2[a][b] = copy[a][b].getIdent();
			if(count <= 1 || count >= 5)//<------------------------------------
				vec2[a][b] = ' ';
			count = 0;
		}
	}
	
	for (unsigned int a = 0; a < copy.size(); a++) //correct 1-18
	{
		for (unsigned int b = 0; b < copy[a].size(); b++) //correct 1-73
		{
				copy[a][b] = vec2[a][b];
		}
	}
}


int main()
{
	int selection = 0;
	int confluence = 0;
	char c = ' ';
	int t = 0;
	Board board(20, 75);

	string trash;
	cout << "Welcome to the cell simulator" << endl;
	cout << endl;
	cout << "Select your cell type: (1) normal cells or (2) cancer cells" << endl;
	while ((selection < 1) || (selection > 2))
	{
		cout << ">";
		cin >> selection;
	}
	getline(cin, trash);

	cout << "Select the confluence percentage (%)" << endl;
	while ((confluence <= 0) || (confluence > 100))
	{
		cout << ">";
		cin >> confluence;
	}
	getline(cin, trash);
	board.seed_cells(selection, confluence);
	system("cls");
	cout << "time:             " << board.get_time() << endl;
	cout << "number of cells: " << board.get_num_cells() << endl;
	board.display(); //displayes initial state of board
	c = cin.get();
	board.next_state(); // displays next state while updating the board without printing in first so that the time and number of cells come out before it
	while (c != 'q')
	{
		system("cls");
		cout << "time:             " << board.get_time() << endl;
		cout << "number of cells: " << board.get_num_cells() << endl;
		board.display();
		c = cin.get();
		board.next_state();
	}
	return 0;
}