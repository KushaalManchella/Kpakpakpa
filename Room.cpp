#include "Room.h"


Room::Room(xml_node<>* room)
{
  // curr contains the first node in the room xml node
  xml_node<>* curr = room->first_node();
  while(curr)
  {
    Edge* temp_edge = new Edge();  // temp vector that contains name and direction of each border


    // checking if the objects in the room class are present in the xml file.

    if(strcmp(curr->name(), "name") == 0){name = curr->value();}
    if(strcmp(curr->name(), "type") == 0){type = curr->value();}
    if(strcmp(curr->name(), "description") == 0){description = curr->value();}
    if(strcmp(curr->name(), "status") == 0){status = curr->value();}
    if(strcmp(curr->name(), "container") == 0) {container.push_back(curr->value());}
    if(strcmp(curr->name(), "creature") == 0) {creature.push_back(curr->value());}
    if(strcmp(curr->name(), "item") == 0) {item.push_back(curr->value());}
    if (strcmp(curr->name(), "trigger") == 0){trigger = new Trigger(curr);}
    if(strcmp(curr->name(), "border") == 0)
    {
      xml_node<>* bord_node = curr->first_node();
      while(bord_node)
      {
        if(strcmp(bord_node->name(), "direction") == 0)
        {
          temp_edge->direction = bord_node->value();
        }
        if(strcmp(bord_node->name(), "name") == 0)
        {
          temp_edge->name = bord_node->value();
        }
        bord_node = bord_node->next_sibling();
      }
      border.push_back(temp_edge);
    }
    curr = curr -> next_sibling();
  }
}

  Room::~Room(){

  }
