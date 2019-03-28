#ifndef ATTACK_H_
#define ATTACK_H_

#include "Header.h"
#include "Condition.h"
using namespace std;
using namespace rapidxml;

class Attack{
public:
   Attack(xml_node<>*);
   virtual ~Attack();
   string action;
   string print;
   Condition * condition;
};

#endif /* ATTACK_H_ */
