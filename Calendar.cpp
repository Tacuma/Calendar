//Tacuma Solomon
//Computer Science 1
//Problem Description: This program writes software that Prints out
//calendars for any given year

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

ifstream inData;

void ID();
int get_year(int&);							//Function Prototype to output student ID
int starting_day(int&);						//Function Prototype to get start day
void Print_heading(int);					//Function Prototype to print heading
void Print_Month(int&, int&, string, int);	//Function Prototype to print month
void Read_month_data (string&, int&);		//Function Prototype to read data from a file
void Footer();

int main ()
{
	int hold;
	inData.open("month_data.dat"); //opens month_data.dat
	int year=0;					   //Year of the calendar
	int start_day=0;			   //Refers to the first day of each month
	string month;				   //This is the month of the year
	int day;					   //The number of days in each month
	ID();						   //prints student info to the screen
	get_year(year);				   //Gets the year from the user
	starting_day(start_day);	   //Gets the starting day from the user
	Print_heading(year);	       //Prints the Calendar head
	for (int count=1;count<=12;count++)   //1-12, for each month of the year
	{  
		Read_month_data(month,day);		  //Reads a month from file
		Print_Month(year, start_day, month, day); // Prints out month read from file
	}	
	Footer();
	system("pause");
	return 0;
}

//************************************************************************************

void ID () //This function Prints out the student and Assignment Information
{ 
	cout << "Tacuma Solomon"<< endl;
	cout << "Computer Science 1 -  Introductory Programming" << endl; 
	cout << "Problem Description: This program writes software that Prints out" << endl
		 << "calendars for any given year" << endl << endl << endl;
	return;

}

//*************************************************************************************

void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}

//*************************************************************************************

int get_year(int& year) // This function gets the year from the user
{
 cout << "Please input the Calendar year. Press Return." << endl;
 cin >> year;
 cout << endl << endl;
 return year;
}

//**************************************************************************************

int starting_day (int& start_day) // This function gets the initial day of the year from the user
{
	string control;
	string day;
	cout << "*****************************************************************" << endl << endl;
	cout << "Please input the first three letters of the year's first day." << endl
	     << "eg. Tuesday=Tue" << endl;
	cout << "Then Press Return." << endl;	
	cin >> day;
	cout << endl;
	cout << "*****************************************************************" << endl << endl;
	if (day=="Sun")
		start_day=1;
	else if (day=="Mon")
		start_day=2;
	else if (day=="Tue")
		start_day=3;
	else if (day=="Wed")
		start_day=4;
	else if (day=="Thu")
		start_day=5;
	else if (day=="Fri")
		start_day=6;
	else if (day=="Sat")
		start_day=7;
	return start_day;
}

//***********************************************************************


void Print_heading(int year) // This function is responsible for the Calendar head
{
	cout << "YEAR -- " << year << endl;
	return ;
}


//*************************************************************************

void Print_Month(int& yr, int& start_day, string month, int days) // Uses a nested loop to print the months of the year
{
	int track=1;	// Tracks when to skip to the next line
	int count=1;	// Counts and prints the days of the month
    track=start_day;  //uses the value from the function starting_day
	cout << month << endl;
	cout << "| S| M| T| W| T| F| S|" << endl;
	if (start_day==1)		// This construct determines how far in the first day of the month will tab.
		cout;
	else if (start_day==2)
		cout << setw(3) << " ";
	else if (start_day==3)
		cout << setw(6) << " ";
	else if (start_day==4)
		cout << setw(9) << " ";
	else if (start_day==5)
		cout << setw(12) << " ";
	else if (start_day==6)
		cout << setw(15) << " ";
	else if (start_day==7)
		cout << setw(18) << " ";
	while (count<=days)					 // Outer loop skips to the next line at the end of each week
	{

		while (track<=7 && count<=days)  // Inner loop prints the days of the month
		{
			cout << setw(3) << count;
			track++;
			count++;
		}
	cout<<endl;
	start_day=track;					//This determines the staring day of the following month
	track=1;
	}
	return;
}


//***************************************************

void Read_month_data(string& month, int& day) // Reads the Month and the number of days from a file
{
		inData >> month >> day;				// inputs data from file
		cout << endl << endl;
		return;
}


/*
Tacuma Solomon
Computer Science 1 -  Introductory Programming
Problem Description: This program writes software that Prints out
calendars for any given year


Please input the Calendar year. Press Return.
2013


*****************************************************************

Please input the first three letters of the year's first day.
eg. Tuesday=Tue
Then Press Return.
Tue

*****************************************************************

YEAR -- 2013


January
| S| M| T| W| T| F| S|
        1  2  3  4  5
  6  7  8  9 10 11 12
 13 14 15 16 17 18 19
 20 21 22 23 24 25 26
 27 28 29 30 31


February
| S| M| T| W| T| F| S|
                 1  2
  3  4  5  6  7  8  9
 10 11 12 13 14 15 16
 17 18 19 20 21 22 23
 24 25 26 27 28


March
| S| M| T| W| T| F| S|
                 1  2
  3  4  5  6  7  8  9
 10 11 12 13 14 15 16
 17 18 19 20 21 22 23
 24 25 26 27 28 29 30
 31


April
| S| M| T| W| T| F| S|
     1  2  3  4  5  6
  7  8  9 10 11 12 13
 14 15 16 17 18 19 20
 21 22 23 24 25 26 27
 28 29 30


May
| S| M| T| W| T| F| S|
           1  2  3  4
  5  6  7  8  9 10 11
 12 13 14 15 16 17 18
 19 20 21 22 23 24 25
 26 27 28 29 30 31


June
| S| M| T| W| T| F| S|
                    1
  2  3  4  5  6  7  8
  9 10 11 12 13 14 15
 16 17 18 19 20 21 22
 23 24 25 26 27 28 29
 30


July
| S| M| T| W| T| F| S|
     1  2  3  4  5  6
  7  8  9 10 11 12 13
 14 15 16 17 18 19 20
 21 22 23 24 25 26 27
 28 29 30 31


August
| S| M| T| W| T| F| S|
              1  2  3
  4  5  6  7  8  9 10
 11 12 13 14 15 16 17
 18 19 20 21 22 23 24
 25 26 27 28 29 30 31


September
| S| M| T| W| T| F| S|

  1  2  3  4  5  6  7
  8  9 10 11 12 13 14
 15 16 17 18 19 20 21
 22 23 24 25 26 27 28
 29 30


October
| S| M| T| W| T| F| S|
        1  2  3  4  5
  6  7  8  9 10 11 12
 13 14 15 16 17 18 19
 20 21 22 23 24 25 26
 27 28 29 30 31


November
| S| M| T| W| T| F| S|
                 1  2
  3  4  5  6  7  8  9
 10 11 12 13 14 15 16
 17 18 19 20 21 22 23
 24 25 26 27 28 29 30


December
| S| M| T| W| T| F| S|

  1  2  3  4  5  6  7
  8  9 10 11 12 13 14
 15 16 17 18 19 20 21
 22 23 24 25 26 27 28
 29 30 31


() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/