#include<iostream>
using namespace std;
struct vertex
{
    int distance;
    vertex *parent;
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
    vertex **vertices;
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
        vertices = new vertex *[vertex_count];
        edges = new Edge[edge_count];
    }
    void create_graph()
    {
        cout<<"Enter vertices data : \n";
        for(int i = 0; i < vertex_count; i++)
           {
                vertices[i] = new vertex;
                vertices[i]->parent = NULL;
                vertices[i]->distance = 99999;
                cin>>vertices[i]->data;
            } 
        cout<<"Enter the each edge's source, dest and weight : \n";
        for(int i = 0; i < edge_count; i++)
        cin>>edges[i].source>>edges[i].dest>>edges[i].weight;
    }
    void initialize_source(vertex *source)
    {
        source->distance = 0;
    }
    int get_vert_index(char var)
    {  
        int found = 0;
        for(int i = 0; i < vertex_count; i++)
        {
            if(vertices[i]->data == var)
            found = i;
        }
        return found;
    }
    void relax(Edge edge)
    {
        if(vertices[get_vert_index(edge.source)]->distance + edge.weight < vertices[get_vert_index(edge.dest)]->distance)
        {
            vertices[get_vert_index(edge.dest)]->distance = vertices[get_vert_index(edge.source)]->distance + edge.weight;
            vertices[get_vert_index(edge.dest)]->parent = vertices[get_vert_index(edge.source)];
        }
    }
    bool bellman_ford(vertex *source)
    {
        initialize_source(source);
        for(int i = 0; i < vertex_count - 1; i++)
        {
            for(int j = 0; j < edge_count; j++)
            relax(edges[j]);
        }
        for(int i = 0; i < edge_count; i++)
        {
            if(vertices[get_vert_index(edges[i].source)]->distance + edges[i].weight < vertices[get_vert_index(edges[i].dest)]->distance)
            {
                cout<<"negative cycle at edge "<<i;
                return false;
            }
        }
        return true;
    }
    void bfs_path(char source_data, char target_data)
    {
        vertex *source_vertex = vertices[get_vert_index(source_data)];
        vertex *target_vertex = vertices[get_vert_index(target_data)];
        if (source_data == target_data)
            cout<<endl<<"------The path is ";
        else if (target_vertex->parent == NULL)
            cout<<"No Path";
        else
            bfs_path(source_data, target_vertex->parent->data);
            cout<<target_data<<"-";        
    }
    void show()
    {
        for(int i = 0; i < vertex_count; i++)
        cout<<"("<<vertices[i]->data<<","<<vertices[i]->distance<<")";
    }
};
int main()
{
    int vertex_count, edge_count;
    cout<<"enter no of vertices and edges : \n";
    cin>>vertex_count>>edge_count;
    Graph graph(vertex_count, edge_count);
    graph.create_graph();
    bool fill = graph.bellman_ford(graph.vertices[0]);
    cout<<"the final shortest path for each vertex from source : \n";
    graph.show();
}
//  st6sy7ty8tx5xt-2zs2ys9zx7tz-4yx-3