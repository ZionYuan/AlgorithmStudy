#include<iostream>
using namespace std;
const int n = 8;
int b[n];
void Merge(int a[],int low,int mid,int high){
	for(int i = low;i<=high;i++){
		b[i]=a[i];//先把 a 暂存到 b
	}
	int i,j,k;
	for(i = low, j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(b[i]<b[j]){
			a[k]=b[i];
			i++;
		}else{
			a[k]=b[j];
			j++;
		}
	}
	while(i<=mid) 	a[k++]=b[i++];
	while(j<high)   a[k++]=b[j++];
}

void MergeSort(int a[],int low,int high){
	if(low<high){
		int mid = (low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		Merge(a,low,mid,high);
	}
}
int main(int argc, char const *argv[])
{
	int a[]={3,2,54,6,3,1,3,5};
	MergeSort(a,0,n-1);
	for(int i = 0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}