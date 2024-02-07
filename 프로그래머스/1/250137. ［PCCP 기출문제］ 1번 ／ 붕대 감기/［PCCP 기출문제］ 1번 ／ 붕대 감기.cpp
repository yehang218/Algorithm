#include <string>
#include <vector>
#include <iostream>

using namespace std;

int maxHP = 0;

int playerDamaged(int health, int damage)
{
    health = health - damage;

    if (health <= 0)
        return -1;
    else
        return health;
}

int playerHPPlus(int health, int x)
{
    health = health + x;

    if (health >= maxHP)
    {
        health = maxHP;
    }
    return health;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int attackArrTemp = 0;
    int conSuccess = 0;

    maxHP = health;

    for (int i = 1; i <= attacks[attacks.size() - 1][0]; i++)
    {
        if (attacks[attackArrTemp][0] == i)
        {
            conSuccess = 0;
            health = playerDamaged(health, attacks[attackArrTemp][1]);
            attackArrTemp++;
            if (health == -1)
                return -1;
        }
        else
        {
            conSuccess++;
            health = playerHPPlus(health, bandage[1]);
            if (conSuccess == bandage[0])
            {
                conSuccess = 0;
                health = playerHPPlus(health, bandage[2]);
            }
        }
    }
    return health;
}