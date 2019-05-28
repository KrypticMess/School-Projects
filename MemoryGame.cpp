#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/***** Function Declarations *****/

void Introduction();
void RandomBoard();
void DisplayBoard();

char  p0,  p1,  p2,  p3,  p4,  p5,
	  p6,  p7,  p8,  p9, p10, p11,
	 p12, p13, p14, p15, p16, p17,
	 p18, p19, p20, p21, p22, p23,
	 p24, p25, p26, p27, p28, p29,
	 p30, p31, p32, p33, p34, p35;	 

/***** Function Definitions *****/

void DisplayBoard()
{
	RandomBoard();
	
	cout << "    1 2 3 4 5 6 \n";
	cout << "  - - - - - - - -" << endl;
	cout << "A | " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " | A" << endl;
	cout << "B | " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " | B" << endl;
	cout << "C | " << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " | C" << endl;
	cout << "D | " << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " | D" << endl;
	cout << "E | " << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " | E" << endl;
	cout << "F | " << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " | F" << endl;
	cout << "  - - - - - - - -" << endl << endl;
}

void RandomBoard()
{
	int s0,  s1,  s2,  s3,  s4,  s5,
		s6,  s7,  s8,  s9,  s10, s11,
		s12, s13, s14, s15, s16, s17,
		s18, s19, s20, s21, s22, s23,
		s24, s25, s26, s27, s28, s29,
		s30, s31, s32, s33, s34, s35;
		
	srand(time(0)); //Unique seed
	
	int numX = 0;
	int sum;
	
	while( numX < 1)
	{
		s0 = rand() % 2; s1 = rand() % 2; s2 = rand() % 2; s3 = rand() % 2; s4 = rand() % 2; s5 = rand() % 2; //Row A
		
		sum = s0 + s1 + s2 + s3 + s4 + s5;
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		s6 = rand() % 2; s7 = rand() % 2; s8 = rand() % 2; s9 = rand() % 2; s10 = rand() % 2; s11 = rand() % 2; //Row B
		
		sum = s6 + s7 + s8 + s9 + s10 + s11;
		
		if (sum % 2 == 0)
		{
			continue;
		}
			
		s12 = rand() % 2; s13 = rand() % 2; s14 = rand() % 2; s15 = rand()% 2; s16 = rand() % 2; s17 = rand() % 2; //Row C

		sum = s12 + s13 + s14 + s15 + s16 + s17;
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		s18 = rand() % 2; s19 = rand() % 2; s20 = rand() % 2; s21 = rand() % 2; s22 = rand() % 2; s23 = rand() % 2; //Row D
		
		sum = s18 + s19 + s20 + s21 + s22 + s23;
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		s24 = rand() % 2; s25 = rand() % 2; s26 = rand() % 2; s27 = rand() % 2; s28 = rand() % 2; s29 = rand() % 2; //Row E
		
		sum = s24 + s25 + s26 + s27 + s28 + s29;
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		s30 = rand() % 2; s31 = rand() % 2; s32 = rand() % 2; s33 = rand() % 2; s34 = rand() % 2; s35 = rand() % 2; //Row F 
		
		sum = s30 + s31 + s32 + s33 + s34 + s35;
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		sum = s0 + s6 + s12 + s18 + s24 + s30; //Col 1
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		sum = s1 + s7 + s13 + s19 + s25 + s31; //Col 2
		
		if (sum % 2 == 0)
		{
			continue;
		}
	
		sum = s2 + s8 + s14 + s20 + s26 + s32; //Col 3
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		sum = s3 + s9 + s15 + s21 + s27 + s33; //Col 4
		
		if (sum % 2 == 0)
		{
			continue;
		}		
		
		sum = s4 + s10 + s16 + s22 + s28 + s34; //Col 5
		
		if (sum % 2 == 0)
		{
			continue;
		}

		sum = s5 + s11 + s17 + s23 + s29 + s35; //Col 6
		
		if (sum % 2 == 0)
		{
			continue;
		}
		
		numX++;		
	}
	
	switch(s0)
	{
		case 0: p0 = 'X'; break;
		case 1: p0 = 'O'; break;
	}
	switch(s1)
	{
		case 0: p1 = 'X'; break;
		case 1: p1 = 'O'; break;
	}
	switch(s2)
	{
		case 0: p2 = 'X'; break;
		case 1: p2 = 'O'; break;
	}
	switch(s3)
	{
		case 0: p3 = 'X'; break;
		case 1: p3 = 'O'; break;
	}
	switch(s4)
	{
		case 0: p4 = 'X'; break;
		case 1: p4 = 'O'; break;
	}
	switch(s5)
	{
		case 0: p5 = 'X'; break;
		case 1: p5 = 'O'; break;
	}
	switch(s6)
	{
		case 0: p6 = 'X'; break;
		case 1: p6 = 'O'; break;
	}
	switch(s7)
	{
		case 0: p7 = 'X'; break;
		case 1: p7 = 'O'; break;
	}
	switch(s8)
	{
		case 0: p8 = 'X'; break;
		case 1: p8 = 'O'; break;
	}
	switch(s9)
	{
		case 0: p9 = 'X'; break;
		case 1: p9 = 'O'; break;
	}
	switch(s10)
	{
		case 0: p10 = 'X'; break;
		case 1: p10 = 'O'; break;
	}
	switch(s11)
	{
		case 0: p11 = 'X'; break;
		case 1: p11 = 'O'; break;
	}
	switch(s12)
	{
		case 0: p12 = 'X'; break;
		case 1: p12 = 'O'; break;
	}
	switch(s13)
	{
		case 0: p13 = 'X'; break;
		case 1: p13 = 'O'; break;
	}
	switch(s14)
	{
		case 0: p14 = 'X'; break;
		case 1: p14 = 'O'; break;
	}
	switch(s15)
	{
		case 0: p15 = 'X'; break;
		case 1: p15 = 'O'; break;
	}
	switch(s16)
	{
		case 0: p16 = 'X'; break;
		case 1: p16 = 'O'; break;
	}
	switch(s17)
	{
		case 0: p17 = 'X'; break;
		case 1: p17 = 'O'; break;
	}
	switch(s18)
	{
		case 0: p18 = 'X'; break;
		case 1: p18 = 'O'; break;
	}
	switch(s19)
	{
		case 0: p19 = 'X'; break;
		case 1: p19 = 'O'; break;
	}
	switch(s20)
	{
		case 0: p20 = 'X'; break;
		case 1: p20 = 'O'; break;
	}
	switch(s21)
	{
		case 0: p21 = 'X'; break;
		case 1: p21 = 'O'; break;
	}
	switch(s22)
	{
		case 0: p22 = 'X'; break;
		case 1: p22 = 'O'; break;
	}
	switch(s23)
	{
		case 0: p23 = 'X'; break;
		case 1: p23 = 'O'; break;
	}
	switch(s24)
	{
		case 0: p24 = 'X'; break;
		case 1: p24 = 'O'; break;
	}
	switch(s25)
	{
		case 0: p25 = 'X'; break;
		case 1: p25 = 'O'; break;
	}
	switch(s26)
	{
		case 0: p26 = 'X'; break;
		case 1: p26 = 'O'; break;
	}
	switch(s27)
	{
		case 0: p27 = 'X'; break;
		case 1: p27 = 'O'; break;
	}
	switch(s28)
	{
		case 0: p28 = 'X'; break;
		case 1: p28 = 'O'; break;
	}
	switch(s29)
	{
		case 0: p29 = 'X'; break;
		case 1: p29 = 'O'; break;
	}
	switch(s30)
	{
		case 0: p30 = 'X'; break;
		case 1: p30 = 'O'; break;
	}
	switch(s31)
	{
		case 0: p31 = 'X'; break;
		case 1: p31 = 'O'; break;
	}
	switch(s32)
	{
		case 0: p32 = 'X'; break;
		case 1: p32 = 'O'; break;
	}
	switch(s33)
	{
		case 0: p33 = 'X'; break;
		case 1: p33 = 'O'; break;
	}
	switch(s34)
	{
		case 0: p34 = 'X'; break;
		case 1: p34 = 'O'; break;
	}
	switch(s35)
	{
		case 0: p35 = 'X'; break;
		case 1: p35 = 'O'; break;
	}

}

void Introduction()
{
	cout << "Author:  Maria Alexis Sales" << endl;
	cout << "Class:   CS 141, Spring 2018" << endl;
	cout << "Lab:     Tues, 9am" << endl;
	cout << "Program: #2, Memory Game" << endl << endl;
	
	cout << "Welcome to the memory game!" << endl << endl;
	
	cout << "Look away fromt he board and have a helper enter r" << endl;
	cout << "to randomize the board until they have a random board" << endl;
	cout << "that they like. Then you glance at it and try to" << endl;
	cout << "imprint it in your mind and look away. Your helper" << endl;
	cout << "will pick a single piece to be flipped by" << endl;
	cout << "choosing its row and column. The changed board is then" << endl;
	cout << "displayed. You must then try to guess which one it was." << endl;
	cout << "Enter x to exit the program." << endl << endl;
}

int main()
{
	Introduction();
	DisplayBoard();
	
	char userInput = ' ';
	
	cout << "Enter r to randomize to board, or row and column to change a value -> ";
	cin >> userInput;
	cout << endl;
	
	while(userInput == 'r' || userInput == 'R')
	{
		DisplayBoard();
		cout << "Enter r to randomize to board, or row and column to change a value -> ";
		cin >> userInput;
		cout << endl;
		
		continue;
	}
	
	char userInput2 = ' ';
	cin >> userInput2;
	
	if (userInput != 'R' || userInput != 'r')
	{		
		switch(userInput)
		{
			case 'a':
			case 'A':
				
				switch(userInput2)
				{
					case '1':
						
						switch(p0)
						{
							case 'X': p0 = 'O'; break;
							case 'O': p0 = 'X'; break;
						}
					break;
					
					case '2':
						
						switch(p1)
						{
							case 'X': p1 = 'O'; break;
							case 'O': p1 = 'X'; break;
						}
					break;
					
					case '3':
						
						switch(p2)
						{
							case 'X': p2 = 'O'; break;
							case 'O': p2 = 'X'; break;
						}
					break;
					
					case '4':
						
						switch(p3)
						{
							case 'X': p3 = 'O'; break;
							case 'O': p3 = 'X'; break;
						}
					break;
					
					case '5':
						
						switch(p4)
						{
							case 'X': p4 = 'O'; break;
							case 'O': p4 = 'X'; break;
						}
					break;
					
					case '6':
						
						switch(p5)
						{
							case 'X': p5 = 'O'; break;
							case 'O': p5 = 'X'; break;
						}
					break;
				}
				break;
				
			case 'b':
			case 'B':
				
				switch(userInput2)
				{
					case '1':
						
						switch(p6)
						{
							case 'X': p6 = 'O'; break;
							case 'O': p6 = 'X'; break;
						}
					break;
					
					case '2':
						
						switch(p7)
						{
							case 'X': p7 = 'O'; break;
							case 'O': p7 = 'X'; break;
						}
					break;
					
					case '3':
						
						switch(p8)
						{
							case 'X': p8 = 'O'; break;
							case 'O': p8 = 'X'; break;
						}
					break;
					
					case '4':
						
						switch(p9)
						{
							case 'X': p9 = 'O'; break;
							case 'O': p9 = 'X'; break;
						}
					break;
					
					case '5':
						
						switch(p10)
						{
							case 'X': p10 = 'O'; break;
							case 'O': p10 = 'X'; break;
						}
					break;
					
					case '6':
						
						switch(p11)
						{
							case 'X': p11 = 'O'; break;
							case 'O': p11 = 'X'; break;
						}
					break;
				}
				break;
			
			case 'c':
			case 'C':
				
				switch(userInput2)
				{
					case '1':
						
						switch(p12)
						{
							case 'X': p12 = 'O'; break;
							case 'O': p12 = 'X'; break;
						}
					break;
					
					case '2':
						
						switch(p13)
						{
							case 'X': p13 = 'O'; break;
							case 'O': p13 = 'X'; break;
						}
					break;
					
					case '3':
						
						switch(p14)
						{
							case 'X': p14 = 'O'; break;
							case 'O': p14 = 'X'; break;
						}
					break;
					
					case '4':
						
						switch(p15)
						{
							case 'X': p15 = 'O'; break;
							case 'O': p15 = 'X'; break;
						}
					break;
					
					case '5':
						
						switch(p16)
						{
							case 'X': p16 = 'O'; break;
							case 'O': p16 = 'X'; break;
						}
					break;
					
					case '6':
						
						switch(p17)
						{
							case 'X': p17 = 'O'; break;
							case 'O': p17 = 'X'; break;
						}
					break;
				}
				break;
			
			case 'd':
			case 'D':
				
				switch(userInput2)
				{
					case '1':
						
						switch(p18)
						{
							case 'X': p18 = 'O'; break;
							case 'O': p18 = 'X'; break;
						}
					break;
					
					case '2':
						
						switch(p19)
						{
							case 'X': p19 = 'O'; break;
							case 'O': p19 = 'X'; break;
						}
					break;
					
					case '3':
						
						switch(p20)
						{
							case 'X': p20 = 'O'; break;
							case 'O': p20 = 'X'; break;
						}
					break;
					
					case '4':
						
						switch(p21)
						{
							case 'X': p21 = 'O'; break;
							case 'O': p21 = 'X'; break;
						}
					break;
					
					case '5':
						
						switch(p22)
						{
							case 'X': p22 = 'O'; break;
							case 'O': p22 = 'X'; break;
						}
					break;
					
					case '6':
						
						switch(p23)
						{
							case 'X': p23 = 'O'; break;
							case 'O': p23 = 'X'; break;
						}
					break;
				}
				break;
				
			case 'e':
			case 'E':
				
				switch(userInput2)
				{
					case '1':
						
						switch(p24)
						{
							case 'X': p24 = 'O'; break;
							case 'O': p24 = 'X'; break;
						}
					break;
					
					case '2':
						
						switch(p25)
						{
							case 'X': p25 = 'O'; break;
							case 'O': p25 = 'X'; break;
						}
					break;
					
					case '3':
						
						switch(p26)
						{
							case 'X': p26 = 'O'; break;
							case 'O': p26 = 'X'; break;
						}
					break;
					
					case '4':
						
						switch(p27)
						{
							case 'X': p27 = 'O'; break;
							case 'O': p27 = 'X'; break;
						}
					break;
					
					case '5':
						
						switch(p28)
						{
							case 'X': p28 = 'O'; break;
							case 'O': p28 = 'X'; break;
						}
					break;
					
					case '6':
						
						switch(p29)
						{
							case 'X': p29 = 'O'; break;
							case 'O': p29 = 'X'; break;
						}
					break;
				}
				break;
				
			case 'f':
			case 'F':
				
				switch(userInput2)
				{
					case '1':
						
						switch(p30)
						{
							case 'X': p30 = 'O'; break;
							case 'O': p30 = 'X'; break;
						}
					break;
					
					case '2':
						
						switch(p31)
						{
							case 'X': p31 = 'O'; break;
							case 'O': p31 = 'X'; break;
						}
					break;
					
					case '3':
						
						switch(p32)
						{
							case 'X': p32 = 'O'; break;
							case 'O': p32 = 'X'; break;
						}
					break;
					
					case '4':
						
						switch(p33)
						{
							case 'X': p33 = 'O'; break;
							case 'O': p33 = 'X'; break;
						}
					break;
					
					case '5':
						
						switch(p34)
						{
							case 'X': p34 = 'O'; break;
							case 'O': p34 = 'X'; break;
						}
					break;
					
					case '6':
						
						switch(p35)
						{
							case 'X': p35 = 'O'; break;
							case 'O': p35 = 'X'; break;
						}
					break;
				}
				break;
		}
	}
	
	char correctInput = userInput;
	char correctInput2 = userInput2;
	char guessInput = ' ';
	char guessInput2 = ' ';
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
	cout << "    1 2 3 4 5 6 \n";
	cout << "  - - - - - - - -" << endl;
	cout << "A | " << p0 << " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << " | A" << endl;
	cout << "B | " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << " " << p11 << " | B" << endl;
	cout << "C | " << p12 << " " << p13 << " " << p14 << " " << p15 << " " << p16 << " " << p17 << " | C" << endl;
	cout << "D | " << p18 << " " << p19 << " " << p20 << " " << p21 << " " << p22 << " " << p23 << " | D" << endl;
	cout << "E | " << p24 << " " << p25 << " " << p26 << " " << p27 << " " << p28 << " " << p29 << " | E" << endl;
	cout << "F | " << p30 << " " << p31 << " " << p32 << " " << p33 << " " << p34 << " " << p35 << " | F" << endl;
	cout << "  - - - - - - - -" << endl << endl;
	
	cout << "Which one? -> ";
	
	cin >> guessInput;
	cin >> guessInput2;
	
	if((guessInput == correctInput && guessInput2 == correctInput2) || (guessInput == toupper(correctInput) && guessInput2 == correctInput2))
	{
		cout << endl << "*** Congratulations, you did it! ***" << endl;
	}
	else
	{
		cout << endl << "Sorry, it was " << correctInput << correctInput2 << ". Better luck next time."<< endl;
	}
	
	cout << endl << "Thank you for playing. Exiting...";
	
	return 0;
}
