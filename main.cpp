#include <iostream>
#include <stack>
class Solution
{
private:
	int 	is_open(char element);
	int 	is_pair(char open_element, char close_element);
public:
	bool 	isValid(std::string line);
};

int Solution::is_open(char element)
{
	return (element == '(' || element == '{' || element == '[');
}

int Solution::is_pair(char open_element, char close_element)
{
	return ((open_element == '{' && close_element == '}') ||\
			(open_element == '(' && close_element == ')') ||\
			(open_element == '[' && close_element == ']'));
}

bool Solution::isValid(std::string line)
{
	std::stack<int> st;
	int 			i;
	size_t			length;

	i = 0;
	length = line.length();
	if (length < 2 || length > 10000)
		return (0);
	while (i < length)
	{
		if(is_open(line[i]))
			st.push(line[i]);
		else if (!st.empty() && is_pair(st.top(), line[i]))
			st.pop();
		else
			return (0);
		i++;
	}
	if (st.empty())
		return (1);
	return (0);
}

int main()
{
	std::string s;
	Solution valid_parentheses;
	int result;

	s = "){";
	result = valid_parentheses.isValid(s);
	std::cout << result;
	s = "()[]{}";
	result = valid_parentheses.isValid(s);
	std::cout << result;
	s = "[{(}])";
	result = valid_parentheses.isValid(s);
	std::cout << result;
	s = "{)";
	result = valid_parentheses.isValid(s);
	std::cout << result;
}