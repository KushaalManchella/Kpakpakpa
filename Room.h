#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Room{
    public:
      Room(xml_node<>* );
      virtual ~Room();
      string name;
      string status;
      string type;
      string description;
      vector<vector<string> > border;
      vector<string> container;
      vector<string> item;
      vector<string> creature;
    //vector<Trigger*> trigger;



};
