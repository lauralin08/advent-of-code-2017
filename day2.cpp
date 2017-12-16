#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;

// add together the biggest difference in each row
int checksum()
{
  ifstream inputFile;
  string row;
  int largest, smallest, difference, total = 0;

  inputFile.open("./day2Input.txt");

  if (!inputFile.fail())
  {
    while (getline(inputFile, row))
    {
      char* input = new char[row.size() + 1];
      for (int i = 0; i < row.size(); i++)
      {
        input[i] = row[i];
      }
      input[row.size()] = '\0';

      char* token = strtok(input, " \t\n");
      largest = smallest = atoi(token);

      while (token != 0)
      {
        int current = atoi(token);
        if (current < smallest)
        {
          smallest = current;
        }
        if (current > largest)
        {
          largest = current;
        }

        token = strtok(0, " \t\n");
      }

      int difference = largest - smallest;
      total += difference;
      
      delete []input;
    }

    inputFile.close();
  }

  return total;
}

// add the dividends of the two divisible numbers in each row
int checksum2()
{
  ifstream inputFile;
  string row;
  int quotient, total = 0;
  vector<int> rowInts;

  inputFile.open("./day2Input.txt");

  if (!inputFile.fail())
  {
    while (getline(inputFile, row))
    {
      char* input = new char[row.size() + 1];
      for (int i = 0; i < row.size(); i++)
      {
        input[i] = row[i];
      }
      input[row.size()] = '\0';

      char* token = strtok(input, " \t\n");

      while (token != 0)
      {
        rowInts.push_back(atoi(token));

        token = strtok(0, " \t\n");
      }

      for (int i = 0; i < rowInts.size(); i++)
      {
        for (int j = 0; j < rowInts.size(); j++)
        {
          if (i != j)
          {
            if (rowInts[i] % rowInts[j] == 0)
            {
              quotient = rowInts[i]/rowInts[j];
            }
            else if (rowInts[j] % rowInts[i] == 0)
            {
              quotient = rowInts[j]/rowInts[i];
            }
          }
        }
      }
      total += quotient;

      rowInts.clear();
      delete []input;
      input = 0;
    }

    inputFile.close();
  }
  
  return total;
}

int main()
{
  cout << checksum() << endl;

  cout << checksum2() << endl;

  return 0;
}