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




  






