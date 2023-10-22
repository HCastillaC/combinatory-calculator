#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void permutations_wo_repetition(int total, int per_set, fstream& file, vector<int> chain)
{
    if(chain.size() == per_set)
    {
        
    }
}

int main()
{
    char selector = '1';
    int total_elements;
    int elements_per_set;
    string file_name;
    vector<int> empty;

    while(true)
    {
        cout << "Write the number of the combinatorics problem you want to solve: " << endl;
        cout << "1. Permutations without repetition" << endl;
        cout << "0. Exit" << endl;
        cin >> selector;

        if(selector == '0') break;

        cout << "How many elements are in total?: ";
        cin >> total_elements;
        if(selector != '1' and selector != '2')
        {
            cout << "How many elements are in a set?: ";
            cin >> elements_per_set;
        }

        cout << "Write the name of the file which will store the answers: ";
        cin >> file_name;
        file_name += ".txt";
        fstream file;
        file.open(file_name, ios::out | ios::app);
               
        switch(selector)
        {
            case '1': permutations_wo_repetition(total_elements, elements_per_set, file, empty); break;
        }
    }

    return 0;
}