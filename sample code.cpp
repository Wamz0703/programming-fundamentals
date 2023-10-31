#include<iostream>
#include<vector>
#include<string>

class Animal {
    protected:
    std::string name;
    public:
    Animal(std::string animalName): name(animalName){}
    virtual void feed(){
        std::cout << name << "has been fed." << std::endl;
    }
    virtual void pet(){
        std::cout << name << "has been petted." << std::endl;
    }
    virtual void makeSound() = 0;
    virtual ~Animal(){} 
};
class Duck : public Animal{
    public:
    Duck(std::string DuckName) : Animal(DuckName) {}
    void makeSound() override {
        std::cout << "Quack!." << std::endl;

    }

};
class Lion : public Animal{
    public:
    Lion(std::string LionName) : Animal(LionName){}
    void makeSound() override {
        std::cout << "Roar." << std::endl;
    }
};
class Monkey : public Animal {
    public :
    Monkey(std::string MonkeyName) : Animal(MonkeyName){}
    void makeSound() override{
        std::cout << "uh uh ah ah." <<std:: endl;
    }
};

int main(){
    std::vector<Animal*> zoo;

    zoo.push_back(new Duck("Daffy."));
    zoo.push_back(new Lion("Simba."));
    zoo.push_back(new Monkey("George."));

    for(Animal* animal : zoo){
        animal -> makeSound();
        animal -> feed();
        animal -> pet();
        std::cout << "--------" <<std::endl;
    }
    for(Animal* animal : zoo){
        delete animal;
    }
    zoo.clear();
    return 0;
}