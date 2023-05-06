#include <iostream>
#include <fstream>

using namespace std;

class Deque{
    int i, j;
public:
    int * v;
    Deque();
    void pop_back();
    void push_back(int toPush);
    int back();
    void pop_front();
    void push_front(int toPush);
    int front();
    bool empty();
};

int main()
{
    ifstream fin("deque.in");
    ofstream fout("deque.out");

    Deque myDeque;
    int n, k, x;
    int sum = 0;
    fin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        fin >> x;
        while(!myDeque.empty() && myDeque.back() > x)
            myDeque.pop_back();

        myDeque.push_back(x);
    }

    sum += myDeque.front();

    for(int i = k; i < n; i++){
        fin >> x;
        if(myDeque.front() == i - k)
            myDeque.pop_front();

        while(!myDeque.empty() && myDeque.back() > x)
            myDeque.pop_back();

        myDeque.push_back(x);

        sum += myDeque.front();
    }

    fout << sum << endl;

    return 0;
}

Deque::Deque()
{
    v = new int[5000000];
    i = -1;
    j = 5000001;
}

void Deque::pop_back()
{
    if(j == 5000001)
        return;
    j++;
}

void Deque::push_back(int toPush)
{
    j--;
    v[j] = toPush;
}

int Deque::back()
{
    if(j <= 5000000)
        return v[j];
    else
        return INT_MIN;
}

void Deque::pop_front()
{
    if(i == -1)
        return;
    i--;
}

void Deque::push_front(int toPush)
{
    v[++i] = toPush;
}

int Deque::front()
{
    if(i >= 0)
        return v[i];
    return INT_MIN;
}

bool Deque::empty()
{
    if(i == -1 && j == 5000001)
        return true;
    return false;
}
