#ifdef __WIN32__
#include <windows.h>
#endif
#include <cstdlib>

#include "Declaration.h"
static const int graphSize = 20; 
static const int charactorTypeNum = 3;
static const string charactorType[charactorTypeNum] = {
    "体育特长生", 
    "学霸",
    "交际达人"
  };
static const int charactorValue[charactorTypeNum][4] = {
    {2, 2, 4, 2}, 
    {4, 2, 2, 2}, 
    {2, 4, 4, 2}
  };
static const Grid gridNothing(
    "NTH", 
    "This grid contain nothing",
    1, 1, 1, 1,
    {}
  );
static const Flu flu;
static const Grid gridHasFlu(
    "FLU", 
    "This grid has flu, flu will affect your health point", 
    1, 1, 1, 1,
    {&flu}
  );
static const Grid gridLibrary(
    "LIB",
    "This grid is library, you can learn better",
    2, 1, 1, 1, 
    {}
  );
int main() {
  srand(time(0));
#ifdef __WIN32__
  SetConsoleOutputCP(65001);
#endif
  cout << "Game Start, Choose Your Charactor Please" << endl;
  for (int i = 0; i < charactorTypeNum; ++i)
    cout << "press " << i << " for " << charactorType[i] << endl;
  int charactorCategory = GetInfo<int>("");
  if (charactorCategory < 0 || charactorCategory >= charactorTypeNum) return 0;
  Player player("YOU", charactorValue[charactorCategory]);
  Graph g;
  for (int i = 0; i < graphSize; ++i) {
    if (rand() % 3) g.PushinGrid(gridNothing);
    else if (rand() % 2) g.PushinGrid(gridLibrary);
    else g.PushinGrid(gridHasFlu);
  }
  Ruler ruler(100, g);
  Computer comp1("Computer1-LearningBaka", charactorValue[1]);
  ruler.PushinPlayer(&player);
  ruler.PushinPlayer(&comp1);
  while (!ruler.IsGameOver()) {
    ruler.HoldOneRound();
  }
  ruler.FinalEstimate();
#ifdef __WIN32__
  system("pause");
#endif
}