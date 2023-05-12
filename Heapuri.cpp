#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> pozitie;
void pushHeap(vector<int>& v, int toPush);
void popHeap(vector<int>& v, int toPop);
int top(vector<int>& v);

int main()
{
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
            pushHeap(v, x);
        }
        else if(operatie == 2){
            int x;
            fin >> x;
            popHeap(v, push_history[x]);
            push_history[x] = -1;
        }
        else if(operatie == 3){
            fout << top(v) << endl;
        }
    }
    return 0;
}

void pushHeap(vector<int>& v, int toPush)
{
    v.push_back(toPush);
    int pos = v.size() - 1;
    pozitie[toPush] = pos;
    while(pos > 0){
        int tata = (pos - 1)/2;
        if(v[tata] > v[pos]){
            swap(pozitie[v[tata]], pozitie[v[pos]]);
            swap(v[tata], v[pos]);
            pos = tata;
        }
        else break;
    }
}

void popHeap(vector<int>& v, int toPop)
{
    int pos = pozitie[toPop];
    swap(pozitie[v[pos]], pozitie[v[v.size() - 1]]);
    swap(v[pos], v[v.size() - 1]);
    v.pop_back();

    while (true) {
        int st = pos * 2 + 1;
        int dr = pos * 2 + 2;
        if(st >= v.size())
            break;
        if (dr < v.size() && v[dr] < v[st] && v[pos] > v[dr]) {
            swap(v[pos], v[dr]);
            swap(pozitie[v[pos]], pozitie[v[dr]]);
            pos = dr;
        }
        else if (v[pos] > v[st]) {
            swap(v[pos], v[st]);
            swap(pozitie[v[pos]], pozitie[v[st]]);
            pos = st;
        }
        else break;
    }
}

int top(vector<int>& v)
{
    return v[0];
}
