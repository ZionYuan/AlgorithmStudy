#include<iostream>
#include <iomanip>
using namespace std;
const int COUNT = 6;//设置常量为6
void matrixChain(int p[ ], int m[ ][COUNT], int s[ ][COUNT] ) {
	int n=COUNT-1;
	for (int i = 1; i <= n; i++) m[i][i] = 0; //初始化对角线
	for (int r = 2; r <= n; r++){
		for (int i = 1; i <= n - r+1; i++) {
			int j=i+r-1;
			m[i][j] = m[i+1][j]+ p[i-1]*p[i]*p[j]; //计算次对角线
			s[i][j] = i;
			for (int k = i+1; k < j; k++) {
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (t < m[i][j]) { 
					m[i][j] = t; s[i][j] = k;
				}
			}
		} 
	}
	for(int i = 0;i<COUNT;i++){
		for(int j = 0;j<COUNT;j++){
			if(i>=j){
				m[i][j]=0;//初始化左半边为0
			}
			if(i==0){
				m[i][j]=0;
			}
			cout<<setw(7)<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0;i<COUNT;i++){
		for(int j = 0;j<COUNT;j++){
			if(i>=j){
				s[i][j]=0;
			}
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0;i<COUNT;i++){
		for(int j = 0;j<COUNT;j++){

		}
	}
}
void AddBrackets(int i,int j,int s[][COUNT]) {//添加括号
     if(i == j){          
     	cout<<"A"<<i;     
 	 }      
     else if(i+1 == j){ 
              cout<<"(A"<<i<<"A"<<j<<")";     
          }
     else{
     	cout<<"(";
        AddBrackets(i,s[i][j],s);         
        AddBrackets(s[i][j]+1,j,s);         
        cout<<")";     
     } 
     
} 
int main(){
	int p[] = {2,3,6,4,2,7};
	int m[COUNT][COUNT];
	int s[COUNT][COUNT];
	matrixChain(p,m,s);
	AddBrackets(1,COUNT-1,s);
	cout<<endl;
}