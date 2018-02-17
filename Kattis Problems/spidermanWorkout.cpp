#include<iostream>
#include<utility>
#include<vector>
using namespace std;

typedef struct Node {
	int max;
	int building;
	int height;
	string path = "";
	Node *leftChild, *rightChild;
	bool root = 0;
} Node;

void build(Node *parent, vector<int> nums) {
	if (!nums.size()) //Stop when nums is empty
		return;
	int first = nums[0];
	nums.erase(nums.begin());
	//Create left subtree recursively
	parent->leftChild = new Node;
	parent->leftChild->building = first;
	parent->leftChild->max = parent->max;
	parent->leftChild->height = parent->height - first; //Subtract next height
	parent->leftChild->path = parent->path;
	parent->leftChild->path.append("D");
	build(parent->leftChild, nums); //Recrusive left subtree call
	//Create right subtree recursively
	parent->rightChild = new Node;
	if (parent->max < parent->height + first) {
		parent->rightChild->max = parent->height + first;
	}
	parent->rightChild->building = first;
	parent->rightChild->height = parent->height + first; //Add next heigh
	parent->rightChild->path = parent->path;
	parent->rightChild->path.append("U");
	build(parent->rightChild, nums);
}

void inOrder(Node *root) {
	if (root != NULL) {
		inOrder(root->leftChild);
		//Only care about leaves
		if (root->leftChild == root->rightChild && root->rightChild == NULL) {
			cout << root->path << " final height: " << root->height << " max height: " << root->max << endl;
		}
		inOrder(root->rightChild);
	}
}

int main() {
	Node *start;
	start = new Node; 
	start->height = 0;
	start->root = 1;
	build(start, {20,20,20,20});
	inOrder(start);
	return 0;
}
