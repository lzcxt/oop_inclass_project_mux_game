#include "Declaration.h"
void Grid::Affect(Player &p) {
  p.SetAllCoeffients(knowledgeLevelCoefficient, charmLevelCoefficient,
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
string Grid::ShowIdentifier() const {
    return identifier;
}
void Graph::PushinGrid(const Grid &g) { 
    identify2grid.insert(make_pair(g.ShowIdentifier(), g));
    gridList.push_back(g); 
}