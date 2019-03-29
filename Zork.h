#include "Header.h"
#include <string.h>
 Room * current_room;

  /*  vector<Item*> items;
    vector<Creature*> creatures;
    vector<Room*> rooms;
    vector<Container*> containers;*/
  string n = "n";
  string s = "s";
  string e = "e";
  string w = "w";


  bool check_cond(Condition * condition,vector<Item *> inventory)
  {
    return true;
  }

  string get_direction(string command)
  {
    if(string(command) == "n")
    {
      return "north";
    }
    else if(string(command) == "s")
    {
      return "south";
    }
    else if(string(command) == "e")
    {
      return "east";
    }
    else if(string(command) == "w")
    {
      return "west";
    }
    else
    {
      return 0;
    }
  }

  Room* assign_room(Room* current_room, string user_in, vector<Room*> rooms)
  {
    for (int i = 0; i < current_room->border.size(); i++)
    {
      // if the border is the same direction
      if (strcmp(get_direction(user_in), current_room->border[i]->direction) ==0)
      {
        // set the value of next room equal to the name of the correct border room
        string next_room = current_room->border[i]->name;
        // iterate through rooms to find the room that matches next room
        for (int i = 0; i < rooms.size(); i++) {
          if (strcmp(rooms[i]->name, next_room)==0)
          {
            current_room = rooms[i];
            cout<<current_room->name<<endl;
            cout<<current_room->description<<endl;
            return current_room;
          }
        }
      }
      else
      {
        cout << "Can't go that way!" << endl;
        return current_room;
      }
    }
  }

    void check_trig(string user_in,vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
  {
    if ( (strcmp(user_in, "n")==0) || (strcmp(user_in, 's')==0) || (strcmp(user_in, 'e')==0) || (strcmp(user_in, 'w')==0) )
    {
      // if the room has a trigger
      if (current_room->trigger)
      {
        // if the user input is equal to the trigger's command
        if (strcmp(user_in, current_room->trigger->command)==0)
        {
          // if the trigger has a condition
          if (current_room->trigger->condition)
          {
            // if the condition is met
            if(check_cond(current_room->trigger->condition, inventory))
            {
              // look through the borders to find the room
              current_room = assign_room(current_room, user_in, rooms);
              return;
            }
          }
        }
      }
      else
      {
        current_room = assign_room(current_room, user_in, rooms);
        return;
      }
    }

    // This is where Tinu's code went
  }


  void zork(vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
  {
    current_room = rooms[0];
    cout<<current_room->name<<endl;
    cout<<current_room->description<<endl;
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
