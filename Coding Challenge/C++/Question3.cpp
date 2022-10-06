#include <bits/stdc++.h>
#include <cmath>

using namespace std;


int solution(int N, int M, int P[])
{
    int current_biggest = P[0];
    int biggest_difference = 0;
    for (int i = 1; i < N; i++) {
        if (current_biggest > P[i]) {
            biggest_difference = max(biggest_difference, current_biggest+P[i]);
            if (biggest_difference > M) {
                return 0;
            }
        } else {
            current_biggest = P[i];
        }
    }
    return 1;
}

int main() {
    int n,m;
    cin>>n>>m;
    int P[n];
    for(int i=0;i<n;i++){
        scanf("%d", &P[i]);
    }
	cout<<solution(n,m,P)<<endl;
	return 0;
}