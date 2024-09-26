#include<bits/stdc++.h>
using namespace std;
//输出1！+2！+..+n! 的和，时间复杂度为O(n)
int main(){
	int n;
	cin >> n;
	int a[n+1]={1},sum=0;
	for(int i = 1;i <=n;++i){
		a[i]=a[i-1]*i;
		sum+=a[i];
	}
	cout << sum << endl;
	return 0;
}