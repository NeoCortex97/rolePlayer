#pragma once

#include "TextUtils.h"
#include "FileUtils.h"
#include <vector>
#include <string>

class Story {
private:
  std::string filename;
  std::string storyName;
  std::string entrypoint;
  std::vector<std::string> lines;
  bool valid;

public:
  Story(std::string filename);
  Story();

  void setFilename(std::string filename);

  std::string getFilename();
  std::string getStoryName();
  std::string getEntrypoint();

  bool testFormat(std::string content);
  std::string findStoryName();
  void load();
  void load(std::string filename);

  virtual ~Story ();
};
