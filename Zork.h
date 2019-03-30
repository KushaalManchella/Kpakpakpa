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

//  getContainerIndex(word,vector<Container *> & containers);
// itemIndex = getItemIndex(word,containers[index]);
void updateRoom(vector<Room *> & rooms, Room * room)
{
  for(int i= 0; i< rooms.size();i++)
  {
    if(room->name == rooms[i]->name)
    {
      rooms.erase(rooms.begin() + i);
      rooms.push_back(room);
      return;
    }

  }
}
int getItemIndex(string word, Container * container)
{
  for(int j =  0; j < container->item.size();j++)
  {
    if(container->item[j]== word)
    {
      return j;
    }
  }
}

int getContainerIndex(string word,vector<Container *> & containers )
{
  for(int i = 0; i < containers.size();i++)
  {
    for(int j =  0; j < containers[i]->item.size();j++)
    {
      if(containers[i]->item[j]== word)
      {
        return i;
      }
    }
  }
}

 void removeFromInventory(string word)
 {
   for(int i = 0; i < playerItems.size();i++)
   {
     if(playerItems[i]->name == word)
     {
       playerItems.erase(playerItems.begin() + i);
      break;
     }
   }
 }
  void get_container_items(vector<Container*> &containers, int j)
  {
    cout<<containers[j]->name+" contains..."<<endl;
    for (int i = 0; i < containers[j]->item.size(); i++)
    {
      cout<<containers[j]->item[i]<<endl;
      current_room->item.push_back(containers[j]->item[i]); //
      //updateRoom(rooms,current_room);
      //containers[j]->item.erase(containers[j]->item.begin() + i);
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

  Item* getItemFromRoom(string name, vector<Item*> items)
  {
      for(int i = 0; i < items.size(); i++)
      {
        if( name == items[i]->name)
        {
          return items[i];
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

  bool itemInContainer(string word,vector<Container *> containers) // checks for item in room
  {
    for(int i = 0; i < containers.size();i++)
    {
      for(int j =  0; j < containers[i]->item.size();j++)
      {
        if(containers[i]->item[j]== word)
        {
          for(int k = 0; k < current_room->container.size(); i++)
          {
            if(current_room->container[i] == containers[i]->name)
            {
                return true;
            }
          }

        }
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

  int get_current_room_item_index(string item_name)
  {
    for(int i = 0; i < current_room->item.size(); i++)
    {
      if (current_room->item[i] == item_name)
      {
        return i;
      }
    }
    return -1;
  }
 /*
 Add (object) to (room/container) – creates instance of object with a specific owner (does not work on the player's inventory).
 Delete (object) – removes object references from game, but the item can still be brought back into the game using the 'Add' command. If a room is removed other rooms will have references to the removed room as a 'border' that was removed, but there is no means for adding a room back in.
 Update (object) to (status) – creates new status for object that can be checked by triggers
 Game Over – ends the game with a declaration of “Victory!”
 */
  void action(string action, vector<Item*> &items, vector<Container*> &containers, vector<Room*> &rooms, vector<Creature*> &creatures, int* end_game)
  {
    istringstream ss(action);
    string word;
    ss>> word;
    if(word == "Add")
    {
      string object;
      ss>> object;
      string owner;
      ss>> owner; // "to"
      ss>> owner; // owner
      // check through non deleted items
      for (int i = 0; i < items.size(); i++)
      {
        // find the items object with the corresponding name
        if (items[i]->name == object)
        {
          // look through rooms for match of owner
          for (int j = 0; j < rooms.size(); j++)
          {
            // find the rooms object with the corresponding name
            if (rooms[j]->name == owner)
            {
              // push item into room's items
              rooms[j]->item.push_back(items[i]->name);
              return;
            }
          }
          // look through containers for match of owner
          for (int j = 0; j < containers.size(); j++)
          {
            // find the containers object with the corresponding name
            if (containers[j]->name == owner)
            {
              // push item into room's items
              containers[j]->item.push_back(items[i]->name);
              return;
            }
          }
        }
      }
      // check through deleted items
      for (int i = 0; i < DeletedItems.size(); i++)
      {
        if (DeletedItems[i]->name == object)
        {
          // look through rooms for match of owner
          for (int j = 0; j < rooms.size(); j++)
          {
            // find the rooms object with the corresponding name
            if (rooms[j]->name == owner)
            {
              // push item into room's items
              rooms[j]->item.push_back(DeletedItems[i]->name);
              items.push_back(DeletedItems[i]);
              return;
            }
          }
          // look through containers for match of owner
          for (int j = 0; j < containers.size(); j++)
          {
            // find the containers object with the corresponding name
            if (containers[j]->name == owner)
            {
              // push item into room's items
              containers[j]->item.push_back(DeletedItems[i]->name);
              items.push_back(DeletedItems[i]);
              return;
            }
          }
        }
      }
    }
    else if(word == "Delete")
    {
      string object;
      ss>>object;
      for(int i = 0; i<items.size();i++)
      {
        if(items[i]->name == object)
        {
          DeletedItems.push_back(items[i]);
          items.erase(items.begin() + i);
        }
      }
        for(int i = 0; i<current_room->item.size();i++)
        {
          if(current_room->item[i] == object)
          {
            current_room->item.erase(current_room->item.begin() + i);
          }
        }
      return;
    }
    else if(word == "Update")
    {
      string object;
      string u_status;
      ss>> object; // item
      ss>> u_status; // to
      ss>> u_status;  // status

      // updating status of item
      for(int i = 0; i<items.size();i++)
      {
        if(items[i]->name == object)
        {
          items[i]->status = u_status;
          return;
        }
      }

      //updating status of containers
      for(int i = 0; i<containers.size();i++)
      {
        if(containers[i]->name == object)
        {
          containers[i]->status = u_status;
          return;
        }
      }

      //updating status of rooms
      for(int i = 0; i<rooms.size();i++)
      {
        if(rooms[i]->name == object)
        {
          rooms[i]->status = u_status;
          return;
        }
      }

      //updating status of creature
      for(int i = 0; i<creatures.size();i++)
      {
        if(creatures[i]->name == object)
        {
          creatures[i]->status = u_status;
          return;
        }
      }
    }
    else if(word == "Game")
    {
      string over;
      ss >> over;  // over

      if(over == "Over")
      {
        *end_game = 1;
      }

    }
  }


    bool check_trig(string user_in, vector<Item*> &items, vector<Creature*> &creatures, vector<Room*> &rooms, vector<Container*> &containers, int* end_game)
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
      if(itemInContainer(word,containers))
       {
         int index;
         int itemIndex;
         playerItems.push_back(getItemFromRoom(word, items));
         index = getContainerIndex(word, containers);
         itemIndex = getItemIndex(word,containers[index]);
         containers[index]->item.erase(containers[index]->item.begin() + itemIndex);
         current_room->item.erase(current_room->item.begin() + get_current_room_item_index(word));
         updateRoom(rooms, current_room);
         cout<<"Item "+items[index]->name+" added to Inventory"<<std::endl;
         return false;
       }
      if(checkForItem(word)) // checks for item in the room
      {
        for(int i= 0; i < items.size();i++)
        {
          if(items[i]->name == word )
          {
              playerItems.push_back(items[i]); // remmeber to add delete item from room<
              cout<<"Item "+items[i]->name+" added to Inventory"<<std::endl;
              current_room->item.erase(current_room->item.begin() + get_current_room_item_index(word));
              updateRoom(rooms, current_room);
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
        cout<<word+" not found"<<endl;
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
        cout<<"playerItems size:" << playerItems.size() << endl;
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
      int cont = 0;
      // check through the containers for the one matching the input
      for (int i = 0; i < current_room->container.size(); i++)
        {

          // if there is a match
          //cout << current_room->container[i] <<endl;
          if (current_room->container[i] == curr_container)
          {
            for (int j = 0; j < containers.size(); j++)
            {
              if (containers[j]->name == curr_container)
              {
                cont = 1;
                if (containers[j]->item.size() == 0  &&  containers[j]->status != "locked")
                {
                    cout<<containers[j]->name+" is empty"<<endl;
                    return false;
                  }
                  else if(containers[j]->item.size() == 0  &&  containers[j]->status == "locked")
                  {
                    cout<<containers[j]->name+" is locked"<<endl;
                  }
                // if the container is not empty
                else
                {
                  get_container_items(containers, j);
                  //cout << "got out" << endl;
                  return false;
                }
              }
            }
            // if the container is empty

          }

        }
        if(cont == 0)
        {
          cout<<curr_container+" is not in this room"<<endl;
          return false;
        }
    }
    /*
    else if(word == "turn")
    {
      ss >> word;
      if (word == "on")
      {
        string item;
        ss >> item;
        if(checkInventory(item))
        {
          Item * action_item = getItem(word);
          cout<<action_item->turnon->print<<endl;
        //action(action_item->action,containers,items);

          return false;
        }
        else
        {
          cout<<"you do not possess this item"<<endl;
          return false;
        }
      }
    }
    */
    else if(word == "drop")
    {
      ss >>word;
      if(!checkInventory(word))
      {
        cout<<"you do not possess this item"<<endl;
      }
      else
      {
        //Item * item = getItem(word);
        current_room->item.push_back(word);
        //updateRoom(rooms, current_room);
        removeFromInventory(word);
        cout<<word<<" dropped"<<endl;
      }


    }
    else if(word == "read")
    {
      ss >> word;
      if(!checkInventory(word))
      {
        cout << "you do not possess this item" << endl;
      }
      else
      {
        Item* item = getItem(word);

        cout << item->writing << endl;
      }

    }
    else if(word == "put")
    {
      string item;
      ss>>item;
      if(!checkInventory(item))
      {
        cout << "you do not possess this item" << endl;
        return false;
      }
      ss>>word;
      ss>>word;
      //container in room

       int cExist = 0;
       int deny = 0;
      for (int i = 0; i < current_room->container.size(); i++)
        {
            if(current_room->container[i] == word)
            {
              cExist = 1;
              for(int j = 0; j< containers.size(); j++)
              {
                if(containers[j]->name == word)
                {
                  if(containers[j]->accept.size() == 0)
                  {
                    containers[j]->item.push_back(item);
                    //print it has been added
                    removeFromInventory(item);
                    cout<<"Item "+item+" added to "+ containers[j]->name<<endl;
                    return false;
                  }
                  else
                  {
                      for(int k = 0; k < containers[j]->accept.size();k++)
                      {
                        if(containers[j]->accept[k] == word)
                        {
                          deny = 1;
                          containers[j]->item.push_back(item);
                          removeFromInventory(item);
                          if(check_cond(containers[j]->trigger->condition,items,containers))
                          {
                              // look through the borders to find the room
                              cout<<containers[j]->trigger->print<<std::endl;
                              action(containers[j]->trigger->action,items,containers,rooms,creatures,end_game);
                              return false;
                          }
                          /////////////////////////////////////////////////////////////////////////
                        }
                      }
                  }

                }

              }
            }
        }

        if(cExist == 0)
        {
          cout<<"Container doesnt exist"<<endl;
        }
        if(deny == 0)
        {
          cout<<"You can't do that!"<<endl;
        }

    }

    else if (word == "turn")
    {
      string item;
      ss>>item; // "on"
      ss>>item; // item
      if (checkInventory(item))
      {
        for (int i = 0; i < items.size(); i++)
        {
          if (items[i]-> name == item)
          {
            if(items[i]->turnon->action !="nothing")
            {
              if (items[i]->on)
              {

                cout<<item+" is already on"<<endl;
                return false;
              }
              else
              {
                // UPDATE ITEM *******
                cout<<items[i]->turnon->print<<endl;
                action(items[i]->turnon->action, items, containers, rooms, creatures, end_game);
                return false;
              }
            }
            else
            {
              cout<<"cannot turn "+item+" on"<<endl;
              return false;
            }
          }
        }
      }
      else
      {
        cout<<"you do not possess this"<<endl;
      }

    }
    else
    {
      cout<<"command not recognized"<<endl;
      return false;
    }

  }

  void zork(vector<Item*> inventory, vector<Item*> &items, vector<Creature*> &creatures, vector<Room*> &rooms, vector<Container*> &containers)
  {
    int end_game = 0;
    current_room = rooms[0];
    cout<<current_room->name<<endl;
    cout<<current_room->description<<endl;
    bool game_state = false;
    while(true)
    {

      string u_input;
      updateRoom(rooms, current_room);
      getline(cin, u_input);
      if(string(u_input) == "q")
      {
        break;
      }
      game_state = check_trig(u_input,items, creatures,rooms,containers, &end_game);
      if(game_state == true)
      {
        break;
      }
      if((end_game) == 1)
      {
        cout << "Victory!" << endl;
        break;
      }
    /*  cout<<"Current Room is "<<current_room->name<<std::endl;
      for(int i = 0 ; i < current_room->border.size();i++)
        {
            cout<<current_room->border[i]->name<<" "<<current_room->border[i]->direction<<std::endl;
        }*/
    }
  }
