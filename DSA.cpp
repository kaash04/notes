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

   // Code for left shifting and element in array:
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