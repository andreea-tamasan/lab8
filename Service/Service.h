#ifndef LAB7_SERVICE_H
#define LAB7_SERVICE_H
#include <iostream>
#include "../Repo/Repo.h"

class Service {
private:
    Repo repo;
public:
    Service();
    Service(Repo& r);
    void create(Entity& E);
    void delete1(Entity E);
    vector <Entity> get_all();
    void update(Entity E_old,Entity E_new);
    virtual ~Service();
    Entity getById(int id);
};


#endif //LAB7_SERVICE_H
