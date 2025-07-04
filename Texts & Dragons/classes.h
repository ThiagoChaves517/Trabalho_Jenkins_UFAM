//#ifdef CLASSES_H
#define CLASSES_H

class Personagem{
    private:
        int vida;
        int poderDeDano;
    public:
    // Constructor:
        Personagem(int vida, int poderDeDano){
            this->vida = vida;
            this->poderDeDano = poderDeDano;
        }

        void ataquComum(){

        }
};


//#endif