#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

void isMax(string color, int value, vector<int> &max)
{
    if (color == "red")
    {
        if (value > max[0])
        {
            max[0] = value;
        }
    }
    else if (color == "green")
    {
        if (value > max[1])
        {
            max[1] = value;
        }
    }
    else if (color == "blue")
    {
        if (value > max[2])
        {
            max[2] = value;
        }
    }
}

int main()
{
    int sum = 0;
    int idGame = 0;
    vector<char> input;
    vector<int> max(3, 0); 

    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Erro no arquivo" << endl;
        return 1;
    }

    char caracter;
    while (inputFile.get(caracter))
    {
        if (caracter == '\n')
        {
            regex pattern("(\\d+) (red|green|blue)");
            smatch match;

            string str(input.begin(), input.end());

            while (regex_search(str, match, pattern))
            {
                isMax(match.str(2), stoi(match.str(1)), max);
                str = match.suffix().str();
            }

            cout << max[0] << " " << max[1] << " " << max[2] << endl;

            sum += max[0] * max[1] * max[2];

            idGame = 0;
            max = {0, 0, 0}; 
            input.clear();
        }
        else if (caracter == ':')
        {
            string str(input.begin(), input.end());
            regex pattern("(\\d+)");
            smatch match;

            if (regex_search(str, match, pattern))
                idGame = stoi(match.str(1));

            input.clear();
        }
        else
        {
            input.push_back(caracter);
        }
    }

    cout << sum << endl;

    inputFile.close();

    return 0;
}
