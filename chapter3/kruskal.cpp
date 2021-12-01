#include <bits/stdc++.h>

using namespace std;

void Union(vector<pair<int, int>> &dsu, int x, int y)
{
    if (dsu[x].second < dsu[y].second)
        dsu[x].first = y;
    else if (dsu[x].second > dsu[y].second)
        dsu[y].first = x;
    else
    {
        dsu[x].first = y;
        dsu[y].second++;
    }
}

int find(vector<pair<int, int>> &dsu, int x)
{
    if (dsu[x].first != x)
        dsu[x].first = find(dsu, dsu[x].first);
    return dsu[x].first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<tuple<int, int, int>> graph;
    int noNodes;
    cout << "Enter number of nodes" << endl;
    cin >> noNodes;
    cout << "Enter number of edges" << endl;
    int noEdges, weight, from, to;
    cin >> noEdges;
    cout << "Enter the edges in the format (weight, start node, end node) - " << endl;
    for (int i = 0; i < noEdges; i++)
    {
        cin >> weight >> from >> to;
        graph.push_back(make_tuple(weight, from, to));
    }
    sort(graph.begin(), graph.end(), [](tuple<int, int, int> a, tuple<int, int, int> b)
         { return get<0>(a) < get<0>(b); });
    vector<pair<int, int>> dsu(noNodes); // first stores the parent and second stores the rank
    for (int i = 0; i < noNodes; i++)
    {
        dsu[i].first = i;
        dsu[i].second = 0;
    }
    vector<tuple<int, int, int>> answerGraph;
    answerGraph.clear();
    for (int i = 0; i < noEdges; i++)
    {
        int x = find(dsu, get<1>(graph[i]));
        int y = find(dsu, get<2>(graph[i]));
        if (x != y)
        {
            answerGraph.push_back(graph[i]);
            Union(dsu, x, y);
        }
    }
    cout << "The MST is" << endl;
    for (int i = 0; i < answerGraph.size(); i++)
        cout << get<0>(graph[i]) << " " << get<1>(graph[i]) << " " << get<2>(graph[i]) << endl;
    return 0;
}