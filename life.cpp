// Charles Kraemer
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

#include "lifeboard.h"

int main(int argc, char *argv[])
{
	bool playGame= true;
	string choice;
	int x, y;
	string tempX, tempY;
	Lifeboard l;
	if(argc==1) {     // checks for file name at command line
		while(playGame) {
			l.display();  // display each iteration
			cout << "Choose an option:\nInput 'a' to add a new live cell\nInput 'r' to remove a cell\nInput 'n' to advance the simulation to the next iteration\nInput 'q' to quit the game\nInput 'p' for the game to play continuously\nEnter your choice: ";
		cin >> choice;
			if(choice=="a") {   // set of conditionals for different options
				cout << "Enter cell coordinates: ";
				cin >> x >> y;
				l.add(x,y);
			}
			else if(choice=="r") {
				cout << "Enter cell coordinates: ";
				cin >> x >> y;
				l.remove(x,y);
			}
			else if(choice=="n") {
				l.advance();
			}
			else if(choice=="q") {
				cout << "Thank you for using my program!" << endl;
				playGame= false;    // end while loop
			}
			else if (choice=="p") {
				bool play = true;
				while(play) {    // advance continuously
					l.display();
					l.advance();
					usleep(1000000);    // delays output
					system("clear");  // clears screen
				}
			}
			else {
				cout << "Error: invalid input" << endl;
			}
			system("clear");
		}
	}
	else if(argc==2) {   // check for argument at command line- corresponds to case in which a file name has been provided
		ifstream ifs;
		string fileName= argv[1];   // file name = string after executable name
		ifs.open(fileName);
		if(!ifs.is_open()) {
			cout << "Error: file " << fileName << " was not found." << endl;
		}
		while(choice!="p") {
			l.display();
			getline(ifs, choice, ' ');    // gets choices from input file, space between choice and coordinates for a case and r case
			if((choice=="a") || (choice=="r")) {
				getline(ifs, tempX, ' ');
				getline(ifs, tempY, '\n');
				x= stoi(tempX);
				y= stoi(tempY);
			}
			if(choice=="a") {
				l.add(x,y);
			}
			else if(choice=="r") {
				l.remove(x,y);
			}
			else if(choice=="n") {
				l.advance();
			}
			else if(choice=="p") {
				bool play=true;
				while(play) {
					l.display();
					l.advance();
					usleep(1000000);
					system("clear");
				}
			}
			else if(choice=="q") {
				choice= "p";
			}
			system("clear");
		}
	}
	else {
		cout << "Error: not sure if interactive or batch" << endl;  // error message if more than one argument is provided after the executable name
	}

	return 0;

}

				

		
	

	
