#ifndef CONTAINER_H_
#define CONTAINER_H_


#include "Condition.h"

  Condition::Condition(xml_node<>* condition)
  {
    owner = new Owner();
    status = new Status();
    xml_node<>* curr = condition->first_node();
    xml_node<>* count = condition->first_node();
    int size = 0;

    // loop to count the number of variables in condition
    while(count)
    {
        size++;
        //cout << size << endl;
        count = count->next_sibling();
    }

    while(curr)
    {
        // if there are 3 variables in condition, you know that object belongs to owner
        if(strcmp(curr->name(),"object") == 0)
        {
          if(size == 3){
            owner->object = curr->value();
          }
          else if(size == 2){
            //cout << "A" << endl;
            status->object = curr->value();
          }
        }

        // status only belongs to the status condition
        if(strcmp(curr->name(),"status") == 0)
        {
          //cout << "B" << endl;
          status->name = curr->value();
        }
        // owner only belongs to the owner condition
        if(strcmp(curr->name(),"owner") == 0)
        {
          owner->name = curr->value();
        }
        // has only belongs to the owner condition
        if(strcmp(curr->name(),"has") == 0)
        {
          owner->has = curr->value();
        }

      curr = curr->next_sibling();
    }
  }
#endif /* CONTAINER_H_ */
