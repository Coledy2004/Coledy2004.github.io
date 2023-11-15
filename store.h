#include <iostream>

using namespace std;



struct Candy{
    string name;
    string description;
    double price;
    string candy_type;
};


class Store
{
private:
    const static int _max_candy_amount = 4;
    Candy _candies[_max_candy_amount];
    int _store_position;

public:
    Store();
    Store(Candy[],int);

    void buyCandy(Candy);
    void setStore(Candy[]);
    void getStore();
    int getPosition();

};
