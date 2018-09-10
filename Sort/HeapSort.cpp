#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b){
	int tmp = b;
	b=a;
	a=tmp;
}
void AdjustDown(vector<int>&v,int p,int len){
	int cur_parent_value = v[p];//存储当前的父节点
	int child = 2*p+1; //一定有左孩子,但不一定有右孩子;

	while(child<len){//p 所表示的父节点有孩子时进入循环
		if(child+1<len&&v[child+1]>v[child]){
			//如果有右孩子,并且右孩子大于左孩子,就取右孩子作为比较的
			//因为如果右孩子比左孩子小,即使有右孩子那么右孩子可有可无
			//只需要将父节点与其最大的孩子比较就行了
			//所以此处有两个条件
			child++;//孩子切换为右孩子
		}
		if(cur_parent_value<v[child]){//父节点小于子节点,不符合大根堆的定义
			//注意,这里是将cur_parent_value与v[child]比较,而不是将
			//v[p] 与 v[child]比较,是因为现在要调整的值为最初的
			//p所存储的值,一开始已经保存在cur_parent_value中了,而p
			//这个值是会一直往下迭代的, v[p]会变
			v[p] = v[child];

			p=child;
			child = 2*p+1;//p和 child 依次向下移动
		}else break;
	} 
	v[p] = cur_parent_value;
}
void BuildMaxHeap(vector<int>&v,int len){
	//从下至上, 
	//i的初始值表示完全二叉树的倒数第二层且有子节点的最后一个节点
	for(int i = len/2-1;i>=0;--i){
		AdjustDown(v,i,len);
	}
}
void HeapSort(vector<int>&v,int len){
	BuildMaxHeap(v,len);//初始化堆
	for(int i = len-1;i>=0;i--){
		swap(v[0],v[i]);//每次取出堆顶的数(最大值),放到堆底
		//然后将剩余的i个数重新排列
		AdjustDown(v,0,i);
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> v;
	v.push_back(53);
	v.push_back(17);
	v.push_back(78);
	v.push_back(9);
	v.push_back(45);
	v.push_back(65);
	v.push_back(87);
	v.push_back(32);
	int len = v.size();
	HeapSort(v,len);
	for(int i =0;i<len;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}