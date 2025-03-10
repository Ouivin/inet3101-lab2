# inet3101-lab2

Code for INET 3101 Lab 2: Memory and Structure

# Overview:
This program provides an in-memory database of a Parts Inventory Records. Each record stores information about a part’s number, name, size, metric, and cost. The application dynamically allocates and frees memory so that the database grows and shrinks as records are added or deleted, no linked list was used. There is also no file I/O, so once the program exits all data is lost.

# Program Operation:
Main() displays a menu with the following options:

Print all records
Print number of records
Print size of database
Add record
Delete last record
Exit
Based on user input, it'll call the corresponding method to handle that operation.

Will assume that option 3, by printing the size of the database, it means printing the size of it in bytes.

# Methods

## printAllRecords:
- Prints all records currently stored in the database.
- Shows each record’s part number, name, size, metric, and cost.
- If there are no records, a message will notify the user

## addRecord:
- Dynamically increases the size of the database by one record using realloc()
- Prompts the user for part number, name, size, metric, and cost, then stores these values in the newly allocated record.

## deleteLastRecord:
- Removes the last record from the database.
- Decreases the total count by one and resizes the database accordingly.
- If there are no records to delete, a message will notify the user.

# Memory Management

## Allocation:
- The database starts as NULL. The program uses realloc() to allocate space for a struct part whenever a new record is added.

## Resizing:
- When adding a record, the database is resized to hold numRecords + 1 elements.
- When deleting a record, the database is resized to hold numRecords - 1 elements.

## Deallocation:
- All allocated memory is freed at program exit.
- If the database has zero records, deletion will not work.
