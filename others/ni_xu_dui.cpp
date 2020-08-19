//求逆序对的个数
//i<j a[i]>a[j]

int merge_sort(vector<int>& arr){
	n=arr.size();
	vector<vector<int>> res;
	if(n==1) return 0;
	//divide
	vector<int> left,right;
	left.clear();
	right.clear();
	for(int i=0;i<n/2;i++){
		left.push_back(arr[i]);
	}
	for(int i=n/2;i<n;i++){
		right.push_back(arr[i]);
	}
	int count=0;
	//recursion,逆序对的pair都在左半边or右半边
	count+=merge_sort(left);
	count+=merge_sort(right);
	
	//merge
	count+=merge(arr,left,right);
}

int merge(vector<int>& arr,vector<int>& left,vector<int>& right){
	arr.clear();
	int i=0,j=0;
	int l=left.size(),r=right.size();
	int count=0;
	while(i<l || j<r){
		if(i>=l){
			arr.push_back(right[j]);
			j++;
		}
		else if(j>=r){
			arr.push_back(left[i]);
			i++;
		}
		else{
			if(left[i]<=right[j]){
				count+=j;
				arr.push_back(left[i]);
				i++;
			}
			else{
				arr.push_back(right[j]);
				j++;
			}
		}
		
	}
	return count;
	
}