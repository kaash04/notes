#include <bits/stdc++.h>
using namespace std;

// Bitwise operators
    /*
        AND [ & ] -> dono 1 then 1 else 0
        OR [ | ] -> 1 bhi 1 then 1
        NOT [ ~ ] -> 1 ka 0, 0 ka 1
        XOR [ ^ ] -> ek 1, ek 0 then 1 else 0 ==> i.e. dono same then 0 else 1
    */
    // work at bit level
        // Ex: 2&3 ->  2 is 10 in bit lvl and 3 is 11
        // thus, 1&1, 0&1 => 10 => 2


    // Left shift (<<) and right shift (>>)
        // Jo side shift karna hai us side point in symbol
        // syntax:    x >> y  OR  x << y
            // x ke bits ko y times left ya right shift kardo
        // * * * padding always done with '0'
            // Ex: 5 << 1
            // 5 ke bits ko 1 bar left shift kardo
            // 5 is 101 is binary
            // padding with 0: 5 = 0000000101
            // left shifting by 1: 0000001010 (padded a 0 at end as saare bits ek se left shift hoge)

        // Ex of right shift:
            // 5 >> 2
            // 5 is 101 in binary
            // padding with 0: 0000101
            // right shifting by 2 bits: 0000001 (data loss in right shift as last ke 2 bits right shift hoke gayab ho jayege)



// Interconversion between decimal and binary number system
    // Decimal to binary
        /*
            divide given number 'n' by 2
            store remainder
            repeat till n!=0
            reverse the string of remainder
        */
       // Ex: n = 10
       /*
            10/2 = 5 (rem = 0)
            5/2 = 2 (rem = 1)
            2/2 = 1 (rem = 0)
            1/2 = 0 (rem = 1)
            thus,
                string of remainder = 0101
                reversing it (interchanging 0<->1): 1010
            thus, 10 is 1010 in binary
       */

        // 2nd APPROACH:
            // As we know an number & 1 = 0 if number is even
                // and 1 if number is odd

            // approach:
                /*
                    do & with 1
                    if result = 0 , last bit is 0
                    and if result = 1, last bit is 1
                    right shift to make last bit disappear and bring last second bit to last bit position
                    repeat until all bits of number are 0, i.e. number = 0
                */
               // Ex Code:
int main() {
    int dec, bit, bin = 0;
    printf("Enter your decimal number: ");
    scanf("%d", &dec);
    for (int i = 0; dec != 0; i++, dec = dec >> 1) {
        bit = dec & 1;
        bin = (bit * pow(10, i)) + bin; // logic for storing binary (hand run to see how it works)
        // if bit is 0, bin = bin thus no change
        // but if bit is 1, bin = (bit * 10 ki power i) + bin = 10 ki power i + old bin value
    }

    printf("Binary representation: %d\n", bin);

    return 0;
}



// Binary to Decimal
    // summation of 2 ki power index where bit is 1
    // Ex: 10101 => 1 is present at index 0, 2, 4 (count from left and start with 0)
    // thus decimal represention = 2 ki power 0 + 2 ki power 2 + 2 ki power 4 = 21

    // Code:
        // WRONG!!
int main() {
    int bin, dec = 0;
    scanf("%d", &bin);
    for (int i = 0; bin != 0; i++, bin = bin >> 1) {
        if (bin & 1 == 1) {
            dec += pow(2, i);
        }

    }
    printf("Decimal representation: %d\n", dec);

    return 0;
}
// Gives incorrect output because bin&1 karne par bin mei jo decimal number input liya ai uska binar form ke sath &1 hoga
// Ex: 101 enter karne par
    // we want last digit i.e. 1 & 1
    // but & is bitwise operator and 101 that we entered is an integer for compiler
    // thus compiler converts it to its binary (i.e. 1100101) and then does & 1
    // so instead of doing bit & 1, extract last digit using remainder method

// Code:
int main() {
    int bin, dec = 0;
    scanf("%d", &bin);
    for (int i = 0; bin != 0; i++, bin /= 10) {
        if (bin % 10 == 1) {
            dec += pow(2, i);
        }

    }
    printf("Decimal representation: %d\n", dec);

    return 0;
}


// Ques: return true is number is power of 2 else return false
// IF it could be represented in 2 ki power something that means its binar representation must contain 1 at only 1 place
// Code:
long int binary(int dec) {
    int bit;
    long int bin = 0;
    for (int i = 0; dec != 0; i++, dec = dec >> 1) {
        bit = dec & 1;
        bin = (bit * pow(10, i)) + bin;
    }

    return bin;
}

int main() {
    int num;
    scanf("%d", &num);
    long int bin = binary(num);
    printf("Binary: %ld\n", bin);

    int count = 0;

    while (bin != 0) {
        if (bin % 2 == 1) {
            count += 1;
        }
        bin /= 10;
    }

    printf("Count: %d\n", count);
    if (count == 1) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }

    return 0;
}



// Consider an array named 'arr' having 10 elements
    // int arr[10];      (declaration)
    // arr[i]            (points element at index i)
    // arr               (gives address of first element)
        // thus we could use "int* ptr = arr" to create a pointer to array


// Linear search
    // In an array check element on every index for given value = linear search
    // Ex:
int linearSearch(int* ar, int sizee, int key) {
    int count = 0;
    for (int p = 0; p < sizee; p++) {
        if (key == *(ar + p)) {
            count += 1;
        }
    }
    return count;
}

int main() {
    int sizee, key;
    printf("How many elements do you want in array: ");
    scanf("%d", &sizee);
    int arr[sizee];

    printf("Enter your elements: ");
    for (int i = 0; i < sizee; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Which value would you like to search for: ");
    scanf("%d", &key);

    int counter = linearSearch(arr, sizee, key);

    if (counter == 0) {
        printf("FALSE - 0 Occurences\n");
    }
    else {
        printf("TRUE - %d Occurences\n", counter);
    }

    return 0;
}


// Reversing an array:
    // swap first and last, then swap second and last second and so on...
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int sizee;
    printf("Enter size of array: ");
    scanf("%d", &sizee);

    int arr[sizee];
    printf("Enter elements for array: ");
    for (int i = 0; i < sizee; i++) {
        scanf("%d", &arr[i]);
    }

    int cpy = sizee - 1; // contains last index
    for (int i = 0; i < (sizee / 2); i++, cpy--) {
        swap(&arr[i], &arr[cpy]);
    }

    printf("Swapped array: ");
    for (int i = 0; i < sizee; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


// Time and Space Complexity
    //Time complexity
        // it is the amount of time taken by an algorithm to run, as a function of length of input
        // NOT counted in sec bcoz execution time will depend on power of machine executing the algorithm
        /*
            Thus, time complexity is represented in:
                BIG O notation (gives upper bound, i.e. max time that algorithm might take)
                Theta notation (gives avg bound)
                omega notation (gives lower bound)

            most used -> BIG O as it gives max time
        */

       /*
            Constant time -> O(1)
            Linear time -> O(n)
            Logarithmic time -> O(log n)
            Quadratic time -> O(n^2)
            Cubic time -> O(n^3)

            Increasing order of complexities:
                [least] O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(n^3) < O(2^n) < O(n!) [max]
       */

      // Calculating time complexity:
        // ignore constants and take operation with highest order of complexity
        /*
            Ex:
            2n^2 + 3n -> ignoring const -> n^2 + n -> highest complexity = n^2 -> thus, O(n^2)

            1200 -> only const present thus, O(1)

            n^2 + log(n) -> O(n^2)
        */

       /*
            Real problem ex:
                for loop printing num from 0-n:
                    number of iterations = n
                    thus time complexity = O(n)

                function for swapping an array
                    1 and last swap, 2 and last second swap and so on....
                    thus number of swap = number of iterations = n/2
                    thus TC = O(n/2)
                    ignoring const, TC = O(n)
       */

        /*
            if 2 for loop present one below other, and number of iterations in 1st=n and 2nd=m:
                TC = O(n+m)

            and if same or loop present one inside other(nested):
                TC = O(n*m)
        */

       /*
            To know which algorithm to use:
                see constrains, if:
                    1 <= n <= 10/11  ---> O(n!), O(n^6)
                    1 <= n <= 15/18  ---> O(2^n * n^2)
                    1 <= n <= 100    ---> O(n^4)
                    1 <= n <= 400    ---> O(n^3)
                    1 <= n <= 2000    ---> O(n^2 * log(n))
                    1 <= n <= 10^4    ---> O(n^2)
                    1 <= n <= 10^6    ---> O(n log(n))
                    1 <= n <= 10^8    ---> O(n), O(log(n))

            so, if number of input is given as upto 2000, we could use O(n^2 * log(n)) OR an complexity lying below it
       */


    // SPACE COMPLEXITY
        /*
            TC = amount of time taken as a function of length of input
            SC = amount of memory taken as a function of length of input
        */
       // SC of variables = O(1)

       /*
            Ex:
                int a;  ---> O(1)
                int arr[5]   ---> fixed size ka array, O(1)

                int n;
                scanf(n);
                int arr[n]   ---> O(n)
       */



// Binary Search
    // TIME COMPLEXITY = O(log n)
    // can be applied only on monotonic functions
    // i.e. values should either be increasing or decreasing

    // check mid element
    // if mid element > key, check left by repeating same process
    // else if mid element == key, return true as key is present
    // else check rightward using same process

    //Code:
int binarySearch(int* ar, int sizee, int key) {
    int start = 0, end = sizee - 1, mid;
    while (start <= end) {
        mid = (start + end) / 2;

        if (*(ar + mid) == key)
            return mid;
        else if (*(ar + mid) > key)
            end = mid - 1;
        else
            start = mid + 1;
        // must use mid+1 AND mid-1 else stuck in loop if ke not present
        // because end will eventually become start+1 so mid = start and stuck there

    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of elements you want to enter: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to search: ");
    scanf("%d", &key);

    int index = binarySearch(arr, n, key);
    if (index != -1) {
        printf("Key found at index %d\n", index);
    }
    else {
        printf("Key not found in given array\n");
    }

    return 0;
}

// in linear search if 1000 elements present, we need to do 1000 comparisons
    // but using binary search we need to do only 10
    // BUT only condition is that given array should be sorted either ascending or descending
    // TIME COMPLEXITY OF LINEAR SEARCH = O(n);



// Selection sort
    // TIME COMPLEXITY = O(n^2)
    // thus use on small sized array only
    /*
        Select minimum element from array
        Swap it with element at index 0
        Select min element from remaining (index 0 chodke)
        Swap with index 1
        and so on...
    */
    // CODE:
void selectionSort(int* arr, int sizee) {
    for (int i = 0; i < sizee - 1; i++) // outer for loop for swapping elements
    {
        int minIndex = i; // hame ever time +1 inde se min search karna hai, 
        //like in first iteration we need to check all
        // in second index 1 and above (bcoz 0 inde pr sabse min value aa ayegi using swap)
        // so declared min index = i, har ek iteration par 1 se aage jayega

        for (int j = i + 1; j < sizee; j++) // inner for loop for find min value
        // value search always next element of i se karna hai so used i+1 as start
        // ex: if arr[0]=3, we need to check if there is value less than 3 frm arr[1]
        {
            if (*(arr + minIndex) > *(arr + j))
                minIndex = j; // stored index of minimum value in minIndex
        }
        swap((arr + minIndex), (arr + i));
    }
}



// Bubble sort
    // TIME COMPLEXITY = O(n^2)
    /*
        if a[0] > a[1], swap
        if a[1] > a[2], swap
        and so on... to bring the largest element to end
        repeat again to bring second largest to second last pos
        and so on ...
    */
    // CODE:
void bubbleSort(int* arr, int sizee) {
    for (int i = 0; i < sizee - 1; i++) // outer for loop for number of rounds, har round mei 1 largest last mei jayega
    {
        for (int j = 0; j < (sizee - i); j++) // inner for loop to bring 1 largest element to last each time
        // loop ko sizee-i tak hi run kiya bcoz har bar last i elements would be already sorted
        // bccoz after eery round, 1 largest element would go to last
        {
            if (*(arr + j) > *(arr + j + 1))
                swap((arr + j), (arr + j + 1));
        }
    }
}



//  Insertion sort
    /*
        put first element as it is
        if 2nd element < first, insert 2nd ne before first (first ko 1 se right shift and then place 2nd in its place)
        if 3rd < 2nd, 3rd < 1st, insert before 1st
        repeat till array is sorted

        logic for shifting:
            value to shift ko temp var mei store karo
            jis element ke pehele shift karna hai usse aage vale saare right shit by 1
            temp vali value copy on desired location
            Ex:
                arr = 1, 5, 8, 2
                we want to shift 2 to index '1'
                temp = 2
                arr[3] = 8
                arr[2] = 5
                arr[1] = temp
                done!!
    */

   // Code for left shifting an element in array:
void leftShift(int* arr, int currentIndex, int destinationIndex) {
    int temp = *(arr + currentIndex);
    for (int i = currentIndex; i > destinationIndex; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + destinationIndex) = temp;
}

// Insertion sort code:
void insertionSort(int* arr, int sizee) {
    for (int i = 0; i < sizee - 1; i++) {
        for (int j = i + 1; j < sizee; j++) {
            if (*(arr + j) < *(arr + i))
                leftShift(arr, j, i);

        }

    }

}
// TC = O(n^3)



// Optimised way to use insertion sort:
void insertionSort(int* arr, int sizee) {
    for (int i = 0; i < sizee - 1; i++) // outer for loop for number of insertions = n-1
    {
        int temp = *(arr + i + 1); // temp mei 1 inde ki val store karo starting with index 1
        int j = i; // j ko index of temp - 1 par initialize

        for (; j >= 0; j--) // j ko 0th index tak leke jao
        {
            if (*(arr + j) > temp)
                *(arr + j + 1) = *(arr + j); // right shift till no. at index is > temp
            else
                break; // jab number temp se bada na ho, break inner loop
        }
        *(arr + j + 1) = temp; // and cpy temp to jth index, i.e. index jaha par loop break hua tha
    }
}

// TC = O(n^2)



// C++ STL
    // STL stands for standard template library and contains optimised codes or most frequently used algos and data structs
    /*
        STL has:
            1. Algorithms
            2. Containers
    */

    // Most commonly used that we will study:
    /*
        Algorithms:
            a. binary search
            b. lower/upper bound
            c. min/max
            d. reverse or rotate
            e. sort/swap
    */

    /*
        Containers:
            i) Sequence containers
                a. Array (stl array is different from normal static array)
                b. Vector
                c. Deque
                d. list
                e. forward list --

            ii) Container adaptors
                a. Stack
                b. Queue
                c. Priority Queue

            iii) Associative Containers
                a. Set
                b. Map
                c. Multiset --
                d. Multimap --

            iv) Unordered Associative Containers
                a. unordered set
                b. unordered map
                c. unordered multiset --
                d. unordered multimap --

            -- represents that they are very very rarely used and hence not covered
    */


    // STL ARRAY
        // stl array offers in built functions along with it ust like string
        /*
         syntax:
            ' #include <array>'   in beginning

            declaration:
                array<data_type, size> arrayName;

            accessing elements:
                accessing elements in stl array could be done in 2 ways
                1. arrayName[index] -> just like normal array
                2. arrayName.at(index) -> like we do in strings
        */

        /*
            Commonly used perations in STL array:
                arr.at(index) -> get element at provided index
                arr.size() -> returns size of array
                arr.empty() -> returns 1 if array is empty, else returns 0
                arr.front() -> returns first element of array
                arr.back() -> returns last element of array
                arr.swap(i, j) -> swap elements on index i and j
        */



    // VECTOR
        // similar to array but, agar vector full hua and we try to add element, then vo apni size double kar lega
        // pehele vo ek naya vector banaega of double size
        // then uske elements naye vec mei copy
        // and purana wala vec destroy

        /*
            syntax:
                ' #include <vector> '

                vector<data_type> vecName;

            accessing elements:
                v.at(index)
                v[index]
        */
       /*
            commonly used methods:
            v.at(index) -> returns value at given index
            v.push_back(val) -> pushes the value to vector end
            v.pop_back() -> removes last element
            v.front() -> returns first element of vector
            v.back() -> returns last element of vector
            v.clear() -> clears the vec by deleting all elements
            ** v.size() -> returns number of elements in vector     // not size lie arr.size()
            ** v.capacity() -> returns size allocated for vec

            * if we just create vec and dont add any element, its capacity = 0
            if we add 1 element, size=1  capacity = 1
            adding 2 elements in vec, size = 2, capacity = 2
            adding 3 elements, size = 3, capacity = 4        // because vec full hone par capacity double karega

            if we already know size and want static sized vec:
                vector<data_type> v2(size, initialValue)
            here, initial value is value at which all 5 values would be initialised

            if we want to make a new vec and copy all elements to it from some other vec:
                vector<data_type> v3(v2)   ---> creates new vec v3, and copies all elements of v2 to it
       */


    // Deque
        // Deque stands for double ended queue
        // They are containers with feature of expansion and contraction on both ends
        // IT IS SIMILAR TO VECTOR, BUT ALLOWS push and pop operations from both front and back.
        /*
            syntax:
                ' #include <deque> '

                deque<data_type> dequeName;
        */
        /*
            commonly used methods:
            d.push_back(value) -> pushes the value to end of deque
            d.push_front(value) -> pushes the value to start of deque
            d.pop_front() -> removes one val from start
            d.pop_back() -> removes one val from end
            d.at(index) -> returns value at provided index
            d.front() -> returns first element [ i.e. element at 0th index ]
            d.back() -> returns last element
            d.empty() -> returns true (1) if deque is empty, else return false (0)
            d.erase(start, end) -> deletes elements from start to end iterator
                ex:
                    d.erase(d.begin(), d.begin()+1) => deletes first element
       */


    // Lists
        // list in stl is ade using doubl linked list
        // same like deque, i.e. can expand and contract on both ends
        // direct access to element at known index NOT possible ( thus, l.at(index) is not a valid method )
        // pehele traverse karke us index par jana padega
        /*
            syntax:
                ' #include <list> '

                list<data_type> listName;
        */
        /*
            commonly used methods:
            l.push_back(value) -> pushes the value to end of list
            l.push_front(value) -> pushes the value to start of list
            baki methods similar to deque, like erase, begin(), end(), etc.
       */



    // Stacks
        // ek ke upar ek data
        // thus it follows, last in first out concept
        /*
            syntax:
                ' #include <stack> '

                stack<data_type> stackName;
        */
        /*
                commonly used methods:
                s.push(val) -> pushes value to top of stack
                s.top() -> returns the top element of stack
                s.pop() -> removes top element of stack
                s.size() -> returns number of elements in stack
                s.empty() -> returns bool (0 or 1) based on if stack is empty or not
        */


    // Queue
        // Very much same as stack, BUT
        // Follows the principle of first in first out
        // shaadi ke line mei jo aage khada hoga usko pehele khana milega :)
        /*
            syntax:
                ' #include <queue> '

                queue<data_type> queueName;
        */
        /*
            commonly used methods, similar to stack
        */


    // Priority Queue
        // Similar to queue but first element hamesha greatest hoga
        // priority queue aka max heap
        // min heap = modified priority queue jisme first element hamesha smallest hoga
        /*
            thus,
                in max heap, pop karne par max element gayab hoga
                and in min heap, pop karne par min element gayab hoga
        */
        /*
            syntax:
                ' #include <queue> '

                // max heap
                    priority_queue<int> maxh;

                //min heap
                    priority_queue<int, vector<int>, greater<int>> minh;
        */
        /*
                commonly used methods are same as queue,
                    just when we pop, first element is popped...and here, elements are sorted based on max/min heap
                    so take that in consideration
        */


    // Set
        // Set ki unique baat = har element 1 hi baar store hoga
        // like agar hamne 3 bar '5' dala to bhi 1 hi baar '5' store karega
        // elements sorted order mei store hote hai
        // unordered set = set jisme elements sorted order mei store nai hote ( thus, it is lil faster than normal set )
        /*
            syntax:
                ' #include <set> '

                set<int> s;
        */
        /*
            commonly used methods:
                s.insert(val) -> inserts provided value to set      [insert method ki TC = O(log n) -> binary search :)]
                s.erase(itera) -> erases elements present at iterator provided
                s.count(val) -> returns true (1) if provided value is present in set, else returns false

                s.find(val) -> returns an iterator to provided value
                    ex:
                        set<int>::iterator itera = s.find(5);
                        now, itera will point to the location where 5 is present
        */


    // Map
        // values are stored in key value pair in Map
        // map = sorted
        // unordered map = not sorted
        // same like set and unordered set
        /*
            ex:
                ' #include <map> '
                .
                .
                .
                map<int, string> m;
                m[1] = "cpp";
                m[54] = "ok";
                m[69] = "sushil";

                thus here,
                    1 will be mapped to cpp
                    54 will be mapped to ok
                    and 69 would be mapped with sushil
                    also, first data type, i.e. int here, is key and the following one (string) is value
        */

        /*
            commonly used methods:
                m.insert( {key, val} ) -> inserts provided ke value pair to map
                m.count(val) -> returns a boolean based on if the value is present in map or not
                m.erase(val) -> erases key value pair of provided ke val
                    * * * point to be noted: baki sab mei erase method iterator leta hai as argument, but isme sidha value

                m.find(val) -> returns an iterator for provided value
        */



    // ALGORITHMS IN STL
        // stl does contain optimised codes for algorithms that could save lot of time instead of re-writing
        // Binary search
            // ex:
int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    bool isPresent = std::binary_search(v.begin(), v.end(), 6);
    std::cout << isPresent << std::endl;
    return 0;
}
// binary search function takes 3 arguments, iterator to first element jaha se aage binary search lagana hai
// iterator to last element, jaha tak binary search lagana hai
// and value to check i it is present or not


// lower/upper bound
    // lower bound
        // lower bound method in c++ return an iterator to the value that is equal to or just greater than provided value
        // i.e. jo val provide ki hai, uske equal ya usse just bade element ka iterator return karega
        // ex: 
int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    std::vector<int>::iterator itera = std::lower_bound(v.begin(), v.end(), 6);
    std::cout << (itera - v.begin()) << std::endl;
    // itera - v.begin kiya to get index
    // bcoz, itera would be technically = v.begin() + index 
    // [cant be fetched like that directly though, because its a object not a pointer]
    return 0;
}

// Upper bound
    // upper bound mei ek to vo value a usse just chote wale element ka iterator return hoga
    // baki same...

// * * * in upper bound and lower bound, agar provided value ke multiple occurences hai, then first occurence ka iterator return hoga


// max(), min(), swap(), sort() are basic functions in STL and need no explaination

// reverse() is used to reverse a string and takes iterator to first and last element as argument

// rotate() is used to rotate a vector around node
// i.e. node ke pehele wale saare element rotate hokar end mei chale jayege
// ex: vec = {1, 3, 6, 7}
    // rotating about index 1: {3, 6, 7, 1} -> index 1 ke pehele e saare element end mei chale jayege

// rotate() function takes 3 arguments, all 3 being iterators of first, node, and last element respectively



// Char, Strings and arrays
    // String = 1D array of characters
    // suppose we store "coding" in a string then it would take 7 bytes of continuous memory space for,
        // 'c' 'o' 'd' 'i' 'n' 'g' and '\0'
        // '\0' is terminator or null character used to represent end of string
        // ASCII value of null character = 0

    //Ex:
#include <bits/stdc++.h>
using namespace std;

int main() {
    char name[20];
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Your Name is " << name << "\n";
    return 0;
}

// WORKS FINE WHEN NAME ENTERED DOESNT CONTAIN SPACE
// agar space hua then, just space ke pehele wala store hoga
// this is bcoz cin stops execution on receiving space( ), tab(\t) or enter(\n)

// Ex:
#include <bits/stdc++.h>
using namespace std;

int main() {
    char name[20] = "coding";
    name[2] = '\0';
    cout << name << "\n";
    return 0;
}
// This code will print only "co" and not "coding" bcoz null character is received at 2nd index so it would stops printing
// * * ACCESSING NULL TERMINATOR IS ONLY POSSIBLE IN char array and std::String does not allow that



// 2D arrays
    // its just a linear array but every element represented in its matrix form, corresponds to a specific element in an linear array
    // Ex: in arr[3][3], 1st element of 2nd row ( arr[1][0] ) will correspond to 4th element in linear array stored in memory
    // Ex: in arr[3][3], 1st element of 2nd row ( arr[1][0] ) will correspond to 4th element in linear array stored in memory
    /*
        providing value to array along with declaring:
        -> int arr[2][2] = {1, 2, 3, 4}
            here, 1 and 2 would be elements of 1st row and 3 and 4 would be of 2nd
        -> int arr[2][2] = {{1, 3}, {2, 4}}
            here elements in first bracket would be elements of first row and that of 2nd bracket would be in 2nd row
    */

    // Function to check if an element is present in an array:
bool isPresent(int arr[][3], int col, int row, int target) // must specify at least number of columns in 2D array
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (arr[i][j] == target)
                return 1;
    return 0;
}
// calling : isPresent(arr, 3, 3, 4)  // just pass name of array

// * * * See spiral printing question in lec 23 @ 47min


// Conversion between linear form of array and matrix form
/*
    suppose there is 3x3 matrix = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    in linear form:
        start index = 0
        end index = (row*col) - 1

    * * to obtain the index we obtain in linear form to matrix form:
        index / col = row index
        index % col = column index

*/

// Binary search in 2D array
// Use same logic as binar search for 1D array and use it here by converting 2D matri to linear form
// Ex:
bool binarySearch(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0, end = (row * col) - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (matrix[mid / col][mid % col] == target)
            return 1;
        else if (matrix[mid / col][mid % col] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}
// IMP ques so see working carefully
// to use this, matri must be sorted in its linear form
// thus, it must be sorted row wise and irst element of each row should be greater than last element of prev row 



// MATHS FOR DSA
    // Sieve of Eratosthenes
        /*
            Ques: count prime numbers from 0-n where n is given input
            approach: for loop to traverse from 0-n, other for loop to check prime
            Thus, Complexity => O(n^2)

            Optimised way = sieve of eratosthenes
            mark every number from 2 to n-1 as prime (bcoz 1, 0 are niether prime nor composite)
            now 2 is prime so cut all numbers that come in 2's table
            3 is prime so cut all numbers from 3's table
            and so on...
            this would also have O(n^2) complexity but
            'n' would be way lesser as we ain't traversing through each element every time.
        */
        // Implementation:
int countPrime(int n) {
    std::vector<bool> numbers(n, true); // created a vector and set all number as prime
    numbers[0] = false;
    numbers[1] = false; // set 0, 1 as not prime
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (numbers[i] == true) {
            count++;
            for (int j = 2 * i; j < n; j += i) {
                // for loop for marking not prime
                // initialised at 2*i i.e. 2x in table of that number
                // and increment by i each time
                numbers[j] = false;
            }

        }
    }
    cout << count;
}



// Euclid's Algorithm
    // gcd = hcf = smallest number jiske table ei dono aaye
    /*
        According to euclid's algorithm:
            gcd(a, b) = gcd(a-b, b)   [ofc, jo bada hai usme se chota subtract... as gcd of negative is undefined]

        If one of the element is 0, the other one is gcd
        else, keep subtracting smaller on from greater until they both are equal
        bcoz gcd(x, x) = x
        easyyy...
    */
    // Implementation:
int gcd(int a, int b) {
    if (a == 0)
        return b;

    if (b == 0)
        return a;


    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// LCM(a, b) * GCD(a, b) = a * b
// use this relation to find unknown values


// Modulo operator [ % ]
    // if its given in ques to print ans in modulo 10^9+7 it means print ans%(10^9+7)
    // this is generally done to bring answer in specific range

// Value of a%n always lies in the range [0, n-1]



// Fast Exponentiation
// To find a^b
/*
    Method 1:
    using for loop
    T.C. = O(b)

    Method 2:
    * * efficient one
    T.C. = O(log n)

    if b is even:
        a^b could be written as (a^2)^b/2       [...1]
    else if b is odd:
        a^b = a * (a^2)^b/2     [...2]
*/

// Thus, logic for fast exponentiation:
// make var res = 1
// check if odd/even
// if odd -> multiply a in res [using 2]
// set a = a square and b = b/2
// repeat until b!=0

// CODE:
int expo(int x, int y) {
    int res = 1;
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    while (y != 0) {
        if (y & 1)
            res *= x;
        x *= x;
        y /= 2;
    }
    return res;
}



// POINTERS
    // pointers are special variables that store memory address
    // computer memory contains symbol table that maps variable name to their memory addresses
    // Address of operator (&) is used to fetch address of a variable

    /*
        Initialisation of a pointer:
            int* p = &var
        creates a pointer for int data type and sets it to point var

        - always initialise a pointer while creating it, else it would have some garbage value and would point to se random address in the memory which might not even belong to the program

        - dereferencing a pointer = usme stored address par ki value read karna
            this is done using ' * ' operator

        - equivalents:
            *p -> var
            (*p)++ -> var++
            p -> &var

        - pointer would always take 8 bytes regardless of the data type it is pointing to..
            this is because it might point to any data type, but it would always store a address

        * * * IMP CONCEPT

        *t = *t + 1     => increments the value to which t is pointing by 1
        t = t + 1       => points to the next value considering the same data type
            ex: if t is of pointer of int data type, it would not point to oldAddress+1 on incrementing by 1,
                instead it would point to oldAddress+4 as int take 4
                thus mostly used to traverse through data structures like arrays
    */

    /*
        for an array, writing array name without index returns address of first element (0th index)
        i.e. &arr[0] is equivalent to arr

        thus int *p = arr
            would create a pointer and make it point to 0th index element of array.
            now doing p++ would point to next element.

        General formula for value at an index:
            arr[i] = *(arr + i)
                bcoz arr would give address of 0th
                so +i for ith index
    */



/*
    * * * specifying size of array (or any other data type) at runtime is BAD PRACTICE
    program has 2 types of memory allocated: stack and heap
    stack = smaller in size, used to allocate memory for compile time elements
    heap = larger in size, used to allocate memory to runtime created elements (created using 'new' keyword)

    Thus,
        instead of using int arr[n] -> use int* arr = new int[n]

        in directly declaring arr[n], all the memory is used from stack
        but in other case, only memory for pointer (8bytes) used from stack, and that ptr will point to array created in heap memory using new keyword

    Allocation of stack memory = static memory allocation
    Allocation of heap memory = dynamic memory allocation

    Disadvantage of dynamic allocation:
        static mei memory apne aap released jab variable a scope ends
        but, in dynamic allocation, you need to manually do that using delete keyword

    Syntax for delete keyword:
        delete ptr; //deletes var
        delete []ptr; //deletes array
*/

// Dynamic memory allocation for 2D array
void dalloc() {
    int r, c;
    int arr[r][c]; // static allocation
    /* VISUALIZE */
    // For dynamic allocation, make array of pointers with number of elements = number of rows
    // and then each pointer will point to linear array with elements = number of columns
    int** ar = new int* [r]; // array of 'r' number of pointers
    for (int i = 0; i < c; i++) {
        ar[i] = new int[c]; // ar[i] is equivalent to *(ar + i)
        // creating an array of length 'c' corresponding to each ptr
    }
    // done creation

    // now, access like normal 2D array ( ar[i][j] )
}



// Macros, global vars and inline functions
    // Macros = used to define a piece of code that would be replaced at each place when the macro name is called
    // macros are made using following syntax:
#define pi 3.14 // ( #define [macro_name] [value_to_be_replaced] )


// global variable = variable declared in global space
// it can be accessed in global space (anywhere in program)
// BUT, bad practice... AVOID using
// nusan = koi bhi change kar sakta hai so 1 func ne modify karne par sabko affect hoga
// instead use reference variable ab bhi variable share karna ho between functions and namespaces


// inline func => used to reduce function calls (thus improving performance)
// function ko inline banane se functon call nahi hogi, and function body would be replaced at each call during compilation.
// readability like funcs, and execution like normal statements
// * * use inline func only for smaller functions, as it would drasticall increase executable size for large func
// generally, aise case mei compiler inline banayega hi nahi



// RECURSION
    // Function calling itself OR function calling another function that calls it back
    // used if a big problems solution can be obtained converting it into smaller problems of same type
    // Ex: 2^4 can be obtained by 2 * 2^3 
    // here, 2^4 is badi problem and 2^3 is choti problem but of same type
    /*
        thus, here the recursive relation is:
        2^n = 2 * 2^(n-1)
        => f(n) = 2 * f(n-1)
    */

    // Recursive function consists of 2 mandatory components: base case, and recursive relation 
    // (other than this their could be additional components like processing etc. based on desired output)
    // base condition = condition jispe function recurse nahi karega and would exit
    // agar base case nahi hogi to func infinite loop mei fasega, calling itself again and again
    // overflow of stack memory, segmentation fault

    // in recursive function, check for base case is always done first... else it would get in infinite loop
    // tail recursion = base case -> processing -> recursive call
    // head recursion = base case -> recursive call -> processing

    //Ex:
int twoKiPower(int n) {
    if (n == 1)
        return 1; // base case

    return n * twoKiPower(n - 1); // recursive relation that we made f(n) = n * f(n-1)
}

// Ex(2):
void fibonacci(int& n, int n1, int n2) {
    if (n == 0)
        return;
    n--;
    cout << n1 + n2 << " ";
    fibonacci(n, n2, n1 + n2);
}

/*
Ques: * * IMP * *
You are standing at 0th stair, and u are given an integer n. Find total number of unique ways to reach nth stair.
You are allowed to climb 1/2 stairs at a time.

Always make recursive relation first..
we are given 'n' so relation would be related to n.
if we reach nth stair, we must have came from n-1 or n-2 th stair.
again for n-1th stair we must have came from (n-1)-1 or (n-1)-2 th stair and so on...
thus f(n) = f(n-1) + f(n-2)

for base condition, check when we need to stop.
here, stop on reaching 0th stair or negative number of stair
thus, +0 ways if it goes negative and +1 ways if it reaches 0th stair (as we need to start from 0, so its valid solution)
*/
// Solution:
int count(int n) {
    if (n == 0) // added this because, its valid way if we reach 0th stair at end
        return 1;
    if (n < 0) // invalid way so + 0
        return 0;
    return count(n - 1) + count(n - 2);
}

// ALWAYS DRAW RECURSION TREE FOR BETTER UNDERSTANDNG OF RECURSION CODE


//Recursion code to spell out a number:
void say(int n) {
    string spell[10] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    if (n == 0)
        return;

    say(n / 10);
    cout << spell[n % 10] << " ";
}
// see carefully, it uses tail recursion as n%10 gives last digit and we want to spell first digit first
// so, recurse first and print its output (isse recursion tree ke end node ka output sabse pehele print hoga and top ka last mei)


// Implementing linear search using recursion:
bool linearS(int arr[], int s, int key) {
    if (s == 0)
        return 0;
    if (arr[0] == key)
        return 1;
    return linearS((arr + 1), s - 1, key);
}

// Implementation of binary search using recursion
bool binS(int* arr, int s, int key) {
    int mid = s / 2;
    if (s == 0)
        return 0;
    if (arr[mid] == key)
        return 1;
    if (arr[mid] > key)
        return binS(arr, (s / 2), key);
    return binS((arr + mid + 1), (s / 2), key);
}

// check palindrome using recursion
bool palindrome(string s, int i = 0) {
    if (s.length() - 1 - i <= 0)
        return 1;
    if (s.at(i) != s.at(s.length() - 1 - i))
        return 0;
    return palindrome(s, i + 1);
}

// Bubble sort using recursion
void bubble(int* arr, int s) {
    if (s == 0 || s == 1)
        return;
    for (int i = 0; i < s - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubble(arr, s - 1);
}
// basic funda of recursion = solve 1 smaller problem and recurse for remaining
// so largest element ko last mei le gaye and recursed for remaining array


// Selection sort using recursion
// selection smallest and swap with first position of unsorted
void selection(int* arr, int s) {
    if (s == 0 || s == 1)
        return;
    int minIndex = 0;
    for (int i = 1; i < s; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }
    swap(arr[0], arr[minIndex]);
    selection(arr + 1, s - 1);
}

// Insertion sort using recursion
void insertion(int* arr, int s, int k = 1) {
    int destinationIndex = k;
    if (s == 0 || s == 1 || k == s)
        return;
    for (int i = 0; i < k; i++) {
        if (arr[i] > arr[k]) {
            destinationIndex = i;
            break;
        }
    }
    for (int i = k; i > destinationIndex; i--) {
        swap(arr[i], arr[i - 1]);
    }
    insertion(arr, s, k + 1);
}


// * * * * * * * VIMP * * * * * * *
// implementing merge sort using recursion (T.C. = O(nlogn))
// merge sort = divide array into sub array unit it has 1 element, then combine while sorting (merge 2 sorted array, classic problem)
// SEE CODE CAREFULLY * * * * 
void mergeSort(int* arr, int s, int e) {
    if (s >= e)
        return;

    // recursively dividing array into 2 parts until it has 2 elements in it
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merger(arr, s, e); // tail recursion to sort array
}

void merger(int* arr, int s, int e) {
    // mid nikalo -> start se mid tak pehela sorted array hoga (bcoz tail recursion se sort karte hue aaye hai) and mid+1 se end tak dusra
    int mid = (s + e) / 2;
    int i = s, j = mid + 1;
    int len = e - s + 1;
    int* sorted = new int[len]; // make new array to merged elements of those 2 arrays in sorted order
    int ins = 0;

    // classic merge 2 sorted arrays problem jaisa same
    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            sorted[ins] = arr[i];
            i++;
        }
        else {
            sorted[ins] = arr[j];
            j++;
        }
        ins++;
    }
    while (i <= mid) {
        sorted[ins] = arr[i];
        i++;
        ins++;
    }
    while (j <= e) {
        sorted[ins] = arr[j];
        j++;
        ins++;
    }

    // copy elements in sorted order to our original array
    for (int i = 0; i < len; i++) {
        arr[s] = sorted[i];
        s++;
    }
    delete[]sorted; // delete dynamically allocated heap memory
}


// Quick Sort
// first element ko uthao and sorted array mei uski jo position hogi vaha rakho (find that using usse chote kitne number hai array mei)
// now swap usse chote wale number before it [so array would be like all elements less than x -> x -> all elements greater than x]
// now repeat the process in both halves
// TC => best case, avg case = nlogn , in worst case = n^2
void quick(int* arr, int n) {
    // base case
    if (n == 0 || n == 1)
        return;
    int pivot = arr[0], count = 0; // set pivot = first element
    for (int i = 1; i < n; i++) {
        if (arr[i] < pivot)
            count++; // count represents number of elements less than it, thus it also shows index of pivot element to be placed
    }
    swap(arr[0], arr[count]);

    int i = 0, j = n - 1;
    while (i < count && j > count) // loop to make all elements b4 pivot less than it, and all elements after it greater than it
    {
        if (arr[i] > pivot && arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        if (arr[i] < pivot)
            i++;
        if (arr[j] > pivot)
            j++;
    }

    quick(arr, count); // recursive call for left part
    quick(arr + count + 1, n - count - 1); // recursive call for right part
}



// * * * Classic question: to find power set (set of all subsets of given array)
// Approach: traverse through each index
// either include that index in output array or else dont (2 recursive calls, 1 excluding and other including)
// do this for all indices and each element to get all 2^n possible subsets
void subsets(vector<int> arr, vector<vector<int>>& res, int index = 0, vector<int> output = {}) {
    // base case
    if (index >= arr.size()) // index = arr.size means we traversed whole array and either included or excluded that element
    {
        res.push_back(output); // push our generated output array to resultant vec and exit that func call
        return;
    }

    subsets(arr, res, index + 1, output); // in first possibility, dont include that specific element and move on to next

    output.push_back(arr.at(index)); // include that element in output and then move on to next
    subsets(arr, res, index + 1, output);
    // (must do include call later, coz we using same array as parameter for both)
}



// Popular interview ques: find all permutations of a given string
// approach => we need to find all permutations i.e. put every char on every place
// for each index belonging to string, swap its value with every char, move index to next pos, recurse same thing
// dry run on paper for better understanding
void perm(string s, vector<string>& res, int index = 0) {
    if (index >= s.length() - 1) {
        res.push_back(s); // base case, push the generated string when index we are swapping reaches end
        return;
    }
    for (int i = index; i < s.length(); i++) // start with 'index' and swap with all elements after it one by one
    {
        swap(s.at(index), s.at(i));
        perm(s, res, index + 1);
        swap(s.at(index), s.at(i)); // back track to prev state of string before swapping again with different index 
    }
}

// VIMP * * * * => solve rat in maze problem by self



// Time and Space Complexity of Recursive algorithms
    /*  Ex:
        int fact(int n){
            if(n == 0)
                return 1;

            return n*fact(n-1);
        }

        Step 1: Try to write the recurrence relation Equation
            Factorial(n) = n * Factorial(n-1)
            Now, if we see carefully, reccursive function has
                base case (that would take constant time, say K)
                recursive call for (n-1)
        Step 2:
            let time required for F(n) = T(n)
            thus, time for F(n-1) = T(n-1)
                F(n-2) = T(n-2)
                and so on...

        Step 3:
            Combining step 1 and 2:
            T(n) = K + T(n-1)

        Step 4:
            T(n) = K + T(n-1)
            T(n-1) = K + T(n-2)
            T(n-2) = K + T(n-3)
            ...
            this will continue till n = 1, bcoz at n=0 it is constant time only (base case)

        Step 5:
            " = " ke right and left mei same value hoge to cancel out - simple maths
            thus, adding all the above equations
            T(n) = n * K = O(n * K) = O(n)

    */

bool binS(int* arr, int s, int key) {
    int mid = s / 2;
    if (s == 0)
        return 0;
    if (arr[mid] == key)
        return 1;
    if (arr[mid] > key)
        return binS(arr, (s / 2), key);
    return binS((arr + mid + 1), (s / 2), key);
}
/*
     Example 2: Binary search

     Recursive Relation:
         T(n) = K + T(n/2)

     thus..
         T(n) = K + T(n/2)
         T(n/2) = K + T(n/4)
         T(n/4) = K + T(n/8)
         ...
     this will continue till worst base case (as we are finding worst TC)..
     Now, kisi bhi number 'n' ko half karte karte 1 tak laane mei 'log n' attempts lagte hai

     hence, above equations will be present log n times
     thus,
         T(n) = K * logn = O(log n)
*/
 /*
     * * * * Ex 3: Merge Sort (See algo along, to get idea)
     let,
         K = constant time for processing in algo
         T(n/2) = time fr recursive call for half of the array
         X = time for merger function
     Recursive Relation:
         T(n) = K + T(n/2) + T(n/2) + X
             = K + 2T(n/2) + X

     thus
         T(n) = K + 2T(n/2) + X
         T(n/2) = K + 2T(n/4) + X
         T(n/4) = K + 2T(n/8) + X
         ...

     Multiply each equation, except first on both LHS and RHS
         T(n) = K + 2T(n/2) + X
         2T(n/2) = 2K + 2*2T(n/4) + 2X -> multipled 2
         4T(n/4) = 4K + 4*2T(n/8) + 4X -> multiplied 4
         ...

     therefore,
         K will occur logn times and will be multiplied with some other constant, say P
         X will occur logn times and will be multiplied with some other constant, say Q
         T(n) = K*P*(logn) + X*Q*(logn)
     eliminating constants:
         T(n) = (logn) + X(log n)
     now, we know, X is TC of merger function, which is O(N) -> because it has just one loop to traverse and merge
     thus,
         T(n) = O(logn) + O(n logn)
             = O(n logn)
 */
 /*
     Ex 4: Fibonaci Series * * *
     Method 1:
     void fibonacci(int &n, int n1, int n2)
     {
         if (n == 0)
             return;
         n--;
         cout << n1 + n2 << " ";
         fibonacci(n, n2, n1 + n2);
     }
     T(n) = K + T(n-1) => O(n) as we saw earlier

     Method 2:
     int fib(int n) {
         if (n == 0 || n == 1)
             return n;
         return fib(n-1) + fib(n-2);
     }
     T(n) = K + T(n-1) + T(n-2)
     T(n-1) = K + T(n-2) + T(n-3)
     T(n-2) = K + T(n-3) + T(n-4)
     ...
     In this case we cant cancel ut the functions of 'T'

     So, ALTERNATE METHOD THAT WORKS IN THIS TYPE OF SITUATION: * * *
     Consider a recursion tree for the algo
     each node requires constant time (K) - time f function excluding recursive call)
     and its recursive calls are depicted by its childs
     For above ques, Recursive tree would look like: (ex inp: 3)
                         3
                        / \
                      2    1
                     / \
                    1   0

     thus, 0th level would have 1 node, 1st would have 2, then 4 and so on...
     similarly: nth level will have 2^n nodes
     In worst case, the largest depth = leftmost depth in above example (when we subtract just 1 each time)
     thus, maximum levels = n

     total nodes = nodes in level 0 + nodes in level 1 + ...
                 = 2^0 + 2^1 + 2^2...+ 2^n
                 = 2^(n+1) - 1

     Now we have number of nodes, and each node need time K
     thus,
         T(n) = K * number of nodes
             = K * 2^(n+1) -1
             = K * 2^n * 2 - 1
         eliminating constants:
         T(n) = O(2^n)
 */


/*
     Space Complexity: maximum space required at an time instant
     - See space we are allocating
     - See Recursive stack space
     see how many instance of recursive func would be running at once * space required by each

     Ex:
         int factorial(int n)
         {
             if(n==0)
                 return 1;
             return n * factorial(n-1);
         }
         here, at a time n func instances would be running and each would require const space 'k'
         thus space complexity => O(k*n) => O(n)


         In binary search: at a time 'a' instances, i.e. logn instances and const space 'k' for each
         thus S.C => O(logn*k) => O(logn)

         merge sort (see algo):
         space in func = K+n
         number of runs = logn
         thus, S.C => O(n + logn)
         also, n >>>>> logn
         therefore, S.C. => O(n)
 */



// OOPS Concepts
    // generally, sizeof(object) = sum of size of variables it has
    // But, if it has '0' vars (i.e. empty class), then it is assigned 1 byte of memory to keep a track on it
    // THOUGH, this is not necessary, sometimes sizeof(object) > sum(sizeof(var)) [bcoz some padding might be added]
    // padding is the addition of some empty bytes of memory in the structure to naturally align the data members in the memory.
    // This is done to reduce cpu read cycles while accessing data members

    // 3 types of access modifiers (public, private, protected)

    // '->' is equivalent to dereferencing and then accessing member using '.' operator [used while dynamic allocation]

    /*
        Constructor:
            invoked while object creation
            no return type
            name same as class name
            always public
    */

    // 'this' keyword stores address of current object [thus, we could access member methods and variables using "this->"]
    // it stores address of object so, it is pointer to object

    // copy constructor = constructor that takes reference to object of same class as input and copies its value to new object
    // when we define a custom copy constructor, default copy constructor set by compiler is destroyed

    // Shallow copy and Deep copy
        // Shallow copy copies the value as it is
        // thus if a pointer member is pointing to some var (say string containing name), it would copy same address to pointer of other object
        // This would cause change in name of both object if one is changed, because both pointer are pointing to same memory location
        // Default copy constructor uses shallow copy

        // Deep copy fixes this issue
        // This is done by first copying the data (say name) to a different location (by creating new string and coping it their)
        // and then assigning the value of 2nd objects pointer to point that address
        // so both objects would have different address to store data

        // we could use '=' to copy all data members values from 1 object to other (copy assignment operator)


    // Destructor = function/method called when object is of no use and about to go out of scope
    // destructor helps in deallocating the memory
    // Statically created objects [ class_name obj; ] ke liye destructor automatically call hoga (bcoz vo delete bhi to automatically hote hai)
    // Dynamically created objects [ class_name *a = new class_name(); ]
    // inke case mei it is called when we manually delete object (bcoz vo automatically delete nahi hote)


    // 4 Pillars of OOPS:
    /*
        1) Encapsulation : wrapping up data members (properties) and functions (methods)
            we take some data members and functions and encapsule them to form a class. That is encapsulation.
            Fully Encapsulated class => class in which all data members are private
        * * * Encapsulation = information hiding & Abstraction = Implementation hiding

        2) Inheritance: ability of a class to derive properties and characteristics from another class
        syntax:
            class child_class : access_modifier parent_class{
                // body of class
            };

        3) Polymorphism (many forms): ability of an entity to exist in multiple forms
            2 types: compile  time (aka static polymorphism), run time (aka dynamic polymorphism)

            Compile Time can be further divided as: function overloading, operator overloading
            In operator overloading, suppose a + b and we want to overload it to perform subtraction
            syntax:
                return__type operator + (input)
                {
                    // code
                    // for a+b a is object for which function is called and b is given as input [thus use this-> to access members of 'a']
                }
            * * not all operators can be overloaded [like scope resolution operator]

            Runtime polymorphism: (runtime par hi pata chalega ki kisi entity ka konsa form use hoga)
                it consists of method overriding
            Function overriding happens only when we inherit a class and both parent and child class have function/method with same name and paramters
            Thus, runtime polymorphism is dependent on inheritance

            Suppose, there is parent class animal having function voice which outputs "speaking".
            And there's a derived class Dog having same func voice but it outputs "barking".
            Now, if we make function of class dog then it prints "barking" as function with same name is available in its own class (nahi hota to "speaking")


        4) Abstraction: Implementation hiding
            Hiding implementation partially or fully by using access modifiers and setting data members and methods as private or protected
    */



// Linked List and its types
    // type of linear data structure formed by collection of nodes
    // each node is combination of data, and address of next node (stored in pointer)
    // It is a type of dynamic data structure (can be grown or shrunk at runtime)
    // Insertion/Deletion => easier than array
    // Does not require continuous storage allocation

    /*
        Types of linked list:
            singly linked list (data and ptr to next node)
            doubly linked list (data and ptr to both prev and next node)
            Circular linked list (singly + last element again points first)
            Circular doubl linked list (doubly + last element again points first)
    */

    // Implementing a singly linked list:
class Node {
public:
    int data;
    Node* next; // pointer to next node

    Node(int data) // constructor
    {
        this->data = data;
        this->next = NULL;
    }
};

// Inserting data to front of linked list:
void insertFront(Node*& head, int data) // takes pointer to head node (took reference var too to avoid new var creation) and value to insert at input
{
    Node* tmp = new Node(data);
    tmp->next = head;
    head = tmp;
}

// Printing linked list:
void printList(Node*& head) // take reference pointer to head node as input
{
    Node* tmp = head; // copy value of it to temp, i.e. create a local variable that points head in beginning for traversal
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// * * Similarly use tail ptr for inserting at tail

// Inserting in between
void insertAt(Node*& head, int pos, int data) // pos = position at which insert karna hai
{
    Node* tmp = head;
    for (int i = 0; i < pos - 2; i++)
        tmp = tmp->next;
    // After execution of this for loop, tmp will point to pos-1 th node
    // we need to insert at pos... so ptr(pos-1) points new node & ptr(newNode) points node at pos (before insertion) [visualize]

    Node* n = new Node(data);
    n->next = tmp->next;
    tmp->next = n;
}
// This doesnt work for insertion at first and last and ma give error if position exceeds list size (could be fixed using conditional if's )
// like, if pos == 1 then call insertFront function

// For deleting a Node, make its prev node point to its next node
// make a ptr to nde that we are deleting before this, and then use that pointer to deallocate dynamic memory using delete keyword
// MUST write a destructor to convey what happens on deleting a node


// Implementing Doubly Linked list:
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node() {
        this->next = NULL;
        this->prev = NULL;
        int d = this->data;
        delete next;
        delete prev;
        cout << "DC called for " << d << endl;
    }
};

// Inserting at head
void insertAtHead(Node*& head, int data) {
    Node* tmp = new Node(data);
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
}

// Printing list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Get length of doubly linked list
int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// * * Inserting at any given position in doubly linked list
void insertAt(int pos, Node* head, int data) {
    if (pos == 1) // insert head
    {
        insertAtHead(head, data);
    }
    else if (pos > getLength(head) + 1) // out of indexing order
    {
        cout << "Cannot insert at invalid index" << endl;
    }
    else {
        // inserting in between
        Node* back = head;
        int count = 1;
        while (count < pos - 1) {
            back = back->next;
            count++;
        }

        // creating new object for element
        Node* tmp = new Node(data);

        // connecting
        tmp->next = back->next;
        tmp->prev = back;
        if (pos != getLength(head) + 1)
            (back->next)->prev = tmp;
        // dont execute this statement if inserting at back bcoz back->next = NULL & accessing NULL->prev means segmentation fault
        back->next = tmp;
    }
}

// Delete node
void deleteNode(Node*& head, int pos) {
    Node* tmp = head;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
    }
    // Now tmp is the node to be deleted
    if (pos > getLength(head)) // Out of index
    {
        cout << "Cannot delete a node that doesn't exist!" << endl;
    }
    else if (tmp->prev == NULL) // tmp is head
    {
        head = tmp->next;
        head->prev = NULL;
    }
    else if (tmp->next == NULL) // tmp is tail
    {
        tmp->prev->next = NULL;
    }
    else {
        (tmp->next)->prev = tmp->prev;
        (tmp->prev)->next = tmp->next;
    }

    // deleting node
    delete tmp; // see constructor for what happens on calling this
}


// Circular linked list
    // Node structure same as singly linked list, just last node points again to first one
    // Thus, we dont need both haid and tail pointer, bcoz head would be tail->next
    // Also, insertion at head = insertion at tail



// Classic Linked list ques:
/*
    Reverse a singly linked list:
    suppose we have list a->b->c we need to reverse it and make c->b->a
    thus, we actually need to make a<-b<-c
    i.e. each element point its back element from original list & head = previous tail
*/
// Iterative solution
void reverseList(Node*& head) {
    Node* back = NULL;
    Node* current = head;
    Node* front = head->next;

    if (head == NULL || head->next == NULL) // empty list or list with 1 element
        return;

    while (current != NULL) {
        current->next = back;
        back = current;
        current = front;
        if (front != NULL)
            front = front->next;
    }
    head = back;
}
// Recursive solution
void reverseRecurse(Node*& head, Node* back, Node* current) {
    if (current == NULL) {
        head = back;
        return;
    }
    Node* front = current->next;
    current->next = back;
    reverseRecurse(head, current, front);
}


// Middle of linked list
// We need to find mid node of linked list
// Naive approach: iterate through list to find its length and hence find pos of mid node. Then iterate again to find its value.
// Optimised Approach: create 2 pointers, one of them woud move 2 nodes front at a time and other would move 1


// Reverse a singly linked list in groups of 'K' elements
    // approach: use recursion to reverse last k element grp, and return its head
    // use that head as back fr prior group and do same for each grp
    // base case: head=null or else k element grp not possible (if last few elements cant form group, have to embed them in same order)
    // * * * * * IMP (Amazon, Paypal, MakeMyTrip, etc)
Node* kReverse(Node* head, int k) {
    if (head == NULL)
        return NULL;
    int a = 1;
    Node* s = head;
    Node* e = s;
    while (e->next != NULL && a != k) {
        e = e->next;
        a++;
    }
    if (e->next == NULL && a != k)
        return s;
    Node* back = kReverse(e->next, k);
    while (s != e) {
        Node* front = s->next;
        s->next = back;
        back = s;
        s = front;
    }
    s->next = back;
    return s;
}


// Detect loop in linked list
    // approach: create a map with [key, value] pair = [Node* , bool]
    // Node* = address and bool represents if its visited

    // METHOD 2: Floyds cycle detection algorithm
    // 2 pointers slow(1 step) and fast(2 step) at head of list in beginning
    // dono ko chalo ab... if fast reaches NULL, theres no loop
    // if slow = fast again after some iterations, there's a loop

// Remove Duplicates in a sorted list
    // Simply, if a->data = a->next->data 
    // then a->next = a->next->next
    // O(n)

// Remove Duplicates in unsorted linked list
    // Approach 1:
        // dual for loop
        // for first occurence of each element, remove all other occurences of that element
        // O(n^2)
void delNode(Node* head, int val) {
    if (head == NULL || head->next == NULL)
        return;
    if (head->next->data == val) {
        head->next = head->next->next;
        delNode(head, val);
    }
    else
        delNode(head->next, val);
}
Node* removeDuplicates(Node* head) {
// your code goes here
    Node* t = head;
    while (t != NULL) {
        delNode(t, t->data);
        t = t->next;
    }
    return head;
}

// Approach 2:
    // Sort linked list first O(n logn)
    // Previous method O(n)
    // O(n logn)
    // But, this wont maintain their order

// Approach 3:
    // Can be solved using map/set (unordered, to maintain order) in O(n), but then Space complexity also changes from O(1) to O(n)
Node* insertList(Node* head, int data) {
    Node* t = head;
    Node* tmp = new Node(data);
    if (t == NULL) {
        head = tmp;
        return head;
    }
    while (t->next != NULL) {
        t = t->next;
    }
    t->next = tmp;
    return tmp;
}
Node* removeDuplicates(Node* head) {
// your code goes here
    unordered_set<int> s;
    Node* t = head;
    Node* res = NULL;
    Node* lastPtr = NULL;
    while (t != NULL) {
        if (s.find(t->data) == s.end()) {
            lastPtr = insertList(lastPtr, t->data);
            if (res == NULL)
                res = lastPtr;
        }
        s.insert(t->data);
        t = t->next;
    }
    return res;
}



// Sort 0s 1s 2s in Linked list
    // Approach 1:
        // using additonal space O(n)
        // TC: o(n logn)
Node* ins(Node* l, int data) {
    Node* tmp = new Node(data);
    if (l != nullptr) {
        l->next = tmp;
    }
    return tmp;
}
Node* sortList(Node* head) {
    vector<int> v;
    while (head != nullptr) {
        v.push_back(head->data);
        head = head->next;
    }
    sort(v.begin(), v.end());
    Node* res = NULL;
    Node* tail = NULL;
    for (auto i : v) {
        tail = ins(tail, i);
        if (res == nullptr)
            res = tail;
    }
    return res;
}

// Approach 2:
    // swap nodes, custom sort algo

// Merge 2 sorted linked list
    // Approach 1: 
        // Push both to vec, sort, create
        // TC: O(n logn)    SC: O(n)


    // Approach 2:
        // Ek list se uthao, dusre sorted mei insert karo bich mei
        // TC: O(n)     SC: O(1)
Node* ins(Node* l, Node* i) {
    if (l->data > i->data) {
        i->next = l;
        return i;
    }
    Node* head = l;
    while (l->next != NULL) {
        if (l->data <= i->data && l->next->data > i->data) {
            Node* tmp = l->next;
            l->next = i;
            i->next = tmp;
            return head;
        }
        l = l->next;
    }
    l->next = i;
    i->next = nullptr;
    return head;
}
Node* mergeTwoLists(Node* list1, Node* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;
    while (list2 != nullptr) {
        Node* fe = list2->next;
        list1 = ins(list1, list2);
        list2 = fe;
    }
    return list1;
}

// Approach 3:
    // Create new list
    // Two pointer approach
    // SC: O(n)   TC: O(n)


// Check if Linked list is a Palindrome
    // Approach 1:
    // Convert to array, check normal palindrome
    // TC: O(n)     SC: O(n)

    // Approach 2:
    // Find mid, reverse list after mid, increment head & mid together to verify
    // TC: O(n)     SC: O(1)
Node* findMid(Node* head) {
    Node* fast = head;
    Node* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == nullptr)
        return slow;
    return slow->next;
}

Node* revList(Node* back, Node* curr, Node* front) {
    curr->next = back;
    if (front == NULL)
        return curr;
    return revList(curr, front, front->next);
}
bool isPalindrome(Node* head) {
    if (head->next == NULL)
        return 1;
    Node* head2 = findMid(head);
    head2 = revList(nullptr, head2, head2->next);
    while (head != nullptr && head2 != nullptr) {
        if (head->data != head2->data)
            return 0;
        head = head->next;
        head2 = head2->next;
    }
    return 1;
}



// Add two numbers represented by linked list
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in * * reverse order * *, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list (reverse).
// Ex: {5, 4, 3} and {5, 4} gives {0, 9, 3} 
// because, 345 + 45 = 390

    // Approach:
    // add from head, maintain carry = sum/10, and value of each node = sum%10
Node* insertTail(Node* tail, int data) {
    Node* tmp = new Node(data);
    if (tail == nullptr)
        return tmp;
    tail->next = tmp;
    return tmp;
}

int adder(Node*& tail, int carry, int a = 0, int b = 0) {
    tail = insertTail(tail, (a + b + carry) % 10);
    return (a + b + carry) / 10;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* tail = nullptr;
    Node* head = nullptr;
    int carry = 0;
    while (l1 != nullptr && l2 != nullptr) {
        carry = adder(tail, carry, l1->data, l2->data);
        l1 = l1->next;
        l2 = l2->next;
        if (head == nullptr)
            head = tail;
    }
    while (l1 != nullptr) {
        carry = adder(tail, carry, l1->data, 0);
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        carry = adder(tail, carry, l2->data, 0);
        l2 = l2->next;
    }
    while (carry != 0)
        carry = adder(tail, carry, 0, 0);
    return head;
}


// Create clone of linked list with random ptr
// You are given a linked list in which each node has an additional random ptr
// random ptr may either point null or to some random node in the list 
// we need to create a clone of given list
    // Approach 1:
    // Create map<int, vector<int>> and store each
    // then replicate
    // TC: O(n)     SC: O(n)

    // Approach 2:
    // suppose List is as follows:
    // 1 -> 2 -> 3 -> 4
    // |         |
    // \---------/
    // Create new node after each existing node
    // list => 1 - 1 - 2 - 2 - 3 - 3
    // now, for each node, node->next is its new version
    // so do node->next->random = node->random->next
    // * * * Understand Carefully * * *
    // At end, remove old nodes
    // TC: O(n)     SC: O(1)



// Stacks
// Follows LIFO - last in first out
// Major methods: push, pop, top, empty, size

// Reverse a string using stack
char* reverse(char* S, int len) {
    stack<char> st;
    for (int i = 0; i < len; i++)
        st.push(S[i]);
    char* ans = new char[len + 1];
    int i = 0;
    while (!st.empty()) {
        ans[i++] = st.top();
        st.pop();
    }
    ans[i] = '\0';
    return ans;
}


// Delete middle element from stack
    // using vec to store upper elements
    // TC: O(n)     SC: O(n)
void deleteMid(stack<int>& s, int sizeOfStack) {
    int len = s.size();
    vector<int> v;
    for (int i = 0; i < (len / 2); i++) {
        v.push_back(s.top());
        s.pop();
    }
    s.pop();
    for (int i = v.size() - 1; i > -1; i--)
        s.push(v[i]);
}

// using recursion * * *
void deleteMid(stack<int>& s, int sizeOfStack, int index = 0) {
    int t = s.top(); // store top
    if (index == sizeOfStack / 2) {
        s.pop(); // base case, pop 1 extra on reaching required and return
        return;
    }
    s.pop(); // if not base case, pop 1
    deleteMid(s, sizeOfStack, index + 1); // recurse for remaining
    s.push(t); // after recursing in whole recursion stack, and deleting required element, push the stored element back
}
// TC: O(n)     SC: O(N) (because of recursive calls being pushed to recusion stack)


// Valid Parenthesis
// Check if a given expression is a valid expression of parenthesis
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() &&
            ((st.top() == '(' && c == ')') ||
                (st.top() == '{' && c == '}') ||
                (st.top() == '[' && c == ']'))) {
            st.pop();
        }
        else
            st.push(c);
    }
    return (st.empty()) ? 1 : 0;
}

// Insert at bottom of stack
// use recursion
// pop elements until stack is empty using tail recursion.. insert element and then push each element back
void solve(stack<int>& s, int& x) {
    if (s.empty()) {
        s.push(x);
        return;
    }
    int tmp = s.top();
    s.pop();
    solve(s, x);
    s.push(tmp);
}
// TC: O(n)     SC: O(n)


// * * * sort elements in a stack
// recurse to make stack empty
// now push elements in sorted order
void pushSorted(stack<int>& s, int data) {
// similar to push at bottom, see logic
    if (s.empty() || (!s.empty() && s.top() <= data)) {
        s.push(data);
        return;
    }
    int tmp = s.top();
    s.pop();
    pushSorted(s, data);
    s.push(tmp);
}
void sortStack(stack<int>& s) {
    // main sorting func, removes all elements and calls pushSorted to push them back in sorted manner
    if (s.empty()) {
        return;
    }
    int tmp = s.top();
    s.pop();
    sortStack(s);
    pushSorted(s, tmp);
}
// TC: O(N^2)      SC: O(N)
// * * * ALWAYS ALWAYS DRAW A RECURSIVE CALL STACK FOR SC
// Here, we might think 2 functions have recursive stack depth of n, and they are nested.. so SC=O(n^2) 
// but pushSorted function only uses the stack space that gets unwinded by sortStack function
// so max stack depth never exceeds n


// Monotonic stack = stack in which element are only stored in strictly increasing/decreasing order

// Next Smaller Element
    // Given an integer array 'A' of length 'n'
    // Find next smaller element for each element in A
    // Ex: A = [2, 3, 1] => ans = [1, 1, -1]
        // thus, for every element, uske baad aane wala usse chota 1st number is answer
    // can be solved using 2 nested loops -> O(n^2)

// Optimised approach: TC: O(n)
    // Observe carefully, for every number, uske baad ka 1st smallest matters, baaki se lena dena nahi
    // how about, traversing from end
        // and, store elements in strictly increasing order 
        // bcoz har number ke liye, smaller milne ke baad usse chote/bade hoge to bhi no significance

        // imagine this: if traversing from back..
            // if we go from y <- x
            // (y > x) -> x is first smallest
            // (y < x) -> our stack has elements in increasing order so we will pop until we get element smaller than x
                // In this case, we will also store x

        // IMP * * * * * Ex: [3, 6, 5, 2]   stack= []   ans = []
        // for 2:
            // stack empty so push -1 is ans (bcoz next smallest doesnt exist)
            // ans = [-1]
            // stack = [2]      
        // for 5:
            // stack top = 2 < 5 => ans = [-1, 2]
            // stack = [2, 5]
        // for 6:
            // stack top = 5 < 6 => ans = [-1, 2, 5]
            // stack = [2, 5, 6]
        // for 3:
            // stack top = 6 > 3
            // we need smaller so pop until top <= 3 (popped and only 2 remain in stack)
            // ans = [-1, 2, 5, 2]
            // stack = [2, 3] .... * * * notice here, we lost the values 5 & 6 BUT doesnt matter bcoz we need first smallest
                // and, both 5, 6 are greater than 3.. so 3 milne ke baad unki no need

        // thus, ans = [-1, 2, 5, 2] -> reverse it

    // Code:
vector<int> nextSmallerElement(vector<int>& arr, int n) {
    vector<int> ans;
    stack<int> s;
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() >= arr[i])
            s.pop(); // pop until top < arr[i]
        if (s.empty())
            ans.push_back(-1); // element nahi mila to -1
        else
            ans.push_back(s.top()); // element mila to  ans
        s.push(arr[i]); // push new element in stack (as it would be by default > top)
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
// TC: O(n)
    // Primary intuition may be that nested loops so its O(n^2)
    // But, think abit, the while loop wont run always
    // it only pops each element once in whole code
    // thus, it would be n + n.. not n * n
// SC: O(n)



// Largest Rectangular area in Histogram (bar graph types)
    // we are given an array representing height of histgram's bars
    // we need to find the largest rectangular area

// Approach 1:
    // for each bar, count number of consecutive bars after it, that have height <= curr bar
        // this way we could get max width of rectangle for each bar
    // area = length * width = height of curr bar * max width obtained
    // TC: O(n^2)

// Approach 2:
    // Imagine:
        // In histogram, largest rectangle consisting any bar can formed by:
            // that bar + consecutive neighbouring bars until height of consecutive neighbour is less than curr bar height
                // try this on pen-paper.. no other rectangle can be formed with higher area
    // Thus, we could maintain a maxArea var, and do this operation for each bar:
        // find index previous smaller element
        // find index of next smaller element
        // calc area, compare it with maxArea variable

    // To optimise, we could traverse just once and store indices of next, prev small in vec
    // * * * * VVIMP, SEE CAREFULLY :
vector<int> nextValidIndices(vector<int>& heights) {
// monotonic increasing stack, backward traverse
// we dont need values, we need first and last valid indices for each bar
    stack<int> s; // stack stores indices 'i' according to increasing order of heights[i]
    vector<int> ans;
    for (int i = heights.size() - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        if (s.empty())
            ans.push_back(heights.size() - 1);
        else
            ans.push_back(s.top() - 1); // top would give index of 1st smallest, so top-1 will give last valid index for area
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> prevValidIndices(vector<int>& heights) {
// monotonic increasing stack, traverse from start
    stack<int> s; // stack stores indices such that height[i] is monotonic (stack isnt)
    vector<int> ans;
    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();
        if (s.empty())
            ans.push_back(0);
        else
            ans.push_back(s.top() + 1);
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    vector<int> prev = prevValidIndices(heights);
    vector<int> next = nextValidIndices(heights);

    for (int i = 0; i < heights.size(); i++) {
        int height = heights[i];
        int width = next[i] - prev[i] + 1;
        if (height * width > maxArea)
            maxArea = height * width;
    }
    return maxArea;
}
// TC: O(n)     SC: O(n) 



// The Celebrity Problem
    /*
        A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

        Input: mat[][] = [[0 1 0],
                        [0 0 0],
                        [0 1 0]]
        Output: 1
        Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.
    */

    // Approach 1: Brute force
        // if for any number i, row[i] sum = 0 & column[i] sum = n-1, then 'i' is celebrity
        // Can be solved using nested loops in O(n^2)

    // Approach 2:
        // It is guaranteed that there would be either 1 celebrity or 0
        // Put all element in stack
        // pop 2, say A and B
        // if A knows B -> A is not a celebrity, remove it, push other
        // thus, in every operation, at least 1 element is removed
        // do this until stack has 1 element (possible celeb)
        // validate celeb by checking if everyone knows him but he knows none
int celebrity(vector<vector<int> >& mat) {
    stack<int> s;
    for (int i = 0; i < mat.size(); i++)
        s.push(i);
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (mat[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }
    int celeb = s.top();
    // Validation
    for (int i = 0; i < mat[celeb].size(); i++) {
        if (i == celeb)
            continue;
        if (mat[celeb][i] == 1 || mat[i][celeb] == 0)
            return -1;
    }
    return celeb;
}
// TC: O(n)     SC: O(n)



// Largest Rectangular area made by 1's in a binary matrix
    /*
        Given a binary matrix, find the largest rectangle containing only 1's and return its area
        Input:
        0 1 1 0
        1 1 1 1
        1 1 1 1
        1 1 0 0
        Output :
        8
    */
    // Must know largest area in histogram to solve this * * * * *
    // bcoz this ques can be divided into it as sub-problem
    // Approach:
    // traverse for each row from 0 - (n-1)
    // consider current row as base and calculate max height (base se upar first 0 encounter hone tk)
    // we will get an array of heights, apply largestArea in histogram on this.. and store it in maxHeight
    // do this for all rows and update maxHeight

    // if we consider base and then try to calculate histo, it takes O(n^2)
    // better to start from first row and store previous histo
    // easy way for histo:
void makeHistogram(vector<char>& row, vector<int>& prevHisto) {
    for (int i = 0; i < row.size(); i++) {
        if (row[i] != '0') // if base is not 0, increase histo height for current level as well as further levels
            prevHisto[i]++;
        else
            prevHisto[i] = 0; // if base is 0, make histo height = 0 for current as well as further levels
    }
}
vector<int> prevValidIndices(vector<int>& hist) {
    vector<int> ans;
    stack<int> s;
    for (int i = 0; i < hist.size(); i++) {
        while (!s.empty() && hist[s.top()] >= hist[i])
            s.pop();
        if (s.empty())
            ans.push_back(0);
        else
            ans.push_back(s.top() + 1);
        s.push(i);
    }
    return ans;
}
vector<int> nextValidIndices(vector<int>& hist) {
    vector<int> ans;
    stack<int> s;

    for (int i = hist.size() - 1; i >= 0; i--) {
        while (!s.empty() && hist[s.top()] >= hist[i])
            s.pop();
        if (s.empty())
            ans.push_back(hist.size() - 1);
        else
            ans.push_back(s.top() - 1);
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int maximalRectangle(vector<vector<char>>& matrix) {
    int maxArea = 0;
    vector<int> hist(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
        // cout << "considering row " << i << endl;
        makeHistogram(matrix[i], hist);
        vector<int> prev = prevValidIndices(hist);
        vector<int> next = nextValidIndices(hist);
        for (int j = 0; j < hist.size(); j++) {
            int height = hist[j];
            int width = next[j] - prev[j] + 1;
            // cout << "area = " << height << "*" << width << " = " << height*width << endl;
            if (height * width > maxArea)
                maxArea = height * width;
        }
    }
    return maxArea;
}
// TC: O(rows * columns) => O(n * m)    SC: O(m)
// n = rows,    m = columns


// 2 stack in a array
    // Use an array data structure to implement 2 stacks
    // Approach:
        // make a stack, consider one stack from its front end and other from back
        // If end.top - 1 = start.top => stack full

// N stack in a array * * *
    // Use a single array to implement 'N' stacks
    // Approach:
        // Suppose length of array = K
        // divide array N parts.
        // thus, we would get N stacks of size 'K/N'
        // BUT, this approach is not Space Optimised
        // (it is possible ki 1 stack full ho jaye and other one is completely empty)


    // Approach 2:
        // Make another array of length 'N' (say 'top') (to store top of each of the 'N' stacks)

        // Also, make an array of size (say 'K') = combined buffer for all stack
            // Let, this array be 'info[]'
            // now.. info has 2 functions:
                // 1. size of arr and info is same.. so if arr[i] holds some data, info[i] would point to previous element in the same stack
                // 2. if arr[i] does not hold data (i.e. it's an empty space), info[i] would point to the next empty space

        // And, maintain a variable 'freespot' to store first free space

        // Using this, the push and pop operations could be done as follows:
            // Initialise top[] = -1
            // At beginning whole array is empty.. thus, info[0] = 1, info[1] = 2 and so on.. (next empty space)
                // BUT, info[lastIndex] = -1 bcoz theres no empty space after lastIndex
            // freeSpot = 0 (bcoz whole array is free)

        // On push operation in stack 'P':
            // if freeSpot = -1, overflow
            // arr[freeSpot] = value    // occupy free spot with value
            // int nextFreeSpot = info[freeSpot] // temporarily store next empty space
            // info[freeSpot] = top[P]  // make info[i] point to prev element
            // top[P] = freeSpot    // set top = index of currently stored
            // freeSpot = nextFreeSpot   // Update freeSpot to next empty space

        // On pop operation in stack 'P':
            // int indexToPop = top[P]
            // if indexToPop == -1, underflow
            // arr[indexToPop] = -1     // vacant the space
            // top[P] = info[indexToPop]    // bcoz info[indexToPop will store index of prev element in that stack]
            // info[indexToPop] = freeSpot  // no element at that index now, so store next free space
            // freeSpot = indexToPop

class NStack {
public:
    vector<int> arr;
    vector<int> top;
    vector<int> info;
    int freeSpot = 0;
    NStack(int N, int S) {
        // Constructor
        arr = *(new vector<int>(S, -1));
        top = *(new vector<int>(N, -1));
        info = *(new vector<int>(S, -1));
        for (int i = 0; i < S - 1; i++)
            info[i] = i + 1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        if (freeSpot == -1)
            return 0;
        arr[freeSpot] = x;
        int nextFreeSpot = info[freeSpot];
        info[freeSpot] = top[m - 1];  // did m - 1 bcoz top is 0 indexed and our input isnt
        top[m - 1] = freeSpot;
        freeSpot = nextFreeSpot;
        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        if (top[m - 1] == -1)
            return -1;
        int indexToPop = top[m - 1];
        int poppedElement = arr[indexToPop];
        top[m - 1] = info[indexToPop];
        info[indexToPop] = freeSpot;
        freeSpot = indexToPop;
        return poppedElement;
    }
};


// Design a special stack that supports push, pop, top, and retrieving the minimum element.
// i.e. we could get minElement of elements present
    // Approach 1:
        // Create a new stack to store corresponding min
class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {}
    void push(int val) {
        s.push(val);
        if (mins.empty())
            mins.push(val);
        else
            mins.push(min(val, mins.top()));
    }

    void pop() {
        if (s.empty())
            return;
        s.pop();
        mins.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return mins.top();
    }
};
// TC: O(1)     SC: O(n)


// Approach 2: * * *
// To solve in O(1) space, make var 'mini' to store minimum
// Keep pushing elements normally... 
    // BUT if we get new mini element,
    // Dont push normal element to stack
    // Instead, push 2*currentElement - prevMini
    // let currElement = x
    // thus, pushedElement = 2*x - prevMini * * *
    // also, x would be stored in mini, as we encountered new mini

// While Popping
    // Pop normally when current is greater than mini
    // If, current is less than mini, we have encountered our changed value (i.e. pushedElement)
    // As we know.. pushedElement = 2*x - prevMini
    // prevMini = 2*x - pushedElement * * *

// Basically,
    // While pushing: push a = 2*element - mini & set mini = element
    // Now while popping, we have element(in mini), a in stack top... so we could get prevMini by rearranging formula

// THESE 2 FORMULAS SOLVE WHOLE PROBLEM BY PROVIDING RELATION BETWEEN PREV AND CURRENT MINI

class MinStack {
public:
    stack<long> s;  // usual stack
    long mini;  // to store minimum till realtime top
    void push(int val) {
        if (s.empty()) {    // 0 elements, normal push
            s.push(val);
            mini = val;
            return;
        }
        if (val >= mini)    // no change in minimum value, normal push
            s.push(val);
        else {
            s.push((2 * long(val)) - mini);     // new minimum found, push encoded value & update mini
            mini = val;
        }
    }
    void pop() {
        if (s.empty())
            return;
        if (s.top() >= mini) {  // normal pop, bcoz top isnt our encoded values (encoded value is always less than mini)
            s.pop();
            return;
        }
        mini = 2 * mini - s.top();  // encoded value found, update mini
        s.pop();
    }
    int top() {
        if (s.top() >= mini)
            return s.top();     // top value normal, return
        return mini;    // top value encoded, normalValue = mini
    }
    int getMin() {
        return mini;
    }
};


// Queues
    // Follows FIFO
    // Enqueue: Adding element to queue
    // Dequeue: Removing element from queue

    // Circular queue = special type of queue in which last element points back to the first

    // Dequeue (aka double ended queue): special type of queue which allows adding and removing elements from both ends


// STL Methods:
    // queue<int> q;    // for normal queue
    // deque<int> dq;   // for dequeue


// Reverse a given STL queue
    // given is a STL queue, thus we could just pushBack and popFront (and ofc, access or see both front and back element)

// Approach 1
    //  Create a stack -> push elements frm queue to stack (from front bcoz thats only way of removing from queue)
    // Stack would contain elements in reverse order, pop top and pushBack in queue
queue<int> rev(queue<int> q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}
// TC: O(n)     SC: O(n)

// Approach 2:
    // Using recursive stack
void solve(queue<int>& q) {
    if (q.empty())
        return;
    int tmp = q.front();
    q.pop();
    solve(q);
    q.push(tmp);
}
queue<int> rev(queue<int> q) {
    solve(q);
    return q;
}
// TC: O(n)     SC: O(n) -> bcoz of recursive stack


// Find 1st negative integer (from left) for every window of size 'k' in an array of length 'n' (k <= n)
    // If no negative number in a window, consider '0'
    /*
        Ex: arr = [-8, 2, 3, -6, 10], k = 2
        windows = [[-8, 2], [2, 3], [3, -6]...]
        ans = [-8, 0, -6, ...]
    */
    // Intuition: Consider 1st window (first k elements)
    // now for all the remaining windows, push 1 element front end, pop 1 from front (until last element)
    // thus we could use a queue
    // Instead of pushing values, how about negative integer's indices
    // this way, front(q) would directly give 1st negative integer (just write adding and removing logic correctly)

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    queue<int> q;
    vector<int> ans;

    //for 1st window
    int lastIndexOfWindow;
    for (lastIndexOfWindow = 0; lastIndexOfWindow < k; lastIndexOfWindow++) {
        if (arr[lastIndexOfWindow] < 0)
            q.push(lastIndexOfWindow);
    }
    (q.empty()) ? ans.push_back(0) : ans.push_back(arr[q.front()]);

    // for subsequent windows
    for (; lastIndexOfWindow < arr.size(); lastIndexOfWindow++) {
        // remove older elements
        if (!q.empty() && q.front() < lastIndexOfWindow - k + 1)
            q.pop();

        // add new element
        if (arr[lastIndexOfWindow] < 0)
            q.push(lastIndexOfWindow);

        // ans
        (q.empty()) ? ans.push_back(0) : ans.push_back(arr[q.front()]);
    }
    return ans;
}
// TC: O(n)     SC: O(n)


// Reverse first 'k' elements of queue
    /*
        Ex: inp = [1, 2, 3, 4, 5]   k = 3
        out = [3, 2, 1, 4, 5]
    */
    // Reversing can always be done with stack :)
    // Put first k element in stack
    // embed reversed order back to queue
    // Ex queue now: [4, 5, 3, 2, 1]
    // now, remove n - k elements from front, and push them to end

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    for (int i = 0; i < k; i++) { // reverse first k elements using stack
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) { // push reversed elements to end of queue
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < q.size() - k; i++) { // rotate queue to get desired output
        q.push(q.front());
        q.pop();
    }
    return q;
}


// First non repeating character in a stream
    // given a string s, for each character, find first non repeating char (from left), till that char
    // if none, embed '#'
    /*
        Ex: aabc
        for a -> a
        for a -> no non repeating char on its left -> #
        for b -> b
        for c -> b

        thus, ans = a#bb
    */

    // We need non repeating char so we need to maintain char that have already came
    // make array of size 26 (a - z) to maintain that
    // this will help in checking if char is repeated
    // now, if char is repeated, ans should be next non repeating char that might have came
    // for this, we could maintain a queue and push non repeating chars
    // pop if char repeats

string FirstNonRepeating(string& s) {
    vector<int> visited(26, 0);
    queue<char> q;
    q.push(s[0]);
    visited[s[0] - 'a']++; // add first element as it is always part of ans

    for (int i = 1; i < s.size(); i++) {
        if (!visited[s[i] - 'a']) // push new uniques
            q.push(s[i]);

        visited[s[i] - 'a']++; // increase visited counter

        while (!q.empty() && visited[q.front() - 'a'] > 1) // pop till q.front has occurenced more than once
            q.pop();

        (q.empty()) ? s[i] = '#' : s[i] = q.front();

    }
    return s;
}


/*
    There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

    You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

    Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
*/
// Approach 1:
    // Start from each station, check if we could move complete round back to it
    // maintain balance of petrol
bool checker(vector<int>& gas, vector<int>& cost, int i) {
    int len = gas.size();
    if (gas[i] - cost[i] < 0)
        return 0;
    int curr = (i + 1) % len, balance = gas[i] - cost[i];
    while (curr != i) {
        if (gas[curr] - cost[curr] + balance < 0)
            return 0;
        balance += gas[curr] - cost[curr];

        curr = (curr + 1) % len;
    }
    return 1;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    for (int i = 0; i < gas.size(); i++) {
        if (checker(gas, cost, i))
            return i;
    }
    return -1;
}
// TC: O(n^2)   SC: O(1)


// Approach 2:
    // ans would be -1 only if totalGas is less than totalCost (i.e. sum of gas - cost for whole array is negative)
    // consider gas stations a -> b -> c -> d -> e -> a
    // now, if are able to travel from a to c but not d (starting with a)
    // that means b to d, c to d are also not possible
    // bcoz a se aate vakt kuch to non negative (whole no.) balance laya hoga... uske saath nahi hua, to uske bina kya hi hoga
    // so, we could directly start checking with start = e

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0, balance = 0, start = 0;
    for (int i = 0; i < gas.size(); i++) { // i keeps moving forward, start keeps track of starting
        totalGas += gas[i];
        totalCost += cost[i];
        balance += gas[i] - cost[i];

        if (balance < 0) {  // if balance goes negative, update start
            start = i + 1;
            balance = 0;    // reset balance, not deficit
        }
    }
    return (totalGas < totalCost) ? -1 : start;
}
// TC: O(n)     SC: O(1)


/*
    given a queue Q of N integers of even length,
    rearrange the elements by interleaving the first half of the queue with the second half of the queue.

    Ex: inp -> 11, 12, 13, 14, 15, 16, 17, 18
        out -> 11, 15, 12, 16, 13, 17, 14, 18
        (iska 1, uska 1)
*/
// Approach 1:
    // create 2 separate queues (to get access to both heads)
    // now push in single and rearrange
void interLeaveQueue(queue < int >& q) {
    int len = q.size();
    queue<int> tmp;
    for (int i = 0; i < (len / 2); i++) {
        tmp.push(q.front());
        q.pop();
    }
    while (!tmp.empty()) {
        q.push(tmp.front());
        tmp.pop();
        q.push(q.front());
        q.pop();
    }
}
// * * Dry run on above example to easy understand
// TC: O(n)     SC: O(n)

// Approach 2:
    // Using stack
    // same above logic could be used BUT...
    // Stack mei dalne pr order reverse hoti h
    // so use.. reverse ka reverse = sidha
    // i.e.  baar stack mei dalke nikalo
void interLeaveQueue(queue < int >& q) {
    // let q = 11 12 13 14 15 16 17 18
    int len = q.size();
    stack<int> s;
    for (int i = 0; i < (len / 2); i++) {
        s.push(q.front());
        q.pop();
    }
    // now q = 15 16 17 18 and s = 14 13 12 11 (14 being the top)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // q = 15 16 17 18 14 13 12 11 and s = empty
    // rotated by len/2, to again get that first half in starting
    for (int i = 0; i < (len / 2); i++) {
        q.push(q.front());
        q.pop();
    }
    // q = 14 13 12 11 15 16 17 18 and s = empty
    for (int i = 0; i < (len / 2); i++) {
        s.push(q.front());
        q.pop();
    }
    // q = 15 16 17 18 and s = 11 12 13 14
    // got the required format, now continue like before
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}


// 'k' queues using a single array of length 'n'
// Approach 1:
    // divide array in k equal parts
    // implement each part as a separate queue
// Brute force, not memory efficient

// Approach 2:
    // Make separate arrays of size k to store front and rear of each queue
    // use data array of size 'n' to keep track of next free spots
    // maintain a freespot variable to get upcoming freespot

class NQueue {
public:
    vector<int> arr;
    vector<int> info;
    vector<int> front;
    vector<int> rear;
    int freespot = 0;
    NQueue(int k, int n) {
        // initialisations
        vector<int> tmp(n, -1);
        arr = tmp;
        info = tmp;
        vector<int> tmp2(k, -1);
        front = tmp2;
        rear = tmp2;

        for (int i = 0; i < n - 1; i++)
            info[i] = i + 1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m) {
        if (freespot == -1)
            return false;
        int indexToPush = freespot; // store index where data would be pushed
        freespot = info[freespot];  // update freespot to next freespot
        if (front[m - 1] == -1) {
            // first element of this queue
            front[m - 1] = indexToPush; // agar empty hai to front mei pushed wala index
        }
        else {
            info[rear[m - 1]] = indexToPush; // not first element, then link prev element to pushed element
        }
        info[indexToPush] = -1; // space occupied, so set info as -1 (indicates end of queue)
        rear[m - 1] = indexToPush;  // update rear to new position
        arr[indexToPush] = x;   // store element
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m) {
        if (front[m - 1] == -1)
            return -1;
        int indexPopped = front[m - 1]; // store index to be popped
        // update front to next linked element 
        // if last element, no linked element after that.. automatically -1 aayega bcoz info[last pushed] is stored -1 in push code
        front[m - 1] = info[indexPopped];
        info[indexPopped] = freespot;   // mark current place as 1st free spot, by placing it in front of freespot chain (visualise...)
        freespot = indexPopped; // update freespot var to current index, as it would be first free spot in list now
        return arr[indexPopped];
    }
};
// DRY RUN... with 3 queues and 10 sized array for better understanding * * *


/*
    You are given an array consisting of N integers, and an integer, K. Your task is to determine the total sum of the minimum element and the maximum element of all subarrays of size K.

    Ex:
    arr = 1 2 3 4 5
    k = 3

    subarrays: [1 2 3]  [2 3 4] [3 4 5]
    thus,
        ans = 1 + 3 + 2 + 4 + 3 + 5 = 18
*/

// Approach 1:
    // Brute force
    // Use sliding window
    // for each window, find the minimum and maximum
    // add it to ans
// TC: O(n*k) bcoz saara array traverse + har baar k elements ke bich ka min and max

// Approach 2:
    /*
        for finding minimum:
        suppose we get 11 while traversing, followed by 3
        11 isnt significant, we only need 3

        but if 3 is followed by something greater than 3.. ex: 5
        we might need 5 in future (if 3 is not in the window range, 5 might be the minimum)

        so, basically, we need a monotonically increasing order..
    */
    // for minimum: make monotonic deque of first k elements
        // for upcoming subarrays, pop elements outside range
        // push new element while maintaining the monotonic increasing order
    // for maximum: everthing same, just we would need monotonic decreasing order
vector<int> getMin(vector<int>& nums, int n, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] <= nums[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);
    for (int lastIndex = k; lastIndex < n; lastIndex++) {
        int firstIndex = lastIndex - k + 1;
        while (!q.empty() && q.front() < firstIndex)
            q.pop_front();
        while (!q.empty() && nums[lastIndex] <= nums[q.back()])
            q.pop_back();
        q.push_back(lastIndex);
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

vector<int> getMax(vector<int>& nums, int n, int k) {
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    ans.push_back(nums[q.front()]);

    for (int lastIndex = k; lastIndex < n; lastIndex++) {
        int firstIndex = lastIndex - k + 1;
        while (!q.empty() && q.front() < firstIndex)
            q.pop_front();
        while (!q.empty() && nums[lastIndex] >= nums[q.back()])
            q.pop_back();
        q.push_back(lastIndex);
        ans.push_back(nums[q.front()]);
    }

    return ans;
}

long long sumOfMaxAndMin(vector<int>& nums, int n, int k) {
    vector<int> mins = getMin(nums, n, k);
    vector<int> maxs = getMax(nums, n, k);
    long long ans = 0;
    for (int i = 0; i < mins.size(); i++)
        ans += mins[i] + maxs[i];
    return ans;
}

// TC: O(n)     SC: O(n)


// Trees
    // Non linear data structure
    // Represented using nodes and edges

// Binary Tree
    // har node ke <= 2 childs

/*
    root node -> topmost node of the tree
    children -> elements(s) directly connected to given node in below level
    parent -> vice versa of children
    siblings -> share a common parent
    ancestor -> kisi bhi node se root node tk (including root node) jaane mei jo jo nodes visit hoge
    leaf node -> 0 children wala node
*/

/*
    structure of node in tree:
    node{
        int data;
        vector<node*> childs;
    }

    structure of node in binary tree:
    node{
        int data;
        node* left;
        node* right;
    }
*/

// * * BFS (Breadth first search)
    // Also known as Level order traversal
    // Traversing technique in which all nodes from lvl 0 (root node) are traversed, followed by level 1 and so on..
    // Easiest way to solve BFS is using queue * * *
    // Queue has root at start
    // Till queue is not empty, print front(queue), pop it, push its children
    // * * visualise * *


// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
/*
    Ex:     3
          /   \
        9      20
              /  \
            15    7

    output: [[3],[9,20],[15,7]]
*/
// Approach:
    // OFC level order, BUT..
    // we need to maintain each lvl in separate array
    // use separator to separate each lvl in queue
    // if we encounter separator, push array to resultant
    // empty array for next lvl
    // ALSO... if we encounter separator and q is not empty, that means another lvl is present in queue
    // so again add a separator before starting with new lvl

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;     // for maintaing queue
    vector<int> tmpList;    // for storing elements in current lvl

    if (!root)
        return ans;     // edge case
    q.push(root);
    q.push(NULL);       // initially, push lvl 0 manually (used NULL as separator as no NULL value will be in queue except separator)
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == NULL) { // found NULL, so lvl finished
            ans.push_back(tmpList);
            tmpList.clear();
            if (!q.empty())
                q.push(NULL);   // if lvl finished but queue not empty, that means other lvl is present (add separator)
        }
        else {
            tmpList.push_back(curr->data);  // add curr data to list
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            // if right and left are not NULL, add them to back of queue    
        }
    }
    return ans;
}


/*
    Common traversal techniques:
        1. Inorder traversal -> root in between -> left root right
        2. Preorder traversal -> root pre -> root left right
        3. Postorder traversal -> root post -> left right root
*/


// Height of binary tree
    // Given a binary tree, find its height / maximum depth
    // Height can be defined as the longest path between root node and leaf node

// Approach 1:
    // Use recursion, maintain a height var
int height(struct TreeNode* node, int lvl = 0) {
    if (node == NULL)   //base case, root NULL
        return 0;
    if (node->left == NULL && node->right == NULL)  // base case, reached leaf node
        return lvl;
    return max(height(node->left, lvl + 1), height(node->right, lvl + 1));
}
// TC: O(n)     SC: O(h) -> h = height of tree (due to recursive stack)


// Using BFS
    // use BFS to find highest depth, by reaching the farthest leaf node
    // see carefully
int height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    queue<TreeNode*> q;
    q.push(node);
    q.push(NULL);
    int lvlCounter = 0;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == NULL) {
            if (!q.empty())
                q.push(NULL);
            lvlCounter++;
            continue;
        }
        if (curr->right)
            q.push(curr->right);
        if (curr->left)
            q.push(curr->left);
    }
    return lvlCounter - 1;
}
// TC: O(n)     SC: O(w) -> w = width of tree (due to queue.. bco queue mei at a time max width jitne hi elements hoge)


// Diameter of a binary tree * * *
    // Diameter of a tree can be defined as the longest path between 2 nodes
    // Now, these distance will always be between 2 leaf nodes (try yourself)

// Approach:
    /*
        There are 3 possibilities:
            1. Both leaf node lie in right subtree
                Ex:     1
                      /  \
                     2    3
                   /  \
                 4     5
                 |      \
                 6       8
                 |       |
                 7       9

                Longest path = 6 between 2 leaf lies in right subtree (between 7 and 9)
                * * * WE ARE COUNTING EDGES, NOT NODES

            2. Iska vice versa, lies in right subtree
            3. One of the node lies on left, other one on right
                We could easily solve this case bcoz..
                    max distance leaf node on right = height of right subtree
                    max distance leaf node on left = height of left subtree
                thus, diameter = right height + left height + 1 (added one to consider curr node too)

            THUS..
                ans would always be max of these 3
    */

int maxHeight(TreeNode* root) { // function to get maximum height in subtree (1-indexed)
    if (!root)
        return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}
int diameter(TreeNode* root) {
    if (!root)
        return 0;

    int left = diameter(root->left);
    int right = diameter(root->right);
    int combined = maxHeight(root->left) + maxHeight(root->right);
    return max({ left, right, combined });
}
// TC: O(n^2) -> bcoz.. for every node: diameter runs 'n' times (n = no. of nodes in subtree)
    // and, for each node, it calls maxHeight which is O(n) in itself
    // Thus O(n * n)
// SC: O(n)


// Approach 2:
    // TC could be reduced if we could remove that separate call for height
    // like, we are anyways going till leaf nodes in diameter func itself, why call height separately
    // make a custom func that would return both height and diameter for a subtree

// * * * * MUST DRY RUN!!!
// combined both functions
pair<int, int>getDiameterAndHeight(TreeNode* root) {
    if (!root)
        return make_pair(0, 0); // base case for root NULL (diameter and height both will be 0)

    pair<int, int> left = getDiameterAndHeight(root->left);
    pair<int, int> right = getDiameterAndHeight(root->right);

    int diameterLeft = left.first;
    int diameterRight = right.first;
    int sumOfHeights = left.second + right.second;

    return make_pair(
        max({ diameterLeft, diameterRight, sumOfHeights }),
        max(left.second, right.second) + 1
    );
}
int diameter(TreeNode* root) {
    return getDiameterAndHeight(root).first;
}
// TC: O(n)     SC: O(n)


// Check if tree is Balanced
    // Given a binary tree, determine if it is height-balanced.
    // A binary tree is considered height-balanced if:
    // absolute difference in heights of the left and right subtrees is at most 1 for "every" node.

    // Thus, max diff between nodes pointing to NULL as child should be 1 * * *

// Approach:
        // The word "every" is imp...
        // if we check just maxHeight from root, tree might not be balanced and still return true
        // So, check:
            // left subtree is balanced
            // right subtree is balanced
            // maxHeight of left = maHeight of right
int maxHeight(TreeNode* root) {
    if (!root)
        return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}
bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool heightCheck = abs(maxHeight(root->left) - maxHeight(root->right)) <= 1;
    if (left && right && heightCheck)
        return true;
    return false;
}
// TC: O(n^2)   SC: O(n)

// Approach 2:
    // Time complexity could be reduced if we could eliminate that extra call for calculating height
    // Make a custom function like prev
pair<bool, int> getBalancedAndHeight(TreeNode* root) {
    if (!root)
        return make_pair(true, 0);
    pair<bool, int> left = getBalancedAndHeight(root->left);
    pair<bool, int> right = getBalancedAndHeight(root->right);

    int height = 1 + max(left.second, right.second);
    bool balanced = (left.first && right.first && (abs(left.second - right.second) <= 1));
    return make_pair(balanced, height);
}
bool isBalanced(TreeNode* root) {
    return getBalancedAndHeight(root).first;
}
// TC: O(n)     SC: O(n)


// Approach 3:
    // Use a queue
    // when a node has left or right child as 1 (dono mei se 1 bhi..), store it using min and max Lvl variables
    // Get difference between minimum and maximum level
bool isBalanced(TreeNode* root) {
    if (!root)
        return true;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int lvl = 0, minLvl = INT_MAX, maxLvl = INT_MIN;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (!curr) {
            if (!q.empty())
                q.push(NULL);
            lvl++;
            continue;
        }
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
        if (!(curr->left && curr->right)) {
            minLvl = min(minLvl, lvl);
            maxLvl = max(maxLvl, lvl);
        }
    }
    return ((maxLvl - minLvl) <= 1);
}


// Check if Binary trees are identical
// Approach:
    // Check data for current nodes
    // recurse for left and right subtree
bool identicalTrees(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)   // if both NULL
        return true;
    if (!root1 || !root2)   // if only one of them is NULL
        return false;
    if (root1->data != root2->data)
        return false;
    return identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right);
}


// Sum Tree
    // Given a Binary Tree. Check for the Sum Tree for every node except the leaf node
    // Return true if it is a Sum Tree otherwise, return false.
    // SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree

// Approach:
    // for every node we need 2 things, sum of subtrees and are those subtrees sumTree
    // make custom function to return both at once
pair<bool, int> isSumTreeAndSumBelow(TreeNode* root) {
    if (!root)  // base case, root NULL
        return make_pair(true, 0);
    if (!(root->left || root->right))   // base case, handle leaf nodes
        return make_pair(true, root->data);

    // to handle if one of the child nodes is NULL:
    pair<bool, int> left = make_pair(true, 0);
    pair<bool, int> right = make_pair(true, 0);
    if (root->left)
        left = isSumTreeAndSumBelow(root->left);
    if (root->right)
        right = isSumTreeAndSumBelow(root->right);

    return make_pair(
        left.first && right.first && (root->data == left.second + right.second),
        left.second + right.second + root->data
    );
    // for every node, it is SumTree if: left subtree is sumTree, right subtree is SumTree, value of node = sum of left and right subtree
    // and, 2nd element in pair return sum inclusing that element itself, so simply adding all 3
}
bool isSumTree(TreeNode* root) {
    return isSumTreeAndSumBelow(root).first;
}



// Binary Tree Zigzag Level Order Traversal
    // Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.

// Approach:
    // 0th lvl -> left to right
    // 1st lvl -> right to left...
    // thus, do normal level order, reverse before pushing for odd levels
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode*> q;
    vector<int> tmp;
    int lvl = 0;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == NULL) {
            if (lvl & 1)
                reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            tmp.clear();
            if (!q.empty())
                q.push(NULL);
            lvl++;
        }
        else {
            tmp.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}
// TC: O(n) * * * might seem ki while ke andar reverse function hai so n^2, but..
    // O(n^2) is when we tranverse each node, and then do operations on tree for each of that nodes
    // here, we are reversing n/2 nodes in total, so it wont be O(n^2)
// SC: O(n)

// Approach 2: 
    // Use indexing in tmp vector to store in required manner, to avoid reversing



// Boundary Traversal
    // The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.
    // Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.

// Approach:
    /*
        Visit root
        visit left boundary part (* * not necessary that it is left skew, might also be left child followed by right.. maing a boundary)
            (except the last leaf node.. to avoid duplicates)
        visit leaf nodes
        visit right part (but reversed order)
    */
void addLeafs(TreeNode* root, vector<int>& ans) {
    if (!root) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
    }
    addLeafs(root->left, ans);
    addLeafs(root->right, ans);
}

void getRightPart(TreeNode* root, vector<int>& ans) {
    if (!root || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if (root->right)
        getRightPart(root->right, ans);
    else
        getRightPart(root->left, ans);
    ans.push_back(root->data);
}
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> ans;
    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        return ans;
    }

    // for left part
    TreeNode* tmp = root->left;
    while (tmp) {
        if (tmp->left == NULL && tmp->right == NULL) {
            break;
        }
        ans.push_back(tmp->data);
        if (tmp->left != NULL)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    // for leafs
    addLeafs(root, ans);
    //for right part
    getRightPart(root->right, ans);
    return ans;
}


// Vertical Traversal
    // Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
    // ques link for sample imgs: https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

// Approach:
    // Consider all nodes on a horizontal number line
    // so we need to print as per number line
    // but, each number on number line will have nodes of tree on multiple levels in tree
    // we must maintain the levels, i.e. print top levels before bottom
    // So, create a map (to store horizontal level and other map)
    // The other map will store vertical level and list of values
    // this way, the answer would already be sorted in our required way

void solve(TreeNode* root, map<int, map<int, vector<int>>>& m, int horizontal = 0, int vertical = 0) {
    if (!root)
        return;
    m[horizontal][vertical].push_back(root->data);
    solve(root->left, m, horizontal - 1, vertical + 1);
    solve(root->right, m, horizontal + 1, vertical + 1);
}
vector<int> verticalOrder(TreeNode* root) {
    vector<int> ans;
    // map to store horizontal dist, map of vertical dist and list
    map<int, map<int, vector<int>>> m;
    solve(root, m);
    for (auto& pair : m) {
        for (auto& lvlPair : pair.second) {
            for (int i : lvlPair.second) {
                ans.push_back(i);
            }
        }
    }
    return ans;
}


// Top view of a binary tree
    // We are given a binary tree, and need to find its top view
    // Similar approach to prev ques, only difference: store only the value in uppermost lvl for each horiontal lvl
// Approach:
    // We need to store uppermost lvl, so use lvl order traversal.
    // only store the first value for each horizontal lvl



// Left view of a binary tree
    // Very much similar, just store values with lowest horizontal lvl for each vertical level



// Lowest common ancestor in a binary tree
    // Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.
    // LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

// Approach:
    // Store paths for both the nodes.
    // Find the last common element from start.
void solve(TreeNode* root, int& n, deque<TreeNode*>& p) {
    if (!root)
        return; // base case on reaching null
    p.push_back(root);
    if (root->data == n)
        return; // base case when path found
    solve(root->right, n, p);

    // recursive calls with base cases to avoid traversing the other sub tree if path is already found
    if (!p.empty() && p.back()->data == n)
        return;
    solve(root->left, n, p);
    if (!p.empty() && p.back()->data == n)
        return;
    p.pop_back(); // backtrack if not found
}
TreeNode* lca(TreeNode* root, int n1, int n2) {
    deque<TreeNode*> p1, p2;
    solve(root, n1, p1);
    solve(root, n2, p2);
    TreeNode* ca = root;
    while (!p1.empty() && !p2.empty() && p1.front()->data == p2.front()->data) {
        ca = p1.front();
        p1.pop_front();
        p2.pop_front();
    }
    return ca;
}