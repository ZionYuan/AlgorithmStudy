#include<iostream>
#include<iomanip>
using namespace std;
const int N = 5;
const int M = 11;
int min(int x,int y){
    if(x>=y){
        return y;
    }else{
        return x;
    }
}
int max(int x,int y){
    if(x>=y){
        return x;
    }else{
        return y;
    }
}
void knapsack(int w[],int v[],int m[][M],int c){
    int n = N-1;
    int jMax = min(w[n]-1,c);
    //判断c和w[n]-1的大小，若c小则m[n][j]全部为0，因为不能装
    //反之，则以w[n]为分界线，j<=w[n],m[n][j]=0;j>w[n],m[n][j]=v[n]
    for(int j = 0;j <= jMax;j++){
        m[n][j] = 0;
    }
    for(int j = w[n];j <= c;j++){
        m[n][j] = v[n];
    }
    //自顶向下依次赋值
    for(int i = n-1;i > 1;i--){
        jMax = min(w[i]-1,c);
        for(int j = 0;j <= jMax;j++){
            m[i][j] = m[i+1][j];
        }
        for(int j = w[i];j <= c;j++){
            m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
        }
    }
    //为m[1][c]赋值
    m[1][c] = m[2][c];
    if(w[1]<=c){
        m[1][c] = max(m[2][c],m[2][c-w[1]]+v[1]);
    }
//    for(int i = 0;i<N;i++){
//        for(int j =0;j<M;j++){
//            cout<<setw(2)<<m[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<"最多价值为:"<<m[1][c]<<endl;



}
void traceback( int m[ ][M], int w[ ], int c, int x[ ],int v[]){
    int n=N-1;
    int sumv = m[1][c];
    for(int i=1; i<n; i++){
        if (m[i][c]==m[i+1][c])//此时，没有装包
            x[i]=0;
        else {//装包，记录
            x[i]=1;
            c-=w[i];
        }
        x[n]=(m[n][c]>0)? 1:0;
    }
    cout<<"拿取方式为："<<endl;
    int sumw=0;
    for(int p = 1 ;p <= n;p++){
        if(x[p]==1){
            cout<<"拿取"<<p<<" "<<"价值:"<<v[p]<<"  体积:"<<w[p]<<endl;
            sumw+=w[p];
        }
    }
    cout<<"总价值:"<<sumv<<" 总体积:"<<sumw<<endl;

    // for(int i = 0;i<N;i++){
    //     for(int j =0;j<M;j++){
    //         cout<<setw(2)<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}

int main(){
    int m[N][M];
    for(int i = 0;i<N;i++){
        for(int j =0;j<M;j++){
            m[i][j] = 0;
        }
    }
    int w[N] = {0,2,3,5,6};
    int v[N] = {0,3,4,5,7};
    int c = 11;
    int x[N];
    x[0]=0;
    knapsack(w,v,m,c);
    traceback(m,w,c,x,v);

}