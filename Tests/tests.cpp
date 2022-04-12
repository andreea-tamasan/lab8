#include <cassert>
#include <cstring>
#include "tests.h"
#include "../Entity/Entity.h"
#include "../Repo/Repo.h"
#include "../Service/Service.h"

void testConstructor(){
    Entity ent;
    assert(ent.getName() == nullptr);
    assert(ent.getSum() == 0);
    assert(ent.getNumber() == 0);
}

void testSetterAndGetter(){
    Entity ent;
    char* s= (char*)"gaz";
    ent.setSum(100);
    ent.setNumber(25);
    ent.setName(s);
    assert(strcmp(ent.getName(),s) == 0);
    assert(ent.getNumber() == 25);
    assert(ent.getSum() == 100);
}

void testRepo(){
    Repo repo;
    Entity ent0,ent1,ent2;
    char* s0= (char*)"gaz";
    ent0.setSum(100);
    ent0.setNumber(25);
    ent0.setName(s0);
    char* s1= (char*)"apa";
    ent1.setSum(100);
    ent1.setNumber(25);
    ent1.setName(s1);
    char* s2= (char*)"curent";
    ent2.setSum(100);
    ent2.setNumber(25);
    ent2.setName(s2);
    repo.addItem(ent0);
    repo.addItem(ent1);
    repo.addItem(ent2);
    assert(repo.getSize()==3);
}

void testDeleteEntities(){
    Repo repo;
    char* s2= (char*)"curent";
    char* s1= (char*)"apa";
    char* s0= (char*)"gaz";
    char* s3 =(char*)"electricitate";
    Entity ent1(0,s0,25,150);
    Entity ent2(1,s2,24,90);
    Entity ent3(2,s1,23,76);
    Entity ent4(3,s3,22,100);
    repo.addItem(ent1);
    repo.addItem(ent2);
    repo.addItem(ent3);
    repo.addItem(ent4);
    repo.deleteItem(3);
    //assert(repo.getSize() == 3);
}

void testModifyItem(){
    Repo repo;
    const char* s2= "curent";
    const char* s1= "apa";
    const char* s0= "gaz";
    const char* s3 ="electricitate";
    Entity ent1(0,s0,25,150);
    Entity ent2(1,s2,24,90);
    Entity ent3(2,s1,23,76);
    Entity ent4(3,s3,22,100);
    repo.addItem(ent1);
    repo.addItem(ent2);
    repo.addItem(ent3);
    repo.modifyItem(ent1,ent4);
    assert(repo.getById(1) == ent2);
    assert(repo.getById(3) == ent4);
}

void testCreateService(){
    Repo R;
    Service S(R);
    const char* s0 = "apa";
    Entity E(0,s0,5,200);
    S.create(E);
    assert(S.get_all().size()==1);

}

void testUpdateService(){
    Repo Ru;
    Service Su(Ru);
    const char* s0= "gaz";
    const char* s1= "apa";
    Entity E1(1,s0,5,200);
    Entity E2(1,s1,7,300);
    Su.create(E1);
    assert(Su.get_all().size()==1);
    Su.update(E1,E2);
    assert(Su.getById(1)==E2);
}

void testDeleteSevice(){
    Repo R;
    Service Sd(R);
    const char* s0= "gaz";
    const char* s2= "apa";
    const char* s1= "apa";
    Entity E1(0,s0,25,150);
    Entity E2(1,s2,24,90);
    Entity E3(2,s1,23,76);
    Sd.create(E1);
    Sd.create(E2);
    Sd.create(E3);
    assert(Sd.get_all().size()==3);
    Sd.delete1(E2);
    assert(Sd.get_all().size()==2);
}

void tests(){
    testConstructor();
    testSetterAndGetter();
    testRepo();
    testDeleteEntities();
    testModifyItem();
    testCreateService();
    testUpdateService();
    //testDeleteSevice();
}