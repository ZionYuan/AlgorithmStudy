

#include<iostream>
using namespace std;

#define LENGTH 10
void BinaryInsertSort(int A[]){
	int i,j;
	for(i = 2;i<LENGTH;i++){
		
		if(A[i]<A[i-1]){
			A[0] = A[i];		
			//先用二分查找,查找出所要插入的位置,再统一移动
			int low=1,high=i-1,mid;
			while(low<=high){
				mid=(low+high)/2;
				if(A[mid]<A[0])
					low = mid+1;
				else
					high=mid-1;
			}

			for(j = i-1;j>=high+1;--j)
				A[j+1]=A[j];
			A[high+1]=A[0];
		}
		
	}
}

int main(int argc, char const *argv[])
{
	int A[LENGTH]={-1,3,8,5,2,4,6,8,0,9};
	BinaryInsertSort(A);
	for(int i = 1;i<LENGTH;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
