### Collision Handling
Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision and must be handled using some collision handling technique. Following are the ways to handle collisions:

-   Chaining: The idea is to make each cell of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.

-   Open Addressing 
Like separate chaining, open addressing is a method for handling collisions. In Open Addressing, all elements are stored in the hash table itself. So at any point, the size of the table must be greater than or equal to the total number of keys (Note that we can increase table size by copying old data if needed). 

Insert(k): Keep probing until an empty slot is found. Once an empty slot is found, insert k. 

Search(k): Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached. 

Delete(k): Delete operation is interesting. If we simply delete a key, then the search may fail. So slots of deleted keys are marked specially as “deleted”. 
The insert can insert an item in a deleted slot, but the search doesn’t stop at a deleted slot. 

https://www.geeksforgeeks.org/hashing-set-3-open-addressing/


### Load Factor
When the total number of items in hashmap goes on increasing keeping the default initial capacity of hashmap 16, At one point of time,
hashmap performance will start degrading and need to increase buckets for improving performance.
Load Factor is a measure, which decides when exactly to increase the hashmap capacity(buckets) to maintain get and put operation complexity of O(1).
Default load factor of Hashmap is 0.75f (i.e 75% of current map size).
You can also say, load factor is a measure "Till what load, hashmap can allow elements to put in it before its capacity is automatically increased"

When the size of hashmap is changed, the process of re-calculating the hashcode of already placed key-value pair again is known as Rehashing.
Rehashing is done to distribute items across the new length hashmap, so that get and put operation 

Read Closed Hashing from here: 
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/
