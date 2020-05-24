#include<iostream>
using namespace std;
struct Edge
{
    char source;
    char dest;
    int weight;     //weight of the edge
};
class Disjset
{
    public:
    int *rank;
    char *parent;
    char *data_in_set;
    Disjset()
    {
        rank = 0;
        parent = NULL;
        data_in_set = NULL;
    }
    Disjset(int sets_count)
    {
        rank = new int[sets_count];
        parent = new char[sets_count];
        data_in_set = new char[sets_count];
    }
};
class Graph
{
    public:
    int vertex_count;          //no of vertices
    int edge_count;          //no of edges
    Edge *edges;
    Disjset sets;
    Graph()
    {
        this->edge_count = 0;
        this->vertex_count = 0;
        edges = NULL;
        sets = Disjset();
    }    
    Graph(int edge_count, int vertex_count) 
    {
        this->edge_count = edge_count;
        this->vertex_count = vertex_count;
        edges = new Edge[edge_count];
        sets = Disjset(vertex_count);
    }
    void create_set()
    {
        cout<<"enter vertices data\n";
        for(int i = 0; i < vertex_count; i++)
            cin>>sets.data_in_set[i];
        cout<<"Enter the edge's source, destination and weight : \n";
        for(int i = 0; i < edge_count; i++)
            cin>>edges[i].source>>edges[i].dest>>edges[i].weight;
    }
    void make_set()
    {
        for(int i = 0; i < vertex_count; i++)
        sets.parent[i] = sets.data_in_set[i];
    }
    int search_index(char search_char)
    {
        int index_of_search_char = 0;
        for(int i = 0; i < vertex_count; i++)
        {
            if(sets.data_in_set[i] == search_char)
                index_of_search_char = i;
        }
        return index_of_search_char;
    }
    char find(char search_char)
    {
        if(sets.parent[search_index(search_char)] != search_char)
        {
            sets.parent[search_index(search_char)] = find(sets.parent[search_index(search_char)]);
        }
        return sets.parent[search_index(search_char)];
    }
    void set_union(char char_1, char char_2)
    {
        char char_1_rep = find(char_1); 
        char char_2_rep = find(char_2);

        if(char_1_rep == char_2_rep)
            return;
        if(sets.rank[search_index(char_1_rep)] < sets.rank[search_index(char_2_rep)])
            sets.parent[search_index(char_1_rep)] = sets.parent[search_index(char_2_rep)];
        else if(sets.rank[search_index(char_1_rep)] < sets.rank[search_index(char_2_rep)])
            sets.parent[search_index(char_1_rep)] = sets.parent[search_index(char_2_rep)];
        else
        {
            sets.parent[search_index(char_1_rep)] = sets.parent[search_index(char_2_rep)];
            sets.rank[search_index(char_2_rep)] = sets.rank[search_index(char_2_rep)] + 1;
        }
    }
};
int main()
{
    int edge_count, vertex_count;
    cout<<"Enter no of vertices and edges : \n";
    cin>>vertex_count>>edge_count;
    Graph graph(edge_count, vertex_count);
    graph.create_set();
    graph.make_set();
    for(int i = 0; i < graph.edge_count - 1; i++)
        {    
	        for(int j = 0; j < graph.edge_count - i - 1; j++)
            {    Edge temp;
	            if(graph.edges[j].weight > graph.edges[j + 1].weight)
	                {
                        temp = graph.edges[j];
	                    graph.edges[j] = graph.edges[j + 1];
	                    graph.edges[j + 1] = temp;	
            	   }
            }
        }
    cout<<"The included edges are : \n";
    for(int i = 0; i < graph.edge_count; i++)
    {
        if(graph.find(graph.edges[i].source) != graph.find(graph.edges[i].dest))
        {
            graph.set_union(graph.edges[i].source, graph.edges[i].dest);
            cout<<graph.edges[i].source<<"-"<<graph.edges[i].dest<<"-"<<graph.edges[i].weight<<endl;
        }
    }
}

