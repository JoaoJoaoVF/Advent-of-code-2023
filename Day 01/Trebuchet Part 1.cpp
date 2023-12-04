#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int sum = 0;
    vector<string> input;

    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Erro no arquivo" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        input.push_back(line);
    }

    // Close the file
    inputFile.close();

    for (const string &str : input)
    {
        int first = -1, last = -1;

        for (char c : str)
        {
            if (isdigit(c))
            {
                if (first == -1)
                    first = c - '0';

                last = c - '0';
            }
        }

        if (first != -1 && last != -1)
        {
            sum += first * 10 + last;
        }
    }

    cout << sum << endl;

    return 0;
}
