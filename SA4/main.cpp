#include <iostream>
#include <string>
#include <vector>
#include <stack>

int getInputs(std::vector<std::string> &);
void convertInputs(std::vector<std::string> &, int);
std::string convert(std::string);

int main( int argc, char *argv[] )
{
	std::vector<std::string> inputs;
	int numberOfInputs = getInputs(inputs);
	convertInputs(inputs, numberOfInputs);
    return 0;
}

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

void convertInputs(std::vector<std::string> &inputs, int size)
{
	int n = 0;
	for(n = 0; n < size; n++)
	{
		inputs[n] = convert(inputs[n]);
	}
}

std::string convert(std::string input)
{
	char top;
	int n = 0;
	std::stack<char> operators;
	std::string result ("");
	char *conversion = new char[input.length() + 1];
	strcpy(conversion, input.c_str());
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
			std::cout << "Called /" << std::endl;
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
				break;
			default:
				result += conversion[n];
				break;
		}
		std::cout << result << std::endl;
		//std::cout << conversion[n] << std::endl;
	}
	while(!operators.empty())
	{
		result += operators.top();
		operators.pop();
	}
	std::cout << result << std::endl;
	return result;
}