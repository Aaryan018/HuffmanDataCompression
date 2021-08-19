//Huffman.cpp file
//Description: This program implements a Huffman algorithm
//Author: Aaryan Gupta


#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;


//this class stores the charachters and the frequency 
class Node{

	public:
		Node(){
			left = right = nullptr;
		}

		Node(string ch, int n){
			s = ch;
			freq = n;
			left = right = nullptr;
		}

		Node(int n){
			freq = n;
			right = left = nullptr;
		}

		//left and right children
		Node *left, *right;
		string s;
		int freq;

};


//compare class for min heap using priority queue
class Compare{
	
	public:
		bool operator()(Node* a, Node* b){
			return a->freq > b->freq;
		}	
};



//this function makes a huffman tree
Node* makeHuffmanTree(priority_queue<Node*, vector<Node*>, Compare> Q){


	int f1, f2;
	Node *t1, *t2;
	Node *t;

	while(Q.size() > 1){

		f1 = Q.top()->freq;
		t1 = Q.top();
		Q.pop();

		f2 = Q.top()->freq;
		t2 = Q.top();
		Q.pop();

		t = new Node(f1+f2);
		t->s = t1->s + t2->s;
		t->left = t1;
		t->right = t2;

		Q.push(t);
	}

	return Q.top();

}

//inorder traversal of a tree.
void inorder(Node *p){
	if(p != nullptr){
		inorder(p->left);
		cout << p->s << " " << p->freq << endl;;
		inorder(p->right);
	}
}


//postorder traversal of a tree
void postorder(Node *p){
	if(p != nullptr){
		postorder(p->left);
		postorder(p->right);
		cout << p->s << " " << p->freq << endl;;
	}
}


//printing the contents of the huffman tree
void printTrie(Node *root){

	cout << "In order traversal of the tree is: " << endl;
	inorder(root);
	cout << endl;

	cout << "Postorder traversal of the tree is: " << endl;
	postorder(root);
	cout << endl;
}


//runs the code.
int main(){


	string str = "EYEWITNESSNEWS";

	priority_queue<Node*, vector<Node*>, Compare> Q;

	vector<char> data;
	vector<int> f;
	bool present = false;


	//finding frequency of each character
	for(unsigned i = 0; i < str.size(); i++){

		for(unsigned j = 0; j < data.size(); j++){

			if(str[i] == data[j]){
				f[j] = f[j] + 1;
				present = true;				
			}
		}

		if(!present){
			data.push_back(str[i]);
			f.push_back(1);

		}

		present = false;

	}

	string s;

	//making the nodes and adding into the queue.
	for(unsigned i = 0; i < data.size(); i++){


		s.push_back(data[i]);
		Node *tmp = new Node(s, f[i]);
		Q.push(tmp);
		s = "";

	}


	Node *root = makeHuffmanTree(Q);

	printTrie(root);
	


}