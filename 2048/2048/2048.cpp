#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

int row, column;

struct player {
	string playerName;
	int score = 0;
};
player arr[5];

struct game {
	int board[4][4];
};
game grid;

struct score {
	int currentScore = 0;
	int highScore = 0;
};
score playerScore;

void mergeNum(int nextRow, int nextColumn, int row, int column) {
	grid.board[nextRow][nextColumn] = 2 * grid.board[row][column];
	playerScore.currentScore += 2 * grid.board[row][column];
	grid.board[row][column] = 0;
}

bool anypossiblemove(int currentRow, int currentColumn)
{
	if ((currentRow - 1) >= 0 && grid.board[currentRow - 1][currentColumn] == grid.board[currentRow][currentColumn])
	{
		return true;
	}
	else if ((currentRow + 1) <= 3 && grid.board[currentRow + 1][currentColumn] == grid.board[currentRow][currentColumn])
	{
		return true;
	}
	else if ((currentColumn + 1) <= 3 && grid.board[currentRow][currentColumn + 1] == grid.board[currentRow][currentColumn])
	{
		return true;
	}
	else if ((currentColumn - 1) >= 0 && grid.board[currentRow][currentColumn - 1] == grid.board[currentRow][currentColumn])
	{
		return true;
	}
	else if (grid.board[currentRow][currentColumn] == 0)
	{
		return true;
	}
	return false;
}

bool checkGameLose() {

	for (int row = 0; row <= 3; row++)
	{
		for (int column = 0; column <= 3; column++)
		{
			if (anypossiblemove(row, column))
			{
				return true;
			}
		}
	}
	return false;
}

void generateStartTiles2() {
	srand(time(0));
	int isOccupied = 1, rowTemp, columnTemp;
	while (isOccupied) {
		rowTemp = rand() % 4;
		columnTemp = rand() % 4;
		if (grid.board[rowTemp][columnTemp] == 0) {
			isOccupied = 0;
		}
	}
	column = columnTemp;
	row = rowTemp;
	int randTemp;
	grid.board[row][column] = 2;
}

void generateStartTiles4() {
	srand(time(0));
	int isOccupied = 1, rowTemp, columnTemp;
	while (isOccupied) {
		rowTemp = rand() % 4;
		columnTemp = rand() % 4;
		if (grid.board[rowTemp][columnTemp] == 0) {
			isOccupied = 0;
		}
	}
	column = columnTemp;
	row = rowTemp;
	int randTemp;
	grid.board[row][column] = 4;
}

void generateTiles() {
	srand(time(0));
	int isOccupied = 1, rowTemp, columnTemp;
	while (isOccupied) {
		rowTemp = rand() % 4;
		columnTemp = rand() % 4;
		if (grid.board[rowTemp][columnTemp] == 0) {
			isOccupied = 0;
		}
	}
	column = columnTemp;
	row = rowTemp;
	int randTemp;
	randTemp = rand() % 2;
	if (randTemp == 0) {
		grid.board[row][column] = 2;
	}
	else {
		grid.board[row][column] = 4;
	}
}

void startGame()
{
	playerScore.currentScore = 0;
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			grid.board[row][column] = 0;
		}
	}
	generateStartTiles2();
	generateStartTiles4();
}

bool canMove(int nextRow, int nextColumn, int currentRow, int currentColumn) {
	if (grid.board[currentRow][currentColumn] == 0) {
		return false;
	}
	else if (grid.board[nextRow][nextColumn] == 0) {
		return true;
	}
	else if (grid.board[nextRow][nextColumn] != 0) {
		return false;
	}
	else
		return false;
}
void moveUp() {
	int nextRow, nextColumn, movePossible, addTile = 0;
	do {
		movePossible = 0;
		for (int row = 1; row <= 3; row++)
		{
			nextRow = row - 1;
			for (int column = 0; column <= 3; column++)
			{
				nextColumn = column;
				if (canMove(nextRow, nextColumn, row, column)) {
					grid.board[nextRow][nextColumn] = grid.board[row][column];
					grid.board[row][column] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	for (int row = 1; row <= 3; row++)
	{
		nextRow = row - 1;
		for (int column = 0; column <= 3; column++)
		{
			nextColumn = column;
			if (grid.board[nextRow][nextColumn] == grid.board[row][column])
			{
				mergeNum(nextRow, nextColumn, row, column);
				addTile = 1;
			}
		}
	}
	do {
		movePossible = 0;
		for (int row = 1; row <= 3; row++)
		{
			nextRow = row - 1;
			for (int column = 0; column <= 3; column++)
			{
				nextColumn = column;
				if (canMove(nextRow, nextColumn, row, column)) {
					grid.board[nextRow][nextColumn] = grid.board[row][column];
					grid.board[row][column] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	if (addTile) {
		generateTiles();
	}
}

void moveDown() {
	int nextRow, nextColumn, movePossible, addTile = 0;
	do {
		movePossible = 0;
		for (int row = 2; row >= 0; row--)
		{
			nextRow = row + 1;
			for (int column = 0; column <= 3; column++)
			{
				nextColumn = column;
				if (canMove(nextRow, nextColumn, row, column)) {
					grid.board[nextRow][nextColumn] = grid.board[row][column];
					grid.board[row][column] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	for (int row = 2; row >= 0; row--)
	{
		nextRow = row + 1;
		for (int column = 0; column <= 3; column++)
		{
			nextColumn = column;
			if (grid.board[nextRow][nextColumn] == grid.board[row][column])
			{
				mergeNum(nextRow, nextColumn, row, column);
				addTile = 1;
			}
		}
	}
	do {
		movePossible = 0;
		for (int row = 2; row >= 0; row--)
		{
			nextRow = row + 1;
			for (int column = 0; column <= 3; column++)
			{
				nextColumn = column;
				if (canMove(nextRow, nextColumn, row, column)) {
					grid.board[nextRow][nextColumn] = grid.board[row][column];
					grid.board[row][column] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	if (addTile) {
		generateTiles();
	}
}

void moveRight() {
	int nextRow, nextColumn, movePossible, addTile = 0;
	do {
		movePossible = 0;
		for (int row = 0; row <= 3; row++)
		{
			nextRow = row;
			for (int column = 2; column >= 0; column--)
			{
				nextColumn = column + 1;
				if (canMove(nextRow, nextColumn, row, column)) {
					grid.board[nextRow][nextColumn] = grid.board[row][column];
					grid.board[row][column] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	for (int row = 0; row <= 3; row++)
	{
		nextRow = row;
		for (int column = 2; column >= 0; column--)
		{
			nextColumn = column + 1;
			if (grid.board[nextRow][nextColumn] == grid.board[row][column])
			{
				mergeNum(nextRow, nextColumn, row, column);
				addTile = 1;
			}
		}
	}
	do {
		movePossible = 0;
		for (int i = 0; i <= 3; i++)
		{
			nextRow = i;
			for (int j = 2; j >= 0; j--)
			{
				nextColumn = j + 1;
				if (canMove(nextRow, nextColumn, i, j)) {
					grid.board[nextRow][nextColumn] = grid.board[i][j];
					grid.board[i][j] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	if (addTile) {
		generateTiles();
	}
}

void moveLeft() {
	int nextRow, nextColumn, movePossible, addTile = 0;
	do {
		movePossible = 0;
		for (int i = 0; i <= 3; i++)
		{
			nextRow = i;
			for (int j = 1; j <= 3; j++)
			{
				nextColumn = j - 1;
				if (canMove(nextRow, nextColumn, i, j)) {
					grid.board[nextRow][nextColumn] = grid.board[i][j];
					grid.board[i][j] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	for (int i = 0; i <= 3; i++)
	{
		nextRow = i;
		for (int j = 1; j <= 3; j++)
		{
			nextColumn = j - 1;
			if (grid.board[nextRow][nextColumn] == grid.board[i][j])
			{
				mergeNum(nextRow, nextColumn, i, j);
				addTile = 1;
			}
		}
	}
	do {
		movePossible = 0;
		for (int i = 0; i <= 3; i++)
		{
			nextRow = i;
			for (int j = 1; j <= 3; j++)
			{
				nextColumn = j - 1;
				if (canMove(nextRow, nextColumn, i, j)) {
					grid.board[nextRow][nextColumn] = grid.board[i][j];
					grid.board[i][j] = 0;
					movePossible = 1;
					addTile = 1;
				}
			}
		}
	} while (movePossible);
	if (addTile) {
		generateTiles();
	}
}

void printMenu() {
	system("cls");
	cout << "\n\n\n\t\t\t\t\t\t       2048\n\t\t\t\t\t\tMade by Team 12 ;)\n\n\n\n\n";
	cout << "\t\t\t\t   N:New Game         ESC:Exit        R:Rank List\n";
}

void printBoard()
{
	system("cls");
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Score     : " << playerScore.currentScore << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t   Highscore : " << playerScore.highScore << endl;
	for (int i = 0; i < 4; i++) {
		cout << "\t\t\t\t\t\t";
		for (int j = 0; j < 4; j++) {
			if (grid.board[i][j] == 0)
				cout << ".\t";
			else
				cout << grid.board[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void showRank()
{
	system("cls");
	int arrTemp[5] = { 5, 4, 3, 2, 1 };
	for (int i = 4; i >= 0; i--)
	{
		cout << arrTemp[i] << " - " << arr[i].playerName << "\t\t" << arr[i].score << endl;
	}

}

void scoreSort(int temp) {
	arr[temp].score = playerScore.currentScore;
	temp++;
	int sortTemp;
	string stringTemp;
	for (int i = 0; i < 4; i++) {
		if (arr[i + 1].score < arr[i].score) {
			sortTemp = arr[i].score;
			arr[i].score = arr[i + 1].score;
			arr[i + 1].score = sortTemp;
			stringTemp = arr[i].playerName;
			arr[i].playerName = arr[i + 1].playerName;
			arr[i + 1].playerName = stringTemp;
		}
	}
	playerScore.currentScore = 0;
	playerScore.highScore = arr[4].score;
}

void exit()
{

}

int main()
{
	int temp = 0;
	arr[0].playerName = "Player 1";
	arr[1].playerName = "Player 2";
	arr[2].playerName = "Player 3";
	arr[3].playerName = "Player 4";
	arr[4].playerName = "Player 5";
	printMenu();

	while (true) {
		char command;
		command = _getch();


		if (command == 'n') {
			scoreSort(temp);
			startGame();
			printBoard();
		}
		else if (command == 27) {
			break;
		}
		else if (command == 'm') {
			printMenu();
			scoreSort(temp);
		}
		else if (command == 'r') {
			showRank();
		}
		else if (command == 72) {
			moveUp();
			printBoard();
			if (checkGameLose() == false)
			{
				cout << "\t\t\t\t\t\t\t\t\t" << "Game Over";
			}
		}
		else if (command == 80) {
			moveDown();
			printBoard();
			if (checkGameLose() == false)
			{
				cout << "\t\t\t\t\t\t\t\t\t" << "Game Over";
			}
		}
		else if (command == 77) {
			moveRight();
			printBoard();
			if (checkGameLose() == false)
			{
				cout << "\t\t\t\t\t\t\t\t\t" << "Game Over";
			}
		}
		else if (command == 75) {
			moveLeft();
			printBoard();
			if (checkGameLose() == false)
			{
				cout << "\t\t\t\t\t\t\t\t\t" << "Game Over";
			}
		}
	}
	return 0;
}