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

	try{
		while(in != "q")
		{
			if(is_str_digit(in)){
				st.push(in);
			}
			else if(is_str_operator(in))
			{
				if(st.size() < 2){	//check there are two operands available
					throw 1;
				}

				string value2 = st.top();
				st.pop();
				string value1 = st.top();
				st.pop();
				int value3;

				//check operands are integers
				if(!is_str_digit(value2) || !is_str_digit(value1)){
					throw 1;
				}

				switch(in[0])
				{
					case '+':
						value3 = stoi(value2) + stoi(value1);
						st.push(to_string(value3));
						break;

					case '-':
						value3 = stoi(value2) - stoi(value1);
						st.push(to_string(value3));
						break;

					case '*':
						value3 = stoi(value2) * stoi(value1);
						st.push(to_string(value3));
						break;

					case '/':
						value3 = stoi(value2) / stoi(value1);
						st.push(to_string(value3));
						break;
				}
			}else{ 	//Unexpected character
				throw 2;
			}
			cin >> in;
		}
		//check that the stack is clear
		if(st.size() != 0){
			throw 3;
		}
	//ERROR handling
	}catch(int e){
		cout << "ERROR: ";
		if(e == 1){
			cout << "Incorrect operands for operation" << endl;
		}else if(e == 2){
			cout << "Unexpected Input" << endl;
		}else if(e == 3){
			cout << "Items remain on stack after operations" << endl;
		}

		return 1;
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
