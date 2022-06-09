
#include "Declaration.h"
bool Ruler::IsGameOver() { return count >= limit; }
void Ruler::FinalEstimate() {
  cout << "GameOver" << endl;
  for (auto &[player, position] : players) {
    if (player->TellMeYourType() == "Player") {
      if (this->count >= 9999999) {
        cout << "Because of your bad health situation, you have to quit "
                "university and stay in hospital.What a pity!"
             << endl;
        return;
      }
      if (player->GetHealthLevel() < 7) {
        cout << "You fail in the health test in the end of a semester!" << endl;
      }
      if (player->GetKnowledgeLevel() < 10) {
        cout << "You fail in the final academic exam !" << endl;
      }
      if (player->GetCharmLevel() > 12) {
        cout << "You become a social star in the university!" << endl;
      }
      if (player->GetMentalLevel() > 10) {
        cout << "You stay positive and happy after one semester!" << endl;
      }
    }
  }
}
void Ruler::PushinPlayer(Player *p) { players.push_back(make_pair(p, 0)); }
void Ruler::HoldOneRound() {
  static const vector<string> HelpMessage = {
      "0. h[elp]", "1. l[earn]", "2. s[how]", "3. d[oExcercise]", "5. e[nd]"};
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
        } else if (StartWith("doExcercise", actionChoice)) {
          if (player->Excercise(3)) {  // not sure the study reward
            cout << "excercise finished" << endl;
          } else {
            cout << "insufficient action point" << endl;
          }
        } else if (StartWith("help", actionChoice)) {
          for (auto s : HelpMessage) cout << s << endl;
        } else if (StartWith("show", actionChoice)) {
          player->ShowInfo();
        } else if (StartWith("end", actionChoice)) {
          puts("");
          if (player->GetHealthLevel() < -5 || player->GetMentalLevel() < -5) {
            cout << "You have too low health level or mental level, you lose!"
                 << endl;
            this->count = 9999999;
          }
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