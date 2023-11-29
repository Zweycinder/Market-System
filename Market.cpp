#include <iostream>

using namespace std;

class market
{
private:
    int user_counter = 1;
    int items_counter = -1;
    string name[100] = { "admin" };
    string password[100] = { "admin1234" };

    string equ[1000];
    int qua[1000];
    int price[1000];

public:
    void regester(string q, string w);
    bool login(string e, string r);
    void input_item(string x, int y, int z);
    int sell(string order, int many);
    void showDB();

};

void market::regester(string q, string w)
{
    if (user_counter == 100)
    {
        cout << "users are full\n";
    }
    else
    {
        name[user_counter] = q;
        password[user_counter] = w;
        user_counter++;
    }
}

bool market::login(string e, string r)
{
    for (int i = 0; i <= user_counter; i++)
    {
        if (e == name[i])
        {
            if (r == password[i])
            {
                return true;
            }
            if (r == "0696969690")
            {
                cout << "enter new password\n";
                cin >> r;
                password[i] = r;
                return true;
            }
        }
    }
    return false;
}

void market::input_item(string x, int y, int z)
{
    if (items_counter < 1000)
    {
        this->equ[items_counter] = x;
        this->qua[items_counter] = y;
        this->price[items_counter] = z;
        items_counter++;
        return;
    }
    cout << "items are full\n";
}

int market::sell(string order, int many)
{
    int total = 0;
    for (int i = 0; i < items_counter; i++)
    {
        if (order == equ[i])
        {
            if (many > qua[i])
            {
                cout << "out of stock\n";
            }
            else
            {
                total = many * price[i];
                qua[i] = qua[i] - many;
            }
        }
    }
    return total;
}

void market::showDB()
{
    for (int i = 0; i <= items_counter; i++)
    {
        cout << "equipments: " << equ[i] << endl;
        cout << "quantity: " << qua[i] << endl;
        cout << "price: " << price[i] << endl;
    }
}


int main()
{
    market obj;
    int picker;
    bool hm = true;
    string namen, passp;
    string iname;
    int qq, pp;
    int totalprice = 0;
    while (hm)
    {
        cout << "1- Login, 2- Register, 3- Forget Password, 4- end\n";
        cin >> picker;
        switch (picker)
        {
        case 1:
        {
            cin >> namen >> passp;
            if (obj.login(namen, passp))
            {
                cout << "welcome\n";
                hm = false;
            }
            else
            {
                cout << "this name doesnt exist or password is wrong" << endl;
            }
            break;
        }
        case 2:
        {
            cin >> namen >> passp;
            obj.regester(namen, passp);
            hm = false;
            break;
        }
        case 3:
        {
            cout << "Enter name\n";
            cin >> namen;
            if (obj.login(namen, "0696969690") != true)
            {
                cout << "this name doesnt exict\n";
            }
            break;
        }
        default:
            hm = false;
        }
    }

    hm = true;
    while (hm)
    {
        cout << "1- sell, 2- input item, 3- showDB, 4- end\n";
        cin >> picker;
        switch (picker)
        {
        case 1:
        {
            obj.showDB();
            cout << "enter order and how many\n";
            cin >> iname >> qq;
            totalprice = totalprice + obj.sell(iname, qq);
            break;
        }
        case 2:
        {
            cout << "name, quantity, price\n";
            cin >> iname >> qq >> pp;
            obj.input_item(iname, qq, pp);
            break;
        }
        case 3:
            obj.showDB();
        default:
            hm = false;
        }
    }
    cout << "your total price is = " << totalprice << endl;

    return 0;
}

