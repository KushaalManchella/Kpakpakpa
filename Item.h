
#ifndef ITEM_H_
#define ITEM_H_

#include "Header.h"
#include "Trigger.h"
using namespace std;
using namespace rapidxml;

class Item{
public:
    typedef struct _turnon{
      string print;
      string action;
    } Turnon;
    Item(xml_node<>*);
    virtual ~Item();
    bool on;
    string name;
    string status;
    string description;
    string writing;
    Trigger* trigger;
    Turnon* turnon;

};
#endif /* ITEM_H_ */
