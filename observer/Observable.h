//
// Created by niels on 4/21/21.
//

#ifndef INC_2DSIDESCROLLER_OBSERVABLE_H
#define INC_2DSIDESCROLLER_OBSERVABLE_H


#include <list>
#include "EntityObserver.h"

class Observable {
public:
    Observable();
    void addObserver(EntityObserver * observer);
    virtual void notifyObservers() {};
    virtual ~Observable();
protected:
    std::list<EntityObserver *> observers;
};


#endif //INC_2DSIDESCROLLER_OBSERVABLE_H
