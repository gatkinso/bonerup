// Determine if string has balanced opening and closing parentheses
// ))((()() = unbalanced
//
// Extension of: <>,{},[],()

#include<iostream>
#include<string>
#include<stack>

using namespace std;

const char OPEN_PAREN = '(';
const char CLOSE_PAREN = ')';

// Test cases:
// ()
// ((********))

// **empty**
// (
// )(
// (()
// ()()

bool isStringBalancedAscii_1(const string& str) {
    if (str.length() < 2)
        return false;

    stack<char> stk;

    for (auto c: str) {
        switch (c) {
            case OPEN_PAREN:
                stk.push(c);
            break;
            case CLOSE_PAREN:
                if (stk.empty())
                    return false;
                else
                    stk.pop();
            break;
            default:
                continue;
        }
    }
    
    if (stk.empty())
        return true;

    return false;
}

void doTest(const string input) {
    if(true == isStringBalancedAscii_1(input)) {
        cout << input << " \t\tBALANCED" << endl;
    }
    else {
        cout << input << " \t\tUNBALANCED" << endl;
    }
}

int main(int argc, char* argv[]) {
    doTest("");
    doTest("()");
    doTest("(())");
    doTest("(a+(b/2))");

    doTest(")()");
    doTest("((");
    doTest("((())");
    doTest("This() is balanced, not)");
    
    return 0;
}