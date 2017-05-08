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
 void Delete(int pos){
		if(it<=0 || it>cnt){
			cout<<"Element doesn't exist"<<endl;
			return NULL;
		}
		curr=head;
		for(int i=0;i<pos;i++)
			curr=curr->next;
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
 //选择排序
 void sort(){
	Link<E> *findlow;
	curr=head;
	int low,lownum;
	for(int i=0;i<cnt-1;i++){
		low=curr->next->element;
		findlow=curr->next;
		for(int j=i+1;j<cnt;j++){
			if(findlow->next->element<low){
				low=findlow->next->element;
				lownum=j;					
			}
			findlow=findlow->next;
		}
	
		findlow=curr;
		for(j=i;j<lownum;j++)
			findlow=findlow->next;
		swap(curr->next->element,findlow->next->element);
		curr=curr->next;
	}
 }
};
 
 int main(){
	LList<int> order;
	order.insert(1);
	order.insert(2);
	order.insert(3);
	order.insert(4);
	order.insert(5);
	order.display();
	order.sort();
	order.display();
	return 0;
 }
