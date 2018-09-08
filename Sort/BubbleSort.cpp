#include<iostream>
#include<vector>
using namespace std;

void swap(int&a,int&b){
	int tmp = b;
	b=a;
	a=tmp;
}
vector<int> BubbleSort(vector<int> v){
	for(int i = v.size();i >0;i--){
		bool flag = false;
		for(int j = 1;j<i;j++){
			if(v[j]<v[j-1]){
				swap(v[j],v[j-1]);
				flag = true;
			}
		}
		if(flag==false) return v ;
	}
	return v;
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(23);
	v.push_back(12);
	v.push_back(3);
	v.push_back(35);
	v.push_back(67);
	v.push_back(22);
	v.push_back(23);
	v.push_back(44);
	v.push_back(56);
	v = BubbleSort(v);
	for(int i : v){
		cout<<i<<" ";
	}
	return 0;
}