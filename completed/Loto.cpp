#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


int f_hash(int n, int p)
{
    return n % p;
}

int main()
{
    ifstream fin("loto.in");
    ofstream fout("loto.out");

    int p = 1000039, n, s, x, v[105];
    unordered_map<int, vector<int>> sume;
    //vector<vector<int>> cautare_rapida(p); // still tle => cautare binara :(
    fin >> n >> s;
    for(int i = 0; i < n; i++){
        fin >> v[i];
        //cautare_rapida[f_hash(v[i], p)].push_back(v[i]);
    }

    sort(v, v + n);

    for(int i = 0; i < n; i++)
        for(int j = i ; j < n; j++)
            for(int k = j; k < n; k++)
                sume[v[i] + v[j] + v[k]] = {v[i], v[j], v[k]};

    bool found = false;
    for(int i = 0; i < n && !found; i++)
        for(int j = i; j < n && !found; j++)
            for(int k = j; k < n && !found; k++){
                int ramas = s - v[i] - v[j] - v[k];
                if(sume.count(ramas)){
                    found = true;
                    auto q = sume.find(ramas);
                    for(auto el: q->second)
                        fout << el << " ";
                    fout << v[i] << " " << v[j] << " " << v[k];
                }

            }
    if(found == false)
        fout << -1;

    return 0;
}
