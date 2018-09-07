#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "TextUtils.h"
#include "FileUtils.h"
#include "TestFunctions.h"
#include "AdvLexer.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::vector;
using std::ifstream;

void help(string arg);
int run(std::vector<string> args);
vector <string> argvToString(int argc, char* arg[]);

int main(int argc, char* argv[])
{

  int res = 0;
  //cout << "Argument count: " << argc << endl;
  if (argc < 2) {
    help(argv[0]);
    res = 0;
  }
  else
  {
    vector<string> args = argvToString(argc, argv);
    res = run(args);
  }

  return res;
}

void help(string arg)
{
  std::cout << "Die anwendung wurde mit zu wenigen parametern aufgerufen.\n"
            << "Bitte halten sie sich an die folgende Form:\n\n"
            << "./" << arg << " <PathToAdventureFile>\n"
            << "Beispiel:\n./" << arg << "Test.adv\n";
}

vector <string> argvToString(int argc, char* argv[])
{
  std::vector<string> ret;

  for (int i = 0; i < argc; i++) {
    ret.push_back(string(argv[i]));
  }
  return ret;
}

int run(vector <string> args)
{
  cout << "hallo welt\n";

  Story test(args[1]);

  return 0;
}
