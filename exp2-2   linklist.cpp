#include<bits/stdc++.h>
using namespace std;
//上机实验2 实现单链表的各种基本操作
class ListNode{
public:
	char c;
	ListNode* next;
	ListNode(char s):c(s),next(nullptr){}
	ListNode():next(nullptr){}
};
class LinkList{
private:
	ListNode* head;
public:
	static int len;
	LinkList(): head(nullptr){
	}
//	void Init_LinkList():head(nullptr){
//	}
	void append(char s){
		if(head==nullptr){
			head=new ListNode(s);
		}else{
			ListNode* p = head;	
			while(p->next!=nullptr){
				p=p->next;
			}
			p->next=new ListNode(s);
		}
		++len;
	}
	void display(){
		if(!head)return;
		ListNode* p = head->next;
		while(p->next!=nullptr){
			cout << p->c << "->";
			p=p->next;
		}
		cout << p->c << endl;
	}
	int length(){
		ListNode* p = head;
		int cnt = 0;
		while(p!=nullptr){
			++cnt;
			p=p->next;
		}
		return cnt;
	}
	bool is_empty(){
		if(this->len==0){
			return false;
		}else{
			return true;
		}
	}
	char at(int index){
		ListNode* p = head;
		while(p!=nullptr&& index){
			p=p->next;
			--index;
		}
		if(p==nullptr){
			return 0;
		}else{
			return p->c;
		}
	}
	int search(char s){
		ListNode* p = head;
		int cnt = 0;
		while(p!=nullptr&&p->c!=s){
			p=p->next;
			++cnt;
		}
		if(p!=nullptr){
			return cnt;
		}
	}
	void insert(int index,char s){
		if(index<0||index>=this->len)return;
		ListNode* pre = head,* p = head->next;
		while(p!=nullptr&&index){
			--index;
			pre=p;
			p=p->next;
		}
		pre->next=new ListNode(s);
		pre->next->next=p;
		++len;
	}
	~LinkList(){
		ListNode* pre=head->next,*p=pre->next;
		delete(head);
		while(pre!=nullptr){
			delete(pre);
			pre=p;
			p=pre->next;
		}
		len=0;
	}
	void del_index(int index){
		if(index<0||index>=this->len)return;
		ListNode*pre=head,*p=head->next;
		while(index&&p!=nullptr){
			--index;
			pre=p;
			p=p->next;
		}
		pre->next=p->next;
		delete(p);
		--len;
	}
};
int LinkList::len=0;
int main(){
	LinkList p;
	p.append('a');
	p.append('b');
	p.append('c');
	p.append('d');
	p.append('e');
	p.display();
	cout << p.length() << endl;
	if(p.is_empty()) cout << "链表为空！"<<endl;
	else cout << "链表不为空！"<<endl;
	cout << p.at(2)<<endl;
	cout << p.search('a')<<endl;
	p.insert(3,'f');
	p.display();
	p.del_index(2);
	p.display();
	return 0;
}