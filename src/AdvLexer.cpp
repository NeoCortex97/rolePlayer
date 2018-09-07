#include "AdvLexer.h"
#include "FileUtils.h"
#include <vector>
#include <iostream>
#include <fstream>

Story::Story(std::string filename)
{
  this->filename = filename;
  this->valid = false;

  std::ifstream input(filename);
  std::string line;
  while (getline(input, line)) {
    if (testFormat(line)) {
      this->valid = true;
    }
  }
  input.close();
  if (!this->valid) {
    std::cerr << "Could not find any AdventureScript text inside\n";
  }else{
    std::cout << "Found valid format file!\n";
  }
}

std::string Story::getFilename()
{
  return this->filename;
}

bool Story::testFormat(std::string content)
{
  bool result = true;
  if (isMarked(content, "!FORMAT")) {
    if (!contains(content, "ADV_TEXT")) {
      //std::cerr << "ERROR: Invalid Format!\n       Das Format muss ADV_TEXT sein!\n";
      result = false;
    }
  }
  return result;
}

void Story::load() {
  this->load(this->filename);
}

void Story::load(std::string filename) {
  loadToLineVectorSkipComments(filename, this->lines);
}

std::string findStoryName()
{

  
}

Story::~Story()
{

}
