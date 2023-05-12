#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


int main()
{
    ifstream fin("proc2.in");
    ofstream fout("proc2.out");

    int n, m;
    fin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> timpi_procesoare;
    priority_queue<int, vector<int>, greater<int>> procesoare_libere;

    for (int i = 1; i <= n; i++)
        procesoare_libere.push(i);

    int s, d;
    for (int i = 0; i < m; i++) {
        fin >> s >> d;

        while(!timpi_procesoare.empty() && s >= timpi_procesoare.top().first){
            procesoare_libere.push(timpi_procesoare.top().second);
            timpi_procesoare.pop();
        }

        int procesorLiber = procesoare_libere.top();
        timpi_procesoare.push({s + d, procesorLiber});
        procesoare_libere.pop();
        fout << procesorLiber << endl;
    }
    return 0;
}
