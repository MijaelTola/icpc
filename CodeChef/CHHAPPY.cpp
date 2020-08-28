#include <bits/stdc++.h> 
using namespace std; 

struct node { 
	long long sum, prefixsum, suffixsum, maxsum; 
}; 

node tree[4 * 300010]; 

void build(int arr[], int low, int high, int index) { 
	if (low == high) { 
		tree[index].sum = arr[low]; 
		tree[index].prefixsum = arr[low]; 
		tree[index].suffixsum = arr[low]; 
		tree[index].maxsum = arr[low]; 
	} 
	else { 
		int mid = (low + high) / 2; 
		build(arr, low, mid, 2 * index + 1); 
		build(arr, mid + 1, high, 2 * index + 2); 
		tree[index].sum = tree[2 * index + 1].sum + 
						tree[2 * index + 2].sum; 
		tree[index].prefixsum = 
					max(tree[2 * index + 1].prefixsum, 
					tree[2 * index + 1].sum + 
					tree[2 * index + 2].prefixsum); 

		tree[index].suffixsum = 
					max(tree[2 * index + 2].suffixsum, 
					tree[2 * index + 2].sum + 
					tree[2 * index + 1].suffixsum); 
	    tree[index].maxsum = 
					max(tree[index].prefixsum, 
					max(tree[index].suffixsum, 
					max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
					tree[2 * index + 1].suffixsum + 
					tree[2 * index + 2].prefixsum)))); 
	} 
} 

node query(int arr[], int index, int low, int high, int l, int r) { 
	node result; 
	result.sum = result.prefixsum = 
				result.suffixsum = 
				result.maxsum = INT_MIN; 

	if (r < low || high < l) 
		return result; 

	if (l <= low && high <= r) 
		return tree[index]; 

	int mid = (low + high) / 2; 

	if (l > mid) 
		return query(arr, 2 * index + 2, 
					mid + 1, high, l, r); 
		
	if (r <= mid) 
		return query(arr, 2 * index + 1, 
					low, mid, l, r); 

	node left = query(arr, 2 * index + 1, 
					low, mid, l, r); 
	node right = query(arr, 2 * index + 2, 
						mid + 1, high, l, r); 

	result.sum = left.sum + right.sum; 
	result.prefixsum = max(left.prefixsum, left.sum + 
						right.prefixsum); 
							
	result.suffixsum = max(right.suffixsum, 
					right.sum + left.suffixsum); 
	result.maxsum = max(result.prefixsum, 
					max(result.suffixsum, 
					max(left.maxsum, 
					max(right.maxsum, 
					left.suffixsum + right.prefixsum)))); 
					
	return result; 
} 

//1 0 1 0 1 0 1 0 
int a[310010];
int main() { 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k,n,q; 
    cin >> n >> q >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; if(a[i] == 0) a[i] = -1e5;
        a[n + i] = a[2 * n + i] = a[i];
    }
    
    int l = 2 * n - 1, r = 3 * n - 1;
    int p = n;
    n *= 3;
	build(a, 0, n - 1, 0); 

    /*for (int i = 0; i < n; ++i) {
        if(a[i] != -1e5) cout << a[i] << " ";
        else cout << "0 ";
    }
    */
    string s; 
    cin >> s;
    //cout << l << " " << r << " start ||\n";
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '?') 
            cout << min((long long)k,max(query(a, 0, 0, n - 1, r - p + 1, r).maxsum,0LL)) << "\n";
        else {
            r--;
            if(r - p + 1 < 0) {
                r = 3 * p - 2;
            }
        }
      /*  for (int j = r - p + 1; j <= r; ++j) {
            if(a[j] != -1e5) cout << a[j] << " ";
            else cout << "0 ";
        }*/
        //cout << "| " <<query(a, 0, 0, n - 1, r - p + 1, r).maxsum << " " << r - p + 1 << " " << r << "\n";
    }
    
	return 0; 
} 

