#include <iostream>
#include <string>
#include <stack>
#include "brain.h"
//#include "calc.h"

//PreCondition: Number stack is of integer type
//PostCondition: Computes addition, subtraction, multiplication, division and exponent.
void brain(const string& str, stack<int>& nums) {
    Calc calculator; 
    bool done = false;

    if(!calculator.is_balanced(str)) {
        cout<<"\nParanthesis don`t match. Hit enter to continue: ";
        cin.clear();
        cin.ignore(123, '\n');
        string in = calculator.input();
        brain(in, nums);
    }else{
        for(int i=0; i<str.length() && calculator.is_balanced(str); i++) {
        if(isdigit(str[i])) {
            char c = str[i];
            int num = calculator.CharToInt(c); //convert char num to int num
            nums.push(num);         //push converted num unto nums stack
        }else if(str[i]=='+') {
            calculator.add(nums, str);
        }else if(str[i]=='-') {
            calculator.subtract(nums, str);
        }else if(str[i]=='*') {
            calculator.multiply(nums, str);
        }else if(str[i]=='/') {
            calculator.divide(nums, str);
        }else if(str[i]=='^') {
            calculator.exponent(nums, str);
        }
    }
    }
    cout<<"\nIt evaluates to: "<<nums.top()<<endl<<endl;
}
