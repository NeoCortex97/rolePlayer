#pragma once

#include <string>
#include <vector>

std::string loadToString(std::string &filename, std::string commentMark = "#", bool stripComments = false);
std::string loadToStringSkipComments(std::string &filename, std::string commentMark = "#");
std::string loadToStringKeepComments(std::string &filename);

void loadToLineVector(std::string &filename, std::vector<std::string> &dest, std::string commentMark = "#", bool stripComments = false);
void loadToLineVectorSkipComments(std::string &filename, std::vector<std::string> &dest, std::string commentMark = "#");
void loadToLineVectorKeepComments(std::string &filename, std::vector<std::string> &dest);

void loadToWordVector(std::string &filename, std::vector<std::string> &dest, std::string commentMark = "#", bool stripComments = false);
void loadToWordVectorSkipComments(std::string &filename, std::vector<std::string> &dest, std::string commentMark = "#");
void loadToWordVectorKeepComments(std::string &filename, std::vector<std::string> &dest);

void printFileContentsFromLineVector(std::vector<std::string> &contents);
void printFileContentsFromWordVector(std::vector<std::string> &contents, unsigned int lineWidth = 80);

void stringVectorToString(std::vector<std::string> &content, std::string &result);
