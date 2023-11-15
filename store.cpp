#include "board.h"
#include "store.h"
#include <iostream>
using namespace std;

Store::Store(){
Candy _candies[4];
int _store_position = 0;
};

Store::Store(Candy store_inventory[], int store_position){

for(int i = 0; i < _max_candy_amount; i++){
    _candies[i] = store_inventory[i];
}
_store_position = store_position;
}

int Store::getPosition(){

return _store_position;
}


void Store::setStore(Candy store_inventory[])
{
for(int i = 0; i < _max_candy_amount; i++){
    _candies[i] = store_inventory[i];
}

}

void Store::getStore(){
    int x = 0;
    while(_candies[x].name != ""){
    cout <<"Candy name: " << _candies[x].name << endl;
    cout << "Candy description:"<< _candies[x].description<<endl;
    cout <<"Candy Price:" << _candies[x].price <<endl;
    cout<<"Candy type:" << _candies[x].candy_type <<endl;
    x++;
    }
}