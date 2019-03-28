#include "Creature.h"


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
      description = nodes->value();
    }
    // vector of vulnerabilities
    if(strcmp(nodes->name(), "vulnerability") == 0)
    {
      vulnerability.push_back(nodes->value());
    }
    // create a new attack object
    if(strcmp(nodes->name(), "attack") == 0)
    {
      //xml_node<> *attack_node = nodes;
      attack = new Attack(nodes);
    }
    // create a new trigger object
    if(strcmp(nodes->name(), "trigger") == 0)
    {
      //xml_node<> *trigg_node = nodes;
      trigger = new Trigger(nodes);
    }

    nodes = nodes->next_sibling();
  }
}

  Creature::~Creature(){};
