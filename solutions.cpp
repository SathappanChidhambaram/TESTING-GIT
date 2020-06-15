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




