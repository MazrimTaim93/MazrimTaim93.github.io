#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

string inToPostFix(string inFix);
double evaluatePostFix(string postFix);
bool hasPrecedence(char expr1, char expr2);

int main()
{
	ifstream ifs;
	ifs.open("data.txt");
	string equation;
	double solution;

	while (!ifs.eof())
	{
		getline(ifs, equation);
		cout << "infix: " << equation << endl;
		equation = inToPostFix(equation);
		cout << "postfix: " << equation << endl;
		solution = evaluatePostFix(equation);
		cout << "answer: " << solution << endl << endl;
		equation = "";
		ifs.peek();
	}

	ifs.close();
}

//returns true if expr1 has higher or equal precedence to expr2
bool hasPrecedence(char expr1, char expr2)
{
	bool higherPrec;

	if (expr1 == '*' || expr1 == '/')
		higherPrec = true;
	else if (expr2 == '+' || expr2 == '-')
		higherPrec = true;
	else
		higherPrec = false;

	return higherPrec;
}

//takes a string inFix equation and returns the equation as a string in postFix notations
string inToPostFix(string inFix)
{
	string postFix = "";
	stack<char> s;

	for (int i = 0; i < inFix.length(); i++)
	{
		if (isspace(inFix.at(i)))
			continue;
		else if (inFix.at(i) == '(')
			s.push(inFix.at(i));
		else if (isdigit(inFix.at(i)))
		{
			postFix += inFix.at(i);
			postFix += " ";
		}
		else if (inFix.at(i) == '+' || inFix.at(i) == '-' || inFix.at(i) == '*' || inFix.at(i) == '/')
		{
			while (!s.empty() && s.top() != '(' && hasPrecedence(s.top(), inFix.at(i)))
			{
				postFix += s.top();
				postFix += ' ';
				s.pop();
			}
			s.push(inFix.at(i));
				
		}
		else if (inFix.at(i) == ')')
		{
			postFix += s.top();
			postFix += " ";
			s.pop();

			while (s.top() != '(')
			{
				postFix += s.top();
				postFix += " ";
				s.pop();
			}
			s.pop();
		}
	}

	while (!s.empty())
	{
		postFix += s.top();
		s.pop();
	}

	return postFix;
}

//calculates the value of a postFix notation string equation and returns the solution as a double
double evaluatePostFix(string postFix)
{
	double answer = 0;
	stack<double> s;

	for (int i = 0; i < postFix.length(); i++)
	{
		if (isspace(postFix.at(i)))
			continue;
		else if (isdigit(postFix.at(i)))
		{
			answer = postFix.at(i) - '0';
			s.push(answer);
		}
		else
		{
			double y = s.top();
			s.pop();
			if (s.empty())
				answer = y;

			//If next is a operator, evaluate the last two numbers on the stack
			else
			{
				double x = s.top();
				s.pop();
				switch (postFix.at(i))
				{
				case '+':
					answer = x + y;
					//cout << x << "+" << y<< "=" << answer << endl;
					s.push(answer);
					break;
				case '-':
					answer = x - y;
					//cout << x << "-" << y << "=" << answer << endl;
					s.push(answer);
					break;
				case '*':
					answer = x * y;
					//cout << x << "*" << y << "=" << answer << endl;
					s.push(answer);
					break;
				case '/':
					answer = x / y;
					//cout << x << "/" << y << "=" << answer << endl;
					s.push(answer);
					break;
				}
			}
		}
	}

	return answer;
}