// Charles Kraemer
#include <iostream>
using namespace std;

#include "lifeboard.h"

Lifeboard::Lifeboard()    // default constructor
{
	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<SIZE; ++j) {
			board[i][j]= DEAD;
		}
	}
}

void Lifeboard::display()   // output board
{
	cout << "+";
	for(int i=0;i<SIZE;++i) cout << "-";
	cout << "+" << endl;

	for(int i=0;i<SIZE;++i) {
		cout << "|";
		for(int j=0; j<SIZE; j++) cout << board[i][j];
		cout << "|" << endl;
	}

	cout << "+";
	for(int i=0;i<SIZE;++i) cout << "-";
	cout << "+" << endl;
}


void Lifeboard::add(int x, int y)  // add live cell
{
	if((x<=SIZE)&&(y<=SIZE)) {
		board[x][y]= ALIVE;
	}
	else {
		cout << "Error: invalid coordinates" << endl;
	}
}

void Lifeboard::remove(int x, int y) // remove live cell
{
	if((x<=SIZE)&&(y<=SIZE)) {
		board[x][y]= DEAD;
	}
	else {
		cout << "Error: invalid coordinates" << endl;
	}
}

void Lifeboard::advance()  // apply rules and create new iteration
{
	char tempBoard[SIZE][SIZE];
	int count =0;
	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<SIZE; ++j) {
			tempBoard[i][j]= DEAD;
		}
	}
	int neighborCount= 0;
	for(int i=0; i<SIZE; ++i) {   // increment through each point on the board and count neighbors
		for(int j=0; j<SIZE; ++j) {
			if((i==0)&&(j==0)) {   // upper left corner
				if(board[i+1][j+1]==ALIVE) { 
					neighborCount=neighborCount+1;
				}
				if(board[i][j+1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i+1][j]==ALIVE) {
					neighborCount=neighborCount+1;
				}
			}
			else if((i==0)&&(j!=0)&&(j!=SIZE-1)) {  // upper row
				if(board[i+1][j+1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i][j+1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i][j-1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i+1][j]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i+1][j-1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
			}
			else if((i==0)&&(j==SIZE-1)) {   // upper right corner
				if(board[i][j-1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i+1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			else if((i!=0)&&(i<SIZE-1)&&(j==0)) {  // left most column
				if(board[i-1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			else if((i!=0)&&(i!=SIZE-1)&&(j!=0)&&(j!=SIZE-1)) {   // middle points of board
				if(board[i-1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j+1]==ALIVE) {
					neighborCount=neighborCount+1;
				}
				if(board[i][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			else if((i!=0)&&(i!=SIZE-1)&&(j==SIZE-1)) {  // right most column
				if(board[i-1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i+1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			else if((i==SIZE-1)&&(j==0)) {   // bottom left corner
				if(board[i-1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			else if((i==SIZE-1)&&(j!=0)&&(j!=SIZE-1)) {  // bottom row
				if(board[i][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i][j+1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			else if((i==SIZE-1)&&(j==SIZE-1)) {  // lower right corner
				if(board[i][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j-1]==ALIVE) {
					neighborCount= neighborCount+1;
				}
				if(board[i-1][j]==ALIVE) {
					neighborCount= neighborCount+1;
				}
			}
			if(board[i][j]==ALIVE) {  // uses neighbor count to determine life value
				if((neighborCount==2) || (neighborCount==3)) {
					tempBoard[i][j]=ALIVE;
				}
				else {
					tempBoard[i][j]=DEAD;
				}
			}
			else if(board[i][j]==DEAD) {
				if(neighborCount==3) {
					tempBoard[i][j]=ALIVE;
				}
			}

			neighborCount=0; // resets neighbor count
		}
	}
	for(int i=0; i<SIZE; ++i) {
		for(int j=0; j<SIZE; ++j) {
			board[i][j]= tempBoard[i][j];
		}
	}
}


				




	


				
