#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>

using namespace std;

bool isValid(string type, int value)
{
    if (type == "red" && value <= 12)
        return true;
    else if (type == "green" && value <= 13)
        return true;
    else if (type == "blue" && value <= 14)
        return true;
    return false;
}

int main()
{
    int sum = 0;
    int idGame = 0;
    vector<char> input;

    ifstream inputFile("input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Erro no arquivo" << endl;
        return 1;
    }

    char caracter;
    bool allValid = true;
    while (inputFile.get(caracter))
    {
        if (caracter == '\n')
        {
            regex pattern("(\\d+) (red|green|blue)");
            smatch match;

            string str(input.begin(), input.end());

            while (regex_search(str, match, pattern))
            {
                if (!isValid(match.str(2), stoi(match.str(1))))
                {
                    allValid = false;
                    break;
                }
                str = match.suffix().str();
            }

            if (allValid)
            {
                sum += idGame;
            }

            idGame = 0;
            allValid = true;
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