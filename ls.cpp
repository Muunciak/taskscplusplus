#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

int n;     

struct slistEl

{
  slistEl * next;
  int data;
};            
void  wych(slistEl** A, int n )
{
    slistEl* p;
    int s = 0, i;

    for (i = 0; i < n; i++) {
        s = 0;
        cout << "outgoing grade " << i << " : ";
        p = A[i];  
        while (p)         
        {
            s++;
          
            p = p->next;              
        }
        cout  << s;
        cout << endl;
    }
}
void wch(slistEl** A, int n)
{
    slistEl* p;
    int s;
    for (int j = 0; j < n; j++) {
        s = 0;
        cout << "ingoing grade " << j << " : ";
        for (int i = 0; i < n; i++) {
           
            p = A[i];
          while (p)          
          {
              if (p->data == j)
			  s++;			 
        p = p->next;        
          }    
        }
        cout<<s<<endl;
    }

}
int main( )
{
	int i, vs, ve, n, m,swych=0;
	slistEl ** A;  
	slistEl *p;	   
     
	
	setlocale(LC_CTYPE, "Polish");
	
	cout << "Enter the number of vertices and the number of neighbors:" << endl; 
	cin >> n >> m;
	A = new slistEl * [ n ];
	
	for( i = 0; i < n; i++ )
    	A [ i ] = NULL;
    
    for( i = 0; i < m; i++ )
    {
  		cout << "Enter neighbors by typing a start and end vertex:" << endl; 
    	cin >> vs >> ve;    
    	p = new slistEl;    
    	p->data = ve;     
    	p->next = A [ vs ]; 
    	A [ vs ] = p;
    }
  	for( i = 0; i < n; i++ ){
	  	cout << " neighbours " << i << ":";
	  	p=A[i]; 
      	while(p) 
    	{
    		cout<<p->data<<" ";
      		
      		p=p->next;
      		
    	}
    	cout<<endl;
	}
	cout<<endl;
	wych(A,n);
	wch(A,n);
	delete[] A;
	return 0;
}
 
