/*
    POSTFIX TO INFIX

    Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
    
    Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
*/

// Example
/*
    Input : abc++
    Output : (a + (b + c))

    Input  : ab*c+
    Output : ((a*b)+c)
*/

// Algorithm
/*
    1.While there are input symbol left
    …1.1 Read the next symbol from the input.
    2.If the symbol is an operand
    …2.1 Push it onto the stack.
    3.Otherwise,
    …3.1 the symbol is an operator.
    …3.2 Pop the top 2 values from the stack.
    …3.3 Put the operator, with the values as arguments and form a string.
    …3.4 Push the resulted string back to stack.
    4.If there is only one value in the stack
    …4.1 That value in the stack is the desired infix string.
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

// Get infix for a given postfix expression
string getInfix(string exp)
{
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {

        // push operand
        if (isOperand(exp[i]))
        {
            string op(1, exp[i]);
            s.push(op);
        }

        // we assume that input is a valid postfix and expect an operator
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}

// Driver
int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);

    return 0;
}