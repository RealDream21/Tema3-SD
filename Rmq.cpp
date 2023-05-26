#include <iostream>
#include <fstream>
#include <cmath>

std::ifstream fin("rmq.in");
std::ofstream fout("rmq.out");


int main()
{
    int n, m;
    fin >> n >> m;
    int size_log = int(log(n));

    int v[n], preprocesare[n][20];
    for(int i = 0; i < n; i++){
        fin >> v[i];
        preprocesare[i][0] = v[i];
    }

    for(int j = 1; j < 20; j++){
        for(int i = 0; i + (1 << j) - 1 < n; i++)
            preprocesare[i][j] = std::min(preprocesare[i][j - 1], preprocesare[i + (1 << (j - 1))][j - 1]);
    }

    int a, b;
    for(int i = 0; i < m; i++){
        fin >> a >> b;
        a--;
        b--;
        int lung = b - a + 1;
        //int range = int(log(lung));
        int range = 0;
        for(range; (1<<(range + 1)) <= lung; range++);
        fout << std::min(preprocesare[a][range], preprocesare[b - (1<<range) + 1][range]) << std::endl;
    }
    return 0;
}
