// ProductNotFoundException.hpp

#pragma once
#include <iostream>
#include <string>

using namespace std;

class ProductNotFoundException {
    
public:
    ProductNotFoundException() { };
    ProductNotFoundException(string p_message) { message = p_message; };
    string what() { return message; };
    
private:
    string message;
};

// Driver.cpp

#include <iostream>
#include <string>
#include "ProductNotFoundException.hpp"

using namespace std;

int getProductID(int ids[], string names[], int numProducts, string target) throw(...) {
    
    for (int i = 0; i < numProducts; i++) {
        if (names[i] == target)
            return ids[i];
    }
    throw ProductNotFoundException("Exception: The product is not included in the array!"); //Not found
}
                                    
int main() {
    
    int productIds[]{ 4, 5, 8, 10, 13 };
    string products[]{ "computer", "flash drive", "mouse", "printer", "camera" };
    
    try {
        
        cout << getProductID(productIds, products, 5, "mouse") << endl;
        cout << getProductID(productIds, products, 5, "camera") << endl;
        cout << getProductID(productIds, products, 5, "laptops") << endl;
        
        cout << endl;
    }
    catch (ProductNotFoundException e){
        
        cout << e.what() << endl;
    }
    catch (overflow_error e) {
        
        cout << e.what() << endl;
    }
    catch ( underflow_error e) {
        
        cout << e.what() << endl;
    }
    catch (length_error e) {
     
        cout << e.what() << endl;
    }
    catch(out_of_range e) {
        
        cout << e.what() << endl;
    }
    
    return 0;
    
}
