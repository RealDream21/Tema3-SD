#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("pariuri.in");
    ofstream fout("pariuri.out");
    int n;
    fin >> n;
    unordered_map<int, int> sume;
    priority_queue<int> timpi_ordine;
    int timp, suma_bani, t;
    for(int i = 0; i < n; i++){
        fin >> t;
        for(int j = 0; j < t; j++){
            fin >> timp >> suma_bani;
            sume[timp] += suma_bani;
        }
    }

    vector<int> vals;
    for(auto i = sume.begin(); i != sume.end(); i++)
        vals.push_back(i->first);
    sort(vals.begin(), vals.end());

    fout << vals.size() << endl;
    for(auto i = vals.begin(); i != vals.end(); i++)
        fout << *i << " " << sume[*i] << " ";

    return 0;
}
