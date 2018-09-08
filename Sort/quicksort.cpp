#include<iostream>
using namespace std;

void swap(int&x,int&y){
	int tmp;
	tmp=x;
	x=y;
	y=tmp;
}
int partition(int array[],int ll,int hh){
	int key = array[hh];
	int i = ll-1;
	for(int j=ll;j<hh;j++){
		if(array[j]<=key){
			i++;
			swap(array[i],array[j]);
		}
	}
	swap(array[i+1],array[hh]);
	return i+1;
}
void quicksort(int array[],int low,int high){
	if(low<high){
		int mid = partition(array,low,high);
		for(int i = 0;i<=8;i++){
		cout<<array[i]<<" ";
		}
		cout<<endl;
		quicksort(array,low,mid-1);
		quicksort(array,mid+1,high);
	}
	
}

int main(int argc, char const *argv[])
{

	int array[] = {4,5,2,3,8,7,9,1,0};
	quicksort(array,0,8);
	for(int i = 0;i<=8;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}