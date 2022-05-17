#include "Declaration.h"

bool StartWith(const string &u, const string &v) {
  if (v.empty() || u.size() < v.size()) return 0;
  return u.substr(0, v.size()) == v;
}
void SleepBySecond(double second) {
  int ed = clock() + second * CLOCKS_PER_SEC;
  while (clock() < ed)
    ;
}

#pragma region  // Player
void Player::AddAllAttributes(int k, int c, int h, int m) {
  AddKnowledgeLevel(k);
  AddCharmLevel(c);
  AddHealthLevel(h);
  AddMentalLevel(m);
}
void Player::SetAllCoeffients(double kc, double cc, double hc, double mc) {
  knowledgeLevelCoefficient = kc;
  charmLevelCoefficient = cc;
  healthLevelCoefficient = hc;
  mentalLevelCoefficient = mc;
}
void Player::AddKnowledgeLevel(int amount) {
  knowledgeLevel += amount * knowledgeLevelCoefficient;
  if (knowledgeLevel < 0) knowledgeLevel = 0;
}
void Player::AddCharmLevel(int amount) {
  charmLevel += amount * charmLevelCoefficient;
}
void Player::AddHealthLevel(int amount) {
  healthLevel += amount * healthLevelCoefficient;
  if (healthLevel < 0) healthLevel = 0;
}
void Player::AddMentalLevel(int amount) {
  mentalLevel += amount * mentalLevelCoefficient;
}
int Player::GetCharmLevel() { return charmLevel; }
int Player::GetKnowledgeLevel() { return knowledgeLevel; }
int Player::GetMentalLevel() { return mentalLevel; }
int Player::GetHealthLevel() { return healthLevel; }
int Player::GetActionCount() { return actionCount; }
void Player::ResetActionCount() { actionCount = actionCountMax; }
const string &Player::GetName() { return name; }
string Player::TellMeYourType() { return "Player"; }
void Player::AutoAct() {}
bool Player::Study(int studyCost) {
  if (actionCount < studyCost)
    return false;
  else {
    actionCount -= studyCost;
    AddKnowledgeLevel(2);
    AddHealthLevel(-1);
    return true;
  }
}
void Player::ShowInfo() {
  printf("========== %s's info ==========\n", name.c_str());
  printf("%-20s: %d (max: %d)\n", "ActionCount",          actionCount, actionCountMax);
  printf("%-20s: %d (x%.3lf)\n", "CharmLevel",            charmLevel, charmLevelCoefficient);
  printf("%-20s: %d (x%.3lf)\n", "HealthLevel",           healthLevel, healthLevelCoefficient);
  printf("%-20s: %d (x%.3lf)\n", "KnowledgeLevel",        knowledgeLevel, knowledgeLevelCoefficient);
  printf("%-20s: %d (x%.3lf)\n", "MentalLevel",           mentalLevel, mentalLevelCoefficient);
}
#pragma endregion

string Computer::TellMeYourType() { return "Computer"; }
void Computer::AutoAct() {
  while (actionCount > 1) {
    puts("haha, I am learing but you are playing");
    Study(1);
    SleepBySecond(0.5);
  }
  puts("");
}
