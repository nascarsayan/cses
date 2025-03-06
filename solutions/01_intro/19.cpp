#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <utility>
#include <tuple>

using namespace std;

const array<pair<int, int>, 8> dirs = {
    pair{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

const unordered_map<char, int> ch2dirIdx = {
    {'U', 1}, {'R', 3}, {'D', 5}, {'L', 7}};

using Board = vector<vector<int>>;
using BoardIdx = pair<int, int>;

class PathFinder
{
private:
  Board &board;
  const string &path;

  bool exist(const BoardIdx &idx) const
  {
    auto [r, c] = idx;
    return (0 <= r && r < 7 && 0 <= c && c < 7);
  }

  template <typename... Args>
  bool exist(const BoardIdx &idx, const Args &...rest) const
  {
    return exist(idx) && exist(rest...);
  }

  bool visited(const BoardIdx &idx) const
  {
    if (!exist(idx))
      return true;
    return board[idx.first][idx.second] == 1;
  }

  void setSquare(const BoardIdx &idx, int val)
  {
    board[idx.first][idx.second] = val;
  }

public:
  PathFinder(Board &b, const string &p) : board(b), path(p) {}

  int dfs(const BoardIdx &boardIdx, int pathIdx)
  {
    if (!exist(boardIdx))
      return 0;
    if (visited(boardIdx))
      return 0;
    if (pathIdx == path.length())
    {
      return (boardIdx == BoardIdx{6, 0}) ? 1 : 0;
    }
    if (boardIdx == BoardIdx{6, 0})
      return 0;

    auto [r, c] = boardIdx;
    vector<BoardIdx> N;
    N.reserve(8);

    for (const auto &[dr, dc] : dirs)
    {
      N.emplace_back(r + dr, c + dc);
    }

    // Check orthogonal conditions
    if (visited(N[1]) == visited(N[5]) && visited(N[3]) == visited(N[7]))
    {
      if (visited(N[1]) != visited(N[3]))
      {
        return 0;
      }
    }

    // Check diagonal conditions
    for (int diag = 0; diag < 7; diag += 2)
    {
      if (exist(N[diag]) && visited(N[diag]) &&
          !visited(N[(diag + 7) % 8]) && !visited(N[diag + 1]))
      {
        return 0;
      }
    }

    setSquare(boardIdx, 1);
    char ch = path[pathIdx];
    vector<BoardIdx> nextBoardIdcs;

    if (ch != '?')
    {
      nextBoardIdcs = {N[ch2dirIdx.at(ch)]};
    }
    else
    {
      nextBoardIdcs = {N[1], N[3], N[5], N[7]};
    }

    int res = 0;
    for (const auto &nextBoardIdx : nextBoardIdcs)
    {
      if (visited(nextBoardIdx))
        continue;
      res += dfs(nextBoardIdx, pathIdx + 1);
    }

    setSquare(boardIdx, 0);
    return res;
  }
};

int main()
{
  string path;
  getline(cin, path);

  Board board(7, vector<int>(7, 0));
  PathFinder finder(board, path);

  int result = finder.dfs({0, 0}, 0);
  cout << result << endl;

  return 0;
}