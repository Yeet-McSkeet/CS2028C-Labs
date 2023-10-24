**Data Structures (2028C) -- Fall 2023 – Lab 8 *Topics covered: Linked Lists*** 

*Lab due: **Monday, Oct 30 at 11:55PM for Tuesday Section*** 

`    `***Tuesday, Oct 31 at 11:55PM for Wednesday Section***              ***Wednesday, Nov 1 at 11:55PM for Thursday Section*** 

**Objective:** 

The objective of this Lab is to explore creating and using an ordered linked list. 

**Task 1:**  Create an ordered double linked list class. 

1. Create a new project.  You can name this whatever you like. 
1. Design and implement an ordered linked list class as described in class.  This class should be a template.  The template is expected to have overloaded the >, < and == operators. 
1. The class should have the following methods fully implemented. 
1. Constructor 
1. AddItem – adds an item from the list 
1. GetItem – searches the list for the given item.  If found, it removes it from the list and returns it.  If not found, it returns a null pointer. 
1. IsInlist – returns a bool indicating if the given item is in the list. 
1. IsEmpty – returns a bool indicating if the list is empty. 
1. Size – returns an int indicating the number of items in the list. 
1. SeeAt – Finds an item at a location in the list (int passed in from user), and returns the item without removing it.  If the location passed by the user is past the end of the list, this will throw an error. The class will maintain the location and will start at the first item in the list. SeeAt will set the location to point at the item after the item returned. 

viii.  SeeNext  – returns the item next  to  current  location in  the list  without removing it from the list. The current location is set by SeeAt. When it gets 

to the last item in the list, it will return a null pointer after it gets past the last item.  If the list is empty, this will throw an error.  2 calls to SeeNext will return the 2 items next to each other in the list unless SeeAt or Reset is called in between the 2 calls (or the first call returns the last item in the list). 

9. SeePrev – Same as SeeNext except in the other direction.  
9. Reset – resets the location that the SeeNext and SeePrev functions use to point at the first item in the list. 
9. Destructor – make sure you remove all items to avoid memory leaks. 
2. All items passed to or from the class should be done so via a pointer rather than by value. 
2. Make sure you don’t have any memory leaks. 

Complete this before moving on to task 2. 

**Task 2:**  Create a class to be used as the item stored in the list.  You need to use this class in the first class to store items. It should have the following members at a minimum. 

1. Private: 
   1. SKU – stock keeping number 
   1. Description 
   1. Price 
   1. UOM - Unit of measure (is it sold by the foot, pound, each, etc…) 
   1. QuantityOnHand 
   1. LeadTime (number of days it takes to order if there aren’t any on hand to sell) 
1. Public: 
1. Constructor – This accepts parameters for SKU, Description, Price, and UOM.  It has an optional parameter for QuantityOnHand which if missing is set to 0. 
1. GetPartInfo  –  this  returns  a  string  containing  both  SKU  concatenated  with Description 
1. GetPrice – this returns the price 
1. InStock – returns a bool indicating if the Quantity On Hand is >0.   
1. Overloads of the >, < and == operators that compare the SKU member of two Part instances. 

Complete this before moving on to task 3. 

**Task 3:**  Create a test program that has a menu allowing you to test each of the functions in your linked last class (Task 1). 

1. This should present the user with a choice of public member functions of your linked list class and ask which the user would like to try. 
1. When the user selects a member function, the program will prompt the user for any required information.  For example, the GetItem function only requires a SKU as that is what is being compared but the AddItem requires the user to enter a SKU, Description, Price, UOM and optionally a QuantityOnHand. 
1. Test your program.  Include a screen shot of some of this testing in your lab report. 

**Lab Submission:** 

1. Write a lab report including the following information: 
   1. A description of the objectives/concepts explored in this assignment including why you think they are important to this course and a career in CS and/or Engineering. 
   1. The sections from each task indicated to be included in the lab report.  
1. Include all source code from all tasks, input and output files (if any), and any special instructions to compile and run those programs. 
1. 1) Submit a lab report to Canvas. 2) Package all source code files in a single zip folder and submit to Canvas. Please submit the lab report and zip folder separately. 

**Lab Grading:** 

1. 10% - Lab attendance 
1. 30% - Task 1 has been correctly implemented and meets all requirements. 
1. 15% - Task 2 has been correctly implemented and meets all requirements.  
1. 15% - Task 3 has been correctly implemented and meets all requirements. 
1. 30% - Lab report contains all required information and is well written. 

If program fails to compile, 0% will be given for that Task. 
