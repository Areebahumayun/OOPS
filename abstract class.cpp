#include <iostream>
#include<string>
#include<cstdlib>
#include<stdexcept>  // Added for exception handling
using namespace std;

class product{
   protected:      //attributes of product 
      int id;
      string name;
      string category;
      float price;
      int quantity;
      string availability;
      string dateOfExpiry;
	friend class cart ;
};

class Item : public product {
   public:
   	int getID(){
   		return id;
	   }
      Item(){
	   price=0; quantity=0; }//CONSTRUCTOR
      void AdminAddItem(){
          try{
              cout << "\t\t\tEnter id: "; 
              if(!(cin >> id)) throw invalid_argument("Invalid ID! Must be a number.");
              
              cout << "\t\t\tEnter name: "; 
              if(!(cin >> name)) throw invalid_argument("Invalid name entered.");
              
              cout << "\t\t\tEnter category: "; 
              if(!(cin >> category)) throw invalid_argument("Invalid category entered.");
              
              cout << "\t\t\tEnter price: "; 
              if(!(cin >> price)) throw invalid_argument("Invalid price! Must be a number.");
              if(price < 0) throw out_of_range("Price cannot be negative!");
              
              cout << "\t\t\tEnter quantity: "; 
              if(!(cin >> quantity)) throw invalid_argument("Invalid quantity! Must be a number.");
              if(quantity < 0) throw out_of_range("Quantity cannot be negative!");
              
              availability = (quantity <= 0) ? "out of stock" : "in stock";
              
              cout << "\t\t\tEnter date of expiry: "; 
              if(!(cin >> dateOfExpiry)) throw invalid_argument("Invalid date entered.");
          }
          catch(const invalid_argument& e){
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "INPUT ERROR: " << e.what() << endl;
          }
          catch(const out_of_range& e){
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "RANGE ERROR: " << e.what() << endl;
          }
          catch(...){
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "Unknown error occurred while adding item!" << endl;
          }
       }
      void ShowItem(){
         cout << "\t\t\t ID:" << id << endl;
         cout << "\t\t\t NAME:" << name << endl;
         cout << "\t\t\t CATEGORY:" << category << endl;
         cout << "\t\t\t PRICE:" << price << endl;
         cout << "\t\t\t QUANTITY:" << quantity << endl;
         cout << "\t\t\t AVAILABILITY:" << availability << endl;  // Added
         cout << "\t\t\t DATE OF EXPIRY:" << dateOfExpiry << endl;
         // Fixed ternary operator syntax
         if(quantity <= 0) cout << "\t\t\tOUT OF STOCK\n"; 
         else cout << "\t\t\tIN STOCK\n";
      }
      void modifyItem(){
          try{
              int choose;
              cout << "\n------MODIFY-------\n";
              cout << "1)Name\n2)Category\n3)Price\n4)Quantity\n5)Date Of Expiry\n";
              cout << "Enter choice: ";
              if(!(cin >> choose)) throw invalid_argument("Invalid choice! Must be a number.");
              
              switch(choose){
                  case 1: 
                      cout << "\t\t\tEnter new name:"; 
                      if(!(cin >> name)) throw invalid_argument("Invalid name!");
                      break;
                  case 2: 
                      cout << "\t\t\tEnter new category:"; 
                      if(!(cin >> category)) throw invalid_argument("Invalid category!");
                      break;
                  case 3: 
                      cout << "\t\t\tEnter new price:"; 
                      if(!(cin >> price)) throw invalid_argument("Invalid price!");
                      if(price < 0) throw out_of_range("Price cannot be negative!");
                      break;
                  case 4: 
                      cout << "\t\t\tEnter new quantity:"; 
                      if(!(cin >> quantity)) throw invalid_argument("Invalid quantity!");
                      if(quantity < 0) throw out_of_range("Quantity cannot be negative!");
                      availability = (quantity <= 0) ? "out of stock" : "in stock"; 
                      break;
                  case 5: 
                      cout << "\t\t\tEnter new date of expiry:"; 
                      if(!(cin >> dateOfExpiry)) throw invalid_argument("Invalid date!");
                      break;
                  default: 
                      throw invalid_argument("Invalid choice! Enter 1-5 only.");
              }
          }
          catch(const invalid_argument& e){
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "INPUT ERROR: " << e.what() << endl;
          }
          catch(const out_of_range& e){
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "RANGE ERROR: " << e.what() << endl;
          }
          catch(...){
              cin.clear();
              cin.ignore(1000, '\n');
              cout << "Unknown error occurred while modifying item!" << endl;
          }
	  }
};

class cart{
    Item arr[20];
    int total;
    int noOfItems;
public:
    cart(){
        total = 0;
        noOfItems = 0;
    }

    void AddToCart(Item i){
        try{
            if(noOfItems == 20) throw overflow_error("Cart is full! Cannot add more items.");
            
            arr[noOfItems] = i;
            cout << "Enter quantity: ";
            if(!(cin >> arr[noOfItems].quantity)) throw invalid_argument("Invalid quantity!");
            if(arr[noOfItems].quantity <= 0) throw out_of_range("Quantity must be greater than 0!");
            
            total += arr[noOfItems].price * arr[noOfItems].quantity;
            noOfItems++;
        }
        catch(const overflow_error& e){
            cout << "CART ERROR: " << e.what() << endl;
        }
        catch(const invalid_argument& e){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INPUT ERROR: " << e.what() << endl;
        }
        catch(const out_of_range& e){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "RANGE ERROR: " << e.what() << endl;
        }
        catch(...){
            cout << "Unknown error occurred while adding to cart!" << endl;
        }
    }

    void DeleteFromCart(){
        try{
            if(noOfItems == 0) throw underflow_error("Cart is already empty!");
            
            int id;
            cout << "Enter ID to delete: ";
            if(!(cin >> id)) throw invalid_argument("Invalid ID! Must be a number.");
            
            int index = -1;
            for(int i = 0; i < noOfItems; i++){
                if(arr[i].getID() == id){
                    index = i;
                    break;
                }
            }
            if(index == -1) throw runtime_error("Item with given ID not found in cart!");
            
            total -= arr[index].price * arr[index].quantity;
            
            for(int i = index; i < noOfItems - 1; i++){
                arr[i] = arr[i + 1];
            }
            noOfItems--;
            cout << "Item deleted successfully!" << endl;
        }
        catch(const underflow_error& e){
            cout << "CART ERROR: " << e.what() << endl;
        }
        catch(const invalid_argument& e){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INPUT ERROR: " << e.what() << endl;
        }
        catch(const runtime_error& e){
            cout << "ERROR: " << e.what() << endl;
        }
        catch(...){
            cout << "Unknown error occurred while deleting from cart!" << endl;
        }
    }

    void ViewCart(){
        try{
            if(noOfItems == 0) throw underflow_error("Cart is empty! Nothing to display.");
            
            cout << "\nID\tName\tPrice\tQty\tLineTotal\n";
            for(int i = 0; i < noOfItems; i++){
                cout << arr[i].getID() << "\t"  // Fixed getID()
                     << arr[i].name << "\t"
                     << arr[i].price << "\t"
                     << arr[i].quantity << "\t"
                     << arr[i].price * arr[i].quantity << endl;
            }
        }
        catch(const underflow_error& e){
            cout << "VIEW ERROR: " << e.what() << endl;
        }
        catch(...){
            cout << "Unknown error occurred while viewing cart!" << endl;
        }
    }

    void CheckOut(){
        try{
            if(noOfItems == 0) throw underflow_error("Cannot checkout! Cart is empty.");
            ViewCart();
            cout << "\nTotal Bill: Rs." << total << endl;
        }
        catch(const underflow_error& e){
            cout << "CHECKOUT ERROR: " << e.what() << endl;
        }
        catch(...){
            cout << "Unknown error occurred during checkout!" << endl;
        }
    }
};

class admin{
    Item inventory[100];  // Inventory array
    int invCount = 0;     // Inventory counter
    
public:
   void AdminMenu(){ 
	  int choice;
      while(true){
         cout << "\t\t\t______________________________\t\t" << endl;
         cout << "\t\t\t     ADMINISTRATOR MENU      \t\t" << endl;
         cout << "\t\t\t______________________________\t\t" << endl;
         cout << "\t\t\t 1)add item\n";
         cout << "\t\t\t 2)delete item\n";
         cout << "\t\t\t 3)modify item\n";
         cout << "\t\t\t 4)show inventory\n";
         cout << "\t\t\t 5)back to main menu\n";
         cout << "\t\t\tEnter ur choice: ";
         
         try{
             if(!(cin >> choice)) throw invalid_argument("Invalid choice! Enter a number.");
         }
         catch(const invalid_argument& e){
             cin.clear();
             cin.ignore(1000, '\n');
             cout << "INPUT ERROR: " << e.what() << endl;
             continue;
         }
         
         system("cls");
         switch(choice){
            case 1: addItem();    break;
            case 2: deleteItem(); break;
            case 3: modifyItem(); break;
            case 4: showInventory(); break;
            case 5: return;
            default: cout << "Invalid choice! Enter 1-5 only.\n"; break;
         }
         cout << "\nPress Enter to continue...";
         cin.ignore(); cin.get();
         system("cls");
      }
   }
   
private:
   void addItem(){
       try{
           if(invCount >= 100) throw overflow_error("Inventory is full! Cannot add more items.");
           inventory[invCount].AdminAddItem();
           invCount++;
           cout << "Item added successfully!\n";
       }
       catch(const overflow_error& e){
           cout << "INVENTORY ERROR: " << e.what() << endl;
       }
       catch(...){
           cout << "Unknown error occurred while adding item!" << endl;
       }
   }
   
   void deleteItem(){
       try{
           if(invCount == 0) throw underflow_error("Inventory is empty! Nothing to delete.");
           
           int id;
           cout << "Enter ID to delete: ";
           if(!(cin >> id)) throw invalid_argument("Invalid ID! Must be a number.");
           
           int index = -1;
           for(int i = 0; i < invCount; i++){
               if(inventory[i].getID() == id){
                   index = i;
                   break;
               }
           }
           if(index == -1) throw runtime_error("Item with given ID not found in inventory!");
           
           // Shift items
           for(int i = index; i < invCount - 1; i++){
               inventory[i] = inventory[i + 1];
           }
           invCount--;
           cout << "Item deleted!\n";
       }
       catch(const underflow_error& e){
           cout << "INVENTORY ERROR: " << e.what() << endl;
       }
       catch(const invalid_argument& e){
           cin.clear();
           cin.ignore(1000, '\n');
           cout << "INPUT ERROR: " << e.what() << endl;
       }
       catch(const runtime_error& e){
           cout << "ERROR: " << e.what() << endl;
       }
       catch(...){
           cout << "Unknown error occurred while deleting item!" << endl;
       }
   }
   
   void modifyItem(){
       try{
           if(invCount == 0) throw underflow_error("Inventory is empty! Nothing to modify.");
           
           int id;
           cout << "Enter ID to modify: ";
           if(!(cin >> id)) throw invalid_argument("Invalid ID! Must be a number.");
           
           int index = -1;
           for(int i = 0; i < invCount; i++){
               if(inventory[i].getID() == id){
                   index = i;
                   break;
               }
           }
           if(index == -1) throw runtime_error("Item with given ID not found in inventory!");
           
           inventory[index].ShowItem();
           inventory[index].modifyItem();
           cout << "Item modified!\n";
       }
       catch(const underflow_error& e){
           cout << "INVENTORY ERROR: " << e.what() << endl;
       }
       catch(const invalid_argument& e){
           cin.clear();
           cin.ignore(1000, '\n');
           cout << "INPUT ERROR: " << e.what() << endl;
       }
       catch(const runtime_error& e){
           cout << "ERROR: " << e.what() << endl;
       }
       catch(...){
           cout << "Unknown error occurred while modifying item!" << endl;
       }
   }
   
   void showInventory(){
       try{
           if(invCount == 0) throw underflow_error("No items in inventory!");
           cout << "\n=== INVENTORY ===\n";
           for(int i = 0; i < invCount; i++){
               inventory[i].ShowItem();
               cout << "----------------\n";
           }
       }
       catch(const underflow_error& e){
           cout << "INVENTORY ERROR: " << e.what() << endl;
       }
       catch(...){
           cout << "Unknown error occurred while showing inventory!" << endl;
       }
   }
};

class customer{
	public :
	 void customerMenu(){
	 	int choiceC;
	 	cart basicCart;
	 	while(true){
			cout << "\t\t\t_____________________________\t\t" << endl;
			cout << "\t\t\t WELCOME TO OOP'S SUPER MART \t\t" << endl;
			cout << "\t\t\t_____________________________\t\t" << endl;
			cout << "\t\t\t1) ADD TO CART\n";
			cout << "\t\t\t2) DELETE FROM CART\n";
			cout << "\t\t\t3) VIEW CART\n";
			cout << "\t\t\t4) CHECKOUT\n";
			cout << "\t\t\t5) Return to main menu\n";
			cout << "\t\t\tEnter your choice: ";
			
			try{
			    if(!(cin >> choiceC)) throw invalid_argument("Invalid choice! Enter a number.");
			}
			catch(const invalid_argument& e){
			    cin.clear();
			    cin.ignore(1000, '\n');
			    cout << "INPUT ERROR: " << e.what() << endl;
			    continue;
			}
			
			system("cls");
			switch(choiceC){
				case 1: {
					// TODO: Show inventory first, then select item
					Item temp;
					cout << "Enter item details manually (for demo):\n";
					temp.AdminAddItem();
					basicCart.AddToCart(temp);
					break;
				}
				case 2: basicCart.DeleteFromCart(); break;
				case 3: basicCart.ViewCart(); break;
				case 4: basicCart.CheckOut(); break;
				case 5: return;
				default: cout << "Invalid choice! Enter 1-5 only.\n";
			}
			cout << "\nPress Enter to continue...";
			cin.ignore(); cin.get();
			system("cls");
		}
	}
};

class superMarket {
int choice;     
Item stock;    
bool itemAdded = false;

void adminLogin() {
    try{
        string id, pass;
        cout << "\t\t\t______________________________\t\t" << endl;
        cout << "\t\t\t        ADMIN LOGIN         \t\t" << endl;
        cout << "\t\t\t______________________________\t\t" << endl;
        cout << "\t\t\tEnter ID: ";  
        if(!(cin >> id)) throw invalid_argument("Invalid ID entered!");
        cout << "\t\t\tEnter Password: "; 
        if(!(cin >> pass)) throw invalid_argument("Invalid password entered!");
        
        if(id == "admin" && pass == "1234") {
            cout << "Login Successful!\n";
            admin ad;
            system("cls");
            ad.AdminMenu();
        } else {
            throw runtime_error("Invalid ID or Password!");
        }
    }
    catch(const invalid_argument& e){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "INPUT ERROR: " << e.what() << endl;
        system("cls");
    }
    catch(const runtime_error& e){
        cout << "LOGIN ERROR: " << e.what() << endl;
        system("cls");
    }
    catch(...){
        cout << "Unknown error occurred during login!" << endl;
        system("cls");
    }
}

public:
		void mainMenu() {
          while(true){
			    cout << "\t\t\t______________________________\t\t" << endl;
                cout << "\t\t\t   SMART SUPERMARKET SYSTEM   \t\t" << endl;
                cout << "\t\t\t______________________________\t\t" << endl;
                cout << "\t\t\t1. Login as Administrator\n";
                cout << "\t\t\t2. Customer\n";
                cout << "\t\t\t3. Exit\n";
                cout << "\t\t\tEnter choice: ";
                
                try{
                    if(!(cin >> choice)) throw invalid_argument("Invalid choice! Enter a number.");
                }
                catch(const invalid_argument& e){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "INPUT ERROR: " << e.what() << endl;
                    continue;
                }
                
                system("cls");
                switch(choice) {
				   case 1: adminLogin(); break;
                   case 2: {customer def; def.customerMenu(); break;}
                   case 3: cout << "Exiting...\n"; exit(0); break;
                   default: cout << "Invalid choice! Enter 1-3 only.\n";
                }
            }
        }
};

int main() {
    try{
        superMarket s1;
        s1.mainMenu();
    }
    catch(...){
        cout << "A fatal error occurred! Program will exit." << endl;
    }
	return 0;
}
