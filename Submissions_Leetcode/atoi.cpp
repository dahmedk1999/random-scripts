#include <string>
#include <limits.h>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Solution {
public:
    int myAtoi(string s) {

        short sign=1;
        int index=0;
        short size=s.length();

        while(s[index]==' ' && index<size)
            index++;

        if(index < size && s[index]=='+'){sign=1;index++;}
        else if(index < size && s[index]=='-'){sign=-1;index++;}

        int res=0;
        int digit=0;
        while(index<size && (s[index]-'0'<=9 && s[index]-'0'>=0)){
            digit=s[index]-'0';

            if((res > INT_MAX/10)||(res == INT_MAX/10 && digit > INT_MAX % 10))
            {
                if(sign==1)return INT_MAX;
                return INT_MIN;
            }

            res= 10 * res + digit;
            index++;
        }
        return res*sign;
    }
};

int main()
{
    Solution test;
    cout<<test.myAtoi("99394 dasdasd ..")<<endl;
    cout<<test.myAtoi("ddddd aaa -+")<<endl;
    cout<<test.myAtoi("-+111")<<endl;
    cout<<test.myAtoi("-94 d+asdasd ..")<<endl;
}