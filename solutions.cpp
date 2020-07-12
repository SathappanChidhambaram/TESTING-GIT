Arrays
1)Find The Duplicate In An Array Of N Integers.
-------------------------------------------------------
Using Floyd's Tortoise and Hare (Cycle Detection)
TC:O(n) 	SC:O(1)

int findDuplicate3(vector<int>& nums)
{
        if (nums.size() > 1)
        {
                int slow = nums[0];
                int fast = nums[nums[0]];
                while (slow != fast)
                {
                        slow = nums[slow];
                        fast = nums[nums[fast]];
                }

                fast = 0;
                while (fast != slow)
                {
                        fast = nums[fast];
                        slow = nums[slow];
                }
                return slow;
        }
        return -1;
}

Input:
4
0 3 1 2
5
2 3 1 2 3 

Sample Output:
-1
2 3 
2)Sort an array of 0’s 1’s 2’s without using extra space or sorting algo
-------------------------------------------------------------------------
Tc:O(n)             SC:O(1)
 void sortColors(vector<int>& nums) 
    {
        int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
    
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {	//swapping(nums[low],nums[mid])
                tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {	
                mid++;
            }
            else if(nums[mid] == 2)
            {	//swapping(nums[mid],nums[high])
                tmp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = tmp;
                high--;
            }
        }
    }
Input:
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1
3)Find the repeating and the missing
------------------------------------------------------
TC:O(n)		SC:O(n)

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n + 1] = {0};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[a[i]]++;
		} int rep = 0, mis = 0, min = n, flag = 0;
		for (int i = 1; i < n + 1; i++) {
			if (b[i] == 0) {
				mis = i;
			}
			if (b[i] > 1 && flag == 0) {
				rep = i ;
				flag = 1;
			}
		}
		cout << rep << " " << mis << "\n";
	}
	return 0;
}

Input:
2
2 2
3 
1 3 3

Output:
2 1
3 2

..............................................
TC:O(n)		SC:O(1)
/*
    Let x be the missing and y be the repeating element.
    Let N is the size of array.
    Get the sum of all numbers using formula S = N(N+1)/2
    Get product of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
    Iterate through a loop from i=1….N
    S -= A[i]
    Sum_Sq -= (A[i]*A[i])
    It will give two equations

    x-y = S – (1)
    x^2 – y^2 = Sum_sq
    x+ y = (Sum_sq/S) – (2)
*/

vector<int>repeatedNumber(const vector<int> &A) { 
    long long int len = A.size(); 
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6; 
    long long int missingNumber=0, repeating=0; 
      
    for(int i=0;i<A.size(); i++){ 
       Sum_N -= (long long int)A[i]; 
       Sum_NSq -= (long long int)A[i]*(long long int)A[i]; 
    } 
      
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; 
    repeating= missingNumber - Sum_N; 
    vector <int> ans; 
    ans.push_back(repeating); 
    ans.push_back(missingNumber); 
    return ans; 
      
} 


4)Efficiently merging two sorted arrays with O(1) extra space
------------------------------------------------------------
TC:O((n+m)*log(n+m))	SC:O(1)
n-size of first array
m-size of second array

// Function to find next gap. 
int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 
  
void merge(int *arr1, int *arr2, int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        // comparing elements in the first array. 
        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 
  
        //comparing elements in both arrays. 
        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 
  
        if (j < m) 
        { 
            //comparing elements in the second array. 
            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
} 

Input:
4 5
1 3 5 7
0 2 6 8 9
2 3
10 12
5 18 20

Output:
0 1 2 3 5 6 7 8 9
5 10 12 18 20

5)Kadane’s Algorithm
----------------------------------------------------
TC:O(n)		SC:O(1)

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int maximum_so_far = INT_MIN, maximum_ending_here = 0;
		for (int i = 0; i < n; i++) {
			maximum_ending_here = maximum_ending_here + a[i];
			if (maximum_ending_here < a[i]) {
				maximum_ending_here = a[i];
			}
			if (maximum_so_far < maximum_ending_here) {
				maximum_so_far = maximum_ending_here;
			}
		}
		cout << maximum_so_far << "\n";
	}
Input:
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output:
9
-1
6)Merge Overlapping Subintervals
-------------------------------------------------------

TC:O(nlogn)	SC:O(1)
struct Interval  
{  
    int s, e;  
};  
  
// Function used in sort  
bool mycomp(Interval a, Interval b)  
{ return a.s < b.s; }  
  
void mergeIntervals(Interval arr[], int n)  
{  
    // Sort Intervals in increasing order of 
    // start time 
    sort(arr, arr+n, mycomp);  
  
    int index = 0; // Stores index of last element  
    // in output array (modified arr[])  
  
    // Traverse all input Intervals  
    for (int i=1; i<n; i++)  
    {  
        // If this is not first Interval and overlaps  
        // with the previous one  
        if (arr[index].e >=  arr[i].s)  
        {  
               // Merge previous and current Intervals  
            arr[index].e = max(arr[index].e, arr[i].e);  
            arr[index].s = min(arr[index].s, arr[i].s);  
        }  
        else { 
	    index++; 
            arr[index] = arr[i];  
            
        }     
    }  
  
    // Now arr[0..index-1] stores the merged Intervals  
    cout << "\n The Merged Intervals are: ";  
    for (int i = 0; i <= index; i++)  
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";  
}  
  
// Driver program  
int main()  
{  
    Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} };  
    int n = sizeof(arr)/sizeof(arr[0]);  
    mergeIntervals(arr, n);  
    return 0;  
}  

Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 4 6 8 9 10
1 9

7)Set Matrix Zeros
---------------------------------------------------------
TC:O(m*n) 	SC:O(1)
void modifyMatrix(int mat[R][C]) 
{ 
    // variables to check if there are any 1 
    // in first row and column 
    bool row_flag = false; 
    bool col_flag = false; 
  
    // updating the first row and col if 1 
    // is encountered 
    for (int i = 0; i < R; i++) { 
        for (int j = 0; j < C; j++) { 
            if (i == 0 && mat[i][j] == 1) 
                row_flag = true; 
  
            if (j == 0 && mat[i][j] == 1) 
                col_flag = true; 
  
            if (mat[i][j] == 1) { 
  
                mat[0][j] = 1; 
                mat[i][0] = 1; 
            } 
        } 
    } 
  
    // Modify the input matrix mat[] using the 
    // first row and first column of Matrix mat 
    for (int i = 1; i < R; i++) { 
        for (int j = 1; j < C; j++) { 
  
            if (mat[0][j] == 1 || mat[i][0] == 1) { 
                mat[i][j] = 1; 
            } 
        } 
    } 
  
    // modify first row if there was any 1 
    if (row_flag == true) { 
        for (int i = 0; i < C; i++) { 
            mat[0][i] = 1; 
        } 
    } 
  
    // modify first col if there was any 1 
    if (col_flag == true) { 
        for (int i = 0; i < R; i++) { 
            mat[i][0] = 1; 
        } 
    } 
}
Input: 
2
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
Output:
1 1
1 0
0 0 1 
1 1 1

8)Pascal Triangle
-------------------------------------------------------
TC:O(n^2)	SC:O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(auto i=0;i<numRows;++i)
        {
            res.push_back(vector<int>(i+1,1));
            for(auto j=1; j<i; ++j) res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
9)Next Permutation
-------------------------------------------------------
TC:O(n) 	SC:O(1)
Explanation:

1.Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
2.Find the largest index l > k such that nums[k] < nums[l].
3.Swap nums[k] and nums[l].
4.Reverse the sub-array nums[k + 1:].

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 

input->output
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

10)Inversions of array : (Merge sort)
-------------------------------------------------------
TC:O(nlogn) 	SC:O(n)
// C++ program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 

int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

/* This function sorts the input array and returns the 
number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
	int temp[array_size]; 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

/* An auxiliary recursive function that sorts the input array and 
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) { 
		/* Divide the array into two parts and 
		call _mergeSortAndCountInv() 
		for each of the parts */
		mid = (right + left) / 2; 

		/* Inversion count will be sum of 
		inversions in left-part, right-part 
		and number of inversions in merging */
		inv_count += _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

/* This funt merges two sorted arrays 
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left, 
		int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 

			/* this is tricky -- see above 
			explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i); 
		} 
	} 

	/* Copy the remaining elements of left subarray 
(if there are any) to temp*/
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 

	/* Copy the remaining elements of right subarray 
(if there are any) to temp*/
	while (j <= right) 
		temp[k++] = arr[j++]; 

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int ans = mergeSort(arr, n); 
	cout << " Number of inversions are " << ans; 
	return 0; 
} 
Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).

11)Stock Buy and Sell
--------------------------------------------------------
TC:O(n)		SC:O(1)
int maxProfit(vector<int>& prices) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = prices.size();
        int diff = 0;
        for(int i=1;i<n;++i)
        {
            if(prices[i] > prices[i-1])
                diff += prices[i]-prices[i-1];
        }
        return diff;
    }
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
12)Rotate matrix
-------------------------------------------------------

TC:O(n^2)	SC:O(1)

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

13)Excel Column Number
-----------------------------------------------------

//Number to label
class Solution {
public:
    string convertToTitle(int n) {
    string s="";
        while(n>0){
            n--;
            s=(char)(n%26+'A')+s;
            n=n/26;
        }
        return s;
    }
};

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

//label to number
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
for (int i = 0; i < s.size();  i++){
    result = result * 26 + (s.at(i) - 'A' + 1);
    cout<<result<<"\n";
}
return result;
    }
};
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
14)Find n^x in log N
-----------------------------
TC:O(logn)
/* Function to calculate x raised to the power y in O(logn)*/
int power(int x, unsigned int y) 
{ 
	int temp; 
	if( y == 0) 
		return 1; 
	temp = power(x, y/2); 
	if (y%2 == 0) 
		return temp*temp; 
	else
		return x*temp*temp; 
} 

Input : x = 2, y = 3
Output : 8

Input : x = 7, y = 2
Output : 49

15)Count trailing zeros in factorial of a number
---------------------------------
TC:O(logn) - base will be 5 	SC:O(1)
/*
The idea is:
    1.The ZERO comes from 10.
    2.The 10 comes from 2 x 5
    3.And we need to account for all the products of 5 and 2. likes 4×5 = 20 ...
    4.So, if we take all the numbers with 5 as a factor, we'll have way more than enough even numbers to pair with them to get factors of 10
Example One:::::::::
How many multiples of 5 are between 1 and 23? There is 5, 10, 15, and 20, for four multiples of 5. Paired with 2's from the even factors, this makes for four factors of 10, so: 23! has 4 zeros.
Example Two:::::::::
How many multiples of 5 are there in the numbers from 1 to 100?because 100 ÷ 5 = 20, so, there are twenty multiples of 5 between 1 and 100.but wait, actually 25 is 5×5, so each multiple of 25 has an extra factor of 5, e.g. 25 × 4 = 100，which introduces extra of zero.So, we need know how many multiples of 25 are between 1 and 100? Since 100 ÷ 25 = 4, there are four multiples of 25 between 1 and 100.
Finally, we get 20 + 4 = 24 trailing zeroes in 100!
The above example tell us, we need care about 5, 5×5, 5×5×5, 5×5×5×5 ....
Example Three
By given number 4617.
5^1 : 4617 ÷ 5 = 923.4, so we get 923 factors of 5
5^2 : 4617 ÷ 25 = 184.68, so we get 184 additional factors of 5
5^3 : 4617 ÷ 125 = 36.936, so we get 36 additional factors of 5
5^4 : 4617 ÷ 625 = 7.3872, so we get 7 additional factors of 5
5^5 : 4617 ÷ 3125 = 1.47744, so we get 1 more factor of 5
5^6 : 4617 ÷ 15625 = 0.295488, which is less than 1, so stop here.
Then 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.
*/
int trailingZeroes(int n) {
    int result = 0;
    for(long long i=5; n/i>0; i=i*5){
        result =result+(n/i);
    }
    return result;
}
Input: n = 5
Output: 1 
Factorial of 5 is 120 which has one trailing 0.

Input: n = 20
Output: 4
Factorial of 20 is 2432902008176640000 which has
4 trailing zeroes.

Input: n = 100
Output: 24
16)Find GCD(n,m) in Log N
-----------------------------------
TC:O(log(min(n,m))
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
    
} 
Input:
98 56
Output:
GCD of 98 and 56 is 14

17)Grid Unique Paths
-------------------------------------
Method 1:
TC:O(max(m,n))	SC:O(1)
int numberOfPaths(int m, int n) 
{ 
    // We have to calculate m+n-2 C n-1 here 
    // which will be (m+n-2)! / (n-1)! (m-1)! 
    int path = 1; 
    for (int i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 
If doubt in above approach:	https://www.youtube.com/watch?v=m7chPc7zIF4

Method 2: (Using DP)
TC:O(mn) 	SC:(mn)
// Returns count of possible paths to reach cell at 
// row number m and column  number n from the topmost 
// leftmost cell (cell at 1, 1) 
int numberOfPaths(int m, int n) 
{ 
    // Create a 2D table to store results of subproblems 
    int count[m][n]; 
  
    // Count of paths to reach any cell in first column is 1 
    for (int i = 0; i < m; i++) 
        count[i][0] = 1; 
  
    // Count of paths to reach any cell in first row is 1 
    for (int j = 0; j < n; j++) 
        count[0][j] = 1; 
  
    // Calculate count of paths for other cells in 
    // bottom-up manner using the recursive solution 
    for (int i = 1; i < m; i++) { 
        for (int j = 1; j < n; j++) 
  
            // By uncommenting the last part the code calculatest he total 
            // possible paths if the diagonal Movements are allowed 
            count[i][j] = count[i - 1][j] + count[i][j - 1]; //+ count[i-1][j-1]; 
    } 
    return count[m - 1][n - 1]; 
} 

Input :  m = 2, n = 2;
Output : 2
There are two paths
(0, 0) -> (0, 1) -> (1, 1)
(0, 0) -> (1, 0) -> (1, 1)

Input :  m = 2, n = 3;
Output : 3
There are three paths
(0, 0) -> (0, 1) -> (0, 2) -> (1, 2)
(0, 0) -> (0, 1) -> (1, 1) -> (1, 2)
(0, 0) -> (1, 0) -> (1, 1) -> (1, 2)


Hashing:
========================================================
18)2 Sum problem
------------------------------------------------------
TC:O(n)		SC:O(n)

//Main logic
/*void printPairs(int arr[],int arr_size,int sum)
{
int i,temp;
bool binMap[MAX]={0};//Initialize hash map as 0
for(i=0;i<arr_size;i++)
{
	temp=sum-arr[i];
	if(temp>=0&&binMap[temp]==1)
		printf("Pair with given sum %d is (%d, %d) \n",sum,arr[i],temp);
	bitMap[arr[i]]=1;
}
}*/

In C++:
void printPairs(int arr[], int arr_size, int sum) 
{ 
    unordered_set<int> s; 
    for (int i = 0; i < arr_size; i++) { 
        int temp = sum - arr[i]; 
  
        if (s.find(temp) != s.end()) 
            cout << "Pair with given sum "<< sum << " is ( " << arr[i] << ", " << temp << ")" << endl; 
  
        s.insert(arr[i]); 
    } 
} 

Input: arr[] = {0, -1, 2, -3, 1}
        sum = -2
Output: -3, 1
If we calculate the sum of the output,
1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}
       sum = 0
Output: -1
No valid pair exists.

19)4 Sum problem
----------------------------------
TC:O(n^2)	SC:O(n^2)

void findFourElements( 
    int arr[], int n, int X) 
{ 
    // Store sums of all pairs 
    // in a hash table 
    unordered_map<int, pair<int, int> > mp; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            mp[arr[i] + arr[j]] = { i, j }; 
  
    // Traverse through all pairs and search 
    // for X - (current pair sum). 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            int sum = arr[i] + arr[j]; 
  
            // If X - sum is present in hash table, 
            if (mp.find(X - sum) != mp.end()) { 
  
                // Making sure that all elements are 
                // distinct array elements and an element 
                // is not considered more than once. 
                pair<int, int> p = mp[X - sum]; 
                if (p.first != i && p.first != j 
                    && p.second != i && p.second != j) { 
                    cout << arr[i] << ", "
                         << arr[j] << ", "
                         << arr[p.first] << ", "
                         << arr[p.second]; 
                    return; 
                } 
            } 
        } 
    } 
} 

Input: array = {10, 2, 3, 4, 5, 9, 7, 8} 
       X = 23 
Output: 3 5 7 8
Sum of output is equal to 23, 
i.e. 3 + 5 + 7 + 8 = 23.

Input: array = {1, 2, 3, 4, 5, 9, 7, 8}
       X = 16 
Output: 1 3 5 7
Sum of output is equal to 16, 
i.e. 1 + 3 + 5 + 7 = 16.

20)Longest Consecutive Sequence
-----------------------------------------------------
Tc:O(n) 	SC:O(n)

int findLongestConseqSubseq(int arr[], int n) 
{ 
    unordered_set<int> S; 
    int ans = 0; 
  
    // Hash all the array elements 
    for (int i = 0; i < n; i++) 
        S.insert(arr[i]); 
  
    // check each possible sequence from 
    // the start then update optimal length 
    for (int i = 0; i < n; i++) { 
        // if current element is the starting 
        // element of a sequence 
        if (S.find(arr[i] - 1) == S.end()) { 
            // Then check for next elements 
            // in the sequence 
            int j = arr[i]; 
            while (S.find(j) != S.end()) 
                j++; 
  
            // update  optimal length if 
            // this length is more 
            ans = max(ans, j - arr[i]); 
        } 
    } 
    return ans; 
} 

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: 
The subsequence 1, 3, 4, 2 is the longest 
subsequence of consecutive elements
/*i.e 1,2,3,4 */

21)Longest Subarray with 0 sum
-----------------------------------------
TC:O(n) 	SC:O(n)

int maxLen(int arr[], int n) 
{ 
    // Map to store the previous sums 
    unordered_map<int, int> presum; 
  
    int sum = 0; // Initialize the sum of elements 
    int max_len = 0; // Initialize result 
  
    // Traverse through the given array 
    for (int i = 0; i < n; i++) { 
        // Add current element to sum 
        sum += arr[i]; 
  
        if (arr[i] == 0 && max_len == 0) 
            max_len = 1; 
        if (sum == 0) 
            max_len = i + 1; 
  
        // Look for this sum in Hash table 
        if (presum.find(sum) != presum.end()) { 
            // If this sum is seen before, then update max_len 
            max_len = max(max_len, i - presum[sum]); 
        } 
        else { 
            // Else insert this sum with index in hash table 
            presum[sum] = i; 
        } 
    } 
  
    return max_len; 
} 

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
Explanation: The longest sub-array with 
elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation:There is no subarray with 0 sum

22)Longest substring without repeat
-----------------------------------
TC:O(n)		SC:O(d) 
		d is 256;

int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Explation of algorithm:
"dict" is used to keep tracking the char in the input string you read every time. start indicates the position of starting position of the substring. At the beginning, it initializes all value in "dict" to -1. Then in the for loop, it scans every char in the string. If the char in the "dict"'s value is larger than "start", it means it already in the substring. You should change the start position of substring to the repeat position and start a new count. "maxLen" records the maximum length of substring you have so far.

For example, the input is "aba", you check dict[s[0]], which is dict[97] is -1. Therefore, you can change the dict[97] to 0. In this way, you keep recording the string char's position in the dict. When you meet the second "a" in the input, dict[97] is 0 and larger than start, which is -1. Then you change start value to 0. When you apply length function ( i - start), you calculate the new substring length, which didn't contain the substring before the first "a".

23)Count number of subarrays with given XOR
--------------------------------------------
/*
Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}
*/
TC:O(n^2) 	SC:O(1)

long long subarrayXor(int arr[], int n, int m) 
{ 
    long long ans = 0; // Initialize ans 
  
    // Pick starting point i of subarrays 
    for (int i = 0; i < n; i++) { 
        int xorSum = 0; // Store XOR of current subarray 
  
        // Pick ending point j of subarray for each i 
        for (int j = i; j < n; j++) { 
            // calculate xorSum 
            xorSum = xorSum ^ arr[j]; 
  
            // If xorSum is equal to given value, 
            // increase ans by 1. 
            if (xorSum == m) 
                ans++; 
        } 
    } 
    return ans; 
} 

TC:O(n)		SC:O(n)
..............................................
long long subarrayXor(int arr[], int n, int m) 
{ 
    long long ans = 0; // Initialize answer to be returned 
  
    // Create a prefix xor-sum array such that 
    // xorArr[i] has value equal to XOR 
    // of all elements in arr[0 ..... i] 
    int* xorArr = new int[n]; 
  
    // Create map that stores number of prefix array 
    // elements corresponding to a XOR value 
    unordered_map<int, int> mp; 
  
    // Initialize first element of prefix array 
    xorArr[0] = arr[0]; 
  
    // Computing the prefix array. 
    for (int i = 1; i < n; i++) 
        xorArr[i] = xorArr[i - 1] ^ arr[i]; 
  
    // Calculate the answer 
    for (int i = 0; i < n; i++) { 
        // Find XOR of current prefix with m. 
        int tmp = m ^ xorArr[i]; 
  
        // If above XOR exists in map, then there 
        // is another previous prefix with same 
        // XOR, i.e., there is a subarray ending 
        // at i with XOR equal to m. 
        ans = ans + ((long long)mp[tmp]); 
  
        // If this subarray has XOR equal to m itself. 
        if (xorArr[i] == m) 
            ans++; 
  
        // Add the XOR of this subarray to the map 
        mp[xorArr[i]]++; 
    } 
  
    // Return total count of subarrays having XOR of 
    // elements as given value m 
    return ans; 
} 
Linked list
======================================================
24)Reverse a LinkedList:
----------------------------------------------
TC:O(n)		SC:O(1)
    void reverse() 
    { 
        // Initialize current, previous and 
        // next pointers 
        Node* current = head; 
        Node *prev = NULL, *next = NULL; 
  
        while (current != NULL) { 
            // Store next 
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
Example:
Input:
2
6
1 2 3 4 5 6
5
2 7 8 9 10
Output:
6 5 4 3 2 1
10 9 8 7 2

25)Find middle of LinkedList
-------------------------------------------------
TC:O(n/2)	SC:O(1)
void printMiddle(struct Node *head)  
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n\n", slow_ptr->data);  
    }  
}  
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
3
7
26)Merge two sorted Linked List
-----------------------------------------------
TC:O(n+m) 	SC:O(1)

node *merge(node *p , node *q , node *sorting)
{
	node *head3;
	
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	
	if(p && q)
	{
		if(p->data <= q->data)
		{
			sorting = p;
			p = sorting->next;
		}
		else
		{
			sorting = q;
			q = sorting->next;
		}
		
	}
	
	head3 = sorting;
	
	while(p && q)
	{
		if(p->data <= q->data)
		{
			sorting->next = p;
			sorting = p;
			p = sorting->next;
		}
		else
		{
			sorting->next = q;
			sorting = q;
			q = sorting->next;
		}
	}
	
	if(p==NULL)
	{
		sorting->next = q;
	}
	
	if(q==NULL)
	{
		sorting->next = p;
	}
	 	
	return head3;	
}

//recurse solution
TC:O(n+m) 	SC:O(n+m)

Node* SortedMerge(Node* a, Node* b)  
{  
    Node* result = NULL;  
      
    /* Base cases */
    if (a == NULL)  
        return(b);  
    else if (b == NULL)  
        return(a);  
      
    /* Pick either a or b, and recur */
    if (a->data <= b->data)  
    {  
        result = a;  
        result->next = SortedMerge(a->next, b);  
    }  
    else
    {  
        result = b;  
        result->next = SortedMerge(a, b->next);  
    }  
    return(result);  
}  




Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4



27)Remove N-th node from back of LinkedList
------------------------------------------------
TC:O(n)		SC:O(1)
 Node* deleteNode(int key) 
    { 
  
        // First pointer will point to 
        // the head of the linked list 
        Node *first = head; 
  
        // Second pointer will poin to the 
        // Nth node from the beginning 
        Node *second = head; 
        for (int i = 0; i < key; i++) 
        { 
  
            // If count of nodes in the given 
            // linked list is <= N 
            if (second->next == NULL)  
            { 
  
                // If count = N i.e. 
                // delete the head node 
                if (i == key - 1) 
                    head = head->next; 
                return head; 
            } 
            second = second->next; 
        } 
  
        // Increment both the pointers by one until 
        // second pointer reaches the end 
        while (second->next != NULL) 
        { 
            first = first->next; 
            second = second->next; 
        } 
  
        // First must be pointing to the 
        // Nth node from the end by now 
        // So, delete the node first is pointing to 
        first->next = first->next->next; 
        return head; 
    } 
Input: 2 -> 3 -> 1 -> 7 -> NULL, N = 1
Output:
Created Linked list is:
2 3 1 7
Linked List after Deletion is:
2 3 1

Input: 1 -> 2 -> 3 -> 4 -> NULL, N = 4
Output:
Created Linked list is:
1 2 3 4
Linked List after Deletion is:
2 3 4 

28)Delete a given Node when a node is given.(without head pointer)
---------------------------------------------
TC:O(1) 	SC:O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};
---------------
if the node should be freed, we need 3 lines:
----------------
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        *node = *temp;
        delete temp;
    }
};

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

/**/
m=(m->next) here u just transfer node m to m->next allocation.
but *m=*(m->next) ,*m pointer assigning the whole block memory of
*(m->next) pointer.

29)Add two numbers as LinkedList
----------------------------------------------------
Tc:O(n+m) 	SC:O(n+m)

Node* addTwoLists(Node* first, Node* second) 
{ 
  
    // res is head node of the resultant list 
    Node* res = NULL; 
    Node *temp, *prev = NULL; 
    int carry = 0, sum; 
  
    // while both lists exist 
    while (first != NULL 
           || second != NULL) { 
        // Calculate value of next 
        // digit in resultant list. 
        // The next digit is sum of 
        // following things 
        // (i) Carry 
        // (ii) Next digit of first 
        // list (if there is a next digit) 
        // (ii) Next digit of second 
        // list (if there is a next digit) 
        sum = carry + (first ? first->data : 0) 
              + (second ? second->data : 0); 
  
        // update carry for next calulation 
        carry = (sum >= 10) ? 1 : 0; 
  
        // update sum if it is greater than 10 
        sum = sum % 10; 
  
        // Create a new node with sum as data 
        temp = newNode(sum); 
  
        // if this is the first node then 
        // set it as head of the resultant list 
        if (res == NULL) 
            res = temp; 
  
        // If this is not the first 
        // node then connect it to the rest. 
        else
            prev->next = temp; 
  
        // Set prev for next insertion 
        prev = temp; 
  
        // Move first and second 
        // pointers to next nodes 
        if (first) 
            first = first->next; 
        if (second) 
            second = second->next; 
    } 
  
    if (carry > 0) 
        temp->next = newNode(carry); 
  
    // return head of the resultant list 
    return res; 
} 

Input:
List1: 5->6->3 // represents number 365
List2: 8->4->2 // represents number 248
Output:
Resultant list: 3->1->6 // represents number 613
Explanation: 365 + 248 = 613

30)Find intersection point of Y LinkedList
------------------------------------------------
TC:O(m+n)	SC:O(1)

struct Node* findMergePoint3(struct Node *A, struct Node *B) {
    int m = length(A);
    int n = length(B);
    int d = n - m;
    if(m > n) {
        struct Node* temp = A;
        A = B;
        B = temp;
        d = m - n;
    }
    int i;
    for(i=0;i<d;i++) {
        B = B->next;
    }
    while(A != NULL && B != NULL) {
        if(A == B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}
2
2 3 2
10 20
30 40 50
5 10
/*
10->20->5->10
30->40->50->5->10
*/
2 3 2
10 20
30 40 50
10 20
/*
10->20->5->10
30->40->50->5->10
*/
Output:
5
10

31)Check if a LinkedList is palindrome or not.
---------------------------------------------
TC:O(n)		SC:O(1)

bool isPalindrome(struct Node* head) 
{ 
    struct Node *slow_ptr = head, *fast_ptr = head; 
    struct Node *second_half, *prev_of_slow_ptr = head; 
    struct Node* midnode = NULL; // To handle odd size list 
    bool res = true; // initialize result 
  
    if (head != NULL && head->next != NULL) { 
        /* Get the middle of the list. Move slow_ptr by 1 
          and fast_ptrr by 2, slow_ptr will have the middle 
          node */
        while (fast_ptr != NULL && fast_ptr->next != NULL) { 
            fast_ptr = fast_ptr->next->next; 
  
            /*We need previous of the slow_ptr for 
             linked lists  with odd elements */
            prev_of_slow_ptr = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        /* fast_ptr would become NULL when there are even elements in list.  
           And not NULL for odd elements. We need to skip the middle node  
           for odd case and store it somewhere so that we can restore the 
           original list*/
        if (fast_ptr != NULL) { 
            midnode = slow_ptr; 
            slow_ptr = slow_ptr->next; 
        } 
  
        // Now reverse the second half and compare it with first half 
        second_half = slow_ptr; 
        prev_of_slow_ptr->next = NULL; // NULL terminate first half 
        reverse(&second_half); // Reverse the second half 
        res = compareLists(head, second_half); // compare 
  
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again 
  
        // If there was a mid node (odd size case) which 
        // was not part of either first half or second half. 
        if (midnode != NULL) { 
            prev_of_slow_ptr->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_ptr->next = second_half; 
    } 
    return res; 
} 
  
/* Function to reverse the linked list  Note that this 
    function may change the head */
void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
/* Function to check if two input lists have same data*/
bool compareLists(struct Node* head1, struct Node* head2) 
{ 
    struct Node* temp1 = head1; 
    struct Node* temp2 = head2; 
  
    while (temp1 && temp2) { 
        if (temp1->data == temp2->data) { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    /* Will reach here when one is NULL 
      and other is not */
    return 0; 
} 

Input:
3
1 2 1
4
1 2 3 4
Output:
1
0

32)Reverse a LinkedList in groups
-------------------------------------
TC:O(n)		SC:O(1)


node *swap_in_a_group(node *start , int k)
{
	//swap the linked list in group size = k
	node *p , *q ,*new_start , *temp;
	int cnt;
	p = start;
	cnt = 0;
	while(cnt != k-1)    // go to the 'K'th node
	{
		if(p->next == NULL)
			{
			return start;
			}
		p = p->next;
		cnt++;
	}
	
	new_start = p; //the new start		
	q = new_start;	
	while(1)
	{
		p = start;
		temp = q->next;
		if(temp == NULL)  // if total number of nodes is divisible by K (multiple of K)
		{
			reverse(p);
			return new_start;
		}
		
		q->next = NULL;
		q = temp;
		start = temp;
		
		cnt = 0;
		//in the last outside while loop , if remainder is non-zero number of nodes
		while(cnt != k-1) 
		{
			if(temp->next == NULL)
				{	/*if remaining elements not to be reversed*/
					reverse(p);	
					p->next = q;
					return new_start;
					/*if remaining elements to be reversed*/
					/*reverse(p);
              				  break;
					*/
				}		
			temp = temp->next;
			cnt++;
		}
		
		reverse(p);
		p->next = temp;
		q = temp;
	}

return new_start;
}
Input:
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4

33)Detect a cycle and removing loop
-------------------------------------
TC:O(n)		SC:O(1)

void remove(Node* head,Node* f)
{
    Node* s=head;
    while(s!=f)
    {
        s=s->next;
        f=f->next;
    }
    
    /to reach the node before the "Loop node"/
    while(s->next!=f)
        s=s->next;
    
    s->next=NULL;
    
}

void removeTheLoop(Node *head)
{
     Node* s=head,*f=head;
     
     while(s&&f&&f->next)
     {
         f=f->next->next;
         s=s->next;
         if(s==f)
         {
             remove(head,f);
             return;
         }
     }
}

Input:
3
1 3 4
2
4
1 8 3 4
0
Output:
1
1

/why floyd works/

Distance traveled by fast pointer = 2 * (Distance traveled 
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by 
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by 
       slow pointer before they meet first time


34)Flattening of a LinkedList
---------------------------------
TC:O(n^k)		SC:O(1)
/*If we take there are ' K ' linked list in right.
and merging two list takes O(N) time.
then overall time complexity will be: O(N*K)*/

Node *merge(Node *p , Node *q )
{
	Node *head3,*sorting;
	
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	
	if(p && q)
	{
		if(p->data <= q->data)
		{
			sorting = p;
			p = sorting->bottom;
		}
		else
		{
			sorting = q;
			q = sorting->bottom;
		}
		
	}
	
	head3 = sorting;
	
	while(p && q)
	{
		if(p->data <= q->data)
		{
			sorting->bottom = p;
			sorting = p;
			p = sorting->bottom;
		}
		else
		{
			sorting->bottom = q;
			sorting = q;
			q = sorting->bottom;
		}
	}
	
	if(p==NULL)
	{
		sorting->bottom = q;
	}
	
	if(q==NULL)
	{
		sorting->bottom = p;
	}
	
	return head3;	
}

Node *flatten(Node *root)
{
    if(root==NULL || root->next==NULL)
    return root;
    
    return merge(root,flatten(root->next));
    
}

Input:
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

Output:
 5->7->8->10->19->20->22->28->30->35->40->45->50.

35)Rotate a LinkedList
-------------------------------------
TC:O(n)		SC:O(1)


Node* temp = head;
while(temp->next){
temp = temp->next;
}
temp->next = head; // linking last node with first node
Node *end;
while(k--){
end = head;
head = head->next;
}
// end is previous of updated head, so make end of next as null as it is the last node of updated linked list
end->next = NULL;
return head;

Input:
2
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3
Output:
5 6 7 8 1 2 3 4
8 9 2 4 7

36)Clone a Linked List with random and next pointer.
------------------------------------------------------
TC:O(n)		SC:O(1)

Node* clone(Node *start) 
{ 
    Node* curr = start, *temp; 
  
    // insert additional node after 
    // every node of original list 
    while (curr) 
    { 
        temp = curr->next; 
  
        // Inserting node 
        curr->next = new Node(curr->data); 
        curr->next->next = temp; 
        curr = temp; 
    } 
  
    curr = start; 
  
    // adjust the random pointers of the 
    // newly added nodes 
    while (curr) 
    { 
        if(curr->next) 
            curr->next->random = curr->random ?  
                                 curr->random->next : curr->random; //when the random pointer points to nullptr. so here you should add a condition if(curr->random!=NULL).
  
        // move to the next newly added node by 
        // skipping an original node 
        curr = curr->next?curr->next->next:curr->next; 
    } 
  
    Node* original = start, *copy = start->next; 
  
    // save the start of copied linked list 
    temp = copy; 
  
    // now separate the original list and copied list 
    while (original && copy) 
    { 
        original->next = 
         original->next? original->next->next : original->next; 
  
        copy->next = copy->next?copy->next->next:copy->next; 
        original = original->next; 
        copy = copy->next; 
    } 
  
    return temp; 
} 

Two pointer
====================================================================
37)Merge two sorted LinkedLists
------------------------------------------------
solved above- question 26

38)Find the starting point of the loop.
-------------------------------------------------
TC:O(n) 	SC:O(1)


int detectLoop(Node* list) 
{ 
    Node *slow_p = list, *fast_p = list; 
  
    while (slow_p && fast_p && fast_p->next) { 
        slow_p = slow_p->next; 
        fast_p = fast_p->next->next; 
        if (slow_p == fast_p) { 
            return 1; 
        } 
    } 
    return 0; 
} 

39)3 sum
-----------------------------------------------
TC:O(n^2)	SC:O(1)

bool find3Numbers(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    /* Sort the elements */
    sort(A, A + arr_size); 
  
    /* Now fix the first element one by one and find the 
       other two elements */
    for (int i = 0; i < arr_size - 2; i++) { 
  
        // To find the other two elements, start two index 
        // variables from two corners of the array and move 
        // them toward each other 
        l = i + 1; // index of the first element in the 
        // remaining elements 
  
        r = arr_size - 1; // index of the last element 
        while (l < r) { 
            if (A[i] + A[l] + A[r] == sum) { 
                printf("Triplet is %d, %d, %d", A[i], 
                       A[l], A[r]); 
                return true; 
            } 
            else if (A[i] + A[l] + A[r] < sum) 
                l++; 
            else // A[i] + A[l] + A[r] > sum 
                r--; 
        } 
    } 
  
    // If we reach here, then no triplet was found 
    return false; 
} 

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24. 

Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present 
in the array whose sum is 9. 

40)Trapping rainwater
------------------------------------------------
TC:O(n)		SC:O(1)
int findWater(int arr[], int n) 
{ 
    // initialize output 
    int result = 0; 
  
    // maximum element on left and right 
    int left_max = 0, right_max = 0; 
  
    // indices to traverse the array 
    int lo = 0, hi = n - 1; 
  
    while (lo <= hi) { 
        if (arr[lo] < arr[hi]) { 
            if (arr[lo] > left_max) 
                // update max in left 
                left_max = arr[lo]; 
            else
                // water on curr element = max - curr 
                result += left_max - arr[lo]; 
            lo++; 
        } 
        else { 
            if (arr[hi] > right_max) 
                // update right maximum 
                right_max = arr[hi]; 
            else
                result += right_max - arr[hi]; 
            hi--; 
        } 
    } 
  
    return result; 
} 

Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7
We can trap "3 units" of water between 3 and 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  

Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6

Trap "1 unit" between first 1 and 2, "4 units" between
first 2 and 3 and "1 unit" between second last 1 and last 2 

41)Remove Duplicate from Sorted array
--------------------------------------------------------
TC:O(n)		SC:O(1)

int removeDuplicates(int arr[], int n) 
{ 
    if (n==0 || n==1) 
        return n; 
  
    // To store index of next unique element 
    int j = 0; 
  
    // Doing same as done in Method 1 
    // Just maintaining another updated index i.e. j 
    for (int i=0; i < n-1; i++) 
        if (arr[i] != arr[i+1]) 
            arr[j++] = arr[i]; 
  
    arr[j++] = arr[n-1]; 
  
    return j; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // removeDuplicates() returns new size of 
    // array. 
    n = removeDuplicates(arr, n); 
  
    // Print updated array 
    for (int i=0; i<n; i++) 
        cout << arr[i] << " "; 
  
    return 0; 
} 

Input  : arr[] = {2, 2, 2, 2, 2}
Output : arr[] = {2}
         new size = 1

Input  : arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}
Output : arr[] = {1, 2, 3, 4, 5}
         new size = 5

42)Max continuous number of 1’s
-----------------------------------------------------------
TC:O(n)		SC:O(1)

int getMaxLength(bool arr[], int n) 
{ 
    int count = 0; //intitialize count 
    int result = 0; //initialize max 
  
    for (int i = 0; i < n; i++) 
    { 
        // Reset count when 0 is found 
        if (arr[i] == 0) 
            count = 0; 
  
        // If 1 is found, increment count 
        // and update result if count becomes 
        // more. 
        else
        { 
            count++;//increase count 
            result = max(result, count); 
        } 
    } 
  
    return result; 
} 

Input  : arr[] = {1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1}
Output : 4

Input  : arr[] = {0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
Output : 1

43)Go through Puzzles from GFG (Search on own)
GREEDY 
=================================================
44)N meeting in one room
---------------------------------------------------
TC:O(nlogn) 	


    #include <bits/stdc++.h>
    using namespace std;
     
    struct Activity{
        int start, finish, index;
    };
     
    bool activityCompare(Activity s1, Activity s2)
    {
        return s1.finish < s2.finish;
    }
     
    int main() {
    	int t,n,i,j;
    	cin>>t;
    	while(t--)
    	{
    	    cin>>n;
    	    Activity arr[n];
    	    for(i=0;i<n;i++)
    	    {
    	        cin>>arr[i].start;
    	        arr[i].index = i;
    	    }
     
    	    for(i=0;i<n;i++)
    	    cin>>arr[i].finish;
    	    sort(arr,arr+n,activityCompare);
     
    	    i = 0;
            cout << arr[i].index+1 << " ";
            for (int j = 1; j < n; j++)
            {
              if (arr[j].start >= arr[i].finish)
              {
                  cout << arr[j].index+1<<" ";
                  i = j;
              }
            }
            cout<<endl;
    	}
    	return 0;
    }

Input:
6
1 3 0 5 8 5/*starting time*/
2 4 6 7 9 9/*Finishing time*/
output:
1 2 4 5 /*index in which meeting will be held*/

45)Activity Selection
---------------------------------------------------
TC:O(nlogn) 

// C++ program for activity selection problem 
// when input activities may not be sorted. 
#include <bits/stdc++.h> 
using namespace std; 

// A job has a start time, finish time and profit. 
struct Activitiy 
{ 
	int start, finish; 
}; 

// A utility function that is used for sorting 
// activities according to finish time 
bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
	return (s1.finish < s2.finish); 
} 

// Returns count of the maximum set of activities that can 
// be done by a single person, one at a time. 
void printMaxActivities(Activitiy arr[], int n) 
{ 
	// Sort jobs according to finish time 
	sort(arr, arr+n, activityCompare); 

	cout << "Following activities are selected n"; 

	// The first activity always gets selected 
	int i = 0; 
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 

	// Consider rest of the activities 
	for (int j = 1; j < n; j++) 
	{ 
	// If this activity has start time greater than or 
	// equal to the finish time of previously selected 
	// activity, then select it 
	if (arr[j].start >= arr[i].finish) 
	{ 
		cout << "(" << arr[j].start << ", "
			<< arr[j].finish << "), "; 
		i = j; 
	} 
	} 
} 

// Driver program 
int main() 
{ 
	Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printMaxActivities(arr, n); 
	return 0; 
} 
Input:
{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}
Output:
Following activities are selected 
(1, 2), (3, 4), (5, 7), (8, 9), 

46)Greedy algorithm to find minimum number of coins
--------------------------------------
TC:O(N*logN).		SC:O(1)
void findMin(int V) 
{ 
    sort(deno, deno + n); 
  
    // Initialize result 
    vector<int> ans; 
  
    // Traverse through all denomination 
    for (int i = n - 1; i >= 0; i--) { 
  
        // Find denominations 
        while (V >= deno[i]) { 
            V -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  
    // Print result 
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " "; 
} 

Following is minimal number of change 
for 93: 50  20  20  2  1

47)Fractional Knapsack Problem
-------------------------------------------------
TC:O(nlogn)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct {
   int v;
   int w;
   float d;
} Item;
void input(Item items[],int sizeOfItems) {
   cout << "Enter total "<< sizeOfItems <<" item's values and weight" <<
   endl;
   for(int I = 0; I < sizeOfItems; i++) {
      cout << "Enter "<< i+1 << " V ";
      cin >> items[i].v;
      cout << "Enter "<< i+1 << " W";
      cin >> items[i].w;
   }
}
void display(Item items[], int sizeOfItems) {
   int i;
   cout << "values: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].v << "\t";
   }
   cout << endl << "weight: ";
   for (I = 0; I < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl;
}
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}
float knapsack(Item items[], int sizeOfItems, int W) {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++) {
      items[i].d = items[i].v / items[i].w;
   }
   sort(items, items+sizeOfItems, compare);
   for(i=0; i<sizeOfItems; i++) {
      if(totalWeight + items[i].w<= W) {
         totalValue += items[i].v ;
         totalWeight += items[i].w;
      } else {
         int wt = W-totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
      }
   }
   cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}
int main() {
   int W;
   Item items[4];
   input(items, 4);
   cout << "Entered data \n";
   display(items,4);
   cout<< "Enter Knapsack weight \n";
   cin >> W;
   float mxVal = knapsack(items, 4, W);
   cout << "Max value for "<< W <<" weight is "<< mxVal;
}

output:
Enter total 4 item's values and weight
Enter 1 V 50
Enter 1 W 10
Enter 2 V 60
Enter 2 W 20
Enter 3 V 70
Enter 3 W 30
Enter 4 V 70
Enter 4 W 40
Entered data
values: 50 60 70 70
weight: 10 20 30 40
Enter Knapsack weight
60
total weight in bag 60
Max value for 60 weight is 180


48)Minimum number of platforms required for a railway
------------------------------------------------
TC:O(nLogn)	SC:O(1)

// Program to find minimum number of platforms 
// required on a railway station 
#include <algorithm> 
#include <iostream> 

using namespace std; 

// Returns minimum number of platforms reqquired 
int findPlatform(int arr[], int dep[], int n) 
{ 
	// Sort arrival and departure arrays 
	sort(arr, arr + n); 
	sort(dep, dep + n); 

	// plat_needed indicates number of platforms 
	// needed at a time 
	int plat_needed = 1, result = 1; 
	int i = 1, j = 0; 

	// Similar to merge in merge sort to process 
	// all events in sorted order 
	while (i < n && j < n) { 

		// If next event in sorted order is arrival, 
		// increment count of platforms needed 
		if (arr[i] <= dep[j]) { 
			plat_needed++; 
			i++; 
		} 

		// Else decrement count of platforms needed 
		else if (arr[i] > dep[j]) { 
			plat_needed--; 
			j++; 
		} 

		// Update result if needed 
		if (plat_needed > result) 
			result = plat_needed; 
	} 

	return result; 
} 

// Driver program to test methods of graph class 
int main() 
{ 
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep, n); 
	return 0; 
} 

output:Minimum Number of Platforms Required = 3

49)Job sequencing Problem
--------------------------------------------------
Time complexity:O(n^2)

// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<iostream> 
#include<algorithm> 
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
char id;	 // Job Id 
int dead; // Deadline of job 
int profit; // Profit if job is over before or on deadline 
}; 

// This function is used for sorting all jobs according to profit 
bool comparison(Job a, Job b) 
{ 
	return (a.profit > b.profit); 
} 

// Returns minimum number of platforms reqquired 
void printJobScheduling(Job arr[], int n) 
{ 
	// Sort all jobs according to decreasing order of prfit 
	sort(arr, arr+n, comparison); 

	int result[n]; // To store result (Sequence of jobs) 
	bool slot[n]; // To keep track of free time slots 

	// Initialize all slots to be free 
	for (int i=0; i<n; i++) 
		slot[i] = false; 

	// Iterate through all given jobs 
	for (int i=0; i<n; i++) 
	{ 
	// Find a free slot for this job (Note that we start 
	// from the last possible slot) 
	for (int j=min(n, arr[i].dead)-1; j>=0; j--) 
	{ 
		// Free slot found 
		if (slot[j]==false) 
		{ 
			result[j] = i; // Add this job to result 
			slot[j] = true; // Make this slot occupied 
			break; 
		} 
	} 
	} 

	// Print the result 
	for (int i=0; i<n; i++) 
	if (slot[i]) 
		cout << arr[result[i]].id << " "; 
} 

// Driver program to test methods 
int main() 
{ 
	Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
				{'d', 1, 25}, {'e', 3, 15}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Following is maximum profit sequence of jobsn"; 
	printJobScheduling(arr, n); 
	return 0; 
} 

Following is maximum profit sequence of jobs
c a e


Backtracking
=========================================================
50)N queens Problem
--------------------------------------------------------
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
bool isSafe(int row,int col,bool board[][10],int n){
    for(int i=0;i<col;i++){
        if(board[row][i]==true)
        return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]==true)
        return false;
    }
    for(int i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j]==true)
        return false;
    }
    return true;
}
void helper(int col,int n,vector<int>v,bool board[][10]){
    if(col==n)
    return;
    for(int i=0;i<n;i++){
        if(isSafe(i,col,board,n)==true){
            v.push_back(i+1);
            board[i][col]=true;
            helper(col+1,n,v,board);
            if(v.size()==n){
                printf("[");
                for(auto x:v)
                printf("%d ",x);
                printf("] ");
            }
            board[i][col]=false;
            v.pop_back();
        }
    }
}
void nQueens(int n){
    vector<int> v;
    bool board[10][10];
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    board[i][j]=false;
    helper(0,n,v,board);
    printf("\n");
}

int main()
 {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n==1)
        printf("[1 ]\n");
        else if(n==2 || n==3)
        printf("-1\n");
        else
        nQueens(n);
	}
	return 0;
}

input:
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]

51)Sudoko
------------------------------------
TC: O(9^(n*n)).		SC: O(n*n)

// A Backtracking program in 
// C++ to solve Sudoku problem 
#include <bits/stdc++.h> 
using namespace std; 

// UNASSIGNED is used for empty 
// cells in sudoku grid 
#define UNASSIGNED 0 

// N is used for the size of Sudoku grid. 
// Size will be NxN 
#define N 9 

// This function finds an entry in grid 
// that is still unassigned 
bool FindUnassignedLocation(int grid[N][N], int& row, int& col); 

// Checks whether it will be legal 
// to assign num to the given row, col 
bool isSafe(int grid[N][N], int row, int col, int num); 

/* Takes a partially filled-in grid and attempts 
to assign values to all unassigned locations in 
such a way to meet the requirements for 
Sudoku solution (non-duplication across rows, 
columns, and boxes) */
bool SolveSudoku(int grid[N][N]) 
{ 
	int row, col; 

	// If there is no unassigned location, 
	// we are done 
	if (!FindUnassignedLocation(grid, row, col)) 
		// success! 
		return true; 

	// Consider digits 1 to 9 
	for (int num = 1; num <= 9; num++) { 
		// if looks promising 
		if (isSafe(grid, row, col, num)) { 
			// make tentative assignment 
			grid[row][col] = num; 

			// return, if success, yay! 
			if (SolveSudoku(grid)) 
				return true; 

			// failure, unmake & try again 
			grid[row][col] = UNASSIGNED; 
		} 
	} 
	// this triggers backtracking 
	return false; 
} 

/* Searches the grid to find an entry that is 
still unassigned. If found, the reference 
parameters row, col will be set the location 
that is unassigned, and true is returned. 
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N], int& row, int& col) 
{ 
	for (row = 0; row < N; row++) 
		for (col = 0; col < N; col++) 
			if (grid[row][col] == UNASSIGNED) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry in the specified row matches 
the given number. */
bool UsedInRow(int grid[N][N], int row, int num) 
{ 
	for (int col = 0; col < N; col++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry in the specified column 
matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num) 
{ 
	for (int row = 0; row < N; row++) 
		if (grid[row][col] == num) 
			return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
an assigned entry within the specified 3x3 box 
matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, 
			int boxStartCol, int num) 
{ 
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++) 
			if (grid[row + boxStartRow] 
					[col + boxStartCol] 
				== num) 
				return true; 
	return false; 
} 

/* Returns a boolean which indicates whether 
it will be legal to assign num to the given 
row, col location. */
bool isSafe(int grid[N][N], int row, 
			int col, int num) 
{ 
	/* Check if 'num' is not already placed in 
	current row, current column and current 3x3 box */
	return !UsedInRow(grid, row, num) 
		&& !UsedInCol(grid, col, num) 
		&& !UsedInBox(grid, row - row % 3, 
						col - col % 3, num) 
		&& grid[row][col] == UNASSIGNED; 
} 

/* A utility function to print grid */
void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) { 
		for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	// 0 means unassigned cells 
	int grid[N][N] =     	      {	{ 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (SolveSudoku(grid) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
} 

// This is code is contributed by rathbhupendra 
output:
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 


52)M coloring Problem
-------------------------------------------------------
TC: O(m^V)	SC:O(V) 


#include <stdbool.h> 
#include <stdio.h> 

// Number of vertices in the graph 
#define V 4 

void printSolution(int color[]); 

/* A utility function to check if 
the current color assignment 
is safe for vertex v i.e. checks 
whether the edge exists or not 
(i.e, graph[v][i]==1). If exist 
then checks whether the color to 
be filled in the new vertex(c is 
sent in the parameter) is already 
used by its adjacent 
vertices(i-->adj vertices) or 
not (i.e, color[i]==c) */
bool isSafe( 
	int v, bool graph[V][V], 
	int color[], int c) 
{ 
	for (int i = 0; i < V; i++) 
		if ( 
			graph[v][i] && c == color[i]) 
			return false; 
	return true; 
} 

/* A recursive utility function 
to solve m coloring problem */
bool graphColoringUtil( 
	bool graph[V][V], int m, 
	int color[], int v) 
{ 
	/* base case: If all vertices are 
	assigned a color then return true */
	if (v == V) 
		return true; 

	/* Consider this vertex v and 
	try different colors */
	for (int c = 1; c <= m; c++) { 
		/* Check if assignment of color 
		c to v is fine*/
		if (isSafe( 
				v, graph, color, c)) { 
			color[v] = c; 

			/* recur to assign colors to 
			rest of the vertices */
			if ( 
				graphColoringUtil( 
					graph, m, color, v + 1) 
				== true) 
				return true; 

			/* If assigning color c doesn't 
			lead to a solution then remove it */
			color[v] = 0; 
		} 
	} 

	/* If no color can be assigned to 
	this vertex then return false */
	return false; 
} 

/* This function solves the m Coloring 
problem using Backtracking. It mainly 
uses graphColoringUtil() to solve the 
problem. It returns false if the m 
colors cannot be assigned, otherwise 
return true and prints assignments of 
colors to all vertices. Please note 
that there may be more than one solutions, 
this function prints one of the 
feasible solutions.*/
bool graphColoring( 
	bool graph[V][V], int m) 
{ 
	// Initialize all color values as 0. 
	// This initialization is needed 
	// correct functioning of isSafe() 
	int color[V]; 
	for (int i = 0; i < V; i++) 
		color[i] = 0; 

	// Call graphColoringUtil() for vertex 0 
	if ( 
		graphColoringUtil( 
			graph, m, color, 0) 
		== false) { 
		printf("Solution does not exist"); 
		return false; 
	} 

	// Print the solution 
	printSolution(color); 
	return true; 
} 

/* A utility function to print solution */
void printSolution(int color[]) 
{ 
	printf( 
		"Solution Exists:"
		" Following are the assigned colors \n"); 
	for (int i = 0; i < V; i++) 
		printf(" %d ", color[i]); 
	printf("\n"); 
} 

// driver program to test above function 
int main() 
{ 
	/* Create following graph and test 
	whether it is 3 colorable 
       (3)---(2) 
	|   /  | 
	|  /   | 
	| /    | 
	(0)---(1) 
	*/
	bool graph[V][V] = { 
		{ 0, 1, 1, 1 }, 
		{ 1, 0, 1, 0 }, 
		{ 1, 1, 0, 1 }, 
		{ 1, 0, 1, 0 }, 
	}; 
	int m = 3; // Number of colors 
	graphColoring(graph, m); 
	return 0; 
} 

output:
Solution Exists: Following are the assigned colors 
 1  2  3  2

53)Rat in a Maze
---------------------------------------------------
Time complexity is an exponential relationship O(bm) where b is the branching factor, and m is the maximal depth of a leaf node.� Number of nodes generated:


1 + b + b^2 + � + b^m = O(b^m)//b can be directions U,D,L,R and m can be max(row,col);
TC:O(4^m)

Space complexity is O(bm) or O(m).� It is a linear relationship, not an exponential relationship like the Time complexity.

// C++ implemenattion of the above approach 
#include <bits/stdc++.h> 
#define MAX 5 
using namespace std; 

// Function returns true if the 
// move taken is valid else 
// it will return false. 
bool isSafe(int row, int col, int m[][MAX], 
				int n, bool visited[][MAX]) 
{ 
	if (row == -1 || row == n || col == -1 || 
				col == n || visited[row][col] 
						|| m[row][col] == 0) 
		return false; 

	return true; 
} 

// Function to print all the possible 
// paths from (0, 0) to (n-1, n-1). 
void printPathUtil(int row, int col, int m[][MAX], 
			int n, string& path, vector<string>& 
			possiblePaths, bool visited[][MAX]) 
{ 
	// This will check the initial point 
	// (i.e. (0, 0)) to start the paths. 
	if (row == -1 || row == n || col == -1 
			|| col == n || visited[row][col] 
						|| m[row][col] == 0) 
		return; 

	// If reach the last cell (n-1, n-1) 
	// then store the path and return 
	if (row == n - 1 && col == n - 1) { 
		possiblePaths.push_back(path); 
		return; 
	} 

	// Mark the cell as visited 
	visited[row][col] = true; 

	// Try for all the 4 directions (down, left, 
	// right, up) in the given order to get the 
	// paths in lexicographical order 

	// Check if downward move is valid 
	if (isSafe(row + 1, col, m, n, visited)) 
	{ 
		path.push_back('D'); 
		printPathUtil(row + 1, col, m, n, 
				path, possiblePaths, visited); 
		path.pop_back(); 
	} 

	// Check if the left move is valid 
	if (isSafe(row, col - 1, m, n, visited)) 
	{ 
		path.push_back('L'); 
		printPathUtil(row, col - 1, m, n, 
				path, possiblePaths, visited); 
		path.pop_back(); 
	} 

	// Check if the right move is valid 
	if (isSafe(row, col + 1, m, n, visited)) 
	{ 
		path.push_back('R'); 
		printPathUtil(row, col + 1, m, n, 
				path, possiblePaths, visited); 
		path.pop_back(); 
	} 

	// Check if the upper move is valid 
	if (isSafe(row - 1, col, m, n, visited)) 
	{ 
		path.push_back('U'); 
		printPathUtil(row - 1, col, m, n, 
			path, possiblePaths, visited); 
		path.pop_back(); 
	} 

	// Mark the cell as unvisited for 
	// other possible paths 
	visited[row][col] = false; 
} 

// Function to store and print 
// all the valid paths 
void printPath(int m[MAX][MAX], int n) 
{ 
	// vector to store all the possible paths 
	vector<string> possiblePaths; 
	string path; 
	bool visited[n][MAX]; 
	memset(visited, false, sizeof(visited)); 
	
	// Call the utility function to 
	// find the valid paths 
	printPathUtil(0, 0, m, n, path, 
					possiblePaths, visited); 

	// Print all possible paths 
	for (int i = 0; i < possiblePaths.size(); i++) 
		cout << possiblePaths[i] << " "; 
} 

// Driver code 
int main() 
{ 
	int m[MAX][MAX] = { { 1, 0, 0, 0, 0 }, 
						{ 1, 1, 1, 1, 1 }, 
						{ 1, 1, 1, 0, 1 }, 
						{ 0, 0, 0, 0, 1 }, 
						{ 0, 0, 0, 0, 1 } }; 
	int n = sizeof(m) / sizeof(m[0]); 
	printPath(m, n); 

	return 0; 
} 

Output:
DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD

54)Print all Permutations of a string/array
------------------------------------------------------
Time Complexity: O(n*n!) 

// C++ program to print all 
// permutations with duplicates allowed 
#include <bits/stdc++.h> 
using namespace std; 


// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string 
// 3. Ending index of the string. 
void permute(string a, int l, int r) 
{ 
	// Base case 
	if (l == r) 
		cout<<a<<endl; 
	else
	{ 
		// Permutations made 
		for (int i = l; i <= r; i++) 
		{ 

			// Swapping done 
			swap(a[l], a[i]); 

			// Recursion called 
			permute(a, l+1, r); 

			//backtrack 
			swap(a[l], a[i]); 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "ABC"; 
	int n = str.size(); 
	permute(str, 0, n-1); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 


Output:

ABC
ACB
BAC
BCA
CBA
CAB

55)Word Break (print all ways)
------------------------------------------------------
 TC:O(2n*s)/*s is string and n is size of dict*/	SC:O(n)/*space complexity doubt*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void breakPossible(string s,unordered_map<string,bool> dict,vector<string> &res,int i=0,vector<string> words=vector<string>())
{
	if(i>=s.length())
	{
		if(!words.size())
		{
			return;
		}
		int l=words[0].length();
		string sent=words[0];
		for(auto itr=words.begin()+1;itr!=words.end();itr++)
		{
			l+=(*itr).length();
			sent+=" "+(*itr);
		}
		if(l==s.length())
		{
			res.push_back(sent);
		}
		return;
	}
	int c=i;
	string t="";
	while(c<s.length())
	{
		t+=s[c];
		c++;
		if(dict[t])
		{
			words.push_back(t);
			breakPossible(s,dict,res,c,words);
			words.pop_back();
		}
	}
}

int main()
{
	int t;
	cin>>t;
	for(int iter=0;iter<t;iter++)
	{
		int n;
		cin>>n;
		unordered_map<string,bool> um;
		for(int i=0;i<n;i++)
		{
			string e;
			cin>>e;
			um[e]=true;
		}
		string s;
		cin>>s;
		vector<string> res;
		breakPossible(s,um,res);
		for(auto itr=res.begin();itr!=res.end();itr++)
		{
			cout<<'('<<(*itr)<<')';
		}
		cout<<endl;
	}
	return 0;
}

dictionary: {i, hello, mango, man, how, ice, cream, like, cell}
string: "icelikemango"
Output: Yes
The string can be segmented as "ice like mango".

56)Combination sum-1
---------------------------------------------------
Based on Author's point of view:
I think the time complexity of this is O(#candidates^target) because the height of the tree would be target and degree of each node would be number of candidates. Space complexity is O(target).

A more accurately expression may be O(#candidates^(target/min of candidates))

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

Note:
    *)All numbers (including target) will be positive integers.
    *)The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

57)Combination sum-2
--------------------------------------------------------
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]


*/

class Solution {
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum2(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i)
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combination.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
    }
};

58)Palindrome Partioning
----------------------------------------------------
TC:O(n*2^n)	SC:O(n) /*length of the string*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

Input:"nitin"
output:
n i t i n
n iti n
nitin

59)Subset Sum-1
-----------------------------------
TC:O(2*2^n) /*n is length of string*/

/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = index; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            subsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};


60)Subset Sum-2
--------------------------------------------
TC:O(2*2^n) /*n is length of string*/

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = index; i < nums.size(); i++) {
            if(i==index||nums[i-1]!=nums[i]){
            sub.push_back(nums[i]);
            subsets(nums, i + 1, sub, subs);
            sub.pop_back();}
        }
    }
};

61)K-th permutation Sequence
----------------------------------------------
TC:O(n)  	SC:O(n) /*for factorial*/
The set [1,2,3,...,n] contains a total of n! unique permutations.

/*By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note:

    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.

Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"*/



class Solution {
public:
    // Our recursive function that will complete the ans string.
	// v - is our current array = [1,2,3,4]
	// ans is the answer string, n and k are current values of n and k
	// factVal is an array containing the factorial of all integers from 0-9 to get factorial in O(1) time.
	// That means I have stored all the factorials in this array before hand to avoid calculation. You can also write factorial funciton if you want.
	
    void setPerm(vector<int>& v,string& ans,int n,int k,vector<int>& factVal){
       // if there is only one element left append it to our ans (Base case)
	   if(n==1){
            ans+=to_string(v.back());
            return;
        }
		
		// We are calculating the required index.  factVal[n-1] means for n =  4 => factVal[3] = 6.
        // 15 / 6 = 2 will the index for k =15 and n = 4.
		int index = (k/factVal[n-1]);
        // if k is a multiple of elements of partition then decrement the index (Corner case I was talking about)
		if(k % factVal[n-1] == 0){
            index--;
        }
		
		ans+= to_string(v[index]);  // add value to string
        v.erase(v.begin() + index);  // remove element from array
        k -= factVal[n-1] * index;   // adjust value of k; k = 15 - 6*2 = 3.
		// Recursive call with n=n-1 as one element is added we need remaing.
        setPerm(v,ans,n-1,k,factVal);
    }
    
    string getPermutation(int n, int k) {
        if(n==1) return "1";
		//Factorials of 0-9 stored in the array. factVal[3] = 6. (3! = 6)
        vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        /*
        or
         //Store all factorials from 0 to N
        fact.push_back(1);
        int f=1;
        for(int i=1;i<n;++i)
        {
            f*=i;
            fact.push_back(f);
        }
        */
        for(int i=1;i<=n;i++){
            factVal[i]=factVal[i-1]*i;
        }
        string ans = "";
        vector<int> v;
		// Fill the array with all elements
        for(int i=1;i<=n;i++) v.emplace_back(i);
        setPerm(v,ans,n,k,factVal);
        return ans;
    }
};


62)1. 1/N-th root of an integer (use binary search) (square root, cube root, ..)
--------------------------------------------------------------------
TC:O(logn)	SC:O(1)

/*floor result*/

// A C++ program to find floor(sqrt(x)
#include<bits/stdc++.h>
using namespace std;

// Returns floor of square root of x
int floorroot(int x, int p)
{
	// Base cases
	if (x == 0 || x == 1)
		return x;

	// Do Binary Search for floor(sqrt(x))
	int start = 1, end = x, ans;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		// If x is a perfect square
		if (pow(mid, p) == x)
			return mid;

		// Since we need floor, we update answer when mid*mid is
		// smaller than x, and move closer to sqrt(x)
		if (pow(mid, p) < x)
		{
			start = mid + 1;
			ans = mid;
		}
		else // If mid*mid is greater than x
			end = mid - 1;
	}
	return ans;
}

// Driver program
int main()
{
	int x ;
	//Enter the integer
	cin >> x;
	int p = 0;
	cin >> p;
	cout << floorroot(x, p) << endl;
	return 0;
}


..................................................


/*accurate result*/
// C++ program to find cubic root of a number
// using Binary Search
#include <bits/stdc++.h>
using namespace std;

// Returns the absolute value of n-mid*mid*mid
double diff(double n, double mid, int p)
{
	if (n > (pow(mid, p)))
		return (n - pow(mid, p));
	else
		return (pow(mid, p) - n);
}

// Returns cube root of a no n
double Root(double n, int p)
{
	// Set start and end for binary search
	double start = 0, end = n;

	// Set precision
	double e = 0.0000001;

	while (true)
	{
		double mid = (start + end) / 2;
		double error = diff(n, mid, p);

		// If error is less than e then mid is
		// our answer so return mid
		if (error <= e)
			return mid;

		// If mid*mid*mid is greater than n set
		// end = mid
		if ((pow(mid, p)) > n)
			end = mid;

		// If mid*mid*mid is less than n set
		// start = mid
		else
			start = mid;
	}
}

// Driver code
int main()
{
	double n;
	//cout << "Enter the integer";
	cin >> n;
	int p = 0;
	//cout << "Enter the 1/Nth root of the integer";
	cin >> p;
	printf("%d root of %lf is %lf\n", p,
	       n, Root(n, p));
	return 0;
}

63)Matrix Median
------------------------------------------------
TC:O(32*r*log(c))	SC:O(1)

// C++ program to find median of a matrix 
// sorted row wise 
#include<bits/stdc++.h> 
using namespace std; 

const int MAX = 100; 

// function to find median in the matrix 
int binaryMedian(int m[][MAX], int r ,int c) 
{ 
	int min = INT_MAX, max = INT_MIN; 
	for (int i=0; i<r; i++) 
	{ 
		// Finding the minimum element 
		if (m[i][0] < min) 
			min = m[i][0]; 

		// Finding the maximum element 
		if (m[i][c-1] > max) 
			max = m[i][c-1]; 
	} 

	int desired = (r * c + 1) / 2; 
	while (min < max) 
	{ 
		int mid = min + (max - min) / 2; 
		int place = 0; 

		// Find count of elements smaller than mid 
		for (int i = 0; i < r; ++i) 
			place += upper_bound(m[i], m[i]+c, mid) - m[i]; 
		if (place < desired) 
			min = mid + 1; 
		else
			max = mid; 
	} 
	return min; 
} 

// driver program to check above functions 
int main() 
{ 
	int r = 3, c = 3; 
	int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} }; 
	cout << "Median is " << binaryMedian(m, r, c) << endl; 
	return 0; 
}
 
Output:
Median is 5

64)Find the element that appears once in sorted array, and rest element appears twice(Binary search)
-------------------------------------------------------------------------------------
TC:O(logn)	SC:O(1)

#include <vector>
#include <iostream>
using namespace std;

int appears_once(const vector<int> &ar, int lo, int hi)  {  // variant of binary search
    if(lo > hi) return ar[lo];  // Base Case
    
    int mid = lo+(hi-lo)/2; // for a cosistently lower mid
    
    // if mid is 0 or mid is the last element in the array
    if((mid == 0 && ar[mid] != ar[mid+1]) || (mid == ar.size()-1 && ar[mid] != ar[mid-1]))
        return ar[mid];
    else    // if mid is anything other than 0th element or last element
        if(!(mid&1))    // even mid
            if(ar[mid] == ar[mid+1])
                return appears_once(ar, mid+2, hi);
            else return appears_once(ar, lo, mid-2);
        else            // odd mid
            if(ar[mid] == ar[mid-1])
                return appears_once(ar, mid+1, hi);
            else return appears_once(ar, lo, mid-1);
}

int main() {
	int t;  cin >> t;
	while(t--) {
	    int n;  cin >> n;
	    vector<int> ar(n);
	    for(int i = 0; i < n; ++i)
	        cin >> ar[i];
	        
	    cout << appears_once(ar, 0, ar.size()-1) << endl;
	}
	return 0;
}

output:
11
1 1 2 2 3 3 4 50 50 65 65
Output:
4

65)Search element in a sorted and rotated array.
----------------------------------------------
TC:O(logn)	SC:O(1)

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


*/

/* Doing binary search to find the pivot node and doing binary search for finding givrn element*/
/* C++ Program to search an element 
in a sorted and pivoted array*/
#include <bits/stdc++.h> 
using namespace std; 

/* Standard Binary Search function*/
int binarySearch(int arr[], int low, 
				int high, int key) 
{ 
if (high < low) 
	return -1; 
	
int mid = (low + high)/2; /*low + (high - low)/2;*/
if (key == arr[mid]) 
	return mid; 
	
if (key > arr[mid]) 
	return binarySearch(arr, (mid + 1), high, key); 
	
// else 
	return binarySearch(arr, low, (mid -1), key); 
} 

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 
it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high) 
{ 
// base cases 
if (high < low) return -1; 
if (high == low) return low; 

int mid = (low + high)/2; /*low + (high - low)/2;*/
if (mid < high && arr[mid] > arr[mid + 1]) 
	return mid; 
	
if (mid > low && arr[mid] < arr[mid - 1]) 
	return (mid-1); 
	
if (arr[low] >= arr[mid]) 
	return findPivot(arr, low, mid-1); 
	
return findPivot(arr, mid + 1, high); 
} 

/* Searches an element key in a pivoted 
sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key) 
{ 
int pivot = findPivot(arr, 0, n-1); 

// If we didn't find a pivot, 
// then array is not rotated at all 
if (pivot == -1) 
	return binarySearch(arr, 0, n-1, key); 

// If we found a pivot, then first compare with pivot 
// and then search in two subarrays around pivot 
if (arr[pivot] == key) 
	return pivot; 
	
if (arr[0] <= key) 
	return binarySearch(arr, 0, pivot-1, key); 
	
	return binarySearch(arr, pivot+1, n-1, key); 
} 

/* Driver program to check above functions */
int main() 
{ 
// Let us search 3 in below array 
int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
int n = sizeof(arr1)/sizeof(arr1[0]); 
int key = 3; 
	
// Function calling 
cout << "Index of the element is : " << 
		pivotedBinarySearch(arr1, n, key); 
			
return 0; 
} 

------------------------------------------------
/*Doing binary search single time to find the given element*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]) return mid; //Case 1: Found X,Yeah
            if(nums[mid]<=nums[high])//Case 2:Right half is sorted
            {
                if(target>nums[mid]&& target<=nums[high]){
                    low=mid+1;//Go searching in right sorted half
                }else{
                    high=mid-1;//go searching left
                }
            }else{  //Case 3: Left half is sorted
                if(nums[low]<=target && target<nums[mid] ){ //Go searching in left sorted half
                    high=mid-1;
                }else{
                    low=mid+1; //go searching right sorted half
                }
            }
        }
        cout<<high;
        return -1;
    }
};

66)K-th element of two sorted arrays
-------------------------------------------
TC:O(logk)	SC:O(1)
/*
Explanation:
arr1[5] = {2, 3, 5, 7, 9};
arr2[4] = {1, 4, 8, 10};

Instead of comparing the middle element of the arrays,
we compare the k / 2nd element.
Let arr1 and arr2 be the arrays.
Now, if arr1[k / 2]  arr1[1]

New subproblem:
Array 1 - 6 7 9
Array 2 - 1 4 8 10
k = 5 - 2 = 3

floor(k / 2) = 1
arr1[1] = 6
arr2[1] = 1
arr1[1] > arr2[1]

New subproblem:
Array 1 - 6 7 9
Array 2 - 4 8 10
k = 3 - 1 = 2

floor(k / 2) = 1
arr1[1] = 6
arr2[1] = 4
arr1[1] > arr2[1]

New subproblem:
Array 1 - 6 7 9
Array 2 - 8 10
k = 2 - 1 = 1

Now, we directly compare first elements,
since k = 1. 
arr1[1] < arr2[1]
Hence, arr1[1] = 6 is the answer.


*/
// C++ Program to find kth element from two sorted arrays 
// Time Complexity: O(log k) 

#include <iostream> 
using namespace std; 

int kth(int arr1[], int m, int arr2[], int n, int k) 
{ 
	
if (k > (m+n) || k < 1) return -1; 
	
// let m <= n 
if (m > n) return kth(arr2, n, arr1, m, k); 
	
// if arr1 is empty returning k-th element of arr2 
if (m == 0) return arr2[k - 1]; 
	
// if k = 1 return minimum of first two elements of both arrays 
if (k == 1) return min(arr1[0], arr2[0]); 
	
// now the divide and conquer part 
int i = min(m, k / 2), j = min(n, k / 2); 
	
if (arr1[i - 1] > arr2[j - 1] ) 
	// Now we need to find only k-j th element since we have found out the lowest j 
	return kth(arr1, m, arr2 + j, n - j, k - j); 
else
	// Now we need to find only k-i th element since we have found out the lowest i 
	return kth(arr1 + i, m - i, arr2, n, k - i); 
} 

// Driver code 
int main() 
{ 
	int arr1[5] = {2, 3, 6, 7, 9}; 
	int arr2[4] = {1, 4, 8, 10}; 
	int m = sizeof(arr1)/sizeof(arr1[0]); 
	int n = sizeof(arr2)/sizeof(arr2[0]); 
	int k = 5; 
	
	int ans = kth(arr1,m,arr2, n, k); 
	
	if(ans == -1) cout<<"Invalid query"; 
	else cout<<ans; 
	
	return 0; 
}
output:6 
/*
Input : Array 1 - 2 3 6 7 9
        Array 2 - 1 4 8 10
        k = 5
Output : 6
Explanation: The final sorted array would be -
1, 2, 3, 4, 6, 7, 8, 9, 10
The 5th element of this array is 6
*/ 


67)Median of two sorted array
-------------------------------------------
TC:O(log(min(m,n))	SC:O(1)

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

 double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        if (a1.size() > a2.size()) swap(a1, a2); // make sure a1 is shorter
        
        int n1 = a1.size(), n2 = a2.size();
        
        // range of a1 cut location: n1 means no right half for a1
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int cut1 = (lo + hi)/2; // cut location is counted to right half
            int cut2 = (n1 + n2)/2 - cut1;
            
            int maxLeftX = cut1 == 0? INT_MIN : a1[cut1-1];//Get l1,l2,r1,r2 respectively
            int maxLeftY = cut2 == 0? INT_MIN : a2[cut2-1];
            int minRightX = cut1 == n1? INT_MAX : a1[cut1];
            int minRightY = cut2 == n2? INT_MAX : a2[cut2];
            
            if (maxLeftX > minRightY) hi = cut1-1;
            else if (maxLeftY > minRightX) lo = cut1+1;
            else return (n1+n2)%2? min(minRightX,minRightY) : (max(maxLeftX,maxLeftY) + min(minRightX,minRightY))/2.;
        }
            return -1;
   }

reference: https://www.youtube.com/watch?v=LPFhl65R7ww

Bits - https://www.hackerearth.com/practice/notes/bit-manipulation/
==========================================================
68)Check if a number if a power of 2 or not in O(1)

#include <bits/stdc++.h> 
using namespace std; 
#define bool int 

/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x) 
{ 
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x&(x-1))); //for example 8=1000 and 8-1 =>7=0111	and we also eed to avoid "0" as input
} 

/*Driver code*/
int main() 
{ 
	isPowerOfTwo(31)? cout<<"Yes\n": cout<<"No\n"; 
	isPowerOfTwo(64)? cout<<"Yes\n": cout<<"No\n"; 
	return 0; 
} 

/*Using log*/
// C++ Program to find whether a 
// no is power of two 
#include<bits/stdc++.h> 
using namespace std; 

// Function to check if x is power of 2 
bool isPowerOfTwo(int n) 
{ 
if(n==0) 
return false; 

return (ceil(log2(n)) == floor(log2(n))); 
} 

// Driver program 
int main() 
{ 
	isPowerOfTwo(31)? cout<<"Yes"<<endl: cout<<"No"<<endl; 
	isPowerOfTwo(64)? cout<<"Yes"<<endl: cout<<"No"<<endl; 

	return 0; 
} 
-----------------------------------------------------------------------
69)Count total set bits
TC:O(n)		SC:O(n)

class Solution {
public:
    vector<int> countBits(int num) {
        //mem[i] = No of 1s from 0 to number i
        vector<int> mem(num+1);
        mem[0] = 0;
        
        for(int i=1;i<=num;++i)
            mem[i] = mem[i/2] + i%2;
        
        return mem;
    }
};

/*
Input: 2
Output: [0,1,1]

Input: 5
Output: [0,1,1,2,1,2]

*/
-------------------------------------------------------
70)Divide Integers without / operator

TC:O(log(n^2))		SC:O(1)
/*TIME COMPLEXITY EXPLANATION
Good question. I hadn't thought of that till now. But let me try to deduce how lee215's solution has a O (log (n^2)) time complexity.
Let's say for example, we had an array of length n.
A doubly nested for loop that looks like the following would have a time complexity of O(n^2):


for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
       //...
    }

}


Similarly, the code I'm running is doing the following:
Let's say a is 100, b is 2,4,8,16,32,64, stopping before 100.
while( a - (b << 1 << x) >= 0){
    x++;
}
In our code, b is like the j pointer, a is like the i pointer.
Then a is decremented because of this line
a -= b << x;
so a would be readjusted to 36 ( 100 - 64 ). b starts again from 2. So b loops from 2,4,8,16,32, stopping before 36.


So you can deduce by analogy the n^2 where n would be dividend. The reason log comes into this is because we are squaring b at each step. The log is a logarithm of base 2.

*/

 int divide(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        long int a = abs(A), b = abs(B), res = 0, x = 0;
        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            res += 1 << x;
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }

ref:https://www.youtube.com/watch?v=htX69j1jf5U

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.


Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.

----------------------------------------------------------
71)Power Set
TC:O(n*2^n)	SC:O(1)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;//for n size of input subset always will be 2^n(1<<n is same as 2^n)
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};

/*
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
ref:https://www.youtube.com/watch?v=MsHFNGltIxw
--------------------------------------------------------------
72)Find MSB in o(1)      -https://www.hackerearth.com/practice/notes/bit-manipulation/

TC:O(1)		SC:O(1)

long largest_power(long N)
{
    //changing all right side bits to 1.
    N = N| (N>>1);
    N = N| (N>>2);
    N = N| (N>>4);
    N = N| (N>>8);


//as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by
 2. 
            return (N+1)>>1;

}

Input : 10
Output : 8
Binary representation of 10 is 1010
The most significant bit corresponds
to decimal number 8.

Input : 18
Output : 16

------------------------------------------------------------
73)Find square of a number without using multiplication or division operators.
TC:O(logn)	SC:O(1)
/*
EXPLANATION:
 square(n) = 0 if n == 0
  if n is even 
     square(n) = 4*square(n/2) 
  if n is odd
     square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

Examples
  square(6) = 4*square(3)
  square(3) = 4*(square(1)) + 4*1 + 1 = 9
  square(7) = 4*square(3) + 4*3 + 1 = 4*9 + 4*3 + 1 = 49

How does this work?

If n is even, it can be written as
  n = 2*x 
  n2 = (2*x)2 = 4*x2
If n is odd, it can be written as 
  n = 2*x + 1
  n2 = (2*x + 1)2 = 4*x2 + 4*x + 1
*/
int square(int n) 
{ 
    // Base case 
    if (n==0) return 0; 
  
    // Handle negative number 
    if (n < 0) n = -n; 
  
    // Get floor(n/2) using right shift 
    int x = n>>1; 
  
    // If n is odd 
    if (n&1) 
        return ((square(x)<<2) + (x<<2) + 1); 
    else // If n is even 
        return (square(x)<<2); 
} 

Input:5
Output:25

Input:6
Output:36

STACK AND QUEUE:
=================================================================

74)Implementing Stack:

Array:
/* C++ program to implement basic stack 
operations */
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1000 
class Stack { 
	int top; 
public: 
	int a[MAX]; // Maximum size of Stack 
	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peek(); 
	bool isEmpty(); 
}; 
bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 
int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[top]; 
		return x; 
	} 
} 
bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	class Stack s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	cout << s.pop() << " Popped from stack\n"; 

	return 0; 
} 

//Linked List

// C++ program for linked list implementation of stack 
#include <bits/stdc++.h> 
using namespace std; 
// A structure to represent a stack 
class StackNode { 
public: 
	int data; 
	StackNode* next; 
}; 
StackNode* newNode(int data) 
{ 
	StackNode* stackNode = new StackNode(); 
	stackNode->data = data; 
	stackNode->next = NULL; 
	return stackNode; 
} 
int isEmpty(StackNode* root) 
{ 
	return !root; 
} 
void push(StackNode** root, int data) 
{ 
	StackNode* stackNode = newNode(data); 
	stackNode->next = *root; 
	*root = stackNode; 
	cout << data << " pushed to stack\n"; 
} 
int pop(StackNode** root) 
{ 
	if (isEmpty(*root)) 
		return INT_MIN; 
	StackNode* temp = *root; 
	*root = (*root)->next; 
	int popped = temp->data; 
	free(temp); 

	return popped; 
} 
int peek(StackNode* root) 
{ 
	if (isEmpty(root)) 
		return INT_MIN; 
	return root->data; 
} 
int main() 
{ 
	StackNode* root = NULL; 

	push(&root, 10); 
	push(&root, 20); 
	push(&root, 30); 

	cout << pop(&root) << " popped from stack\n"; 

	cout << "Top element is " << peek(root) << endl; 

	return 0; 
} 

//Queue implementation using arrays - TC: enqueue=O(1)	Dequeue=O(n)

/* C++ program to implement basic stack 
operations */
#include <bits/stdc++.h> 

using namespace std; 

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peek(); 
	bool isEmpty(); 
}; 

bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[top]; 
		return x; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	class Stack s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	cout << s.pop() << " Popped from stack\n"; 

	return 0; 
} 

//Linked List implementation of queue -TC: enqueue=O(1)	Dequeue=O(1)
#include <bits/stdc++.h> 
using namespace std; 

struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		// Create a new LL node 
		QNode* temp = new QNode(x); 

		// If queue is empty, then 
		// new node is front and rear both 
		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		// Add the new node at 
		// the end of queue and change rear 
		rear->next = temp; 
		rear = temp; 
	} 

	// Function to remove 
	// a key from given queue q 
	void deQueue() 
	{ 
		// If queue is empty, return NULL. 
		if (front == NULL) 
			return; 

		// Store previous front and 
		// move front one node ahead 
		QNode* temp = front; 
		front = front->next; 

		// If front becomes NULL, then 
		// change rear also as NULL 
		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
}; 

// Driven Program 
int main() 
{ 

	Queue q; 
	q.enQueue(10); 
	q.enQueue(20); 
	q.deQueue(); 
	q.deQueue(); 
	q.enQueue(30); 
	q.enQueue(40); 
	q.enQueue(50); 
	q.deQueue(); 
	cout << "Queue Front : " << (q.front)->data << endl; 
	cout << "Queue Rear : " << (q.rear)->data; 
} 
d
75)BFS using queue
--------------------------------------------
TC:O(V+E) V is Vertices and E is Edges

void bfs(int s,vector<int> adj[],bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto i:adj[node])//checking for all the adjacent vertices for that vertex
	    {
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
}

76)Implement Stack using Queue
--------------------------------------------
TC:
for Push operation is o(1)
for pop operation is O(n)

void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code       
        
        if(q1.empty()){
            return -1;
        }
        else{
            
            // Transfer from q1 to q2 till only 1 element left
            while(q1.size()!=1){
                int ele=q1.front();
                q1.pop();
                q2.push(ele);
            }
            // Last element left is to be popped
            int elementDeleted=q1.front();
            q1.pop();
            
            // Swap q1 and q2
            swap(q1,q2);
            
            return elementDeleted;
            
        }
}

77)Implement Queue using Stack
---------------------------------------------------
TC:
for enqueue operation is o(1)
for dequque operation is O(n)

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        if(s1.empty()) return -1;

        //shifting the elements from s1 to s2 , until only one element is left
        while(s1.size()!=1){
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }

        //the last element in s1
        int x = s1.top();
        s1.pop();

        //shifting back the elements from s2 to s1
        while(!s2.empty()){
            int z = s2.top();
            s2.pop();
            s1.push(z);
        }

        //returning the last element
        return x ;
}


78)Check for balanced parentheses
---------------------------------------------------
TC:O(n)		SC:O(n)

bool isValid(string s) {
    stack<char> st;
    for(char c : s){
        if(c == '('|| c == '{' || c == '['){
            st.push(c);
        }else{
            if(st.empty()) return false;
            if(c == ')' && st.top() != '(') return false;
            if(c == '}' && st.top() != '{') return false;
            if(c == ']' && st.top() != '[') return false;
            st.pop();
        }
    }
return st.empty();
}

Input: "()"
Output: true


Input: "()[]{}"
Output: true


Input: "(]"
Output: false

Input: "([)]"
Output: false

Input: "{[]}"
Output: true

80)Next Greater Element
---------------------------------------
TC:O(n)		SC:O(n)

int main() {
	int t;
	cin >> t;
	while (t--) {
		long int n;
		cin >> n;
		vector<long int> v(n);
		for (long int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long int> ans(n);
		stack<long int> s;
		// Push 1st element (index of 1st element to stack)
		s.push(0);
		long int cur;
		for (long int i = 1; i < n; i++) {
			cur = v[i];
			// See if current element can be next larger element for any element in stack
			while (!s.empty() && cur > v[s.top()]) {

				// Found next larger element for s.top
				ans[s.top()] = cur;
				// Pop from stack
				s.pop();
			}
			// Now push current element index to stack
			s.push(i);
		}
		// For remaining elements in stack ans is -1
		while (!s.empty()) {

			ans[s.top()] = -1;
			s.pop();
		}
		// Print the ans
		for (long int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

Input:
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

81)Next smaller element
-----------------------------------
TC:O(n)		SC:O(n)

void printNSE(int arr[], int n) 
{ 
    stack<int> s; 
    unordered_map<int, int> mp; 
    /* push the first element to stack */
    s.push(arr[0]); 
    // iterate for rest of the elements 
    for (int i = 1; i < n; i++) { 
  
        if (s.empty()) { 
            s.push(arr[i]); 
            continue; 
        }  
        /* if stack is not empty, then 
       pop an element from stack. 
       If the popped element is smaller 
       than next, then 
    a) print the pair 
    b) keep popping while elements are 
    smaller and stack is not empty */
        while (s.empty() == false && s.top() > arr[i]) { 
            mp[s.top()] = arr[i]; 
            s.pop(); 
        }   
        /* push next to stack so that we can find 
    next smaller for it */
        s.push(arr[i]); 
    } 
    /* After iterating over the loop, the remaining 
  elements in stack do not have the next smaller 
  element, so print -1 for them */
    while (s.empty() == false) { 
         mp[s.top()] = -1; 
        s.pop(); 
    } 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " ---> " << mp[arr[i]] << endl; 
} 

Input:
11, 13, 21, 3

Output:
3, 3, 3, -1

82)LRU cache
-----------------------------------------
TC:O(1)
//DATA STRUCTURE USED
// doubly linked list in which every node is  pair of key,value.
// Hash_map which takes key as "key" and value as "iterator of node" of dll 

//TIME COMPLEXITY
// we want "searching" of pair  - O(1) complexity
// we need "deletion" of pair (either from somewhere middle or back of dll)  - O(1) comlexity
// we need "insertion" of pair (at front of dll) - O(1) complexity
int maxSize;
list<pair<int,int>> dll;  
unordered_map<int, list<pair<int,int>> :: iterator> ma;

LRUCache::LRUCache(int N)
{
    maxSize = N;
    dll.clear();
    ma.clear();
}

void LRUCache::set(int x, int y) 
{
    //Here  least recently used eleemnts are present at the back of the dll
    auto it = ma.find(x);
     if(it == ma.end()) // given pair is not present 
    {
       if(dll.size() == maxSize)  // size is full
       {
           // delete Lest Recently used element(back) from dll and remove entry hash table;
           auto L_key = dll.back().first;
           dll.pop_back();
           ma.erase(L_key);
       }
    }
    else // existing pair
    {   
        //delete existing pair from dll and remove entry hash table;
        dll.erase(it->second);
        ma.erase(x);
    }
    
    //Finally add the given pair  to front of dll and update the same in hash table
    dll.push_front({x,y});
    ma[x]=dll.begin();
}
int LRUCache::get(int x)
{
    if(ma.find(x) == ma.end()) // not present
    {
        return -1;
    }
    // existing pair - delete current pair and bring it to front of DLL and update same in hash tabe
    auto it = ma.find(x);
    int d  = (*(it->second)).second;
    dll.erase(it->second);
    dll.push_front({x,d});
    ma[x] = dll.begin();
    return d;
}

83)Largest rectangle in histogram
--------------------------------------------
TC:O(n) //worst case o(2n)

int getMaxArea(int hist[], int n) 
{ 
	// Create an empty stack. The stack holds indexes 
	// of hist[] array. The bars stored in stack are 
	// always in increasing order of their heights. 
	stack<int> s; 

	int max_area = 0; // Initialize max area 
	int tp; // To store top of stack 
	int area_with_top; // To store area with top bar 
					// as the smallest bar 

	// Run through all bars of given histogram 
	int i = 0; 
	while (i < n) 
	{ 
		// If this bar is higher than the bar on top 
		// stack, push it to stack 
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 

		// If this bar is lower than top of stack, 
		// then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index' 
		else
		{ 
			tp = s.top(); // store the top index 
			s.pop(); // pop the top 

			// Calculate the area with hist[tp] stack 
			// as smallest bar 
			area_with_top = hist[tp] * (s.empty() ? i : 
								i - s.top() - 1); 

			// update max area, if needed 
			if (max_area < area_with_top) 
				max_area = area_with_top; 
		} 
	} 

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false) 
	{ 
		tp = s.top(); 
		s.pop(); 
		area_with_top = hist[tp] * (s.empty() ? i : 
								i - s.top() - 1); 

		if (max_area < area_with_top) 
			max_area = area_with_top; 
	} 

	return max_area; 
} 

Input: [2,1,5,6,2,3]
Output: 10

Ref:https://youtu.be/RVIh0snn4Qc

84)Sliding Window Maximum
-----------------------------------------------------
TC:O(n)		SC:O(k)//k is capacity of the window


void printKMax(int arr[], int n, int k) 
{ 
	// Create a Double Ended Queue, Qi that will store indexes of array elements 
	// The queue will store indexes of useful elements in every window and it will 
	// maintain decreasing order of values from front to rear in Qi, i.e., 
	// arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
	std::deque<int> Qi(k); 

	/* Process first k (or first window) elements of array */
	int i; 
	for (i = 0; i < k; ++i) { 
		// For every element, the previous smaller elements are useless so 
		// remove them from Qi 
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
			Qi.pop_back(); // Remove from rear 

		// Add new element at rear of queue 
		Qi.push_back(i); 
	} 

	// Process rest of the elements, i.e., from arr[k] to arr[n-1] 
	for (; i < n; ++i) { 
		// The element at the front of the queue is the largest element of 
		// previous window, so print it 
		cout << arr[Qi.front()] << " "; 

		// Remove the elements which are out of this window 
		while ((!Qi.empty()) && Qi.front() <= i - k) 
			Qi.pop_front(); // Remove from front of queue 

		// Remove all elements smaller than the currently 
		// being added element (remove useless elements) 
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()]) 
			Qi.pop_back(); 

		// Add current element at the rear of Qi 
		Qi.push_back(i); 
	} 

	// Print the maximum element of last window 
	cout << arr[Qi.front()]; 
} 

/*First for loop can be avoided... by checking i>=k-1 before adding into the result vector or printing the answer*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> buffer;
        vector<int> res;

        for(auto i=0; i<nums.size();++i)
        {
            while(!buffer.empty() && nums[i]>=nums[buffer.back()]) buffer.pop_back();
            buffer.push_back(i);

            if(i>=k-1) res.push_back(nums[buffer.front()]);
            if(buffer.front()<= i-k + 1) buffer.pop_front();
        }
        return res;
    }

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 

85)Implement Min Stack
---------------------------------------------
TC:O(1)

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

86)Rotten Orange using (BFS)
------------------------------------------------
TC:O(r*c)	SC:(r*c)

int orangesRotting(vector<vector<int>>& grid) {
    //number of valid cells (cells with some orange)
    int ct = 0;
    //result
    int res = -1;
    //actually queue of pairs of coord i and j
    queue<vector<int>> q;
    
    //ways to move
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    //create staring nodes to queue to do bfs
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            //increasing number of valid cells
            if(grid[i][j] > 0) 
                ct++;
            
            //only rotten oranges must be on initial step of queue
            if(grid[i][j] == 2) 
                q.push({i, j});
        }
    }
    
    //bfs
    while(!q.empty()) {
        
        //we do one step from rotten
        res++;
        
        //see next comment
        int size = q.size();
        
        //need to start from all rotten nodes at one moment 
        for(int k = 0; k < size; k++) {
            
            //take node from head
            vector<int> cur = q.front();
            q.pop();
            
            //number of valid decreasing
            ct--;
            
            //need to look through all four directions
            for(int i = 0; i < 4; i++) {
                //taking coords
                int x = cur[0] + dir[i][0];
                int y = cur[1] + dir[i][1];
                
                //if we go out of border or find non-fresh orange, we skip this iteration
                if(x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] != 1) 
                    continue;
                
                //orange becomes rotten
                grid[x][y] = 2;
                
                //this orange will make neighbor orange rotten
                q.push({x, y});
            }
        }
    }
    //if we looked through all oranges, return result, else -1
    return (ct == 0) ? max(0, res) : -1;
}

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1

Strings
========================================================
87)Reverse Words in a String

TC:O(n)		SC:O(1)


class Solution {
public:
    string reverseWords(string  s) {
        int i, len, start, end;
        // remove leading spaces
        for (i = 0; i < s.size() && ' ' == s[i]; i++)
            ;
        start = i;
        // remove trailing spaces
        for (i = s.size() - 1; i >= 0 && ' ' == s[i]; i--)
            ;
        end = i;
        // remove multiple spaces btw. words
        for (i = start, len = 0; i <= end; i++) {
            if (' ' == s[i] && ' ' == s[i - 1])
                continue;
            s[len++] = s[i];
        }
        s.erase(s.begin() + len, s.end());

        reverse(s.begin(), s.end());
        for (i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        // last word
        reverse(s.begin() + start, s.end());
        return s;
    }
};

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

88)Longest Palindrome in a string
-------------------------------------------------------------
TC:O(n^2)	SC:O(n^2)

//java solution be careful
class Solution {
    public String longestPalindrome(String s) {
        if (s.length() <= 1)
            return s;
        
        boolean[][] dp = new boolean[s.length()][s.length()];
        
        for (int i = 0; i < s.length(); i++)
            dp[i][i] = true;
        
        int longestPalindromeStart = 0, longestPalindromeLength = 1;
        for (int start = s.length() - 1; start >= 0; start--) {
            for (int end = start + 1; end < s.length(); end++) {
                if (s.charAt(start) == s.charAt(end)) {
                    if (end - start == 1 || dp[start + 1][end - 1]) {
                        dp[start][end] = true;
                        if (longestPalindromeLength < end - start + 1) {
                            longestPalindromeStart = start;
                            longestPalindromeLength = end - start + 1;
                        }
                    }
                }

            }
        }
        
        return s.substring(longestPalindromeStart, longestPalindromeStart + longestPalindromeLength);
    }
}

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

89)Roman Number to Integer and vice versa
---------------------------------------------------

Integer to roman:
TC:O(n)		SC:O(1)//constant space
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
*/
...........................................................

class Solution {
public:
    string intToRoman(int num) 
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }
        
        return res;
    }
};
Example 1:

Input: 3
Output: "III"

Example 2:

Input: 4
Output: "IV"

Example 3:

Input: 9
Output: "IX"


Roman to Integer:
/*
Time complexity: O(n).
Space complexity: O(1).
Time and Space complexity

    We are iterating each letter of the given string, so Time complexity is O(n) where n is the length of the string.
    We are using constant space, so Space complexity is O(1).
*/
..............................................................

int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
}

Example 1:

Input: "III"
Output: 3

Example 2:

Input: "IV"
Output: 4

90)String to Integer (atoi)
------------------------------------------------------
TC:O(n)		SC:O(1)

atoi
/*
1. check NULL

2. skip leading space

3. handle negative sign '-'

4. handle optional positive sign '+'

5. handle non-digit character

6. handle overflow

7. handle underflow

*/

 int myAtoi(string str) {
        long long int res = 0;
        string trim = str;
        bool sign = false;
        
        while(trim[0] == ' ')
            trim.erase(trim.begin());
        
        if(trim[0] == '-' || trim[0] == '+')
        {
            if(trim[0] == '-')
                sign = true;
            trim.erase(trim.begin());
        }
        
        for(char ch : trim)
        {
            if(!(ch >= '0' && ch <= '9'))
                break;
            
            res = res*10 + (ch-'0');
            if(res > INT_MAX)
                return (sign ? INT_MIN : INT_MAX);
        }
        
        if(sign)
            res = -1*res;
        return res;
    }

/*
Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
*/

..........................................................
Implement Strstr//Using two pointer algo
TC:O(m*n) //m is the original string and n is the substring to be found
SC:O(1)


class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
	if(m==0){return 0;}
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/
91)Longest Common Prefix
--------------------------------------
TC:O(n*m)	SC:O(m)//to store the prefix result

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(prefix)!=0)//str.find(prefix) returns the starting index of str if prefix is found in string str
 	    {
                prefix=prefix.substr(0,prefix.size()-1);//chop off the last letter in the string
            }
        }
        return prefix;
        
    }
};

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

91)Rabin-Karp//rolling hash function
------------------------------------------------------------------
TC:(n+m)

drawback:Spurious Hits(hash function matches but pattern doesn't) /*TC:O(nm)*/
This drawback can be overcome by using strong hash function

/* Following program is a C++ implementation of Rabin Karp 
Algorithm given in the CLRS book */
#include <bits/stdc++.h> 
using namespace std; 

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
void search(char pat[], char txt[], int q) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 
	int i, j; 
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M - 1; i++) 
		h = (h * d) % q; 

	// Calculate the hash value of pattern and first 
	// window of text 
	for (i = 0; i < M; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + txt[i]) % q; 
	} 

	// Slide the pattern over text one by one 
	for (i = 0; i <= N - M; i++) 
	{ 

		// Check the hash values of current window of text 
		// and pattern. If the hash values match then only 
		// check for characters on by one 
		if ( p == t ) 
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (txt[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M) 
				cout<<"Pattern found at index "<< i<<endl; 
		} 

		// Calculate hash value for next window of text: Remove 
		// leading digit, add trailing digit 
		if ( i < N-M ) 
		{ 
			t = (d*(t - txt[i]*h) + txt[i+M])%q; 

			// We might get negative value of t, converting it 
			// to positive 
			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 

/* Driver code */
int main() 
{ 
	char txt[] = "GEEKS FOR GEEKS"; 
	char pat[] = "GEEK"; 
	int q = 101; // A prime number 
	search(pat, txt, q); 
	return 0; 
} 

Input:  txt[] = "THIS IS A TEST TEXT"
        pat[] = "TEST"
Output: Pattern found at index 10

Input:  txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"
Output: Pattern found at index 0
        Pattern found at index 9
        Pattern found at index 12

92)Prefix Function/Z-Function
--------------------------------------------------------
TC:O(m+n)	SC:O(m+n)
package com.interview.string;

import java.util.ArrayList;
import java.util.List;

/**
 * Date 10/31/2015
 * @author Tushar Roy
 *
 * Z algorithm to pattern matching
 *
 * Time complexity - O(n + m)
 * Space complexity - O(n + m)
 *
 * http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
 * http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm
 */
public class ZAlgorithm {

    private int[] calculateZ(char input[]) {
        int Z[] = new int[input.length];
        int left = 0;
        int right = 0;
        for(int k = 1; k < input.length; k++) {
            if(k > right) {
                left = right = k;
                while(right < input.length && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                //we are operating inside box
                int k1 = k - left;
                //if value does not stretches till right bound then just copy it.
                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { //otherwise try to see if there are more matches.
                    left = k;
                    while(right < input.length && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }

    /**
     * Returns list of all indices where pattern is found in text.
     */
    public List<Integer> matchPattern(char text[], char pattern[]) {
        char newString[] = new char[text.length + pattern.length + 1];
        int i = 0;
        for(char ch : pattern) {
            newString[i] = ch;
            i++;
        }
        newString[i] = '$';
        i++;
        for(char ch : text) {
            newString[i] = ch;
            i++;
        }
        List<Integer> result = new ArrayList<>();
        int Z[] = calculateZ(newString);

        for(i = 0; i < Z.length ; i++) {
            if(Z[i] == pattern.length) {
                result.add(i - pattern.length - 1);
            }
        }
        return result;
    }

    public static void main(String args[]) {
        String text = "aaabcxyzaaaabczaaczabbaaaaaabc";
        String pattern = "aaabc";
        ZAlgorithm zAlgorithm = new ZAlgorithm();
        List<Integer> result = zAlgorithm.matchPattern(text.toCharArray(), pattern.toCharArray());
        result.forEach(System.out::println);
    }
}

ref:https://www.youtube.com/watch?v=CpZh4eF8QBw

93)KMP algo
----------------------------------------------------
TC:O(n+m)		SC:O(m)//m is pattern and n is the text
// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} 

94)Minimum characters needed to be inserted in the beginning to make it palindromic.
------------------------------------------------
TC:O(n)

// C++ program for getting minimum character to be 
// added at front to make string palindrome 
#include <bits/stdc++.h> 
using namespace std; 

// returns vector lps for given string str 
vector<int> computeLPSArray(string str) 
{ 
	int M = str.length(); 
	vector<int> lps(M); 

	int len = 0; 
	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) 
	{ 
		if (str[i] == str[len]) 
		{ 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (str[i] != str[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) 
			{ 
				len = lps[len-1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
	return lps; 
} 

// Method returns minimum character to be added at 
// front to make string palindrome 
int getMinCharToAddedToMakeStringPalin(string str) 
{ 
	string revStr = str; 
	reverse(revStr.begin(), revStr.end()); 

	// Get concatenation of string, special character 
	// and reverse string 
	string concat = str + "$" + revStr; 

	// Get LPS array of this concatenated string 
	vector<int> lps = computeLPSArray(concat); 

	// By subtracting last entry of lps vector from 
	// string length, we will get our result 
	return (str.length() - lps.back()); 
} 

// Driver program to test above functions 
int main() 
{ 
	string str = "AACECAAAA"; 
	cout << getMinCharToAddedToMakeStringPalin(str); 
	return 0; 
} 

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.

ref:https://www.youtube.com/watch?v=c4akpqTwE5g

95)Check for Anagrams
----------------------------------------------
TC:O(n)		SC:O(number of lowercase alphabets)//if special characters are included the we can use unordered map ,then SC:O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};		

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

96)Count and Say
--------------------------------------
TC:O(n*k)
actually i think it is O(k*n) where k is the length of the previous sequence (different from n^2). Because the length of each string has nothing to do with the total number of strings. The author of cracking the coding interview made this distinction

string countAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (int i = 0; i < res.size(); i++) {
            int count = 1;
             while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                count++;    
                i++;
            }
            cur += to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}

output:
Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".

97)Compare version numbers
--------------------------------------------------
TC:O(num1+num2) 	SC:O(1)

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

int compareVersion(string version1, string version2) {
    int i = 0; 
    int j = 0;
    int n1 = version1.size(); 
    int n2 = version2.size();
    
    int num1 = 0;
    int num2 = 0;
    while(i<n1 || j<n2)
    {
        while(i<n1 && version1[i]!='.'){
            num1 = num1*10+(version1[i]-'0');
            i++;
        }
        cout<<num1<<"\n";
        
        while(j<n2 && version2[j]!='.'){
            num2 = num2*10+(version2[j]-'0');;
            j++;
        }
        cout<<num2<<"\n";
        if(num1>num2) return 1;
        else if(num1 < num2) return -1;
        
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    
    return 0;
}

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1

Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1

Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1

Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”

Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"

Binary tree
=============================================================
/*
FOR INORDER,PREORDER,POSTORDER
TC:O(n)		SC:O(n)//sometimes height of the tree
*/
98)Inorder traversal	
<left> <root> <right>

Recursive:
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 

Non recursive:
// C++ program to print inorder traversal 
// using stack. 
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree Node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
	Node (int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

/* Iterative function for inorder tree 
traversal */
void inOrder(struct Node *root) 
{ 
	stack<Node *> s; 
	Node *curr = root; 

	while (curr != NULL || s.empty() == false) 
	{ 
		/* Reach the left most Node of the 
		curr Node */
		while (curr != NULL) 
		{ 
			/* place pointer to a tree node on 
			the stack before traversing 
			the node's left subtree */
			s.push(curr); 
			curr = curr->left; 
		} 

		/* Current must be NULL at this point */
		curr = s.top(); 
		s.pop(); 

		cout << curr->data << " "; 

		/* we have visited the node and its 
		left subtree. Now, it's right 
		subtree's turn */
		curr = curr->right; 

	} /* end of while */
} 

/* Driver program to test above functions*/
int main() 
{ 

	/* Constructed binary tree is 
	       	   1 
		  / \ 
		 2   3 
		/ \ 
	       4   5 
	*/
	struct Node *root = new Node(1); 
	root->left	 = new Node(2); 
	root->right	 = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 

	inOrder(root); 
	return 0; 
} 

output: 4 2 5 1 3

98)Preorder Traversal
<root><left><right>
Recursive:
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  
Non- Recursive:
void iterativePreorder(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
       return; 
  
    // Create an empty stack and push root to it 
    stack<node *> nodeStack; 
    nodeStack.push(root); 
  
    /* Pop all items one by one. Do following for every popped item 
       a) print it 
       b) push its right child 
       c) push its left child 
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) 
    { 
        // Pop the top item from stack and print it 
        struct node *node = nodeStack.top(); 
        printf ("%d ", node->data); 
        nodeStack.pop(); 
  
        // Push right and left children of the popped node to stack 
        if (node->right) 
            nodeStack.push(node->right); 
        if (node->left) 
            nodeStack.push(node->left); 
    } 
} 

99)PostOrder Traversal
<left><right><root>
Recursive:
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 

Non-Recursive:
TC:O(n)		SC:O(height of the stack)
Using two stack:
--------------------------------
 public void postOrderItr(Node root){
        Deque<Node> stack1 = new LinkedList<Node>();
        Deque<Node> stack2 = new LinkedList<Node>();
        stack1.addFirst(root);
        while(!stack1.isEmpty()){
            root = stack1.pollFirst();
            if(root.left != null){
                stack1.addFirst(root.left);
            }
            if(root.right != null){
                stack1.addFirst(root.right);
            }
            stack2.addFirst(root);
        }
        while(!stack2.isEmpty()){
            System.out.print(stack2.pollFirst().data + " ");
        }
    }
Using one stack:
-----------------------------------------
    public void postOrderItrOneStack(Node root){
        Node current = root;
        Deque<Node> stack = new LinkedList<>();
        while(current != null || !stack.isEmpty()){
            if(current != null){
                stack.addFirst(current);
                current = current.left;
            }else{
                Node temp = stack.peek().right;
                if (temp == null) {
                    temp = stack.poll();
                    System.out.print(temp.data + " ");
                    while (!stack.isEmpty() && temp == stack.peek().right) {
                        temp = stack.poll();
                        System.out.print(temp.data + " ");
                    }
                } else {
                    current = temp;
                }
            }
        }
    }

100)LeftView Of Binary Tree
------------------------------------------
TC:O(n)		SC:O(n)
void leftViewUtil(struct node* root, queue<node*>& q) 
{ 
    if (root == NULL) 
        return; 
  
    // Push root 
    q.push(root); 
  
    // Delimiter 
    q.push(NULL); 
  
    while (!q.empty()) { 
        node* temp = q.front(); 
  
        if (temp) { 
  
            // Prints first node 
            // of each level 
            cout << temp->data << " "; 
  
            // Push children of all nodes at 
            // current level 
            while (q.front() != NULL) { 
  
                // If left child is present 
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 
  
                // If right child is present 
                // push into queue 
                if (temp->right) 
                    q.push(temp->right); 
  
                // Pop the current node 
                q.pop(); 
  
                temp = q.front(); 
            } 
  
            // Push delimiter 
            // for the next level 
            q.push(NULL); 
        } 
  
        // Pop the delimiter of 
        // the previous level 
        q.pop(); 
    } 
} 

Recursive:
TC:O(n)		SC:O(n)
.........................................
void leftViewUtil(node* root, int level, int* max_level) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first node of its level 
    if (*max_level < level) { 
        cout << root->data << "\t"; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    leftViewUtil(root->left, level + 1, max_level); 
    leftViewUtil(root->right, level + 1, max_level); 
} 

101)Bottom View of Binary Tree
---------------------------------------------
TC:O(n)		SC:O(n+n)=>O(n)

void bottomView(Node *root)
{
    // TreeMap which stores key value pair 
    // sorted on key value 
    map<int,int>mp;
	// Queue to store tree nodes in level 
    	// order traversal 
   	queue<pair<Node *,int > >q;
	// Initialize a variable 'hd' with 0 
    	// for the root element. 
	int d=0;
	if(root==NULL)
	return ;
	// Assign initialized horizontal distance 
    	// value to root node and add it to the queue. 
	q.push(make_pair(root,d));
	while(!q.empty())
	{
		pair<Node *,int> p = q.front();
		q.pop();// In STL, pop() is used dequeue an item 
		struct Node *cur = p.first;
		// Extract the horizontal distance value 
        	// from the dequeued tree node. 
		int val = p.second;
        	// Put the dequeued tree node to TreeMap 
        	// having key as horizontal distance. Every 
        	// time we find a node having same horizontal 
        	// distance we need to replace the data in 
       		// the map. 
		mp[val] = cur->data;
	        // If the dequeued node has a left child, add 
        	// it to the queue with a horizontal distance hd-1. 
		if(cur->left!=NULL)
		{
			q.push(make_pair(cur->left,val-1));
		}
		// If the dequeued node has a right child, add 
        	// it to the queue with a horizontal distance 
        	// hd+1. 
		if(cur->right !=NULL)
		{
			q.push(make_pair(cur->right,val+1));
		}
	}
		map<int ,int >::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->second<<" ";
	}
}
Ref:https://www.youtube.com/watch?v=FPPkYYWZTkg

102)TopView of binary Tree
----------------------------------------------
TC:O(n)		SC:O(n)

void topView(struct Node *root)
{
     // TreeMap which stores key value pair 
     // sorted on key value 
    map<int,int>mp;
	// Queue to store tree nodes in level 
    	// order traversal 
   	queue<pair<struct Node *,int > >q;
	// Initialize a variable 'hd' with 0 
    	// for the root element. 
	int d=0;
	if(root==NULL)
	return ;
	// Assign initialized horizontal distance 
    	// value to root node and add it to the queue. 
	q.push(make_pair(root,d));
	while(!q.empty())
	{
		pair<Node *,int> p = q.front();
		q.pop();// In STL, pop() is used dequeue an item 
		struct Node *cur = p.first;
		// Extract the horizontal distance value 
        	// from the dequeued tree node. 
		int val = p.second;
                // count function returns 1 if the container  
                // contains an element whose key is equivalent  
                // to hd, or returns zero otherwise. 
       		if(mp.count(val)==0)
		{mp[val] = cur->data;}
	        // If the dequeued node has a left child, add 
        	// it to the queue with a horizontal distance hd-1. 
		if(cur->left!=NULL)
		{
			q.push(make_pair(cur->left,val-1));
		}
		// If the dequeued node has a right child, add 
        	// it to the queue with a horizontal distance 
        	// hd+1. 
		if(cur->right !=NULL)
		{
			q.push(make_pair(cur->right,val+1));
		}
	}
		map<int ,int >::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->second<<" ";
	}
}
103)Level order traversal
----------------------------------------------
TC:O(n)		SC:O(n)
void printLevelOrder(Node *root) 
{ 
    // Base Case 
    if (root == NULL)  return; 
  
    // Create an empty queue for level order traversal 
    queue<Node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 
  
        /*Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    } 
} 

LevelOrderSpiral printing:
-----------------------------------------------

void printSpiral(struct node* root) 
{ 
    if (root == NULL) 
        return; // NULL check 
  
    // Create two stacks to store alternate levels 
    stack<struct node*> s1; // For levels to be printed from right to left 
    stack<struct node*> s2; // For levels to be printed from left to right 
  
    // Push first level to first stack 's1' 
    s1.push(root); 
  
    // Keep printing while any of the stacks has some nodes 
    while (!s1.empty() || !s2.empty()) { 
        // Print nodes of current level from s1 and push nodes of 
        // next level to s2 
        while (!s1.empty()) { 
            struct node* temp = s1.top(); 
            s1.pop(); 
            cout << temp->data << " "; 
  
            // Note that is right is pushed before left 
            if (temp->right) 
                s2.push(temp->right); 
            if (temp->left) 
                s2.push(temp->left); 
        } 
  
        // Print nodes of current level from s2 and push nodes of 
        // next level to s1 
        while (!s2.empty()) { 
            struct node* temp = s2.top(); 
            s2.pop(); 
            cout << temp->data << " "; 
  
            // Note that is left is pushed before right 
            if (temp->left) 
                s1.push(temp->left); 
            if (temp->right) 
                s1.push(temp->right); 
        } 
    } 
} 

104)Height of a Binary Tree
-----------------------------------------
Recursive:
TC:o(n)		SC:O(n)
int height(node* root)
{
if(root==NULL)
return 0;
return max(height(root->left),height(root->right))+1;
}
.........................................

Iterative approach:
TC:O(n)		SC:O(n)
int treeHeight(node *root) 
{ 
    // Base Case 
    if (root == NULL) 
        return 0; 
  
    // Create an empty queue for level order tarversal 
    queue<node *> q; 
  
    // Enqueue Root and initialize height 
    q.push(root); 
    int height = 0; 
  
    while (1) 
    { 
        // nodeCount (queue size) indicates number of nodes 
        // at current lelvel. 
        int nodeCount = q.size(); 
        if (nodeCount == 0) 
            return height; 
  
        height++; 
  
        // Dequeue all nodes of current level and Enqueue all 
        // nodes of next level 
        while (nodeCount > 0) 
        { 
            node *node = q.front(); 
            q.pop(); 
            if (node->left != NULL) 
                q.push(node->left); 
            if (node->right != NULL) 
                q.push(node->right); 
            nodeCount--; 
        } 
    } 
} 

105)Diameter of a tree
-----------------------------------
TC:O(n)		SC:O(1)

/* Function to find height of a tree */
int height(Node* root, int& ans) 
{ 
    if (root == NULL) 
        return 0; 
  
    int left_height = height(root->left, ans); 
  
    int right_height = height(root->right, ans); 
  
    // update the answer, because diameter of a 
    // tree is nothing but maximum value of 
    // (left_height + right_height + 1) for each node 
    ans = max(ans, 1 + left_height + right_height); 
  
    return 1 + max(left_height, right_height); 
} 
  
/* Computes the diameter of binary tree with given root. */
int diameter(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, ans); 
    return ans; 
} 

ref:https://www.youtube.com/watch?v=kFuYJi-Pvyg

106)Check if Binary tree is height balanced or not //AVL tree
------------------------------------------
TC:O(n)		SC:O(1)
int ifHeightBalancedTree(Node *node) {
    if (node == NULL) {
      return 0;
    }
    
    if(node->left == NULL && node->right == NULL) {
      return 1;
    }

    int lH = ifHeightBalancedTree(node->left);
    int rH = ifHeightBalancedTree(node->right);
    
    if(lH == -1 || rH == -1 || abs(lH - rH) > 1) {
      return -1;
    }

    return max(lH, rH) + 1;
  }
107)LCA in Binary Tree
-------------------------------------------------
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
TC:O(n)		SC:O(h)//worst case O(n)
/*

  *  All of the nodes' values will be unique.
  *  p and q are different and both values will exist in the binary tree.

*/
TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
{
    if( root == p || root == q || root == NULL)
        return root;
    TreeNode * parent1 = dfsTraverse(root->left, p, q);
    TreeNode * parent2 = dfsTraverse(root->right, p, q);
    if( parent1 && parent2)
        return root;
    else
        return parent1 ? parent1:parent2;
}
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
    return dfsTraverse(root, p, q);
}

/*
I was asked this question in an interview, with 2 special conditions as the follow-up:
1. The given 2 TreeNodes are NOT guaranteed to be on the tree. 
2. If either or neither of them is on the tree, it is required to return null*/

  boolean ifN1Present = false;
  boolean ifN2Present = false;

  public Node findLowestCommonAncestor(Node node, int n1, int n2) {

    Node lca = this.findLowestCommonAncestorUtil(node, n1, n2);

    if (ifN1Present && ifN2Present) {
      return lca;
    } else if (!ifN1Present && !ifN2Present) {
      return null;
    } else {
      int val = lca.data == n1 ? n2 : n1;
      if (ifElementPresent(lca, val)) {
        return lca;
      }
    }

    return null;
  }

  public Node findLowestCommonAncestorUtil(Node node, int n1, int n2) {
    if (node == null) {
      return null;
    }

    if (node.data == n1) {
      ifN1Present = true;
      return node;
    }

    if (node.data == n2) {
      ifN2Present = true;
      return node;
    }

    Node leftLCA = findLowestCommonAncestorUtil(node.left, n1, n2);
    Node rightLCA = findLowestCommonAncestorUtil(node.right, n1, n2);

    if (leftLCA != null && rightLCA != null) {
      return node;
    }

    return leftLCA != null ? leftLCA : rightLCA;
  }

  private boolean ifElementPresent(Node node, int val) {
    if (node == null) {
      return false;
    }

    if (node.data == val) {
      return true;
    }

    return ifElementPresent(node.left, val) || ifElementPresent(node.right, val);
  }

108)Check if two trees are identical or not
------------------------------------------
TC:O(n)		SC:O(h)//worst case O(n)

int identicalTrees(node* a, node* b)  
{  
    /*1. both empty */
    if (a == NULL && b == NULL)  
        return 1;  
  
    /* 2. both non-empty -> compare them */
    if (a != NULL && b != NULL)  
    {  
        return
        (  
            a->data == b->data &&  
            identicalTrees(a->left, b->left) &&  
            identicalTrees(a->right, b->right)  
        );  
    }  
      
    /* 3. one empty, one not -> false */
    return 0;  
}

109)Maximum path sum
------------------------
TC:O(n)		SC:O(n)//without considering stack space then SC:O(1)

// This function returns overall maximum path sum in 'res' 
// And returns max path sum going through root. 
int findMaxUtil(Node* root, int &res) 
{ 
    //Base Case 
    if (root == NULL) 
        return 0; 
  
    // l and r store maximum path sum going through left and 
    // right child of root respectively 
    int l = findMaxUtil(root->left,res); 
    int r = findMaxUtil(root->right,res); 
  
    // Max path for parent call of root. This path must 
    // include at-most one child of root 
    int max_single = max(max(l, r) + root->data, root->data); 
  
    // Max Top represents the sum when the Node under 
    // consideration is the root of the maxsum path and no 
    // ancestors of root are there in max sum path 
    int max_top = max(max_single, l + r + root->data); 
  
    res = max(res, max_top); // Store the Maximum Result. 
  
    return max_single; 
} 

110)Construct Binary Tree from inorder and preorder
-------------------------
TC:O(n)	SC:O(n)

/* Recursive function to construct binary of size 
len from Inorder traversal in[] and Preorder traversal  
pre[]. Initial values of inStrt and inEnd should be  
0 and len -1. The function doesn't do any error  
checking for cases where inorder and preorder  
do not form a tree */
struct Node* buildTree(char in[], char pre[], int inStrt, 
                       int inEnd, unordered_map<char, int>& mp) 
{ 
    static int preIndex = 0; 
  
    if (inStrt > inEnd) 
        return NULL; 
  
    /* Pick current node from Preorder traversal using preIndex  
    and increment preIndex */
    char curr = pre[preIndex++]; 
    struct Node* tNode = newNode(curr); 
  
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return tNode; 
  
    /* Else find the index of this node in Inorder traversal */
    int inIndex = mp[curr]; 
  
    /* Using index in Inorder traversal, construct left and  
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp); 
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp); 
  
    return tNode; 
} 
  
// This function mainly creates an unordered_map, then 
// calls buildTree() 
struct Node* buldTreeWrap(char in[], char pre[], int len) 
{ 
    // Store indexes of all items so that we 
    // we can quickly find later 
    unordered_map<char, int> mp; 
    for (int i = 0; i < len; i++) 
        mp[in[i]] = i; 
  
    return buildTree(in, pre, 0, len - 1, mp); 
} 

111)Construct Binary Tree from Inorder and Postorder
-----------------------------------------------
TC:O(n)		SC:O(n)

Node* buildUtil(int in[], int post[], int inStrt, 
    int inEnd, int* pIndex, unordered_map<int, int>& mp) 
{ 
    // Base case 
    if (inStrt > inEnd) 
        return NULL; 
  
    /* Pick current node from Postorder traversal   
    using postIndex and decrement postIndex */
    int curr = post[*pIndex]; 
    Node* node = newNode(curr); 
    (*pIndex)--; 
  
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return node; 
  
    /* Else find the index of this node in Inorder  
    traversal */
    int iIndex = mp[curr]; 
  
    /* Using index in Inorder traversal, construct  
    left and right subtress */
    node->right = buildUtil(in, post, iIndex + 1, 
                            inEnd, pIndex, mp); 
    node->left = buildUtil(in, post, inStrt, 
                           iIndex - 1, pIndex, mp); 
  
    return node; 
} 
  
// This function mainly creates an unordered_map, then 
// calls buildTreeUtil() 
struct Node* buildTree(int in[], int post[], int len) 
{ 
    // Store indexes of all items so that we 
    // we can quickly find later 
    unordered_map<int, int> mp; 
    for (int i = 0; i < len; i++) 
        mp[in[i]] = i; 
  
    int index = len - 1; // Index in postorder 
    return buildUtil(in, post, 0, len - 1, 
                     &index, mp); 
} 
112)Symmetric Binary Tree
-----------------------------------------------
TC:O(n)		SC:O(n)

// Returns true if trees with roots as root1 and root2 are mirror 
bool isMirror(struct Node *root1, struct Node *root2) 
{ 
    // If both trees are emptu, then they are mirror images 
    if (root1 == NULL && root2 == NULL) 
        return true; 
  
    // For two trees to be mirror images, the following three 
    // conditions must be true 
    // 1 - Their root node's key must be same 
    // 2 - left subtree of left tree and right subtree 
    //      of right tree have to be mirror images 
    // 3 - right subtree of left tree and left subtree 
    //      of right tree have to be mirror images 
    if (root1 && root2 && root1->key == root2->key) 
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left); 
  
    // if neither of above conditions is true then root1 
    // and root2 are not mirror images 
    return false; 
} 
  
// Returns true if a tree is symmetric i.e. mirror image of itself 
bool isSymmetric(struct Node* root) 
{ 
    // Check if tree is mirror of itself 
    return isMirror(root, root); 
} 

113)Flatten Binary Tree to LinkedList
--------------------------------------------
TC:O(n)		SC:O(1) //excluding stack space

// Function to convert binary tree into 
// linked list by altering the right node 
// and making left node point to NULL 
void flatten(struct Node* root) 
{ 
    // base condition- return if root is NULL 
    // or if it is a leaf node 
    if (root == NULL || root->left == NULL && 
                        root->right == NULL) { 
        return; 
    } 
  
    // if root->left exists then we have  
    // to make it root->right 
    if (root->left != NULL) { 
  
        // move left recursively 
        flatten(root->left); 
     
        // store the node root->right 
        struct Node* tmpRight = root->right; 
        root->right = root->left; 
        root->left = NULL; 
  
        // find the position to insert 
        // the stored value    
        struct Node* t = root->right; 
        while (t->right != NULL) { 
            t = t->right; 
        } 
  
        // insert the stored value 
        t->right = tmpRight; 
    } 
  
    // now call the same function 
    // for root->right 
    flatten(root->right); 
} 

Input:
    1
   / \
  2   5
 / \   \
3   4   6
Output:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

ref:https://www.youtube.com/watch?v=598gdjE6Quo
114)Check if Binary Tree is mirror of itself or not
-----------------------------------------------
TC:O(n)		SC:O(1)//excluding stack space
bool isMirror(struct Node *root1, struct Node *root2) 
{ 
    // If both trees are emptu, then they are mirror images 
    if (root1 == NULL && root2 == NULL) 
        return true; 
  
    // For two trees to be mirror images, the following three 
    // conditions must be true 
    // 1 - Their root node's key must be same 
    // 2 - left subtree of left tree and right subtree 
    //      of right tree have to be mirror images 
    // 3 - right subtree of left tree and left subtree 
    //      of right tree have to be mirror images 
    if (root1 && root2 && root1->key == root2->key) 
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left); 
  
    // if neither of above conditions is true then root1 
    // and root2 are not mirror images 
    return false; 
} 
  
// Returns true if a tree is symmetric i.e. mirror image of itself 
bool isSymmetric(struct Node* root) 
{ 
    // Check if tree is mirror of itself 
    return isMirror(root, root); 
} 

Binary search Tree
=======================================================
115)Populate Next Right pointers of Tree
----------------------------------------
TC:O(n)		SC:O(1)//excluding stack space
/*
1. First we populate 'neighbor for left child of current node'. If current node's left child is not null then 
 1a. If 'right child of current node' is not null then we make 'right child of current node' as the neighbor of left child of current node.
 1b. If 'right child of current node' is null then we need to find the first non-null node after the left child at left child's level and make that node as left child's neighbor. 

2. To populate the 'neighbor for right child of current node', we use same logic as step #1b. We find the first non-null node after the right child at its level and make that node as the neighbor of right child.

3. Once neighbors for current node's child nodes are populated, we make recursive calls to populate neighbors for nodes in left and right sub-trees.
*/
void connect(Node *root)
{if(root==NULL){
    return;
}
// populate the right neighbor for left child
if(root->left!=NULL){
    if(root->right!=NULL){
        root->left->nextRight=root->right;
    }
    // find first non-null node after left child at its level
    else{
        Node* parentNextRight=root->nextRight;
        Node* tempNextRight;
        while(parentNextRight!=NULL){// find first non-null node after left child at its level
            tempNextRight=(parentNextRight->left!=NULL)?parentNextRight->left:parentNextRight->right;
            //we have found the non-null neighbor for left child
            if(tempNextRight!=NULL){
                root->left->nextRight=tempNextRight;
                break;
            }
            parentNextRight=parentNextRight->nextRight;
        }
    }
}

//populate the right neighbor for right child
if(root->right!=NULL){
    //find first non-null node after right child at its level
    Node* parentNextRight=root->nextRight;
    Node* tempNextRight;
    while (parentNextRight != NULL)
            {
                tempNextRight = (parentNextRight->left != NULL)? parentNextRight->left : parentNextRight->right;
                 
                // we have found the non-null neighbor for right child 
                if (tempNextRight != NULL)
                {
                    root->right->nextRight = tempNextRight;
                    break;
                }
                 
                parentNextRight = parentNextRight->nextRight;
            }
        }
        /* 
          Populating neighbors in the right sub-tree before that of left sub-tree
          allows us to access all nodes at the level of current node using neighbor-node chain 
          while populating neighbors for current node's child nodes. 
        */
         
        // populate neighbors in the right sub-tree first
        connect(root->right);
      
        // and then populate neighbors in the left sub-tree
        connect(root->left);
}
116)Search given Key in BST
SC:O(1)
/*
The Time complexity of a Balanced Binary Searched Tree is logN, as stated in Wikipedia, because as it transverse the tree, it either goes left or right eliminating half of the whole Tree. for an unbalanced Binary search tree, the time complexity is O(n), its basically similar to a linear search.*/

Iterative:

class Solution {
public:
   TreeNode* searchBST(TreeNode* root, int val) {
    while (root != nullptr && root->val != val) {
      root = (root->val > val) ? root->left : root->right;
    }
    return root;
}
};


recursive:
class Solution {
   public:
     TreeNode* searchBST(TreeNode* root, int val) {
     return root==NULL?NULL:(val==root->val?root:(root->val>val?searchBST(root->left,val):searchBST(root->right,val)));
  }
};

117)Construct (balanced) BST from given keys.
----------------------------------
TC:O(n)		SC:O(n)

TNode* sortedArrayToBST(int arr[],  
                        int start, int end)  
{  
    /* Base Case */
    if (start > end)  
    return NULL;  
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2;  
    TNode *root = newNode(arr[mid]);  
  
    /* Recursively construct the left subtree  
    and make it left child of root */
    root->left = sortedArrayToBST(arr, start,  
                                    mid - 1);  
  
    /* Recursively construct the right subtree  
    and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);  
  
    return root;  
}  

118)Check is a BT is BST or not
--------------------------------------
TC:O(n)		SC:O(1)//excluding stack space tree

int isBST(node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  

119)Find LCA of two nodes in BST
---------------------------------------------
TC:O(h)		SC:O(1)//If recursive stack space is ignored, the space complexity of the above solution is constant.

/* Function to find LCA of n1 and n2.  
The function assumes that both  
n1 and n2 are present in BST */
node *lca(node* root, int n1, int n2)  
{  
    if (root == NULL) return NULL;  
  
    // If both n1 and n2 are smaller 
    // than root, then LCA lies in left  
    if (root->data > n1 && root->data > n2)  
        return lca(root->left, n1, n2);  
  
    // If both n1 and n2 are greater than  
    // root, then LCA lies in right  
    if (root->data < n1 && root->data < n2)  
        return lca(root->right, n1, n2);  
  
    return root;  
}  

120)Find the inorder predecessor/successor of a given Key in BST
------------------------------------------------------------------
TC:O(n)		SC:O(1)
// This function finds predecessor and successor of key in BST. 
// It sets pre and suc as predecessor and successor respectively 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    // Base case 
    if (root == NULL)  return ; 
  
    // If key is present at root 
    if (root->key == key) 
    { 
        // the maximum value in left subtree is predecessor 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
  
        // the minimum value in right subtree is successor 
        if (root->right != NULL) 
        { 
            Node* tmp = root->right ; 
            while (tmp->left) 
                tmp = tmp->left ; 
            suc = tmp ; 
        } 
        return ; 
    } 
  
    // If key is smaller than root's key, go to left subtree 
    if (root->key > key) 
    { 
        suc = root ; 
        findPreSuc(root->left, pre, suc, key) ; 
    } 
    else // go to right subtree 
    { 
        pre = root ; 
        findPreSuc(root->right, pre, suc, key) ; 
    } 
} 

121)Floor and Ceil in a BST
-------------------------------------------------------
TC:O(n)		SC:O(1)

void findFloorCeil(Node* root, Node* &floor, Node* &ceil, int key)
{
	// base case
	if (root == nullptr)
		return;

	// if node with key's value is found, both floor and ceil is equal
	// to the current node
	if (root->data == key)
	{
		floor = root;
		ceil = root;
	}

	// if given key is less than the root node, recur for left subtree
	else if (key < root->data)
	{
		// update ceil to current node before recursing in left subtree
		ceil = root;
		findFloorCeil(root->left, floor, ceil, key);
	}

	// if given key is more than the root node, recur for right subtree
	else
	{
		// update floor to current node before recursing in right subtree
		floor = root;
		findFloorCeil(root->right, floor, ceil, key);
	}
}

output will be -1 if floor or ceil is not found;
cout<<(floor?floor->data:-1)<<endl;
cout<<(ceil?ceil->data:-1)<<endl;

122)Find K-th smallest and K-th largest element in BST
------------------------------------------
Kth smallest element in BST (inorder traversal)
TC:O(n)		SC:O(1)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int nums[2]={0};
        inorder(root,nums,k);
        return nums[1];
    }
public:
    void inorder(TreeNode* root,int nums[],int k){
        if(root == NULL){
            return;
        }
        
        inorder(root->left,nums,k);
        if(++nums[0] == k){
            nums[1]=root->val;
            return;
        }
        inorder(root->right,nums,k);
    }
    
};

Kth largest element in BST ( Reverse Inorder traversal )
TC:O(n)		SC:O(1)

int KthLargestBST (BSTNode root, int K, int &count )
{
  if(root == NULL || count >= K)
   return -1
  KthLargestBST (root.right, K, count)
  count = count + 1
  if(count == K)
   return root.data
  KthLargestBST (root.left, K, count)
}


123)Find a pair with a given sum in BST
-----------------------------------------------
TC:O(n)		SC:(h)//if tree is balanced
// Function to find a pair with given sum 
bool existsPair(node* root, int x) 
{ 
    // Iterators for BST 
    stack<node *> it1, it2; 
  
    // Initializing forward iterator 
    node* c = root; 
    while (c != NULL) 
        it1.push(c), c = c->left; 
  
    // Initializing backward iterator 
    c = root; 
    while (c != NULL) 
        it2.push(c), c = c->right; 
  
    // Two pointer technique 
    while (it1.top() != it2.top()) { 
  
        // Variables to store values at 
        // it1 and it2 
        int v1 = it1.top()->data, v2 = it2.top()->data; 
  
        // Base case 
        if (v1 + v2 == x) 
            return true; 
  
        // Moving forward pointer 
        if (v1 + v2 < x) { 
            c = it1.top()->right; 
            it1.pop(); 
            while (c != NULL) 
                it1.push(c), c = c->left; 
        } 
  
        // Moving backward pointer 
        else { 
            c = it2.top()->left; 
            it2.pop(); 
            while (c != NULL) 
                it2.push(c), c = c->right; 
        } 
    } 
  
    // Case when no pair is found 
    return false; 
} 

ref:https://www.geeksforgeeks.org/pair-with-a-given-sum-in-bst-set-2/
124)BST iterator
-------------------------------------------
TC:O(1)//best and avg //TC:O(n) only tree skewed but that too goes through left of that node
SC:O(h)
/*

Space complexity: The space complexity is O(h) which is occupied by our custom stack for simulating the inorder traversal. Again, we satisfy the space requirements as well as specified in the problem statement. 
*/
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
            
        return top->val;
    }
    
    /** put all the left child() of root */
    void find_left(TreeNode* root)
    {
        TreeNode* p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};
125)Size of the largest BST in a Binary Tree
------------------------------------------------
TC:O(n)		SC:O(1)//excluding the call stack

// Data structure to store information about binary tree rooted under a node
struct SubTreeInfo
{
	// stores the min and the max value in the binary tree rooted under the
	// current node. They are relevant only if isBST flag is true
	int min, max;

	// stores the size of largest BST in binary tree rooted under
	// the current node
	int size;

	// true if binary tree rooted under the current node is a BST
	bool isBST;

	// Constructor
	SubTreeInfo(int min, int max, int size, bool isBST)
	{
		this->min = min;
		this->max = max;
		this->size = size;
		this->isBST = isBST;
	}
}

// Recursive function to find the size of the largest BST in a given binary tree
SubTreeInfo* findLargestBST(Node* root)
{
	// Base case: empty tree
	if (root == nullptr)
		return new SubTreeInfo(INT_MAX, INT_MIN, 0, true);

	// Recur for left subtree and right subtrees
	SubTreeInfo* left  = findLargestBST(root->left);
	SubTreeInfo* right = findLargestBST(root->right);

	SubTreeInfo* info = nullptr;

	// Check if binary tree rooted under the current root is a BST

	// 1. Left and right subtree are also BST
	// 2. The value of the root node should be more than the largest value
	//	in the left subtree
	// 3. The value of the root node should be less than the smallest value
	//	in the right subtree
	if (left->isBST && right->isBST &&
		(root->data > left->max && root->data < right->min))
	{
		info = new SubTreeInfo(min(root->data, min(left->min, right->min)),
						max(root->data, max(left->max, right->max)),
						left->size + 1 + right->size,
						true);
	}
	else
	{
		// If binary tree rooted under the current root is not a BST
		// return the size of largest BST in its left and right subtree

		info = new SubTreeInfo(0, 0,
						max(left->size, right->size),
						false);
	}

	// deallocate the memory for left and right subtrees info node
	delete(left), delete(right);

	return info;
}

126)Serialize and deserialize Binary Tree
------------------------------------------
TC:O(n)		SC:O(1)

void serialize(Node *root,vector<int> &A)
{
    if(root==NULL){
        A.push_back(-1);
        return;
    }
    
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);

}

/*this function deserializes
 the serialized vector A*/

Node* deSerializeUtil(vector<int> &A,int &pointer)
{
if(A[pointer]==-1){
pointer++;
return NULL;
}
Node *root = new Node(A[pointer]);
pointer++;
root->left = deSerializeUtil(A,pointer);
root->right = deSerializeUtil(A,pointer);

return root;
}

Node * deSerialize(vector<int> &A)
{
//Your code here
int pointer=0;
return deSerializeUtil(A,pointer);
}

127)Binary Tree to Double Linked List
----------------------------------
TC:O(n)		SC:O(1)

void inorder(Node* root,Node** head)
{
if(root==NULL)
return ;
static Node* prev=NULL;
inorder(root->left,head);
if(*head==NULL)
*head=root;
else
{
root->left=prev;
prev->right=root;
}
prev=root;
inorder(root->right,head);
}
Node * bToDLL(Node *root)
{
Node* head=NULL;
inorder(root,&head);
return head;
}

128)Find median in a stream of running integers
-------------------------------------
TC:O(log n)//for addNum()
TC:O(1)//for finding the medium
SC:O(n)

class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
        else secQ.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};
129)K-th largest element in a stream.
------------------------------------
TC:O(log k)	SC:O(k)
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minheap;// Syntax to create a min heap for priority queue
    int m_k;
    KthLargest(int k, vector<int>& nums) {
        m_k=k;
        for(int x:nums)add(x);
    }
    
    int add(int val) {
        if(minheap.size()<m_k)minheap.push(val);
        else
        {
            if(val>minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }
};

130)Distinct numbers in Window.
---------------------------------
TC:O(n)		SC:O(n)

void countDistinct(int arr[], int k, int n) 
{ 
    // Creates an empty hashmap hm 
    map<int, int> hm; 
  
    // initialize distinct element count for current window 
    int dist_count = 0; 
  
    // Traverse the first window and store count 
    // of every element in hash map 
    for (int i = 0; i < k; i++) { 
        if (hm[arr[i]] == 0) { 
            dist_count++; 
        } 
        hm[arr[i]] += 1; 
    } 
  
    // Print count of first window 
    cout << dist_count << endl; 
  
    // Traverse through the remaining array 
    for (int i = k; i < n; i++) { 
        // Remove first element of previous window 
        // If there was only one occurrence, then reduce distinct count. 
        if (hm[arr[i - k]] == 1) { 
            dist_count--; 
        } 
        // reduce count of the removed element 
        hm[arr[i - k]] -= 1; 
  
        // Add new element of current window 
        // If this element appears first time, 
        // increment distinct element count 
  
        if (hm[arr[i]] == 0) { 
            dist_count++; 
        } 
        hm[arr[i]] += 1; 
  
        // Print count of current window 
        cout << dist_count << endl; 
    } 
} 

131)K-th largest element in an unsorted array
------------------------------------
TC:O(n)		sc:O(1)
class Solution {
public:
	int partition(vector<int>& nums, int i, int j)
	{
		if (i == j) return i;

		int pivot = nums[i];
		std::swap(nums[i], nums[j]);
		
		int i0 = i;
		for(int k = i; k < j; k ++)
		{
			if(nums[k] <= pivot)
			{
				std::swap(nums[k], nums[i0 ++]);
			}
		}
		std::swap(nums[i0], nums[j]);
		return i0;
	}
    int findKthLargest(vector<int>& nums, int k) 
	{
		size_t len = nums.size();
		int pi = 0;
		int tgt = len - k;

		int a = 0, b = len - 1;
		while((pi = partition(nums, a, b)) != tgt)
		{
			if(pi < tgt)
			{
				a = pi + 1;
			}
			else if(pi > tgt)
			{
				b = pi - 1;
			}
		}
		return nums[pi];
    }
};
Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
132)Flood-fill Algorithm
----------------------------------------------
Time Complexity: O(N), where NNN is the number of pixels in the image. We might process every pixel.

Space Complexity: O(N), the size of the implicit call stack when calling dfs.

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor){
            return image;
        }
        
        fill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
public:
    void fill(vector<vector<int>>& image,int i,int j,int color,int newColor){
        if(i<0 || i>=image.size() || j<0 || j>=image[i].size() || image[i][j] != color){
            return;
        }
        image[i][j]=newColor;
        fill(image,i+1,j,color,newColor);
        fill(image,i-1,j,color,newColor);
        fill(image,i,j+1,color,newColor);
        fill(image,i,j-1,color,newColor);
    }
};

GRAPH
===========================
134)Clone a graph
----------------------------
TC:O(E+V)	SC:O(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        unordered_map<int, Node*> visited;
        return clone_node(node,visited);
    }
    
    Node* clone_node(Node* node,unordered_map<int,Node*>& visited){
        Node *new_node = new Node(node->val);
        visited.insert({node->val,new_node});
        
        for(Node *n : node->neighbors){
            auto it=visited.find(n->val);
            if(it==visited.end()){//not visited
                Node* cn =clone_node(n,visited);
                new_node->neighbors.push_back(cn);
            }
            else{
                (new_node->neighbors).push_back(it->second);
            }
        }
        return new_node;
    }
};

ref:https://www.youtube.com/watch?v=S931KMpiKmQ

134)DFS (PREORDER) // Stack 
-------------------------------------------
TC:O(V+E)	SC:O(V)//https://www.youtube.com/watch?v=ZpOy0-QBVPM
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
/*Handling disconnected graph*/
// The function to do DFS traversal. It uses recursive DFSUtil() 
void Graph::DFS() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to print DFS traversal 
    // starting from all vertices one by one 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            DFSUtil(i, visited); 
} 
135)BFS (LEVELORDER) //queue
-------------------------------------------
TC:O(V+E)	SC:O(V)//https://www.youtube.com/watch?v=ZpOy0-QBVPM

void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
136)Detect A cycle in Undirected Graph/Directed Graph
------------------------------------------------------
TC:O(v+E)	SC:O(V)
Undirected Graph
-----------------------------------
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
    adj[w].push_back(v); // Add v to w’s list. 
} 
  
// A recursive function that uses visited[] and parent to detect 
// cycle in subgraph reachable from vertex v. 
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    // Mark the current node as visited 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        // If an adjacent is not visited, then recur for that adjacent 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        // If an adjacent is visited and not parent of current vertex, 
        // then there is a cycle. 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for (int u = 0; u < V; u++) 
        if (!visited[u]) // Don't recur for u if it is already visited 
          if (isCyclicUtil(u, visited, -1)) 
             return true; 
  
    return false; 
} 

Directed graph
--------------------------------------------
// This function is a variation of DFSUtil() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack) 
{ 
    if(visited[v] == false) 
    { 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true; 
        recStack[v] = true; 
  
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  // remove the vertex from recursion stack 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
// This function is a variation of DFS() in https://www.geeksforgeeks.org/archives/18212 
bool Graph::isCyclic() 
{ 
    // Mark all the vertices as not visited and not part of recursion 
    // stack 
    bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    // Call the recursive helper function to detect cycle in different 
    // DFS trees 
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack)) 
            return true; 
  
    return false; 
} 

137)Topo Sort//Kahn’s algorithm
-----------------------------------
TC:O(V+E)	SC:O(V)

void Graph::topologicalSort() 
{ 
    // Create a vector to store 
    // indegrees of all 
    // vertices. Initialize all 
    // indegrees as 0. 
    vector<int> in_degree(V, 0); 
  
    // Traverse adjacency lists 
    // to fill indegrees of 
    // vertices.  This step 
    // takes O(V+E) time 
    for (int u = 0; u < V; u++) { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); 
             itr != adj[u].end(); itr++) 
            in_degree[*itr]++; 
    } 
  
    // Create an queue and enqueue 
    // all vertices with indegree 0 
    queue<int> q; 
    for (int i = 0; i < V; i++) 
        if (in_degree[i] == 0) 
            q.push(i); 
  
    // Initialize count of visited vertices 
    int cnt = 0; 
  
    // Create a vector to store 
    // result (A topological 
    // ordering of the vertices) 
    vector<int> top_order; 
  
    // One by one dequeue vertices 
    // from queue and enqueue 
    // adjacents if indegree of 
    // adjacent becomes 0 
    while (!q.empty()) { 
        // Extract front of queue 
        // (or perform dequeue) 
        // and add it to topological order 
        int u = q.front(); 
        q.pop(); 
        top_order.push_back(u); 
  
        // Iterate through all its 
        // neighbouring nodes 
        // of dequeued node u and 
        // decrease their in-degree 
        // by 1 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); 
             itr != adj[u].end(); itr++) 
  
            // If in-degree becomes zero, 
            // add it to queue 
            if (--in_degree[*itr] == 0) 
                q.push(*itr); 
  
        cnt++; 
    } 
  
    // Check if there was a cycle 
    if (cnt != V) { 
        cout << "There exists a cycle in the graph\n"; 
        return; 
    } 
  
    // Print topological order 
    for (int i = 0; i < top_order.size(); i++) 
        cout << top_order[i] << " "; 
    cout << endl; 
} 
138)Number of islands (Do in Grid and Graph both)
--------------------------------------------------
Example 1:

Input:
11110
11010
11000
00000

Output: 1

Example 2:

Input:
11000
11000
00100
00011

Output: 3


/*Number of islands*/
TC:O(m*n)	SC:O(m*n)//including stack space
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};

/*
Connected Components in an undirected graph */
TC:O(V+E)	SC:O(V)

void Graph::connectedComponents() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            // print all reachable vertices 
            // from v 
            DFSUtil(v, visited); 
  
            cout << "\n"; 
        } 
    } 
    delete[] visited; 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices 
    // adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
Graph::~Graph() 
{ 
    delete[] adj; 
} 

139)Bipartite Check
--------------------------------------------------------
TC:O(V+E)	SC:O(v)

// C++program to check if a connected 
// graph is bipartite or not suing DFS 
#include <bits/stdc++.h> 
using namespace std; 

// function to store the connected nodes 
void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

// function to check whether a graph is bipartite or not 
bool isBipartite(vector<int> adj[], int v, 
				vector<bool>& visited, vector<int>& color) 
{ 

	for (int u : adj[v]) { 

		// if vertex u is not explored before 
		if (visited[u] == false) { 

			// mark present vertic as visited 
			visited[u] = true; 

			// mark its color opposite to its parent 
			color[u] = !color[v]; 

			// if the subtree rooted at vertex v is not bipartite 
			if (!isBipartite(adj, u, visited, color)) 
				return false; 
		} 

		// if two adjacent are colored with same color then 
		// the graph is not bipartite 
		else if (color[u] == color[v]) 
			return false; 
	} 
	return true; 
} 

// Driver Code 
int main() 
{ 
	// no of nodes 
	int N = 6; 

	// to maintain the adjacency list of graph 
	vector<int> adj[N + 1]; 

	// to keep a check on whether 
	// a node is discovered or not 
	vector<bool> visited(N + 1); 

	// to color the vertices 
	// of graph with 2 color 
	vector<int> color(N + 1); 

	// adding edges to the graph 
	addEdge(adj, 1, 2); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	addEdge(adj, 4, 5); 
	addEdge(adj, 5, 6); 
	addEdge(adj, 6, 1); 

	// marking the source node as visited 
	visited[1] = true; 

	// marking the source node with a color 
	color[1] = 0; 

	// Function to check if the graph 
	// is Bipartite or not 
	if (isBipartite(adj, 1, visited, color)) { 
		cout << "Graph is Bipartite"; 
	} 
	else { 
		cout << "Graph is not Bipartite"; 
	} 

	return 0; 
} 

140)Strongly Connected Components Kosaraju's Algorithm Graph Algorithm
------------------------------------------------------------
TC:O(V+E)	SC:O(V)

// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    cout << v << " "; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph Graph::getTranspose() 
{ 
    Graph g(V); 
    for (int v = 0; v < V; v++) 
    { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
    } 
    return g; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
} 
  
// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
    // Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            gr.DFSUtil(v, visited); 
            cout << endl; 
        } 
    } 
} 

141)Djisktra’s Algorithm
----------------------------------------------
TC:O(ElogV)	SC:O(E+V)

set <pair <int,int>>setds; //distance,node
vector<int> dist(V+1,INF); // distance vector ,initialized with infinity
setds.insert(make_pair(0,src)); // inserting source node with distance as 0
dist[src]=0;
while(!setds.empty()){
pair<int,int> tmp = *(setds.begin());//get the node which has shortest distance i.e first element in the set
setds.erase(setds.begin());
int u = tmp.second;//storing the node value
list<pair<int,int>>::iterator i;
for(i=adj[u].begin();i!=adj[u].end();++i){
	int v=(*i).first;//node
	int weight=(*i).second;
	if(dist[v]>dist[u]+weight) 
	{
		if(dist[v]!=INF){
			setds.erase(Setds.find(make_pair(dist[v],v)));
		}
		dist[v]=dist[u]+weight;
		setds.insert(make_pair(dist[v],v));
	}
}
}

142)Bellman Ford Algo // works for negative weights      // fails for negative cycles
---------------------------------------
TC:O(V*E)	SC:O(V)

// The main function that finds shortest distances from src to 
// all other vertices using Bellman-Ford algorithm.  The function 
// also detects negative weight cycle 
void BellmanFord(struct Graph* graph, int src) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
  
    // Step 1: Initialize distances from src to all other vertices 
    // as INFINITE 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX; 
    dist[src] = 0; 
  
    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 
    // edges 
    for (int i = 1; i <= V - 1; i++) { 
        for (int j = 0; j < E; j++) { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
  
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there 
    // is a cycle. 
    for (int i = 0; i < E; i++) { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
            printf("Graph contains negative weight cycle"); 
            return; // If negative cycle is detected, simply return 
        } 
    } 
  
    printArr(dist, V); 
  
    return; 
} 
143)Floyd Warshall Algorithm // If diagonals changes to negative numberthen it has cycle containing negative edges
-------------------------------------------------------
TC:O(V^3)    //O((v*E)V) => all v can be connected each other worst case then E becomes V = > O(v*v*V) =>O(v^3)
SC:O(V^2)

// Solves the all-pairs shortest path  
// problem using Floyd Warshall algorithm  
void floydWarshall (int graph[][V])  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int dist[V][V], i, j, k;  
  
    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial values of shortest distances 
    are based on shortest paths considering  
    no intermediate vertex. */
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    /* Add all vertices one by one to  
    the set of intermediate vertices.  
    ---> Before start of an iteration,  
    we have shortest distances between all  
    pairs of vertices such that the  
    shortest distances consider only the  
    vertices in set {0, 1, 2, .. k-1} as 
    intermediate vertices.  
    ----> After the end of an iteration,  
    vertex no. k is added to the set of  
    intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++)  
    {  
        // Pick all vertices as source one by one  
        for (i = 0; i < V; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (j = 0; j < V; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    // Print the shortest distance matrix  
    printSolution(dist);  
}  
  
144)MST using Prim’s Algo
--------------------------------------------
TCC:O(Elog(V))   SC:O(E+V)

// Prints shortest paths from src to all other vertices 
void Graph::primMST() 
{ 
    // Create a priority queue to store vertices that 
    // are being preinMST. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // http://geeksquiz.com/implement-min-heap-using-stl/ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
  
    int src = 0; // Taking vertex 0 as source 
  
    // Create a vector for keys and initialize all 
    // keys as infinite (INF) 
    vector<int> key(V, INF); 
  
    // To store parent array which in turn store MST 
    vector<int> parent(V, -1); 
  
    // To keep track of vertices included in MST 
    vector<bool> inMST(V, false); 
  
    // Insert source itself in priority queue and initialize 
    // its key as 0. 
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    /* Looping till priority queue becomes empty */
    while (!pq.empty()) 
    { 
        // The first vertex in pair is the minimum key 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted key (key must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;  // Include vertex in MST 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  
    // Print edges of MST using parent array 
    for (int i = 1; i < V; ++i) 
        printf("%d - %d\n", parent[i], i); 
} 

145)MST using Kruskal’s Algo
--------------------------------------
TC:O(Elog(E)+E)//ElogE for sorting ,E for disjoint set opertions(worst case)
SC:O(V+E)		

// To represent Disjoint Sets 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // Constructor. 
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        // Initially, all vertices are in 
        // different sets and have rank 0. 
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is parent of itself 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
 /* Functions returns weight of the MST*/ 
  
int Graph::kruskalMST() 
{ 
    int mst_wt = 0; // Initialize result 
  
    // Sort edges in increasing order on basis of cost 
    sort(edges.begin(), edges.end()); 
  
    // Create disjoint sets 
    DisjointSets ds(V); 
  
    // Iterate through all sorted edges 
    vector< pair<int, iPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
  
        // Check if the selected edge is creating 
        // a cycle or not (Cycle is created if u 
        // and v belong to same set) 
        if (set_u != set_v) 
        { 
            // Current edge will be in the MST 
            // so print it 
            cout << u << " - " << v << endl; 
  
            // Update MST weight 
            mst_wt += it->first; 
  
            // Merge two sets 
            ds.merge(set_u, set_v); 
        } 
    } 
  
    return mst_wt; 
} 

Dynamic programming
==================================================

146)Max Product Subarray
--------------------------------
TC:O(n)		SC:O(1)
int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int globalMaxProduct=nums[0];
        int currentMaxProduct=nums[0];
        int currentMinProduct=nums[0];
        
        for(int i=1;i<n;i++){
            int temp = currentMaxProduct;
            
            currentMaxProduct = max( nums[i],max(currentMaxProduct * nums[i],currentMinProduct * nums[i]));
            
            globalMaxProduct = max(globalMaxProduct , currentMaxProduct);
            
            currentMinProduct = min( nums[i] ,min( temp*nums[i] , currentMinProduct*nums[i] ) );
        }
        return globalMaxProduct;
    }

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

147)Longest Increasing Subsequence
-----------------------------------------
TC:O(n^2)		SC:O(n)
/* lis() returns the length of the longest   
  increasing subsequence in arr[] of size n */
int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  

148)Maximum sum increasing subsequence
----------------------------------------------------
TC:O(n^2)	SC:O(n)

/* maxSumIS() returns the maximum  
sum of increasing subsequence  
in arr[] of size n */
int maxSumIS(int arr[], int n)  
{  
    int i, j, max = 0;  
    int msis[n];  
  
    /* Initialize msis values  
    for all indexes */
    for ( i = 0; i < n; i++ )  
        msis[i] = arr[i];  
  
    /* Compute maximum sum values  
    in bottom up manner */
    for ( i = 1; i < n; i++ )  
        for ( j = 0; j < i; j++ )  
            if (arr[i] > arr[j] &&  
                msis[i] < msis[j] + arr[i])  
                msis[i] = msis[j] + arr[i];  
  
    /* Pick maximum of  
    all msis values */
    for ( i = 0; i < n; i++ )  
        if ( max < msis[i] )  
            max = msis[i];  
  
    return max;  
}  

/*
if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) 
*/
149)Longest Common Subsequence
-------------------------------------------
TC:O(m*n)	SC:(m*n)

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )  
{  
    int L[m + 1][n + 1];  
    int i, j;  
      
    /* Following steps build L[m+1][n+1] in  
       bottom up fashion. Note that L[i][j]  
       contains length of LCS of X[0..i-1] 
       and Y[0..j-1] */
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
          
    /* L[m][n] contains length of LCS  
    for X[0..n-1] and Y[0..m-1] */
    return L[m][n];  
}  
Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
150)0-1 Knapsack
---------------------------------------
TC:o(n*m)	SC:O(m*n)
// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i - 1][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
} 

151)Edit distance
--------------------------------------
TC:O(n*m)	SC:O(n*m)

int editDistDP(string str1, string str2, int m, int n) 
{ 
    // Create a table to store results of subproblems 
    int dp[m + 1][n + 1]; 
  
    // Fill d[][] in bottom up manner 
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            // If first string is empty, only option is to 
            // insert all characters of second string 
            if (i == 0) 
                dp[i][j] = j; // Min. operations = j 
  
            // If second string is empty, only option is to 
            // remove all characters of second string 
            else if (j == 0) 
                dp[i][j] = i; // Min. operations = i 
  
            // If last characters are same, ignore last char 
            // and recur for remaining string 
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
  
            // If the last character is different, consider all 
            // possibilities and find the minimum 
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]); // Replace 
        } 
    } 
  
    return dp[m][n]; 
} 

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

   1 Insert a character
   2 Delete a character
   3 Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

152)Matrix Chain Multiplication
------------------------------------
TC:O(n^3)	sc:O(n^2)

main(){
	int n=5;
	int p={5,4,6,2,7};
	int m[5][5]={0};
	int s[5][5]={0};
	int j,min,q;
	for(int d=1;d<n-1;d++){
		for(int i=1;i<n-d;i++){
			j=i+d;
			min=INT_MAX;
			for(int k=i;k<=j-1;k++){
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<min){
					min = q;
					s[i][j]=k;//for trace backing the path
				}
			}
			min[i][j]=min;
		}
	}
	cout<<m[i][n-1];
}

153)MINIMUM SUM PATH IN MATRIX	
----------------------------------------
TC:O(n^2)	SC:O(n^2)

public int minCost(int [][]cost,int m,int n){
        
        int temp[][] = new int[m+1][n+1];
        int sum = 0;
        for(int i=0; i <= n; i++){
            temp[0][i] = sum + cost[0][i];
            sum = temp[0][i];
        }
        sum = 0;
        for(int i=0; i <= m; i++){
            temp[i][0] = sum + cost[i][0];
            sum = temp[i][0];
        }
        
        for(int i=1; i <= m; i++){
            for(int j=1; j <= n; j++){
                temp[i][j] = cost[i][j] + min(temp[i-1][j-1], temp[i-1][j],temp[i][j-1]);
            }
        }
        return temp[m][n];
    }
154)Find minimum number of coins that make a given value
------------------------------------------------------
TC:(n*amount)	SC:O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);//Creating an array of size amount+1 and initializing all the values with amount+1 
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

....................................................................
TC:O(n*amount)		SC:O(amount)

	public static int change(int amount, int[] coins){
		int[] combinations = new int[amount + 1];
		
		combinations[0] = 1;
		
		for(int coin : coins){
			for(int i = 1; i < combinations.length; i++){
				if(i >= coin){
					combinations[i] += combinations[i - coin];
					//printAmount(combinations);
				}
			}
			//System.out.println();
		}
		
		return combinations[amount];
	}
/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.
Example 1:
Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10] 
Output: 1
Ref:https://www.youtube.com/watch?v=jaNZ83Q3QGc

*/
155)Subset Sum
-------------------------------------------
TC:O(n*sum)	SC:O(n*sum)

bool isSubsetSum(int set[], int n, int sum) 
{ 
    // The value of subset[i][j] will be true if 
    // there is a subset of set[0..j-1] with sum 
    // equal to i 
    bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
    return subset[n][sum]; 
} 	

156)Rod Cutting
----------------------------------------------------
TC:O(n^2)	SC:O(n)
int rodCut(int price[], int n)
{
	// T[i] stores maximum profit achieved from rod of length i
	int T[n + 1];

	// initialize maximum profit to 0
	for (int i = 0; i <= n; i++)
		T[i] = 0;

	// consider rod of length i
	for (int i = 1; i <= n; i++)
	{
		// divide the rod of length i into two rods of length j
		// and i-j each and take maximum
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], price[j - 1] + T[i - j]);
	}

	// T[n] stores maximum profit achieved from rod of length n
	return T[n];
}
157)Egg Dropping
------------------------------------------------------------
TC = >O(total floors * total eggs ) * O(total floors)//inner most loop
   => o(total floors ^2 *total eggs)
SC:O(totalFloors*totalEggs) 

    public int calculate(int eggs, int floors){
        
        int T[][] = new int[eggs+1][floors+1];
        int c =0;
        for(int i=0; i <= floors; i++){
            T[1][i] = i;
        }
        
        for(int e = 2; e <= eggs; e++){
            for(int f = 1; f <=floors; f++){
                T[e][f] = Integer.MAX_VALUE;
                for(int k = 1; k <=f ; k++){
                    c = 1 + Math.max(T[e-1][k-1], T[e][f-k]);
                    if(c < T[e][f]){
                        T[e][f] = c;
                    }
                }
            }
        }
        return T[eggs][floors];
    }
158)Word break
------------------------------------------
TC:O(n^4)//including finding the substring
SC:O(n^2)
 /**
     * Dynamic programming version for breaking word problem.
     * It returns null string if string cannot be broken into multipe words
     * such that each word is in dictionary.
     * Gives preference to longer words over splits
     * e.g peanutbutter with dict{pea nut butter peanut} it would result in
     * peanut butter instead of pea nut butter.
     */
    public String breakWordDP(String word, Set<String> dict){
        int T[][] = new int[word.length()][word.length()];
        
        for(int i=0; i < T.length; i++){
            for(int j=0; j < T[i].length ; j++){
                T[i][j] = -1; //-1 indicates string between i to j cannot be split
            }
        }
        
        //fill up the matrix in bottom up manner
        for(int l = 1; l <= word.length(); l++){
            for(int i=0; i < word.length() -l + 1 ; i++){
                int j = i + l-1;
                String str = word.substring(i,j+1);
                //if string between i to j is in dictionary T[i][j] is true
                if(dict.contains(str)){
                    T[i][j] = i;
                    continue;
                }
                //find a k between i+1 to j such that T[i][k-1] && T[k][j] are both true 
                for(int k=i+1; k <= j; k++){
                    if(T[i][k-1] != -1 && T[k][j] != -1){
                        T[i][j] = k;
                        break;
                    }
                }
            }
        }
        if(T[0][word.length()-1] == -1){
            return null;
        }
        
        //create space separate word from string is possible
        StringBuffer buffer = new StringBuffer();
        int i = 0; int j = word.length() -1;
        while(i < j){
            int k = T[i][j];
            if(i == k){
                buffer.append(word.substring(i, j+1));
                break;
            }
            buffer.append(word.substring(i,k) + " ");
            i = k;
        }
        
        return buffer.toString();
    }
-----------------------------------------------
TC:O(n*s) //if finding the string cost o(n) then O(n^2*s)  // if hash map used to find the substring then find operation takes O(1)
/*The time complexity of the algorithm is O(n * s) where s is the length of the largest string in the dictionary and n is the length of the given string.
As we run the loop only once, which takes O(n) time and each time we match it with the dictionary word which can have a length <=s so overall time taken by the program is O(n * s).*/
SC:O(n+1)

public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        if(s.length() == 0) return false;
        boolean[] breakable = new boolean[s.length() + 1];
        breakable[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(breakable[j] && wordDict.contains(s.substring(j, i))){
                    breakable[i] = true;
                    break;
                }
            }
        }
        //for(boolean b : breakable) System.out.print(b + ", ");
        return breakable[s.length()];
    }
}


159)Palindrome partitioning
-------------------------------
TC:O(n^2)	SC:O(n^2)
public static int partition(String s) {
		  int n = s.length();
		  boolean palindrome[][] = new boolean[n][n]; //boolean table
		  
		  //Trivial case: single letter palindromes
		  for (int i = 0; i < n; i++) {
			  palindrome[i][i] = true;
		  }
		  
		  //Finding palindromes of two characters.
		  for (int i = 0; i < n-1; i++) {
		    if (s.charAt(i) == s.charAt(i+1)) {
		      palindrome[i][i+1] = true;
		    }
		  }
		  
		  //Finding palindromes of length 3 to n
		  for (int curr_len = 3; curr_len <= n; curr_len++) {
		    for (int i = 0; i < n-curr_len+1; i++) {
		      int j = i+curr_len-1;
		      if (s.charAt(i) == s.charAt(j) //1. The first and last characters should match 
		    	  && palindrome[i+1][j-1]) //2. Rest of the substring should be a palindrome
		      {
		    	palindrome[i][j] = true; 
		      }
		    }
		  }
		  
		  int[] cuts = new int[n];
		  for(int i=0; i<n; i++)
		  {
			  int temp = Integer.MAX_VALUE;
			  if(palindrome[0][i])
				  cuts[i] = 0;
			  else
			  {
				  for(int j=0; j<i; j++)
				  {
					 if((palindrome[j+1][i]) && temp > cuts[j] + 1) 
					 {
						 temp = cuts[j] + 1;
					 }
				  }
				  cuts[i] = temp;
			  }			  
		  }
		  return cuts[n-1];
		}
 