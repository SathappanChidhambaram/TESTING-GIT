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

Doubt:https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
Method-5 TC:O(n) SC:O(1)

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

23)DO AGAIN******************************************************************************

Count number of subarrays with given XOR

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

42)Remove Duplicate from Sorted array
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

43)Max continuous number of 1’s
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
bool isSafe( int v, bool graph[V][V], int color[], int c) 
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

Bits
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
70)
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




 