#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (size_t i = 0; i < s.length(); ++i){
            char ch = s[i];
            if(ch=='('|| ch =='['|| ch == '{'){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                st.pop();
                if(ch==')'&& top != '(') return false;
                if(ch==']'&& top != '[') return false;
                if(ch=='}'&& top != '{') return false;
                
            }

        }
        return st.empty();

    }
};

// Example usage
int main() {
    Solution sol;
    string test = "()[]}";
    cout << (sol.isValid(test) ? "Valid" : "Invalid") << endl;
    return 0;
}