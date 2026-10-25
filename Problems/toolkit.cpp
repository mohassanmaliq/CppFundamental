#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

// ---------- helpers ----------

vector<int> readArray(int &n) {
    cout << "Enter size: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    return a;
}

void printArray(const vector<int> &a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i + 1 < a.size()) cout << " ";
    }
    cout << endl;
}

// ---------- 1. prime numbers up to N (sieve) ----------

void primesUpTo() {
    int n;
    cout << "Enter N: ";
    cin >> n;
    if (n < 2) {
        cout << "No primes." << endl;
        return;
    }
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (long long i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
            count++;
        }
    }
    cout << endl << "Total: " << count << endl;
}

// ---------- 2. GCD and LCM ----------

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void gcdLcm() {
    long long a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    long long g = gcd(a, b);
    cout << "GCD: " << g << endl;
    cout << "LCM: " << (a / g) * b << endl;
}

// ---------- 3. Fibonacci ----------

void fibonacci() {
    int n;
    cout << "How many terms: ";
    cin >> n;
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        long long next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// ---------- 4. palindrome check ----------

bool isPalindrome(const string &s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        while (l < r && !isalnum((unsigned char)s[l])) l++;
        while (l < r && !isalnum((unsigned char)s[r])) r--;
        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[r])) return false;
        l++;
        r--;
    }
    return true;
}

void palindromeCheck() {
    string s;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, s);
    cout << (isPalindrome(s) ? "Palindrome" : "Not a palindrome") << endl;
}

// ---------- 5. anagram check ----------

void anagramCheck() {
    string a, b;
    cout << "Enter two words: ";
    cin >> a >> b;
    string x = a, y = b;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    cout << (x == y ? "Anagrams" : "Not anagrams") << endl;
}

// ---------- 6. max subarray sum (Kadane) ----------

void maxSubarray() {
    int n;
    vector<int> a = readArray(n);
    if (n == 0) return;
    long long best = a[0], cur = a[0];
    int start = 0, bestStart = 0, bestEnd = 0;
    for (int i = 1; i < n; i++) {
        if (cur < 0) {
            cur = a[i];
            start = i;
        } else {
            cur += a[i];
        }
        if (cur > best) {
            best = cur;
            bestStart = start;
            bestEnd = i;
        }
    }
    cout << "Max sum: " << best << endl;
    cout << "From index " << bestStart << " to " << bestEnd << endl;
}

// ---------- 7. two sum ----------

void twoSum() {
    int n, target;
    vector<int> a = readArray(n);
    cout << "Enter target: ";
    cin >> target;
    map<int, int> seen;
    for (int i = 0; i < n; i++) {
        int need = target - a[i];
        if (seen.count(need)) {
            cout << "Indices: " << seen[need] << " and " << i << endl;
            return;
        }
        seen[a[i]] = i;
    }
    cout << "No pair found." << endl;
}

// ---------- 8. binary search ----------

int binarySearch(const vector<int> &a, int key) {
    int lo = 0, hi = (int)a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        if (a[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

void searchInArray() {
    int n, key;
    vector<int> a = readArray(n);
    sort(a.begin(), a.end());
    cout << "Sorted: ";
    printArray(a);
    cout << "Enter key: ";
    cin >> key;
    int pos = binarySearch(a, key);
    if (pos == -1) cout << "Not found." << endl;
    else cout << "Found at index " << pos << endl;
}

// ---------- 9. sorting ----------

void bubbleSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

void insertionSort(vector<int> &a) {
    for (size_t i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = (int)i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void sortingDemo() {
    int n;
    vector<int> a = readArray(n);
    vector<int> b = a, c = a;
    bubbleSort(a);
    selectionSort(b);
    insertionSort(c);
    cout << "Bubble:    ";
    printArray(a);
    cout << "Selection: ";
    printArray(b);
    cout << "Insertion: ";
    printArray(c);
}

// ---------- 10. second largest ----------

void secondLargest() {
    int n;
    vector<int> a = readArray(n);
    int first = INT_MIN, second = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        } else if (a[i] > second && a[i] != first) {
            second = a[i];
        }
    }
    if (second == INT_MIN) cout << "No second largest." << endl;
    else cout << "Second largest: " << second << endl;
}

// ---------- 11. matrix multiplication ----------

void matrixMultiply() {
    int r1, c1, r2, c2;
    cout << "Rows and columns of A: ";
    cin >> r1 >> c1;
    cout << "Rows and columns of B: ";
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Cannot multiply these matrices." << endl;
        return;
    }
    vector<vector<int> > A(r1, vector<int>(c1)), B(r2, vector<int>(c2));
    vector<vector<int> > C(r1, vector<int>(c2, 0));
    cout << "Enter A:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) cin >> A[i][j];
    cout << "Enter B:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) cin >> B[i][j];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++) C[i][j] += A[i][k] * B[k][j];
    cout << "Result:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) cout << C[i][j] << " ";
        cout << endl;
    }
}

// ---------- 12. character frequency ----------

void charFrequency() {
    string s;
    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, s);
    map<char, int> freq;
    for (size_t i = 0; i < s.size(); i++) freq[s[i]]++;
    for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        cout << "'" << it->first << "' : " << it->second << endl;
    }
}

// ---------- 13. digit problems ----------

void digitProblems() {
    long long n;
    cout << "Enter a number: ";
    cin >> n;
    long long original = n, rev = 0;
    int sum = 0, digits = 0;
    if (n < 0) n = -n;
    long long t = n;
    while (t > 0) {
        int d = t % 10;
        sum += d;
        rev = rev * 10 + d;
        digits++;
        t /= 10;
    }
    cout << "Digits: " << digits << endl;
    cout << "Digit sum: " << sum << endl;
    cout << "Reversed: " << rev << endl;

    long long armstrong = 0;
    t = n;
    while (t > 0) {
        int d = t % 10;
        long long p = 1;
        for (int i = 0; i < digits; i++) p *= d;
        armstrong += p;
        t /= 10;
    }
    cout << (armstrong == n ? "Armstrong number" : "Not an Armstrong number") << endl;
    cout << (rev == n ? "Palindromic number" : "Not a palindromic number") << endl;
    (void)original;
}

// ---------- 14. factorial and nCr ----------

long long factorial(int n) {
    long long f = 1;
    for (int i = 2; i <= n; i++) f *= i;
    return f;
}

void combinatorics() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    if (r > n || n > 20) {
        cout << "Invalid input (need r <= n and n <= 20)." << endl;
        return;
    }
    cout << n << "! = " << factorial(n) << endl;
    cout << "nPr = " << factorial(n) / factorial(n - r) << endl;
    cout << "nCr = " << factorial(n) / (factorial(r) * factorial(n - r)) << endl;
}

// ---------- menu ----------

void showMenu() {
    cout << endl;
    cout << "1.  Primes up to N" << endl;
    cout << "2.  GCD and LCM" << endl;
    cout << "3.  Fibonacci series" << endl;
    cout << "4.  Palindrome string" << endl;
    cout << "5.  Anagram check" << endl;
    cout << "6.  Maximum subarray sum" << endl;
    cout << "7.  Two sum" << endl;
    cout << "8.  Binary search" << endl;
    cout << "9.  Sorting algorithms" << endl;
    cout << "10. Second largest element" << endl;
    cout << "11. Matrix multiplication" << endl;
    cout << "12. Character frequency" << endl;
    cout << "13. Digit problems" << endl;
    cout << "14. Factorial, nPr, nCr" << endl;
    cout << "0.  Exit" << endl;
    cout << "Choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: primesUpTo(); break;
            case 2: gcdLcm(); break;
            case 3: fibonacci(); break;
            case 4: palindromeCheck(); break;
            case 5: anagramCheck(); break;
            case 6: maxSubarray(); break;
            case 7: twoSum(); break;
            case 8: searchInArray(); break;
            case 9: sortingDemo(); break;
            case 10: secondLargest(); break;
            case 11: matrixMultiply(); break;
            case 12: charFrequency(); break;
            case 13: digitProblems(); break;
            case 14: combinatorics(); break;
            case 0: cout << "Bye." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);
    return 0;
}