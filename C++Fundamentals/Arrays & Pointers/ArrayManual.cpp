/*
ARRAYS IN C++

1. What an array is
   An array stores a fixed number of values of the same type in
   consecutive memory locations. All elements share one name and are
   reached by an index.

2. Declaration
   data_type name[size];

   int marks[5];        // 5 ints, values are garbage until you set them
   double prices[10];
   char grade[3];

   The size must be a constant known at compile time.
   (Variable-length arrays are not standard C++.)

3. Initialization
   int a[5] = {10, 20, 30, 40, 50};   // all values given
   int b[5] = {1, 2};                 // rest become 0 -> 1 2 0 0 0
   int c[5] = {};                     // all zeros
   int d[] = {3, 6, 9};               // size deduced as 3
   char name[] = "Ali";               // 4 chars, includes '\0'

4. Indexing
   Indexes start at 0 and end at size - 1.

   int a[3] = {10, 20, 30};
   a[0]  -> 10
   a[2]  -> 30
   a[1] = 99;                         // changes the second element

5. Out of bounds
   a[3] on a size-3 array is undefined behavior. The compiler usually
   will not stop you. You may read junk, overwrite other data or crash.
   Always keep the index between 0 and size - 1.

6. Looping through an array
   for (int i = 0; i < 5; i++) {
       cout << a[i] << " ";
   }

   Range-based for (C++11):
   for (int x : a) {
       cout << x << " ";
   }

7. Getting the size
   int n = sizeof(a) / sizeof(a[0]);  // total bytes / bytes per element

   This works only where the array is still an array (not inside a
   function that received it as a parameter, see point 9).
   Since C++17 you can also use std::size(a).

8. Taking input into an array
   for (int i = 0; i < n; i++) {
       cin >> a[i];
   }

9. Passing an array to a function
   An array decays to a pointer when passed, so the function does not
   know its size. Pass the size separately.

   void printArray(int arr[], int size) {
       for (int i = 0; i < size; i++) {
           cout << arr[i] << " ";
       }
   }

   printArray(a, 5);

   Changes made to arr inside the function affect the original array,
   because no copy is made.

10. Two-dimensional arrays
    data_type name[rows][cols];

    int m[2][3] = { {1, 2, 3},
                    {4, 5, 6} };
    m[1][2] -> 6

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

11. Common mistakes
    - Using index = size (it should be size - 1 at most)
    - Forgetting that local arrays are not zeroed automatically
    - Trying to copy with b = a; (not allowed, copy element by element)
    - Comparing two arrays with == (compares addresses, not contents)
    - Using sizeof inside a function to get the array length

12. Things to practice
    - Sum, average, max and min of an array
    - Reverse an array
    - Linear search
    - Bubble sort
    - Count even and odd numbers
    - Add two matrices
*/