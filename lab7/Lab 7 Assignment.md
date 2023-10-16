**Data Structures (2028C) -- Fall 2023 – Lab 7 *Topics covered: Pointers and Ordered Lists*** 

*Lab due: **Monday, Oct 16 at 11:55PM for Tuesday Section*** 

`    `***Tuesday, Oct 17 at 11:55PM for Wednesday Section***               ***Wednesday, Oct 18 at 11:55PM for Thursday Section*** 

**Objective:** 

The objective of this Lab is to manipulate an ordered list and explore possible efficiency options in creating the list. 

**Task 1:**  Create an ordered list class. 

1. Create a new project.  You can name this whatever you like. 
1. Design and implement an ordered list class using an array of pointers as described in class.  This class should be a template.   
   1. The class should have an array that holds 25 items. 
   1. The AddItem method should start at the front of the array (index 0) when searching for a place to insert a new item. 
   1. The RemoveItem method should ensure that the items in the array are still in order and there are no empty spots between items. 
   1. The class should include IsEmpty, IsFull and MakeEmpty methods. 
1. Any error conditions encountered such as the item to be removed doesn’t exist or the list is full when trying to add an item should throw a custom error class. 

Complete this before moving on to task 2. 

**Task 2:**  Create a derived class from the class created in Task 1.  This version of the class is to investigate the theory that by starting from the middle (index 12), fewer items will need to be moved on every insert. 

1. This version should have the AddItem method start from the middle of the array when searching for a place to insert a new item. 
1. This version may move left or right when inserting but can’t go past the end of the array.  If there is still room in the array but not in the direction needed, you will need to shift everything over when inserting. For example, if you have the following array and want to insert 50 to this array, you should shift everything to the left by 1. 



||1 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10 |11 |12 |13 |14 |15 |16 |17 |18 |19 |20 |30 |40 |60 |
| :- | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |

Complete this before moving on to task 3. 

**Task 3:**  Create another derived class from the class created in Task 1.  This version of the class is to investigate leaving blank spots (points to a null) in the array can reduce the number of moves when inserting. 

1. Modify the AddItem method to insert an item halfway between any two items in the array where it belongs.  If this array is empty, it should add the new item in the middle (index 12). If this array has one item, it should add the new item halfway between the middle and beginning/end, where the  direction  is  determined  by the value of the new item.  The AddItem method should only move items in the array if the inserting item sits between two items that are in contiguous locations. 
2. Modify the RemoveItem method so that it will not move any items in the array.  Instead, it will just make that spot = to null. 
2. Include in your lab submission a paragraph for each of the 3 versions of the class a description of what are trying to achieve, what the strengths and weaknesses are and how you think it will perform. 

Complete this before moving on to task 4. **Task 4:**  Create a test program. 

1. Create a test program to test the 3 classes’ performance. 
   1. This should instantiate each of the three classes. 
   1. This should insert 30 randomly generated items into the array (using integers between 0 and 100 as the list data type might be the easiest way to do this). 
   1. This should remove 25 items from the array. 
   1. Individual inserted and removed from steps b and c should be randomly selected rather than done sequentially. For example, you can begin by adding an item, then adding another one, then removing an item, and so on. 
   1. Every insert/remove operation should be identically performed against all 3 of the class instances. For example, if you insert 20 to the instance of the first class, you also need to insert 20 to the instances of the other two classes. 
   1. Every comparison and move operation in the AddItem and RemoveItem methods should be counted (except checks to see if an array location holds a nullptr).  In other words, you need to count the total number of comparison and move operations for inserting 30 items and removing 25 items. The total at the end of the run should be displayed to measure efficiency of each class. 
1. Run the program 100 times (use a loop) against the 3 versions of the class.  You should display the total number of comparison and move operations across 100 runs. Describe your results and how they compare with your expected results from the end of Task 3. 
1. Increase the size of the array to hold 50 items. And rerun the program 100 times (the same as task 4.2).  Describe your results and how they compare with the previous step. 
1. Decrease the size of the array to hold 10 items and rerun the program 100 times (the same as task 4.2).  Describe your results and how they compare with the previous step. 
1. Include in the lab report a screen shot(s) of the output of a test.  Include a discussion of how you designed your program to simplify running it and reporting results 100 times.   

**Lab Submission:** 

1. Write a lab report including the following information: 
1. A description of the objectives/concepts explored in this assignment including why you think they are important to this course and a career in CS and/or Engineering. 
1. The sections from each task indicated to be included in the lab report.  
2. Include all source code from all tasks, input and output files (if any), and any special instructions to compile and run those programs. 
2. 1) Submit a lab report to Canvas. 2) Package all source code files in a single zip folder and submit to Canvas. Please submit the lab report and zip folder separately. 

**Lab Grading:** 

1. 10% - Lab attendance 
1. 10% - Task 1 has been correctly implemented and meets all requirements. 
1. 5% - Task 2 has been correctly implemented and meets all requirements.  
1. 10% - Task 3 has been correctly implemented and meets all requirements. 
1. 35% - Task 4 has been correctly implemented and meets all requirements. 
1. 30% - Lab report contains all required information and is well written. 

If program fails to compile, 0% will be given for that Task. 
