#include<iostream>
using namespace std;
const int n = 3;
void swap(int i,int j){
	int tmp;
	tmp=j;
	j=i;
	i=tmp;

}
void SolveWithLU(int a[n][n],int b[n]){
	int L[n][n] ={{1,0,0},{0,1,0},{0,0,1}};//定义出初始L矩阵
	for(int i= 0;i<n-1;i++){
		int p = i;
		for(int j=i+1;j<n;j++){
			if(a[j][i]>a[p][i]) p=j;
		}
		for(int k=i;k<n;k++){
			swap(a[i][k],a[p][k]);
		}
		for(int j=i+1;j<n;j++){
			int tmp = a[j][i]/a[i][i];
			for(int k = i;k<n;k++){
				a[j][k]=a[j][k]-a[i][k]*tmp;
				if((j==1&&k==0)||(j==2&&k==1)||(j==2&&k==0)){
					L[j][k] = tmp;//将倍数放在相应位置，形成L矩阵
				}
				
			}
		}
	}//以上为求出下三角矩阵U
	int U[n][n];
	cout<<"L矩阵："<<endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<L[i][j]<<" ";
			U[i][j] = a[i][j];
		}
		cout<<endl;
	}
     cout<<endl;
     cout<<"U矩阵："<<endl;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}

	int y[n];//求出y向量，方法与求出x类似，只不过一个上三角，一个下三角
	y[0]=b[0]/L[0][0];
	for(int i = 1;i<n;i++){
		int sum = 0;
		for(int j = 0;j<i;j++){
			sum = sum + L[i][j]*y[j];
		}
		y[i]=(b[i]-sum)/L[i][i];
	}
	cout<<endl<<"解出y=：";
	for(int i = 0;i<n;i++){
		cout<<y[i]<<endl;
		
	}
	int x[n];
	x[n-1]=y[n-1]/U[n-1][n-1];
	for(int i = n-2;i>=0;i--){
		int sum = 0;
		for(int j = i+1;j<n;j++){
			sum = a[i][j] * x[j] + sum;
		}
		x[i] = (y[i]-sum)/a[i][i];
	}
	cout<<endl<<"解出x=："<<endl;
	for(int i = 0;i<n;i++){
		cout<<x[i]<<" "<<endl;
	}
}

int main(){
	int a[3][3] = {{1,1,1},{2,1,1},{1,-1,3}};
	int b[3] = {2,3,8};
	SolveWithLU(a,b);
}