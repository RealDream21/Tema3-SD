#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long a, b, c, d, e;


int f_hash(long long last, long long secondToLast)
{
    long long rez = c * last + d * secondToLast;
    return int(rez % e);
}

int main()
{
    ifstream fin("muzica.in");
    ofstream fout("muzica.out");
    int n, m, rez = 0;
    fin >> n >> m;
    fin >> a >> b >> c >> d >> e;

    unordered_set<long long> melodii;
    long long x;
    for(int i = 0; i < n; i++){
        fin >> x;
        melodii.insert(x);
    }

    long long last = b, secondToLast = a;
    if(melodii.count(last)){
        rez++;
        melodii.erase(last);
    }
    if(melodii.count(secondToLast)){
        rez++;
        melodii.erase(secondToLast);
    }

    for(int i = 3; i <= m; i++){
        long long decoded = f_hash(last, secondToLast);
        if(melodii.count(decoded)){
            rez++;
            melodii.erase(decoded);
        }
        secondToLast = last;
        last = decoded;
    }
    fout << rez;
    return 0;
}
