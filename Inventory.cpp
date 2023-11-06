#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class Item{
private:
	string itemName;
	string category;
	int quantity;
	int id;

public:
	Item(string itemName, string category, int id, int quantity)
	{
		this->itemName = itemName;
		this->category = category;
		this->id = id;
		this->quantity = quantity;
	}

	string getItemName() const{return itemName;}
	string getCategory() const{return category;}
	int getID() const{return id;}
	int getQuantity() const{return quantity;}

	void setItemName(string itemName){this->itemName = itemName;}
	void setCategory(string category){this->category = category;}
	void setID(int id){this->id = id;}
	void setQuantity(int quantity){this->quantity = quantity;}
};

class Inventory{
private:
	vector<Item> inventoryItems;

public:
	void addItem(Item item);
	void deleteItem(int id);
	void printAllItems();
	void saveItemsToFile(string filename);
	void loadItemsFromFile(string filename);
	Item* findItem(int id);
	Item* searchByCatergory(string category);
	void updateItem(int id, string name, string category, int quantity);
	void upadateItemQuantity(int id, int quantity);
};

void Inventory::addItem(Item item)
{
	bool found = false;

	for(auto& i : inventoryItems)
	{
		if(i.getID() == item.getID())
		{
			cout<<"Item already exists in the system"<<endl;
			cout<<"-----------------------------------------------------------"<<endl;
			found = true;
			break;
		}
	}

	if(!found)
	{
		inventoryItems.push_back(item);
		cout<<item.getQuantity()<<" "<<item.getItemName()<<"(s) have been added successfully"<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
	}
}

void Inventory::deleteItem(int id)
{
	bool found = false;

	for(auto i = inventoryItems.begin(); i != inventoryItems.end(); i++)
	{
		if(i->getID() == id)
		{
			cout<<i->getItemName()<<" has been deleted from the system"<<endl;
			cout<<"-----------------------------------------------------------"<<endl;
			inventoryItems.erase(i);
			found = true;
			break;
		}
	}

	if(!found)
	{
		cout<<"Item is not in the system"<<endl;
	}
}

void Inventory::printAllItems()
{
	for(auto& i : inventoryItems)
	{
		cout<<"-----------------------------------------------------------"<<endl;
		cout<<"ID: "<<i.getID()<<endl;
		cout<<"Item Name: "<<i.getItemName()<<endl;
		cout<<"Quantity: "<<i.getQuantity()<<endl;
		cout<<"Category: "<<i.getCategory()<<endl;
		cout<<"-----------------------------------------------------------"<<endl;
	}
}

void Inventory::saveItemsToFile(string filename) 
{
    ofstream file;
    file.open(filename, ios::out | ios::app);
    for (int i = 0; i < inventoryItems.size(); i++) 
        {
           	Item p = inventoryItems[i];
            file<<p.getID()<<","<<p.getItemName()<<","<<p.getCategory()<<","<<p.getQuantity()<<endl;
        }
    file.close();
}

void Inventory::loadItemsFromFile(string filename) 
{
    ifstream file;
    file.open(filename);

    if (file.is_open()) 
    {
        string line;
        while (getline(file, line)) 
        {
           	stringstream ss(line);
            string idStr, name, category, quantityStr;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, category, ',');
            getline(ss, quantityStr);

            int id = stoi(idStr);
            int quantity = stoi(quantityStr);

            Item item(name,category,id,quantity);
            inventoryItems.push_back(item);
        }

        file.close();
    } else {
            cout << "Error: Could not open file " << filename << endl;
            cout<<"-----------------------------------------------------------"<<endl;
    }
}

Item* Inventory::findItem(int id)
{
	for(auto i = inventoryItems.begin(); i != inventoryItems.end(); i++)
	{
		if(i->getID()==id)
        {
            return &(*i);
        }
	}
	return nullptr;
}

void Inventory::updateItem(int id, string name, string category, int quantity)
{
	bool found = false;

	for(auto& i : inventoryItems)
	{
		if(i.getID() == id)
		{
			i.setItemName(name);
			i.setCategory(category);
			i.setQuantity(quantity);
			found = true;
			break;
		}
	}
	if (!found)
    {
        cout << "ID does not exist." << endl;
        cout<<"-----------------------------------------------------------"<<endl;
    }
}

Item* Inventory::searchByCatergory(string category)
{
	for (auto& i : inventoryItems) {
    if (i.getCategory() == category) {
    	cout<<"-----------------------------------------------------------"<<endl;
      	cout<<"ID: "<<i.getID()<< endl;
      	cout<<"Name: "<<i.getItemName()<<endl;
      	cout<<"Category: "<<i.getCategory()<<endl;
      	cout<<"Quantity: "<<i.getQuantity()<<endl;
      	cout<<"-----------------------------------------------------------"<<endl;
    }
  }
	return nullptr;
}

void Inventory::upadateItemQuantity(int id, int quantity)
{
	bool found = false;

	for(auto& i : inventoryItems)
	{
		if(i.getID() == id)
		{
			i.setQuantity(quantity);
			found = true;
			break;
		}
	}
	if (!found)
    {
        cout << "ID does not exist." << endl;
        cout<<"-----------------------------------------------------------"<<endl;
	}
}
