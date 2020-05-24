#include<iostream>
#include<cmath>
using namespace std;
int heap_size = 0;
struct vertex
{
    int key;
    char parent;
    char data;
};
struct Edge
{
    char source;
    char dest;
    int weight;
};
class Graph
{
    public:
    int vertex_count;
    int edge_count;
    vertex *vertices;
    Edge *edges;
    Graph()
    {
        vertex_count = 0;
        edge_count = 0;
        vertices = NULL;
        edges = NULL;
    }
    Graph(int vertex_count, int edge_count)
    {
        this->vertex_count = vertex_count;
        this->edge_count = edge_count;
        vertices = new vertex[vertex_count];
        edges = new Edge[edge_count];
    }
    void create_graph()
    {
        cout<<"enter vertices data \n";
        for(int i = 0; i < vertex_count; i++)
        {
            cin>>vertices[i].data;
            vertices[i].key = 999999;
            vertices[i].parent = '\0';
        }
        cout<<"Enter the edge's source, destination and weight : \n";
        for(int i = 0; i < edge_count; i++)
            cin>>edges[i].source>>edges[i].dest>>edges[i].weight;
    }
    int get_index(char search_char)
    {
        int p;
        for(int i = 0; i < heap_size; i++)
        {
            if(vertices[i].data == search_char)
            p = i;
        }
        return p;
    }
    bool is_vertex_in_queue(char check)
    {
        bool status = false;
        for(int i = 0; i < heap_size; i++)
        {
            if(vertices[i].data == check)
            status = true;
        }
        return status;
    }
    void build_min_heap()
    {
        heap_size = vertex_count;
		for(int i = (heap_size - 1) / 2; i >= 0; i--)
			minheapify(i);
    }
    void swap_vertices(vertex &a, vertex &b)
    {
    	vertex t = a;
	    a = b;
	    b = t;
	}
    void minheapify(int index)
    {
        int left = 2 * index + 1;
	    int right = 2 * index + 2;
	    int smallest = index;
	    if(left < heap_size && vertices[left].key < vertices[index].key)
	    	smallest = left;
	    if(right < heap_size && vertices[right].key < vertices[smallest].key)
		    smallest = right;
	    if(smallest != index)
	    {
		    swap_vertices(vertices[index], vertices[smallest]);
		    minheapify(smallest);
	    }
    }
    vertex extract_min()
    {
	    vertex new_vertex = vertices[0];
	    vertices[0] = vertices[heap_size - 1];
	    heap_size = heap_size - 1;
	    minheapify(0);	
	    return new_vertex;
    }
    void Prims_algo()
    {
        vertex extracted;
        vertices[0].key = 0;
        build_min_heap();
        while(heap_size > 0)
        {
            extracted = extract_min();
            cout<<endl<<extracted.data<<extracted.key<<endl;
            for(int i = 0; i < edge_count; i++)
            {
                if(edges[i].source == extracted.data || edges[i].dest == extracted.data)
                {
                    char ch = (edges[i].source == extracted.data) ? edges[i].dest : edges[i].source;
                    if(is_vertex_in_queue(ch) && edges[i].weight < vertices[get_index(ch)].key)
                    {
                        vertices[get_index(ch)].key = edges[i].weight;
                        vertices[get_index(ch)].parent = extracted.data;
                        minheapify(floor((get_index(ch) - 1) / 2));
                    }
                }
            }
        }
    }
};
int main()
{
    int vertex_count, edge_count;
    cout<<"Enter no of vertices and edges : \n";
    cin>>vertex_count>>edge_count;
    Graph graph(vertex_count, edge_count);
    graph.create_graph();
    graph.Prims_algo();
}
//    ab4bc8cd7de9ef10fg2gh1ha8bh11ci2ih7ig6cf4df14