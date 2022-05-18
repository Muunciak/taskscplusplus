#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

const int MAX=2147483647;
const int MIN=-2147483647;
int s=0;
struct listEl{
	listEl*next;
	int priority, data;
};

class priorityqueue{
	private:
		listEl*head;
		listEl*tail;
	public:
		priorityqueue();
		~priorityqueue();
		bool empty (void);
		int findmaxdata (void);
		int findmaxpriority(void);
		int findmindata (void);
		int findminpriority(void);
		void insert(int priority, int v);
		void insertmin (int priority, int v);
		void deletemax(void);
		void deletemin(void);
};
priorityqueue::priorityqueue(){
	head=tail=NULL;
}
priorityqueue::~priorityqueue(){
	while(head)deletemax();
}
bool priorityqueue::empty(void){
	return !head;
}
int priorityqueue::findmaxdata(void){
	if(head) 
	return head->data;
	else
	return MAX;
}
int priorityqueue::findmaxpriority(void){
	if(!head)
	return MAX;
	else
	return head->priority;
}
void priorityqueue::insert ( int priority, int v ){
	listEl*p,*r;
	p=new listEl;
	p->next=NULL;
	p->priority=priority;
	p->data=v;
	
	if(!head)
	head=tail=p;
	else
	if(head->priority<priority){
		p->next=head;
		head=p;
		}
		else{
			r=head;
			while((r->next)&&(r->next->priority >=priority))
			r=r->next;
			p->next=r->next;
			r->next=p;
			if(!p->next)
			tail=p;
			
		}
	}
void priorityqueue::deletemax(void){
	if(head){
		head=head->next;
		if(!head)
		tail=NULL;
	}
}
int priorityqueue::findmindata(void){
	if(head) 
	return head->data;
	else
	return MAX;
}
int priorityqueue::findminpriority(void){
	if(!head)
	return MAX;
	else
	return head->priority;
}
void priorityqueue::insertmin ( int priority, int v ){
	s=0;
	listEl*p,*r;
	p=new listEl;
	p->next=NULL;
	p->priority=priority;
	p->data=v;
	
	if(!head){
	head=tail=p;
	}
	else if(head->priority>=priority){
		p->next=head;
		head=p;
		s++;
		}
		else{
			r=head;
			while((r->next)&&(r->next->priority<priority)){
			r=r->next;
			s++;
		}
			p->next=r->next;
			r->next=p;
			s++;
			if(!p->next)
			tail=p;
			s++;
		}
		cout<<"How many compares in init: "<<s<<endl;
	}
void priorityqueue::deletemin(void){
	if(head){
		head=head->next;
		if(!head)
		tail=NULL;
	}
}
int main(int argc, char** argv) {
	priorityqueue Q;
	int i,p,v,j;
	srand(time(NULL));
	cout<<"Elements:prio"<<endl;
	for(i=1;i<=10;i++){
		v=i;
		p=rand()%100;
		cout<<v<<" | "<<p<<endl;
		Q.insert(p,v);
	}
	cout<<endl<<"Max:prio\n";
	while(!Q.empty()){
		cout<<Q.findmaxdata()<<"|"<<Q.findmaxpriority()<<endl;
		Q.deletemax();
		}
		cout<<"Elements:prio"<<endl;
	for(j=1;j<=10;j++){
		v=j;
		p=rand()%100;
		cout<<v<<" | "<<p<<endl;
		Q.insertmin(p,v);
	}
	cout<<endl<<"MIN:prio\n";
	while(!Q.empty()){
		cout<<Q.findmindata()<<"|"<<Q.findminpriority()<<endl;
		Q.deletemin();
		}
	return 0;
}
