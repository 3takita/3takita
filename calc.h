#pragma once
#include <stack>
#include <cmath>

#include <iostream>
using namespace std;

class Calc {
private:
    string str;
public:
    //constructors
    Calc() {
        str = "";
    }
    Calc(const string _str, stack<int>& _nums) {
        setStr(_str);
    }
    //setters
    void setStr(string _str) {
        str = _str;
    }
    //getters
    string getStr() {
        return str;
    }
    stack<int> nums; //stack that holds input numbers
    friend void brain(const string str, stack<int>& nums);
                    //MEMBER FUNCTIONS
    //PreCondition: Input string is fully parenthesized.
    //PostCondition: Returns a true value if the parenthesis in the input string are balanced, else returns a value of false.
    bool is_balanced(const string& str) {
	    const char left_par = '(';
	    const char right_par = ')';
	    stack<char> store; //stores the left parenthesis
	    char next; //next charater from the string
	    bool done = false; //becomes true if a needed par is not found
	    for(int i=0; !done && (i<str.length()); i++) {
		    next = str[i];
		    if(next==left_par) {
			store.push(next);
		    }else if((next==right_par) && (!store.empty())) {
			    store.pop(); //pops the corresponding left parenthesis
		    }else if((next==right_par) && (store.empty())) {
			    done = true;
		    }
	    }
	    return (store.empty() && !done);
    }
    
    //Precondition: Input string is a fully parenthesized expression of positive numbers (from 0 to 9), five operations (+, -, *, /, ^).
    //Postcondition: Returns a string of characters for the calculator program.
    string input() { //input
        cout<<"Make your entry: "; //ask for user input
        string _str;                //declare str
        getline(cin, _str);         //get user input n store it in str
        return _str;
    }
    
    //PreCondition: Argument must be a stack of positive numbers and input string.
    //PostCondition: Pops the last two numbers in the number stack and pushes their sum unto the stack.
    void add(stack<int>& nums, const string str) { 
        int r=nums.top();  //save 1st nums top to r
        nums.pop();        //pop off r
        int l=nums.top();  //save 2nd nums top to l
        nums.pop();        //pop off l
        int result = l+r;  //add l to r and save sum a result
        nums.push(result); //push result unto the num stack
    }
    
    //PreCondition: Argument must be a stack of positive numbers and input string.
    //PostCondition: Pops the last two numbers in the nums stack and pushes their difference unto the nums stack.
    void subtract(stack<int>& nums, const string str) { 
        int r=nums.top();  //save 1st nums top to r
        nums.pop();        //pop off r
        int l=nums.top();  //save 2nd nums top to l
        nums.pop();        //pop off l
        int result = l - r;  //do l - r and save the difference as result
        nums.push(result); //push result unto the num stack
    }
    
    //PreCondition: Argument must be a stack of positive numbers and input string.
    //PostCondition: Pops the last two numbers in the number stack and pushes their product unto the stack.
     void multiply(stack<int>& nums, const string str) { 
        int r=nums.top();  //save 1st nums top to r
        nums.pop();        //pop off r
        int l=nums.top();  //save 2nd nums top to l
        nums.pop();        //pop off l
        int result = l * r;  //do l * r and save the difference as result
        nums.push(result); //push result unto the num stack
    }
    
    //PreCondition: Argument must be a stack of positive numbers and input string.
    //PostCondition: Pops the last two numbers in the number stack and pushes their quotient unto the stack.
    void divide(stack<int>& nums, const string str) {
        int r=nums.top();  //save 1st nums top to r
        nums.pop();        //pop off r
        int l=nums.top();  //save 2nd nums top to l
        nums.pop();        //pop off l
        int result = l / r;  //do l / r and save the difference as result
        nums.push(result); //push result unto the num stack
    }
    
    //PreCondition: Argument must be a stack of positive numbers and input string.
    //PostCondition: Pops the last two numbers in the number stack and pushes their exponent unto the stack.
    void exponent(stack<int>& nums, const string str) {
        int r=nums.top();  //save 1st nums top to r
        nums.pop();        //pop off r
        int l=nums.top();  //save 2nd nums top to l
        nums.pop();        //pop off l
        int result = pow(l, r);  //do l - r and save the difference as result
        nums.push(result); //push result unto the num stack
    }
    
    //PreCondition: Argument is of char data type, ranging from '0' to '9'.
    //PostCondition: Returs a number of integer type.
    int CharToInt(const char c) {
        switch (c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
        }
    }
};
