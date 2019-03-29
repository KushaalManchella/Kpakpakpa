// #include "Header.h"
// #include <string.h>
//  Room * current_room;
//
//   /*  vector<Item*> items;
//     vector<Creature*> creatures;
//     vector<Room*> rooms;
//     vector<Container*> containers;*/
//   string n = "n";
//   string s = "s";
//   string e = "e";
//   string w = "w";
//
//
//   bool check_cond(Condition * condition,vector<Item *> inventory)
//   {
//     return true;
//   }
//
//   string get_direction(string command)
//   {
//     if(string(command) == "n")
//     {
//       return "north";
//     }
//     else if(string(command) == "s")
//     {
//       return "south";
//     }
//     else if(string(command) == "e")
//     {
//       return "east";
//     }
//     else if(string(command) == "w")
//     {
//       return "west";
//     }
//     else
//     {
//       return 0;
//     }
//   }
//
//   Room* assign_room(Room* current_room, string user_in, vector<Room*> rooms)
//   {
//     for (int i = 0; i < current_room->border.size(); i++)
//     {
//       // if the border is the same direction
//       if (strcmp(get_direction(user_in), current_room->border[i]->direction) ==0)
//       {
//         // set the value of next room equal to the name of the correct border room
//         string next_room = current_room->border[i]->name;
//         // iterate through rooms to find the room that matches next room
//         for (int i = 0; i < rooms.size(); i++) {
//           if (strcmp(rooms[i]->name, next_room)==0)
//           {
//             current_room = rooms[i];
//             cout<<current_room->name<<endl;
//             cout<<current_room->description<<endl;
//             return current_room;
//           }
//         }
//       }
//       else
//       {
//         cout << "Can't go that way!" << endl;
//         return current_room;
//       }
//     }
//   }
//
//     void check_trig(string user_in,vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
//   {
//     if ( (strcmp(user_in, "n")==0) || (strcmp(user_in, 's')==0) || (strcmp(user_in, 'e')==0) || (strcmp(user_in, 'w')==0) )
//     {
//       // if the room has a trigger
//       if (current_room->trigger)
//       {
//         // if the user input is equal to the trigger's command
//         if (strcmp(user_in, current_room->trigger->command)==0)
//         {
//           // if the trigger has a condition
//           if (current_room->trigger->condition)
//           {
//             // if the condition is met
//             if(check_cond(current_room->trigger->condition, inventory))
//             {
//               // look through the borders to find the room
//               current_room = assign_room(current_room, user_in, rooms);
//               return;
//             }
//           }
//         }
//       }
//       else
//       {
//         current_room = assign_room(current_room, user_in, rooms);
//         return;
//       }
//     }
//
//     // This is where Tinu's code went
//   }
//
//
//   void zork(vector<Item*> inventory, vector<Item*> items, vector<Creature*> creatures, vector<Room*> rooms, vector<Container*> containers)
//   {
//     current_room = rooms[0];
//     cout<<current_room->name<<endl;
//     cout<<current_room->description<<endl;
//     while(true)
//     {
//       string u_input;
//       getline(cin, u_input);
//       if(string(u_input) == "q")
//       {
//         break;
//       }
//       check_trig(u_input,inventory,items, creatures,rooms,containers);
//
//
//     }
//   }

#include "Header.h"
#include <string.h>
#include "Item.h"
#include "Container.h"
Room * current_room;
vector<Item *> playerItems;
vector<Item *> DeletedItems;

  string n = "n";
  string s = "s";
  string e = "e";
  string w = "w";



  // string get_add_type(string name,vector<Container*> &containers, vector<Room*> &rooms)
  // {
  //   for(int i = 0; i < containers.size(); i++)
  //   {
  //     if( name == containers[i].name() )
  //     {
  //       return "Container"
  //     }
  //   }
  //   for(int i = 0; i < rooms.size(); i++)
  //   {
  //     if ( name == rooms[i].name() )
  //     {
  //       return "Room"
  //     }
  //   }
  // }
  //
  //
  //
  // void action(string act,vector<Container*> &containers,vector<Item*> &items,vector<Room *> &rooms)
  // {
  //     istringstream ss(act);
  //     string word;
  //     ss>>word;
  //     if(word == "Add")
  //     {
  //       ss>>word;
  //       for(int i = 0; i < items.size();i++)
  //       {
  //         if(items[i]->name == word )
  //         {
  //           ss>>word;
  //           ss>>word;
  //           if(get_add_type(word,containers,rooms) == 'container')
  //           {
  //              addToContainer(Items[i],rooms);
  //           }
  //
  //           return;
  //         }
  //
  //       }
  //       for(int i = 0; i < DeletedItems.size();i++)
  //       {
  //         if(DeletedItems->name == word )
  //         {
  //           ss>>word;
  //           ss>>word;
  //
  //           return;
  //         }
  //
  //       }
  //
  //
  //     }
  // }



  void get_container_items(vector<Container*> &containers, int j)
  {
    cout<<containers[j]->name+" contains..."<<endl;
    for (int i = 0; i < containers[j]->item.size(); i++)
    {
      cout<<containers[j]->item[i]<<endl;
      current_room->item.push_back(containers[j]->item[i]); //
      containers[j]->item.erase(containers[j]->item.begin() + i);
    }
    return;
  }

  Item* getItem(string name)
  {
      for(int i = 0; i < playerItems.size(); i++)
      {
        if( name == playerItems[i]->name)
        {
          return playerItems[i];
        }
      }
  }

  bool checkForItem(string word) // checks for item in room
  {
    for(int i = 0; i < current_room->item.size();i++)
        {
          if(current_room->item[i] == word)
          {
             return true;
          }
        }
        return false;
  }

  bool checkInventory(string word)
  {
    for(int i =0; i < playerItems.size();i++)
    {
      if(word == playerItems[i]->name)
      {
        return true;
      }
    }
    return false;
  }

  bool check_cond(Condition * condition,vector<Item*> items,vector<Container*> containers)
  {
    // Checking if condition is met

    if(condition->owner->has == "yes")
    {
      if(checkInventory(condition->owner->object))
      {
        return true;
      }
    }
    else if (condition->owner->has == "no")
    {
      if(!checkInventory(condition->owner->object) == true)
      {
        return true;
      }
    }



    //
    for(int i = 0; i < items.size();i++)
    {
      if(condition->status->object == items[i]->name)
      {
        if(condition->status->name == items[i]->status)
        {
          return true;
        }
      }

    }
    for(int i = 0; i < containers.size();i++)
    {
      if(condition->status->object == containers[i]->name)
      {
        if(condition->status->name == containers[i]->status)
        {
          return true;
        }
      }

    }
  //  if (condition->status->name)
    return false;
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

  Room* assign_room( string user_in, vector<Room*> rooms)
  {
    //int way = 0;

    for (int i = 0; i < current_room->border.size(); i++)
    {
      // if the border is the same direction
      //*TEST*cout<<get_direction(user_in)<<std::endl;
      // cout<<"input"<<endl;
      // cout<<get_direction(user_in)<<endl;
      // cout<<current_room->border[i]->direction<<endl;
      if (get_direction(user_in)==current_room->border[i]->direction)
      {
        //way = 1;
        // set the value of next room equal to the name of the correct border room
        string next_room = current_room->border[i]->name;
        // iterate through rooms to find the room that matches next room
        for (int i = 0; i < rooms.size(); i++) {
          if (rooms[i]->name == next_room)
          {
            current_room = rooms[i];
            cout<<current_room->name<<endl;
            cout<<current_room->description<<endl;
            return current_room;
          }
        }

      }
    }
    cout << "Can't go that way!" << endl;
    return current_room;
  }

    bool check_trig(string user_in, vector<Item*> &items, vector<Creature*> &creatures, vector<Room*> &rooms, vector<Container*> &containers)
  {

    istringstream ss(user_in); // split into words

    if ( user_in == n || user_in == s || user_in == e || user_in == w )
    {
      // if the room has a trigger
      if (current_room->trigger)
      {
        // if the user input is equal to the trigger's command
        if (user_in ==current_room->trigger->command)
        {
          // if the trigger has a condition
          if (current_room->trigger->condition)
          {
            // if the condition is met
            if(check_cond(current_room->trigger->condition,items,containers))
            {
                // look through the borders to find the room
                cout<<current_room->trigger->print<<std::endl;
                return false;
            }
            else
            {
              current_room = assign_room(user_in, rooms);
              return false;
            }
          }
        }
        else {
          current_room = assign_room(user_in, rooms);
          return false;
        }
      }
      else
      {
        current_room = assign_room(user_in, rooms);
        return false;
      }
    }
    string word;
    ss >> word;// gets first word in sentence
    if(word == "take")
    {
      ss >> word;// next word
      if(checkForItem(word)) // checks for item in the room
      {
        for(int i= 0; i < items.size();i++)
        {
          cout<<items[i]->name<<word<<endl;
          cout<<word<<endl;
          if(items[i]->name == word  )
          {
              playerItems.push_back(items[i]); // remmeber to add delete item from room<
              cout<<"Item "+current_room->item[i]+" added to Inventory"<<std::endl;
              //current_room->item.erase(current_room->item.begin() + i);
              return false;
          }
          // else
          // {
          //   cout<<"applini"<<endl;
          //   return true;
          // }
        }
      }
      else
      {
        cout<<word+" not in room"<<endl;
        return false;
      }
    }
    else if (word == "i")
    {

      if(playerItems.size() == 0)
      {
        cout<< "Inventory:empty" << endl;
        return false;
      }
      else
      {
        cout<<"Inventory:"<<endl;
        for (int i = 0; i < playerItems.size(); i++)
        {
          cout<<playerItems[i]->name<<endl;
        }
        return false;
      }
    }
    else if (word == "open")
    {
      // look at the next word and assign to container
      string curr_container;
      ss >> curr_container;
      // if the user tries to "open exit"
      if (curr_container == "exit")
      {
        // check if the current room is of type exit
        if (current_room->type == "exit")
        {
          cout<<"Game Over"<<endl;
          return true; // false to break the loop in the function zork
        }
      }
      // check through the containers for the one matching the input
      for (int i = 0; i < current_room->container.size(); i++)
        {
          // if there is a match
          if (current_room->container[i] == curr_container)
          {
            for (int j = 0; j < containers.size(); j++)
            {
              if (containers[j]->name == curr_container)
              {
                if (containers[j]->item.size() == 0)
                {
                  cout<<containers[j]->name+" is empty"<<endl;
                  return false;
                }
                // if the container is not empty
                else
                {
                  get_container_items(containers, j);
                  cout << "got out" << endl;
                  return false;
                }
              }
            }
            // if the container is empty

          }
          else
          {
            cout<<curr_container+" is not in this room"<<endl;
            return false;
          }
        }
    }
    else if(word == "turn")
    {
      ss >> word;
      if (word == "on")
      {

        ss >> word;
        if(checkInventory(word))
        {
          Item * action_item = getItem(word);
        //  action(action_item->action,containers,items);
          return false;
        }
        else
        {
          cout<<"you do not poessess this item"<<endl;
          return false;
        }
      }
    }
    else
    {
      cout<<"command not recognized"<<endl;
      return false;
    }


    // This is where Tinu's code went
  }

  void zork(vector<Item*> inventory, vector<Item*> &items, vector<Creature*> &creatures, vector<Room*> &rooms, vector<Container*> &containers)
  {
    current_room = rooms[0];
    cout<<current_room->name<<endl;
    cout<<current_room->description<<endl;
    bool game_state = false;
    while(true)
    {

      string u_input;
      getline(cin, u_input);
      if(string(u_input) == "q")
      {
        break;
      }
      game_state = check_trig(u_input,items, creatures,rooms,containers);
      if(game_state == true)
      {
        break;
      }
    /*  cout<<"Current Room is "<<current_room->name<<std::endl;
      for(int i = 0 ; i < current_room->border.size();i++)
        {
            cout<<current_room->border[i]->name<<" "<<current_room->border[i]->direction<<std::endl;
        }*/
    }
  }
