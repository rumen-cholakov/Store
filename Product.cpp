#include "Product.h"

#include <cstring>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

istream& operator >> (istream& s, Product& e)
{
    cout << "\nSKU: ";
    getline(s, e.SKU);

    cout << "\nBrand: ";
    getline(s, e.Brand);

    cout << "\nModel: ";
    getline(s, e.Model);

    int tempCat;
    do
    {
        cout << "\nPossible categories: Men-1, Women-2, Kids-3"
             << "\nPlease input the corresponding number" << "\nCategory: ";
        cin >> tempCat;
        if(cin) break;
        cin.clear();
        cin.ignore();
    }while(true);
    switch(tempCat)
    {
        case 1: e.Pcategory = Men;
        break;
        case 2: e.Pcategory = Women;
        break;
        case 3: e.Pcategory = Kids;
        break;
        default: e.Pcategory = Men;
        break;
    }

    int tempCol;
    do
    {
        cout << "\nPossible colors: Red-1, Blue-2, White-3"
             << "\nPlease input the corresponding number" << "\nColor: ";
        cin >> tempCol;
        if(cin) break;
        cin.clear();
        cin.ignore();
    }while(true);
    switch(tempCol)
    {
        case 1: e.Pcolor = Red;
        break;
        case 2: e.Pcolor = Blue;
        break;
        case 3: e.Pcolor = White;
        break;
        default: e.Pcolor = Red;
        break;
    }

    int tempSz;
    do
    {
        cout << "\nPossible sizes: S-1, M-2, L-3, XL-4, XXL-5"
             << "\nPlease input the corresponding number" << "\nSize: ";
        cin >> tempSz;
        if(cin) break;
        cin.clear();
        cin.ignore();
    }while(true);
    switch(tempSz)
    {
        case 1: e.Psize = S;
        break;
        case 2: e.Psize = M;
        break;
        case 3: e.Psize = L;
        break;
        case 4: e.Psize = XL;
        break;
        case 5: e.Psize = XXL;
        break;
        default: e.Psize = S;
        break;
    }

    int tempPr;
    do
    {
        cout << "\nPrice: ";
        cin >> tempPr;
        if(cin) break;
        cin.clear();
        cin.ignore();
    }while(true);
    e.Price = tempPr;

    int tempCou;
    do
    {
        cout << "\nCount: ";
        cin >> tempCou;
        if(cin) break;
        cin.clear();
        cin.ignore();
    }while(true);
    e.Count = tempCou;

    return s;
}

ostream& operator << (ostream& s, const Product& e)
{
    int i;

    s << '\t' << e.SKU;

    s << '\t' << e.Brand;
    for (i = e.Brand.length() + 1; i < 10; i++)
        s.put(' ');

    s << '\t' << e.Model;
    for (i = e.Model.length() + 1; i < 10; i++)
        s.put(' ');

    s << '\t';
    switch(e.getCategory())
    {
    	case 1: s<<"Men";
    	for (i = 3; i < 10; i++)
        s.put(' ');
    	break;
    	case 2: s<<"Women";
    	for (i = 5; i < 10; i++)
        s.put(' ');
    	break;
    	case 3: s<<"Kids";
    	for (i = 4; i < 10; i++)
        s.put(' ');
    	break;
    }

    s << '\t';
    switch(e.getColor())
    {
    	case 1: s<<"Red";
    	for (i = 3; i < 10; i++)
        s.put(' ');
    	break;
    	case 2: s<<"Blue";
    	for (i = 4; i < 10; i++)
        s.put(' ');
    	break;
    	case 3: s<<"White";
    	for (i = 5; i < 10; i++)
        s.put(' ');
    	break;
    }

    s << '\t';
    switch(e.getSize())
    {
    	case 1: s<<"S";
    	for (i = 1; i < 10; i++)
        s.put(' ');
    	break;
    	case 2: s<<"M";
    	for (i = 1; i < 10; i++)
        s.put(' ');
    	break;
    	case 3: s<<"L";
    	for (i = 1; i < 10; i++)
        s.put(' ');
    	break;
    	case 4: s<<"XL";
    	for (i = 2; i < 10; i++)
        s.put(' ');
    	break;
    	case 5: s<<"XXL";
    	for (i = 3; i < 10; i++)
        s.put(' ');
    	break;
    }

    s << '\t' <<e.getPrice();
    s << '\t' <<e.getCount();
    s << endl;
    return s;
}
Product::Product()
{
		SKU = "";
		Brand = "";
		Model = "";
		Pcategory = Men;
		Pcolor = Red;
		Psize = S;
		Price = 0;
		Count = 0;
}
Product Product::Set()
{
    cin >> *this;
    return *this;
}

Product::Product(const Product& a)
{
    *this = a;
}

Product Product::Change(string sku)
{
    if(sku == this->SKU)
        Set();
    return *this;
}

string Product::Save()
{
    string sPcategory;
    switch(this->Pcategory)
    {
    	case 1: sPcategory = "Men";
    	break;
    	case 2: sPcategory = "Women";
    	break;
    	case 3: sPcategory = "Kids";
    	break;
    }
    string sPcolor;
    switch(this->Pcolor)
    {
    	case 1: sPcolor = "Red";
    	break;
    	case 2: sPcolor = "Blue";
    	break;
    	case 3: sPcolor = "White";
    	break;
    }
    string sPsize;
    switch(this->Psize)
    {
    	case 1: sPsize = "S";
    	break;
    	case 2: sPsize = "M";
    	break;
    	case 3: sPsize = "L";
    	break;
    	case 4: sPsize = "XL";
    	break;
    	case 5: sPsize = "XXL";
    	break;
    }
    stringstream ssPice;
    ssPice << (this->Price);
    string sPrice = ssPice.str();
    stringstream ssCount;
    ssCount << (this->Count);
    string sCount = ssCount.str();
    string line = SKU + ";" + Brand + ";" + Model + ";" + sPcategory + ";" + sPcolor +
                  ";" + sPsize + ";" + sPrice + ";" + sCount;
    return line;
}

void Product::Load(string &line)
{
    stringstream sstream(line);

    getline(sstream, SKU, ';');
    getline(sstream, Brand, ';');
    getline(sstream, Model, ';');

    string sPcategory;
    getline(sstream, sPcategory, ';');
    if(sPcategory == "Men")
        Pcategory = Men;
    else if(sPcategory == "Women")
        Pcategory = Women;
    else if(sPcategory == "Kids")
        Pcategory = Kids;

    string sPcolor;
    getline(sstream, sPcolor, ';');
    if(sPcolor == "Red")
        Pcolor = Red;
    else if(sPcolor == "Blue")
        Pcolor = Blue;
    else if(sPcolor == "White")
        Pcolor = White;

    string sPsize;
    getline(sstream, sPsize, ';');
    if(sPsize == "S")
        Psize = S;
    else if(sPsize == "M")
        Psize = M;
    else if(sPsize == "L")
        Psize = L;
    else if(sPsize == "XL")
        Psize = XL;
    else if(sPsize == "XXL")
        Psize = XXL;

    string sPrice;
    getline(sstream, sPrice, ';');
    Price= atof(sPrice.c_str());

    string sCount;
    getline(sstream, sCount, ';');
    Count= atoi(sCount.c_str());
}
