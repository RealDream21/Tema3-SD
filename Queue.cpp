#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;

ifstream fin("queue.in");
ofstream fout("queue.out");

stack<int> stiva1;
stack<int> stiva2;

void push_coada(int a);
void pop_coada();

void push_back(int a);
void pop_front();

int main()
{
    int n;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        string querry;
        fin >> querry;
        int number = 0;
        for(int j = 10; j < querry.size(); j++){
            if(querry[1] == 'o')
                break;
            if(querry[j] == ')')
                break;
            number = number * 10 + (querry[j] - '0');
        }

        fout << i << ": ";
        if(querry[1] == 'u')
            push_back(number);
        else if(querry[1] == 'o')
            pop_front();
        fout << endl;
    }
    return 0;
}

void push_back(int a)
{
    fout << "read(" << a << ") ";
    /*
    if(stiva1.empty() && stiva2.empty())
    {
        fout << "push(2," << a << ") ";
        stiva2.push_back(a);
        return;
    }*/
    while(!stiva2.empty())
    {
        int toPush = stiva2.top();
        stiva2.pop();
        stiva1.push(toPush);
    }
    stiva1.push(a);
    fout << "push(1," << a << ") ";
}

void pop_front()
{
    if(stiva1.empty() && stiva2.empty())
        return;
    if(!stiva2.empty())
    {
        fout << "pop(2) ";
        fout << "write(" << stiva2.top() << ") ";
        stiva2.pop();
        return;
    }
    while(stiva1.size() > 1)
    {
        fout << "pop(1) ";
        fout << "push(2," << stiva1.top() << ") ";
        stiva2.push(stiva1.top());
        stiva1.pop();
    }
    fout << "pop(1) ";
    fout << "write(" << stiva1.top() << ") ";
    stiva1.pop();
    return;
}
