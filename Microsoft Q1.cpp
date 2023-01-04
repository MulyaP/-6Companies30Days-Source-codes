class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i=0;i<tokens.size();i++){
            if (tokens[i][0]=='-' && tokens[i].length()>1){
                s.push(stoi(tokens[i]));
                continue;
            }
            if (tokens[i][0]>=48 && tokens[i][0]<=57){
                s.push(stoi(tokens[i]));
                continue;
            }
            else{
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                switch(tokens[i][0]){
                    case '+':
                        s.push(op2+op1);
                        break;
                    case '-':
                        s.push(op2-op1);
                        break;
                    case '*':
                        s.push(op2*op1);
                        break;
                    case '/':
                        s.push(op2/op1);
                        break;
                }
            }
        }
        return s.top();
    }
};
