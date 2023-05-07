#include <iostream>
#include <deque>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    ifstream fin("alibaba.in");
    ofstream fout("alibaba.out");

    deque<int> numar_maxim;
    int n, k, v[10005];
    fin >> n >> k;
    int deTaiat = k;
    string input;
    fin >> input;
    for(int i = 0; i < n; i++)
        v[i] = input[i] - '0';

    for(int i = 0; i < n; i++){
        while(!numar_maxim.empty() && v[i] > numar_maxim.back() && deTaiat > 0){
            numar_maxim.pop_back();
            deTaiat--;
        }
        numar_maxim.push_back(v[i]);
    }

    while(numar_maxim.size() > n - k)
        numar_maxim.pop_back();

    int numar = 0;
    while(!numar_maxim.empty()){
        fout << numar_maxim.front();
        numar_maxim.pop_front();
    }

    return 0;
}
