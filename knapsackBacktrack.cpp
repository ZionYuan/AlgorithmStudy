#include<iostream>
using namespace std;
class Knapsack{
public:
    int n;		//物品数
    double* w;	//每个物品的体积
    double c;	//背包体积
    double cw;	//当前体积
    double cp;	//当前价值
    double* p;	//每个物品价值
    int *x;		//存储每个物品是否装
    int *bestx;	//最优解
    double bestp;//最优价值

    double bound(int i);
    void backtrack(int i);
    void bestloading(double pp[],double ww[],double cc,int nn);
};
void Knapsack::bestloading(double pp[],double ww[],double cc,int nn){
    n = nn;
    w=ww;
    p=pp;
    x=new int[n+1];
    bestx = new int[n+1];
    for(int i =0;i<=n;i++){
        w[i]=ww[i];
        p[i]=pp[i];
    }
    c=cc;
    cw=0;
    cp=0;
    bestp=0;//初始化
    backtrack(1);
    for(int i = 0;i<=n;i++){
    	if(bestx[i]==1){
    		cout<<"第"<<i<<"个物品被装进"<<endl;
    	}
    }
    cout<<"最佳价值为"<<bestp<<endl;
   
}
double Knapsack::bound(int i){

    double cleft = c - cw; //剩余容量
    double bound = cp;//设定边界为当前的价值
    //以物品单位重量价值递减序装入物品
    while(i<=n&&w[i]<=cleft){//当物品未装完并且第i个物品体积小于剩余容量
        cleft -= w[i];//装第i个物品
        bound += p[i];//当前价值增加
        i++;
    }
    //
    if(i<=n) bound += p[i]/w[i]*cleft;//若未装完物品，
    //则边界为已装完的价值+以i物品的单位价值计算的剩余物品的总价值
    return bound;
}
void Knapsack::backtrack(int i){
    if(i>n){//叶节点
        if(cp>bestp){
        	bestp=cp;
        	for(int i = 0;i<=n;i++){
        		bestx[i]=x[i];
        	}
        }
    }
    else{
    	if (cw+w[i]<=c){//进入左子树
    	x[i]=1;
        cw+=w[i];
        cp+=p[i];
       // cout<<"第"<<i<<"层"<<cw<<" "<<cp<<endl;
        backtrack(i+1);
       // cout<<"第"<<i<<"层"<<cw<<" "<<cp<<endl;
        cw-=w[i];
        cp-=p[i];
    	}
	    if(Knapsack::bound(i+1)>=bestp){//进入右子树
	    	x[i]=0;
	    	//cout<<i<<"没装"<<endl;
	        backtrack(i+1);
	    }
    }
    
}
int main(){
    int n = 4;
    double w[] = {0,2,3,5,6};
    double p[] = {0,3,4,5,7};
    double c = 11;
    Knapsack k;
    k.bestloading(p,w,c,n);
    


}
