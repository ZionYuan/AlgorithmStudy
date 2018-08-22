#include<iostream>
#include<math.h>
using namespace std;

class Queen{
public:
	int n;//皇后个数
	int* x;//解向量
	int sum;//解的 个数
	bool place(int k);//限制条件，不能位于同一列，同一行，同一对角线
	void backtrack(int t);//回溯
	long nQueen(int nn);
};
long Queen::nQueen(int nn){
	n=nn;
	sum=0;
	x=new int[n+1];
	for(int i=0;i<=n;i++){
		x[i]=0;
	}//初始化
	backtrack(1);
	return sum;
}
bool Queen::place(int k){
	for(int j=1;j<k;j++){//不能位于同一行
		if ( (abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]) )//不能位于对角线和同一列
			return false;
	}
	return true;
}

void Queen::backtrack(int t){
	if(t>n) {//叶子结点
		//输出每一个解
		for(int i = 1;i<=n;i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
		sum++;//解个数++
	}
	else{
		for(int i = 1;i<=n;i++){//每一个皇后的位置都和前面的皇后有关，所以从1开始
			x[t]=i;
			if(place(t)) backtrack(t+1);
		}
	}
}
int main(int argc, char const *argv[])
{
	Queen q;
	cout<<q.nQueen(8);
	return 0;
}
