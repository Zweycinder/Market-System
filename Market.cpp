#include <iostream>

using namespace std;

class market
{
private:
    string name[5] = { "admin","0","0","0","0" };
    string password[5] = { "12345678","0","0","0","0" };

    string equ[3] = { "0","0","0" };
    int qua[3] = { 0,0,0 };
    int price[3] = { 0,0,0 };

public:
    void regester(string q, string w)
    {
        for (int i = 0; i < 5; i++)
        {
            if (name[i] == "0")
            {
                name[i] = q;
                password[i] = w;
                return;
            }

        }
        cout << "users are full\n";
    }

    bool login(string e, string r)
    {
        for (int i = 0; i < 5; i++)
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

    void input_item(string x, int y, int z)
    {
        for (int i = 0; i < 3; i++)
        {
            if (equ[i] == "0")
            {
                equ[i] = x;
                qua[i] = y;
                price[i] = z;
                return;
            }
        }
        cout << "items are full\n";
    }

    int sell(string order, int many)
    {
        int total = 0;
        for (int i = 0; i < 3; i++)
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

    void showDB()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "equipments: " << equ[i] << endl;
            cout << "quantity: " << qua[i] << endl;
            cout << "price: " << price[i] << endl;
        }
    }

};




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

