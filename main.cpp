#include "Game.h"
int main()
{
    int tanks = 0;
    std::cout << "How many tanks?: ";
    std::cin >> tanks;
    Game game(1280,720,"Tanks",tanks);
    game.run();
    return 0;
}
