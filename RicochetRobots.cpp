/* ------------------------------------------------
   msales3Prog5.cpp
 
   Program #5: Ricochet Robots: Allow solving the sliding robots puzzle
   Class: CS 141
   Author: Maria Alexis Sales
   Lab: Tues 5am
   System:  C++ Mac Xcode

   Grading Rubric:

   55 Execution points
        2 Displays header info and instructions on screen when run
        3 Displays the board (Since I'm giving you all the code for this...)
        5 Allows selecting default values (robot 2 to square M), random values, or user-selected values.
       15 Allows making moves, displaying move numbers.  Input can be upper or lower case, and can have spaces or not.
       20 Robots stop at walls and don't run over each other
        5 Game stops and message is given when goal robot makes it to the goal square.
        5 If some robot besides robot 2 goes to the destination square (square M in this case), the destination square should change to show the robot there. When this robot moves away, the square should go back to displaying the letter that was there previously (M in our case.)

   45 Programming Style (Given only if program runs substantially correctly)
         5 Program naming convention is followed
         5 Meaningful identifier names
         5 Comments: Has header and this rubric.  Has comments on each block of code
        20 Appropriate data and control structures. Is implemented using classes.
        10 Code Layout: Appropriate indentation and blank lines
   ------------------------------------------------
*/

#include <iostream>
#include <cstring>      // for getline
#include <cstdlib>      // for the system command
#include <cctype>       // For the letter checking functions, e.g. toupper( )
#include <fstream>      // For file input and output
#include <cstdlib> 		//for rand()
#include <time.h>		//time for random
using namespace std;

// Global data structure for board
const int BOARD_EDGE = 16;
const int BOARD_SIZE = BOARD_EDGE * BOARD_EDGE;
const int NUMBER_OF_ROBOTS = 4;
// declare constants to later use instead of numbers to select values from theBoard
const int NUMBER_OF_ELEMENTS = 5;   // Number of elements for each piece, enumerated below
const int PIECE = 0;    // to reference the character, such as in: theBoard[ i][ PIECE]
const int LEFT = 1;     // to reference the left wall character, such as in: theBoard[ i][ LEFT]
const int ABOVE = 2;    // to reference the above wall character, such as in: theBoard[ i][ ABOVE]
const int RIGHT = 3;    // to reference the right wall character, such as in: theBoard[ i][ RIGHT]
const int BELOW = 4;    // to reference the below wall character, such as in: theBoard[ i][ BELOW]


//-------------------------------------------------------------------------------------
void displayIdentifyingInformationAndInstructions()
{
    // Display identifying information
    cout << "Author: Dale Reed                    " << endl
         << "Program 5: RicoRobots in C++         " << endl
         << "Lab: Tues, 9AM						  " << endl
         << "March 22, 2018                       " << endl;

    // Display Instructions
    cout << "Welcome to Ricochet Robots                                     " << endl
         << "(\'Ricochet Robot\' is a registered trademark of Hans im Glück " << endl
         << "Munich, Germany, 1999. The game was created by Alex Randolph.) " << endl
         << endl
         << "The object of the game is to get the designated numbered robot " << endl
         << "to the indicated letter position.                              " << endl
         << "The numbered squares are all robots.  They unfortunately have  " << endl
         << "no brakes, and so will continue in whatever direction they are " << endl
         << "moving until they encountar an obstacle.                       " << endl
         << "For each move enter the robot number and the desired direction." << endl
         << "For instance entering                                          " << endl
         << "   1 U " << endl
         << "would move the #1 robot up as far as it can go.                " << endl
         << "The first letter of input is the robot number (1 - 4),         " << endl
         << "and the second letter is the direction:                        " << endl
         << "  (L=left, U=up, R=right, D=down)                              " << endl
         << "Enter x to exit.  Have fun!                                    " << endl
         <<  endl;
}//end displayIdentifyingInformationAndInstructions()


//-------------------------------------------------------------------------------------
// createBoard() - Create the board, initializing all the display characters
//
void createBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
{
    for( int i=0; i<BOARD_SIZE; i++) {
        theBoard[ i][ PIECE]= '.';    // Set each playing piece default
        // set the default wall values to be blank
        theBoard[ i][ LEFT]= ' ';
        theBoard[ i][ ABOVE]= ' ';
        theBoard[ i][ RIGHT]= ' ';
        theBoard[ i][ BELOW]=  ' ';
        
        // reset the edge pieces
        // reset the left wall if piece is on left edge
        if( (i % BOARD_EDGE) == 0) {
            theBoard[ i][ LEFT]= '|';
        }
        // reset the above wall if piece is on top edge
        if( i < BOARD_EDGE) {
            theBoard[ i][ ABOVE]= '-';
        }
        // reset the right wall if piece is on right edge
        if( ((i+1) % BOARD_EDGE) == 0) {
            theBoard[ i][ RIGHT]= '|';
        }
        // reset the below wall if piece is on bottom edge
        if( i >= (BOARD_SIZE - BOARD_EDGE) ) {
            theBoard[ i][ BELOW]= '-';
        }
    }//end for( int i...
    
}//end createBoard()


//-------------------------------------------------------------------------------------
// readFromFileAndModifyBoard() - Read from data file, updating board accordingly
//
void readFromFileAndModifyBoard(
        char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS],
        int theRobots[ ],
        int &numberOfDestinationPieces)
{
    int numberOfSpecialSquares;  // Read from file, denotes number of pieces with some kind of wall
    string inputLine;            // Input line from file
    int pieceNumber;             // pieceNumber for each square defined in data file
    char c;
    
    ifstream inStream;           // declare an input file stream
    inStream.open("board.txt");  // Open input file, associating the actual file name with "inStream"
    if ( inStream.fail() ) {
        cout << "Input file opening failed.  Exiting...\n\n";
        exit(-1);
    }
    
    // Read from file one line at a time.  First read the top three data file lines which are documentation.
    getline( inStream, inputLine);
    getline( inStream, inputLine);
    getline( inStream, inputLine);
    
    inStream >> numberOfDestinationPieces;      // read how many destination pieces there are
    inStream >> numberOfSpecialSquares;         // number of square with walls around them somewhere
    inStream.get( c);                           // Get rid of return character at end of current line
                                                // to get ready for reading a line at a time below
    
    // process the special squares, updating the board
    for( int i=0; i<numberOfSpecialSquares; i++) {
        getline( inStream, inputLine);
        char *pInputLine = &inputLine[0];
        // Extract the piece number from the input line array
        sscanf( pInputLine, "%d", &pieceNumber);
        // Advance the inputLine pointer to the space after the number
        pInputLine = strchr( pInputLine, ' ');

        // Read the information on whether or not there is each of the potential 4 walls.
        // The four values read correspond in order to the pieces on all four sides,
        // which are defined as global constants for the values LEFT=1, ABOVE=2, RIGHT=3, BELOW=4
        for( int position=1; position<=4; position++) {
            pInputLine++;   // advance to next character to be read
            sscanf( pInputLine, " %c", &c);         // Read the next potential wall character
            // Convert it to a blank if it was '0'.  '0' was left in input file to make it easier to read.
            if( c=='0') {
                c = ' ';
            }
            theBoard[ pieceNumber][ position] = c;
        }
        pInputLine++;

        // See if there is a piece letter still to be read on this input line.
        // Do this by finding the end of the line, and seeing the length of the string
        // after that.
        // An inputline sample for piece 18 would be:
        // 18 00|- A
        if( strlen( pInputLine) > 0) {
            sscanf( pInputLine, " %c", &theBoard[ pieceNumber][ PIECE]);
        }

    }//end for( int i...
    
    // At the end of the data file read the information on the location of the robots, updating the board.
    char junk[80];           // used to read and discard input file information
    // Loop starts counting from 1 (rather than 0), since we ignore the 0th position
    // of the robots array, so that robot numbers correspond to what is shown
    // on the board.
    for( int i=1; i<=NUMBER_OF_ROBOTS; i++) {
        inStream >> theRobots[ i];
        inStream.getline( junk, '\n');    // discard rest of line, which is color information, if using graphics
        // set robot on board, converting the integer value to a character
        theBoard[ theRobots[ i]][ PIECE] = (char)('0'+i);     // record the robot number in place on board
    }
    
    inStream.close();         // close the input file stream
}//end readFromFileAndModifyBoard()


//-------------------------------------------------------------------------------------
// Display the Board
//
void displayTheBoard( char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS])
{
    // display the top edge
    cout << "  ---------------------------------------------------------------- " << endl;
    
    // display the "body" of the board
    for( int i=0; i<BOARD_SIZE; i++) {
        // Figure out what character should be displayed to the left.  It will
        // be a wall if the current spot has a left wall, or if the spot to the
        // left has a right wall.
        
        char leftCharacter = theBoard[ i][ LEFT];   // set left display char
        // See if the piece to the left has a right wall.  Don't do this for the
        // first piece on the board, since it has no left neighbor.
        if ( (i>0) && (theBoard[ i-1][ RIGHT] != ' ')) {
            leftCharacter = theBoard[ i-1][ RIGHT];
        }
        cout << " " << leftCharacter << " " << theBoard[ i][ PIECE];
        // see if we're at the end of a row
        if( ((i+1) % BOARD_EDGE) == 0) {
            // we are at the end of a row, so display right wall and go to next line
            cout << "  " << theBoard[ i][ RIGHT] << endl;
            // Now display any walls immediately below the line of pieces just displayed
            // Backup our index counter j to the beginning of this line again, to find any
            // walls displayed below this line.  Don't do it for the bottom row though.
            if( i < BOARD_SIZE - BOARD_EDGE) {
            
                cout << " |";       // display the left boundary
                for( int j=i-BOARD_EDGE+1; j<(i+1); j++) {
                    // Set the character to be displayed.  This is a wall if the
                    // current spot has a wall below, or if the spot below has a wall
                    // above.
                    char belowCharacter = theBoard[ j][ BELOW];
                    // Only check the square below if we're NOT on the bottom row
                    if ( (j<(BOARD_SIZE - BOARD_EDGE)) &&      // verify not on bottom row
                        (theBoard[ j+16][ ABOVE] != ' ')) {    // piece below has wall above
                        belowCharacter = theBoard[ j+16][ ABOVE];
                    }
                    for( int i=0; i<3; i++) {
                       cout << belowCharacter;        // display the character
                    }
                    // display extra spaces, if we're not at the end of a row
                    if( ((j+1) % BOARD_EDGE) != 0) {
                        cout << " ";
                    }
                }//end for( int j...
                cout << " |" << endl;       // display the right boundary
            }//end if( i< BOARD_SIZE...

        }//end if( ((i+1...
        
    }//end for( int i=0;...
    
    // display the bottom edge
    cout << "  ---------------------------------------------------------------- " << endl;
    cout << endl;
}//end displayTheBoard()

void makeMove(char moveDirection, int robotNum, char theBoard[BOARD_SIZE][NUMBER_OF_ELEMENTS], int theRobots[NUMBER_OF_ROBOTS + 1], int &numOfTurns, int &robotIndex)
{
	if (robotNum >= 1 && robotNum <= 4)
	{
		if (isalpha(moveDirection) && (moveDirection == 'U' || moveDirection == 'D' || moveDirection == 'R' || moveDirection == 'L'))
		{
			int robotIndex = theRobots[robotNum];
			
			if (moveDirection == 'U')
			{
				while (theBoard[robotIndex][ABOVE] != '-' && theBoard[robotIndex - 16][BELOW] != '-' && (theBoard[robotIndex - 16][PIECE] < 48 || theBoard[robotIndex - 16][PIECE] > 52))
				{
					theBoard[robotIndex][PIECE] = '.';
					theRobots[robotNum] = robotIndex - 16;
					robotIndex = theRobots[robotNum];
					theBoard[robotIndex][PIECE] = '0' + robotNum;
					system("cls");
				}
				
				numOfTurns++;
			}
			else if (moveDirection == 'D')
			{
				while (theBoard[robotIndex + 16][ABOVE] != '-' && theBoard[robotIndex][BELOW] != '-' && (theBoard[robotIndex + 16][PIECE] < 48 || theBoard[robotIndex + 16][PIECE] > 52))
				{
					theBoard[robotIndex][PIECE] = '.';
					theRobots[robotNum] = robotIndex + 16;
					robotIndex = theRobots[robotNum];
					theBoard[robotIndex][PIECE] = '0' + robotNum;
					system("cls");
				}
				
				numOfTurns++;
			}
			else if (moveDirection == 'L')
			{
				while (theBoard[robotIndex][LEFT] != '|' && theBoard[robotIndex - 1][RIGHT] != '|' && (theBoard[robotIndex - 1][PIECE] < 48 || theBoard[robotIndex - 1][PIECE] > 52))
				{
					theBoard[robotIndex][PIECE] = '.';
					theRobots[robotNum] = robotIndex - 1;
					robotIndex = theRobots[robotNum];
					theBoard[robotIndex][PIECE] = '0' + robotNum;
					system("cls");
				}
				
				numOfTurns++;
			}
			else if (moveDirection == 'R')
			{
				while (theBoard[robotIndex + 1][LEFT] != '|' && theBoard[robotIndex][RIGHT] != '|' && (theBoard[robotIndex + 1][PIECE] < 48 || theBoard[robotIndex + 1][PIECE] > 52))
				{
					theBoard[robotIndex][PIECE] = '.';
					theRobots[robotNum] = robotIndex + 1;
					robotIndex = theRobots[robotNum];
					theBoard[robotIndex][PIECE] = '0' + robotNum;
					system("cls");
				}
				
				numOfTurns++;
			}
			else
			{
				cout << "***Error, invalid direction. Retry Input." << endl;
			}
		
		robotIndex = theRobots[robotNum];			
		}
		else
		{
			cout << "Error, invalid direction. Retry Input." << endl;
		}
	}
}

void setGoalRobotAndDestinationLetter(char theBoard[BOARD_SIZE][NUMBER_OF_ELEMENTS], int &destinationLetterNumber, char destinationLetter)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (theBoard[i][PIECE] != destinationLetter && isalpha(theBoard[i][PIECE]))
		{
			theBoard[i][PIECE] = '.';
		}
		if(theBoard[i][PIECE] == destinationLetter)
		{
			destinationLetterNumber = i;
		}
	}
}

void checkIfEnterX(int &robotNum, char &moveDirection)
{
	char tempVariable;
	cin >> tempVariable;
	
	if (toupper(tempVariable) == 'X')
	{
		cout << "*** Exiting program..." << endl;
		exit(-1);
	}
	else
	{
		cin >> moveDirection;
		moveDirection = toupper(moveDirection);
		robotNum = tempVariable - '0';
	}
}



//-------------------------------------------------------------------------------------
// main() - main part of program, that drives everything else
//
int main()
{
    // theBoard itself is represented by a one-dimensional array.
    // The other entries are used to keep track of walls.  Each row
    // in theBoard array will contain the character to be displayed,
    // followed by any "walls" to be displayed around the displayed
    // character.  For instance the first couple of entries are be:
    //
    //       PIECE   LEFT ABOVE RIGHT BELOW
    //      ---0---  --1-  --2-  --3-  --4-
    //    0    .       |     _
    //    1    .             _
    //   ...
    //   255   .                   |     _
    //
    char theBoard[ BOARD_SIZE][ NUMBER_OF_ELEMENTS];
    // Declare the 4 robots, which will store the board position of where they are found
    // Robots are displayed using values 1-4.  We declare 5 robots, though we will never use
    // the 0th robot in the array, so that we can use the robot digit itself as the index.
    int theRobots[ NUMBER_OF_ROBOTS + 1] = {0,0,0,0,0};

    int goalRobot;                  // the robot that needs to reach the goal
    char destinationLetter;         // the goal letter
    int numberOfDestinationPieces;  // Number of destination pieces.  Value
                                    //    comes from the data file.
    
	/*************** end of Reed's sample main() code***************/
	
	//my new variables
	int robotNum;
	char moveDirection;
	char setUpRobotAndLetter;
	int numOfTurns = 1;
	int newGoalRobot;
	char newDestinationRobot;
	int destinationLetterNumber;
	int robotIndex;
	
	displayIdentifyingInformationAndInstructions();
    createBoard( theBoard);  
    readFromFileAndModifyBoard( theBoard, theRobots, numberOfDestinationPieces);
    
    while (setUpRobotAndLetter != 'D' || setUpRobotAndLetter != 'R' || setUpRobotAndLetter != 'S')
    {
    	cout << "Enter 'r' for random robot and goal, 'd' for default or 's' to select:	";
		cin >> setUpRobotAndLetter;
		setUpRobotAndLetter = toupper(setUpRobotAndLetter);
		
		if (setUpRobotAndLetter == 'D')
		{
			goalRobot = 2;
			destinationLetter = 'M';
			
			setGoalRobotAndDestinationLetter(theBoard, destinationLetterNumber, destinationLetter);
			break;
		} 
		else if (setUpRobotAndLetter == 'R')
		{
			srand(time(0));
			
			goalRobot = (rand() % 4) + 1;
			destinationLetter = (rand() % 15) + 'A';
			
			setGoalRobotAndDestinationLetter(theBoard, destinationLetterNumber, destinationLetter);
			break;
		}
		else if (setUpRobotAndLetter == 'S')
		{
			displayTheBoard(theBoard);
			
			cout << "Enter the goal robot number and destination letter: ";
			cin >> newGoalRobot;
			cin >> newDestinationRobot;
			newDestinationRobot = toupper(newDestinationRobot);
			
			goalRobot = newGoalRobot;
			destinationLetter = newDestinationRobot;
			
			setGoalRobotAndDestinationLetter(theBoard, destinationLetterNumber, destinationLetter);
			break;
		}
		else
		{
			cout << "***Error. Please enter the appropriate letter to set up the maze." << endl;
			continue;
		}
	}
	
	cout << "Move robot " << goalRobot << " to square " << destinationLetter << endl;
	
	while (goalRobot != destinationLetter)
	{
		if (theBoard[destinationLetterNumber][PIECE] == '.')
		{
			theBoard[destinationLetterNumber][PIECE] = destinationLetter;
		}
		
		if(theRobots[goalRobot] == destinationLetterNumber)
		{
			displayTheBoard(theBoard);
			cout<< "*** Goal reached! You did it in: " << numOfTurns << " moves." << endl;
			return 0;
		}
		
		displayTheBoard(theBoard);
		
		cout << numOfTurns << ". Please enter the robot to move and the direction (e.g. 2 r): ";
		
		checkIfEnterX(robotNum, moveDirection);
		
		makeMove(moveDirection, robotNum, theBoard, theRobots, numOfTurns, robotIndex);
	}
}//end main()
