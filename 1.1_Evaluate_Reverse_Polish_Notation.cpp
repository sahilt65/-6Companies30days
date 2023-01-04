/*
Link to the Question : https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;

        for(int i = 0; i<tokens.size(); i++){
            string s = tokens[i];
            if(s == "+" || s == "-" ||s == "/" ||s == "*" ){
                long op1 = st.top();
                st.pop();
                long op2 = st.top();
                st.pop();

                if(s=="+"){
                    op1 = op2 + op1;
                }
                if(s=="-"){
                    op1 = op2-op1;
                }
                if(s=="/"){
                    op1 = op2/op1;
                }
                if(s=="*"){
                    op1 = op2*op1;
                }

                st.push(op1);
            }else{
                st.push(stoi(s));
            }
        }

        return st.top();
        
    }
};