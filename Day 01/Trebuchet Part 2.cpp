#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int main()
{
    int sum = 0;
    map<string, int> dictionary;

    dictionary["one"] = 1;
    dictionary["two"] = 2;
    dictionary["three"] = 3;
    dictionary["four"] = 4;
    dictionary["five"] = 5;
    dictionary["six"] = 6;
    dictionary["seven"] = 7;
    dictionary["eight"] = 8;
    dictionary["nine"] = 9;
    dictionary["1"] = 1;
    dictionary["2"] = 2;
    dictionary["3"] = 3;
    dictionary["4"] = 4;
    dictionary["5"] = 5;
    dictionary["6"] = 6;
    dictionary["7"] = 7;
    dictionary["8"] = 8;
    dictionary["9"] = 9;

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

    inputFile.close();

    regex regexPattern("(one|two|three|four|five|six|seven|eight|nine|1|2|3|4|5|6|7|8|9)");

    for (int i = 0; i < input.size(); i++)
    {

        int first = -1, last = -1;

        sregex_iterator iter(input[i].begin(), input[i].end(), regexPattern);
        sregex_iterator end;

        while (iter != end)
        {
            smatch match = *iter;
            int value = dictionary[match.str()];

            if (first == -1)
                first = value * 10;

            last = value;
            ++iter;
        }

        if (first != -1 && last != -1)
        {
            sum += first + last;
        }
    }

    cout << sum << endl;

    return 0;
}
