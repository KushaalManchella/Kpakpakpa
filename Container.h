#include "Trigger.h"
using namespace std;
using namespace rapidxml;

class Container{
    Container(xml_node<>* );
    virtual ~Container();
    string name;
    string status;
    string description;
    vector<string> accept;
    vector<string> item;
    //vector<Trigger*> trigger;


};
