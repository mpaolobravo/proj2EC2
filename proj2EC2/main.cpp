/*  Program: Project 2 EC version
 Author: Miguel Bravo
 Class:	CSCI 110 FRI
 Date: 10/17/2014
 Description:
 
 I certify that the code below is my own work.
	
	Exception(s): N/A
 
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void programInfo();
void inputInfo(char slash, char &operation, int &n1, int &n2, int &d1, int &d2, int &a1, int &a2);
void calc(char operation,int &n3, int &d3,int n1, int n2, int d1, int d2, int &counter, int &correctCounter, int a1, int a2);
void outputInfo(char operation, int n1, int n2, int n3, int d1, int d2, int d3);

void calcFraction (int &n3, int &d3);

int main()
{
    
    cout << "Author: Miguel Bravo's Fraction Tutorial Program... \n\n";
    
    int n1, n2, n3, d1, d2, d3 , a1, a2;
    char slash;
    char operation;
    int counter=0;
    int correctCounter=0;
    double answerCounter=0;
    
    programInfo();
    
    while(operation != '%'){
        
        inputInfo(slash, operation, n1, n2, d1, d2, a1, a2);
        calc(operation, n3, d3, n1, n2, d1, d2, counter, correctCounter, a1, a2);
        outputInfo(operation, n1, n2, n3, d1, d2, d3);
        
    }
    
    answerCounter = double(correctCounter) / double(counter);
    
    cout << "You answered " << correctCounter << " out of " << counter << " problems correctly (" << answerCounter << "%).\n"<< endl;
    
    
    return 0;
}


void programInfo(){
    cout << "Please follow instructions carefully." << endl;
    cout << "Enter your operation like 1/2 + 1/4." << endl;
    cout << "You must enter a valid operation." << endl;
    cout << "Enter % operator to stop the program (0/1 % 0/1)." << endl;
}


void inputInfo(char slash, char &operation, int &n1, int &n2, int &d1, int &d2, int &a1, int &a2){
    
    cout << "\nPlease enter your operation --> ";
    cin >> n1 >> slash >> d1 >> operation >> n2 >> slash >> d2;
    
    if(operation != '%'){
        if(d1 * d2 == 1){
            cout << "Please enter your result --> ";
            cin >> a1;
        }else{
        cout << "Please enter your result --> ";
        cin >> a1 >> slash >> a2;
        }
    }
}


void calc(char operation, int &n3, int &d3,int n1, int n2, int d1, int d2 , int &counter, int &correctCounter, int a1, int a2){
    
    
    if(operation=='+'){
        n3 = (n1 * d2) + (n2 * d1);
        d3 = d1 * d2;
        calcFraction(n3, d3);
    }
    
    if(operation=='-'){
        n3 = (n1 * d2) - (n2 * d1);
        d3 = d1 * d2;
        calcFraction(n3, d3);
    }
    
    if(operation=='/'){
        n3 = (n1 * d2);
        d3 = (n2 * d1);
        calcFraction(n3, d3);
    }
    
    if(operation=='*'){
        n3 = (n1 * n2);
        d3 = (d1 * d2);
        calcFraction(n3, d3);
    }
    
    if(operation != '%'){
        counter++;
        if(n3 == a1 && d3 == a2){
            correctCounter++;
            cout << "Great job! It is correct. " << endl;
        }else{
            cout << "It is incorrect: " << endl;
        }
    }
}


void outputInfo(char operation, int n1, int n2, int n3, int d1, int d2, int d3){
    
    double answerValue;
    
    cout << fixed << showpoint << setprecision(2);
    
    if(operation != '%'){
        
        if(d3 ==1){
            cout << n1 << "/" << d1 << " " << operation << " "  << n2 << "/" << d2 <<
            " = " << n3 << endl;
        }else{
        
        cout << n1 << "/" << d1 << " " << operation << " "  << n2 << "/" << d2 <<
        " = " << n3 << "/" << d3  << endl;
        
        answerValue = double(n3) / double(d3);
        
        cout << "Its floating-point value is " << answerValue << endl ;
            
        }
        
    }else{
        cout << "You have chosen to exit the program. "<< endl;
    }
    
}

void calcFraction (int &n3, int &d3){
    
    int x=0;
    
    for (x = abs(n3 * d3); x > 1; x--) {
        if ((n3 % x == 0) && (d3 % x == 0)) {
            n3 /= x;
            d3 /= x;
        }
        
    }
    
}








