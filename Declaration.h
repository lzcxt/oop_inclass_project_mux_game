#ifndef DEC_H
#define DEC_H
#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Player {
 protected:
  string name;
  int actionCount;
  int actionCountMax;

  int knowledgeLevel;
  int charmLevel;
  int healthLevel;
  int mentalLevel;

 public:
  Player(const string &name, const int *a)
      : name(name),
        actionCountMax(5),
        knowledgeLevel(a[0]),
        charmLevel(a[1]),
        healthLevel(a[2]),
        mentalLevel(a[3]) {}
  void ResetActionCount();  // actionCount = actionCountMax;
  void AddAll(int a, int b, int c, int d);
  void AddKnowledgeLevel(int num);
  void AddCharmLevel(int num);
  void AddHealthLevel(int num);
  void AddMentalLevel(int num);
  int GetActionCount();
  int GetCharmLevel();
  int GetHealthLevel();
  int GetKnowledgeLevel();
  int GetMentalLevel();
  const string &GetName();
  bool Study(int studyCost);
  virtual string TellMeYourType();
  virtual void AutoAct();
};
class Computer : public Player {
 protected:
 public:
  Computer(const string &name, const int *a) : Player(name, a) {}
  virtual string TellMeYourType();
  virtual void AutoAct();
};
class Ruler {
 private:
  int limit;
  int count;
  vector<Player *> players;

 public:
  Ruler(int limit) : limit(limit), count(0) {}
  void HoldOneRound();
  void FinalEstimate();
  bool IsGameOver();
  void PushinPlayer(Player *p);
};
class Event {
 public:
  void Flu(Player &player);
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