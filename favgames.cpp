#include "favgames.h"
#include <fstream>

using namespace std;

void load(vector<string> &favGames, const string &filename) {
  ifstream file(filename);
  string game;
  while (getline(file, game)) {
    favGames.push_back(game);
  }
  file.close();
}

void save(const vector<string> &favGames,
          const string &filename) {
  ofstream file(filename);
  for (const auto &game : favGames) {
    file << game << endl;
  }
  file.close();
}