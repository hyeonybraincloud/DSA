#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    stack<char> st;
    
    for (char ch : s) {
        if (ch == '(') {
            st.push(ch);
        }
        else {
            if (st.empty())
                return false;
            
            st.pop();
        }
    }
    
    return st.empty();
}