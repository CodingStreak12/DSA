#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &height){
  vector<int> leftMax(height.size());
  
  
  vector<int> rightMax(height.size());
  
  int maxi = -1;
  for(int i = 0; i < height.size(); i++){
    leftMax[i] = maxi;
    maxi = max(maxi, height[i]);
    
  }
  maxi = -1;
  for(int i = height.size()-1; i>=0; i--){
  	rightMax[i] = maxi;
  	maxi = max(maxi, height[i]);
  }

  cout << "Printing the leftMax array: "<< endl;
  for(auto i: leftMax){
  	cout << i << " ";
  }
  cout <<endl <<"Printing the right max array: " <<endl;
  for(auto i: rightMax){
  	cout << i << " ";
  }

  int finalSum = 0;
  for(int i = 0; i < height.size(); i++){
  	int val = min(leftMax[i], rightMax[i]);
  	if(val == -1){
  		continue;
  	}
  	else if(val - height[i] < 0){
  		continue;
  	}
  	else{
  		finalSum = finalSum + (val - height[i]);
  	}
  }


  return finalSum;
}
int main() {
  vector<int> height{4,2,0,3,2,5};

  int ans = trap(height);
  cout << endl;
  cout << "The answer is: "<< ans << endl;
}