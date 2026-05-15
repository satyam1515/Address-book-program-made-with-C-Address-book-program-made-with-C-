#include<iostream>
#include<string>
using namespace std;
const int MAX_CONTACTS=100;
struct Contact
{
    string name;
    string phoneNumber;
    string address;
};
class AddressBook
{
	private:
	    Contact contacts[MAX_CONTACTS];
	    int contactCount;
	
	public:
	    AddressBook(): contactCount(0){}
		    void addContact()
			{
	        if (contactCount>=MAX_CONTACTS)
			{
	            cout<<"\n Address book is full!"<<endl;
	            return;
	        }	
	        Contact newContact;
	        cout<<"\n Enter name: "<<endl;
	        cin.ignore();
	        getline(cin, newContact.name);
	        cout<<"Enter phone number: "<<endl;
	        getline(cin, newContact.phoneNumber);
	        cout<<"Enter address: "<<endl;
	        getline(cin, newContact.address);
	        contacts[contactCount++]=newContact;
	        cout << "\n Contact added successfully!"<<endl;
	    }	
	    void searchContact()
		{
	        string name;
	        cout<<"\n Enter name to search: "<<endl;
	        cin.ignore();
	        getline(cin, name);	
	        for (int i = 0; i < contactCount; i++)
			{
	            if (contacts[i].name == name)
				{
	                cout<<"\n Name: "<<contacts[i].name<<endl;
	                cout<<"Phone Number: "<<contacts[i].phoneNumber<<endl;
	                cout<<"Address: "<<contacts[i].address<<endl;
	                return;
	            }
	        }
	        cout<<"\n Contact not found!"<< endl;
	    }	
	    void updateContact()
		{
	        string name;
	        cout<<"\n Enter name of the contact to update: "<<endl;
	        cin.ignore();
	        getline(cin, name);	
	        for(int i=0; i<contactCount;i++)
			{
	            if(contacts[i].name==name)
				{
	                cout<<"\n Enter new phone number: "<<endl;
	                getline(cin, contacts[i].phoneNumber);
	                cout<<"Enter new address: "<<endl;
	                getline(cin, contacts[i].address);
	                cout<<"Contact updated successfully!" <<endl;
	                return;
	            }
	        }
	        cout<<"\n Contact not found!"<<endl;
	    }
	
	    void displayContacts()
		{
	        if(contactCount == 0)
			{
	            cout<<"\n No contacts available!"<<endl;
	            return;
	        }
	
	        for(int i=0;i<contactCount;i++)
			{
	            cout<<"\n Contact "<<(i+1)<<": "<<endl;
	            cout<<"Name: "<<contacts[i].name<<endl;
	            cout<<"Phone Number: "<<contacts[i].phoneNumber<<endl;
	            cout<<"Address: "<<contacts[i].address<<endl;
	            cout<<"---------------------"<<endl;
	        }
	    }
};
int main()
{
    AddressBook addressBook;
    int choice;
    do {
        cout<<"Address Book Menu"<<endl;
        cout<<"1. Add Contact"<<endl;
        cout<<"2. Search Contact"<<endl;
        cout<<"3. Update Contact"<<endl;
        cout<<"4. Display All Contacts"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"\n Enter your choice: "<<endl;
        cin>>choice;
        switch (choice)
		{
            case 1:
                addressBook.addContact();
                break;
            case 2:
                addressBook.searchContact();
                break;
            case 3:
                addressBook.updateContact();
                break;
            case 4:
                addressBook.displayContacts();
                break;
            case 5:
                cout<<"\n Exiting the program..."<<endl;
                break;
            default:
                cout<<"\n Invalid choice! Please try again."<<endl;
        }
        cout<<endl;
    } while(choice!=5);
    return 0;
}