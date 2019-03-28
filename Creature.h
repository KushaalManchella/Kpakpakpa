#ifndef CREATURE_H_
#define CREATURE_H_
#include "Header.h"
#include "Attack.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Creature{
  public:
    Creature(xml_node<>*);
    virtual ~Creature();
    string name;
    string status;
    string description;
    vector<string> vulnerability;
    Attack* attack;
    Trigger* trigger;
};

#endif /* CREATURE_H_ */
