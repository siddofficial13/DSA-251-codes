Family Structure
string child(int n , long long k){
	if(n==1 || k==1){
		return "Male";
	}
	long long parent = (k+1)/2;
	string parchild = child(n-1,parent);
	if(k==(2*parent-1)){
		return parchild;
	}
	else {
		 if(parchild=="Female")

           return "Male";
	}
	return "Female";
}


string kthChildNthGeneration(int n, long long int k)
{
	// Write your code here	
	return child(n,k);
}
