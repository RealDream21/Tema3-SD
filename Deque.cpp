#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

const int NMAX = 5000000;

class Deque {
    long long *v;
    long long i, j;

public:
    Deque();
    void push_back(long long a);
    void pop_back();
    long long back();
    void push_front(long long a);
    void pop_front();
    long long front();
    bool empty();
};

int main() {
    ifstream fin("deque.in");
    ofstream fout("deque.out");

    Deque myDeque;
    long long n, k, x;
    long long sum = 0;

    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        fin >> x;

        if (!myDeque.empty() && myDeque.front() <= i - k)
            myDeque.pop_front();

        while (!myDeque.empty() && x < myDeque.back())
            myDeque.pop_back();

        myDeque.push_back(x);

        if (i >= k - 1) {
            sum += myDeque.front();
            if (myDeque.front() == i - k + 1)
                myDeque.pop_front();
        }
    }

    cout << sum << "\n";
    return 0;
}

Deque::Deque() {
    j = 0;
    i = 0;
    v = new long long[NMAX];
}

void Deque::push_back(long long a) {
    v[j] = a;
    j++;
}

void Deque::pop_back() {
    if (!empty())
        j--;
}

long long Deque::back() {
    if (!empty())
        return v[j - 1];
    return INT_MIN;
}

void Deque::push_front(long long a) {
    i = (i - 1 + NMAX) % NMAX;
    v[i] = a;
}

void Deque::pop_front() {
    if (!empty())
        i++;
}

long long Deque::front() {
    if (!empty())
        return v[i];
    return INT_MAX;
}

bool Deque::empty() {
    if (i >= j)
        return true;
    return false;
}
