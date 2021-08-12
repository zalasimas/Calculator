/*
Task:

Write command line application "Calculator". Application should allow to enter math line of any length,
 i.e. x+2*9-8/3* (2- 1) -32.4, and give the result. 

· Application should be written in C++ in object oriented way;  

· A tree should be constructed where nodes are operations and leafs are values;

· Use features from C++ 11 or C++ 14 where possible;

· Implement couple unit tests with gtest;

· Use Cmake for build configuration.

*/


// Include main header file
#include "main.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <exception>
#include <stdexcept>

using namespace std;



int main() {

// Declare a variable for the user input

Calculator variable;

    variable.infix = "";

    // Display Calculator instructions for the user
    DisplayInstructions information;
    information.Display();

    try {

        // Receive data from the user
        cout << "\nIveskite norima skaiciuoti eilute: ";
        getline(cin, variable.infix);


        // Convert Infix expression to the Postfix
        Conversion start;
        string postfix = start.PerformConversion(variable.infix);


    // Evaluate the Postfix string and assign it to the result variable
        PostFix Evaluate;
        double result = Evaluate.EvaluatePostfix(postfix);


    // Output an answer to the user 
        cout << "\nGautas atsakymas = " << result << endl;
    } 
    

    // If an error has occurred, display error message
    catch (exception& e) {

        cout << "\nKlaida!: " + string(e.what()) << endl;
    }
 
    cout << "\n<ENTER> kad langas uzsidarytu" << endl;
    cin.get();
    return 0;
}
// End of main function
