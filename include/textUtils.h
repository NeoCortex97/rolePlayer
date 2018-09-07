#pragma once
#include <string>
#include <vector>

std::string stripcapsule(std::string text, std::string opening, std::string closing);
std::string stripLeadingWs(std::string text);
std::string stripAll(std::string text, char symbol);
std::string stripMultipleWs(std::string text);
void findAllOccurences(std::vector <std::size_t> &positions, std::string &text, std::string pattern);
std::vector <std::string> splitIntoBlocks(std::string text, std::string opening, std::string closing);
void toLowerCase(std::string &text);
void toUpperCase(std::string &text);
