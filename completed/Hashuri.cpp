#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

inline int f_hash(int n, int p)
{
    return n % p;
}

int main()
{
    ifstream fin("hashuri.in");
    ofstream fout("hashuri.out");

    int n, p = 666013;
    fin >> n;

    vector<vector<int>> v(666013);

    int operatie, x;
    while(n)
    {
        fin >> operatie >> x;
        if(operatie == 1)
        {
            v[f_hash(x, p)].push_back(x);
        }
        else if(operatie == 2)
        {
            bool found = false;
            int where = f_hash(x, p);
            int aux = v[where].size();
            for(int i = 0; i < aux; i++){
                if(v[where][i] == x){
                    found = true;
                    if(i == aux - 1){
                        v[where].pop_back();
                        break;
                    }
                }
                if(found == true)
                    v[where][i] = v[where][i + 1];
            }
        }
        else if(operatie == 3)
        {
            bool found = false;
            int where = f_hash(x, p);
            int aux = v[where].size();
            for(int i = 0; i < aux; i++)
                if(v[where][i] == x){
                    found = true;
                    break;
                }
            fout << found << endl;
        }
        n--;
    }
    return 0;
}
