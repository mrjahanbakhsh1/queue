// implementation of queue
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Queue
{
    int  *a;
	int  front;
	int  rear;
	int  size;
    unsigned capacity;
};

struct Queue* create(unsigned c)
{
    struct Queue* q ;
    q = (struct Queue*) malloc(sizeof(struct Queue));
    
	q->capacity     = c;
    q->front = 0;
    q->rear  = c - 1;  
   	q->size  = 0; 
    q->a = (int*) malloc(q->capacity * 4);
    
	return q;
}

int isEmpty(struct Queue* q)
{  
  return (q->size == 0); 
}

int isFull(struct Queue* q)
{ 
  return (q->size == q->capacity);  
}

void add(struct Queue* q, int item)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->capacity;
    int i;
    i=q->rear;
    q->a[i] = item;
    q->size = q->size + 1;
    cout<<"added : " << item <<endl;
}

void deleted(struct Queue* q)
{
    if (isEmpty(q)){
        cout << "Empty";
    }

    int item,i;
	i=q->front;
	item = q->a[i];
    
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    
    cout <<"deleted : " << item << endl;
}

int main()
{
    struct Queue *q;
    
    q=create(5);
    
    add(q,52);
    add(q,9);
    add(q,150);
    add(q,45);
    add(q,15);
    add(q,542);
    
    cout<<"_________________________" << endl;
    cout<<"front=" << q->front << endl;
    cout<<"rear=" << q->rear << endl;
    cout<<"size=" << q->size << endl;
    cout<<"_________________________" << endl;

    deleted(q);
    deleted(q);
    deleted(q);
    
    cout<<"_________________________" << endl;
    cout<<"front=" << q->front << endl;
    cout<<"rear=" << q->rear << endl;
    cout<<"size=" << q->size << endl;
    cout<<"_________________________" << endl;
    
    getch();
}
