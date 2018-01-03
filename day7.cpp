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

struct Tower
{
  string base;
  vector<Tower> balancers;
  Tower(string b)
  {
    base = b;
  }
};  

long long int findTowerWeight(Tower t, vector<Tower> bL, map <string, int> p, int w)
{
  long long int towerWeight = w;
  cout << towerWeight << endl;
  bool hasTowers = false;
  for (int i = 0; i < bL.size(); i++)
  {
    if (bL[i].base == t.base)
    {
      towerWeight += p[t.base];
      cout << towerWeight << endl;
      hasTowers = true;
      for (int j = 1; j < bL[i].balancers.size(); j++)
      {
        towerWeight += findTowerWeight(bL[i].balancers[j], bL, p, towerWeight);
        cout << towerWeight << endl;
      }
      return towerWeight;
    }
  }
  if (!hasTowers)
  {
    return towerWeight;
  }
}

void getCulpritAndWeight(string bottom)
{
  map <string, int> programs;
  vector<Tower> towerList;

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

      programs.insert(pair<string, int>(temp[0], stoi(temp[1])));

      if (temp.size() > 3)
      {
        vector<Tower> tempBalancers;
        for (int i = 3; i < temp.size(); i++)
        {
          Tower tempBalancer = Tower(temp[i]);
          tempBalancers.push_back(tempBalancer);
        }
        Tower tempTower = Tower(temp[0]);
        tempTower.balancers = tempBalancers;
        tempBalancers.clear();
        towerList.push_back(tempTower);
      }
    }
  }
  inputFile.close();

  for (int i = 0; i < towerList.size(); i++)
  {
    cout << towerList[i].base << ": " << programs[towerList[i].base] << " -> ";
    for (int j = 0; j < towerList[i].balancers.size(); j++)
    {
      cout << towerList[i].balancers[j].base << ": " << programs[towerList[i].balancers[j].base] << " ";
    }
    cout << endl;
  }
}

int main()
{
  string bottom = getTowerBottom();

  getCulpritAndWeight(bottom);

  return 0;
}