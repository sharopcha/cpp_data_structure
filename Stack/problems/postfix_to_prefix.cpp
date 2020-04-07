// POSTFIX TO PREFIX CONVERSION
/*
    Postfix: An expression is called the postfix expression if the operator appears in the expression after the operands. Simply of the form (operand1 operand2 operator).
    Example : AB+CD-* (Infix : (A+B) * (C-D) )

    Prefix : An expression is called the prefix expression if the operator appears in the expression before the operands. Simply of the form (operator operand1 operand2).
    Example : *+AB-CD (Infix : (A+B) * (C-D) ) 
*/

// Example
/*
    Input :  Postfix : AB+CD-*
    Output : Prefix :  *+AB-CD
    Explanation : Postfix to Infix : (A+B) * (C-D)
                Infix to Prefix :  *+AB-CD

    Input :  Postfix : ABC/-AK/L-*
    Output : Prefix :  *-A/BC-/AKL
    Explanation : Postfix to Infix : ((A-(B/C))*((A/K)-L))
              Infix to Prefix :  *-A/BC-/AKL 
*/

// Algorithm
/*
    Read the Postfix expression from left to right
    If the symbol is an operand, then push it onto the Stack
    If the symbol is an operator, then pop two operands from the Stack
    Create a string by concatenating the two operands and the operator before them.
    string = operator + operand2 + operand1
    And push the resultant string back to Stack
    Repeat the above steps until end of Prefix expression.
*/

#include <bits/stdc++.h>
using namespace std;

// function to check if character is operator
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

// convert postfix to prefix expression
string postToPref(string post_exp)
{

    stack<string> s;

    // length of expression
    int length = post_exp.size();

    // reading from left to right
    for (int i = 0; i < length; i++)
    {

        // check if symbol is operator
        if (isOperator(post_exp[i]))
        {

            // pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // concat the operands and operator
            string temp = post_exp[i] + op2 + op2;

            // cout << temp << endl;

            // push string temp back to stack
            s.push(temp);
        }

        // if symbol is operand
        else
        {
            // push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }

    // stack[0] contains the prefix expression
    return s.top();
}

// Driver
int main()
{
    string post_exp = "ABC/-AK/L-*";
    cout << "Prefix: " << postToPref(post_exp);

    return 0;
}