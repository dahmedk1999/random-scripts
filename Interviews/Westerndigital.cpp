#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

bool palindrome(){
string inputS="madyam";
int size=inputS.length();
int ptr=size-1;
for(int i=0;i<size/2;i++)
{
    if(!(inputS[i]==inputS[ptr--]))
        {
            cout<<"Not a palindrome";
            return false;

        }
}
cout<<"Is a palindrome";
}



int fibbonacci(int f)
{
    vector<int> fibList;
    fibList.reserve(100);
    fibList.push_back(0);
    fibList.push_back(1);
    int nextSeq=0;

    for(int i =2;i<=f;i++)
    {
        nextSeq=fibList[i-1]+fibList[i-2];
        fibList.push_back(nextSeq);
    }
    for(auto x:fibList)cout<<x<<endl;
    return fibList.at(f);
}
string vowelremove(){
string Instring="This is a new sentence";
int s= Instring.length();
string vowels="aeiou";
cout<<Instring<<std::endl;
for(int i=0;i<s;i++)
{
    for(int k=0;k<vowels.length();k++)
    {
    if(Instring[i]==vowels[k])
        Instring[i]='-';
    else continue;
    }
}
cout<<Instring<<std::endl;
return Instring;
}
int main(){
    vowelremove();
    fibbonacci(9);
}
