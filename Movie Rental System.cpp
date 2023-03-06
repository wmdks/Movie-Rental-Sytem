#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<windows.h>
using namespace std;


string acc_no[]={"1234567","7654321","00000000","1111111","555555555"};

class MainSystemClass{

	private:
	struct movie_Info{
	string id;
	string name;
	string cast;
	float rating;
	int year;
	movie_Info *left,*right,*link;
       }*root,*front;
		
	public:	
	
	MainSystemClass()
	{
		front=NULL;
		root=NULL;
	}
	
	void dotsLoading()
	{
		for(int i=0;i<15;i++)
		{
			cout<<".";Sleep(200);
		}
	}
bool isEmpty() const { return root==NULL; }
void movieDetails(movie_Info* p)
{
   cout<<"\nMovie id: "<<p->id<<"\nMovie Name: "<<p->name<<"\nCast: "<<p->cast<<"\nRating: "<<p->rating<<"\nYear: "<<p->year<<endl;
}



void InsertTree(string idy,string n,string c,float r,int y)
{
    movie_Info* t = new movie_Info;
    movie_Info* parent;
    t->id = idy;
    t->name = n;
    t->cast=c;
    t->rating=r;
    t->year=y;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    if(isEmpty()) root = t;
    else
    {
        movie_Info* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(t->name > curr->name) curr = curr->right;
            else curr = curr->left;
        }

        if(t->name < parent->name)
           parent->left = t;
        else
           parent->right = t;
    }
}

void enqueue(string idy,string n,string c,float r,int y)
        {
            movie_Info *tmp, *q;
            tmp = new movie_Info;
            
            tmp->id=idy;
            tmp->name = n;
            tmp->cast=c;
            tmp->rating = r;
            tmp->year=y;
            tmp->link=NULL;
            if (front == NULL || r > front->rating)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != NULL && q->link->rating >= r)
                {
					q=q->link;
				}
                    tmp->link = q->link;
                    q->link = tmp;
            }
        }

void dequeue(string name)
        {
            movie_Info *tmp,*del;
            if(front == NULL)
                cout<<"\nNo Records Found!\n";
            else
            {
            	tmp=front;
                while(tmp->link!=NULL && tmp->name==name)
                tmp=tmp->link;
                
                del=tmp->link;
                tmp->link=tmp->link->link;
                free(del);
            }
        }

void TopRatingMovies()
        {
            movie_Info *ptr;
            ptr = front;
            if (front == NULL)
                cout<<"\nNo Records Found!\n";
            else
            {	cout<<"\n\tTop 10 Movies in the Collection\n";
                int i=0;
                while(ptr != NULL && i<10)
                {
                    cout<<i+1<<"\nMovie: "<<ptr->name<<"\nRating: "<<ptr->rating<<endl;
                    ptr = ptr->link;
                    i++;
                }
            }
        }

void AddMovie()
{
	string name, id,cast;float rating;int year;
	system("cls");
	cin.ignore();
	cout<<"\n***** Enter Movie Details *****\n\n";
	cout<<"Enter Movie's id: ";
	getline(cin,id);
	cout<<"Enter Movie's Name: ";
	getline(cin,name);
	cout<<"Enter Movie's Cast: ";
	getline(cin,cast);
	cout<<"Enter Movie's Rating: ";
	cin>>rating;
	cout<<"Enter Movie's Releasing Year: ";
	cin>>year;
	InsertTree(id,name,cast,rating,year);
	enqueue(id,name,cast,rating,year);
	cout<<"\n\nAdding New Movie";
	dotsLoading();
	cout<<"\n\nMovie Added Successfully.";
	int n;
	cout<<"\n\n\n1. ADD MORE \n2. BACK\n3. MAIN MENU\n4. EXIT\n";
		cin>>n;
		switch(n)
		{
		case 1:
			AddMovie();
			break;
		case 2:
			adminSection();
			break;
		case 3:
			mainMenu();
			break;
		case 4:
			break;
		default:
			exit(0);
	    }
}

void check_shows(string name)
{
	if(SearchMovieForShow(root,name))
	{
		cout<<"\n\n\tAvailable Shows For Normmal Day (Friday is Off)\n\n\t\t1) 11:00AM-02:00PM\n\t\t2) 05:00PM-08:00PM\n\t\t3) 11:00PM-02:00AM\n";
	}
	else
	{
		cout<<"\nSorrry....! No Shows Available.\n";
		getch();
		customerSection();
	}
}

void buy_ticket(string name)
{
	int ch;
	string s;
	cout<<"\nPlease Choose a Show\n";
	check_shows(name);
	cin>>ch;
	switch(ch)
	{
		case 1:
			s="11:00AM-02:00PM";
			break;
		case 2:
			s="05:00AM-08:00PM";
			break;
		case 3:
			s="11:00PM-02:00AM";
			break;
		default:
			cout<<"\nInvalid Input\n";
	}
	string cust_name,phone,email,acc;
	cout<<"\nPlease Enter Your Details:\nName: ";
	cin.ignore();
	getline(cin,cust_name);
	cout<<"\nPhone: ";
	cin>>phone;
	cout<<"Email: ";
	cin>>email;
	cout<<"Payment Account Number: ";
	cin>>acc;
	bool ver=false;
	for(int i=0;i<5;i++)
	{
		if(acc==acc_no[i])
		{
			ver=true;
		}
	}
	if(ver)
	{
		system("cls");
		cout<<"\n\n\n\a\tThank You!\n\n";
		cin.get();
		cout<<"\n Creating Slip";dotsLoading();
		system("cls");
		cout<<"\n\tCineMehfil Cinema, Comissioner Road Sialkot\n";
		cout<<"\n\t    Name:  "<<cust_name;
		cout<<"\n\t    Phone: "<<phone;
		cout<<"\n\t    Email: "<<email;
		cout<<"\n\t    Movie: "<<name;
		cout<<"\n\t    Time:  "<<s;
		
		cout<<"\n\n\n\nPress any key to continue . . . . . .";
		getch();
		customerSection();
	}
}

void UpdateMovie(string d)
{
	string name,cast;
	float rating;
	int year;
	if(iterativeSearch(root,d)) 
	{
	movieDetails(sbn);
	cin.ignore();
	cout<<"\n\nEnter Movie's New Details\nenter Name: "; 
	getline(cin,sbn->name);
	cout<<"\nenter Cast: "; 
	getline(cin,sbn->cast);
	cout<<"\nenter Rating: "; 
	cin>>sbn->rating;
	cout<<"\nenter Year: "; 
	cin>>sbn->year;
	cout<<"\n\nMovie Details Updated Successfully.\n";
    }
    else
    {
    	cout<<"\nNo Records Found!\n";
    	return;
	}
}

void DeleteMovie(string id)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" \nStock Is Already Empty!\n "<<endl;
        return;
    }
    
    movie_Info* curr;
    movie_Info* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->id == id)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(id>curr->id) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<"\nNo Records Found!\n"<<endl;
        return;
    }
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
          //   dequeue(d);
             cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
           }
           else
           {
             parent->right = curr->right;
             delete curr;
          //   dequeue(d);
             cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
           }
       }
       else
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
          //   dequeue(d);
             cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
           }
           else
           {
             parent->right = curr->left;
             delete curr;
         //    dequeue(d);
             cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
           }
       }
     return;
    }
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 	//	 dequeue(d);
		 		 cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
		 		 return;
    }
	if (curr->left != NULL && curr->right != NULL)
    {
        movie_Info* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
           // dequeue(d);
            cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
            curr->right = NULL;
        }
        else
        {
		   if((curr->right)->left != NULL)
            {
                movie_Info* lcurr;
                movie_Info* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->id = lcurr->id;
                delete lcurr;
               // dequeue(d);
                cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
                lcurrp->left = NULL;
           }
           else
           {
               movie_Info* tmp;
               tmp = curr->right;
               curr->id = tmp->id;
	       curr->right = tmp->right;
               delete tmp;
               //dequeue(d);
               cout<<"Deleting The Movie ";dotsLoading();cout<<"\nMovie Deleted Successfully.";
           }

        }
		 return;
    }

}

void inorder(movie_Info* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        movieDetails(p);
        if(p->right) inorder(p->right);
    }
    else return;
}
void ShowList()
{
  inorder(root);
}
movie_Info *sbn;

bool SearchMovieForShow(movie_Info *root, string key) 
{  
    while (root != NULL) 
    {  
        if (key > root->name) 
            root = root->right;  
        else if (key < root->name) 
            root = root->left; 
        else
        {
        	sbn=root;
            return true;
        }
    } 
    return false; 
} 
bool iterativeSearch(movie_Info *root, string key) 
{  
    while (root != NULL) 
    {  
        if (key > root->id) 
            root = root->right;  
        else if (key < root->id) 
            root = root->left; 
        else
        {
        	sbn=root;
            return true;
        }
    } 
    return false; 
} 

void SearchMovie(string id)
{
	if(iterativeSearch(root,id)) {cout<<"\nMovie Available.\n";movieDetails(sbn);}
	else	{cout<<"\nSorry....! Movie's Not Available.\n";}
}
void mainMenu()
{
	system("cls");

	MainSystemClass n;
	int ch;
	string pass="";
	cout<<"\n\n         -----------------------------------------------------------"<<endl;
	cout<<"\t |\t               MAIN MENU                           |"<<endl;
	cout<<"         -----------------------------------------------------------"<<endl;
	
	cout<<"\t *                                                         *"<<endl;
	cout<<"\t *         1. ADMIN SECTION                                *"<<endl;
	cout<<"\t *         2. CUSTOMER SECTION                             *"<<endl;
	cout<<"\t *         3. EXIT                                         *"<<endl;
	cout<<"\t *                                                         *"<<endl;
	cout<<"\t *=========================================================*"<<endl;
	cout<<"\n         Enter your choice from menu : ";
	cin>>ch;
	switch(ch)
	{
	case 1:
		char a;
		cout<<"\n         Enter Password: ";
		a=_getch();
		while(a != 13){
        pass.push_back(a);
        cout << '*';
        a = _getch();}
		if(pass=="waqas")
		n.adminSection();
		else
		{
		cout<<"\nIncorrect Password. Try Again\n";
		Sleep(1000);
		mainMenu();
	    }
	case 2:
		system("cls");
		customerSection();
		break;
	case 3:
		exit(0);
	default:
		cout<<"\n\nInvalid Input Detected......! \nClosing";dotsLoading();
		Sleep(1000);
		system("cls");
		exit(0);
    }
}
void adminSection()
{
	system("cls");
	float rating;
	string id,name,cast;
	int ch,year,n,c;
	cout<<endl<<endl;
	cout<<"     ------------------------------------------------------------------";
	cout<<"\n     |\t\t           ADMIN SECTION                              |\n";
	cout<<"     ------------------------------------------------------------------";
	cout<<"\n     *                                                                *";
	cout<<"\n     *           1. ADD NEW MOVIE                                     *\n     *           2. DELETE A MOVIE                                    *\n     *           3. SEARCH A MOVIE                                    *\n     *           4. CHECK STOCK                                       *\n     *           5. UPDATE MOVIE INFO                                 *\n     *           6. MIAN MENU                                         *\n     *           7. EXIT                                              *\n     *                                                                *\n     *================================================================*\n";
	cout<<"\n\n      Enter choice from Menu : ";
	cin>>ch;
	switch(ch)
	{
	case 1:
		AddMovie();
	    break;
	    case 2:
	    	system("cls");
	    	cin.ignore();
	    	cout<<"\n\tnEnter Movie id To Delete:\n";
	    	getline(cin,id);
	    	DeleteMovie(id);
	    	cout<<"\n\n1. BACK\n2. MAIN MENU\n3. EXIT\n";
	    	cin>>n;
	    	switch(n)
	    	{
	    	case 1:
	  		adminSection();
	  		break;	
	    	case 2:
			mainMenu();
			break;	
	    	default:
			exit(0);
	    	}
	    	break;
		case 3:
		    system("cls");
		    
			
			cout<<"Enter Movie id to SEARCH: ";
			cin.ignore();
			getline(cin,id);
			SearchMovie(id);
			system("pause");
			adminSection();
		
			break;
		case 4:
		    system("cls");
			cout<<"\nLoading stock";dotsLoading();
			system("cls");
			cout<<"\n\n\t*******MOVIES IN THE STOCK*******\n";
		
			ShowList();
			cout<<"\n1. BACK\n2. EXIT\n";
			cin.ignore();
			cin>>c;
			switch(c)
			{
				case 1:
					adminSection();
					break;
				case 2:
					exit(0);
					break;
				default:
					adminSection();
			}
			break;
		case 5:
			system("cls");
			cin.ignore();
			cout<<"\n\tMovie Details Modification\n\nEnter Movie id: ";
			getline(cin,id);
			UpdateMovie(id);
			cout<<"\n\nPress Any Key To Go Back........................";
			getch();
			adminSection();
			break;
		case 6:
			mainMenu();
			break;
		case 7:
			exit(0);
		default:
			cout<<"Invalid Input Detected!\nGoing Back to Main Menu\n";
			Sleep(1000);
			mainMenu();
}
}
customerSection()
{
	system("cls");
	
	float rating;
	string name,id,cast;
	int ch,year,n,c;
	cout<<"             ------------------------------------------------------------------";
      	cout<<"\n\t     |\t                     CUSTOMER SECTION                         |\n";
	cout<<"             ------------------------------------------------------------------\n";
	cout<<"             *                                                                *\n";
    cout<<"             *           1. SEARCH A MOVIE                                    *\n";
    cout<<"             *           2. TOP RATING MOVIES IN STOCK                        *\n";
    cout<<"             *           3. CHECK STOCK                                       *\n";
    cout<<"             *           4. BUY TICKET                                        *\n";
    cout<<"             *           5. MAIN MENU                                         *\n";
    cout<<"             *           6. EXIT SYSTEM                                       *\n";
    cout<<"             *                                                                *\n";
    cout<<"             *================================================================*\n";
    
    
	
	cout<<"\n\n             Enter your choice ";
	cin>>ch;
	switch(ch)
	{
	case 3:
		system("cls");
		cout<<"\nChecking Movies from Stock";dotsLoading();
		system("cls");
		cout<<"\n\n\tMovies from Stock\n";
		ShowList();
		cout<<"\n         1. BACK\n2. EXIT\n";
		cin.ignore();
		cin>>c;
		switch(c)
		{
			case 1:
				customerSection();
				break;
			case 2:
				exit(0);
				break;
			default:
				customerSection();
		}
		break;
	case 1:
		int a;
		system("cls");
		
		cout<<"Enter Movie id: ";
		cin.ignore();
	    getline(cin,id);
	    SearchMovie(id);
		cout<<"\n\n\n\n\n\n\n\n\n";
		system("pause");
		customerSection();
		
		break;
	case 2:
		system("cls");
		TopRatingMovies();
		cout<<"\n\n\n\n\n\n\n\n\n";
		system("pause");
		customerSection();
		break;
	case 4:
		system("cls");
		cout<<"\n\tBuy Movie Ticket\nEnter Movie Name: ";
		cin.ignore();
		getline(cin,name);
		buy_ticket(name);
		break;
	case 5:
		mainMenu();
		break;
	case 6:
		exit(0);
	default:
		cout<<"Invalid Input Detected!\nGoing Back to Main Menu\n";
		Sleep(1000);
		mainMenu();
	}
}



};




void WelcomeNote()
{
   
     cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
     cout<<"W";Sleep(200);
     cout<<"E";Sleep(200); 
     cout<<"L";Sleep(200); 
     cout<<"L";Sleep(200);
     cout<<"C";Sleep(200); 
     cout<<"O";Sleep(200); 
     cout<<"M";Sleep(200); 
     cout<<"E";Sleep(200);
     cout<<" T";Sleep(200); 
     cout<<"O";Sleep(200); 
     cout<<" M";Sleep(200); 
     cout<<"O";Sleep(200); 
     cout<<"V";Sleep(200); 
     cout<<"I";Sleep(400);
     cout<<"E";Sleep(200);
     cout<<" R";Sleep(200);
     cout<<"E";Sleep(200);
     cout<<"N";Sleep(200);
     cout<<"T";Sleep(200);
     cout<<"A";Sleep(200);
     cout<<"L";Sleep(200);
     cout<<" S";Sleep(200);
     cout<<"Y";Sleep(200);
     cout<<"S";Sleep(200);
     cout<<"T";Sleep(200);
     cout<<"E";Sleep(200);
     cout<<"M";Sleep(200);
    
     cout<<"\n\n\n\n\n\n";
     system("pause");
}                     
int main()
{
	WelcomeNote();
	MainSystemClass m;
	m.mainMenu();
	return 0;	
}

