#include "TestFunctions.h"
#include "TextUtils.h"
#include "FileUtils.h"
#include <iostream>
#include <fstream>

void manualLoadFile(std::string filename)
{
  std::cout << "\nLoad file and add to string manually...\n"
       << "------------------------------------------------------------\n";
  std::ifstream input(filename);
  std::string line = "", text = "";
  while (getline(input, line)) {
    if (!isMarked(line, "#")) {
      text += line;
    }
  }
  input.close();
  std::cout << "------------------------------------------------------------\n";
}

void loadFileLinesComments(std::string filename, std::vector<std::string> &dest)
{
  std::cout << "\nLoad File with comments...\n"
       << "------------------------------------------------------------\n";
  loadToLineVector(filename, dest);
  std::cout << "------------------------------------------------------------\n";
}

void printLinesTest(std::vector<std::string> &src)
{
  std::cout << "\nPrint file: \n"
       << "------------------------------------------------------------\n";
  printFileContentsFromLineVector(src);
  std::cout << "------------------------------------------------------------\n";
}

void clearVector(std::vector<std::string> &dest)
{
  std::cout << "\nClear contents of line vector...\n"
       << "------------------------------------------------------------\n";
  dest.clear();
  std::cout << "------------------------------------------------------------\n";
}

void loadFileLines(std::string filename, std::vector<std::string> &dest)
{
  std::cout << "\nLoad File stripping comments...\n"
       << "------------------------------------------------------------\n";
  loadToLineVector(filename, dest, "#", true);
  std::cout << "------------------------------------------------------------\n";
}

void metaInformationTest(std::vector<std::string> &src, std::vector<std::string> &dest)
{
  std::cout << "\nGet all line that contain meta information...\n"
       << "------------------------------------------------------------\n";
  getMarkedLines(src, dest, "!");
  std::cout << "------------------------------------------------------------\n";
}

void loadFileWords(std::string &filename, std::vector<std::string> &dest)
{
  std::cout << "\nLoad file to vector of words...\n"
       << "------------------------------------------------------------\n";
  loadToWordVector(filename, dest);
  std::cout << "------------------------------------------------------------\n";
}

void printWordVector(std::vector<std::string> &content)
{
  std::cout << "\nPrint the words:\n"
       << "------------------------------------------------------------\n";
  printFileContentsFromWordVector(content);
  std::cout << "------------------------------------------------------------\n";
}

void loadFileWordsNoComments(std::string &filename, std::vector<std::string> &dest)
{
  std::cout << "\nLoad file to vector of words without comments:\n"
       << "------------------------------------------------------------\n";
  loadToWordVector(filename, dest, "#", true);
  std::cout << "------------------------------------------------------------\n";
}

void manualPrintWordVector(std::vector<std::string> &content)
{
  std::cout << "\nPrint Vector of words:\n"
       << "------------------------------------------------------------\n";
  //printFileContentsFromWordVector(test);
  for (size_t i = 0; i < content.size(); i++) {
    std::cout << content[i] << ' ';
  }
  std::cout << "\n------------------------------------------------------------\n";
}
