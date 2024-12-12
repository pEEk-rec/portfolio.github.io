#include<iostream>
using namespace std;

class Dijkstra
{
public:
    int cost[10][10];
    int vertices;
    int dist[10];
    int path[10];
    bool visited[10];

    void read_cost();
    void initialise(int source);
    void shortest_path(int source);
    void print_path();
};

void Dijkstra::read_cost()
{
    cout << "Enter the cost matrix: " << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> cost[i][j];
        }
    }
}

void Dijkstra::initialise(int source)
{
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = 1000000;
        visited[i] = false;
        path[i] = -1;
    }
    dist[source] = 0;
}

void Dijkstra::shortest_path(int source)
{
    for (int i = 0; i < vertices - 1; i++)
    {
        int min_dist = 1000000;
        int u;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && dist[v] < min_dist)
            {
                min_dist = dist[v];
                u = v;
            }
        }

        visited[u] = true;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && cost[u][v] != -1 && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
                path[v] = u;
            }
        }
    }
}

void Dijkstra::print_path()
{
    cout << "Energy distribution paths: " << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Sector " << i << ": Distance = " << dist[i] << ", Path: ";
        int vertex = i;
        while (vertex != -1)
        {
            cout << vertex << " ";
            vertex = path[vertex];
        }
        cout << endl;
    }
}

int main()
{
    Dijkstra d;
    cout << "Enter number of sectors: ";
    cin >> d.vertices;
    d.read_cost();

    int source;
    cout << "Enter the source sector: ";
    cin >> source;

    d.initialise(source);
    d.shortest_path(source);
    d.print_path();

    return 0;
}
