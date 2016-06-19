#include "Store.h"
#include <iostream>
#include <cstring>
#include <fstream>

Store::Store()
{
    maxSize = 5;
    currentSize = 0;
    productList = new Product*[maxSize];
}

Store::~Store()
{
    for (int i = 0; i < currentSize; i++)
        delete productList[i];
    delete[] productList;
}

int Store::FindProduct(string sku) const
{
    for (int i = 0; i < currentSize; i++)
        if ((productList[i]->getSKU()) == sku)
            return i;

    return -1;
}

void Store::Grow()
{
    maxSize = currentSize + 5;
    Product** newList = new Product*[maxSize];

    for (int i = 0; i < currentSize; i++)
        newList[i] = productList[i];

    delete[] productList;
    productList = newList;
}

void Store::Insert()
{
    if (currentSize == maxSize)
        Grow();

    cout << "\nType the information for the product, each category followed"
        << "\n by RETURN or ENTER:\n> ";
    productList[currentSize] = new Product();
    cin >> *productList[currentSize];
    currentSize++;
}

void Store::Remove()
{
    string sku;
    cout << "\nType the SKU of the product to be removed, followed by <Enter>: ";
    getline(cin, sku);

    int thisProduct = FindProduct(sku);

    if (thisProduct == -1)
        cout << "Product with SKU:" << sku << " not found in the store";
    else
    {
        delete productList[thisProduct];

        for (int j = thisProduct + 1; j < currentSize; j++)
            productList[j - 1] = productList[j];

        currentSize--;
        cout << "Product removed.\n";
    }
}

void Store::Update()
{
    cout << "\nPlease enter the SKU of the product to be modified: ";
    string sku;
    getline(cin, sku);

    int thisProduct = FindProduct(sku);

    if (thisProduct == -1)
        cout << "Product with SKU:" << sku << " not found in the store";
    else
    {
        cout << "\nCurrent product is: \n";
        cout << *productList[thisProduct];

        cout << "\nReplace with new product as follows: \n";
        cin >> *productList[thisProduct];
    }
}

void Store::DisplayProducts() const
{
    if (currentSize == 0)
    {
        cout << "\nCurrent store is empty.\n";
        return;
    }

    // Display a header.
    cout << "\n\tSKU\tBrand\t\tModel\t\tCategory\tColor\t\tSize\t\tPrice\tCount\n\n";

    for (int i = 0; i < currentSize; i++)
        cout << *productList[i];
}

void Store::Save()
{
    cout << "\nPlease enter the name of file to save to: ";
    string fName;
    getline(cin, fName);
    ofstream ofs(fName.c_str());

    ofs << "SKU;Brand;Model;Category;Color;Size;Price;Count" << endl;

    for (int i = 0; i < currentSize; i++)
    {
        ofs << productList[i]->Save() << endl;
    }
    ofs.close();
    cout << "Store saved.\n";
}

void Store::Load()
{
    cout << "\nPlease enter the name of file to load: ";
    string fName;
    getline(cin, fName);
    ifstream ifs(fName.c_str());
    for (int i = 0; i < currentSize; i++)
        delete productList[i];
    currentSize = 0;
    string line;
    getline(ifs, line);
    while (getline(ifs, line))
    {
        Product *pProduct = new Product();
        pProduct->Load(line);
        productList[currentSize] = pProduct;
        currentSize++;
    }
    ifs.close();
    cout << "Product loaded.\n";
}
