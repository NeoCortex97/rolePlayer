#include <iostream>
#include <iomanip>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>
#include "TermUtils.h"

int getTermWidth()
{
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_col;
}

int getTermHeight()
{
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return w.ws_row;
}

void printMenuBar(std::vector <std::string> entrys, unsigned int active)
{
  int width = getTermWidth() / entrys.size();
  int rest = getTermWidth() % width;

  for(unsigned int i = 0; i < entrys.size(); ++i)
  {
    if(i == active)
      std::cout << "\033[31;47;7m";
    else
      std::cout << "\033[31;47;2m";

    std::cout << std::setw(width) << std::left << entrys.at(i) << "\033[0m";
  }

  std::cout << "\033[0m\033[32;47;2m" << std::setw(rest) << " " << "\033[0m\n";
}

void printMaxWidth(std::string text, unsigned int width)
{
  std::cout << text.substr(0, width - 3);
  if (text.size() > width){
    std::cout  << "...";
  }
}

std::string color(int fg, int bg, int deco)
{
  std::string result = "\033[";
  if(fg > 0)
  {
    result += '3';
    result += (((fg - 1) % 8) + '0');
  }

  if(bg > 0)
  {
    result += ";4";
    result += (((bg - 1) % 8) + '0');
  }

  if(deco >= 0)
  {
    result += ';';
    result += (deco % 9 + '0');
  }

  result += 'm';

  return result;
}
