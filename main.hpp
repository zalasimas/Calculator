#ifndef MAIN_HPP
#define MAIN_HPP


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



// Description of additional function prototypes

// Function that checks if operand is a math operator
bool isMathOperator(char token);

// Function that returns the priority of each math operator
int OrderOfOperations(char token);

// Function that carries out calculation processes
double MakeCalculations(char mathOperator, double value1, double value2);

bool isNumeric(char value);
bool isNumeric(string value);

vector<string> SplitInput(const string& source, const string& delimiters = " ");
string ReplaceAllStrings(const string& source, const string& oldValue, const string& newValue);



// Declare a variable for the user input
class Calculator{
public:

string infix;
};



// This class displays instructions to the user
class DisplayInstructions{
    public:

void Display() {

        cout  << "\n**Skaiciuotuvo programa**\n"
        << "\nGalite naudoti siuos operatorius:\n" << endl
        << "+  Sudetis\n"
        << "-  Atimtis\n"
        << "*  Daugyba\n"
        << "/  Dalyba\n"
        << "$  Saknies traukimas\n"
        << "%  Modulis\n"
        << "^  Kelimas laipsniu\n"
        << "s  Sin\n"
        << "t  Tan\n"
        << "c  Cos\n"
        << "-  Neigiamas skaicius\n";
    }
};
// End of DisplayInstructions



// This class converts an infix expression to postfix
class Conversion {
    public:


string PerformConversion(string infix) {

    string postfix;
    stack<char> charStack;


    // Take away all whitespace from the string
    infix.erase(remove_if(infix.begin(), infix.end(), [](char c) {

        return isspace(static_cast<unsigned char>(c));
    }), infix.end());


    // Eliminate equations that are marked with -- sign
    infix = ReplaceAllStrings(infix, "(--", "(");


    /* At this point need to convert negative numbers to have ~ sign 
       After that we can separate negative numbers and the subtraction sign
    */ 

    for (unsigned x = 0; x < infix.length(); ++x) {

        if (infix[x] != '-') {

            continue;
        }

        if (x == 0 || infix[x - 1] == '(' || isMathOperator(infix[x - 1])) {

            infix[x] = '~';
        }
    }

    // Looping through array until data are available (until there is no more data)
    for (unsigned x = 0; x < infix.length(); ++x) {

        /* Place numbers (standard, decimal, & negative)
           numbers into the 'postfix' string
        */ 

        if (isNumeric(infix[x])) {

            if (postfix.length() > 0 && !isNumeric(postfix[postfix.length() - 1])) {

                if (!isspace(postfix[postfix.length() - 1])) {

                    postfix += " ";
                }
            }

            postfix += infix[x];
        }
         else if (isspace(infix[x])) {

            continue;
        } 
        else if (isMathOperator(infix[x])) {

            if (postfix.length() > 0 && !isspace(postfix[postfix.length() - 1])) {

                postfix += " ";
            }

            /*
             Need to use OrderOfOperations in order to check equality
             of the math operator which is at the top of the stack compared to
             the current math operator in the Infix string.
            */

            while ((!charStack.empty()) && (OrderOfOperations(charStack.top()) >= OrderOfOperations(infix[x]))) {

                /*
                Need to place math operator from the top of the stack
                into the Postfix string and continue the process until
                complete
                */
                
                if (postfix.length() > 0 && !isspace(postfix[postfix.length() - 1])) {

                    postfix += " ";
                }

                postfix += charStack.top();
                charStack.pop();
            }

            // Push remaining math operator into the stack
            charStack.push(infix[x]);
        }


        // Push outer parentheses into stack
        else if (infix[x] == '(') {

            charStack.push(infix[x]);
        } 
        
        else if (infix[x] == ')') {

            // Pop current math operator from the stack
            while ((!charStack.empty()) && (charStack.top() != '(')) {

                if (postfix.length() > 0 && !isspace(postfix[postfix.length() - 1])) {

                    postfix += " ";
                }

                // Place math operator into the Postfix string
                postfix += charStack.top();

                /*
                 Pop the next operator from the stack and
                 Continue the process until complete
                */
                charStack.pop();
            }

            // Pop '(' symbol off the stack
            if (!charStack.empty()) {

                charStack.pop();

            } 
            else {

                // Show error if there is a parenthesis error
                throw invalid_argument{ "Klaida!" };
            }

            // Or simply in other cases...
        } 
        else {

            throw invalid_argument{ "Bloga ivestis!" };
        }
    }


 // Place any remaining math operators from the stack into the postfix array
    while (!charStack.empty()) {

        if (charStack.top() == '(' || charStack.top() == ')') {

            throw invalid_argument{ "Bloga ivestis!" };
        }

        if (postfix.length() > 0 && !isspace(postfix[postfix.length() - 1])) {

            postfix += " ";
        }

        postfix += charStack.top();
        charStack.pop();
    }

    // Replacing all ~ symbols with a minus sign
    postfix = ReplaceAllStrings(postfix, "~", "-");

    return postfix;
    }
};
// End of PerformConversion



// This function checks if operand is a math operator

bool isMathOperator(char token) {

    switch (tolower(token)) {

        case '+': case '-': case '*': case '/':
        case '%': case '^': case '$': case 'c':
        case 's': case 't':

            return true;
            break;

        default:
            return false;
            break;
        }
}
// End of isMathOperator



// This function returns the priority of each math operator
int OrderOfOperations(char token) {

    int priority = 0;

    switch (tolower(token)) {

        case 'c': case 's': case 't':
            priority = 5;
            break;
        case '^': case '$':
            priority = 4;
            break;
        case '*': case '/': case '%':
            priority = 3;
            break;
        case '-':
            priority = 2;
            break;
        case '+':
            priority = 1;
            break;
    }
    return priority;
}
// End of OrderOfOperations



// This class evaluates a postfix expression
class PostFix{
    public:

double EvaluatePostfix(const string& postfix) {

    // Function variables
    double answer = 0;
    stack<double> doubleStack;
    
     // Create objects for the MathOperator
   // Operator Check;

    /*
     Split string into tokens to isolate multi digit, negative and decimal
     numbers, aswell as single digit numbers and math operators
    */

    auto tokens = SplitInput(postfix);

    cout << "\nAtlikti skaiciavimai:\n";

    // Looping through array until data are available (until there is no more data)
    for (unsigned x = 0; x < tokens.size(); ++x) {

        auto token = tokens[x];

        // Push numbers and negative numbers into the stack
        if (isNumeric(token)) {

            doubleStack.push(atof(token.c_str()));
        }

        /*
         If an expression is a math operator, pop numbers from the stack
         and send the popped numbers to the MakeCalculations function
         */

        else if (isMathOperator(token[0]) && (!doubleStack.empty())) {

            double value1 = 0;
            double value2 = 0;
            char mathOperator = static_cast<unsigned char>(tolower(token[0]));

        /*
        If expression is square root, sin, cos,
         or tan operation only pop stack once
        */

            if (mathOperator == '$' || mathOperator == 's' || mathOperator == 'c' || mathOperator == 't') {

                value2 = 0;
                value1 = doubleStack.top();
                doubleStack.pop();
                answer = MakeCalculations(mathOperator, value1, value2);
                doubleStack.push(answer);

            } 
            else if (doubleStack.size() > 1) {

                value2 = doubleStack.top();
                doubleStack.pop();
                value1 = doubleStack.top();
                doubleStack.pop();
                answer = MakeCalculations(mathOperator, value1, value2);
                doubleStack.push(answer);
            }
        } 
    }

    // Pop the final answer from the stack, and return it to the main
    if (!doubleStack.empty()) {

        answer = doubleStack.top();
    }
    return answer;
    }
};
// End of EvaluatePostfix



// Function that carries out calculation processes
double MakeCalculations(char mathOperator, double value1, double value2) {
    
    double ans = 0;

    switch (tolower(mathOperator)) {

        case '+':
            cout << value1 << mathOperator << value2;
            ans = value1 + value2;
            break;

        case '-':
            cout << value1 << mathOperator << value2;
            ans = value1 - value2;
            break;

        case '*':
            cout << value1 << mathOperator << value2;
            ans = value1 * value2;
            break;

        case '/':
            cout << value1 << mathOperator << value2;
            ans = value1 / value2;
            break;

        case '%':
            cout << value1 << mathOperator << value2;
            ans = ((int)value1 % (int)value2) + std::modf(value1, &value2);
            break;

        case '^':
            cout << value1 << mathOperator << value2;
            ans = pow(value1, value2);
            break;

        case '$':
            cout << char(251) << value1;
            ans = sqrt(value1);
            break;

        case 'c':
            cout << "cos(" << value1 << ")";
            ans = cos(value1);
            break;

        case 's':
            cout << "sin(" << value1 << ")";
            ans = sin(value1);
            break;

        case 't':
            cout << "tan(" << value1 << ")";
            ans = tan(value1);
            break;

        default:
            ans = 0;
            break;
    }

    cout << " = " << ans << endl;
    return ans;
}
// End of MakeCalculations



vector<string> SplitInput(const string& source, const string& delimiters) {

    size_t prev = 0;
    size_t currentPos = 0;
    vector<string> results;

    while ((currentPos = source.find_first_of(delimiters, prev)) != string::npos) {

        if (currentPos > prev) {

            results.push_back(source.substr(prev, currentPos - prev));
        }
        prev = currentPos + 1;
    }
    if (prev < source.length()) {

        results.push_back(source.substr(prev, string::npos));
    }
    return results;
}

// End of SplitInput



string ReplaceAllStrings(const string& source, const string& oldValue, const string& newValue) {

    if (oldValue.empty()) {

        return source;
    }

    string newString;
    newString.reserve(source.length());
    size_t lastPos = 0;
    size_t findPos;

    while (string::npos != (findPos = source.find(oldValue, lastPos))) {

        newString.append(source, lastPos, findPos - lastPos);
        newString += newValue;
        lastPos = findPos + oldValue.length();
    }

    newString += source.substr(lastPos);
    return newString;
}
// End of ReplaceAllStrings



bool isNumeric(char value) {

    return isdigit(value) || value == '.' || value == '~';
}
// End of CharNumeric



bool isNumeric(string value) {

    for (unsigned index = 0; index < value.length(); ++index) {

        if (index == 0 && value[index] == '-' && value.length() > 1) {

            continue;
        }
        if (!isNumeric(value[index])) {

            return false;
        }
    }
    return true;
}
// End of StringNumeric

#endif