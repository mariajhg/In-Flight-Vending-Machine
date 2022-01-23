#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


struct menuItem{
    string description;
    float price;
    int quantity;
};

const int SIZE=6;

void display(menuItem item[SIZE]);
float order(menuItem item[SIZE]);
int highest(menuItem item[SIZE]);

void display(menuItem item[])
{
       for (int x=0; x<SIZE; x++)
       {
            if (x<5)
            {
                cout << fixed << setprecision(2) << showpoint;
                cout << "[" << x+1 << "] " << item[x].description;
                cout << setw(5) << "\t$" << item[x].price << endl;
            }
            else
            {
                cout << fixed << setprecision(2) << showpoint;
                cout << "[" << x+1 << "] " << item[x].description;
                cout << setw(8) << "\t$" << item[x].price << endl;
            }
       }
}

float order(menuItem item[])
{

    int order1;
    float subtotal=0;

    cout << endl << "Input the items for the order, 0 to quit." << endl;
    cout << "For example: 1 3 4 0." << endl;
    while (order1!=0)
    {
        cin >> order1;

        if (order1 < 0 || order1 > 6)
        {
            cout << "*Error: There is no item " << order1 << "." << endl;
            cout << "Processing other items..." << endl;
        }
        else if (order1!=0)
        {
            subtotal+=item[order1-1].price;
            item[order1-1].quantity+=1;
        }
    }

    return subtotal;
}

int highest (menuItem item[])
{

    int index=item[0].quantity;
    string position = item[0].description;

    for (int i=0; i<SIZE; i++)
    {

        if (item[i+1].quantity > item[i].quantity)
        {
            index=item[i+1].quantity;
            position=item[i+1].description;
        }
    }

    cout << "Item ordered most often: " << position;

    return index;

}

int main()
{

    menuItem item[SIZE];

    cout << endl << "- MENU ITEMS -" << endl << endl;

    item[0].description = "Rolex Watch";
    item[0].price = 1099.00;
    item[0].quantity = 0;

    item[1].description = "MacBook Pro";
    item[1].price = 1299.00;
    item[1].quantity = 0;

    item[2].description = "Men's Cufflinks";
    item[2].price = 499.00;
    item[2].quantity = 0;

    item[3].description = "iPad Pro 11-in";
    item[3].price = 799.00;
    item[3].quantity = 0;

    item[4].description = "Ladies Ring";
    item[4].price = 999.00;
    item[4].quantity = 0;

    item[5].description = "Watch S4";
    item[5].price = 399.00;
    item[5].quantity = 0;

    display(item);

    char choice;
    float subtotal, tax, total, salesTotal=0;

    subtotal=order(item);
    tax=subtotal*.0825;
    total=subtotal+tax;
    salesTotal+=total;

    cout << fixed << right << setprecision(2) << showpoint;
    cout << endl << "Subtotal... $ " << subtotal << endl;
    cout << "Tax........ $ " << tax << endl;
    cout << "Total...... $ " << total << endl<< endl;

    while(1==1)
    {
        cout << "Enter 'N' to continue and 'E' to exit: ";
        cin >> choice;

        while (choice!='N' & choice!='E')
        {
            cout << "Invalid. Try again" << endl;
            cin >> choice;
        }

        if (choice=='N')
        {
            display(item);

            subtotal=order(item);
            tax=subtotal*.0825;
            total=subtotal+tax;
            salesTotal+=total;

            cout << fixed << setprecision(2) << showpoint;
            cout << "Subtotal... $ " << subtotal << endl;
            cout << "Tax........ $ " << tax << endl;
            cout << "Total...... $ " << total << endl<< endl;
        }
        else if (choice=='E')
        {

            cout << "*** End of Day:" << endl;
            cout << "Total Sales: $" << salesTotal << endl << endl;
            break;
        }
    }

    int index=highest(item);
    cout << " was purchased " << index << " times." << endl;


    return 0;
}