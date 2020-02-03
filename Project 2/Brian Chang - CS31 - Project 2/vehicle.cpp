//
//  main.cpp
//  Project 2
//
//  Created by Brian Chang on 1/15/20.
//  Copyright © 2020 Brian Chang. All rights reserved.
//

#include <iostream>
#include <climits>
#include <string>
using namespace std;

int main()
{
    double price = 0.00;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Which vehicle would you like to order? ";
    string model;
    cin >> model;
    cin.ignore( INT_MAX, '\n');
    
    if (model != "S" && model != "3" && model != "X")
    {
        cout << "Error - Incorrect model choice." << endl;
        return -1;
    }
    
    
    cout << "Which kind would you like? ";
    string kind;
    getline(cin,kind);
    
    if (kind != "Long Range" && kind != "Performance")
    {
        cout << "Error - Incorrect kind choice." << endl;
        return -1;
    }
    
    
    cout << "What exterior color would you like? ";
    string color;
    getline(cin,color);
    
    if (color != "White" && color != "Black" && color != "Blue" && color != "Grey" && color != "Red")
    {
        cout << "Error - Incorrect color choice." << endl;
        return -1;
    }
    
    
    cout << "Which wheels would you like? ";
    string wheels;
    getline(cin,wheels);
    
    if (model=="3" && ((wheels != "18") && (wheels != "19")))
    {
        cout << "Error - Incorrect wheel value.";
        return -1;
    }
    
    else if (model=="S" && ((wheels != "19") && (wheels != "21")))
    {
        cout << "Error - Incorrect wheel value.";
        return -1;
    }
    
    else if (model=="X" && ((wheels != "20") && (wheels != "22")))
    {
        cout << "Error - Incorrect wheel value.";
        return -1;
    }
    
    
    cout << "Want leather interior? ";
    string leather;
    getline(cin,leather);
    
    if (leather != "Yes" && leather != "No")
    {
        cout << "Error - Incorrect leather choice.";
        return -1;
    }
    
    
    cout << "Want Auto-Pilot? ";
    string autopilot;
    getline(cin,autopilot);
    
    if (autopilot != "Yes" && autopilot != "No")
    {
        cout << "Error - Incorrect autopilot choice.";
        return -1;
    }
    
    
    
    
   //--------------------------------------------------------------------------------------------------------------------------------------
    

    
    
    
    if (model=="3")
    {
        if (kind=="Long Range")
        {
            price += 47990;
        }
        else if (kind=="Performance")
        {
            price += 55990;
        }
        else
        {
            cout << "Error - Incorrect kind choice.\n";
            
        }
        
        
        if (color=="White")
        {
            price = price;
        }
        else if (color=="Black")
        {
            price += 500;
        }
        else if ((color=="Blue") || (color=="Grey"))
        {
            price += 1000;
        }
        else if (color=="Red")
        {
            price += 1500;
        }
        else
        {
            cout << "Error - Incorrect color choice.\n";
        }
        
        
        if (wheels=="18")
            }
            price = price;
        }
        else if (wheels=="19")
        {
            price += 1500;
        }
        else
        {
            cout << "Error - Incorrect wheel value.\n";
        }
        
        
        if ((leather == "Yes"))
        {
            price += 1000;
        }
        else if ((leather == "No"))
        {
            price = price;
        }
        else
        {
            cout << "Error - Incorrect leather choice.\n";
        }
        
        
        if ((autopilot == "Yes"))
        {
            price += 6000;
        }
        else if ((autopilot == "No"))
        {
            price = price;
        }
        else
        {
            cout << "Error - Incorrect leather choice.\n";
        }
        
    }
    
    
    //--------------------------------------------------------------------------------------------------------------------------------------
    
    
    if (model=="S")
    {
        if (kind=="Long Range")
        {
            price += 79990;
        }
        else if (kind=="Performance")
        {
            price += 99990;
        }
        else
        {
            cout << "Error - Incorrect kind choice.\n";
            
        }
        
        
        if (color=="White")
        {
            price = price;
        }
        else if (color=="Black")
        {
            price += 1000;
        }
        else if ((color=="Blue") || (color=="Grey"))
        {
            price += 1500;
        }
        else if (color=="Red")
        {
            price += 2500;
        }
        else
        {
            cout << "Error - Incorrect color choice.\n";
        }
        
        
        if (wheels=="19")
        {
            price = price;
        }
        else if (wheels=="21")
        {
            price += 4500;
        }
        else
        {
            cout << "Error - Incorrect wheel value.\n";
        }
        
        
        if ((leather == "Yes"))
        {
            price += 1000;
        }
        else if ((leather == "No"))
        {
            price = price;
        }
        else
        {
            cout << "Error - Incorrect leather choice.\n";
        }
        
        
        if ((autopilot == "Yes"))
        {
            price += 6000;
        }
        else if ((autopilot == "No"))
        {
            price = price;
        }
        else
        {
            cout << "Error - Incorrect leather choice.\n";
        }
        
    }
    
    
    //--------------------------------------------------------------------------------------------------------------------------------------
    
    
    
    if (model=="X")
    {
        if (kind=="Long Range")
        {
            price += 84990;
        }
        else if (kind=="Performance")
        {
            price += 104990;
        }
        else
        {
            cout << "Error - Incorrect kind choice.\n";
            
        }
        
        if (color=="White")
        {
            price = price;
        }
        else if (color=="Black")
        {
            price += 1000;
        }
        else if ((color=="Blue") || (color=="Grey"))
        {
            price += 1500;
        }
        else if (color=="Red")
        {
            price += 2500;
        }
        else
        {
            cout << "Error - Incorrect color choice.\n";
        }
        
        
        if (wheels=="20")
        {
            price = price;
        }
        else if (wheels=="22")
        {
            price += 5500;
        }
        else
        {
            cout << "Error - Incorrect wheel value.\n";
        }
        
        
        if ((leather == "Yes"))
        {
            price += 1000;
        }
        else if ((leather == "No"))
        {
            price = price;
        }
        else
        {
            cout << "Error - Incorrect leather choice.\n";
        }
        
        
        if ((autopilot == "Yes"))
        {
            price += 6000;
        }
        else if ((autopilot == "No"))
        {
            price = price;
        }
        else
        {
            cout << "Error - Incorrect leather choice.\n";
        }
        
    }
    
    
    cout << "Enjoy your new $" << price << " " << color << " " << "Model " << model << "!" << endl;
        
}

