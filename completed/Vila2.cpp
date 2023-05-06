#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");

int main()
{
    int n, k, varste[100005];
    fin >> n >> k;

    for (int i = 0; i < n; i++)
        fin >> varste[i];

    deque<int> maxDeque, minDeque;
    int diferentMaxima = 0;

    for (int i = 0; i < n; i++)
    {
        while (!maxDeque.empty() && varste[i] > varste[maxDeque.back()])
            maxDeque.pop_back();

        while (!minDeque.empty() && varste[i] < varste[minDeque.back()])
            minDeque.pop_back();

        maxDeque.push_back(i);
        minDeque.push_back(i);

        if (i - maxDeque.front() > k)
            maxDeque.pop_front();

        if (i - minDeque.front() > k)
            minDeque.pop_front();

        diferentMaxima = max(diferentMaxima, varste[maxDeque.front()] - varste[minDeque.front()]);
    }

    fout << diferentMaxima << endl;

    return 0;
}
