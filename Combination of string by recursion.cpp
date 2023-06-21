//Design and implement a program for generating all possible combinations of given string using recursion.


#include <iostream>
#include <string.h>

using namespace std;

char temp[10];
void combination(char *str,int r,int index)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        temp[index]=str[i];     
        if(index==r-1)
        {
            cout<<"\t"<<temp;
        }
        else
            combination(str,r,index+1);
    }

}

int main()
{
    char str[45];
    cout<<"Enter the String:";
    cin>>str;

    for(int r=1;r<=strlen(str);r++)
    {
        combination(str,r,0);
    }

}

