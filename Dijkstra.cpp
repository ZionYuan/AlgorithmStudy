#include<iostream>
#include<set>
#include<stack>
using namespace std;
#define INFINITY  1000000000
int main(int argc, char const *argv[])
{
	//初始化
	int arcs[6][6]={{0,0,0,0,0,0},
					{0,0,10,INFINITY,INFINITY,5},
					{0,INFINITY,0,1,INFINITY,3},
					{0,INFINITY,INFINITY,0,4,INFINITY},
					{0,7,INFINITY,6,0,INFINITY},
					{0,INFINITY,3,9,2,0}};//简单起见,使用邻接矩阵表示图
	int dist[6];//源点1到各点的最短距离
	int path[6]={1,1,1,1,1,1};//源点1到各点的最短距离的前驱节点
	path[0]=0;
	dist[0]=0;
	set<int> U,V;//U 代表已经获得最短距离的点的集合, V 是另外的点的集合
	for(int i = 1;i<6;i++){
		V.insert(i);
	}
	U.insert(1);
	V.erase(1);	//将1放入 U

	for(int i =1;i<6;i++){
		dist[i] = arcs[1][i];
	}			
//算法开始
//(1)从顶点集合 U中选出j,满足 dist[j]=Min{dist[i]|i∈V},
//	 j就是当前求的一条从源点出发的最短路径的终点,令V=V∪{j}
//(2)若dist[j]+arcs[j][k]<dist[k],则修改长度,令
//dist[k] = dist[j]+arcs[j][k];
	while(U.size()!=5){
		set<int>::iterator it;
		it = V.begin(); 
		int j = *it;
		for(it=V.begin();it!=V.end();it++) {
			if(dist[j]>dist[*it]){
				j=*it;	
			}
		}
		U.insert(j);
		V.erase(j);

		for(it=V.begin();it!=V.end();it++){
			int k = *it;
			if(dist[j]+arcs[j][k]<dist[k]){
				dist[k] = dist[j]+arcs[j][k];
				path[k]=j;
			}

		}

	}

	//输出
	for(int i = 2;i<6;i++){
		cout<<"1到"<<i<<"的最短距离为"<<dist[i]<<endl;
	}
	int start;
	stack<int> routine;//利用栈存储路径
	for(int i = 2;i<6;i++){
		cout<<1<<"到"<<i<<"的最短路径为: ";
		start = i;
		routine.push(start);
		while(start!=1){
			routine.push(path[start]);
			start = path[start];
		}
		while(!routine.empty()){
			if(routine.size()==1){
				cout<<routine.top();
			}
			else cout<<routine.top()<<"->";
			routine.pop();
		}
		cout<<endl;
	}
	return 0;
}