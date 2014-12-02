#include<iostream>
#include <time.h>
using namespace std;

void Grid(int grid[6][7])
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			grid[i][j] = 0;
		}
	}
}
void Display(int grid[6][7])
{
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<6; j++)
		{
			if (grid[i][j] == 0){ cout << " "; }
			else if (grid[i][j] == 1){ cout << "X"; }
			else if (grid[i][j] == 2){ cout << "O"; }
			if (j<6){ cout << " | "; }
		}
		cout << endl;
		if (i<6){ cout << "--+---+---+---+---+---+" << endl; }
	}
}
int playerMove(int grid[6][7]) {
	int x = 0;
	///do {
		cout << "Please choose number 1-6 " << endl;
		cin >> x;
		x = x - 1;
		cout << endl;
		if (x<6 && x>-1)
		{
			if (grid[6][x] == 0)
			{
				grid[6][x] = 1;
			}

			else if (grid[5][x] == 0)
			{
				grid[5][x] = 1;
			}
			else if (grid[4][x] == 0)
			{
				grid[4][x] = 1;
			}
			else if (grid[3][x] == 0)
			{
				grid[3][x] = 1;
			}
			else if (grid[2][x] == 0)
			{
				grid[2][x] = 1;
			}
			else if (grid[1][x] == 0)
			{
				grid[1][x] = 1;
			}
			else if (grid[0][x] == 0)
			{
				grid[0][x] = 1;
			}
			else
			{
				cout << "Pick an empty cell! - MISS A GO!";
			}
		}
		else
		{
			cout << "That's not in the grid - MISS A GO!";
		}
	//} while ((x >= 7 || x < 0));
		return x;

}
void AI_Move(int grid[6][7], int playermove)
{
	cout << "AI Move ";
	int x = 0, min = 0, max = 0, diff = 0;
	max = playermove + 1;
	min = playermove - 1;
	diff = max - min + 1;
	if (playermove == 0)
	{
		x = playermove ;
	}
	else if (playermove == 5)
	{
		x = playermove - 1;
	}
	else if (playermove != 0 && playermove != 5)
	{
		x = rand() % diff + min;
		srand(time(NULL));
	}
	else
	{
		x = rand() % 6;
		srand(time(NULL));
	}
	if (x<6 && x>-1)
	{
		if (grid[6][x] == 0)
		{
			grid[6][x] = 2;
		}

		else if (grid[5][x] == 0)
		{
			grid[5][x] = 2;
		}
		else if (grid[4][x] == 0)
		{
			grid[4][x] = 2;
		}
		else if (grid[3][x] == 0)
		{
			grid[3][x] = 2;
		}
		else if (grid[2][x] == 0)
		{
			grid[2][x] = 2;
		}
		else if (grid[1][x] == 0)
		{
			grid[1][x] = 2;
		}
		else if (grid[0][x] == 0)
		{
			grid[0][x] = 2;
		}
		else
		{
			AI_Move(grid, playermove);
		}
	}
	else
	{
		cout << "That's not in the grid - MISS A GO!";
	}
	cout << x << endl;

}
int winlose(int grid[6][7])
{
	for (int i = 0; i<6; i++)
		for (int j = 0; j<7; j++)
		{    //แนวนอน
			if (grid[i][j] == 1 && grid[i + 1][j] == 1 && grid[i + 2][j] == 1 && grid[i + 3][j] == 1)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 1;
			}
			if (grid[i][j] == 2 && grid[i + 1][j] == 2 && grid[i + 2][j] == 2 && grid[i + 3][j] == 2)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 2;
			}
			//แนวตั้ง
			if (grid[i][j] == 1 && grid[i][j + 1] == 1 && grid[i][j + 2] == 1 && grid[i][j + 3] == 1)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 1;
			}
			if (grid[i][j] == 2 && grid[i][j + 1] == 2 && grid[i][j + 2] == 2 && grid[i][j + 3] == 2)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 2;
			}
		}
	for (int i = 5; i >= 0; i--)
		for (int j = 0; j <= 5; j++)
		{
			//แนวทแยง
			if (grid[i][j] == 1 && grid[i - 1][j + 1] == 1 && grid[i - 2][j + 2] == 1 && grid[i - 3][j + 3] == 1)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 1;
			}
			if (grid[i][j] == 2 && grid[i - 1][j + 1] == 2 && grid[i - 2][j + 2] == 1 && grid[i - 3][j + 3] == 1)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 2;
			}

			if (grid[i][j] == 1 && grid[i - 1][j - 1] == 1 && grid[i - 2][j - 2] == 1 && grid[i - 3][j - 3] == 1)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 1;
			}
			if (grid[i][j] == 2 && grid[i - 1][j - 1] == 2 && grid[i - 2][j - 2] == 2 && grid[i - 3][j - 3] == 2)
			{
				//cout << "Player " << player << " WIN" << endl;
				return 2;
			}
		}

	//return 0;

}
bool who_win(int grid[6][7])
{
		if (winlose(grid) == 1){
			cout << "###### You WIN!!! ######" << endl;
			return true;
		}
		if (winlose(grid) == 2){
			cout << "###### You LOST 555 #####" << endl;
			return true;
		}
		else
		{
			return false;
		}
}
void main()
{
	int grid[6][7];
	int x = 0;
	Grid(grid);
	//int player = 1;
	for (int i = 0; i<100; i++)
	{
		Display(grid);
		x = playerMove(grid);
		if (who_win(grid) == true)
		{
			Display(grid);
			break;
		}
		//Display(grid);
		AI_Move(grid,x);
		if (who_win(grid) == true)
		{
			Display(grid);
			break;
		}
	}

}
