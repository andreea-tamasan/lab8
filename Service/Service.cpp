#include "../Repo/Repo.h"
#include "Service.h"

Service::Service()= default;

Service::Service(Repo &r) {
    this->repo = r;
}

Service::~Service() {}

void Service::create(Entity& E) {
    repo.addItem(E);
}

void Service::update(Entity E_old,Entity E_new) {
    repo.modifyItem(E_old,E_new);
}

void Service::delete1(Entity E) {
    repo.deleteItem(E.getId());
}

vector<Entity> Service::get_all() {
    vector<Entity> entities = this->repo.getAll();
    return entities;
}

Entity Service::getById(int id) {
    return repo.getById(id);
}





