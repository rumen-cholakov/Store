#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;

enum Category { Men = 1, Women, Kids };
enum Color { Red = 1, Blue, White };
enum Size { S = 1, M, L, XL, XXL };

class Product
{
    friend istream& operator >> (istream& a, Product& e);
    friend ostream& operator << (ostream& a, const Product& e);

    public:
        Product();
        Product Set();
        Product(const Product&);
        Product Change(string);
        string Save();
        void Load(string &);
        string getSKU() const { return SKU; }
        string getBrand() const { return Brand; }
        string getModel() const { return Model; }
        Category getCategory() const { return Pcategory; }
        Color getColor() const { return Pcolor; }
        Size getSize() const { return Psize; }
        double getPrice() const { return Price; }
        int getCount() const { return Count; }
    private:
        string SKU;
        string Brand;
        string Model;
        Category Pcategory;
        Color Pcolor;
        Size Psize;
        double Price;
        int Count;
};
#endif // PRODUCT_H
