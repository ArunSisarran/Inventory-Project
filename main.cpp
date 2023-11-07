#include "Inventory.cpp"
using namespace std;

int main()
{
	Inventory inventory;

	char userInput;

	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"----------------Inventory Management System----------------"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;

	do
	{
		cout<<"Choose an action to preform"<<endl;
		cout<<"1. Add an item"<<endl;
		cout<<"2. Remove an item"<<endl;
		cout<<"3. Find an item"<<endl;
		cout<<"4. Search by category"<<endl;
		cout<<"5. Update an item"<<endl;
		cout<<"6. Update an item's quantity"<<endl;
		cout<<"7. View all items"<<endl;
		cout<<"8. Save"<<endl;
		cout<<"9. Load"<<endl;
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
		case '2':
			{
				int id;
				cout<<"Enter product ID number"<<endl;
				cin>>id;
				inventory.deleteItem(id);
				break;
			}
		case '3':
			{
				int id;
				cout<<"Enter the item ID you want to locate: "<<endl;
				cin>>id;
				Item* item = inventory.findItem(id);
				if(item)
				{
					cout << "ID: "<<item->getID()<<endl;
					cout << "Name: " << item->getItemName() << endl;
                	cout << "Category: " << item->getCategory() << endl;
                	cout << "Quantity: " << item->getQuantity() << endl;
                	cout<<"-----------------------------------------------------------"<<endl;
                	break;
				}

			}
		case '4':
			{
				string category;
				cout<<"Enter a category: "<<endl;
				cin>>category;
				inventory.searchByCatergory(category);
				break;
			}
		case '5':
			{
				int id;
				string name;
				string category;
				int quantity;

				cout<<"Enter the item ID to update"<<endl;
				cin>>id;
				cout<<"Enter new item name"<<endl;
				cin>>name;
				cout<<"Enter new category"<<endl;
				cin>>category;
				cout<<"Enter new quantity"<<endl;
				cin>>quantity;
				inventory.updateItem(id,name,category,quantity);
				cout<<"Updated "<<name<<"(s) successfully"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				break;
			}
		case '6':
			{
				int id;
				int quantity;

				cout<<"Enter the item ID to update"<<endl;
				cin>>id;
				cout<<"Enter new quantity"<<endl;
				cin>>quantity;

				inventory.updateItemQuantity(id,quantity);
				cout<<"Updated successfully"<<endl;
				cout<<"-----------------------------------------------------------"<<endl;
				break;
			}
		case '7':
			{
				inventory.printAllItems();
				break;
			}
		case '8':
			{
				inventory.saveItemsToFile("Inventory.csv");
				cout << "Inventory saved to file." << endl;
            	cout << "-----------------------------------------------------------" <<endl;
            	break;
			}
		case '9':
			{
				inventory.loadItemsFromFile("Inventory.csv");
            	cout << "Inventory loaded from file." << endl;
            	cout << "-----------------------------------------------------------" <<endl;
            	break;
			}
		case 'q':
		case 'Q':
			{
				return 0;
			}
		default:
			{
				cout<<"Invalid selection, try again"<<endl;
				cout << "-----------------------------------------------------------" <<endl;
				break;
			}
		}
	} while(true);

	return 0;
}
