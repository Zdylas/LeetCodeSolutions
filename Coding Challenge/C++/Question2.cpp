#include <bits/stdc++.h>

using namespace std;

int solution(string files) 
{
    map<char, int> count;
    for (char c : files) {
        counter[c]++;
    }
    int s = 0;
    int t = 0;
    for (auto p : count) {
        t += (p.second & ~1);
        if (p.second & 1 && !s) {
            s = 1;
        }
    }

    return t+s;
}


int main() {
     string files="";
     cin>>files;
     cout<<solution(files);
     return 0;
}
