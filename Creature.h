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
    //string attack;
    //vector<Trigger*> trigger;
};
