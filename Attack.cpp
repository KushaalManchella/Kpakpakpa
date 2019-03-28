#include"Attack.h"


using namespace std;

Attack::Attack(xml_node<>* node)
{
  xml_node<>* nodes = node->first_node();
  // iterate through xml nodes
  while(nodes)
  {
    // if action put string in action
    if(strcmp(nodes->name(), "action") == 0)
    {
      action = nodes->value();
    }
    // if print put string in print
    if(strcmp(nodes->name(), "print") == 0)
    {
      print = nodes->value();
    }
    // if condition create condition object
    if(strcmp(nodes->name(), "condition") == 0)
    {
      condition = new Condition(nodes);
    }
    nodes = nodes->next_sibling();
  }
}
  Attack::~Attack(){}
