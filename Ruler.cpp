
#include "Declaration.h"
bool Ruler::IsGameOver() { return count >= limit; }
void Ruler::FinalEstimate() {
  cout << "GameOver" << endl;
  // TODO: add more things like announcing the winner.
}
void Ruler::PushinPlayer(Player *p) { players.push_back(make_pair(p, 0)); }
void Ruler::HoldOneRound() {
  static const vector<string> HelpMessage = {"0. h[elp]", "1. l[earn]",
                                             "2. s[how]", "5. e[nd]"};
  ++count;
  cout << "============= " << count << "-th round =============" << endl;
  for (auto &[player, position] : players) {
    player->ResetActionCount();
    cout << player->GetName() << "'s turn" << endl;
    if (player->TellMeYourType() == "Player") {
      graph.InitRound(player, position);
      for (auto s : HelpMessage) cout << s << endl;
      graph.Affect(position, player);
      while (1) {
        string actionChoice = GetInfo<string>("");
        if (StartWith("learn", actionChoice)) {
          if (player->Study(1)) {  // not sure the study reward
            cout << "learning finished" << endl;
          } else {
            cout << "insufficient action point" << endl;
          }
        } else if (StartWith("help", actionChoice)) {
          for (auto s : HelpMessage) cout << s << endl;
        } else if (StartWith("show", actionChoice)) {
          player->ShowInfo();
        } else if (StartWith("end", actionChoice)) {
          puts("");
          break;
        } else if (actionChoice == "ShowPosition") {  // used for debug
          cerr << position << endl;
        } else {
          cout << "invalid action" << endl;
        }
      }
    } else {
      player->AutoAct();
    }
  }
}