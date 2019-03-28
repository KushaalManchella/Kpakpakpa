#include "Container.h"

Container::Container(xml_node<>* container)
{
  xml_node<>* curr = container->first_node();

  while(curr)
  {
    if(strcmp(curr->name(), "accept") == 0) {accept.push_back(curr->value());}
    if(strcmp(curr->name(), "description") == 0) {description = curr->value();}
    if(strcmp(curr->name(), "status") == 0) {status = curr->value();}
    if(strcmp(curr->name(), "name") == 0) {name = curr->value();}
    if(strcmp(curr->name(), "item") == 0){item.push_back(curr->value());}
    curr = curr->next_sibling();
  }
}


Container::~Container(){}
