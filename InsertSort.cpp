#include<iostream>
using namespace std;

#define LENGTH 10
void InsertSort(int A[]){
	int i,j;
	//从2开始,是因为A[1]看做一个为长度为1的有序序列
	//并且A[0]作为"哨兵",存储当前准备插入的 A[i]的副本
	//与之比较,并且在移动后, A[i]更改了,仍然可以在 A[0]中
	//保存当前值
	for(i = 2;i<LENGTH;i++){
		//默认为升序,所以当前准备插入的元素比前一个元素小的话,说明需要插入到前面相应的位置
		if(A[i]<A[i-1]){
			A[0] = A[i];//保存副本
			//从后往前依次查找比 A[i]大的元素往后移
			for(j = i-1;A[0]<A[j];j--){
				A[j+1]=A[j];
			}
			//直到找到 A[i]应处的位置,并将其复制到插入位置
			A[j+1]=A[0];
		}
		
	}
}

int main(int argc, char const *argv[])
{
	int A[LENGTH]={-1,3,8,5,2,4,6,8,0,9};
	InsertSort(A);
	for(int i = 1;i<LENGTH;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}