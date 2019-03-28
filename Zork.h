#include "Header.h"
 Room * current_room;

  /*  vector<Item*> items;
    vector<Creature*> creatures;
    vector<Room*> rooms;
    vector<Container*> containers;*/
  string n = "n";
  string s = "s";
  string e= "e";
  string w = "w";


  bool check_cond(Condition * condition,vector<Item *> inventory)
  {
    return true;
  }
    void check_trig(string user_in,vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
  {
    if(user_in == n)
    {
      if(current_room->trigger->command == n)
      {
        if(current_room->trigger->condition == NULL)
        {
          for(int i = 0; i < current_room->border.size(); i++)
            {
              if(current_room->border[i]->direction == "north")
              {
                for(int i = 0; i < rooms.size();i++)
                {
                  if(rooms[i]->name == current_room->border[i]->name)
                  {
                    current_room = rooms[i];
                  }
                }
              }
            }
        }
       else
        {
          if(check_cond(current_room->trigger->condition,inventory))
          {
            cout<<current_room->trigger->print<<std::endl;
          }
        }
      }
      else
      {
          cout<<"there is nothing here"<<std::endl;
      }
    }
    if(user_in ==  s)
    {
      if(current_room->trigger->command ==  s)
      {
        cout<<"south we go"<<std::endl;
      }
      else
      {
          cout<<"there is nothing here"<<std::endl;
      }
    }
    if(user_in == e)
    {
      if(current_room->trigger->command == e)
      {
        cout<<"east we go"<<std::endl;
      }
      else
      {
          cout<<"there is nothing here"<<std::endl;
      }
    }
    if(user_in==w)
    {
      if(current_room->trigger->command == w)
      {
        cout<<"west we go"<<std::endl;
      }
      else
      {
          cout<<"there is nothing here"<<std::endl;
      }
    }


  }


  void zork(vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
  {
    current_room = rooms[0];
    cout<<current_room->description<<std::endl;
    while(true)
    {
      string u_input;
      getline(cin, u_input);
      if(string(u_input) == "q")
      {
        break;
      }
      check_trig(u_input,inventory,items, creatures,rooms,containers);




    }
  }
