class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>st;
        for(int i = 0 ;i<s.length(); i++){
            char ch = s[i];

            if( ch =='(')
            st.push(ch);
            else{
                //ch is closing brace
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
            //stack contain invalid expression
            int a = 0 , b=0;
            while(!st.empty()){
                if(st.top() == '('){
                    b++;
                }
                else{
                    a++;
                }
                st.pop();
            }
        
            int ans = a+b;
            return ans;
        }
    
    
};