#ifndef ROOM_H_
#define ROOM_H_


#include "Condition.h"
#include "Header.h"
#include "Trigger.h"

using namespace std;
using namespace rapidxml;

class Room{
public:
      typedef struct _edge{
        string direction;
        string name;
      } Edge;

      Room(xml_node<>* );
      virtual ~Room();
      string name;
      string status;
      string type;
      string description;
      vector<Edge* > border;
      vector<string> container;
      vector<string> item;
      vector<string> creature;
      Trigger* trigger;
};

#endif /* ROOM_H_ */
