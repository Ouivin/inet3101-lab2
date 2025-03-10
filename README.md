# inet3101-lab2

Code for INET 3101 Lab 2: Memory and Structure

# Overview:
The program gives an in-memory database of a Parts Inventory Records. Each record stores information about a part’s number, name, size, metric, and cost. The application dynamically allocates and frees memory so that the database expands or shrinks whenever records are added or deleted by the user, additionally no linked lists were used. 

# Program Operation:
Main() displays a menu with the following options:

Print all records
Print number of records
Print size of database
Add record
Delete last record
Exit
Based on user input, it'll call the corresponding method to handle that operation.

# Methods

## printAllRecords:
- Prints all records stored in the database.
- includes record’s part number, name, size, metric, and cost.
- If there are no records, a message will be prompted to user.

## addRecord:
- Asks user for part number, name, size, metric, and cost, then stores the inputted values in the new record.
- Dynamically increases the size of the database by one using realloc()

## deleteLastRecord:
- Removes the last record from the database and decreases total count by one while resizing the database.
- A message will notify the user if there are no records to delete.

# Memory Management

## Allocation:
- The database begins as NULL and program uses realloc() to allocate space for a struct part when a new record is added.

## Resizing:
- When deleting a record, database will be resized to store numRecords - 1 elements.
- When a record is added, database will be resized to store numRecords + 1 elements.

## Deallocation:
- Any allocated memory is freed at program exit.
- If database is empty, deallocation will not function.
