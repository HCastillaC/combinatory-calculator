#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void permutations_wo_repetition(int total, int initial, fstream& file, vector<int> chain, vector<int> remaining, int& total_sets)
{
    vector<int> chain_aux;
    vector<int> remaining_aux;

    if(chain.size() == total)
    {
        for(int i = 0; i < chain.size(); i++) file << chain[i] << " ";
        file << endl;
        total_sets++;
    }
    else
    {
        for(int i = 0; i < remaining.size(); i++)
        {
            chain_aux = chain;
            remaining_aux = remaining;
            chain_aux.push_back(remaining_aux[i]);
            remaining_aux.erase(remaining_aux.begin() + i);
            permutations_wo_repetition(total, i, file, chain_aux, remaining_aux, total_sets);
        }
    }
}

int main()
{
    char selector = '1';
    int total_elements;
    int elements_per_set;
    int total_sets = 0;
    string file_name;
    vector<int> empty;
    vector<int> elements;

    while(true)
    {
        cout << "Write the number of the combinatorics problem you want to solve: " << endl;
        cout << "1. Permutations without repetition" << endl;
        cout << "0. Exit" << endl;
        cin >> selector;

        if(selector == '0') break;

        cout << "How many elements are in total?: ";
        cin >> total_elements;
        for(int i = 0; i < total_elements; i++) elements.push_back(i);
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
            case '1':
                permutations_wo_repetition(total_elements, 0, file, empty, elements, total_sets);
                break;
        }

        file.close();

        cout << "There are " << total_sets << " sets" << endl;
        total_sets = 0;
    }

    return 0;
}