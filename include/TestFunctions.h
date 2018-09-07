#pragma once
#include <string>
#include <vector>

void manualLoadFile(std::string filename);
void loadFileLinesComments(std::string filename, std::vector<std::string> &dest);
void loadFileLines(std::string filename, std::vector<std::string> &dest);
void printLinesTest(std::vector<std::string> &src);
void clearVector(std::vector<std::string> &dest);
void metaInformationTest(std::vector<std::string> &src, std::vector<std::string> &dest);
void loadFileWords(std::string &filename, std::vector<std::string> &dest);
void printWordVector(std::vector<std::string> &content);
void loadFileWordsNoComments(std::string &filename, std::vector<std::string> &dest);
void manualPrintWordVector(std::vector<std::string> &content);
