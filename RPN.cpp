// RPN calculator

#include <iostream> 
#include <string>
#include <stack> 

using namespace std;
bool is_str_digit(string);  // returns true if input parameter string is and integer (e.g., "127343")
bool is_str_operator(string); // returns true if the input parameter is an operator character (e.g., "+", "*")


int main() 
{
    string in;
    stack<string> st;   // stack definition

    cin >> in;

	while(in != "q")
	{
		if(is_str_digit(in)){
			// add your code here
			st.push(in);
		}
		else if(is_str_operator(in))
		{
			// add your code here 
			int value1, value2, value3;

			switch(in[0])
			{
				case '+':
					value2 = stoi(st.top());
					st.pop();
					value1 = stoi(st.top());
					st.pop();
					value3 = value2 + value1;
					st.push(to_string(value3));
					break;

				case '-':
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
					value3 = value2 - value1;
					st.push(to_string(value3));
					break;

				case '*':
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
					value3 = value2 * value1;
					st.push(to_string(value3));
					break;

				case '/':
					value1 = stoi(st.top());
					st.pop();
					value2 = stoi(st.top());
					st.pop();
					value3 = value2 / value1;
					st.push(to_string(value3));
					break;
			}

			// add your code here

		}
		cin >> in;
	}

    cout << "The answer is : " << st.top() << endl;

    return 0; 
}

bool is_str_digit(string s)
{
    for (int i = 0; i < s.length(); ++i)
    {
            if(!isdigit(s[i]))
                return false;
    }
    return true;
}
bool is_str_operator(string s)
{
    return (s.length()==1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0]== '/'));
}
