#include <iostream>
#include <string>

int main() 
{

    std::string name = "Benjie";
    int n;
    int PLAYER_HP = 100;
    int MAX_HP = 100;
    int MP = 15;
    int MP_CAST = 20;
    int SLIME_HP = 80;
    int SLIME_DAMAGE = 10;
    
    bool isDefend = false;
    bool isQuit = false;
    
    while ((PLAYER_HP > 0) && (SLIME_HP > 0)) {
        std::cout << "===== RPG BATTLE SYSTEM =====\n";

        std::cout << "PLAYER: " << name << "\n";
        std::cout << "HP: " << PLAYER_HP << "\n";
        std::cout << "MP: " << MP << "\n";

        std::cout << "\n";

        std::cout << "ENEMY: Slime\n";
        std::cout << "HP: " << SLIME_HP << "\n";

        std::cout << "\n";
        std::cout << "===== ACTION MENU =====\n";

        std::cout << "[1] Attack\n";
        std::cout << "[2] Defend\n";
        std::cout << "[3] Use Potion\n";
        std::cout << "[4] Use Magic\n";
        std::cout << "[5] Run Away\n";
        std::cout << "\n";

        std::cout << "Choose your action:";
        std::cin >> n; 
        std::cout << "\n";

        switch (n) {
            case 1:
                std::cout << "You deal damage 20!\n";                
                SLIME_HP -= 20;
            break;

            case 2:
                std::cout << "DEFEND\n";
                PLAYER_HP -= 0;
                isDefend = true;
            break;

            case 3:
                if (PLAYER_HP > MAX_HP) {
                    PLAYER_HP = MAX_HP;
                }
                if (PLAYER_HP == MAX_HP) {
                    std::cout << "POTION CANNOT BE USED!\n";
                } else { 
                    PLAYER_HP += 20;
                    std::cout << "USE POTION\n";
                }
            break;
            
            case 4:

                if (MP < 0) {
                    MP = 0;
                }

                if (MP_CAST > MP) {
                    std::cout << "Not Enought Mana!\n";
                    std::cout << "\n";
                } else {
                    SLIME_HP -= 40;
                    MP -= MP_CAST;
                    std::cout << "USE MAGIC! damage of 40\n";
                }
            break;

            case 5:
                std::cout << "Run Away!\n";
                isQuit = true;
            break;

            default:
                std::cout << "Invalid Actions!\n";
            break;
        }
        std::cout << "\n";
        if (SLIME_HP < 0) {
            SLIME_HP = 0;
        }
        if (SLIME_HP > 0) {
            if (!isDefend) {
                if (!isQuit) {
                    std::cout << "Enemy Attack! 10\n";
                    PLAYER_HP -= SLIME_DAMAGE;
                }
                //-50 < 0
                if (PLAYER_HP < 0) {
                    PLAYER_HP = 0;
                }

            } else {
                std::cout << "Player used Defend\n";
                PLAYER_HP -= 0;
                isDefend = false;
            }
        }

        if (isQuit == true) {
            std::cout << "GAME OVER!";        
            break;
        }
    }

    if (PLAYER_HP <= 0) {
        std::cout << "Player Won!\n";
    }
    return 0;
}
