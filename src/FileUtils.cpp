#include "FileUtils.h"
#include "TextUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::string loadToString(std::string &filename, std::string commentMark, bool stripComments)
{
  if (stripComments)
  {
    return loadToStringSkipComments(filename, commentMark);
  }
  else
  {
    return loadToStringKeepComments(filename);
  }
}

std::string loadToStringKeepComments(std::string &filename)
{
  std::ifstream input(filename);
  std::string result = "", line;

  while (getline(input, line))
  {
    result += line;
  }

  input.close();

  return result;
}

std::string loadToStringSkipComments(std::string &filename, std::string commentMark)
{
  std::ifstream input(filename);
  std::string result = "", line;

  while (getline(input, line))
  {
    if (!isMarked(line, commentMark))
    {
      result += line;
    }
  }

  input.close();

  return result;
}

void loadToLineVector(std::string &filename, std::vector<std::string> &dest, std::string commentMark, bool stripComments)
{
  if (stripComments)
  {
    loadToLineVectorSkipComments(filename, dest, commentMark);
  }
  else
  {
    loadToLineVectorKeepComments(filename, dest);
  }
}

void loadToLineVectorKeepComments(std::string &filename, std::vector<std::string> &dest)
{
  std::ifstream input(filename);
  std::string line;

  while (getline(input, line))
  {
    if (line.size() > 0) {
      dest.push_back(line);
    }
  }

  input.close();
}

void loadToLineVectorSkipComments(std::string &filename, std::vector<std::string> &dest, std::string commentMark)
{
  std::ifstream input(filename);
  std::string line;

  while (getline(input, line))
  {
    if (!isMarked(line, commentMark))
    {
      if (line.size() > 0) {
        if(line.find(commentMark, 0) == std::string::npos)
        {
          dest.push_back(line);
        }
        else
        {
          dest.push_back(line.substr(0, line.find(commentMark, 0)));
        }
      }
      //std::cout << line.size() << " ";
    }
  }


  input.close();
}

void printFileContentsFromLineVector(std::vector<std::string> &contents)
{
  for (size_t i = 0; i < contents.size(); i++)
  {
    std::cout << contents[i] << '\n';
  }
}

void printFileContentsFromWordVector(std::vector<std::string> &contents, unsigned int lineWidth)
{
  unsigned int width = lineWidth;
  for(unsigned int i = 0; i < contents.size(); i++)
  {
    if (width <= contents[i].size())
    {
      std::cout << '\n';
      width = lineWidth;
    }
    std::cout << contents[i] << ' ';
    width -= contents[i].size() + 1;
  }
  std::cout << '\n';
}

void loadToWordVector(std::string &filename, std::vector<std::string> &dest, std::string commentMark, bool stripComments)
{
  if (stripComments) {
    //std::cout << "loading without comments!\n";
    loadToWordVectorSkipComments(filename, dest, commentMark);
  }
  else
  {
    loadToWordVectorKeepComments(filename, dest);
  }
}

void loadToWordVectorSkipComments(std::string &filename, std::vector<std::string> &dest, std::string commentMark)
{
  std::ifstream input(filename);
  std::string line;
  std::stringstream s;
  int lineCont = 0;

  //std::cout << "entering while loop\n";
  while (getline(input, line))
  {
    //std::cout << "Current Line: " << line << '\n';
    ++lineCont;
    if (!isMarked(line, commentMark))
    {
      //std::cout << "current line is no whole line comment.\n";
      if(line.find(commentMark, 0) == std::string::npos)
      {
        //std::cout << "current line contains no comment\n";
        //std::cout << "Line: " << stripLeadingWs(line) << '\n';
        //s << stripLeadingWs(line);
        std::stringstream sstr(stripLeadingWs(line));
        //std::cout << s.str() << '\n';
        //std::cout << sstr.str() << '\n';
        std::string word;
        while (sstr >> word)
        {
          //std::cout << "Destination size: " << dest.size() << '\n';
          //std::cout << s.str();
          //std::cout << word;
          dest.push_back(word);
        }
      }
      else
      {
        std::cout << "Found inline comment in line " << lineCont << " at " << line.find(commentMark, 0) << '\n';
        std::cout << "Text is: " << stripLeadingWs(line.substr(0, line.find(commentMark, 0))) << '\n';
        std::stringstream csstr(stripMultipleWs(line.substr(0, line.find(commentMark, 0))));
        std::string word2;
        while (csstr >> word2) {
          dest.push_back(word2);
        }
      }
    }
    else
    {
      //std::cout << "Current line is whole line comment.\nAdding no words to vector\n";
    }
    //std::cout << "======================\n";
  }
  input.close();
}

void loadToWordVectorKeepComments(std::string &filename, std::vector<std::string> &dest)
{
  //std::cout << "load file To Word Vector Keep Comments" << '\n';

  std::cout << filename << '\n';
  std::ifstream input(filename);
  std::string wort;

  if (!input.good()) {
    std::cerr << "Could not open file" << '\n';
  }
  else
  {
    //std::cout << "Start reading file..." << '\n';
    while (input >> wort)
    {
      //std::cout << "Word is read..." << '\n';
      dest.push_back(wort);
      //std::cout << wort << '\n';
    }
  }

  input.close();
}

void stringVectorToString(std::vector<std::string> &content, std::string &result)
{
  result = "";
  for (size_t i = 0; i < content.size(); i++) {
    result += content[i];
  }
}
