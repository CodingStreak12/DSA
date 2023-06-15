/*
Approach: 
1. Basically I created one class Node which will hold the information what is the value and what is the row of vector and what is the column of the array.
2. Created compare function in which we will creater our min heap according to our val variable of Node class.
3. created priority_queue which is bascially min heap.
4. used one for loop till k elements which will store every first element of every single vector.
5. then use while loop till our queue is not empty.
6. extract the top value of the queue which is basically the shortest val.
7. pushed into our answer and popped the element from the queue.
8. then we will check if the next column is available or not if yes then we will create node for the next column and push into our queue.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
public:
	int val;
	int row;
	int col;
	Node(int val, int row, int col){
		this->val = val;
		this->row = row;
		this->col = col;
	}

};

class compare{
public:
	bool operator()(Node* a, Node* b){
		return a->val > b->val;
	}
};

vector<int> mergeKArrays(vector<vector<int>> &arr, int k){
	priority_queue<Node*, vector<Node*>, compare> pq;

	for(int i = 0; i < k; i++){
		Node* temp = new Node(arr[i][0], i, 0);
		pq.push(temp);
	}
	vector<int> ans;

	while(!pq.empty()){
		int val = pq.top()->val;
		int row = pq.top()->row;
		int col = pq.top()->col;
		ans.push_back(val);
		pq.pop();
		if(col+1 < k){
			Node* newNode = new Node(arr[row][col+1], row, col+1);
			pq.push(newNode);
		}
	}
	return ans;

}



int main(){
	vector<vector<int> > arr{{2,4,6,8}, {1,3,5,7}, {0,9,10,11}, {12, 13, 14, 15}};
	int k = 4;
	vector<int> ans = mergeKArrays(arr, k);
	for(auto i : ans){
		cout << i << " ";
	}

	

}