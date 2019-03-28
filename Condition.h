#ifndef CONDITION_H_
#define CONDITION_H_


#include "Header.h"

using namespace std;
using namespace rapidxml;

class Condition{
public:
    Condition(xml_node<> *);
    virtual ~Condition(){};
    typedef struct _owner{
      string object;
      string has;
      string name;
    } Owner;

    typedef struct _status{
      string object;
      string name;
    } Status;

    Status* status;
    Owner* owner;



};
#endif /* CONDITION_H_ */
