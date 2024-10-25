#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

using namespace std;
using ll = long long;

const int N = 102;

char stkIn[N]; 
int top, stkOut[N];
vector<int> outNums;
vector<char> output;
string input;

bool isNum(char c) { return '0' <= c && c <= '9'; }

int toInt(char c) { return static_cast<int>(c - '0'); }

char toChar(int n) { return static_cast<char>(n + '0'); }

int pre(int i) 
{
    while(output[i] == 'S') i --;
    return i;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> input;


    for(auto & i : input)
    {
        if (isNum(i)) output.push_back(i);
        else
        {
            // 处理括号 
            if(i == ')')
            {
                while(stkIn[top] != '(') output.push_back(stkIn[top --]);
                top --;
            }

            if (i == '^') stkIn[++ top] = i;

            if (i == '*' || i == '/') 
            {
                while (top && (stkIn[top] == '^' || stkIn[top] == '*' || stkIn[top] == '/'))
                    output.push_back(stkIn[top --]);
                stkIn[++ top] = i;
            }

            if (i == '+' || i == '-')
            {
                while (top && stkIn[top] != '(')
                    output.push_back(stkIn[top --]);
                stkIn[++ top] = i;
            }

            if(i == '(') stkIn[++ top] = i;
        }
    }
    while (top --) output.push_back(stkIn[top + 1]);

    for(auto &i : output)
        if(isNum(i)) outNums.push_back(toInt(i));
        else outNums.push_back(-INTMAX_MAX - 1);

    top = 0;
    while( output.size() - 1)
    {
        for(auto &i : output) cout << (i == 'S' ? : i) << ' ';
        cout << '\n';

        for(int i = 0; i < output.size(); ++ i)
        {
            if(isNum(output[i])) stkOut[++ top] = toInt(output[i]);
            else 
            {
                switch (output[i])
                {
                case '+': 
                    output[i] = output[pre(i)] = 'S'; 
                    output[pre(pre(i))] = toChar(toInt(output[pre(i)]) + toInt(output[pre(pre(i))]));
                    break;
                
                default:
                    break;
                }
            }
        }
    }        
        

    return 0;
}