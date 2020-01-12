#include <iostream>
#include <string>

struct Node{
	size_t data;
	Node *left;
	Node *right;
}

Node* FindMin(Node* root, size_t data){
	while(root->left != nullptr)
		root = root->left;

	return root;
}

bool before( const std::string& s1, const std::string& s2 ){

   for(auto it1 = s1.begin(), it2 = s2.begin(); 
      it1 != s1.end(), it2 != s2.end(); it1++, it2++ ){
      
      char ch1 = tolower( *it1 );
      char ch2 = tolower( *it2 );
      
      if( ch1 == ch2 )
         continue;
      else if( ch1 > ch2 )
         return false;
      else
         return true;  
   }
   if( s1.size() < s2.size() )
      return true;
   else
      return false;
}

void LevelOrder (Node *root){
	if(root == nullptr)
		return;
	std::queue<Node*> q;
	p.push(root);

	while(!q.empty()){
		Node* current = q.front();
		q.pop();
		cout<<current->data<<" ";
		if(current->left != nullptr)
			q.push(current->left);
		if(current->right != nullptr)
			q.push(current->right);
	}
}

Node* Delete(Node *root, int data){
	if(root == nullptr)
		return root;
	else if (data < root->left)
		root->left = Delete(root->left, data);
	else if (data > root -> right)
		root->right = Delete(root->right, data);
	else{

		if(root->left == nullptr && root->right == nullptr){
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr){
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr){
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
			delete temp;
		}
	}

	return root;

}

int main(){
	std::cout << before( "aStanagoi", "AsTaNa" ) << "\n";
	// false
	std::cout << before( "astana", "Almaty" ) << "\n";
	// false.
	std::cout << before( "almaty", "ASTANA" ) << "\n";
	// true.
}