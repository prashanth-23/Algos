# define WHITE 0
# define BLACK 1
# define GREY 2
#include<iostream>
using namespace std;
int TIME;
struct graphVertex;
struct graphArc
  {
	graphVertex *destination;
	graphArc *nextArc;
  };
struct graphVertex
  {
	char data;
    int color;
    int distance;
	graphVertex *nextVertex;
    graphVertex *parent;
	graphArc *firstArc;
  };
struct HEAD
  {
	graphVertex *first;
	int count;
  };	
struct node
  {
	graphVertex *dataptr;
	node *link;
  };
struct queuehead
  {
	int scount;
	node *front;
	node *rear;
  };
  
class queue
  {
	
	public:
    queuehead *sh;
	queue()
	{
		sh = new queuehead;
		sh->scount = 0;
		sh->front = NULL;
		sh->rear = NULL;
	}
	void display()
	{
		node *newnode = sh->front;
		while(newnode != NULL)
		{
			cout<<newnode->dataptr->data<<"->";
			newnode = newnode->link;
		}
	}
	void enqueue(graphVertex *gv)
	{
		++(sh->scount);
		node *newnode = new node;
		newnode->dataptr = gv;
		newnode->link = NULL;
		if(sh->scount == 1)
		{
			sh->front = newnode;
			sh->rear = newnode;
		}
		else
		{
			sh->rear->link = newnode;
			sh->rear = newnode;
		}
	}
	graphVertex* dequeue()
	{
		--(sh->scount);
		graphVertex *tmp = new graphVertex;
		tmp = sh->front->dataptr;
		if(sh->scount == 0)
		{
		sh->front = NULL;
		sh->rear = NULL;
		}
		else
		{
		sh->front = sh->front->link;
		}
		return tmp;
	}
	bool emptyqueue()
	{
		if(sh->scount == 0)
			return true;
		else
			return false;
	}
};
class Graph
  {
	public:
	HEAD *h;
	void createGraph()
	{
	    h = new HEAD;
	    h->first = NULL;
	    h->count = 0;
	}
	bool emptygraph()
	{
		if(h->count == 0)
			return true;
		else
			return false;
	}
	void insertVertex(char datain)
	{	
	    graphVertex *newvertex = new graphVertex;
    	newvertex->data = datain;
	    newvertex->color = WHITE;
    	newvertex->distance = 999999;
        newvertex->parent = NULL;
	    newvertex->nextVertex = NULL;
	    newvertex->firstArc = NULL;
	    ++(h->count);
	    if(h->first == NULL)
	    	h->first = newvertex;
	    else
	    {
	      graphVertex *t = h->first;
	      while(t->nextVertex != NULL)
	      t = t->nextVertex;
	      t->nextVertex = newvertex;
	    }
	}
	int insertArc(char fromkey, char tokey)
	{
		graphArc *newarc = new graphArc;
		graphVertex *fromvertex = new graphVertex;
		graphVertex *tovertex = new graphVertex;
		fromvertex = search(fromkey);
		if(fromvertex == NULL)
			return -2;
		tovertex = search(tokey);
		if(tovertex == NULL)
			return -3;
		newarc->destination = tovertex;
		newarc->nextArc = NULL;
		if(fromvertex->firstArc == NULL)
		{ 
		  fromvertex->firstArc = newarc;
		  return 1;
		}
		else
		{
		  graphArc *t = fromvertex->firstArc;
		  while(t->nextArc != NULL)
	 	  	t = t->nextArc;
	 	  t->nextArc = newarc;
		  return 2;
		}
	}
	void display()
	{
	graphArc *y = new graphArc;
	graphVertex *f = h->first;
	while(f != NULL)
	{
		cout<<f->data<<" ->";
		y = f->firstArc;
		while(y != NULL)
		{
			cout<<y->destination->data<<"->";
			y = y->nextArc;
		}
		cout<<endl;
		f = f->nextVertex;
	}
	}
	graphVertex* search(char ch)
	{
		graphVertex *t = h->first;
		while(t != NULL)
		  {	
			if(t->data == ch)
				break;
			t = t->nextVertex;
		  }
			return t;
	}
	int BFS(char source_data)
	{
        if (emptygraph())
			return -1;
        graphVertex *source_vertex = search(source_data);
		source_vertex->color = GREY;
        source_vertex->distance = 0;
        queue bfs_queue;
        bfs_queue.enqueue(source_vertex);
        while (!bfs_queue.emptyqueue())
        {
            graphVertex *popped_vertex = bfs_queue.dequeue();
            cout<<popped_vertex->data<<"-";
            graphArc *runner_arc = popped_vertex->firstArc;
            while(runner_arc != NULL)
            {
                if (runner_arc->destination->color == WHITE)
                    {
                        runner_arc->destination->color = GREY;
                        runner_arc->destination->parent = popped_vertex;
                        runner_arc->destination->distance = popped_vertex->distance + 1;
                        bfs_queue.enqueue(runner_arc->destination);
                    }
                runner_arc = runner_arc->nextArc;
            }
            popped_vertex->color = BLACK;
        }
		return 0;
	}
    void bfs_path(char source_data, char target_data)
    {
        graphVertex *source_vertex = search(source_data);
        graphVertex *target_vertex = search(target_data);
        if (source_data == target_data)
            cout<<endl<<"------The path is ";
        else if (target_vertex->parent == NULL)
            cout<<"No Path";
        else
            bfs_path(source_data, target_vertex->parent->data);
            cout<<target_data<<"-";        
    }
};	
int main()
{
	Graph p;
	int n, m, l;
	p.createGraph();
	cout<<"enter no of vertices:\n";
	cin>>m;
	char key = 'A';
	for (int i = 0; i < m; i++, key++)
	{
	p.insertVertex(key);
	}
	cout<<"enter no of edges:\n";
	cin>>n;
	for(int i = 0; i < n; i++)
	{
	char x, y;
	cout<<"enter"<<i+1<<"edge's from and to keys\n";
	cin>>x>>y;
	l = p.insertArc(x,y);
	cout<<i+1<<"'s result"<<l<<"   "<<endl;
	}
	p.display();
    char source_data, target_data;
	cout<<"enter source and target character data"<<endl;
    cin>>source_data>>target_data;
    p.BFS(source_data);
    p.bfs_path(source_data, target_data);
	cout<<endl;
}
	