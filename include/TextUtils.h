#pragma once
#include <string>
#include <vector>

// Formatting functions
std::string stripCapsule(std::string &text, std::string opening, std::string closing);
void killComments(std::string &text, std::string commentMark);
std::string stripAll(std::string text, char symbol);
std::string stripMultipleWs(std::string text);
std::string stripLeadingWs(std::string text);
void toLowerCase(std::string &text);
void toUpperCase(std::string &text);

// Information extraction functions
void getMarkedLines(std::vector<std::string> &contents, std::vector<std::string> &dest, std::string mark = "#");
std::string getBetweenTags(std::string &text, std::string &openTag, std::string &closeTag, int start);
void findAllOccurences(std::vector <std::size_t> &positions, std::string &text, std::string pattern);
std::vector <std::string> getTags(std::string text, std::string opening, std::string closing);
void concatVector(std::string &result, std::vector<std::string> content);

// Testing funtions
bool isPair(std::string a, std::string b, std::string lBorder, std::string rBorder, char closingSign);
bool isMarked(std::string &text, std::string mark);
bool contains(std::string &text, std::string query);
//bool isComment(std::string &text, std::string commentMark);
