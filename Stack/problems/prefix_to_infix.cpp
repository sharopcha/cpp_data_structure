//   PREFIX TO INFIX CONVERSION
/*
    Infix : An expression is called the Infix expression if the operator appears in between the operands in the expression. Simply of the form (operand1 operator operand2).
    Example : (A+B) * (C-D)

    Prefix : An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2).
    Example : *+AB-CD (Infix : (A+B) * (C-D) )
*/

// Example
/*
    Input :  Prefix :  *+AB-CD
    Output : Infix : ((A+B)*(C-D))

    Input :  Prefix :  *-A/BC-/AKL
    Output : Infix : ((A-(B/C))*((A/K)-L)) 
*/

// Algorithm
/*
    Read the Prefix expression in reverse order (from right to left)
    If the symbol is an operand, then push it onto the Stack
    If the symbol is an operator, then pop two operands from the Stack
    Create a string by concatenating the two operands and the operator between them.
    string = (operand1 + operator + operand2)
    And push the resultant string back to Stack
    Repeat the above steps until end of Prefix expression.  
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if the character is operator
bool isOperator(char x)
{

    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }

    return false;
}

// Convert prefix to Infix expression
string prefixToInfix(string pre_exp)
{
    stack<string> s;

    // length of expression
    int length = pre_exp.size();

    // reading from right to left
    for (int i = length - 1; i >= 0; i--)
    {

        // check if symbol is operator
        if (isOperator(pre_exp[i]))
        {

            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // concat the operands and operator
            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            // push string temp back to stack
            s.push(temp);
        }

        // if symbol is operand
        else
        {
            s.push(string(1, pre_exp[i]));
        }

        for (int j = 0; j < s.size(); j++)
        {
            cout << s.top() << endl;
        }
    }

    // stack now conatins the infix expression
    return s.top();
}

// Driver
int main()
{
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix: " << prefixToInfix(pre_exp) << endl;

    return 0;
}