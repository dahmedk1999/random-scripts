#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::string;
using std::vector;

/*
Difficulty: Hard
Acceptance Rate: 14%

A password is considered strong if the below conditions are all met:

It has at least 6 characters and at most 20 characters.
It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
It does not contain three repeating characters in a row (i.e., "...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.

In one step, you can:

Insert one character to password,
Delete one character from password, or
Replace one character of password with another character.
 
Example 1:

Input: password = "a"
Output: 5
Example 2:

Input: password = "aA1"
Output: 3
Example 3:

Input: password = "1337C0d3"
Output: 0
 
Constraints:
1 <= password.length <= 50
password consists of letters, digits, dot '.' or exclamation mark '!'.
*/
class Solution {
public:
    int strongPasswordChecker(string password) {
        short stepsReq=0;
        short Len=0,Rep=0,Req=0;
        short del=0;
        cout<<"Pwd: "<<password<<'\n';
        //Length check
        Len=checkLen(password,&del);
        //Repitition Check
        Rep=checkRep(password);
        //Requirements Check
        Req=checkReq(password);
        cout<<"Len: "<<Len<<" Rep: "<<Rep<<" Req: "<<Req<<'\n';
        stepsReq=Len+Req+Rep;
        if(Len > Rep && Len > Req){stepsReq= Len;}
        else if(Len > Req && Req > Rep)stepsReq= Len+Req-Rep;
        else if(Len > Rep && Req > Rep && del)stepsReq=Len+Req;
        else if(Req > Rep)stepsReq=Req;
        else if(Rep > Req)stepsReq=Rep;
        else if(Rep==1 && Req==1)stepsReq=1;

        cout<<"Steps needed to make password strong: "<<stepsReq<<"\n\n";
        return stepsReq;
    }
    int checkLen(string pwd,short *del)
    {
        short len = pwd.length();
        if (pwd.length() > 20)
        {
            cout << "Password Length " << pwd.length() - 20 << " char over limit\n";
            *del=1;
            return pwd.length() - 20;
        }
        if (pwd.length() < 6)
        {
            cout << "Password Length " << 6 - pwd.length() << " char under limit\n";

            return 6 - pwd.length();
        }
            return 0;
    }
    int checkRep(string pwd)
    {
        short isrepeating=0;
        short size=pwd.length();
        short read=0;
        short mod=0;
        for(short i=0;i<size-2;i++)
        {
            char state0=pwd[i+0];//cout<<state0;

            char state1=pwd[i+1];//cout<<state1;

            char state2=pwd[i+2];//cout<<state2<<'\n';

            if(state0 == state1 && state1 == state2)
            {   
                isrepeating++;
                i+=2;
                // cout<<"Change above sequence!"<<isrepeating<<'\n';
            }
        }
        if(size/3>=isrepeating)
        { 
        cout<<"Repeating chars to change: "<<isrepeating<<'\n';
        return isrepeating;
        }
        cout<<"Repeating chars to change: "<<size/3<<'\n';
        return size/3;

        /* 
        in aacaaaccc, isrepeating it would be two
        in aaaaaaaaa, isrepeating will be 7 but is actually 3. Size=9/3 =3
        in aaaaaaaaaa, isrepeating is 8 but is actually 10/3 =3.33 minimum 3 still
        */
    }
    int checkReq(string pwd)
    {
        //need lcc, ucc, d (. ! optional)
        short size=pwd.length();
        short lower=0,upper=0,digit=0;
        short stepsReq=0;
        for(short i=0;i<size;i++)
        {
            char currentChar=pwd[i];
            if(islower(currentChar))
                lower++;
            else if (isupper(currentChar))
                upper++;
            else if (isdigit(currentChar))
                digit++;
            
        }
        cout<<"lower"<<lower<<'\n';
        cout<<"upper"<<upper<<'\n';
        cout<<"digit"<<digit<<'\n';
        if(lower && upper && digit)//if there are at least 1 of each, return 0
            return 0;
        if(!lower)stepsReq++;
        if(!upper)stepsReq++;
        if(!digit)stepsReq++;
        return stepsReq;
    }
};
int main(){
    Solution test;
    test.strongPasswordChecker("ABABABABABABABABABAB1");
    test.strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc");
    test.strongPasswordChecker("ABABABABABABABABABAB1ABABA");
    test.strongPasswordChecker("aa123");
}
