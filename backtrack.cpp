#include<iostream>
#include<math.h>
using namespace std;

const int n = 5;
int x[5];
void swap(int&x,int&y){
	int t = x;
	x=y;
	y=t;
}
void backtrack1(int t){
	if(t>=n){
		for(int i = 0;i<n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}else{
		for(int i = 0;i<=1;i++){
			x[t] = i;
			backtrack1(t+1);
		}
	}
}
void backtrack2(int t){
	if(t>=n){
		for(int i = 0;i<n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}else{
		for(int i = t;i<n;i++){
			swap(x[t],x[i]);
			cout<<"before   t:"<<t<<"   x[i]:"<<i<<endl;
			backtrack2(t+1);
			cout<<"after    t:"<<t<<"   x[i]:"<<i<<endl;
			swap(x[t],x[i]);
		}
	}
}
void backtrack3(){
	int i = 0;
	int t = 0;
	while(t<pow(2,5)){
		while(i<n-1) {
			x[i] = 1;
			i++;
		    /* code */
		}
		if(i>=n-1){
			x[i]=1;
			for(int j = 0;j<n;j++){
				cout<<x[j]<<" ";
			}
			cout<<endl;
			x[i]=0;
		}else{
			//
		}
		t++;

	}
}
int main(int argc, char const *argv[])
{
	backtrack3();
	return 0;
}