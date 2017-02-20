
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//******************************************************************************************************
// Global  const int
//******************************************************************************************************

const int COL = 4;

//******************************************************************************************************
// Prototype
//*****************************************************************************************************

void displayGrades (const int [][COL], string [], const int);
void calcuQuizAverage (double [], const int [] [COL], const int);
void calcStudentAverage (double [], const int [][COL], const int);
void displayAvg (double [], const int);
double calcAverage (const int [][COL], const int);

//******************************************************************************************************
// Main Function
//******************************************************************************************************

int main ()
{
	const int ROW = 4;
	int grades [ROW] [COL] = 
	    { 43, 42, 34, 45,
		  33, 37, 49, 50,
		  25, 29, 27, 34,
		  29, 33, 34, 32 };
	string studentName [COL] = { "John Doe", "Joe Doe", "Jane Doe", "Jerry Doe" };
	double quizAverages [COL];
	double studentAverages [COL];
	const int SIZE = 4;
	double getAverage; 


	displayGrades (grades, studentName, ROW);
	calcuQuizAverage (quizAverages, grades, ROW);
	calcStudentAverage (studentAverages, grades, ROW);
	// Display msg before calling function
	cout << "\n""For each quiz, the averages are: " << endl;
	cout << "=======================================================================" << endl;
	cout << left << setw (10) << "QUIZ1";
	cout << left << setw (10) << "QUIZ2";
	cout << left << setw (10) << "QUIZ3";
	cout << left << setw (10) << "QUIZ4";
	cout << endl;
	displayAvg (quizAverages, SIZE);
	// Display msg before calling function
	cout << "\n""For each student, the averages are: " << endl;
	cout << "=======================================================================" << endl;
	cout << left << setw (10) << "John Doe";
	cout << left << setw (10)  << "Joe Doe";
	cout << left << setw (10) << "Jane Doe";
	cout << left << setw (10) << "Jerry Doe";
	cout << endl;
	displayAvg (studentAverages, SIZE);
	getAverage = calcAverage (grades, ROW);
	cout << "\n""The average for all students are: " << fixed << showpoint << setprecision(1);
	cout << getAverage << endl;
	
		
	return 0;
}

//******************************************************************************************************
// Void displayGrades display student's grades in a 2-D table
//******************************************************************************************************

void displayGrades (const int grades [] [COL], string studentName [], const int ROW)
{
	const int TEST_MIN = 0;

	cout << left << setw (15) << "";

	for ( int counter = TEST_MIN; counter < COL; counter++)
	{
		cout << "Quiz" << left << setw (11) << counter + 1;
	}
	cout << endl;


	for (int r = TEST_MIN; r < ROW; r++)
	{
		cout << left << setw (15) << studentName [r];

		for ( int c = TEST_MIN; c < COL; c++)
		{
			cout << left << setw (15) << grades [r][c];
		}
		cout << endl;
	}
	cout << "=======================================================================" << endl;
}
	
//******************************************************************************************************
// Void calcQuizAverage calculate the average of each quiz
//******************************************************************************************************

void calcuQuizAverage (double quizAvg [], const int grades [] [COL], const int row)
{
	const int TEST_MIN = 0;
	int total;


	for ( int c = TEST_MIN; c < COL; c++)
	{
		total = 0;

		for (int r = TEST_MIN; r < row; r++)

			total += grades [r][c];

			quizAvg [c] = static_cast <double> (total) / row;
	}
}
			
//******************************************************************************************************
// Void calcStudentAverage calculate the average of each student
//******************************************************************************************************

void calcStudentAverage (double studentAvg [], const int grades [][COL], const int ROW)
{
	const int TEST_MIN = 0;
	double total;
	
	for (int r = TEST_MIN; r < ROW; r++)
	{
		total = 0;

		for ( int c = TEST_MIN; c < COL; c++)
			total += grades [r][c];

		studentAvg [r] = total / COL;
	}

}

//******************************************************************************************************
// Void displayAvg display both quiz average and student averages
//******************************************************************************************************

void displayAvg (double average [], const int SIZE)
{
	const int TEST_MIN = 0;

	for (int i = TEST_MIN; i < SIZE; i++)
	{
		cout << left << setw (10) << fixed << showpoint << setprecision(1)
		<< average[i];
	}
	cout << endl; 
}

//******************************************************************************************************
// Void calAverage calculates the average for all students and all quizzes
//******************************************************************************************************

double calcAverage (const int grades [][COL], const int ROW)
{
	const int TEST_MIN = 0;
	double total = 0;
	double avg;
	
	for ( int r = TEST_MIN; r < ROW; r++)
	{
		for (int c = TEST_MIN; c < COL; c++)
			total += grades[r][c];
		
	}	
	avg = total/ (ROW * COL);
		
	return avg;
}

// Display information entered by user
/*
** Grades information for all students **
=======================================================================
               Quiz1          Quiz2          Quiz3          Quiz4
John Doe       43             42             34             45
Joe Doe        33             37             49             50
Jane Doe       25             29             27             34
Jerry Doe      29             33             34             32
=======================================================================

For each quiz, the averages are:
=======================================================================
QUIZ1     QUIZ2     QUIZ3     QUIZ4
32.5      35.3      36.0      40.3

For each student, the averages are:
=======================================================================
John Doe  Joe Doe   Jane Doe  Jerry Doe
41.0      42.3      28.8      32.0

The average for all students are: 36.0
Press any key to continue . . .
*/
			
