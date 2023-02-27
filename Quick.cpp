// Scope resolution operator  ( :: )
    // used to refer to global variable if local variable with same name exists
    int vr = 19;
    int main() {
        int vr = 4;
        cout << vr << endl;  // prints 4
        cout << ::vr << endl;  // prints 19
    }


// By default C++ compiler's consider decimal literals as 'double' data type
    // You need to specify for long double and float as:
    34.4f // passes 34.4 as 'float'
    34.4l // passes 34.4 as 'long double'



// Reference variable
    int var = 4;
    int &ref = var;  // Reference variable to var (doesn't create new variable with same value, just refers to var when called.)


// Typecasting in C++
    // Changing data type (**if possible)
    float val = 33.3;
    cout << val << endl;  // prints '33.3' as its a float
    cout << int(val) << endl;  // prints 33 as we specified int, so it will move to nearest preceding integer

// Switch Statement
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;
    switch (age)
    {
    case 18:
        cout << "YOU ARE SAME AGE AS ME!!" << endl;
        break; // BREAKS THROUGH LOOP AND RUNS PART OF CODE DIRECTLY AFTER SWITCH END (prints all rest after 1 check true, if break not used)
    
    default:
        cout << "Your Age is " << age << endl;
        break;
    }



// Loops in C++ (3 Types: for, while, do while)
    // FOR LOOP
        for (int i = 0; i < count; i++)  // (initialization, condition, increment)
            {
                // Code to execute
            }
    // WHILE LOOP
        while (condition)
            {
                //Code
            }
    // do While LOOP
        do
        {
            // Code
        } while (condition);
        // 1 bar to loop guaranteed chalega fir condition ke hisab se..... thats why different from while loop



// BREAK AND CONTINUE
    for (int i = 0; i <= 10; i++)
        {
            cout << i << endl;           // Prints numbers from 0-10
        }

    //BREAK
    for (int i = 0; i <= 10; i++)
    {
        cout << i << endl;          // Should have printed numbers from 0-10 
        // BUT i=7 hone par break karke loop se bahar chala jayega and execute next line of code
        // So, prints from 0-7 (cout upar hai so i=7 print hone ke bad break)
        if (i==7)
        {
            break;
            // BREAK => loop se bahar aao and execute next code
        }
            
    }

    //CONTINUE
    for (int i = 0; i <= 10; i++)
    { 
        // should have printed 0-10
        // BUT prints 0-6 and then 8-10 (7 print nahi hoga because i=7 hote hi 'cout << 7' hone se pehele hi loop rukke firse run karega
        if (i == 7)
        {
            continue;
            // CONTINUE => loop ka niche wala bacha hua code execute rok do and run loop again...therefore, i++ and run again in this case of for loop
        }
        cout << i << endl;
        
    }



// POINTERS IN C++
    int vari = 10;   // Creates varibale 'vari' with value 10
    int *point = &vari;   // creates integer pointer 'point' and assigns it the value of address of 'vari'

    /*
        *************************   IMP   ****************************
        using &(variablename) gives address of variable
        calling (pointername) gives address stored in pointer
        calling *(pointername) gives value of address stored
    */

    // " & " -------> Address of operator
        cout << "The address of vari is: " << point << endl;

    // " * " -------> Dereference operator   (pointer mei stored address par ki value dega)
        cout << "The value at address stored in point is: " << *point << endl;

    //  MULTI - LEVEL POINTER (1 star more per each level of pointer)
    int **point2 = &point; // pointer to pointer named "point"

    // vari(10) --> point(&vari) --> point2(&point)

    cout << "Address of pointer 'point' is: " << point2 << endl;
    cout << "value at 'point' thats is... address of vari is: " << *point2 << endl;
    cout << "value at vari is: " << **point2 << endl;



// Arrays in C++
    int marks[] = {10, 7, 2, 9};
    // can use -> int marks[4] = {10, 7, 2, 9};   too.. but c++ compiler automatically takes size of array so no need
    cout << marks[0] << endl; // prints 10

    // Pointer arithemetic in arrays
        // you dont need to use address operator to get address of array, instead write only its name to get it..
        cout << "Address of marks array is: " << marks << endl;
        // Gives address of first block

        int *p = marks; // pointer declared to store marks (i.e. address of array[0])
        // p++;  // marks[1]
        // p++; // marks[2]  and so on.....
        // therefore dereferencing p+3 [ using *(p+3) ] would give element at 3rd index of array... i.e. 4th element



// USER DEFINED DATA STRUCTURES
    // Struct
    // Array -> collection of same data type elements
    // Struct -> collection of different data types of elements
        struct employee
        {
            int empId;
            float salary;
        };
        
        int main() {
            employee Harry;    // created a custom data type named employee, now use it just like we use int/char
            Harry.empId = 01;
            Harry.salary = 65000;
            std::cout << Harry.empId;
            return 0;
        }
        
    // Union Data Type
    // like struct, but 1 declaration par list mei se koi 1 hi valid 
    // (dusra declare karoge kisi element ke liye to pehele wala overwrite hoga and garbage value dega)
    // thus, saves alot of memory...as struct mei all used and reserved even if not declared
    //EX: 
        union payment
        {
            int amountRice;
            char exchangeCode;
            float inr;
        };
        
        int main() {
            payment p1;
            p1.amountRice = 34; // set as rice with value 34 for p1, now p1 ke liye dusra likne par ye overwrite
            payment p2;
            p2.inr = 2500;  // dusra element banake usko de sakte hai, alag data type, no problem
        }



// Functions
    int sum(int a, int b)
    {
        int c = a+b;
        return c;
    }

    int main() {
        int num1 = 3, num2 = 4;
        sum (num1, num2);  // COPIES num1 and num2 (actual arguments) into 'a' and 'b' (formal arguments of function)
    }
    // must be placed above int main() so that it loads before its called in main


    // FUNCTION PROTOTYPING --> used when we want to put function below int main but still use it without error
    // Ex: 
        int sum(int, int);  //  Format => type name(arguments)

        int main()
        {
            sum(3, 4);
        }

        int sum (int a, int b)
        {
            int c = a+b;
            return c;
        }




// ***************************  IMP **************************
    #include <iostream>

    void swap (int a, int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int main() {
        int num1=3, num2=7;
        std::cout << "a = " << num1 << " and b = " << num2 << std::endl;
        swap(num1, num2);
        std::cout << "a = " << num1 << " and b = " << num2 << std::endl;
        return 0;
    }

    // Perfect code but still.....this wont swap numbers
    // because when we call swap() it COPIES value from actual argument into formal argument and then operates there.
    // So, instead we could pass memory address of our actual variables to function and then work on it there :)
    // Ex: 
        void swap (int *a, int *b)  // Function that takes pointer to address as formal argument
        {
            int temp = *a;   // dereferencing value at 'a' and set it in 'temp'
            *a = *b;
            *b = temp;
        }
        int main() {
            int num1=3, num2=7;
            std::cout << "a = " << num1 << " and b = " << num2 << std::endl;
            swap(&num1, &num2); // passing address of 'num1' and 'num2' to formal pointers 'a' and 'b'
            std::cout << "a = " << num1 << " and b = " << num2 << std::endl;
            return 0;
        }



// Inline Functions
    // in functions, on calling -> actual argument copies to formal argument -> calculations done -> func returns value
    // then cout prints it, so its kinda time consuming...
    // to reduce this time consumption, inline function replaces function code wherever it is called while compiling
    // Thus, reduces time but increases exe size, SO USE INLINE ONLY WHEN FUNCTION HAS LESS LINES OF CODE INSIDE IT
    // Ex:
        inline int pr(int a, int b)  // just add "inline" before function declaration to use it
        {
            return a*b;
        }
        int main()
        {
            int n1=5, n2=4;
            std::cout << "The product of n1 and n2 is: " << pr(n1, n2) << std::endl;
        }
    // AVOID using inline functions when function contains static variable, loops, recursive functions, etc.



// Default argument
    // Function arguments could be set to have a default value, so that if the value isnt specified, it will take the default one
    // Ex:
        float money(int amount, float interest = 4)
        {
            return (amount + ((interest/100)*amount));
        }
        int main()
        {
            int amount = 100
            std::cout << money(amount); // only amount argument given, as other one has default value that would be taken
        }



// Finding factorial using recursion
    int factorial(int number)
    {
        if (number == 1 || number == 0)
        {
            return 1;
        }
        else
        {
            return number*factorial(number-1);
        }
    }



// Function Overloading
    // Using function for multiple purposes
    // same naam se alag alag functions bana lo, program apne aap figure out karlega using arguments matching
    // Ex:
        int sum(int a, int b)
        {
            return a+b;   // Func 1
        }
        int sum(int a, int b, int c)
        {
            return a+b+c;  // Func 2
        }
        int main() {
            int a=3, b=5, c=7;
            cout << "Sum of 3 and 5 is: " << sum(a, b);  //  uses func 1
            cout << "Sum of 3, 5 and 7 is: " << sum(a, b, c);  //  uses func 2
        }



// **************************************** OBJECT ORIENTED PROGRAMMING **************************************
/*
    Works on the concept of classes and objects.
    Class is a template to create objects.
    Treats data as critical element.
    Better code reusability using objects and inheritance.
    Complexity can be easily managed, making the code more human readable.
*/
/*
    BASIC TERMINOLOGY IN OOPS :-
        Classes -> Basic template for creating objects.
        Objects -> Basic runtime entities.
        Data abstraction/Encapsulation -> wrapping data/function in single unit.
        Inheritance -> Properties of one class can be inherited into other classes.
        Polymorphism -> ability to take more than one forms.
        Dynamic binding -> Code executing is not known until its is run.
*/


// CLASSES AND OBJECTS
    // Classes are similar to struct BUT
        // struct cant handle functions inside it.
        // struct doesnt provide data security and data can be accessed from anywhere in program.
        // classes can have methods and properties, struct dont.
            class employee
            {
                private: // things written inside private can only be accessed by functions of this class
                    float salary;
                public:
                    int empId;
                    // Functions in classes (must place in public to be accessible outside)
                    // (if placed in private, they can only be called by other public function)
                    // NORMAL:
                    void getData()
                    {
                        std::cout << "Employee Id: " << empId << std::endl;
                        std::cout << "Salary: " << salary << std::endl;
                    }
                    // USING FUNCTION PROTOTYPING:
                    void setData(int, float);
            };

            int main()
            {
                employee harry; // Created object harry in class employee
                harry.empId = 1; // valid, as empId is public so we can access it directly
                // harry.salary = 60000 // INVALID, as salary is private, so only the functions of that class can access it
                harry.setData(2, 60000);
                harry.getData();

            }

            void employee::setData(int id, float sal)  // Writing the function that was declared as prototype
            {
                empId = id;
                salary = sal;
            }



// Nesting of member functions
    // Member functions of same class can be nested and called from each other without using operator
    // Ex: (good example for nesting, classes and string so see carefully)

        // main -> b.read() -> gets string -> passes it to checkBinary() -> checks if all alphabets are 0 and 1
        class binary
        {
            std::string s; // string is private member in this class(by default sab kuch private hota hai, unless specified)
        public:
            void checkBinary(void);
            void read(void);
        };
        
        int main()
        {
            binary b;
            b.read();
        }

        void binary::checkBinary()
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s.at(i) != '0' && s.at(i) != '1')
                {
                    std::cout << "INVALID BINARY FORMAT!!" << std::endl;
                    exit(0);
                }
                else
                {
                    std::cout << "VALID BINARY FORMAT :)" << std::endl;
                    exit(0);
                }
            }
        }
        void binary::read()
        {
            std::cout << "Enter binary number: ";
            std::cin >> s;
            checkBinary();
        }



// Memory allocation and Arrays in C++
    // C++ compiler allocates memory smartly by allocating memory only once to things which will be common for all
    // (like functions)

    // ARRAY IMP EX: 
        class shop
        {
            int itemId[33];
            int itemPrice[33];
            int counter;
        public:
            void initCounter() { counter=0; }
            void addItem();
            void displayItems();
        };
        int main()
        {
            shop dukan;
            dukan.initCounter();
            dukan.addItem();
            dukan.displayItems();
            return 0;
        }
        void shop::addItem()
        {
            int number;
            std::cout << "How many items do you want to add: ";
            std::cin >> number;
            for (int i = 0; i < number; i++)
            {
                std::cout << "Enter item ID: ";
                std::cin >> itemId[counter];
                std::cout << "Enter item Price: ";
                std::cin >> itemPrice[counter];
                counter++;
            } 
        }
        void shop::displayItems()
        {
            for (int i = 0; i < counter; i++)
            {
                std::cout << "ID: " << itemId[i] << "     " << "Price: " << itemPrice[i] << std::endl;
            }
        }



// Static data members
    // data inside this will be common for all objects
    // Ex: if we need to maintain number of employee, and we create a private variable for it,
    //          every object will have its own var.
    // static data members are declared outside class for memory allocation outside but mentioned in class too.
    // Ex: 
        class company
        {
            int empId;
            int salary;
            static int count; // static int initiated at '0' by default
        public:
            void addEmployee();
            // #1
        };

        int company::count=1; // initiated it at '1'

        int main()
        {
            company tester;
            tester.addEmployee();
            return 0;
        }

        void company::addEmployee()
        {
            std::cout << "Enter employee ID: ";
            std::cin >> empId;
            std::cout << "Enter employee salary: ";
            std::cin >> salary;
            std::cout << "this is emp " << count << std::endl;
            count++;
            addEmployee();
            // using static allots memory in common space for all objects
            // in this program emp count will keep increasing till program is running
        }



// Static Function members
    // used when we need to access static variables only
    // static functions will have access ONLY to other static variables and other static functions.
    // for same example above,

    static void getCount()   // in place of #1
    { 
        std::cout << "The value of count is: " << count << std::endl;
            // wont give this error when initiated inside same class
    }
    // Static function are not linked to any object thus we can call them directly with class name
    // NO NEED TO SPECIFY OBJECT LIKE line 447
    // instead...
    company::getCount(); // directly along with class name to call



// Array of objects
    // classes are nothing but custom data types, and objects inside it are like declared variables
    // thus we can create array of objects the same way like we do for other data types
    class employee 
    {
        int empId;
        float salary;
    public:
        void setId();
        void getId();
    };

    int main()
    {
        employee dev[4]; // declared dev(object) like variable in class employee (like we do for data type)


        for (int i = 0; i < 4; i++)
        {
            dev[i].setId(); // sets id for all 4 elements of array
            dev[i].getId();
        }
        
    }

    void employee::setId()
    {
        std::cout << "Enter employee ID: ";
        std::cin >> empId;
        std::cout << "Enter employee salary: ";
        std::cin >> salary;
    }
    void employee::getId()
    {
        std::cout << "ID of this employee is " << empId << " and his salary is " << salary << std::endl;
    }



// Friend functions in C++
    // friend functions are the functions that are friend of some class
    // i.e. they have written permission to access private data of that class :)
    // Ex: 
    class Complex
    {
        int a, b; // declared private variables 'a' and 'b' to store real and imaginary part of complex number
    public:
        void setComplex(int real, int imaginary)
        {
            a = real;
            b = imaginary;
        }
        void printComplex()
        {
            std::cout << a << " + " << b << "i" << std::endl;
        }
        // declared our sum function as its friend so it can access class private var's
        // format -> friend 'data type of function' 'func name()';
        friend Complex sumComplex(Complex, Complex); 
    };

    Complex sumComplex(Complex o1, Complex o2) // error if we declare like Complex Complex::sumComplex()
    // because sumcomplex is friend function so its not in class so declare normal, but mention friend in class
    // complex->return data type, as sum will be returned as another complex
    // THIS IS ALSO EXAMPLE OF PASSING OBJECTS TO FUNCTIONS
    {
        Complex sum;
        sum.setComplex((o1.a+o2.a), (o1.b+o2.b));
    }

    // JUST MAKE A NORMAL FUNCTION OUTSIDE WITHOUT ASSOCIATING IT WITH CLASS USING "Complex:: " and declare as friend



// Member friend functions
    // Function of one class is friend of other class and can access its data
    // ***********Forward declaration is same as prototyping that we did for functions

    // * * * * * * * * * * * * * * * * * VIMP * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    // CODE 1: 
        class Complex
        {
            int real, img;
        public:
            void setComplex(int a, int b)
            {
                real = a;
                img = b;
            }
            void getComplex()
            {
                std::cout << real << " + " << img << "i" << std::endl;
            }
            friend Complex Calculator::addComplex(Complex, Complex);
        };

        class Calculator
        {
        public:
            Complex addComplex(Complex, Complex)
            {
                Complex temp;
                temp.setComplex((o1.real+o2.real), (o1.img+o2.img));
                return temp;
            }
        };

    // LOOKS FINE, BUT WE DECLARED Calculator::addComplex as friend even before it was created so compile ERROR
    // FIX --> Declare addComplex first, by declaring Calculator class before and then add it as friend

    // CODE 2:
        class Calculator
        {
        public:
            Complex addComplex(Complex, Complex)
            {
                Complex temp;
                temp.setComplex((o1.real+o2.real), (o1.img+o2.img));
                return temp;
            }
        };

        class Complex
        {
            int real, img;
        public:
            void setComplex(int a, int b)
            {
                real = a;
                img = b;
            }
            void getComplex()
            {
                std::cout << real << " + " << img << "i" << std::endl;
            }
            friend Complex Calculator::addComplex(Complex, Complex);
        };
    // NOW THE PROBLEM IS, WE ARE USING "Complex" class inside Calculator even before its declared (1)
    // ALSO, we are using data from Complex inside addComplex before its created (2)

    // FIX FOR (1) --> Using 'forward declaration' to declare that there will be class named Complex coming
    /* FIX FOR (2) --> Just Declaring addComplex there with 'prototyping' so that it wont use any data from Complex class
        and then declaring it outside after done with Complex class */

    // CODE 3: [ final fixed :) ]
        class Complex;  // Forward declaration of Complex class

        class Calculator
        {
        public:
            Complex addComplex(Complex, Complex); // Protoyped to avoid using data from Complex class that isnt yet created
        };

        class Complex
        {
            int real, img;
        public:
            void setComplex(int a, int b)
            {
                real = a;
                img = b;
            }
            void getComplex()
            {
                std::cout << real << " + " << img << "i" << std::endl;
            }
        friend Complex Calculator::addComplex(Complex, Complex);
        };

        Complex Calculator::addComplex(Complex o1, Complex o2) // Declared addComplex after declaring data in Complex class
        {
            Complex temp;
            temp.setComplex((o1.real+o2.real), (o1.img+o2.img));
            return temp;
        }



// Friend Classes
    // Suppose we have 100 functions from other class that need to access data like this
    // Too much hectic to declare everyone as friend + resource wastage
    // ALTERNATIVE -> declare whole class having functions as friend
    // like,
        class Complex;  // Forward declaration of Complex class

        class Calculator
        {
        public:
            Complex addComplex(Complex, Complex); 
        };

        class Complex
        {
            int real, img;
        public:
            void setComplex(int a, int b)
            {
                real = a;
                img = b;
            }
            void getComplex()
            {
                std::cout << real << " + " << img << "i" << std::endl;
            }
        friend Calculator; 
        // DECLARED WHOLE CLASS AS FRIEND, SO ANY FUNCTION FROM Calculator CAN NOW ACCESS PRIVATE OF Complex
        };

        Complex Calculator::addComplex(Complex o1, Complex o2) 
        {
            Complex temp;
            temp.setComplex((o1.real+o2.real), (o1.img+o2.img));
            return temp;
        }



// Constructors 
    // Constructors are special type of function 
    // They have same name as that of class
    // They cant be called and are automatically invoked when an object is created
    // They do not have return types and cant return any value
        class Complex
        {
            int a, b;
        public: 
            void printComplex()
            {
                std::cout << a << " + " << b << "i" << std::endl;
            }
            Complex(); // declaration of constructor function (must be in public)
        };

        Complex::Complex()
        {
            a = 0; // This function will be automatically invoked whenever an object is created, and set a,b=0 for each obj.
            b = 0;
        }

        int main()
        {
            Complex o1;
            o1.printComplex();
            return 0;
        }
    // * * * * * * * * * * * * * * * * * CONSTRUCTOR MUST BE DECLARED IN PUBLIC SECTION OF CLASS



// Default constructor vs parameterized constructor
    // above example -> default constructor
    // parameterized constructor -> constructor that takes arguments to assign value (not just assign 0 to all)
    // takes parameters therefore, parameterized constructor
        class Complex
        {
            int a, b;
        public: 
            void printComplex()
            {
                std::cout << a << " + " << b << "i" << std::endl;
            }
            Complex(int, int);
        };

        Complex::Complex(int real, int img)
        {
            a = real; 
            b = img;
        }

        int main()
        {
            // * * * * * * * * 2 METHODS TO PASS ARGUMENTS TO CONSTRUCTORS
            // Method(1): implicit call
            Complex o1(4, 5);
            o1.printComplex();

            // Method(2): explicit call
            Complex o2 = Complex(5, 4);
            o2.printComplex();

            return 0;
        }



// Constructor overloading
    // SAME AS FUNCTION OVERLOADING
        // CODE (1)
            class Complex
            {
                int real, img;
            public:
                Complex(int r, int i)
                {
                    real = r;
                    img = i;
                }
            };

            int main()
            {
                Complex o1;
                return 0;
            }
        // Gives ERROR as we initiated complex without argument as there is no constructor that works without argument.
        // WE CAN CREATE MULTIPLE CONSTRUCTOR FUNCTION DEPENDING ON ARGUMENTS

        // CODE (2)
            class Complex
            {
                int real, img;
            public:
                Complex(int r, int i)
                {
                    real = r;
                    img = i;
                }
                Complex(){}
            };

            int main()
            {
                Complex o1;
                return 0;
            }
        // NO ERROR NOW, as there is constructor with 0 arguments (even though its an empty func that does nothing)

        // CODE (3) [using this to specify one/both of the real and img parts]
            class Complex
            {
                int real, img;
            public:
                Complex(int r, int i) // COnstructot that takes both parameters
                {
                    real = r;
                    img = i;
                }
                Complex() // Constructor that takes no parameters
                {
                    real = 0;
                    img = 0;
                }
                Complex(int r) // Constructor that take single parameter (real part)
                {
                    real = r;
                    img = 0;
                }
            };

            int main()
            {
                Complex usingBothArg(2, 3);
                Complex usingSingleArg(2);
                Complex usingNoArg;
                return 0;
            }
    // We can also give default argument in constructor just like functions (line 274)

// * * Dynamic -> something that happens at runtime



// Copy Constructor
    /* 
    Constructor that copies data from 
    one object [that is given as argument] to other object [the new one for which constructor is called] 
    */
   // SEE BELOW CODE CAREFULLY FOR DECLARATION OF COPY CONSTRUCTOR
        #include <iostream>

        class Complex
        {
            int real, img;

        public:
            void setComplex(int a, int b)
            {
                real = a;
                img = b;
            }
            void getComplex()
            {
                std::cout << real << " + " << img << "i" << std::endl;
            }
            // Constructors
            Complex() // Default
            {
                setComplex(0, 0);
            }

            Complex(int a, int b) // parameterized which takes 2 parameters for real, img
            {
                setComplex(a, b);
            }

            Complex(Complex &a) // Copy Constructor declaration (must use '&' as its a reference)
            {
                std::cout << "Copy Constructor Called!!" << std::endl;
                real = a.real;
                img = a.img;
            }
            // for prototyping copy constructor: Complex(Complex &) and then declare like above later ('&' is must..)

            // WE NEED TO USE '&' bc we are creating duplicate reference onbject that would take value of object that is passed as argument
            // like, below we pass object named 'arg' so our reference object 'a' would take value of arg without creating new object
            // just like reference variables (line 18)
        };

        int main()
        {
            Complex noArg, arg(2, 3), copyConst(arg);
            std::cout << "Complex with no arguments: ";
            noArg.getComplex();
            std::cout << "Complex with arguments (2, 3): ";
            arg.getComplex();
            std::cout << "Complex with copy arguments from (2, 3): ";
            copyConst.getComplex();

            return 0;
        }
    // But, C++ compiler automatically assigns a default copy constructor if one isnt present already!!
    // so even if we dont write a copy constructor it would work, but then our custom statement of copy constructor called wont run..
    // so, if we need some extra things to work or display when copy constrcutor is used, write its func else used inbuilt 



// Blocks in C++
    // block ke andar jo elements hai unka scope vo block tak hi hota hai
    // block ka end = elements destroyed by compiler
        // See below destructor ex for ex of blocks


// Destructors in C++
    // never takes an argument, nor does it return a value
    // Called when compiler destructs an object when its no more needed...
    // like, if theres and local object, after end of its scope destructor would be called
        // Try running this and study output for flow of code and when are objects destroyed
        // like, objects inside a block are destroyed when block ends, obj inside func are destroyed when func ends etc..
        class obj
        {
            static int count;
        public:
            obj()
            {
                // Constructor
                count++;
                std::cout << "Constructor called for object number " << count << std::endl;
            }

            ~obj()
            {
                //Destructor
                std::cout << "Destructor called for object number " << count << std::endl;
                count--;
            }
        };

        int obj::count = 0; // set counter to 0 as number of obj created = 0
        // we can assign static vars of a class like this from global scope (but not from main)

        int main()
        {
            std::cout << "o1 creating.." << std::endl;
            obj o1;
            {
                // block is enclosed with curly braces
                std::cout << "INSIDE A BLOCK!!" << std::endl;
                std::cout << "Creating o2 and 03.." << std::endl;
                obj o2, o3;
                std::cout << "Exiting Block " << std::endl;
            }
            return 0;
        }



// Inheritance in C++
    // Increases code reuseability as it allows us to inherit member methods (functions) and vars from one class to other
    // existing class -> base class     new class -> derived class
    /*
        TYPES OF INHERITANCE: 
            ->Single Inheritance
            ->Multiple Inheritance
            ->Hierarchical Inheritance
            ->Multilevel Inheritance
            ->Hybrid Inheritance
    */
    /*
        (1) Single Inheritance
            -> 1 base class, 1 derived class
        (2) Multiple Inheritance
            -> more than one base class, 1 derived class
        (3) Hierarchical Inheritance
            -> 1 base class, more than one derived class
        (4) Multilevel Inheritance
            -> deriving a class from already derived class
        (5) Hybrid Inheritance
            -> combination of above inheritances
    */
    // Ex:

        // Base Class
        class Employee
        {
            float salary;
        public:
            int id;
            Employee(int empId, float sal=150.0f)
            {
                // Parameterized Constructor of this class
                std::cout << "Employee class parameterized constructor called!!" << std::endl;
                id = empId;
                salary = sal;
            }
            Employee()
            {
                // default constructor for this class
                std::cout << "Employee class default constructor called!!" << std::endl;
            }
        };

        /* * * * * * *  Derived Class Syntax:
            class {derived_class_name} : {visibility_mode} {base_class_name} */
        /*
            -> visibility mode can be either public or priavte
            -> if not specified its private by default * * * 
            -> PRIVATE VISIBILITY MODE: Public members of base become PRIVATE members of derived
            -> PUBLIC VISIBILITY MODE: Public members of base become PUBLIC members of derived
            -> * * * thus, one thing for sure, inheritance herits only public members from base
        */
        // Creating derived class :
        class Programmer : Employee // visibility not specified thus, its private by default
        {
            // thus now, constructor of employee class and id var are private members of this class too
        public:
            Programmer(int empId)
            {
                std::cout << "Programmer class parameterized constructor called!!" << std::endl;
                id = empId;
            }
            Programmer()
            {
                std::cout << "Programmer class default constructor called!!" << std::endl;
            }
        };

        int main()
        {
            Employee rahul; // Calls default 'Employee' constructor
            Employee mahesh(2, 300.0f); // Calls parameterized 'Employee' constructor
            Programmer harry(3); // Calls default 'Employee' constructor first then, parameterized 'Programmer'
            Programmer sushil; // Calls default 'Employee' constructor first then, default 'Programmer'
        }

        // * * * * By running the following code we come to know that,
        // everytime constructor of derived class is called, default constructor of base class also gets executed.. 



// Protected access modifier
    // Just like we had public & private access modifier in class till now, there is protected too
    // protected = similar to private BUT inherit hoga
    /*
        * * * * * * * * * * * * * * * * * * IMP * * * * * * * * * * * * * * * * * * * 

                            (Public derivation)           (Private derivation)          (Protected derivation)

        (Public)            Public                          Private                         Protected
        
        (Private)           NOT INHERITED                   NOT INHERITED                   NOT INHERITED

        (Protected)         Protected                       Private                         Protected
        [members]
    */
   /*
        Trick to remember:
            Private members never inherited
            Public derivation/visibilty -> public members=public & Protected=protected (jaisa hai vaisa rehene dega)
            Private derivation -> sab private karega
            Protected derivation -> sab protected karega
   */



// Multilevel Inheritance
    // Ex:
        class Animals
        {
            int murders; // private (default)
        protected:
            bool relationship;
            int relationships;
        public:
            int legs;
        };

        class Mammals : public Animals // inherit public and protected as it is
        {
            // thus, murders not inherited
            /* 
            inherited code=>
            protected:
                bool relationship;
                int relationships;
            public:
                int legs;
            */
        public:
            int childs;
        };

        class Humans : private Mammals
        {
            /*
            inherited code=>
            private:
                bool relationship;
                int relationships;
                int legs;
                int childs;
            */
        };
        // Multilevel inheritance=>     Animals -> Mammals -> Humans



// Ambiguity Resolution
    // Try this code:
        class SimpleCalculator
        {
        protected:
            float firstNum, SecondNum;
        public:
            void setNum(float a, float b)
            {
                firstNum = a;
                SecondNum = b;
            }
            void getResult ()
            {
                std::cout << "Addition: " << firstNum+SecondNum << std::endl;
                std::cout << "Subtraction: " << firstNum-SecondNum << std::endl;
                std::cout << "Multiplication: " << firstNum*SecondNum << std::endl;
                std::cout << "Division: " << firstNum/SecondNum << std::endl;
            }
            SimpleCalculator()
            {
                std::cout << "Simple Calculator Called!!" << std::endl;
            }
        };

        class ScientificCalculator
        {
        protected:
            float number;
        public:
            void setNum(float a)
            {
                number = a;
            }
            void root()
            {
                std::cout << "Sqrt: " << sqrt(number) << std::endl;
            }
            void logarithm()
            {
                std::cout << "Log: " << log(number) << std::endl;
            }
            void trigo_sin()
            {
                std::cout << "Sin: " << sin(number) << std::endl;
            }
            void trigo_cos()
            {
                std::cout << "Cos: " << cos(number) << std::endl;
            }
            void trigo_tan()
            {
                std::cout << "Tan: " << tan(number) << std::endl;
            }
            ScientificCalculator()
            {
                std::cout << "Scientific Calculator Called!!" << std::endl;
            }
            
        };

        class HybridCalculator : public SimpleCalculator, public ScientificCalculator 
        {
        public:
            HybridCalculator()
            {
                std::cout << "Hybrid Calculator Called!!" << std::endl;
            }
        };

        int main()
        {
            SimpleCalculator calc1;
            calc1.setNum(8, 3);
            calc1.getResult();

            ScientificCalculator calc2;
            calc2.setNum(10);
            calc2.logarithm();
            calc2.root();
            calc2.trigo_sin();
            calc2.trigo_cos();
            calc2.trigo_tan();

            HybridCalculator hyper;
            hyper.setNum(10, 12);
            hyper.setNum(100);
            hyper.getResult();
            hyper.logarithm();

            return 0;
        }
    // Gives error that setNum is ambiguous in hybrid class
    // bcoz there are 2 setNum functions being inherited (1 from simpleCalculator and other from scientificCalculator)
    // solution: create a function in derived class and use it to call the func u want

    // Resolving the Ambiguity: 
        //* * * * * * * * * * * * IMP * * * * * * * * * * * * * * * * * * * * *
        // Create a function in derived class that would call the function that u want :)
        class SimpleCalculator
        {
        protected:
            float firstNum, SecondNum;
        public:
            void setNum(float a, float b)
            {
                firstNum = a;
                SecondNum = b;
            }
            void getResult ()
            {
                std::cout << "Addition: " << firstNum+SecondNum << std::endl;
                std::cout << "Subtraction: " << firstNum-SecondNum << std::endl;
                std::cout << "Multiplication: " << firstNum*SecondNum << std::endl;
                std::cout << "Division: " << firstNum/SecondNum << std::endl;
            }
            SimpleCalculator()
            {
                std::cout << "Simple Calculator Called!!" << std::endl;
            }
        };

        class ScientificCalculator
        {
        protected:
            float number;
        public:
            void setNum(float a)
            {
                number = a;
            }
            void root()
            {
                std::cout << "Sqrt: " << sqrt(number) << std::endl;
            }
            void logarithm()
            {
                std::cout << "Log: " << log(number) << std::endl;
            }
            void trigo_sin()
            {
                std::cout << "Sin: " << sin(number) << std::endl;
            }
            void trigo_cos()
            {
                std::cout << "Cos: " << cos(number) << std::endl;
            }
            void trigo_tan()
            {
                std::cout << "Tan: " << tan(number) << std::endl;
            }
            ScientificCalculator()
            {
                std::cout << "Scientific Calculator Called!!" << std::endl;
            }
            
        };

        class HybridCalculator : public SimpleCalculator, public ScientificCalculator 
        {
        public:
            HybridCalculator()
            {
                std::cout << "Hybrid Calculator Called!!" << std::endl;
            }
            void setNum(float a)
            {
                ScientificCalculator::setNum(a);
            }
            void setNum(float a, float b)
            {
                SimpleCalculator::setNum(a, b);
            }
            // USED AMBIGUITY RESOLUTION AND FUNCTION PROTOTYPING TOGETHER xD
        };

        int main()
        {
            SimpleCalculator calc1;
            calc1.setNum(8, 3);
            calc1.getResult();

            ScientificCalculator calc2;
            calc2.setNum(10);
            calc2.logarithm();
            calc2.root();
            calc2.trigo_sin();
            calc2.trigo_cos();
            calc2.trigo_tan();

            HybridCalculator hyper;
            hyper.setNum(10, 12);
            hyper.setNum(100);
            hyper.getResult();
            hyper.logarithm();

            return 0;
        }



// Virtual Base Class
    /*
        Consider a base class 'A'
        let 'B' and 'C' be classes derived from 'A'
        then 'D' is derived from both 'B' and 'C'

        let class A have variable named 'x'
        now as B and C are derived from A, they will inherit x too
        also, D will inherit x, from both B and C
        thus there will be ambiguity error in D bcoz it will have 2 variables named x
    */
    // VIRTUAL BASE CLASS IS SOLUTION TO THIS ISSUE 
    // kisi bhi virtual base class ke members bas 1 bar inherit hoge within any given class

    // so we could base class A as virtual so that x would be passed only once (as x is data member of A)
    // Syntax for virtual base class:
        // Class B : virtual public A {...}

        class Student
        {
        protected:
            int phone;
        public:
            int rollNo;
        };

        class Sports : virtual public Student
        {
        protected:
            int sportsMarks;
        };

        class Test : virtual public Student
        {
        protected:
            int testMarks;
        };

        class Result : public Sports, public Test
        {
        public:
            void setData(int ph, int roll, int sports, int test)
            {
                phone = ph;
                rollNo = roll;
                sportsMarks = sports;
                testMarks = test;
            }
            void Display()
            {
                std::cout << "Roll No: " << rollNo << std::endl;
                std::cout << "Phone No: " << phone << std::endl;
                std::cout << "Sports Marks: " << sportsMarks << std::endl;
                std::cout << "Test Marks: " << testMarks << std::endl;
            }
        };

        int main()
        {
            int data[4];
            std::cout << "Enter Roll No: ";
            std::cin >> data[1];
            std::cout << "Enter Phone No: ";
            std::cin >> data[0];
            std::cout << "Enter Sports Marks: ";
            std::cin >> data[2];
            std::cout << "Enter Test Marks: ";
            std::cin >> data[3];
            
            Result Harry;
            Harry.setData(data[0], data[1], data[2], data[3]);
            Harry.Display();

            return 0;
        }
        // if we wont virtually inherit Student Class, rollNo and phoneNo will be inherited twice in Result class
        // Thus causing ambiguity error



// Constructors in derived class
    // * * * * * IF BOTH BASE CLASS AND DERIVED CLASS HAVE CONSTRUCTORS THEN CONSTRUCTOR OF BASE CLASS IS EXECUTED FIRST!!

    // For Multiple Inheritance (2 base classes se 1 derived class)
        // ofc base class ka pehele call hoga but which base class..
        // jisko pehele declare kiya hai while making derived class uska constructor pehele call hoga
        class baseClass1
        {
        public:
            baseClass1()
            {
                std::cout << "Base Class 1 Constructor Called !!" << std::endl;
            }
        };

        class baseClass2
        {
        public:
            baseClass2()
            {
                std::cout << "Base Class 2 Constructor Called !!" << std::endl;
            }
        };

        class derivedClass : public baseClass2, public baseClass1
        {
        public:
            derivedClass()
            {
                std::cout << "Derived Class Constructor Called !!" << std::endl;
            }
        };
        // CONSTRUCTOR RUN ORDER ==> baseClass2, baseClass1, derivedClass
        // bcoz baseclass2 is declared first while making derived class



    // For Multilevel Inheritance:
        // Ex: A -> B -> C
        // jab C ka object banega to pehele base class ka constructor (i.e. A)
        // then B
        // then C

    // * * * * * THERE'S AN EXCEPTION TO THIS ORDER...
        // IF VIRTUAL BASE CLASS IS PRESENT THEN ITS CONSTRUCTOR WOULD BE CALLED FIRST
        // [IF MULTIPLE VIRTUAL BASE CLASSES PRESENT THEN AGAIN SAME ORDER RULE BETWEEN THEM]


    
    // * * FOR HYBRID INHERITANCE USE COMBINATION OF THESE RULES 
        // LIKE, if C derived from A and B THEN D derived from C then first A/B depending on rules of multiple inheritance
        // After that remaining using rules of multilevel inheritance



    // Special Syntax * * * 
        // C++ supports special syntax to pass all arguments to constructors of all classes( base+derived ) at once

        class baseClass1
        {
        public:
            int a1;

            baseClass1(){}

            baseClass1(int num1)
            {
                a1 = num1;
                std::cout << "BASE CLASS 1 PARAMETERIZED CONSTRUCTOR CALLED !!" << std::endl;
            }
        };

        class baseClass2
        {
        public:
            int b1;

            baseClass2(){}

            baseClass2(int num1)
            {
                b1 = num1;
                std::cout << "BASE CLASS 2 PARAMETERIZED CONSTRUCTOR CALLED !!" << std::endl;
            }
        };

        class derivedClass : public baseClass1, public baseClass2
        {
        public:
            int c1;

            derivedClass(){}

            // SYNTAX OF PASSING ARGUMENTS TO BASE CLASS CONSTRUCTOR:
            derivedClass(int int1, int int2, int int3): baseClass1(int1), baseClass2(int2)
            {
                c1 = int3;
                std::cout << "DERIVED CLASS PARAMETERIZED CONSTRUCTOR CALLED" << std::endl;
            }
            // So basically, take values as arguments or constructor of derived class 
            // and pass them to base class using above syntax

            friend void display(derivedClass);
        };

        void displayObject(derivedClass d1)
        {
            std::cout << "a1 = " << d1.a1 << std::endl;
            std::cout << "b1 = " << d1.b1 << std::endl;
            std::cout << "c1 = " << d1.c1 << std::endl;
        }

        int main()
        {
            derivedClass obj(1, 2, 3);
            displayObject(obj);
            return 0;
        }



// Initialisation list in Constructors
    // Used to quickly assign values
    /*
        Syntax:
            [Constructor name]() : [initialisation section]
            {
                other constructor code . . 
            }
    */
    // * * * * ALWAYS REMEMBER: jo var pehele declare kiya hai usko pehele initialise karo ( ELSE THROWS ERROR )

    class calculator
    {
        int sum, sub, div, mult;
    public:
        calculator(int num1, int num2) : sum(num1+num2), sub(num1-num2), div(num1/num2), mult(num1*num2)
        {
            std::cout << "Constructor Called !!" << std::endl;

            std::cout << "Addition       -> " << sum << std::endl;
            std::cout << "Subtraction    -> " << sub << std::endl;
            std::cout << "Multiplication -> " << mult << std::endl;
            std::cout << "Division       -> " << div << std::endl;
        }
    };

    int main()
    {
        calculator calc1(6, 3);
        return 0;
    }
    // Thus, for initialisation section:    variable_to_store_data(value_to_set)
    // THE SYNTAX: 
        /*  
            calculator(int num1, int num2) : sum(num1+num2), sub(num1-num2), div(num1/num2), mult(num1*num2)
            {
                std::cout << "Constructor Called !!" << std::endl;
            }

            This is equivalent to below code =>
            calculator(int num1, int num2)
            {
                sum = num1+num2;
                sub = num1-num2;
                div = num1/num2;
                mult = num1*num2;
                std::cout << "Constructor Called !!" << std::endl;
            }

            * * * * * sequence of declaration matters !!
            therefore the variable initialized first could be used to intialize other
            Ex:
                constructor(int num1, int num2) : a(num1+num2), b(a*num1)
                {
                    . . . . 
                }
        */



// new and delete keyword in C++
    // new Keyword -> used to dynamically create variables and store its address in pointer
        // Syntax:
            int *ptr = new int(5);
            std::cout << *(ptr) << std::endl;
            // creates a new variable with value 5 and assigns its address to pointer ptr
            // *ptr while cout for dereferencing pointer

        // To Allocate Block of Memory (array)
            int *ar = new int[3];    // (new integer array with 3 data size)
            ar[0] = 6;
            ar[1] = 11;
            ar[2] = 2;
            std::cout << ar[0] << std::endl;
            std::cout << ar[1] << std::endl;
            std::cout << ar[2] << std::endl;

    // Delete Keyword -> used to delete dynamically allocated variables and blocks of memory
        // Usage:
            int *ptr = new int(5);
            std::cout << *ptr << std::endl; // prints 5
            delete ptr;
            std::cout << *ptr << std::endl; // prints garbage value aas pointer ptr is already deleted



// Pointers to objects and arrow operator in C++
    // JUST LIKE WE USE INTEGER POINTER TO POINT AN INTEGER, WE COULD USE:
    class Complex
    {
        int real, img;
    public:
        void setData(int r, int i)
        {
            real = r;
            img = i;
        }

        void getData()
        {
            std::cout << real << " + " << img << "i" << std::endl;
        }
    };

    int main()
    {
        Complex c1;
        c1.setData(3, 5);
        c1.getData();

        // Pointer to object:
        Complex *ptr = &c1;
        // same like we did for 'int'

        // as we know dereferencing the pointer gives value at address stored in pointer
        (*ptr).getData();   // (*ptr) is equivalent to c1
        // we need to use bracket bcoz precedence of '.' is higher than '*' 
        // so '.' will be executed first before dereferencing,  if we dont put that in bracket

        // making dynamically using new keyword:
        Complex *ptr2 = new Complex;


        // Arrow Operator
        // used to dereference pointer and run its function directly 

        ptr->getData(); // this is equivalent to (*ptr).getData();
        return 0;
    }



// Array of objects using pointers
    class Complex
    {
        int real, img;
    public:
        void setData(int r, int i)
        {
            real = r;
            img = i;
        }

        void getData()
        {
            std::cout << real << " + " << img << "i" << std::endl;
        }
    };

    int main()
    {
        Complex *object = new Complex[3]; // Dynamically created array of 3 objects of class Complex using pointer

        int temp1, temp2;
        for (int i = 0; i < 3; i++)
        {
            std::cout << "Enter Real and Imaginary part for Complex No. " << i+1 << " : ";
            std::cin >> temp1 >> temp2;
            (object+i)->setData(temp1, temp2);
            (object+i)->getData();
        }
        /*
            Equivalent: 
            object->setData(1, 3);
            object->getData();
            (object+1)->setData(2, 4);
            (object+1)->getData();
            (object+2)->setData(3, 5);
            (object+2)->getData();
        */
    }



// this Keyword in C++
    // Try running this code:
        class Dummy{
            int a;
        public:
            void setData(int a)
            {
                a = a;
            }
            
            void getData()
            {
                std::cout << a << std::endl;
            }
        };

        int main()
        {
            Dummy num;
            num.setData(4);
            num.getData();
        }
        // GIVES GARBAGE VALUE AS OUTPUT
        // THIS IS BCOZ IN C++, WHEN WE USED SAME VAR NAME FOR CLASS VAR AS WELL AS FUNC VAR,
        // BY DEFAULT COMPILER GIVES PRIORITY TO LOCAL VARIABLE (i.e. Function Variable in this case)
        // Therefore, while setting value of 'a' , we are actually not setting the value of class variable 'a'

        // 'this' keyword is used to solve the issue
        // " this keyword is a pointer that points to the object that is invoking the member function "

        // Solution: 
            class Dummy{
            int a;
            public:
                void setData(int a)
                {
                    this->a = a; 
                    // this will point to object, and this->a will be equivalent to object ka member var 'a'
                }
                
                void getData()
                {
                    std::cout << a << std::endl;
                }
            };

            int main()
            {
                Dummy num;
                num.setData(4);
                num.getData();
            }



// Polymorphism in C++
    // Polymorphism = multiple forms of single thing
    // Example of polymorphism that we already did => function overloading
    
    /*
        Types of Polymorphism in C++:
        1. Compile Time Polymorphism
            1.1 Function Overloading
            1.2 Operator Overloading
        2. Run Time Polymorphism
            2.1 Virtual Functions
    */



// Pointers to Derived Class
    // pointers of base class can be used to point to objects of derived class
    // but.. this pointer can only be used to call and set var's that are inherited from base class 
    // (to which the pointer points)
    class Base
    {
    public:
        int base;
        void display()
        {
            std::cout << "[base class display] var_base: " << base << std::endl;
        }
    };
    
    class Derived : public Base
    {
    public:
        int derived;
        void display()
        {
            std::cout << "[derived class display] var_base: " << derived << std::endl;
            std::cout << "[derived class display] var_derived: " << derived << std::endl;
        }
    };
    
    int main()
    {
        Derived derivedClassObject;
        Base *base_class_pointer = &derivedClassObject;
        base_class_pointer->base = 3;
        base_class_pointer->display();
        base_class_pointer->derived = 4; 
        // THIS LINE GIVES ERROR AS 'DERIVED' VARIABALE IS NOT THE MEMBER INHERITED FROM CLASS TO WHICH THE POINTER POINTS

        // Even when we called display function, the one inherited from base class is called

        Derived *derived_class_pointer = &derivedClassObject;
        derived_class_pointer->derived = 444;
        derived_class_pointer->display();
        // Normal pointer to object of same class, so it can access and call all functions of that class
    }



// Virtual Functions (used in runtime polymorphism)
    // Like above case, if pointer points to base class and object is of derived class
    // we could only run functions from base class
    // VIRTUAL FUNCTIONS SOLVE THIS ISSUE BY ALLOWING US TO RUN FUNCTIONS FROM CLASS IN WHICH OBJECT IS CREATED

    // CODE 1 ( without using virtual function )
    class Base
    {
    public:
        int base;
        void display()
        {
            std::cout << "[base class display] var_base: " << base << std::endl;
        }
    };

    class Derived : public Base
    {
    public:
        int derived;
        void display()
        {
            std::cout << "[derived class display] var_base: " << base << std::endl;
            std::cout << "[derived class display] var_derived: " << derived << std::endl;
        }
    };

    int main()
    {
        Base *base_class_pointer;
        Derived derivedClassObject;
        base_class_pointer = &derivedClassObject;
        base_class_pointer->display();
    }



    // CODE 2 ( with virtual function )
    class Base
    {
    public:
        int base;
        virtual void display() // pointer jis class ko point kar raha hai uske function ko virtual bana diya
        {
            std::cout << "[base class display] var_base: " << base << std::endl;
        }

        // now if, function with same name is available in class of object then, it is used when called with pointer
    };

    class Derived : public Base
    {
    public:
        int derived;
        void display()
        {
            std::cout << "[derived class display] var_base: " << base << std::endl;
            std::cout << "[derived class display] var_derived: " << derived << std::endl;
        }
    };

    int main()
    {
        Base *base_class_pointer;
        Derived derivedClassObject;
        base_class_pointer = &derivedClassObject;
        base_class_pointer->display(); // runs display function from derived class as it is declared virtual in base class
    }



// Real life use of Virtual Functions
    class codeWithHarry
    {
    protected:
        string title; // declare "using std::string" in start
        float rating;

    public:
        codeWithHarry(string s, float r)
        {
            // constructor
            title = s;
            rating = r;
        }

        virtual void display()
        {
            // this display is kept empty as we would be using different display for video tutorial and different one for text tutorial
        }
    };

    class videoTutorial : public codeWithHarry
    {
        float videoLength;
    public:
        videoTutorial(string s, float r, float vl) : codeWithHarry(s, r)
        {
            videoLength = vl;
        }
        void display()
        {
            std::cout << "[ videoTutorial class display called ]" << std::endl;
            std::cout << "Title -> " << title << std::endl;
            std::cout << "Rating -> " << rating << std::endl;
            std::cout << "videoLength -> " << videoLength << std::endl;
        }
    };

    class textTutorial : public codeWithHarry
    {
        int wordCount;
    public:
        textTutorial(string s, float r, int wc) : codeWithHarry(s, r)
        {
            wordCount = wc;
        }
        void display()
        {
            std::cout << "[ videoTutorial class display called ]" << std::endl;
            std::cout << "Title -> " << title << std::endl;
            std::cout << "Rating -> " << rating << std::endl;
            std::cout << "videoLength -> " << wordCount << std::endl;
        }
    };

    int main()
    {
        // creating pointers to point the objects
        codeWithHarry *base_class_pointer_for_video_tutorial;
        codeWithHarry *base_class_pointer_for_text_tutorial;

        // creating objects of derived class
        videoTutorial vid("video1", 4.9, 10);
        textTutorial txt("textTut1", 3, 1200);

        base_class_pointer_for_video_tutorial = &vid;
        base_class_pointer_for_text_tutorial = &txt;

        base_class_pointer_for_video_tutorial->display();   
        base_class_pointer_for_text_tutorial->display();

        return 0;
    }

    // Study this code to get an idea of how we used virtual function for runtime polymorphism
/*
    RULES OR VIRTUAL FUNCTIONS:
        -> They cannot be declared as static functions
        -> The concept of virtual functions is used only by object pointers
        -> BUT THEY CAN BE FRIEND FUNCTION OF ANOTHER CLASS
        -> Not necessary that we must declare function with same name in derived class (if func with same name not present, virtual func is ran)
*/



// Pure Virtual Functions (aka do nothing function)
    //  When we need to ALWAYS want to use func with same name in derived class, and never use func of base class, pure virtual function is used
    // Every Derived class must have func with same name if we declare func as pure virtual
    // EX: 

    // Code [1]: (normal virtual function)
    class codeWithHarry
    {
    protected:
        string title;
        float rating;

    public:
        codeWithHarry(string s, float r)
        {
            title = s;
            rating = r;
        }

        virtual void display(){}
    };

    class videoTutorial : public codeWithHarry
    {
        float videoLength;
    public:
        videoTutorial(string s, float r, float vl) : codeWithHarry(s, r)
        {
            videoLength = vl;
        }
        void display()
        {
            std::cout << "[ videoTutorial class display called ]" << std::endl;
            std::cout << "Title -> " << title << std::endl;
            std::cout << "Rating -> " << rating << std::endl;
            std::cout << "Word Count -> " << videoLength << std::endl;
        }
    };

    class textTutorial : public codeWithHarry
    {
        int wordCount;
    public:
        textTutorial(string s, float r, int wc) : codeWithHarry(s, r)
        {
            wordCount = wc;
        }
    };

    int main()
    {
        codeWithHarry *base_class_pointer_for_video_tutorial;
        codeWithHarry *base_class_pointer_for_text_tutorial;

        videoTutorial vid("video1", 4.9, 10);
        textTutorial txt("textTut1", 3, 1200);

        base_class_pointer_for_video_tutorial = &vid;
        base_class_pointer_for_text_tutorial = &txt;

        base_class_pointer_for_video_tutorial->display(); // calls display from video class 

        base_class_pointer_for_text_tutorial->display(); 
        // calls display from codeWithHarry 'base class' as display not present in derived class 'text'

        return 0;
    }


    // Code [2] : (pure virtual function)
    class codeWithHarry
    {
    protected:
        string title;
        float rating;

    public:
        codeWithHarry(string s, float r)
        {
            title = s;
            rating = r;
        }

        virtual void display() = 0; // DECLARATION OF PURE VIRTUAL FUNCTION
    };

    class videoTutorial : public codeWithHarry
    {
        float videoLength;
    public:
        videoTutorial(string s, float r, float vl) : codeWithHarry(s, r)
        {
            videoLength = vl;
        }
        void display()
        {
            std::cout << "[ videoTutorial class display called ]" << std::endl;
            std::cout << "Title -> " << title << std::endl;
            std::cout << "Rating -> " << rating << std::endl;
            std::cout << "videoLength -> " << videoLength << std::endl;
        }
    };

    class textTutorial : public codeWithHarry
    {
        int wordCount;
    public:
        textTutorial(string s, float r, int wc) : codeWithHarry(s, r)
        {
            wordCount = wc;
        }
    };

    int main()
    {
        codeWithHarry *base_class_pointer_for_video_tutorial;
        codeWithHarry *base_class_pointer_for_text_tutorial;

        videoTutorial vid("video1", 4.9, 10);
        textTutorial txt("textTut1", 3, 1200);

        base_class_pointer_for_video_tutorial = &vid;
        base_class_pointer_for_text_tutorial = &txt;

        base_class_pointer_for_video_tutorial->display(); // calls display from video class 
         
        base_class_pointer_for_text_tutorial->display(); 
        // calls display from codeWithHarry 'base class' as display not present in derived class 'text'

        return 0;
    }

    // CODE 2 WILL GIVE ERROR AS BASE CLASS DISPLAY IS PURE VIRTUAL AND IT CANT BE CALLED
    // THUS FUNCTION WITH SAME NAME MUST BE PRESENT IN DERIVED CLASS (TEXT)



// Abstract Base Class
    // aisi class jisko banaya hi jata hai dusri classes banane ke liye
    // thus, abstract base classes contain at least 1 pure virtual function * * * 




// ---------------------------- FILE I/O IN C++ ---------------------------------

// "fstream" has some default classes to play around with file

/*
    Useful classes to work with files in C++ :
        -> fstreambase          [base]
        -> ifstream             [derived]
        -> ofstream             [derived]
*/

/*
    In order to work with files in C++, we need to first open them
    1. using constructor
    2. using member function open()
    of the classes listed above 
*/

/*
    Reading/Writing to a File:
        -> Create an object of class ifstream/ofstream
        -> Use that object to read or write to file
*/

// EX:
    #include <iostream>
    #include <fstream>

    int main()
    {
        std::ofstream writer("Sample.txt");  // Used Constructor to open file
        writer << "text_to_be_written";  // writing to that file
        return 0;
    }


// Using member function " open() " to open a file and write to it
    int main()
    {
        std::ofstream writer;
        writer.open("Sample.txt");
        writer << "text_to_be_written";
        return 0;
    }


// Reading from a file
    int main()
    {
        std::ifstream reader("Sample.txt"); // used constructor to open file
        std::string s1;
        reader >> s1; // copied data from our object to string
        std::cout << s1;  // cout string
    }

    // Limitations: this will read from the file BUT, wont work on spaces and new lines
    // i.e. it will only read the 1st word before and space or newline comes
    // Solution: Use getline(from, to) function to get 1 complete line

    int main()
    {
        std::ifstream reader("Sample.txt");
        std::string s1;
        getline(reader, s1);
        std::cout << s1;
        reader.close(); // * * GOOD PRACTISE TO CLOSE FILE AFTER USAGE
    }

    // * * USING getline() multiple times gives us other lines in files
    // Ex: using getline() 2 times will give us second line



// Getting Whole Document using getline
    // We could use "eof" (end of file) member function for our object created
    // eof returns 0 if the end of file is not yet reached

    // EX:
        int main()
        {
            std::fstream reader;
            reader.open("Sample.txt");
            std::string s1;

            while (reader.eof() == 0) // i.e. end o ile not reached
            {
                getline(reader, s1);
                std::cout << s1 << std::endl;
            }

            reader.close();
            return 0;
        }



// C++ Templates
    /*
        Just like
        Class -> Object
        Template -> Class

        Suppose we want to create a class that has int as members
        then other classes that has float, char and so on as members
        It would be too much code and repetition
        So,
        We create a class template that could be used to create Multiple Classes
    */

   // Ex for C++ Template:
    class vector
    {
        int arr[3];
    public:
        vector(int x, int y, int z)
        {
            arr[0] = x;
            arr[1] = y;
            arr[2] = z;
        }
        
        int dotProduct(vector v)
        {
            int d = 0;
            for (int i = 0; i < 3; i++)
            {
                d += this->arr[i] * v.arr[i];
            }
            return d;
            
        }
    };

    int main()
    {
        vector v1(3, 6, 3), v2(2, 1, 2);
        std::cout << v1.dotProduct(v2);
        return 0;
    }

    // WHAT IF WE WANT TO USE FLOATING POINTS INSTEAD OF INT IN THIS
    // INSTEAD ON CREATING NEW CLASS WE COULD MODIFY THIS CLASS USING TEMPLATE AS BELOW:

    template <class T> // represents that jaha jaha 'T' use hoga vaha ek custom data type hai jo badme specify hoga
    class vector
    {
        T arr[3];
    public:
        vector(T x, T y, T z)
        {
            arr[0] = x;
            arr[1] = y;
            arr[2] = z;
        }
        
        T dotProduct(vector v)
        {
            T d = 0;
            for (int i = 0; i < 3; i++)
            {
                d += this->arr[i] * v.arr[i];
            }
            return d;
            
        }
    };

    int main()
    {
        vector<float> v1(3.1, 6.2, 3.1), v2(2.1, 1.2, 2.1); // specifying data type to replace with 'T' like this
        std::cout << v1.dotProduct(v2);
        return 0;
    }



// Multi Parameter Templates (more than one parameters)
    template <class T, class B>
    class myClass
    {
        T data1;
        B data2;
    public:
        myClass(T d1, B d2)
        {
            data1 = d1;
            data2 = d2;
        }
        void display()
        {
            std::cout << this->data1 << " and " << this->data2 << std::endl;
        }
    };

    int main()
    {
        myClass<int, char> obj(3, 'a');
        obj.display();
        return 0;
    }



// Templates with default Parameters
    // We could provide default values to Template variables that will be used if data type is not provided
    template <class T1=int, class T2=float>
    class myClass
    {
        T1 data1;
        T2 data2;
    public:
        myClass(T1 v1, T2 v2)
        {
            data1 = v1;
            data2 = v2;
        }

        void display()
        {
            std::cout << "Size of first data type is: " << sizeof(T1) << " and its value is " << data1 << std::endl;
            std::cout << "Size of second data type is: " << sizeof(T2) << " and its value is " << data2 << std::endl;
        }
    };

    int main()
    {
        myClass<float, char> obj1(2.1, 'w');
        obj1.display();

        myClass< > obj2(2, 3.3);
        obj2.display();
        return 0;
    }



// Function Template
    // Uses Template parameter in function
    // EX(1):
    template <class T1>
    T1 avg(T1 a, T1 b)
    {
        T1 average = (a+b)/2;
        return average;
    }

    int main()
    {
        std::cout << avg(2.5,10.5) << std::endl;
        std::cout << avg(2,10) << std::endl;
        return 0;
    }
    // Thus, can be used for both integer type values and floating point values

    //EX(2):
    template <class T1>
    void swap(T1 &a, T1 &b)
    {
        T1 temp = a;
        a = b;
        b = temp;
    }

    int main()
    {
        int num1=5, num2=7;
        char char1='a', char2='z';
        std::cout << "BEFORE: " << std::endl;
        std::cout << "Num1: " << num1 << " & Num2: " << num2 << std::endl;
        std::cout << "Char1: " << char1 << " & Char2: " << char2 << std::endl;
        swap(num1, num2);
        swap(char1, char2);
        std::cout << std::endl;
        std::cout << "AFTER: " << std::endl;
        std::cout << "Num1: " << num1 << " & Num2: " << num2 << std::endl;
        std::cout << "Char1: " << char1 << " & Char2: " << char2 << std::endl;
        return 0;
    }
    // As, we had seen before, send reference o variable while swapping else it wont swap



// Using Templates if we are using function prototyping for member functions of a Class
    template <class T>
    class myClass
    {
    public:
        T data;

        myClass(T a)
        {
            data = a;
        }

        void display();
    };

    template <class T> // declare T again
    void myClass<T>::display() //write className<templateParameterName>::funcName instead of className::funcName like before
    {
        std::cout << data;
    }

    int main()
    {
        myClass<int> obj(22);
        obj.display();
        return 0;
    }



// Function overloading using templates
    template <class T>
    void func(T a)
    {
        std::cout << "Template function called !" << std::endl;
        std::cout << a << std::endl;
    }

    void func(int a)
    {
        std::cout << "Int specific function called !" << std::endl;
        std::cout << a << std::endl;
    }

    int main()
    {
        func(3);
        return 0;
    }
    // Run this code with overloaded func and see the output
    // Yoou will notice that int specific function runs even though there us generak template present
    // This is bcoz exact functions take higher priority than template functions



// C++ STL
    // Library of generic classes and functions used to make coding faster especially in competitive environment
    /*
        Components of STL:
            -> Containers (stores data, ex: vectors, lists, etc)
            -> Algorithms (process data, ex: sorting, searching, etc)
            -> Iterators (its an object that points to a element in a container)
                        (it is an object but handeled just like pointers)
                        (connects algorithms to containers)
    */



// Containers in C++
    // Three types of containers in C++
    // 1. Sequence Containers 
        // linear fashion mei store karna
        // []->[]->[]->[]
        // ex: Vector, List, Dequeue (double ended queue)
        // these type of container are quite slow in search algo, as u would need to check all list 1 by 1
    // 2. Associative Containers
        // Direct access containers i.e. data store in tree like structure
        // ex: set, multiset, map, multimap
    // 3. Derived Containers
        // derived from sequence and associative containers
        // made according to real world modelling
        // like, stack is like an array but follows LIFO (last in first out) principles used in real life
        // Queue follows FIFO (first in first out)
        // ex: Stack, queue



// Vectors
    // must use #include <vector>

    // Same like array but,
    // array cant be dynamically resized
    // like, if there is arr[10], we cant put 11th element in it
    // In vector, we could keep on adding elements, it automatically manages its size

    // use cplusplus.com to see member functions/methods or any container

    void setVec(std::vector<int> &vec)
    {
        int length, element;
        std::cout << "Enter the number of elements you want to add in Vector: ";
        std::cin >> length;
        for (int i = 0; i < length; i++)
        {
            std::cout << "Enter element " << i + 1 << " : ";
            std::cin >> element;
            vec.push_back(element);
        }
    }

    void displayVec(std::vector<int> &vec)
    {
        std::cout << "Your Vector is:  ";
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i] << " ";
        }
    }

    int main()
    {
        std::vector<int> vec1; // Creates vector of 0 length (resizeable)
        //std::vector<int> vec2(7); // Creates vector of length 7
        setVec(vec1);
        displayVec(vec1);

        return 0;
    }

    // push_back method -> pushes element to vector
    // pop_back -> pulls back the last element from vector
    // size -> gives length of vector
    // There are many more, check cplusplus.com



// Iterator and insert method of vector
    // Iterator is an object to class like vectors, lists etc
    // but acts like pointer to an element
    // Declaring an Iterator:
        // className<dataType> :: iterator iteratorName = valueToPoint

    // EX:
        void setVec(std::vector<int> &v)
        {
            int length, element;
            std::cout << "Enter number of elements you want to add: ";
            std::cin >> length;
            for (int i = 0; i < length; i++)
            {
                std::cout << "Enter your element: ";
                std::cin >> element;
                v.push_back(element);
            }
        }

        void displayVec(std::vector<int> &vec)
        {
            std::cout << std::endl;
            std::cout << "Your Vector is:  ";
            for (int i = 0; i < vec.size(); i++)
            {
                std::cout << vec[i] << " ";
            }
        }

        int main()
        {
            std::vector<int> vec1;
            setVec(vec1);
            displayVec(vec1);

            //declaring iterator and setting it to point first element of vector
            std::vector<int>::iterator iter = vec1.begin();

            // using insert method to insert value in vector
            // insert method take 2 args
            // 1. iterator to var jiske pehele insert karna hai
            // 2. value that you wanna insert
            vec1.insert(iter, 6969);

            // suppose we wanna insert at 5th place, then use iter+4
            // bcoz iter points at 1 (i.e. index 0) therefore, iter+4 will point 5th position (i.e. index 4)

            // suppose we need to insert multiple copies at same place
            // we can use overloaded version of insert method (having 3 arguments)
            // i.e.  vec1.insert(iterator, numberOfCopiesToInsert, valueToInsert)

            displayVec(vec1);

            return 0;
        }
        // SEE WEB FOR MORE METHODS (There are lot of them)



// Lists in C++
    // use #include <list>
    // Array -> continuous memory location for data
    // List -> like array, but not necessarily continuous in memory like array
    // each List item container -> [data, ptr to next data member]

    // Therefore advantage over array =>
        // agar array mei middle element delete ya add karna ho to saare element shift karne hoge
        // but in list we can just make new data and ptr and change ptr's in such a way that it includes new data

    // Disadvantage =>
        // slower access than array as we need more around ptr's to get to our required index

    // Ex: Create a program to take input list from user, allow adding integers in between, del values, etc

    #include <iostream>
    #include <list>

    void display(std::list<int> &lst)
    {
        std::list<int>::iterator itera = lst.begin();
        for (int i = 0; i < lst.size(); i++)
        {
            std::cout << *(itera) << " ";
            itera++;
        }

        std::cout << std::endl;
    }

    void insertNum(std::list<int> &lst, int position, int num)
    {
        std::list<int>::iterator iter = lst.begin();

        for (int i = 1; i < position; i++, iter++)
            ;

        lst.insert(iter, num);
    }

    void eraseNum(std::list<int> &lst, int posStart, int posEnd)
    {
        std::list<int>::iterator iterStart = lst.begin();
        std::list<int>::iterator iterEnd = lst.begin();

        for (int i = 1; i < posStart; i++, iterStart++)
            ;
        for (int i = 1; i < posEnd; i++, iterEnd++)
            ;

        lst.erase(iterStart, iterEnd); // start included, end excluded
    }

    int menu();

    int main()
    {
        std::list<int> list1;
        int len, element;

        std::cout << "How many elements do you want to insert in list: ";
        std::cin >> len;
        for (int i = 0; i < len; i++)
        {
            std::cout << "Enter list item " << i + 1 << " : ";
            std::cin >> element;
            list1.push_back(element);
        }

        while (true)
        {
            std::cout << std::endl;
            std::cout << std::endl;

            int choice = menu();
            if (choice == 1)
            {
                std::cout << "At what position do you want to insert the number: ";
                int pos, num;
                std::cin >> pos;
                std::cout << "What's the number that you want to insert: ";
                std::cin >> num;
                insertNum(list1, pos, num);
            }
            else if (choice == 2)
            {
                int start, end;
                std::cout << "What's the position of first number that you want to erase: ";
                std::cin >> start;
                std::cout << "What's the position of last number that you want to erase: ";
                std::cin >> end;
                end += 1; // bcoz erase method wont include that number on last pos
                eraseNum(list1, start, end);
            }
            else if (choice == 3)
            {
                std::cout << "Your list is:  ";
                display(list1);
            }
        }

        return 0;
    }

    int menu()
    {
        int choice;
        std::cout << "1 : Insert Number to list" << std::endl;
        std::cout << "2 : Erase Number from list" << std::endl;
        std::cout << "3 : Display list" << std::endl;
        std::cout << "4 : EXIT" << std::endl;
        std::cin >> choice;

        if (choice == 1)
        {
            return 1;
        }
        else if (choice == 2)
        {
            return 2;
        }
        else if (choice == 3)
        {
            return 3;
        }
        else if (choice == 4)
        {
            exit(0);
        }
        else
        {
            std::cout << " INVALID CHOICE!! " << std::endl;
            std::cout << std::endl;
            exit(0);
        }
    }

    // use list.sort() method to sort list items in ascending order
    // use list1.merge(list2) to merge list2 elements in list 1



// Maps in C++
    // used to store data in key value pairs
    // Ex: to store marks of ppl, we would map them with their names [names=key, marks=value]
    // Thus, map is an associative array
    // Ex of map:
        #include <iostream>
        #include <map>
        #include <string>

        int main()
        {
            std::map<std::string, int> marksMap;
            marksMap["Suyog"] = 90;
            marksMap["Sushil"] = 1;
            marksMap["Random"] = 40;
            std::map<std::string, int>::iterator iter;

            for(iter=marksMap.begin(); iter!=marksMap.end(); iter++)
            {
                std::cout << (*iter).first << " " << (*iter).second << std::endl;
            }
            // (*iter).first gives us key and (*iter).second gives us value
            
            
            return 0;
        }
        // INITIALISED FOR LOOP WITH ITER ITSELF TO REDUCE 1 var usage