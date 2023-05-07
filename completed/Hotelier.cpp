#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <stack>

using namespace std;

int v[10];

int main()
{
    //ifstream fin("date.in");
    //ofstream fout("date.out");
    int n;
    string input;
    cin >> n;
    cin >> input;
    deque<int> free_rooms;
    for(int i = 0; i <= 9; i++)
        free_rooms.push_back(i);

    for(int i = 0; i < n; i++)
    {
        if(input[i] == 'L'){
            v[free_rooms.front()] = 1;
            free_rooms.pop_front();
        }
        else if(input[i] == 'R'){
            v[free_rooms.back()] = 1;
            free_rooms.pop_back();
        }
        else{
            int room_nr = input[i] - '0';
            v[room_nr] = 0;
            if(room_nr <= 10){
                stack<int> aux;
                while(room_nr > free_rooms.front()){
                    aux.push(free_rooms.front());
                    free_rooms.pop_front();
                }
                free_rooms.push_front(room_nr);
                while(!aux.empty()){
                    free_rooms.push_front(aux.top());
                    aux.pop();
                }
            }
            else if(room_nr > 5){
                stack<int> aux;
                while(room_nr < free_rooms.back()){
                    aux.push(free_rooms.back());
                    free_rooms.pop_back();
                }
                free_rooms.push_back(room_nr);
                while(!aux.empty()){
                    free_rooms.push_back(aux.top());
                    aux.pop();
                }
            }
        }
    }
    for(int i = 0; i <= 9; i++)
        cout << v[i];

        //ddd
    return 0;
}
