#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

const int  NMAX = 5000000;

class Deque {
    int  i, j;
public:
    int  *v;
    Deque();
    void push_back(int  a);
    void pop_back();
    int  back();
    void push_front(int  a);
    void pop_front();
    int  front();
    bool empty();
};

int main() {
    ifstream fin("deque.in");
    ofstream fout("deque.out");

    Deque myDeque;
    int  n, k, x;
    long long  *v = new long long [NMAX];
    long long  sum = 0;

    fin >> n >> k;
    for (int  i = 0; i < n; i++)
        fin >> v[i];

    for (int  i = 0; i < n; i++) {
        if (!myDeque.empty() && myDeque.front() <= i - k)
            myDeque.pop_front();

        while (!myDeque.empty() && v[i] < v[myDeque.back()])
            myDeque.pop_back();

        myDeque.push_back(i);

        if (i >= k - 1) {
            sum += v[myDeque.front()];
            if (myDeque.front() == i - k + 1)
                myDeque.pop_front();
        }
    }
    fout << sum << "\n";
    return 0;
}

Deque::Deque() {
    j = 0;
    i = 0;
    v = new int [NMAX];
}

void Deque::push_back(int  a) {
    v[j] = a;
    j = (j + 1) % NMAX;
}

void Deque::pop_back() {
    if (!empty())
        j = (j - 1 + NMAX) % NMAX;
}

int Deque::back() {
    if (!empty())
        return v[(j - 1 + NMAX) % NMAX];
    return INT_MIN;
}

void Deque::push_front(int  a) {
    i = (i - 1 + NMAX) % NMAX;
    v[i] = a;
}

void Deque::pop_front() {
    if(!empty())
        i = (i + 1) % NMAX;
}

int Deque::front() {
    if (!empty())
        return v[i];
    return INT_MAX;
}

bool Deque::empty() {
    if (i == j)
        return true;
    return false;
}
