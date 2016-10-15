#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

static const int world_x = 10; // 世界のx方向サイズ
static const int world_y = 10; // 世界のy方向サイズ
static const int x_length = 5; // もらえる土地のx方向サイズ
static const int y_length = 5; // もらえる土地のy方向サイズ

struct point {
  int x = 0;
  int y = 0;
  int n_gold = 0;
};

std::vector<std::string > inputGoldMountain()
{
  std::vector<std::string> world(10);
  for (int i = 0; i < world_y; ++i) std::getline(std::cin, world[i]);
  return world;
}

void outputPoint(point p)
{
  std::cout << "{" << "\"x\":" << p.x << ","
                   << "\"y\":" << p.y << ","
                   << "\"g\":" << p.n_gold << "}";
}

//! 金額を計算する関数
/*!
 * \param x もらう土地の左上のx座標
 * \param y もらう土地の左上のy座標
 * \param world 世界
 * \return Goldの数
 */
int calcGold(int x, int y, const std::vector<std::string> &world)
{
  if (x < 0 || x >= (world_x - x_length + 1) ||
      y < 0 || y >= (world_y - y_length + 1))   // もらう土地が世界に収まらない
    return 0;

  int gold = 0;
  for (int i = y; i < y + y_length; ++i)
    for (int j = x; j < x + x_length; ++j)
      if (world[i][j] == 'G') ++gold;
  return gold;
}

//! 最大Gとなるポイントを探す
/*!
 * 素朴なアルゴリズムのため、速度は気にしていない。
 *
 * \param world 世界
 * \return 最大Gとなる座標とそのGの値
 */
point serchMaxGold(const std::vector<std::string> &world)
{
  point p;
  for (int i = 0; i < world_x - x_length + 1; ++i) {
    for (int j = 0; j < world_y - y_length + 1; ++j) {
      int new_gold = calcGold(i, j, world);
      if (new_gold > p.n_gold) {
        p.n_gold = new_gold;
        p.x = i;
        p.y = j;
      }
    }
  }
  return p;
}

int main()
{
  std::vector<std::string> world = inputGoldMountain();
  point result = serchMaxGold(world);
  outputPoint(result);
  return 0;
}
