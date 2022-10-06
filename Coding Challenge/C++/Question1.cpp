#include<bits/stdc++.h>

using namespace std; 

string solution(long num)
{
    if (num & 1) {
        return "SELL";
    }
    if (num >> 2 & 1) {
        return "BUY";
    }
    return "PASS";
}

/*  Do not edit below code */
int main()  
{
    long n;	cin >> n;
    string answer=solution(n);	
    cout << answer << endl; 
}
