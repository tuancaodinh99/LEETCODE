#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Mapping of closing brackets to opening brackets
        unordered_map <char,char> bracket_map ={            
                                                {')','('},  // first - second
                                                {'}','{'},  // close - open
                                                {']','['}
                                                        };
        stack <char> st;
        for (auto ch : s){
            if(bracket_map.find(ch) == bracket_map.end())  // Add open brackets to stack
            {
                st.push(ch);
            }
            else    // Process with clode brackets
            {
                // If there is no open bracket(it must be first position of string) -> false
                // Check if the open bracket on top of the stack matches the current close bracket.
                if(st.empty() || st.top() != bracket_map[ch])
                {
                    return false;
                }
                st.pop();   // Remove the top element of the stack
            }
        }
            return st.empty(); // The stack will be empty if the parenthesis is valid.
    }
};

int main()
{
    Solution sl;
    cout << boolalpha;
    cout << "isValid(\"()\") = " << sl.isValid("()") << endl;       // Result: true
    cout << "isValid(\"()[]{}\") = " << sl.isValid("()[]{}") << endl; // Result: true
    cout << "isValid(\"(]\") = " << sl.isValid("(]") << endl;       // Result: false
    cout << "isValid(\"([])\") = " << sl.isValid("([])") << endl;   // Result: true
    return 0;
}