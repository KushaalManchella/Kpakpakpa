#ifndef TRIGGER_H_
#define TRIGGER_H_


#include "Condition.h"
#include "Header.h"

using namespace std;
using namespace rapidxml;

class Trigger{
public:
  Trigger(xml_node<>* );
  virtual ~Trigger(){};
  string type;
  Condition* condition;
  string print;
  string action;
  string command;

};
#endif /* TRIGGER_H_ */
