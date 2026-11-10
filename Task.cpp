#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int studentId;
	Node* left;
	Node* right;
};
Node* createNode(int ID)
{
	Node* newNode = new Node;
	newNode->studentId = ID;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Node* insertBST(Node* root, int ID)
{
	if(root == NULL)
	{
		return createNode(ID);
	}
	if(ID > root->studentId)
	{
		root->right = insertBST(root->right, ID);
	}
	else if(ID < root->studentId)
	{
		root->left = insertBST(root->left, ID);
	}
	return root;
}
void inorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->studentId << " ";
	inorder(root->right);
}
void preorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	cout << root->studentId << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->studentId << " ";
}
void search(Node* root, int ID)
{
	if(root == NULL)
	{
		cout << "Student ID " << ID << " not found." << endl;
		return;
	}
	if(root->studentId == ID)
	{
		cout << "Student ID " << ID << " found." << endl;
		return;
	}
	if(ID < root->studentId)
	{
		search(root->left, ID);
	}
	else
	{
		search(root->right, ID);
	}
}
int countNodes(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
	Node* node = NULL;
	int size;
	int choice;
	int ID;
	cout << "Enter the number of student IDs: ";
	cin >> size;
	int* sId = new int[size];
	for(int i = 0; i < size; i++)
	{
		cout << "Enter ID of student " << i + 1 << ": ";
		cin >> sId[i];
		node = insertBST(node, sId[i]);
	}
	do
	{
		cout << endl;
		cout << "BST MENU:" << endl;
		cout << "1. Display Inorder Traversal" << endl;
		cout << "2. Display Preorder Traversal" << endl;
		cout << "3. Display Postorder Traversal" << endl;
		cout << "4. Search Student ID" << endl;
		cout << "5. Count Student Records" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "Inorder Traversal: ";
				inorder(node);
				cout << endl;
				break;
			case 2:
				cout << "Preorder Traversal: ";
				preorder(node);
				cout << endl;
				break;
			case 3:
				cout << "Postorder Traversal: ";
				postorder(node);
				cout << endl;
				break;
			case 4:
				cout << "Enter student ID to search: ";
				cin >> ID;
				search(node, ID);
				break;
			case 5:
				cout << "Total number of student records: ";
				cout << countNodes(node) << endl;
				break;
			case 6:
				cout << "Exiting program..." << endl;
				break;
			default:
				cout << "Invalid choice." << endl;
		}
	} while(choice != 6);
	delete[] sId;
	return 0;
}