#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

//Precondition: number part of input must be positive numbers and there must be space between each character
//Postcondition: returns a string
string input() { //input
    cout << "Make your entry: "; //ask for user input
    string str;                //declare str
    getline(cin, str);         //get user input n store it in str
    return str;
}

//add function
void add(stack<int>& nums, const string str) {
    int r = nums.top();  //save 1st nums top to r
    nums.pop();        //pop off r
    int l = nums.top();  //save 2nd nums top to l
    nums.pop();        //pop off l
    int result = l + r;  //add l to r and save sum a result
    nums.push(result); //push result unto the num stack
}

//subtract
void subtract(stack<int>& nums, const string str) {
    int r = nums.top();  //save 1st nums top to r
    nums.pop();        //pop off r
    int l = nums.top();  //save 2nd nums top to l
    nums.pop();        //pop off l
    int result = l - r;  //do l - r and save the difference as result
    nums.push(result); //push result unto the num stack
}

//multiply
void multiply(stack<int>& nums, const string str) {
    int r = nums.top();  //save 1st nums top to r
    nums.pop();        //pop off r
    int l = nums.top();  //save 2nd nums top to l
    nums.pop();        //pop off l
    int result = l * r;  //do l * r and save the difference as result
    nums.push(result); //push result unto the num stack
}
//divide function
void divide(stack<int>& nums, const string str) {
    int r = nums.top();  //save 1st nums top to r
    nums.pop();        //pop off r
    int l = nums.top();  //save 2nd nums top to l
    nums.pop();        //pop off l
    int result = l / r;  //do l / r and save the difference as result
    nums.push(result); //push result unto the num stack
}

//exponent function
void exponent(stack<int>& nums, const string str) {
    int r = nums.top();  //save 1st nums top to r
    nums.pop();        //pop off r
    int l = nums.top();  //save 2nd nums top to l
    nums.pop();        //pop off l
    int result = pow(l, r);  //do l - r and save the difference as result
    nums.push(result); //push result unto the num stack
}

//Function to check for balanced parenthesis
/*Postcondition: A true return value indicates the parenthesis in the given expression are balanced, else return value is false.
*/
bool is_balanced(const string& str) {
    const char left_par = '(';
    const char right_par = ')';
    stack<char> store; //stores the left parenthesis
    char next; //next charater from the string
    bool done = false; //becomes true if a needed par is not found
    for (int i = 0; !done && (i < str.length()); i++) {
        next = str[i];
        if (next == left_par) {
            store.push(next);
        }
        else if ((next == right_par) && (!store.empty())) {
            store.pop(); //pops the corresponding left par
        }
        else if ((next == right_par) && (store.empty())) {
            done = true;
        }
    }
    return (store.empty() && !done);
}

int CharToInt(const char c) {
    switch (c)
    {
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

int main() {
    //initialize a stack of double numbers
    stack<int> nums;
    string entry = input();
    if (is_balanced(entry)) {
        for (int i = 0; i < entry.length(); i++) {
            if (isdigit(entry[i])) {
                char c = entry[i];
                int num = CharToInt(c); //convert char num to int num
                nums.push(num);         //push converted num unto nums stack
            }
            else if (entry[i] == '+') {
                add(nums, entry);
            }
            else if (entry[i] == '-') {
                subtract(nums, entry);
            }
            else if (entry[i] == '*') {
                multiply(nums, entry);
            }
            else if (entry[i] == '/') {
                divide(nums, entry);
            }
            else if (entry[i] == '^') {
                exponent(nums, entry);
            }
        }
    }
    else {
        cout << "Paranthesis not balanced" << endl;
    }
    cout << nums.size() << " number remaining. \nAnswer :" << nums.top() << endl;
    //Input: 5 3 2 * + 4 - 5 +
    return 0;
}

