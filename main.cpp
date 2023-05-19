#include "HashTable.h"


int main()
{
    HashTable ht;
    
    ht.insertFromFile("text.txt");
    ht.insertFromFile("text1.txt");

    ht.printWordFrequencies();

    int itemCount = ht.getNumberofItems();

    std::cout << "Number of items in the hash table: " << itemCount << std::endl;

    ht.printTopWords(3);

    return 0;
}