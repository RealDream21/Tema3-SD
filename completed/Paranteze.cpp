#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("paranteze.in");
ofstream fout("paranteze.out");

int main()
{
    int n;
    fin >> n;

    string paranteze;
    fin >> paranteze;

    stack<int> stiva;
    int maxLungime = 0;
    stiva.push(-1);

    for (int i = 0; i < n; i++){
        if (paranteze[i] == '(' || paranteze[i] == '[' || paranteze[i] == '{'){
            stiva.push(i);
        }
        else if (paranteze[i] == ')' || paranteze[i] == ']' || paranteze[i] == '}'){
            if (!stiva.empty() && ((paranteze[i] == ')' && paranteze[stiva.top()] == '(') || (paranteze[i] == ']' && paranteze[stiva.top()] == '[') || (paranteze[i] == '}' && paranteze[stiva.top()] == '{')))
                {
                stiva.pop();
                maxLungime = max(maxLungime, i - stiva.top());
            }
            else{
                stiva.push(i);
            }
        }
    }
    fout << maxLungime << endl;
    return 0;
}
