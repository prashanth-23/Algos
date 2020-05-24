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
    int start;
    int end;
	graphVertex *nextVertex;
    graphVertex *parent;
	graphArc *firstArc;
  };
struct HEAD
  {
	graphVertex *first;
	int count;
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
    	newvertex->start = 0;
        newvertex->end = 0;
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
    void DFS_visit(graphVertex *runner)
    {
        TIME = TIME + 1;
        runner->start = TIME;
        runner->color = GREY;
        graphArc *runner_arc = runner->firstArc;
        while(runner_arc != NULL)
        {
            if(runner_arc->destination->color == WHITE)
                {
                    runner_arc->destination->parent = runner;
                    DFS_visit(runner_arc->destination);
                }
            runner_arc = runner_arc->nextArc;
        }
        TIME = TIME + 1;
        runner->end = TIME;
        cout<<runner->data<<"-"<<runner->start<<"-"<<runner->end<<endl;
        runner->color = BLACK;
    }
	int DFS()
	{
		if (emptygraph())
			return -1;
		TIME = 0;
        graphVertex *runner = h->first;
        while(runner != NULL)
        {
            if(runner->color == WHITE)
                DFS_visit(runner);
            runner = runner->nextVertex;
        }
		return 0;
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
	p.DFS();
	cout<<endl;
}
	