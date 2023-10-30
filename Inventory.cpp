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
};

void Inventory::addItem(Item item)
{
	bool found = false;

	for(auto& i : inventoryItems)
	{
		if(i.getID() == item.getID())
		{
			cout<<"Item already exists in the system"<<endl;
			found = true;
			break;
		}
	}

	if(!found)
	{
		inventoryItems.push_back(item);
		cout<<item.getQuantity()<<" "<<item.getItemName()<<"(s) have been added successfully"<<endl;
	}
}

void Inventory::deleteItem(int id)
{
	bool found = false;

	for(auto& i : inventoryItems)
	{
		if(i.getID() == item.getID())
		{
			cout<<i.getItemName()<<" has been deleted from the system"<<endl;
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
		cout<<"ID: "<<i.getID()<<endl;
		cout<<"Item Name: "<<i.getItemName()<<endl;
		cout<<"Quantity: "<<i.getQuantity()<<endl;
		cout<<"Category: "<<i.getCategory()<<endl;
		cout<<"-------------------------------------------------"<<endl;
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

int main()
{
	Inventory inventory;

	char userInput;

	do
	{
		cout<<"Choose an action to preform"<<endl;
		cout<<"1. Add an item"<<endl;
		cout<<"2. Remove an item"<<endl;
		cout<<"3.View all items"<<endl;
		cout<<"4. Save"<<endl;
		cout<<"Q. Exit"<<endl;
		cin>>userInput;

		switch(userInput)
		{
		case '1':
			{
				int id;
				string itemName;
				string category;
				int quantity;

				cout<<"Enter ID number: "<<endl;
				cin>>id;
				cout<<"Enter the name of the item"<<endl;
				cin>>itemName;
				cout<<"Enter category of the item"<<endl;
				cin>>category;
				cout<<"Enter the quantity of item(s)"<<endl;
				cin>>quantity;

				Item item(itemName,category,id,quantity);
				inventory.addItem(item);
				break;
			}
		}
	} while(true);

	return 0;
}