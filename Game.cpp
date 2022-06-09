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
// the order is knowledge, charm, health, mental
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
static const SportsMeeting sportsMeeting;
static const FallInLove fallInLove;
static const RandomEvent randomEvent;
static const Grid gridHasSportsMeeting(
    "SPM", 
    "This grid has sports meeting, you have an opportunity to get better if you are healthy enough", 
    1, 1, 1, 1,
    {&sportsMeeting}
  );
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
  static const Grid gridDate(
    "DAT",
    "This grid is time to date, you may advance your love process or just fail. You can be more charming but become less concentrated on study",
    0.5, 2, 1, 1, 
    {&fallInLove}
  );
    static const Grid gridRandom(
    "RAN",
    "This grid is random events. You can encounter some events there",
    1, 1, 1, 1, 
    {&randomEvent}
  );
const int SEED1 = 666;
int main() {
  srand(SEED1);
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
    int r=rand()%10;
    if (r<3) g.PushinGrid(gridNothing);
    else if (r<4) g.PushinGrid(gridDate);
    else if(r<6) g.PushinGrid(gridHasSportsMeeting);
    else if(r<8)g.PushinGrid(gridLibrary);
    else if(r<9) g.PushinGrid(gridHasFlu);
    else g.PushinGrid(gridRandom);
  }
  g.BuildGraph();
  Ruler ruler(10, g);  // hold at most 10 rounds on the graph g
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