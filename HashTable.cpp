#include "HashTable.h"
#include "LinkedList.h"
#include <vector>

int HashTable::hash(std::string key)
{
    int value = 0;
    for (int i = 0; i < key.length(); i++)
    {
        value += key[i];
    }

    return (key.length() * value) % length;
}

HashTable::HashTable(int tableLength)
{
    if (tableLength <= 0)
    {
        tableLength = 10;
    }

    arr = new LinkedList[tableLength];
    length = tableLength;
}

HashTable::~HashTable()
{
    delete[] arr;
}

void HashTable::insert(Node* key)
{
    std::string lowercaseKey = key->key_;
    
    lowercaseKey.erase(std::remove_if(lowercaseKey.begin(), lowercaseKey.end(), [](char c) { return !std::isalpha(c); }), lowercaseKey.end());
    std::transform(lowercaseKey.begin(), lowercaseKey.end(), lowercaseKey.begin(), [](char c) { return std::tolower(c); });

    if (!lowercaseKey.empty())
    {
        int index = hash(lowercaseKey);
        Node* existingNode = arr[index].getItem(lowercaseKey);

        if (existingNode)
        {
            existingNode->frequency_++; 
            delete key; 
        }
        else
        {
            arr[index].insert(key); 
        }
    }
}

bool HashTable::remove(std::string key)
{
    int index = hash(key);
    return arr[index].remove(key);
}

Node* HashTable::getItemByKey(std::string key)
{
    int index = hash(key);
    return arr[index].getItem(key);
}

int HashTable::getLength()
{
    return length;
}

int HashTable::getNumberofItems()
{
    int itemCount = 0;
    for (int i = 0; i < length; i++)
        itemCount += arr[i].getLength();
    return itemCount;
}

void HashTable::insertFromFile(std::string filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        std::string word;
        while (inputFile >> word)
        {
            if (std::all_of(word.begin(), word.end(), ::isalpha))
            {
                Node* node = new Node{ word, 0 };
                insert(node);
            }
        }
        inputFile.close();
    }
    else
    {
        std::cout << "Unable to open file: " << filename << std::endl;
    }
}

void HashTable::printWordFrequencies()
{

    std::cout << "Word Frequencies:\n";
    for (int i = 0; i < length; i++)
    {
        Node* current = arr[i].getHead();
        while (current != nullptr)
        {
            if (current->frequency_ != 0)
            {
                std::cout << "Word: " << current->key_ << ", Frequency: " << current->frequency_ << std::endl;
            }
            
            current = current->next;
        }
    }

}

void HashTable::printTopWords(int n)
{
    std::cout << "\nTop " << n << " Words by Frequency:\n";

    std::vector<std::pair<std::string, int>> wordFreqs;
    for (int i = 0; i < length; i++)
    {
        Node* current = arr[i].getHead();
        while (current != nullptr)
        {
            wordFreqs.push_back(std::make_pair(current->key_, current->frequency_));
            current = current->next;
        }
    }

    
    std::sort(wordFreqs.begin(), wordFreqs.end(),
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
        {
            return a.second > b.second;
        });

    
    int count = 0;
    for (const auto& pair : wordFreqs)
    {
        std::cout << "Word: " << pair.first << ", Frequency: " << pair.second << std::endl;
        count++;
        if (count == n)
            break;
    }
}
