#include "main.h"
/***************************************************************************//**
 * @author wizage
 *
 * @date Feb 10, 2016
 *
 * @par Csc 300 - Spring 2016
 *
 * @brief
 *    A barebone main that converst infix to postfix
 *
 ******************************************************************************/
int main( int argc, char *argv[] )
{
	std::vector<std::string> inputs;
	int numberOfInputs = getInputs(inputs);
	convertInputs(inputs, numberOfInputs);
    return 0;
}

/***************************************************************************//**
 * @author wizage
 *
 * @date Feb 10, 2016
 *
 * @par Csc 300 - Spring 2016
 *
 * @brief
 *    Gets the input from the user
 *
 * @param[out] inputs - A vector that contains all of the user inputs
 *
 * @return This function returns the size of the list.
 *
 ******************************************************************************/
int getInputs(std::vector<std::string> &inputs)
{
	int size = 0, n = 0;
	std::cin >> size;
	inputs.resize(size);
	for(n = 0; n < size; n++)
	{
		std::getline(std::cin, inputs[n]);
		if(inputs[n].empty()){n--;}
	}
	return size;
}

/***************************************************************************//**
 * @author wizage
 *
 * @date Feb 10, 2016
 *
 * @par Csc 300 - Spring 2016
 *
 * @brief
 *    Loops throught the list and converts the infix to postfix
 *
 * @param[in] inputs - A vector that contains all of the user inputs.
 * @param[in] size   - Size of the vector.
 *
 ******************************************************************************/
void convertInputs(std::vector<std::string> &inputs, int size)
{
	int n = 0;
	for(n = 0; n < size; n++)
	{
		convert(inputs[n]);
	}
}


/***************************************************************************//**
 * @author wizage
 *
 * @date Feb 10, 2016
 *
 * @par Csc 300 - Spring 2016
 *
 * @brief
 *    Converts the users input to postfix
 *
 * @param[in] input - A string containing one infix equation
 *
 ******************************************************************************/
void convert(std::string input)
{
	char top;
	bool isInt = true;
	int n = 0;
	std::stack<char> operators;
	std::string result ("");
	char *conversion = new char[input.length() + 1];
	std::strcpy(conversion, input.c_str());
	for(n = 0; n < input.length(); n++)
	{
		switch(conversion[n])
		{
			case '(':
				operators.push(conversion[n]);
				break;
			case ')':
				if(!operators.empty())
				{
					top = operators.top();
					while(top != '('){
						result += top;
						operators.pop();
						top = operators.top();
					}
					operators.pop();
				}
				break;
			case '+':
			case '-':
			
				if(!operators.empty())
				{
					top = operators.top();
					if(top == '*' || top == '/' || top == '^')
					{
						while(!operators.empty() && top != '(')
						{
							result += top;
							operators.pop();
							if(!operators.empty())
								top = operators.top();
						}
					}
					else if(top == '-' || top == '+')
					{
						result += top;
						operators.pop();
					}
				}
				operators.push(conversion[n]);
				break;
			case '*':
			case '/':
				if(!operators.empty())
				{
					top = operators.top();
					if(top == '^')
					{
						while(!operators.empty() && top != '(')
						{
							result += top;
							operators.pop();
							if(!operators.empty())
								top = operators.top();
						}
					}
					else if(top == '/' || top == '*')
					{
						result += top;
						operators.pop();
					}
				}
				operators.push(conversion[n]);
				break;
			case '^':
				operators.push(conversion[n]);
				break;
			case ' ':
				//Bye bye spaces
				break;
			default:
				result += conversion[n];
				if(isInt && std::isalpha(conversion[n]))
					isInt = false;
				break;
		}
	}
	while(!operators.empty())
	{
		result += operators.top();
		operators.pop();
	}
	delete[] conversion;
	std::cout << result;
	if (isInt)
		solveEqu(result);
	std::cout << std::endl;
}

/***************************************************************************//**
 * @author wizage
 *
 * @date Feb 10, 2016
 *
 * @par Csc 300 - Spring 2016
 *
 * @brief
 *    Evaluates a postfix equation if it contains integers
 *
 * @param[in] input - A string containing one postfix equation
 *
 ******************************************************************************/
void solveEqu(std::string result)
{
	std::stack<char> numberList;
	int number, number1, number2, n;
	char *conversion = new char[result.length() + 1];
	std::strcpy(conversion, result.c_str());
	for(n = 0; n < result.length(); n++)
	{
		switch(conversion[n])
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				number2 = numberList.top();
				numberList.pop();
				number1 = numberList.top();
				numberList.pop();
				number = doMaths(number1, number2, conversion[n]);
				numberList.push(number);
				break;
			default:
				number = conversion[n] - '0';
				numberList.push(number);
				break;
		}
	}
	number = numberList.top();
	std::cout << " = "<< number;
}

/***************************************************************************//**
 * @author wizage
 *
 * @date Feb 10, 2016
 *
 * @par Csc 300 - Spring 2016
 *
 * @brief
 *    Reads the operator and then preforms the operator function
 *
 * @param[in] number1 - An integer in the equation
 * @param[in] number2 - An integer in the equation
 * @param[in] op      - The operator that needs to be preformed
 *
 ******************************************************************************/
int doMaths(int number1, int number2, char op)
{
	if(op == '+')
		return number1+number2;
	else if(op == '-')
		return number1-number2;
	else if(op == '*')
		return number1*number2;
	else if(op == '/')
		return number1/number2;
	else if(op == '^')
		return std::pow(number1, number2);
}