#include "Trigger.h"



Trigger::Trigger(xml_node<>* trigger){
  xml_node<>* curr = trigger->first_node();

  while(curr)
  {
    if(strcmp(curr->name(),"type") == 0)
    {
      type = curr->value();
    }
    if(strcmp(curr->name(),"print") == 0)
    {
      print = curr->value();
    }
    if(strcmp(curr->name(),"action") == 0)
    {
      action = curr->value();
    }
    if(strcmp(curr->name(),"command") == 0)
    {
      command = curr->value();
    }
    if(strcmp(curr->name(), "condition") == 0)
    {
      xml_node<>* cond_node = curr;
      condition = new Condition(cond_node);
    }



    curr = curr->next_sibling();
  }

}
