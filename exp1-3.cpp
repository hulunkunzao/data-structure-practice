#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

//输出1-n中素数的个数
int main(){
	int n,a[N];
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i =2;i<=n;++i){
		for(int j=i*2;j<=n;j+=i){
			a[j]=1;
		}
	}
	int cnt=0;
	for(int i = 2;i<=n;++i){
		if(a[i]==0){
			++cnt;
		}
	}
	cout << cnt << endl;
	cnt =0;
	for(int i = 2;i<=n;++i){
		int flag = true;
		for(int j=2;j<=sqrt(i);++j){
			if(i%j==0){
				flag=false;
				break;
			}
		}
		if(flag){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}