#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include <string>

class Store
{
    public:
        Store();
        ~Store();
        void Insert();
        void Remove();
        void Update();
        void DisplayProducts() const;
        void Save();
        void Load();
        int getMaxSize() const { return maxSize; }
        int getCurrentSize() const { return currentSize; }
        Product** getProductList() const { return productList; }

    private:
        int	maxSize, currentSize;
        Product** productList;
        void Grow();
        int FindProduct(string) const;
};

#endif // STORE_H
