#include<iostream>
#include<cmath>
using namespace std;
int heap_size = 0;
struct vertex
{
    int distance;
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
            vertices[i].distance = 999999;
            vertices[i].parent = '\0';
        }
        cout<<"Enter the edge's source, destination and weight : \n";
        for(int i = 0; i < edge_count; i++)
            cin>>edges[i].source>>edges[i].dest>>edges[i].weight;
    }
    int get_index(char search_char)
    {
        int p = 0;
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
	    if(left < heap_size && vertices[left].distance < vertices[index].distance)
	    	smallest = left;
	    if(right < heap_size && vertices[right].distance < vertices[smallest].distance)
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
    void relax(int source_distance, Edge edge)
    {
        if(source_distance + edge.weight < vertices[get_index(edge.dest)].distance)
        {
            vertices[get_index(edge.dest)].distance = source_distance + edge.weight;
            vertices[get_index(edge.dest)].parent = edge.source;
            for(int i = floor((get_index(edge.dest) - 1) / 2); i >= 0; i--)
			minheapify(i);
        }
    }
    void show()
    {
        for(int i = 0; i < heap_size; i++)
            cout<<"("<<vertices[i].data<<","<<vertices[i].distance<<")";
    }
    void dijkstra_algo()
    {
        vertex extracted;
        vertices[0].distance = 0;
        build_min_heap();
        while(heap_size > 0)
        {
            extracted = extract_min();
            cout<<endl<<extracted.data<<extracted.distance<<endl;
            for(int i = 0; i < edge_count; i++)
            {
                if(edges[i].source == extracted.data)
                {
                    if(is_vertex_in_queue(edges[i].dest))
                    {
                        relax(extracted.distance, edges[i]);
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
    graph.dijkstra_algo();
}
//    st10sy5ty2yt3zs7tx1yz2yx9xz6zx4