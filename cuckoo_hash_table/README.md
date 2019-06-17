# cpp-projects
Created 6/17/2019

Problem: Creating Cuckoo Hash Table data structure

Resource: https://www.geeksforgeeks.org/cuckoo-hashing/

Inputs & Outputs:
    Example Input 1: {20, 50, 53, 75, 100, 67, 105, 3, 36, 39}

    Example Output 1:
        -	100	-	36	-	-	50	-	-	75	-
        3	20	-	39	53	-	67	-	-	105	-

    Example Input 2: {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6}

    Example Output 2:
        -	67	-	3	-	-	39	-	-	53	-
        6	20	-	36	50	-	75	-	-	100	-

Approach:
    The Cuckoo Hash Table has a basic structure that is described in the resource link.
    The key idea here is that whenever a new item is inserted,
    it would act like a Cuckoo bird, kicking existing item away.
    This would result in a chain reaction, but knowing when to stop is a problem.
    To resolve knowing when to stop the chain reaction,
    the approach is that once a certain number of kicking occurred,
    currently carrying item will be dropped.
    By default, and as implemented in the data structure,
    Cuckoo kicking limit is set to the number of items in a row.


Scratch of Pseudo code:
    place(KEY, TO INDEX, count, hash function labeled) {
        if count == 0 {
            RETURN ERROR, item is dropped.
        }
        else if THE SPACE IS EMPTY {
            place item;
        }
        else {
            place item
            get key that occupies that SPACE
            hash function
            call place(new Key, from TO Index, to Hash Index)
        }
    }
