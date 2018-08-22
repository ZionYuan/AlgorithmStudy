#include<iostream>
using namespace std;
const int n = 7;

void swap(int&a,int&b){
	int tmp;
	tmp = b;
	b = a;
	a = tmp;
}

//对数组c进行排序
void sort(int c[]){
	for(int j = 0;j< n;j++){
		for(int i = 1;i < n;i++){
			if(c[i]<c[i+1]){
				swap(c[i],c[i+1]);
			}
	    }
	}
	
}

//比较m1,m2,m3数组和，并返回和最小的数组
int*  SumOfArrayCmp(int m1[],int m2[],int m3[]){
	int sum1=0;
	int sum2=0;
	int sum3=0;
	for(int i = 0;i<=n;i++){
		sum1 = sum1 + m1[i];
		sum2 = sum2 + m2[i];
		sum3 = sum3 + m3[i];
	}
	int *arr[] = {m1,m2,m3};//建立指针数组，分别保存三个数组的首地址
	int a[] = {sum1,sum2,sum3};
	int min = a[0];
	int minnum = 0;
	for(int i = 0;i<2;i++){
		if(min>a[i+1]){
			min = a[i+1];
			minnum = i+1;
		}
	}
	return arr[minnum];
}
void Schedule(int c[]){
	int a[n+1];
	for(int i =0;i<n+1;i++){
		a[i]=c[i];
	}
	sort(c);

	//定义m1,m2,m3分别保存不同机器上任务所耗费的时间
	int m1[n+1];
	int m2[n+1];
	int m3[n+1];
	for(int i = 0;i <= n;i++){
		m1[i]=0;
		m2[i]=0;
		m3[i]=0;
	}
	for(int h = 0;h<=n;h++){
		SumOfArrayCmp(m1,m2,m3)[h]=c[h];//从0开始，数组和最小的添加任务
										//此时任务c已经进过排序，从大到小排列
										
	}

	cout<<"M1: ";
	for(int i = 1;i<=n;i++){
		if(m1[i]!=0){
			for(int j = 0;j<=n;j++){
				if(m1[i]==a[j]){
					cout<<j<<" ";
				}
			}
		}
	}
	cout<<endl;
	cout<<"M2: ";
	for(int i = 1;i<=n;i++){
		if(m2[i]!=0){
			for(int j = 0;j<=n;j++){
				if(m2[i]==a[j]){
					cout<<j<<" ";
				}
			}
		}
	}
	cout<<endl;
	cout<<"M3: ";
	for(int i = 1;i<=n;i++){
		if(m3[i]!=0){
			for(int j = 0;j<=n;j++){
				if(m3[i]==a[j]){
					cout<<j<<" ";
				}
			}
		}
	}
	cout<<endl;

}

int main(int argc, char const *argv[])
{
	int c[]={0,2,14,4,16,6,5,3};//各个作业的时间花费
	Schedule(c);
	return 0;
}