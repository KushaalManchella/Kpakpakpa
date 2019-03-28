#include "Header.h"
  Room * current_room;

  /*  vector<Item*> items;
    vector<Creature*> creatures;
    vector<Room*> rooms;
    vector<Container*> containers;*/

  void check_trig(string user_in)
  {
    if(user_in == "n")
    {
      if(current_room->trigger->command == 'n')
      {
        
      }
      else
      {
          cout<<"there is nothing here"<<std::endl;
      }
    }
    if(user_in == "s")
    {

    }
    if(user_in == "e")
    {

    }
    if(user_in == "w")
    {

    }

    if()
  }


  void zork(string user_in, vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
  {
    current_room = rooms[0];
    while(true)
    {
      getline(cin, u_input);
      if(string(u_input) == "q")
      {
        break;
      }
      check_trig(u_input);




    }
  }
