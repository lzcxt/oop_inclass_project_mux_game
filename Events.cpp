#include "Declaration.h"

void Flu::Affect(Player *player) const {
  int randNum = 100 * (double(rand()) / (RAND_MAX + 1ll));
  bool flag = false;
  if (player->GetHealthLevel() < 50) {
    if (randNum < 80) flag = true;
  } else if (player->GetHealthLevel() < 100) {
    if (randNum < 50) flag = true;
  } else if (player->GetHealthLevel() < 150) {
    if (randNum < 20) flag = true;
  }
  if (flag) {
    player->AddHealthLevel(-2);
    player->AddMentalLevel(-1);
  }
}