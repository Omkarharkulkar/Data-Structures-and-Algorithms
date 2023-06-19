
#include <bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;
 
class Node 
{
    public:
    Node *left, *right;
    int info;
 
    bool lthread;
 
    bool rthread;
    
    Node* insert(Node* root, int ikey)
    {
        
        Node* ptr = root;
       
        Node* par = NULL; 
        while (ptr != NULL) 
		{
            if (ikey == ptr->info)
            {
                cout<<endl<<"\nDuplicate Key";
                return root;
            }
 
            par = ptr; 
 
            if (ikey < ptr->info) 
			{
                if (ptr->lthread == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else 
			{ 
                if (ptr->rthread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
 
        Node* tmp = new Node;
        tmp->info = ikey;
        tmp->lthread = true;
        tmp->rthread = true;
        
        if (par == NULL) 
		{
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if (ikey < (par->info)) 
		{
            tmp->left = par->left; 
            tmp->right = par;       
            par->lthread = false;   
            par->left = tmp;        
        }
        else 
		{
            tmp->left = par;        
            tmp->right = par->right;  
            par->rthread = false;  
            par->right = tmp;    
        }
        return root;
    }
    
    void inorder(Node* root)
	{
        if(root == NULL)
            return;
       
        if(root->lthread == false)
            inorder(root->left);
            
        cout << root->info<< " ";
        
        if(root->rthread == false)
            inorder(root->right);
    }
    
    
    void preorder(Node* root){
        if(root == NULL)
            return;
       
        cout << root->info<< " ";
        
        if(root->lthread == false)
            preorder(root->left);
        
        if(root->rthread == false)
            preorder(root->right);
    }
    
    void postorder(Node* root){
        if(root == NULL)
            return;
       
        if(root->lthread == false)
            postorder(root->left);
       
            postorder(root->right);
        
        cout << root->info<< " ";
    }
   
    Node* inorderSuccessor(Node* ptr)
    {
        if (ptr->rthread == true)
            return ptr->right;
 
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }

    void inOrder(Node* root)
    {
        if (root == NULL)
            cout<<endl<<"\nTree is empty";
 
        Node* ptr = root;
        while (ptr->lthread == false)
            ptr = ptr->left;
 
        while (ptr != NULL) {
            cout<<" "<<ptr->info;
            ptr = inorderSuccessor(ptr);
        }
    }

    void preOrder(Node *root)
    {
        Node *ptr;
        if(root==NULL)
        {
            cout<<"Tree is empty";
            return;
        }
        ptr=root;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            if(ptr->lthread==false)
                ptr=ptr->left;
            else if(ptr->rthread==false)
                ptr=ptr->right;
            else
            {
                while(ptr!=NULL && ptr->rthread==true)
                    ptr=ptr->right;    
                if(ptr!=NULL)
                    ptr=ptr->right;    
            }
        }
    }

    
    Node* inSucc(Node* ptr)
    {
        if (ptr->rthread == true)
            return ptr->right;
 
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
 
        return ptr;
    }


    Node* inPred(Node* ptr)
    {
        if (ptr->lthread == true)
            return ptr->left;
 
        ptr = ptr->left;
        while (ptr->rthread == false)
            ptr = ptr->right;
        
        return ptr;
    }

    Node* caseA(Node* root, Node* par,Node* ptr)
    {

        if (par == NULL)
            root = NULL;
 
        else if (ptr == par->left) {
            par->lthread = true;
            par->left = ptr->left;
        }
        else {
            par->rthread = true;
            par->right = ptr->right;
        }
 
        delete ptr;
        
        return root;
    }
 
    Node* caseB(Node* root, Node* par,Node* ptr)
    {
        Node* child;
 
        if (ptr->lthread == false)
            child = ptr->left;
        else
            child = ptr->right;
 
        if (par == NULL)
            root = child;
        else if (ptr == par->left)
            par->left = child;
        else
            par->right = child;

        Node* s = inSucc(ptr);
        Node* p = inPred(ptr);
 
        if (ptr->lthread == false)
            p->right = s;
        else 
		{
            if (ptr->rthread == false)
                s->left = p;
        }
 
        delete ptr;
        
        return root;
    }
 
    
    Node* caseC(Node* root,Node* par,Node* ptr)
    {
        Node* parsucc = ptr;
        Node* succ = ptr->right;
 
        while (succ->lthread==false) 
		{
            parsucc = succ;
            succ = succ->left;
        }
 
        ptr->info = succ->info;
 
        if (succ->lthread == true && succ->rthread == true)
            root = caseA(root, parsucc, succ);
        else
            root = caseB(root, parsucc, succ);
 
        return root;
    }
 
    Node* delThreadedBST(Node* root, int dkey)
    {
        Node *par = NULL, *ptr = root;
 
        int found = 0;
 
        while (ptr != NULL) 
		{
            if (dkey == ptr->info) 
			{
                found = 1;
                break;
            }
            par = ptr;
            if (dkey < ptr->info) 
			{
                if (ptr->lthread == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else 
			{
                if (ptr->rthread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
 
        if (found == 0)
            cout<<"\ndkey is not present";
        else if (ptr->lthread == false && ptr->rthread == false)
           root = caseC(root, par, ptr);
        else if (ptr->lthread == false)
            root = caseB(root, par, ptr);
        else if (ptr->rthread == false)
            root = caseB(root, par, ptr);
        else
            root = caseA(root, par, ptr);
 
        return root;
    }
    
    
    Node* search(Node* root, int key) {
        if(root == NULL || root->info == key)        
            return root;

        if(root->info < key && root->rthread==false)
            return search(root->right,key);

        else if (root->info > key && root->lthread==false)
            return search(root->left,key);
    }
    
    void printLevelOrder(Node *root)  
    {   
        if (root == NULL) return;  
  
        queue<Node *> q;  
  
        q.push(root);  
  
        while (q.empty() == false)  
        {   
            cout<<" ---> ";
            while (q.size() > 0) 
            {  
                Node *node = q.front();  
                cout<<node->info<<" ";  
                q.pop();  
                if (node->left != NULL)  
                    q.push(node->left);  
                if (node->right != NULL)  
                    q.push(node->right);  
            }  
        }  
    }
    
};


int main()
{
    Node Tree;
   
    Node* root = NULL;
    int choice;
    char ch='Y';
   
    while(ch=='Y'||ch=='y')
    {
        cout<<endl<<" \n\nSelect An Operation Want To Perform:"<<endl;
        cout<<endl<<"\n1)Create\n2)Insert\n3)Delete\n4) Search"<<endl;
		cout<<"5)Display\n6)LOP\n7)Exit"<<endl;
        cout<<endl<<"\nEnter your Choice = ";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                int t;
                cout<<endl<<"\nEnter number of nodes want to insert = ";
                cin>>t;
                while(t--)
				{
                    int data;
                    cout<<endl<<"\nEnter "<<t<<" Element = ";
                    cin>>data;
                    root = Tree.insert(root,data);
                }
                cout<<endl<<"\nOperation Processed Successfully!\nTBT is Formed"<<endl;
                break;
            case 2: 
                t=0;
                cout<<endl<<"\nEnter element to insert in TBT = ";
                cin>>t;
                root = Tree.insert(root,t);
                cout<<endl<<"\nOperation Processed Successfully!\nNode is Added";
                break;
            case 3: 
                int delete_data;
                cout<<endl<<"\nEnter the node want to delete = ";
                cin>>delete_data;
                
                root = Tree.delThreadedBST(root, delete_data);
                
                cout<<endl<<"\nNon-Recursive Inorder Traversal of Given TBT = ";
                Tree.inOrder(root);
                
                break;
            case 4:
                if(root!=NULL){
                    cout<<endl<<"\nEnter the element to search in TBT = ";
                    int data;
                    cin>>data;
                    
                    if(Tree.search(root,data)!=NULL)
                        cout<<endl<<"\n"<<data<<" is found";
                    else
                        cout<<endl<<"\n"<<data<<" is not found";
                }
                else
                    cout<<endl<<"\nTBT is Empty!!";
                break;
            case 5:
                if(root!=NULL)
                {
                    cout<<endl<<"\nTBT Traversals = ";
                    
                    cout<<endl<<endl<<"\n\nInorder Traversal of Tree = ";
                    Tree.inorder(root);
                   
                    cout<<endl<<endl<<"\n\nNon-recursive Inorder Traversal of Tree = ";
                    Tree.inOrder(root);
                    
                    cout<<endl<<endl<<"\n\nPreorder Traversal of Tree = ";
                    Tree.preorder(root);
                    
                    cout<<endl<<endl<<"\n\nNon-recursive Preorder Traversal of Tree = ";
                    Tree.preOrder(root);
                    
                    cout<<endl<<endl<<"\n\nPostorder Traversal of Tree = ";
                    Tree.postorder(root);
                    
                }
                else
                    cout<<endl<<"\nTBT is Empty!!";
                break;
            case 6: 
                if(root!=NULL)
                {
                    cout<<endl<<"\nLOP = ";
                    Tree.printLevelOrder(root);  
                }
                else
                    cout<<endl<<"\nTBT is Empty!!";
                break;
            case 7: exit(0);
            default : 
                cout<<endl<<"\nSomething Went Wrong!!";
                break;
        }
        
        cout<<endl<<endl<<"\nWant to Continue (Y\N) ? : ";
        cin>>ch;
        if(ch=='Y' || ch=='y')
            continue;
        else
            exit(0);
    }
    return 0;
}



/* OUTPUT:


Select An Operation Want To Perform:
1)Create
2)Insert
3)Delete
4) Search
5)Display
6)LOP
7)Exit
Enter your Choice = 1


Enter number of nodes want to insert = 5


Enter 4 Element = 1


Enter 3 Element = 6


Enter 2 Element = 9


Enter 1 Element = 3


Enter 0 Element = 5


Operation Processed Successfully!
TBT is Formed


-------------------------------------------------------
Want to Continue (Y\N) ? : y



Select An Operation Want To Perform:
1)Create
2)Insert
3)Delete
4)Search
5)Display
6)LOP
7)Exit
Enter your Choice = 2


Enter element to insert in TBT = 4


Operation Processed Successfully!
Node is Added

---------------------------------------------------------
Want to Continue (Y\N) ? : y



Select An Operation Want To Perform:
1)Create
2)Insert
3)Delete
4)Search
5)Display
6)LOP
7)Exit
Enter your Choice = 3


Enter the node want to delete = 3


Non-Recursive Inorder Traversal of Given TBT =  1 4 5 6 9

------------------------------------------------------------
Want to Continue (Y\N) ? : y



Select An Operation Want To Perform:
1)Create
2)Insert
3)Delete
4)Search
5)Display
6)LOP
7)Exit
Enter your Choice = 4


Enter the element to search in TBT = 5


5 is found

---------------------------------------------------------------
Want to Continue (Y\N) ? : y


*/
