class Solution {
public:
bool solve(char op, vector<char>values){
    if(op=='!')return values[0]=='f';

    if(op=='|'){
        for(char c:values){
            if(c=='t')return true;
        }
        return false;
    }

    for(char c:values){
        if(c=='f')return false;
    }
    return true;
}
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for(char c:expression){
            if(c == ')'){
                vector<char>values;

                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }

                st.pop();
                char operand = st.top();
                st.pop();

                st.push(solve(operand,values)?'t':'f');
            }
            else if(c!=','){
                st.push(c);
            }
        }



        return st.top() == 't';
    }
};