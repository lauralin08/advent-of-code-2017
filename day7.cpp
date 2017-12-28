#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::pair;

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
    bottom = bottoms[0];
  }


  inputFile.close();

  cout << bottom << endl;
  return bottom;
}

void getCorrectWeight()
{
  struct Tower
  {
    string base;
    vector<string> balancers;
    Tower(string b, vector<string> bal)
    {
      base = b;
      balancers = bal;
    }
  };
  int correctWeight;
  map <string, int> programs;
  vector<Tower> balancerList;

  ifstream inputFile;
  inputFile.open("./day7Input.txt");
  if (!inputFile.fail())
  {
    string row;
    while (getline(inputFile, row))
    {
      char* input = new char[row.size() + 1];
      for (int i = 0; i < row.size(); i++)
      {
        if (row[i] == ',' || row[i] == '(' || row[i] == ')')
        {
          input[i] = ' ';
        }
        else
        {
          input[i] = row[i];
        }
      }
      input[row.size()] = '\0';

      vector<string> temp;
      char* token = strtok(input, " ");
      while (token != 0)
      {
        temp.push_back(token);
        token = strtok(0, " ");
      }

      delete []input;
      input = 0;

      if (temp.size() > 3)
      {
        vector<string> tempBalancers;
        for (int i = 3; i < temp.size(); i++)
        {
          tempBalancers.push_back(temp[i]);
        }
        Tower tempTower = Tower(temp[0], tempBalancers);
        balancerList.push_back(tempTower);
      }
      programs.insert(pair<string, int>(temp[0], stoi(temp[1])));
    }
  }
  inputFile.close();

  // string bottom = getTowerBottom();
  // for (int i = 0; i < balancerList.size(); i++)
  // {
  //   if (balancerList[i].base == bottom)
  //   {
  //     cout << programs[bottom] << " -> ";
  //     for (int j = 1; j < balancerList[i].balancers.size(); j++)
  //     {
  //       for (int k = 0; k < balancerList.size(); k++)
  //       {
          
  //       }
  //       cout << programs[balancerList[i].balancers[j]] << " ";
  //     }
  //     cout << endl;
  //   }
  // }

  // for (auto elem : programs)
  // {
  //   cout << elem.first << ": " << elem.second << endl;
  // }

  cout << correctWeight << endl;
}

int main()
{
  getTowerBottom();

  getCorrectWeight();

  return 0;
}