
#include "Declaration.h"
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