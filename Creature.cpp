#include "Creature.h"

/*
Creature::Creature(xml_node<> *node ){
  xml_node<>* nodes = node->first_node();
  while(nodes)
  {
    if(strcmp(nodes->name(), "name") == 0)
    {
    name = nodes->value();
    }
    if(strcmp(nodes->name(), "status") == 0)
    {
      status = nodes->value();
    }
    if(strcmp(nodes->name(), "description") == 0)
    {
    description = nodes->value();;
    }
    if(strcmp(nodes->name(), "vulnerability") == 0)
    {
      vulnerability = nodes->value();
    }
    if(strcmp(nodes->name(), "turnon") == 0)
    {
      on = true;
      xml_node<>* nodal = nodes->first_node();
      while(nodal)
      {
        turnon.push_back(nodal->value());
      }
      nodal = nodal->next_sibling();
    }
  if(strcmp(nodes->name(), "trigger") == 0)
    {
      Trigger.pushback(nodes.value);
    }

    nodes = nodes->next_sibling();
  }

}
*/
