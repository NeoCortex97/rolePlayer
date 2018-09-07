#include <string>
#include <vector>
#include "TextUtils.h"
#include <iostream>

std::string stripCapsule(std::string &text, std::string opening, std::string closing)
{
	std::size_t start = text.find(opening) + opening.size();
	std::size_t end = text.find(closing);
	std::string result = "";

	if(opening == "")
		result = text.substr(0, end);
	else if(closing == "")
		result = text.substr(start);
	else if(start != std::string::npos && end != std::string::npos)
		result = text.substr(start, end - start);
	return result;
}

std::size_t findFirstNonWsChar(std::string &text)
{
  std::size_t pos = 0;

  if(text.size() > 0)
  {
    // advances until it sees the first non-whitespace character.
    while(text.at(pos) == 32 || text.at(pos) == 9)
	  {
		  ++pos;
  	}
  }
	return pos;
}

std::string stripLeadingWs(std::string text)
{
	//unsigned int start = 0;

  if(text.size() > 0)
	  return text.substr(findFirstNonWsChar(text));
	else
	  return "";
}

std::string stripMultipleWs(std::string text)
{
	std::string result = "";

  if(text.size() > 0)
  {
    for(unsigned int i = 0; i < text.size() - 1; ++i)
    {
	    if(!(text.at(i) == ' ' && text.at(i + 1) == ' '))
	    {
		    result += text.at(i);
	    }
    }

	  if(text.at(text.size() - 1) != ' '){
		  result += text.at(text.size() - 1);
	  }
	}

	return result;
}

void findAllOccurences(std::vector <std::size_t> &positions, std::string &text, std::string pattern)
{
	std::size_t pos = text.find(pattern, 0);
	std::size_t old;
	while(pos != std::string::npos)
	{
		old = pos;
		//	std::cout << "Found at: " << pos << std::endl;
		positions.push_back(pos);
		pos = text.find(pattern, pos);
		if(old == pos && pos < text.size())
			pos = text.find(pattern, pos + 1);
		else if(pos == text.size() - 1)
		break;
	}
}

std::vector <std::string> getTags(std::string text, std::string opening, std::string closing)
{
	std::vector <std::size_t> openings;
	findAllOccurences(openings, text, opening);

	std::vector <std::size_t> closings;
	findAllOccurences(closings, text, closing);

	unsigned int size = std::min(openings.size(), closings.size());
	std::vector <std::string> result;
	for(unsigned int i = 0; i < size; ++i)
	{
		result.push_back(text.substr(openings[i], closings[i] - openings[i] + closing.size()));
	}

	return result;
}

void toLowerCase(std::string &text)
{
	for(unsigned int i = 0; i < text.size(); ++i)
	{
		if(text.at(i) >= 'A' && text.at(i) <= 'Z')
		{
			text.at(i) += 32; // 32 is the difference between "A" and "a"
		}
	}
}

void toUpperCase(std::string &text)
{
	for(unsigned int i = 0; i < text.size(); ++i)
	{
		if(text.at(i) >= 'a' && text.at(i) <= 'z')
		{
			text.at(i) -= 32; // 32 is the difference between "A" and "a"
		}
	}
}

std::string stripAll(std::string text, char symbol)
{
	std::string result = "";

	for(unsigned int i = 0; i < text.size() - 1; ++i)
	{
		if(text.at(i) != symbol)
		{
			result += text.at(i);
		}
	}

	if(text.at(text.size() - 1) != symbol){
		result += text.at(text.size() - 1);
	}

	return result;
}

std::string getBetweenTags(std::string &text, std::string &openTag, std::string &closeTag, int start)
{
  std::size_t startPos = text.find(openTag, start) + openTag.size();
  std::size_t length = text.find(closeTag, start) - startPos;

  return text.substr(startPos,length);
}


bool isPair(std::string first, std::string second, std::string lBorder, std::string rBorder, char closingSign)
{
  std::string tmpFirst = stripCapsule(first, lBorder, rBorder);
  std::string tmpSecond = stripCapsule(second, lBorder, rBorder);
//  std::cout << "tmpFirst: " << tmpFirst << " tmpSecond: " << tmpSecond << std::endl;

  //std::cout << "test if tags are opening and closing . . .\n";
  if(tmpFirst.find(closingSign, 0) == std::string::npos && tmpSecond.find(closingSign, 0) != std::string::npos)
  {
//    std::cout << "Performing strip all / . . .\n";
    if(tmpSecond.find(tmpFirst, 0) != std::string::npos)
    {
//      std::cout << "Found Pair!\n";
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

//bool isComment(std::string &text, std::string commentMark)
bool isMarked(std::string &text, std::string mark)
{
  if(text.size() > 0)
  {
    //std::cout << findFirstNonWsChar(text) << "   ";
    if(text.substr(findFirstNonWsChar(text), mark.size()) == mark)
    {
      //std::cout << "Found comment!\n";
      return true;
    }
    else
    {
      return false;
    }
  }
	return false;
}

void killComments(std::string &text, std::string commentMark)
{
  std::vector <std::size_t> positions;
  findAllOccurences(positions, text, "\n");

  std::size_t start = 0;
  std::size_t ende;
  std::string line;
  std::string result = "";

  for(unsigned int i = 0; i < positions.size(); i++)
  {
    ende = positions[i];
    line = text.substr(start, ende - start);
    start = ende;

    std::cout << line;

    if(!isMarked(line, commentMark))
    {
    std::cout << "This line is not a comment!\n";
      result += line;
    }
  }
  text = result;
}

void getMarkedLines(std::vector<std::string> &contents, std::vector<std::string> &dest, std::string mark)
{
	for (size_t i = 0; i < contents.size(); i++) {
		if (isMarked(contents[i], mark)) {
			dest.push_back(contents[i]);
		}
	}
}

bool contains(std::string &text, std::string query)
{
	if (text.find(query, 0) != std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}
