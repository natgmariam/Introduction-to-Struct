/*
Description: using struct to read user input and save data 
to output list contaning name, grade, and result. 
Input:User is prompted to put a sstring for names annd an 
int for grades to assigne letter grade 
Output:is a list contaning all the info from user input and 
the asssigned letter grade
*/
#include <iostream> //c++ librarary
#include <string>   //string libraray
#include <iomanip>  //library for parametric manipulators
using namespace std;
//struct to hole inofrmation  
struct studentType
{
    //user defined function 
    //memebers / ekements 
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};
//function prototypes 
void getStudentData(studentType &);
void getLetterGrade(studentType &);
void printStudentData(studentType);

int main()
{
    //declaring instance of struct 
    studentType student;
    //calling student data 
    getStudentData(student);
    //calling letter grade 
    getLetterGrade(student);
    //output student data 
    printStudentData(student);

    return 0;
}
//refrence passed student data, input from user 
void getStudentData(studentType &student)
{

    int eMax = 100;
    int MIN = 0;
    int MAX = 4;

    cout << "Enter a first name\n**";
    cin >> student.firstName;
    cout << endl;

    cout << "Enter a last name\n**";
    cin >> student.lastName;
    cout << endl;
    //to account of input error for grades
    do
    {
        cout << "Enter a grade\n**";
        cin >> student.grade;

        if (cin.fail() || student.grade < MIN || student.grade > MAX)
        {
            cin.clear();
            cin.ignore(eMax, '\n');
            cout << "\nError: Invalid grade\n";
            continue;
        }
        break; 
    } while (true);
}
//ussing user input to set letter grade and pass student struct
void getLetterGrade(studentType &student)
{
    //assigning letter grades to user input for int 
    if (student.grade == 4)
    {
        student.letterGrade = 'A';
    }
    else if (student.grade == 3)
    {
        student.letterGrade = 'B';
    }
    else if (student.grade == 2)
    {
        student.letterGrade = 'C';
    }
    else if (student.grade == 1)
    {
        student.letterGrade = 'D';
    }
    else if (student.grade == 0)
    {
        student.letterGrade = 'F';
    }
}
//print data on the student and arranged by parametric manipulators 
void printStudentData(studentType student)
{
    cout << "\nData Entered\n";
    cout << right << setw(19) << "student.firstName" 
    << setw(5) << "= " << student.firstName << endl;
    //output arrangement via parametric manipulators
    cout << right << setw(18) << "student.lastName" 
    << setw(6) << "= " << student.lastName << endl;
    
    cout << right << setw(15) << "student.grade" 
    << setw(9) << "= " << student.grade << endl;
    
    cout << right << setw(21) << "student.letterGrade" 
    << setw(3) << "= " << student.letterGrade << endl;
}

