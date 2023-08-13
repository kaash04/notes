#include <bits/stdc++.h>

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
                    int main()
                    {
                    int dec, bit, bin = 0;
                    printf("Enter your decimal number: ");
                    scanf("%d", &dec);
                    for (int i = 0; dec != 0; i++, dec = dec >> 1)
                    {
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
            int main()
            {
            int bin, dec=0;
            scanf("%d", &bin);
            for (int i = 0; bin!=0; i++, bin = bin >> 1)
            {
                if (bin&1 == 1)
                {
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
                int main()
                {
                int bin, dec=0;
                scanf("%d", &bin);
                for (int i = 0; bin!=0; i++, bin /= 10)
                {
                    if (bin%10 == 1)
                    {
                    dec += pow(2, i);
                    }
                    
                }
                printf("Decimal representation: %d\n", dec);
                
                return 0;
                }


            // Ques: return true is number is power of 2 else return false
            // IF it could be represented in 2 ki power something that means its binar representation must contain 1 at only 1 place
            // Code:
                long int binary(int dec)
                {
                    int bit;
                    long int bin = 0;
                    for (int i = 0; dec != 0; i++, dec = dec >> 1)
                    {
                        bit = dec & 1;
                        bin = (bit * pow(10, i)) + bin;
                    }

                    return bin;
                }

                int main()
                {
                    int num;
                    scanf("%d", &num);
                    long int bin = binary(num);
                    printf("Binary: %ld\n", bin);

                    int count = 0;

                    while (bin != 0)
                    {
                        if (bin % 2 == 1)
                        {
                        count += 1;
                        }
                        bin /= 10;
                    }

                    printf("Count: %d\n",count);
                    if (count == 1)
                    {
                        printf("True\n");
                    }
                    else
                    {
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
    // In an array check element on every index or given value = linear search
    // Ex:
        int linearSearch(int *ar, int sizee, int key)
        {
            int count = 0;
            for (int p = 0; p < sizee; p++)
            {
                if (key == *(ar + p))
                {
                    count += 1;
                }
            }
            return count;
        }

        int main()
        {
            int sizee, key;
            printf("How many elements do you want in array: ");
            scanf("%d", &sizee);
            int arr[sizee];

            printf("Enter your elements: ");
            for (int i = 0; i < sizee; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("Which value would you like to search for: ");
            scanf("%d", &key);

            int counter = linearSearch(arr, sizee, key);

            if (counter == 0)
            {
                printf("FALSE - 0 Occurences\n");
            }
            else
            {
                printf("TRUE - %d Occurences\n", counter);
            }

            return 0;
        }


// Reversing an array:
    // swap first and last, then swap second and last second and so on...
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    int main()
    {
        int sizee;
        printf("Enter size of array: ");
        scanf("%d", &sizee);

        int arr[sizee];
        printf("Enter elements for array: ");
        for (int i = 0; i < sizee; i++)
        {
            scanf("%d", &arr[i]);
        }

        int cpy = sizee - 1; // contains last index
        for (int i = 0; i < (sizee / 2); i++, cpy--)
        {
            swap(&arr[i], &arr[cpy]);
        }

        printf("Swapped array: ");
        for (int i = 0; i < sizee; i++)
        {
            printf("%d ", arr[i]);
        }

        return 0;
    }


// Time and Space Complexity
    //Time complexity
        // it is the amount of time taken by an algorithm to run, as a function of length of input
        // NOT counted in sec bcoz eecution time will depend on power of machine executing the algorithm
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
        int binarySearch(int *ar, int sizee, int key)
        {
            int start = 0, end = sizee - 1, mid;
            while (start <= end)
            {
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

        int main()
        {
            int n, key;
            printf("Enter number of elements you want to enter: ");
            scanf("%d", &n);

            int arr[n];
            printf("Enter elements of array: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &arr[i]);
            }

            printf("Enter number to search: ");
            scanf("%d", &key);

            int index = binarySearch(arr, n, key);
            if (index != -1)
            {
                printf("Key found at index %d\n", index);
            }
            else
            {
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
        void selectionSort(int *arr, int sizee)
        {
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
        void bubbleSort(int *arr, int sizee)
        {
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
        void leftShift(int *arr, int currentIndex, int destinationIndex)
        {
            int temp = *(arr + currentIndex);
            for (int i = currentIndex; i > destinationIndex; i--)
            {
                *(arr + i) = *(arr + i - 1);
            }
            *(arr + destinationIndex) = temp;
        }

    // Insertion sort code:
        void insertionSort(int *arr, int sizee)
        {
            for (int i = 0; i < sizee-1; i++)
            {
                for (int j = i+1; j < sizee; j++)
                {
                    if (*(arr+j) < *(arr+i))
                        leftShift(arr, j, i);
                    
                }
                
            }
            
        }
        // TC = O(n^3)



    // Optimised way to use insertion sort:
        void insertionSort(int *arr, int sizee)
        {
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
            adding 2 elements in vec, size = 2, capaity = 2
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
                int main()
                {
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
                    int main()
                    {
                        std::vector<int> v;
                        v.push_back(1);
                        v.push_back(3);
                        v.push_back(6);
                        v.push_back(7);
                        std::vector<int>::iterator itera = std::lower_bound(v.begin(), v.end(), 6);
                        std::cout << (itera-v.begin()) << std::endl;
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

        int main()
        {
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

        int main()
        {
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
        bool binarySearch(vector<vector<int>> &matrix, int target)
        {
            int row = matrix.size();
            int col = matrix[0].size();

            int start = 0, end = (row * col) - 1, mid;

            while (start <= end)
            {
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
        int countPrime(int n)
        {
            std::vector<bool> numbers(n, true); // created a vector and set all number as prime
            numbers[0] = false;
            numbers[1] = false; // set 0, 1 as not prime
            int count = 0;

            for (int i = 2; i < n; i++)
            {
                if(numbers[i]==true)
                {
                    count++;
                    for (int j = 2*i; j < n; j+=i)
                    {
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
        int gcd(int a, int b)
        {
            if(a==0)
                return b;

            if(b==0)
                return a;
            

            while (a != b)
            {
                if(a>b)
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
        int expo(int x, int y)
        {
            int res = 1;
            if(x==0)
                return y;
            if(y==0)
                return x;
            while(y!=0)
            {
                if(y&1)
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
    void dalloc()
    {
        int r, c;
        int arr[r][c]; // static allocation
        /* VISUALIZE */
        // For dynamic allocation, make array of pointers with number of elements = number of rows
        // and then each pointer will point to linear array with elements = number of columns
        int** ar = new int*[r]; // array of 'r' number of pointers
        for(int i = 0; i < c; i++)
        {
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
    int twoKiPower(int n)
    {
        if(n==1)
            return 1; // base case
        
        return n * twoKiPower(n-1); // recursive relation that we made f(n) = n * f(n-1)
    }

    // Ex(2):
    void fibonacci(int &n, int n1, int n2)
    {
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
    int count(int n)
    {
        if(n == 0) // added this because, its valid way if we reach 0th stair at end
            return 1;
        if(n < 0) // invalid way so + 0
            return 0;
        return count(n-1) + count(n-2);
    }

    // ALWAYS DRAW RECURSION TREE FOR BETTER UNDERSTANDNG OF RECURSION CODE


    //Recursion code to spell out a number:
    void say(int n)
    {
        string spell[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        if (n == 0)
            return;

        say(n / 10);
        cout << spell[n % 10] << " ";
    }
    // see carefully, it uses tal recursion as n%10 gives last digit and we want to spell first digit first
    // so, recurse first and print its output (isse recursion tree ke end node ka output sabse pehele print hoga and top ka last mei)


    // Implementing linear search using recursion:
    bool linearS(int arr[], int s, int key)
    {
        if (s == 0)
            return 0;
        if (arr[0] == key)
            return 1;
        return linearS((arr + 1), s - 1, key);
    }

    // Implementation of binary search using recursion
    bool binS(int *arr, int s, int key)
    {
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
    bool palindrome(string s, int i = 0)
    {
        if (s.length() - 1 - i <= 0)
            return 1;
        if (s.at(i) != s.at(s.length() - 1 - i))
            return 0;
        return palindrome(s, i + 1);
    }

    // Bubble sort using recursion
    void bubble(int *arr, int s)
    {
        if (s == 0 || s == 1)
            return;
        for (int i = 0; i < s - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        bubble(arr, s - 1);
    }
    // basic funda of recursion = solve 1 smaller problem and recurse for remaining
    // so largest element ko last mei le gaye and recursed for remaining array


    // Selection sort using recursion
    // selection smallest and swap with first position of unsorted
    void selection(int *arr, int s)
    {
        if (s == 0 || s == 1)
            return;
        int minIndex = 0;
        for (int i = 1; i < s; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }
        swap(arr[0], arr[minIndex]);
        selection(arr + 1, s - 1);
    }

    // Insertion sort using recursion
    void insertion(int *arr, int s, int k = 1)
    {
        int destinationIndex = k;
        if (s == 0 || s == 1 || k == s)
            return;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] > arr[k])
            {
                destinationIndex = i;
                break;
            }
        }
        for (int i = k; i > destinationIndex; i--)
        {
            swap(arr[i], arr[i - 1]);
        }
        insertion(arr, s, k + 1);
    }


    // * * * * * * * VIMP * * * * * * *
    // implementing merge sort using recursion (T.C. = O(nlogn))
    // merge sort = divide array into sub array unit it has 1 element, then combine while sorting (merge 2 sorted array, classic problem)
    // SEE CODE CAREFULLY * * * * 
    void mergeSort(int *arr, int s, int e)
    {
        if (s >= e)
            return;

        // recursively dividing array into 2 parts until it has 2 elements in it
        int mid = (s + e) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);

        merger(arr, s, e); // tail recursion to sort array
    }

    void merger(int *arr, int s, int e)
    {
        // mid nikalo -> start se mid tak pehela sorted array hoga (bcoz tail recursion se sort karte hue aaye hai) and mid+1 se end tak dusra
        int mid = (s + e) / 2;
        int i = s, j = mid + 1;
        int len = e - s + 1;
        int *sorted = new int[len]; // make new array to merged elements of those 2 arrays in sorted order
        int ins = 0;

        // classic merge 2 sorted arrays problem jaisa same
        while (i <= mid && j <= e)
        {
            if (arr[i] < arr[j])
            {
                sorted[ins] = arr[i];
                i++;
            }
            else
            {
                sorted[ins] = arr[j];
                j++;
            }
            ins++;
        }
        while (i <= mid)
        {
            sorted[ins] = arr[i];
            i++;
            ins++;
        }
        while (j <= e)
        {
            sorted[ins] = arr[j];
            j++;
            ins++;
        }

        // copy elements in sorted order to our original array
        for(int i=0; i < len; i++)
        {
            arr[s] = sorted[i];
            s++;
        }
        delete []sorted; // delete dynamically allocated heap memory
    }


    // Quick Sort
    // first element ko uthao and sorted array mei uski jo position hogi vaha rakho (find that using usse chote kitne number hai array mei)
    // now swap usse chote wale number before it [so array would be like all elements less than x -> x -> all elements greater than x]
    // now repeat the process in both halves
    // TC => best case, avg case = nlogn , in worst case = n^2
    void quick(int *arr, int n)
    {
        // base case
        if (n == 0 || n == 1)
            return;
        int pivot = arr[0], count = 0; // set pivot = first element
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < pivot)
                count++; // count represents number of elements less than it, thus it also shows index of pivot element to be placed
        }
        swap(arr[0], arr[count]);

        int i = 0, j = n - 1;
        while (i < count && j > count) // loop to make all elements b4 pivot less than it, and all elements after it greater than it
        {
            if (arr[i] > pivot && arr[j] < pivot)
            {
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
    void subsets(vector<int> arr, vector<vector<int>> &res, int index = 0, vector<int> output = {})
    {
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
    void perm(string s, vector<string> &res, int index = 0)
    {
        if (index >= s.length() - 1) 
        {
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
    // Time complexity = time required for each run * number of runs of recursive function
    /* 
        Ex: linear search (see algo above): O(k*n) such that, k is constant time required for single run
        thus, linear Search => O(n) [eliminating 'k' as its constant]

        for binary Search:
            lets say we have array of n elements, so while doing binary search we find mid and so on... 'a' times
            thus, T.C. => O(k*a)
            we are actually decreasing size of array to 1 in following order:- n->n/2->n/4->n/8->....->1 [in 'a' times]
            thus, 2^a = n (think mathematically multiplying 2 a times would reverse the effect of dividing by 2 n times)
            taking log on both sides:
                a log2 = logn -> O(a) = O(logn) [neglected const time O(log2)]
            thus,
                Binary Search => O(k*a) => O(a) => O(logn)

        Merge sort: O(nlogn) 
        [O(logn) as number of runs = 2logn, O(n) for merging 2 sorted array (see merger code, it has O(n) complexity)]

        Fibonacci using recursion: O(2^n) [exponential time complexity == ghatiya]
    */
    /*
        Space Complexity: maximum space required at an time instant
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
        class Node
        {
        public:
            int data;
            Node *next; // pointer to next node

            Node(int data) // constructor
            {
                this->data = data;
                this->next = NULL;
            }
        };

    // Inserting data to front of linked list:
        void insertFront(Node *&head, int data) // takes pointer to head node (took reference var too to avoid new var creation) and value to insert at input
        {
            Node *tmp = new Node(data);
            tmp->next = head;
            head = tmp;
        }

    // Printing linked list:
        void printList(Node *&head) // take reference pointer to head node as input
        {
            Node *tmp = head; // copy value of it to temp, i.e. create a local variable that points head in beginning for traversal
            while (tmp != NULL)
            {
                cout << tmp->data << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }

    // * * Similarly use tail ptr for inserting at tail

    // Inserting in between
    void insertAt(Node *&head, int pos, int data) // pos = position at which insert karna hai
    {
        Node *tmp = head;
        for (int i = 0; i < pos - 2; i++)
            tmp = tmp->next;
        // After execution of this for loop, tmp will point to pos-1 th node
        // we need to insert at pos... so ptr(pos-1) points new node & ptr(newNode) points node at pos (before insertion) [visualize]

        Node *n = new Node(data);
        n->next = tmp->next;
        tmp->next = n;
    }
    // This doesnt work for insertion at first and last and ma give error if position exceeds list size (could be fixed using conditional if's )
    // like, if pos == 1 then call insertFront function

    // For deleting a Node, make its prev node point to its next node
    // make a ptr to nde that we are deleting before this, and then use that pointer to deallocate dynamic memory using delete keyword
    // MUST write a destructor to convey what happens on deleting a node


    // Implementing Doubly Linked list:
        class Node
        {
        public:
            int data;
            Node *prev;
            Node *next;

            Node(int data)
            {
                this->data = data;
                this->next = NULL;
                this->prev = NULL;
            }

            ~Node()
            {
                this->next = NULL;
                this->prev = NULL;
                int d = this->data;
                delete next;
                delete prev;
                cout << "DC called for " << d << endl;
            }
        };

    // Inserting at head
    void insertAtHead(Node *&head, int data)
    {
        Node *tmp = new Node(data);
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }

    // Printing list
    void printList(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Get length of doubly linked list
    int getLength(Node *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    // * * Inserting at any given position in doubly linked list
    void insertAt(int pos, Node *head, int data)
    {
        if (pos == 1) // insert head
        {
            insertAtHead(head, data);
        }
        else if (pos > getLength(head) + 1) // out of indexing order
        {
            cout << "Cannot insert at invalid index" << endl;
        }
        else
        {
            // inserting in between
            Node *back = head;
            int count = 1;
            while (count < pos - 1)
            {
                back = back->next;
                count++;
            }

            // creating new object for element
            Node *tmp = new Node(data);

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
    void deleteNode(Node *&head, int pos)
    {
        Node *tmp = head;
        for (int i = 1; i < pos; i++)
        {
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
        else
        {
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
    void reverseList(Node *&head)
    {
        Node *back = NULL;
        Node *current = head;
        Node *front = head->next;

        if (head == NULL || head->next == NULL) // empty list or list with 1 element
            return;

        while (current != NULL)
        {
            current->next = back;
            back = current;
            current = front;
            if (front != NULL)
                front = front->next;
        }
        head = back;
    }
// Recursive solution
    void reverseRecurse(Node *&head, Node *back, Node *current)
    {
        if (current == NULL)
        {
            head = back;
            return;
        }
        Node *front = current->next;
        current->next = back;
        reverseRecurse(head, current, front);
    }


// Middle of linked list
// We need to find mid node of linked list
// Naive approach: iterate through list to find its length and hence find pos of mid node. Then iterate again to find its value.
// Optimised Approach: create 2 pointers, one of them woud move 2 nodes front at a time and other would move 1
