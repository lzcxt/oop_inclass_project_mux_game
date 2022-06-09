#ifndef DEC_H
#define DEC_H
#include <time.h>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;
class Player {
 protected:
  string name;
  int actionCount;
  int actionCountMax;

  double knowledgeLevel;
  double charmLevel;
  double healthLevel;
  double mentalLevel;

  double knowledgeLevelCoefficient;
  double charmLevelCoefficient;
  double healthLevelCoefficient;
  double mentalLevelCoefficient;
  int LoveStage;
 public:
  Player(const string &name, const int *a)
      : name(name),
        actionCountMax(5),
        knowledgeLevel(a[0]),
        charmLevel(a[1]),
        healthLevel(a[2]),
        mentalLevel(a[3]),
        knowledgeLevelCoefficient(1),
        charmLevelCoefficient(1),
        LoveStage(0),
        healthLevelCoefficient(1),
        mentalLevelCoefficient(1) {}
  void ResetActionCount();  // actionCount = actionCountMax;
  void AddAllAttributes(int k, int c, int h, int m);
  void SetAllCoeffients(double kc, double cc, double hc, double mc);
  void AddKnowledgeLevel(int amount);
  void AddCharmLevel(int amount);
  void AddHealthLevel(int amount);
  void AddMentalLevel(int amount);
  int GetActionCount();
  double GetCharmLevel();
  double GetHealthLevel();
  double GetKnowledgeLevel();
  double GetMentalLevel();
  int GetLoveStage();
  void SetLoveStage(int newStage);
  const string &GetName();
  bool Study(int studyCost);
  bool Excercise(int excerciseCost);
  virtual string TellMeYourType();
  virtual void AutoAct();
  void ShowInfo();
};
class Computer : public Player {
 protected:
 public:
  Computer(const string &name, const int *a) : Player(name, a) {}
  virtual string TellMeYourType();
  virtual void AutoAct();
};
class Event {
 public:
  virtual void Affect(Player *player) const = 0;
};
class Grid {
 private:
  string identifier;
  string explanation;
  double knowledgeLevelCoefficient;
  double charmLevelCoefficient;
  double healthLevelCoefficient;
  double mentalLevelCoefficient;
  vector<const Event *> events;

 public:
  Grid(const string id, const string exp, double knowledgeCoe, double charmCoe, double healthCoe,
       double mentalCoe, const vector<const Event *> &evs)
      : identifier(id),
        explanation(exp),
        knowledgeLevelCoefficient(knowledgeCoe),
        charmLevelCoefficient(charmCoe),
        healthLevelCoefficient(healthCoe),
        mentalLevelCoefficient(mentalCoe),
        events(evs) {
    assert((int)id.size() == 3);
  }
  string GetIdentifier() const;
  void ExplainYourself();
  void Affect(Player *player);
};
class Graph {
 private:
  vector<int> extraEdge;
  vector<Grid> gridList;
  map<string, Grid> identify2grid;
 public:
  static constexpr double HAS_BRANCH_PROBILITY = 0.4;
  void PushinGrid(const Grid &grid);
  void DrawGraph(int currentPosition, int printLength = 7);
  void Affect(int currentPosition, Player *player);
  void BuildGraph();
  int GraphSize() const;
  void InitRound(Player *player, int &position);
};
class Flu : public Event {
 public:
  virtual void Affect(Player *player) const;
};
class SportsMeeting : public Event {
 public:
  virtual void Affect(Player *player) const;
};
class FallInLove : public Event {
 public:
  virtual void Affect(Player *player) const;
};
class RandomEvent : public Event {
 public:
  virtual void Affect(Player *player) const;
};
class Ruler {
 private:
  int limit;
  int count;
  Graph graph;
  vector<pair<Player *, int> > players;

 public:
  Ruler(int limit, const Graph &g) : limit(limit), count(0), graph(g) {}
  void HoldOneRound();
  void FinalEstimate();
  bool IsGameOver();
  void PushinPlayer(Player *p);
};
template <class T>
T GetInfo(const string &guideMessage) {
  if (guideMessage.size()) cout << guideMessage << endl;
  cout << ">>> ";
  T s;
  cin >> s;
  return s;
}
bool StartWith(const string &u, const string &v);
void SleepBySecond(double second);
#endif