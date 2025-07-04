#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout, std::cin, std::endl, std::string;

//Links of the arts: https://ascii.co.uk/art/knights and https://ascii.co.uk/art/dragon

class Item{
    private:
        int DamagePoints;
        int HealingPoints;
        string SecondaryEffect;
    public:
        //Class Constructor:
        Item(){
            DamagePoints = 0;
            HealingPoints = 0;
            SecondaryEffect = "Normal";
        }
        Item(int damagePoints, int healingPoints, string secondaryEffect){
            DamagePoints = damagePoints;
            HealingPoints = healingPoints;
            SecondaryEffect = secondaryEffect;
        }

        //Sets and Gets:
        void setDamagePoints(int dp){
            DamagePoints = dp;
        }
        int getDamagePoints(){
            return DamagePoints;
        }

        void setHealingPoints(int hp){
            HealingPoints = hp;
        }
        int getHealingPoints(){
            return HealingPoints;
        }

        void setSecondaryEffect(string sf){
            SecondaryEffect = sf;
        }
        string getSecondaryEffect(){
            return SecondaryEffect;
        }
};

class Bomb : public Item{
    private:
        int BombClock;
    public:
        Bomb(int damagePoints, int healingPoints, string secondaryEffect) : Item(damagePoints, healingPoints, secondaryEffect){
            BombClock = 0;
        }

        void setBombClock(int bombClock){
            BombClock = bombClock;
        }
        int getBombClock(){
            return BombClock;
        }
};

class Character{
    private:
        int Health;
        int Stamina;
        string Status;
        Item Items[4];
        int itemsNum;
    public:
        //Class Constructor:
        Character(int hp, int st){
            Health = hp;
            Stamina = st;
            Status = "Normal";
            itemsNum = 0;
        }

        //Sets and Gets:
        void setHealth(int hp){
            Health = hp;
        }
        int getHealth(){
            return Health;
        }

        void setStamina(int st){
            Stamina = st;
        }
        int getStamina(){
            return Stamina;
        }

        void setStatus(string st){
            Status = st;
        }
        string getStatus(){
            return Status;
        }

        void setItem(Item item){
            if(itemsNum < 4){
                Items[itemsNum] = item;
                itemsNum++;
            }
        }
        Item getItem(int index){
            for(int i = 0; i < itemsNum; i++){
                if(i == index-1){
                    return Items[index-1];
                }
            }

            return Item(0,0,"NULL");
        }
        
        //Class Methods:
        void attack(Character &c){
            c.setHealth(c.getHealth() - 1);
            if(Health < 10 && Stamina < 10){
                Stamina++;
            }
        }

        void beHurt(int damage){
            Health = Health - damage;
        }
};

class Knight : public Character {
    public:
        //Class Constructor: 
        Knight(int hp, int st) : Character(hp, st){}

        //Class Methods:
        void flameBladeAttack(Character &c){
            c.setHealth(c.getHealth() - 2);
            setStamina(getStamina() - 1);
        }
        void healingMagic(){
            if(getHealth() < 10){
                setHealth(getHealth() + 2);
            }
            
            if(getHealth() > 10){
                setHealth(10);
            }

            setStamina(getStamina() - 1);
        }
};

void menuInicial(Character c1, Character c2);

void menuDeMagia(Character c1, Character c2);

void menuDeItens(Character c1, Character c2);



int main(){
    int option1 = 0, option2 = 0;
    int battleTurns = 1;

    //Setting characters:
    Knight knight(10, 10);
    Character dragon(25, 10);

    //Setting the knight items:
    Bomb bigBomb(3, 0, "3 Turns Delay");
    Item thunderSpear(1, 0, "Paralyzed");

    knight.setItem(bigBomb);
    knight.setItem(thunderSpear);

    do{
        srand(time(nullptr));
        menuInicial(knight, dragon);
        cin >> option1;

        switch (option1)
        {
        case 1: //The Knight Attacks!
            knight.attack(dragon);
            break;
        case 2: //The Menu of Magics is opened!
            if(knight.getStamina() > 0){
                menuDeMagia(knight, dragon);
                cin >> option2;
                
                switch (option2)
                {
                case 1:
                    knight.flameBladeAttack(dragon);
                    break;
                case 2:
                    knight.healingMagic();
                    break;
                default:
                    break;
                }
            }
            else{
                cout << endl;
                cout << "                                                                     Insufficient stamina!" << endl;
            }

            break;
        case 3: //The Menu of Items is opened!
            menuDeItens(knight, dragon);
            cin >> option2;
            switch (option2)
            {
            case 1:                
                if(knight.getItem(option2).getSecondaryEffect() == "3 Turns Delay"){
                    bigBomb.setBombClock(battleTurns + 3); //The Big Bomb is set!
                }

                break;
            case 2:
                if(knight.getItem(option2).getSecondaryEffect() == "Paralyzed"){
                    if((rand() % 5) == 1){
                        dragon.setStatus("Paralyzed");
                    }
                }
                knight.attack(dragon);

                break;
            default:
                break;
            }

            break;
        default: //Default Option!
            break;
        }

        if(dragon.getStatus() == "Paralyzed"){
            if((rand() % 10) <= 5){
                dragon.attack(knight);
            }
        }
        else{
            dragon.attack(knight);
        }

        battleTurns++;
        
        if(bigBomb.getBombClock() == battleTurns){
            dragon.beHurt(knight.getItem(1).getDamagePoints());
            bigBomb.setBombClock(0);
        }
        
    } while (option1 != 4 && knight.getHealth() > 0 && dragon.getHealth() > 0);
    

    string END;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    if(knight.getHealth() <= 0){
    cout << "                                                  NO SIGN OF YOU IS FIND                              " << endl;
    cout << "                                            BUT THE ASHES OF A LOST KINGDOM...                        " << endl; 
    cout << "                                                        YOU LOST!                                     " << endl;    
    }
    else{
    cout << "                                                     CONGRATULATIONS!                                 " << endl;
    cout << "                                       THE WORLD WAS SAVED FROM THE EMINENT DARKNESS                  " << endl;   
    cout << "                                             ONCE MORE, BUT SOMETHING SAYS THAT                       " << endl;  
    cout << "                                                   IT IS NOT THE END...                               " << endl;
    cout << "                                                        YOU WON!                                      " << endl;   
    }
    cout << "                                                                                                " << endl;
    cout << "                                                                                                " << endl;
    cout << "                                                                                                " << endl;
    cout << "                                                                                                " << endl;
    cout << "                                                    ULTRALINK STUDIOS                                 " << endl;
    cout << "                                               - Making Dreams Come True -                            " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                             < Thank you for Playing (\\'w'/) >                        " << endl;
    cout << "                                                   < Till next time! >                                " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                       31/07/2023                                    " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cout << "                                                                                 " << endl;
    cin >> END;
}



void menuInicial(Character c1, Character c2){
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "                                                                 \\  Gragonir, The Ancient Dragon  \\"<< endl;
    cout << "                                                                  \\  HP: ";
    for(int i = 0; i < c2.getHealth(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c2.getHealth())/25)*100 << "%" << endl;
    if(c2.getStatus() == "Paralyzed"){
        cout << "                                                                           (PARALYZED)"<< endl;
    }
    cout << "                                                                        .     ." << endl;
    cout << "                                                                         \\   //  .''-.     .-." << endl;
    cout << "                                                                          \\ //.'     '-.-'   '." << endl;
    cout << "                                                                     ~__ (    ) __~            '.    ..~" << endl;
    cout << "                                                                     (  . (||)    . )     .-''-.  '..~~~~" << endl;
    cout << "                                                                      | | (--)---| |'-..-'BP    '-..-~'" << endl;
    cout << "                  |                                                  ^^^   ''   ^^^" << endl;
    cout << "                  |                                                              " << endl;
    cout << "                  + \\                                                           " << endl;
    cout << "                  (\\.G_.*=.                                                     " << endl;
    cout << "                   `(H'/.\\|                    |  1: Attack      2: Magic  |    " << endl;
    cout << "                .>' (_--.                      |  3: Itens       4: Run    |    " << endl;
    cout << "                 _=/d   ,^\\                                                     " << endl;
    cout << "                ~~ \\)-'   '                                                     " << endl;
    cout << "                  / |                                                            " << endl;
    cout << "                 '  '       a:f                                                  " << endl;
    cout << "         \\ HP: ";
    for(int i = 0; i < c1.getHealth(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c1.getHealth())/10)*100 << "%" << endl;
    cout << "          \\ ST: ";
    for(int i = 0; i < c1.getStamina(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c1.getStamina())/10)*100 << "%" << endl;
    cout << endl;
    cout << endl << endl << endl << endl << endl;
    cout << "          Choose an option: ";
}

void menuDeMagia(Character c1, Character c2){
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;    
    cout << endl;
    cout << "                                                                 \\  Gragonir, The Ancient Dragon  \\"<< endl;
    cout << "                                                                  \\  HP: ";
    for(int i = 0; i < c2.getHealth(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c2.getHealth())/25)*100 << "%" << endl;
    if(c2.getStatus() == "Paralyzed"){
        cout << "                                                                           (PARALYZED)"<< endl;
    }
    cout << "                                                                        .     ." << endl;
    cout << "                                                                         \\   //  .''-.     .-." << endl;
    cout << "                                                                          \\ //.'     '-.-'   '." << endl;
    cout << "                                                                     ~__ (    ) __~            '.    ..~" << endl;
    cout << "                                                                     (  . (||)    . )     .-''-.  '..~~~~" << endl;
    cout << "                                                                      | | (--)---| |'-..-'BP    '-..-~'" << endl;
    cout << "                  |                                                  ^^^   ''   ^^^" << endl;
    cout << "                  |                                                              " << endl;
    cout << "                  + \\                                                           " << endl;
    cout << "                  (\\.G_.*=.                                                     " << endl;
    cout << "                   `(H'/.\\|                    |   1: Flame Blade       2: Healing Magic   |    " << endl;
    cout << "                .>' (_--.                      | (doubles the damage)     (restores 2 HP)  |    " << endl;
    cout << "                 _=/d   ,^\\                                                     " << endl;
    cout << "                ~~ \\)-'   '                                                     " << endl;
    cout << "                  / |                                                            " << endl;
    cout << "                 '  '       a:f                                                  " << endl;
    cout << "         \\ HP: ";
    for(int i = 0; i < c1.getHealth(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c1.getHealth())/10)*100 << "%" << endl;
    cout << "          \\ ST: ";
    for(int i = 0; i < c1.getStamina(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c1.getStamina())/10)*100 << "%" << endl;
    cout << endl;
    cout << endl << endl << endl << endl << endl;
    cout << "          Choose an option: ";
}

void menuDeItens(Character c1, Character c2){
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;    
    cout << endl;
    cout << "                                                                 \\  Gragonir, The Ancient Dragon  \\"<< endl;
    cout << "                                                                  \\  HP: ";
    for(int i = 0; i < c2.getHealth(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c2.getHealth())/25)*100 << "%" << endl;
    if(c2.getStatus() == "Paralyzed"){
        cout << "                                                                           (PARALYZED)"<< endl;
    }
    cout << "                                                                        .     ." << endl;
    cout << "                                                                         \\   //  .''-.     .-." << endl;
    cout << "                                                                          \\ //.'     '-.-'   '." << endl;
    cout << "                                                                     ~__ (    ) __~            '.    ..~" << endl;
    cout << "                                                                     (  . (||)    . )     .-''-.  '..~~~~" << endl;
    cout << "                                                                      | | (--)---| |'-..-'BP    '-..-~'" << endl;
    cout << "                  |                                                  ^^^   ''   ^^^" << endl;
    cout << "                  |                                                              " << endl;
    cout << "                  + \\                                                           " << endl;
    cout << "                  (\\.G_.*=.                                                     " << endl;
    cout << "                   `(H'/.\\|                    |       1: Big Bombs               2: Volt Spear         |" << endl;
    cout << "                .>' (_--.                      |  (explodes after 3 turns)     (enemies loose 1 HP)     |" << endl;
    cout << "                 _=/d   ,^\\                    |    (enemies loose 3 HP)    (possibly paralizing them)  |" << endl;
    cout << "                ~~ \\)-'   '                                                     " << endl;
    cout << "                  / |                                                            " << endl;
    cout << "                 '  '       a:f                                                  " << endl;
    cout << "         \\ HP: ";
    for(int i = 0; i < c1.getHealth(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c1.getHealth())/10)*100 << "%" << endl;
    cout << "          \\ ST: ";
    for(int i = 0; i < c1.getStamina(); i++){
        cout << "#";
    }
    cout << " \\ " << (float(c1.getStamina())/10)*100 << "%" << endl;
    cout << endl;
    cout << endl << endl << endl << endl << endl;
    cout << "          Choose an option: ";
}