#include <gtest/gtest.h>

#include "../Test.hpp"


// Functions tested

// Check that the operator entered by the user is correct
TEST(CalculatorTest, CheckOperator){

          bool result = isMathOperator('+');
          EXPECT_TRUE(result);

          bool result2 = isMathOperator('-');
          EXPECT_TRUE(result2);

          bool result3 = isMathOperator('*');
          EXPECT_TRUE(result3);

          bool result4 = isMathOperator('/');
          EXPECT_TRUE(result4);

          bool result5 = isMathOperator('%');
          EXPECT_TRUE(result5);

          bool result6 = isMathOperator('^');
          EXPECT_TRUE(result6);

          bool result7 = isMathOperator('$');
          EXPECT_TRUE(result7);

          bool result8 = isMathOperator('c');
          EXPECT_TRUE(result8);

          bool result9 = isMathOperator('s');
          EXPECT_TRUE(result9);

          bool result10 = isMathOperator('t');
          EXPECT_TRUE(result10);
}



// Check calculation process
TEST(CalculatorTest2, CheckCalculation){

    // For example give some parameters for the equation
    //double answer = 25;
    double Calculation;
    double RootValue = 3.53;
    double Cosinus = 12.5;
    double Sinus = 12.5;
    double Tangent = 12.5;


    Calculation = MakeCalculations('+', 12.5, 12.5);
    EXPECT_EQ(25, Calculation) << Calculation;

    Calculation = MakeCalculations('-', 12.5, 12.5);
    EXPECT_EQ(0, Calculation) << Calculation;

    Calculation = MakeCalculations('*', 12.5, 12.5);
    EXPECT_EQ(156.25, Calculation) << Calculation;

    Calculation = MakeCalculations('/', 12.5, 12.5);
    EXPECT_EQ(1, Calculation) << Calculation;

    Calculation = MakeCalculations('%', 12.5, 12.5);
    EXPECT_EQ(0.5, Calculation) << Calculation;


// At this point I have to use smaller numbers, in order to get a more readable answer 
    Calculation = MakeCalculations('^', 2, 2);
    EXPECT_EQ(4, Calculation) << Calculation;


// At this point I must get math operation with only one number (value1)
    Calculation = MakeCalculations('$', 12.5, 0); 


// To get reduced Sqrt value for comfortable use, I have to set precision for the result

    stringstream SmallerValue; // Allow to use a string object like a stream
    SmallerValue << setprecision(3) << fixed << Calculation; // set manipulator function to control the number of digits
    double ReducedRootValue = stod(SmallerValue.str()); // Parse string as a floating-point and return double

    EXPECT_EQ(3.536, ReducedRootValue) << ReducedRootValue;
    SmallerValue.str(string()); // Clear SmallerValue for future use


    Calculation = MakeCalculations('c', 12.5, 0);
    EXPECT_EQ(cos(Cosinus), Calculation) << Calculation;
    

    Calculation = MakeCalculations('s', 12.5, 0);
    EXPECT_EQ(sin(Sinus), Calculation) << Calculation;


    Calculation = MakeCalculations('t', 12.5, 0);
    EXPECT_EQ(tan(Tangent), Calculation) << Calculation;

// Wrong operator
    Calculation = MakeCalculations('.', 12.5, 12.5);
    EXPECT_EQ(0, Calculation) << Calculation;

}   



// Check the priority of math operator

/*
For this test case I tried to do some automated testing,
for example when we have many chars. But now I have a suspicion
that this is not the best solution, especially when using strok()
*/

TEST(CalculatorTest3, CheckPriority){


char FirstCase[] = "c-s-t";
char SecondCase[] = "^-$";
char ThirdCase[] = "*-/-%";
char FourthCase[] = "-";
char FifthCase[] = "+";


// Return tokens
char *token1 = strtok(FirstCase, "-");
char *token2 = strtok(SecondCase, "-");
char *token3 = strtok(ThirdCase, "-");
char *token4 = strtok(FourthCase, "/");
char *token5 = strtok(FifthCase, "/");


char *ReceivedValueFirst;
char *ReceivedValueSecond;
char *ReceivedValueThird;
char *ReceivedValueFourth;
char *ReceivedValueFifth;


int ExpectedPriority5 = 5;
int ExpectedPriority4 = 4;
int ExpectedPriority3 = 3;
int ExpectedPriority2 = 2;
int ExpectedPriority1 = 1;


    /*
    Keep printing tokens while one of the
    delimiters present in Cases[].
    */


while (token1 != NULL)
    {
        ReceivedValueFirst = token1;
        int ReceivedToken1 = OrderOfOperations(*ReceivedValueFirst);
        EXPECT_EQ(ExpectedPriority5, ReceivedToken1) << ReceivedToken1;
        token1 = strtok(NULL, "-");
    }

while (token2 != NULL)
    {
        ReceivedValueSecond = token2;
        int ReceivedToken2 = OrderOfOperations(*ReceivedValueSecond);
        EXPECT_EQ(ExpectedPriority4, ReceivedToken2) << ReceivedToken2;
        token2 = strtok(NULL, "-");
    }

while (token3 != NULL)
    {
        ReceivedValueThird = token3;
        int ReceivedToken3 = OrderOfOperations(*ReceivedValueThird);
        EXPECT_EQ(ExpectedPriority3, ReceivedToken3) << ReceivedToken3;
        token3 = strtok(NULL, "-");
    }

while (token4 != NULL)
    {
        ReceivedValueFourth = token4;
        int ReceivedToken4 = OrderOfOperations(*ReceivedValueFourth);
        EXPECT_EQ(ExpectedPriority2, ReceivedToken4) << ReceivedToken4;
        token4 = strtok(NULL, "/");
    }

while (token5 != NULL)
    {
        ReceivedValueFifth = token5;
        int ReceivedToken5 = OrderOfOperations(*ReceivedValueFifth);
        EXPECT_EQ(ExpectedPriority1, ReceivedToken5) << ReceivedToken5;
        token5 = strtok(NULL, "/");
    }
}   