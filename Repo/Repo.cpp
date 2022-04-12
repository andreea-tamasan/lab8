#include "Repo.h"
#include <vector>

Repo::Repo() {
    this->numberOfEntities = 0;
}

Repo::~Repo() = default;

void Repo::addItem(Entity &ent) {
    this->entities[this->numberOfEntities++] = ent;

}

int Repo::getSize() const {
    return this->numberOfEntities;
}

vector <Entity> Repo::getAll() const {
    vector <Entity> v;
    v.reserve(numberOfEntities);
    for(int i=0;i<numberOfEntities;i++)
        v.push_back(v[i]);
    return v;
}

void Repo::deleteItem(int id) {
    for(int i=0;i<numberOfEntities;i++)
        if(id == entities[i].getId())
        {
            for (int j = i; j < numberOfEntities-1; j++){
                entities[j] = entities[j+1];
            numberOfEntities--;
            }
        }
}

void Repo::modifyItem(Entity &entOld, Entity &entNew){
    for(int i=0; i<numberOfEntities;i++)
        if(entities[i].getId() == entOld.getId())
            entities[i] = entNew;

}

Entity Repo::getById(int i) {
    for(Entity &E: entities){
        if(E.getId() == i)
            return E;
    }
    throw runtime_error("No entity with that id was found !");
}

Repo &Repo::operator=(const Repo &repo) {
    if(this != &repo)
    {
        this->numberOfEntities= repo.numberOfEntities;
        for(int i = 0; i < numberOfEntities; i++)
            this->entities[i] = repo.entities[i];
    }
    return *this;
}

