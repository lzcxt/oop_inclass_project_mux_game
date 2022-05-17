
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
      graph.DrawGraph(position);
      int chooseStep = 0, minStep = 1, maxStep = max<int>(1, ceil(log(player->GetHealthLevel() / log(1.5))));
      while (chooseStep < minStep || chooseStep > maxStep)
        chooseStep = GetInfo<int>("Choose the number of the steps you'll move between " + to_string(minStep) + " and " + to_string(maxStep));
      position = (position + chooseStep) % graph.GraphSize();
      graph.DrawGraph(position);
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
        } else {
          cout << "invalid action" << endl;
        }
      }
    } else {
      player->AutoAct();
    }
  }
}