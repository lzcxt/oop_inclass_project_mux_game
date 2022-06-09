#include "Declaration.h"
void Grid::Affect(Player *p) {
  p->SetAllCoeffients(knowledgeLevelCoefficient, charmLevelCoefficient,
                     healthLevelCoefficient, mentalLevelCoefficient);
  for (const auto e : events) e->Affect(p);
}
void Grid::ExplainYourself() {
  cout << "=== " << identifier << " : " << explanation << " ===" << endl;
  cout << "knowledgeLevelCoefficient : " << knowledgeLevelCoefficient << endl;
  cout << "charmLevelCoefficient     : " << charmLevelCoefficient << endl;
  cout << "healthLevelCoefficient    : " << healthLevelCoefficient << endl;
  cout << "mentalLevelCoefficient    : " << mentalLevelCoefficient << endl;
}
string Grid::GetIdentifier() const { return identifier; }
void Graph::PushinGrid(const Grid &g) {
  identify2grid.insert(make_pair(g.GetIdentifier(), g));
  gridList.push_back(g);
}
void Graph::BuildGraph() {
  int n = gridList.size();
  extraEdge.resize(n);
  fill(extraEdge.begin(), extraEdge.end(), -1);
  for (int i = 2; i < n; ++i) {
    if (extraEdge[i - 1] == -1 && extraEdge[i - 2] == -1 &&
        double(rand()) / RAND_MAX < HAS_BRANCH_PROBILITY) {
      extraEdge[i] = rand() % n;
    }
  }
}
void Graph::DrawGraph(int currentPosition, int printLength) {
  /*
       +---+---+---+
       |LAB NTH  ?
    ---+   +---+---+---+
         *  NTH FLU  ?
    ---+---+---+---+---+
  */
  static string mp[4][20];
  assert(printLength < 15);
  int n = gridList.size();
  currentPosition = (currentPosition + n - 1) % n;
  for (int i = 0; i < printLength; ++i) mp[1][i].clear();
  mp[2][0] = gridList[currentPosition].GetIdentifier();
  for (int i = 1; i < printLength; ++i) {
    currentPosition = (currentPosition + 1) % n;
    mp[2][i] = gridList[currentPosition].GetIdentifier();
    if (extraEdge[currentPosition] != -1) {
      for (int j = 0, jpos = extraEdge[currentPosition];
           j < 1 && i + j < printLength;
           ++j, jpos = (jpos + 1) % currentPosition)
        mp[1][i + j] = gridList[jpos].GetIdentifier();
      mp[1][min(i + 1, printLength)] = " ? ";
    }
  }
  mp[2][printLength] = " ? ";
  for (int i = 0; i <= printLength; ++i) {
    printf(mp[1][i].size() ? "---" : "   ");
    putchar(mp[1][i].size() || mp[1][i + 1].size() ? '+' : ' ');
  }
  puts("");
  for (int i = 0; i <= printLength; ++i) {
    printf("%s", mp[1][i].size() ? mp[1][i].c_str() : "   ");
    putchar(!mp[1][i].size() && mp[1][i + 1].size() ? '|' : ' ');
  }
  puts("");
  for (int i = 0; i <= printLength; ++i) {
    printf("%s", i && !mp[1][i - 1].size() && mp[1][i].size() ? "   " : "---");
    putchar('+');
  }
  puts("");
  for (int i = 0; i <= printLength; ++i) {
    printf(i == 1 ? "\033[0m\033[1;31m%s \033[0m" : "%s ", mp[2][i].c_str());
  }
  puts("");
  for (int i = 0; i <= printLength; ++i) {
    printf("---+");
  }
  puts("");
}
int Graph::GraphSize() const { return gridList.size(); }
void Graph::Affect(int currentPosition, Player *player) {
  gridList[currentPosition].Affect(player);
}
void Graph::InitRound(Player *player, int &position) {
  int n = gridList.size();
  DrawGraph(position);
  string direction = "";
  if (extraEdge[position] != -1) {
    while (!StartWith("up", direction) && !StartWith("right", direction))
      direction = GetInfo<string>("Go u[p] or r[ight]?");
  }
  int chooseStep = 0, minStep = 1, maxStep = max<int>(1, ceil(log(player->GetHealthLevel() / log(1.5))));
  cout<<"Type to select a random number of the steps you'll move between " + to_string(minStep) + " and " + to_string(maxStep)<<endl;
  while (chooseStep < minStep || chooseStep > maxStep)
    {
      
      //chooseStep=GetInfo<int>("Choose the number of the steps you'll move between " + to_string(minStep) + " and " + to_string(maxStep));
      if(maxStep==minStep)
      chooseStep=maxStep;
      else
      chooseStep=rand()%(maxStep-minStep)+minStep;//生成随机数
      
    }
#ifdef __WIN32__
  system("pause");
#endif
    cout<<"You will go "<<chooseStep<<" steps" << endl;
  if (StartWith("up", direction)) {
    position = (extraEdge[position] + chooseStep - 1) % n;
  } else {
    position = (position + chooseStep) % n;
  }
  DrawGraph(position);
}