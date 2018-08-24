#include<iostream>
using namespace std;

void getNext(string T,int next[]){
	int i = 1;
	next[1] = 0;
	int j =0;
	while(i<=T.length()){
		if(j==0||T[i]==T[j]){
			++i;
			++j;
			next[i]=j;
		}else{
			j=next[j];
		}
	}

}
int Index(string S,string T){

	int next[T.length()];
	next[0]=-1;
	getNext(T,next); 

	for(int i =1;i<T.length();i++){
		cout<<next[i];
	}
	cout<<endl;
	int i = 1;
	int j = 1;
	while(i<S.length() && j<T.length()){
		if(j==0||S[i]==T[j]){		
			++i;
			++j;
			
		}else{
			j=next[j];
			
		}
	}
	if(j==T.length()){
		return i;
	}else{
		return -1;
	}
}


int main(){
	string S="#ababcabcacbab";
	string T="#cabcac";	
	
	int num = Index(S,T);
	if(num == -1){
		cout<<"找不到"<<endl;
		return 0;
	}else{
		for(int i = 1;i<S.length();i++){
			if(i==num-T.length()+1){
				cout<<"["<<S[i];
			}else if(i==num-1){
				cout<<S[i]<<"]";
			}
			else{cout<<S[i];}
			
		}
		cout<<endl;
		return 0;
	}
}