#include<iostream>
using namespace std;
template <typename E>
class Link{
	public:
	E element;
	Link *next;
	Link(const E &elemval,Link *nextval=NULL){
		element=elemval;
		next=nextval;
	}
	Link(Link *nextval=NULL){next=nextval;}
};
template <typename E>
class LList{
private:
	Link<E> *head;
	Link<E> *tail;
	Link<E> *curr;
	int cnt;
	void create(){
		curr=tail=head=new Link<E>;
		cnt=0;
	}
	void removeall(){
		while(head!=NULL){
			curr=head;
			head=head->next;
			delete curr;
		}
	}
public:
	LList(){ create();}
	~LList(){removeall();}
 //求长度
	int length() const{ return cnt;}
 //取表中第i个结点值
	const E &get(int pos) const{
		if(it<=0 || it>cnt){
			cout<<"Element doesn't exist"<<endl;
			return NULL;
		}
		curr=head;
		for(int i=0;i<pos;i++)
			curr=curr->next;
		return curr->next;
	}
 //按值查找元素的位置
	int locate(const E &it){
		curr=head;
		for(int i=0;i<cnt;i++){
			if(curr->next==it);
				return i+1;
			 curr=curr->next;
		}
	cout<<"Element doesn't exist"<<endl;
	return NULL;
 }
 //插入节点
	void insert(const E &it){
		curr->next=new Link<E>(it,curr->next);
		if(tail==curr)
			tail=curr->next;
		cnt++;
	}
 //删除结点
 void Delete(){
		Link<E> *temp=curr->next;
		if(tail==curr->next)
			tail=curr;
		curr->next=curr->next->next;
		delete temp;
		cnt--;
 }
 //显示表
 void display(){
	 curr=head;
	 for(int i=0;i<cnt;i++){
		 cout<<curr->next->element<<" ";
		 curr=curr->next;
	 }
	 cout<<endl;
 }
//找大王
 int findking(int m){
	 int count=1;
	 curr=head;
	 //剩下猴子大于1继续寻找
	 while(length()>1){
		 //淘汰第m个猴子
		 if(count==m){
			Delete();
			count=0;
			if(curr==tail)
				curr=head;
		 }
		 else{
			if(curr->next==tail)
				 curr=head;
			else
				curr=curr->next;
		 }
		count++;
	 }
	 return curr->next->element;
 }
};
 
 int main(){
	 int n,m;
	 cout<<"请输入猴子个数：";cin>>n;
	 cout<<"请输入报数m：";cin>>m;
	LList<int> monkey;
	for(int i=n;i>0;i--)
		monkey.insert(i);
	cout<<monkey.findking(m)<<endl;
	return 0;
 }
