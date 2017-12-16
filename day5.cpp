#include <iostream>
#include <vector>
#include <fstream>
using std::endl;
using std::cout;
using std::vector;
using std::ifstream;

// count steps required to hit index beyond list
// each time an index is "hit" the jump value increases
int stepsToExit()
{
  int steps = 0, index = 0;
  ifstream inputFile;

  inputFile.open("./day5Input.txt");
  if (!inputFile.fail())
  {
    int jump;
    vector<int> jumpList;

    while (inputFile >> jump)
    {
      jumpList.push_back(jump);
    }

    while (index < jumpList.size())
    {
      int temp = jumpList[index];
      jumpList[index]++;
      index += temp;
      steps++;
    }
  }

  inputFile.close();

  return steps;
}

// count steps but if jump >= 3, decrease instead of increase
int stepsToExit2()
{
  int steps = 0, index = 0;
  ifstream inputFile;

  inputFile.open("./day5Input.txt");
  if (!inputFile.fail())
  {
    int jump;
    vector<int> jumpList;

    while (inputFile >> jump)
    {
      jumpList.push_back(jump);
    }

    while (index < jumpList.size())
    {
      int temp = jumpList[index];
      if (temp >= 3)
      {
        jumpList[index]--;
      }
      else
      {
        jumpList[index]++;
      }
      index += temp;
      steps++;
    }
  }

  inputFile.close();

  return steps;
}

int main()
{
  cout << stepsToExit() << endl;

  cout << stepsToExit2() << endl;

  return 0;
}