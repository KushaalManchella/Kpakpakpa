#ifndef CONTAINER_H_
#define CONTAINER_H_
#include "Condition.h"
#include "Header.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;



class Container{
public:
    Container(xml_node<>*);
    virtual ~Container();
    string name;
    string status;
    string description;
    vector<string> accept;
    vector<string> item;
    Trigger* trigger;
};

#endif /* CONTAINER_H_ */
