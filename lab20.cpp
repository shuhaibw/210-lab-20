// COMSC-210 | Lab 20 | Shuhaib Walahi
// IDE used: VS Code

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> 

using namespace std;

const int SIZE = 3;
// min and max for random prices
const int MIN = 10000, MAX = 99999;

class Chair 
{
    private:
        int legs;
        double * prices;

    public:
    // default constructor
    Chair() 
    {
        prices = new double[SIZE];
        // randomly assign 3 or 4 legs
        legs = int (rand() % 2) + 3;
        for (int i = 0; i < SIZE; i++)
        {
            // randomly select prices
            prices[i] = (rand() % (MAX-MIN+1) + MIN) / (double) 100;
        }
    }

    // parameter constructor
    Chair(int l, const double pr[SIZE]) 
    {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++)
        {
            prices[i] = pr[i];
        }   
    }

    // Destructor
    ~Chair() 
    {
        delete[] prices;
    }

    // setters and getters
    void setLegs(int l) { legs = l; }

    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) 
    {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() 
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += prices[i];
        }
        return sum / SIZE;
    }

    void print() 
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
        {
            cout << prices[i] << " ";
        }
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() 
{
    // seed random num generator
    srand(static_cast<unsigned int>(time(0)));

    cout << fixed << setprecision(2);

    // creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->print();
    // free the memory
    delete chairPtr;
    chairPtr = nullptr;

    // creating dynamic chair object with constructor
    double chairPrices[SIZE] = {525.25, 434.34, 252.52};
    // sending in an array with 3 prices
    Chair *livingChair = new Chair(3, chairPrices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    // creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    // print the collection
    for (int i = 0; i < SIZE; i++)
    {
        collection[i].print();
    }

    // free the dynamic array
    delete[] collection;
    collection = nullptr;

    return 0;
}
