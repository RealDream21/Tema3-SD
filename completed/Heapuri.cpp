#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    set<int> notAHeap;
    vector<int> push_history;
    push_history.push_back(-1);
    vector<int> v;
    ifstream fin("heapuri.in");
    ofstream fout("heapuri.out");
    int n;
    fin >> n;
    int operatie;
    for(int i = 0; i < n; i++){
        fin >> operatie;
        if(operatie == 1){
            int x;
            fin >> x;
            push_history.push_back(x);
            notAHeap.insert(x);
        }
        else if(operatie == 2){
            int x;
            fin >> x;
            notAHeap.erase(push_history[x]);
            push_history[x] = -1;
        }
        else if(operatie == 3){
            fout << *notAHeap.begin() << endl;
        }
    }
    return 0;
}
