#include<iostream>
#include<vector>
using namespace std;

void swap(int&a,int&b){
	int tmp = b;
	b=a;
	a=tmp;
}
void SelectSort(vector<int> & v){
	int min=0;;
	for(int i = 0;i<v.size();i++){
		min = i;
		for(int j = i+1;j<v.size();j++){
			if(v[j]<v[min]) min = j;
		}
		if(min!=i) swap(v[min],v[i]);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	v.push_back(2);
	SelectSort(v);
	for(int i = 0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}