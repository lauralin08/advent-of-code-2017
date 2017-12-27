#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

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

int getCorrectWeight()
{
  class ProgramList
  {
  protected:
    struct ListNode
    {
      string program;
      int weight;
      ListNode *next;
      ListNode (string p, int w, ListNode *node = 0)
      {
        program = p;
        weight = w;
        next = node;
      }
    };
    ListNode *head;
  public:
    void add(string p, int w)
    {
      if (head == 0)
      {
        head = new ListNode(p, w);
      }
      else
      {
        ListNode *nodePtr = head;
        while (nodePtr->next != 0)
        {
          nodePtr = nodePtr->next;
        }
        nodePtr->next = new ListNode(p, w);
      }
    }
    void moveDuplicates()
    {
      ListNode *nodePtr = head;
      while (nodePtr != 0)
      {
        if (nodePtr->weight == 0)
        {
          ListNode *movePtr = head;
          while (movePtr != 0)
          {
            if (movePtr->program == nodePtr->program && movePtr->weight != 0)
            {
              nodePtr->weight = movePtr->weight;
              ListNode *garbage = movePtr;
              movePtr = movePtr->next;
              delete garbage;
              garbage = 0;
              movePtr = 0;
            }
          }
        }
        nodePtr = nodePtr->next;
      }
    }
    // int positionOf(string p)
    // {
    //   int index = 0;
    //   ListNode *nodePtr = head;
    //   while (nodePtr != 0)
    //   {
    //     if (nodePtr->program == p)
    //     {
    //       return index;
    //     }
    //     else
    //     {
    //       index++;
    //       nodePtr = nodePtr->next;
    //     }
    //   }
    //   return -1;
    // }
    // bool setNodeVal(int i, string p, int w)
    // {
    //   int counter = i - 1;
    //   ListNode *nodePtr = head;
    //   while (counter >= 0)
    //   {
    //     if (nodePtr == 0)
    //     {
    //       return false;
    //     }
    //     else
    //     {
    //       counter--;
    //       nodePtr = nodePtr->next;
    //     }
    //   }
    //   nodePtr->program = p;
    //   nodePtr->weight = w;
    //   return true;
    // }
    vector<string> getAsVector()
    {
      vector<string> programs;
      ListNode *nodePtr = head;
      while (nodePtr != 0)
      {
        programs.push_back(nodePtr->program + ": " + to_string(nodePtr->weight));
        nodePtr = nodePtr->next;
      }
      return programs;
    }
    ProgramList()
    {
      head = 0;
    }
    ~ProgramList()
    {
      ListNode *nodePtr = head;
      while (nodePtr != 0)
      {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
      }
    }
  };

  int correctWeight;
  ifstream inputFile;
  inputFile.open("./day7Input.txt");
  if (!inputFile.fail())
  {
    string row;
    ProgramList programList;
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

      vector<char*> temp;
      char* token = strtok(input, " ");
      while (token != 0)
      {
        temp.push_back(token);
        token = strtok(0, " ");
      }

      delete []token;
      token = 0;

      programList.add(temp[0], atoi(temp[1]));
      for (int i = 3; i < temp.size(); i++)
      {
        programList.add(temp[i], 0);
      }

      delete []input;
      input = 0;
    }
    
    programList.moveDuplicates();

    vector<string> programs = programList.getAsVector();
    for (int i = 0; i < programs.size(); i++)
    {
      cout << programs[i] << endl;
    }
  }


  inputFile.close();

  cout << correctWeight << endl;

  return correctWeight;
}

int main()
{
  getTowerBottom();

  getCorrectWeight();

  return 0;
}