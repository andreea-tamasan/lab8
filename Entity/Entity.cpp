#include "Entity.h"
#include <cstring>
#include <vector>

using namespace std;

Entity::Entity() {
    this->name = nullptr;
    this->number= 0;
    this->sum = 0;
    this->id = 0;
}

Entity::Entity(int i,const char *name, int number, int sum) {
    this->name = new char[strlen(name)+1];
    strcpy_s(this->name,sizeof this->name,name);
    this->id = i;
    this->number = number;
    this->sum = sum;
}

Entity::Entity(const Entity &ent) {
    this->name = new char[strlen(ent.name)+1];
    this->number = ent.number;
    this->sum = ent.sum;
    this->id = ent.id;
    strcpy_s(this->name,sizeof this->name,ent.name);

}

Entity::~Entity() {
    if(this->name != nullptr)
    {
        this->name = nullptr;
        this->number = 0;
        this->sum = 0;
        this->id = 0;
    }
    delete [] this->name;
}

int Entity::getId() {
    return id;
}
char *Entity::getName() {
    return name;
}

int Entity::getNumber() {
    return number;
}
void Entity::setId(int i) {
    this->id = i;
}

void Entity::setNumber(int num) {
    this->number = num;
}

void Entity::setName(const char *n) {
    this->name = new char[strlen(n)+1];
    strcpy_s(this->name,sizeof this->name,n);
}
int Entity::getSum() {
    return sum;
}

void Entity::setSum(int s) {
    this->sum= s;
}

Entity &Entity::operator=(const Entity &ent) {
    if(this->name != nullptr){
        delete[] this->name;
    }
    this->name = new char[strlen(ent.name) +1];
    strcpy(this->name, ent.name);
    //this->setName(ent.name);
    this->setNumber(ent.number);
    this->setSum(ent.sum);
    this->setId(ent.id);
}

bool Entity::isValid() {
    //char *s2= (char*)"curent";
    //char *s1=(char*)"apa";
    //char *s0=(char*)"gaz";
    //char *s3=(char*)"caldura";
    //char *s4=(char*)"internet";
    //char *s5=(char*)"electricitate";
    const char *s2= "curent";
    const char *s1="apa";
    const char *s0="gaz";
    const char *s3="caldura";
    const char *s4="internet";
    const char *s5="electricitate";
    vector<const char*>utilitati= {s0,s1,s2,s3,s4,s5};
    for (auto &s: utilitati) {
        if (strcmp(s, name) == 0 ) {
            return true;
        }
    }
}



bool Entity::operator==(const Entity &ent) {
    return this->sum == ent.sum && this->number == ent.number && this->id == ent.id && strcmp(this->name, ent.name)==0;
}
