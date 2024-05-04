#ifndef FAVGAMES_H
#define FAVGAMES_H

#include <string>
#include <vector>

void load(std::vector<std::string>& favGames, const std::string& filename);
void save(const std::vector<std::string>& favGames, const std::string& filename);

#endif // FAVGAMES_H