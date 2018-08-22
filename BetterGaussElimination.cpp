#include<iostream>
using namespace std;
const int n = 3;//令n为常数3

// 交换函数
void swap(int i,int j){
	int tmp;
	tmp=j;
	j=i;
	i=tmp;

}
void SolveWithGauss(int a[n][n+1] )//传入参数为n行n+1列的矩阵，最后一列为方程的根的一维矩阵
{
	for(int i= 0;i<n-1;i++){
		int p = i;
		for(int j=i+1;j<n;j++){
			if(a[j][i]>a[p][i]) p=j;
		}
		for(int k=i;k<n+1;k++){
			swap(a[i][k],a[p][k]);
		}//防止当A[i][i]太小的情况，出现误差。
		for(int j=i+1;j<n;j++){
			int tmp = a[j][i]/a[i][i];
			for(int k = i;k<n+1;k++){
				a[j][k]=a[j][k]-a[i][k]*tmp;
			}
		}//通过tmp防止新旧值混用
	}
	int x[n];//求解x[n]
	x[n-1]=a[n-1][n]/a[n-1][n-1];//先求出x[n-1]，因为可直接求出
	for(int i = n-2;i>=0;i--){
		int sum = 0;
		for(int j = i+1;j<n;j++){
			sum = a[i][j] * x[j] + sum;
		}
		x[i] = (a[i][n]-sum)/a[i][i];//通过回代，分别求出其他x
	}
	for(int i = 0;i<n;i++){
		cout<<x[i]<<" "<<endl;
	}
}
int main(){
	int a[3][4]={{1,1,1,2},{2,1,1,3},{1,-1,3,8}};
	SolveWithGauss(a);

}