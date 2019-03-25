#include "Trigger.h"
using namespace std;
using namespace rapidxml;

class Item{
public:
  Item(xml_node<>*);
  virtual ~Item();
   bool on;
    string name;
    string status;
    string description;
    string writing;
    vector<string> turnon;
    //vector<Trigger*> trigger;


};
