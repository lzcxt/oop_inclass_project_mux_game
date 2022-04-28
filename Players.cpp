#include "Declaration.h"

bool StartWith(const string &u, const string &v) {
  if (v.empty() || u.size() < v.size()) return 0;
  return u.substr(0, v.size()) == v;
}
void SleepBySecond(double second) {
  int ed = clock() + second * CLOCKS_PER_SEC;
  while (clock() < ed);
}

#pragma region  // Player
void Player::AddAll(int a, int b, int c, int d) {
  AddKnowledgeLevel(a);
  AddCharmLevel(b);
  AddHealthLevel(c);
  AddMentalLevel(d);
}
void Player::AddKnowledgeLevel(int num) {
  knowledgeLevel += num;
  if (knowledgeLevel < 0) knowledgeLevel = 0;
}
void Player::AddCharmLevel(int num) { charmLevel += num; }
void Player::AddHealthLevel(int num) {
  healthLevel += num;
  if (healthLevel < 0) healthLevel = 0;
}
void Player::AddMentalLevel(int num) { mentalLevel += num; }
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

bool Ruler::IsGameOver() { return count >= limit; }
void Ruler::FinalEstimate() {
  cout << "GameOver" << endl;
  // TODO: add more things like announcing the winner.
}
void Ruler::PushinPlayer(Player *p) { players.push_back(p); }
void Ruler::HoldOneRound() {
  static const vector<string> HelpMessage = {"0. h[elp]", "1. l[earn]",
                                             "2. s[how]", "5. e[nd]"};
  ++count;
  cout << "============= " << count << "-th round =============" << endl;
  for (auto p : players) {
    p->ResetActionCount();
    cout << p->GetName() << "'s turn" << endl;
    if (p->TellMeYourType() == "Player") {
      for (auto s : HelpMessage) cout << s << endl;
      while (1) {
        string actionChoice = GetInfo<string>("");
        if (StartWith("learn", actionChoice)) {
          if (p->Study(1)) {  // not sure the study reward
            cout << "learning finished" << endl;
          } else {
            cout << "insufficient action point" << endl;
          }
        } else if (StartWith("help", actionChoice)) {
          for (auto s : HelpMessage) cout << s << endl;
        } else if (StartWith("show", actionChoice)) {
          printf("========== %s's info ==========\n", p->GetName().c_str());
          printf("%-20s: %d\n", "AcctionAccount", p->GetActionCount());
          printf("%-20s: %d\n", "CharmLevel", p->GetCharmLevel());
          printf("%-20s: %d\n", "HealthLevel", p->GetHealthLevel());
          printf("%-20s: %d\n", "KnowledgeLevel", p->GetKnowledgeLevel());
          printf("%-20s: %d\n", "AcctionAccount", p->GetMentalLevel());
        } else if (StartWith("end", actionChoice)) {
          puts("");
          break;
        } else {
          cout << "invalid action" << endl;
        }
      }
    } else {
      p->AutoAct();
    }
  }
}
