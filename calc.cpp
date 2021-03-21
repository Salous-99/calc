#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

string postFix(string str){
  if(str.length() == 0) return "";
  stack<char> s;
  string post = "";

  for(int i = 0; i < str.length(); i++){
    if(str[i] >= '0' && str[i] <= '9' || str[i] == '.'){
      post += str[i];
    }

    else if(i == 0 && str[i] == '-'){
      post += '-';
    }

    else if(str[i] == '-' && (str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/' || str[i-1] == '^' || str[i-1] == '('
    || str[i-1] == '%')){
      post += '-';
    }

    else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == ')' || str[i] == '(' || str[i] == '%'){
      if(str[i] != '(') post += ' ';
      if(str[i] == '(')
        s.push(str[i]);

      else if(str[i] == ')'){
        while(s.top() != '('){
          post += s.top();
          post += ' ';
          s.pop();
        }
        s.pop();
      }
      else if(str[i] == '^'){
        while(!s.empty() && s.top() == '^' && s.top() != '('){
          post += '^';
          post += ' ';
          s.pop();
        }
        s.push(str[i]);
      }

      else if(str[i] == '*' || str[i] == '/' || str[i] == '%'){
        while(!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '('){
          post += s.top();
          post += ' ';
          s.pop();
        }
        s.push(str[i]);
      }

      else if(str[i] == '+' || str[i] == '-'){
        while(!s.empty() && s.top() != '('){
          post += s.top();
          post += ' ';
          s.pop();
        }
        s.push(str[i]);
      }
    }
    else{
      cout << "Invalid character " << str[i] << " in infix expression\n";
      cout << "Exiting...\n";
      exit(-1);
    }

  }

  post += ' ';
  while(!s.empty()){
    post += s.top();
    post += ' ';
    s.pop();
  }
  return post;
}

double better_stoi(string str){
  if(str[0] == '-') return 0 - better_stoi(str.erase(0,1));
  int dot = str.length();
  for(int i = 0; str[i] != '\0'; i++){
      if(str[i] == '.'){
        dot = i;
        continue;
      }
      else if(str[i] > '9' || str[i] < '0'){
        cout << "string contains invalid character\n";
        return -1;
        }
  }

	string temp1 = "", temp2 = "";
	for(int i = 0; i != dot; i++) temp1 += str[i];
	for(int i = dot + 1; i < str.length(); i++) temp2 += str[i];

	double whole;
  if(temp1.length() != 0) whole = stoi(temp1);
	double frac;
  if(temp2.length() != 0) frac = (double)stoi(temp2)/pow(10, temp2.length());

  return whole + frac;
}

double calc(string str){
  if(str.length() == 0) return 0;
  stack<double> s;

  for(int i = 0; i < str.length(); i++){
    if(str[i] == ' ') continue;

    else if(i != str.length() - 1 && str[i] == '-' && str[i+1] >= '0' && str[i+1] <= '9'){
      string temp = "";
      while(i < str.length() && str[i+1] != ' ') temp += str[i++];
      temp += str[i++];
      s.push(better_stoi(temp));
    }

    else if(str[i] >= '0' && str[i] <= '9'){
      string temp = "";
      while(i < str.length() && str[i+1] != ' ') temp += str[i++];
      temp += str[i++];
      s.push(better_stoi(temp));
    }

    else if(!s.empty() && str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '%'){
      double operR = s.top();
      s.pop();
      double operL = s.top();
      s.pop();

      if(str[i] == '+')
        s.push(operL + operR);
      if(str[i] == '-')
        s.push(operL - operR);
      if(str[i] == '*')
        s.push(operL * operR);
      if(str[i] == '/')
        s.push(operL / operR);
      if(str[i] == '%')
        s.push((int)operL % (int)operR);
      if(str[i] == '^')
        s.push(pow(operL, operR));
    }
  }

  return s.top();
}

int main(int argc, char *argv[]){
  string infix = "";
  while(!cin.eof()){
    infix = "";
    if(argc == 1){
      string temp;
      getline(cin, temp);
      for(int i = 0; i < temp.length(); i++)
        if(temp[i] != ' ')
          infix += temp[i];

      if(infix != "") cout << calc(postFix(infix)) << endl;
    }
    else{
      cout << "calc does not take any command line argument, enter \"calc\" then the input infix expression through stdin\n";
      exit(-1);
    }
  }

  return 0;
}
