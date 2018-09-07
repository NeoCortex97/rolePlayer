#include "TestFunctions.h"
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

vector <string> argvToString(int argc, char* arg[]);

int main(int argc, char *argv[]) {
  vector <string> args = argvToString(argc, argv);

  manualLoadFile(args[1]);
  std::vector<std::string> test;
  loadFileLinesComments(args[1], test);
  printLinesTest(test);
  clearVector(test);
  loadFileLines(args[1], test);
  printLinesTest(test);
  std::vector<std::string> meta;
  metaInformationTest(test, meta);
  printLinesTest(test);
  clearVector(test);
  loadFileWords(args[1], test);
  printWordVector(test);
  clearVector(test);
  loadFileWordsNoComments(args[1], test);
  cout << "Length of word vector: " << test.size() << std::endl;
  manualPrintWordVector(test);


  return 0;
}

vector <string> argvToString(int argc, char* argv[])
{
  std::vector<string> ret;

  for (int i = 0; i < argc; i++) {
    ret.push_back(string(argv[i]));
  }
  return ret;
}
