#include "board.h"
#include "store.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Card
{
    string color;
    string doub;
};

Card drawCard(char choice)
{

    Card deck;

    srand(time(NULL));
    if (choice == 'D')
    {
        int random = (rand() % 6) + 1;
        if (random == 1)
        {
            deck.color = "Blue";
            deck.doub = "";
        }
        else if (random == 2)
        {
            deck.color = "Green";
            deck.doub = "";
        }
        else if (random == 3)
        {
            deck.color = "Purple";
            deck.doub = "";
        }else if (random == 4)
        {
            deck.color = "Blue";
            deck.doub = "Double";
        }else if (random == 5)
        {
            deck.color = "Green";
            deck.doub = "Double";
        }else if(random == 6)
        {
            deck.color = "Purple";
            deck.doub = "Double";
        }
    }
    else
    {
        cout << "Invalid Selection" << endl;
    }

    return deck;
}

int main()
{

    Board board;

    Candy fudge;
    fudge.name = "Fudge";
    Candy bar;
    bar.name = "Bar";
    Candy powder;
    powder.name = "Powder";
    Candy Choc;
    Choc.name = "Chocolate";
    Candy candArr[4] = {fudge, bar, powder, Choc};

    Store store1(candArr, 12);
    store1.setStore(candArr);
    board.addCandyStore(12);

    Store store2(candArr, 33);
    store2.setStore(candArr);
    board.addCandyStore(33);

    Store store3(candArr, 80);
    store3.setStore(candArr);
    board.addCandyStore(80);

    Store store_array[3] = {store1, store2, store3};

    board.tileNames();
    char choice;
    Card card;
    while (board.getPlayerPosition() != 83)
    {

        for (int a = 0; a < 83; a++)
        {
            cout << "To Draw a Card press D" << endl;
            cin >> choice;
            card = drawCard(choice);
            cin.ignore(100000, '\n');
            cout << "Your card is: " <<card.color<<" "<<card.doub << endl;
            for (int b = board.getPlayerPosition() + 1; b < 83; b++)
            {
                if (card.color == board.getTile(b).color_name)
                {
                    cout << "Number: " << b << endl;
                    board.movePlayer(b);
                    board.setPlayerPosition(b);

                if(card.doub == "Double"){
                    board.movePlayer(b + 3);
                    board.setPlayerPosition(b + 3);
                }
                
                    if (board.isPositionCandyStore(board.getPlayerPosition()) == true)
                    {
                        for (int x = 0; x < 3; x++)
                        {
                            if (b == store_array[x].getPosition())
                            {
                                cout << "Store Contents: " << endl;
                                store_array[x].getStore();
                                break;
                            }
                        }
                    }
                    break;
                }
            }

            board.displayBoard();
        }
    }
    return 0;
}