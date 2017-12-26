#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
// #include <cstdlib>
#include <vector>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;

string getTowerBottom()
{
  string bottom;
  ifstream inputFile;
  inputFile.open("./day7Input.txt");
  if (!inputFile.fail())
  {
    string row;
    vector<string> bases;
    vector<string> bottoms;
    vector<string> tops;
    while (getline(inputFile, row))
    {
      if (row.find("->") != string::npos)
      {
        bases.push_back(row);
      }
    }

    for (int i = 0; i < bases.size(); i++)
    {
      char* input = new char[bases[i].size() + 1];
      for (int j = 0; j < bases[i].size(); j++)
      {
        if (bases[i][j] == ',')
        {
          input[j] = ' ';
        }
        else
        {
          input[j] = bases[i][j];
        }
      }
      input[bases[i].size()] = '\0';

      vector<char*> temp;
      char* token = strtok(input, " ");
      while (token != 0)
      {
        temp.push_back(token);
        token = strtok(0, " ");
      }

      delete []token;
      token = 0;

      bottoms.push_back(temp[0]);
      for (int j = 3; j < temp.size(); j++)
      {
        tops.push_back(temp[j]);
      }

      delete []input;
      input = 0;
    }

    for (int i = 0; i < tops.size(); i++)
    {
      for (int j = 0; j < bottoms.size(); j++)
      {
        if (bottoms[j] == tops[i])
        {
          bottoms.erase(bottoms.begin() + j);
        }
      }
    }

    cout << bottoms.size() << endl;
    bottom = bottoms[0];
  }


  inputFile.close();

  cout << bottom << endl;
  return bottom;
}

int main()
{
  getTowerBottom();

  return 0;
}