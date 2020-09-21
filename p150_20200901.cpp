class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (auto token:tokens)
        {
            if (token=="+")
            {
                int n = stack.back();
                stack.pop_back();
                stack.back() = stack.back()+n;
            }
            else if (token=="-")
            {
                int n = stack.back();
                stack.pop_back();
                stack.back() = stack.back()-n;
            }
            else if (token=="*")
            {
                int n = stack.back();
                stack.pop_back();
                stack.back() = stack.back()*n;
            }
            else if (token=="/")
            {
                int n = stack.back();
                stack.pop_back();
                stack.back() = stack.back()/n;
            }
            else
            {
                int b_sign = 1;
                int i=0;
                if (token[0]=='-') {i++;b_sign = -1;}
                int res = 0;
                while(i<token.size())
                    res = res*10 + (token[i++]-'0');
                stack.push_back(res*b_sign);
            }
        }
        return(stack.back());
    }
};