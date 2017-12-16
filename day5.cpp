#include <iostream>
#include <vector>
#include <fstream>
using std::endl;
using std::cout;
using std::vector;
using std::ifstream;

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
      cout << jump << " ";
      jumpList.push_back(jump);
    }

    cout << endl;

    while (index < jumpList.size())
    {
      cout << index << " ";
      cout << jumpList[index] << " ";
      index += jumpList[index];
      steps++;
    }
  }

  inputFile.close();

  return steps;
}

int main()
{
  cout << stepsToExit() << endl;

  // cout << << endl;

  return 0;
}