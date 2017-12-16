#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using std::endl;
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

// count the number of passphrases that have no repeats
int getValidCount()
{
  ifstream inputFile;
  string passphrase;
  vector<string> validPass;
  bool valid;
  int count = 0;

  inputFile.open("./day4Input.txt");
  if (!inputFile.fail())
  {
    while (getline(inputFile, passphrase))
    {
      valid = true;

      char* passCopy = new char[passphrase.size() + 1];
      for (int i = 0; i < passphrase.size(); i++)
      {
        passCopy[i] = passphrase[i];
      }
      passCopy[passphrase.size()] = '\0';

      char* token = strtok(passCopy, " ");
      while (token != 0)
      {
        for (int i = 0; i < validPass.size(); i++)
        {
          if (token == validPass[i])
          {
            valid = false;
          }
        }
        validPass.push_back(token);
        token = strtok(0, " ");
      }

      delete []passCopy;
      passCopy = 0;

      validPass.clear();

      if (valid)
      {
        count++;
      }
    }
  }

  inputFile.close();

  cout << count << endl;
  return count;
}

// count passphrases with no repeats or anagrams
int getValidCount2()
{
  ifstream inputFile;
  string passphrase;
  vector<string> validPass;
  bool valid;
  int count = 0;

  inputFile.open("./day4Input.txt");
  if (!inputFile.fail())
  {
    while (getline(inputFile, passphrase))
    {
      valid = true;

      char* passCopy = new char[passphrase.size() + 1];
      for (int i = 0; i < passphrase.size(); i++)
      {
        passCopy[i] = passphrase[i];
      }
      passCopy[passphrase.size()] = '\0';

      char* token = strtok(passCopy, " ");
      while (token != 0)
      {
        for (int i = 0; i < validPass.size(); i++)
        {
          if (token == validPass[i])
          {
            valid = false;
          }
          else if (valid && strlen(token) == validPass[i].size())
          {
            vector<char> letterBank;
            for (int j = 0; j < strlen(token); j++)
            {
              letterBank.push_back(token[j]);
            }

            for (int j = 0; j < validPass[i].size(); j++)
            {
              for (int k = 0; k < letterBank.size(); k++)
              {
                if (validPass[i][j] == letterBank[k])
                {
                  letterBank.erase(letterBank.begin() + k);
                }
              }
            }
             
            if (letterBank.empty())
            {
              valid = false;
            }
            letterBank.clear();
          }
        }
        validPass.push_back(token);
        token = strtok(0, " ");
      }

      delete []passCopy;
      passCopy = 0;

      validPass.clear();

      if (valid)
      {
        count++;
      }
    }
  }

  inputFile.close();

  cout << count << endl;
  return count;
}

int main()
{
  getValidCount();

  getValidCount2();

  return 0;
}