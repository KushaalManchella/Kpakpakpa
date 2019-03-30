#include "Item.h"
using namespace std;

Item::Item(xml_node<>* node)
{
  on  = false;
  // Step into the nodes of the item
  xml_node<>* nodes = node->first_node();
  turnon = new Turnon();
  turnon->action = "nothing";
  // Iterate through siblings of item
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
    if(strcmp(nodes->name(), "writing") == 0)
    {
      writing = nodes->value();
    }
    if(strcmp(nodes->name(), "turnon") == 0)
    {
      xml_node<>* nodal = nodes->first_node();
      while(nodal)
      {
        if( strcmp(nodal->name(),"print") == 0){
          turnon->print = nodal->value();
        }
        if( strcmp(nodal->name(),"action") == 0){
          turnon->action = nodal->value();
        }
        nodal = nodal->next_sibling();
      }
    }
  /*  if(strcmp(nodes->name(), "trigger") == 0)
    {
      Trigger.pushback(nodes.value);
    }
*/
    nodes = nodes->next_sibling();
  }
}


  Item::~Item(){}
