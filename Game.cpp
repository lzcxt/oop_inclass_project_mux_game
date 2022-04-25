#ifdef __WIN32__
#include <windows.h>
#endif
#include <cstdlib>

#include "Declaration.h"

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
  Ruler ruler(100);
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