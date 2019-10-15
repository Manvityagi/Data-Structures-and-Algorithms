// Load Factor
// When the total number of items in hashmap goes on increasing keeping the default initial capacity of hashmap 16, At one point of time,
// hashmap performance will start degrading and need to increase buckets for improving performance.
// Load Factor is a measure, which decides when exactly to increase the hashmap capacity(buckets) to maintain get and put operation complexity of O(1).
// Default load factor of Hashmap is 0.75f (i.e 75% of current map size).
// You can also say, load factor is a measure "Till what load, hashmap can allow elements to put in it before its capacity is automatically increased"



// When the size of hashmap is changed, the process of re-calculating the hashcode of already placed key-value pair again is known as Rehashing.
// Rehashing is done to distribute items across the new length hashmap, so that get and put operation time complexity remains O(1).




#include<string>

template<typename V>
class MapNode{
	public:
	string key;
	V value;
	MapNode<V>* next;
	MapNode(string key, V value){
		this->key = key;
		this->value = value;
		next = NULL;
	}
};

template<typename V>
class HashMap{
	
	// Dynamically
	MapNode<V>** bucket;
	int count; // Number of key value pairs inserted in map
	int bucketSize; // Size of bucket Array

	public:
	HashMap(){
		bucketSize = 10;
		count = 0;
		bucket  =	new MapNode<V>*[bucketSize];	
		for(int i = 0; i < bucketSize; i++){
			bucket[i] = NULL;
		}
	}

	int size(){
		return count;
	}

	// Hash Function
	int getBucketIndex(string key){
		// Hashcode
		long hashCode = 0;
		long currentFactor = 1;
		for(int i = key.size() - 1; i >= 0; i--){
			hashCode += key[i] * currentFactor;
			currentFactor *= 37;
		}
		// Compress
		return hashCode % bucketSize;
	}

	V search(string key){
			
		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = bucket[bucketIndex];
		if(head == NULL){
			// key does not exist
			return 0;
		}
		MapNode<V>* temp = head;
		while(temp != NULL){
			if(temp->key == key){
				// Found 
				return temp->value;
			}
			temp = temp->next;
		}
		// Key doesn't exist
		return 0;	
	}

	void insert(string key, V value){

		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = bucket[bucketIndex];
		if(head == NULL){
			// key does not exist
			MapNode<V>* newNode = new MapNode<V>(key, value);
			// Bakwas head = newNode;
			bucket[bucketIndex] = newNode;
			count++;
		}else{
			MapNode<V>* temp = head;
			MapNode<V>* prev = NULL;
			while(temp != NULL){
				if(temp->key == key){
				// Found -> Override value 
					temp->value = value;
					return;
				}
				prev = temp;
				temp = temp->next;
			}
			// Insert at End
			MapNode<V>* newNode = new MapNode<V>(key, value);
			prev->next = newNode;	
			count++;
		}
		
		double loadFactor = (1.0* count) / bucketSize;
		if(loadFactor >= 0.75){
			rehash();
		}

	}

	void erase(string key){

		int bucketIndex = getBucketIndex(key);
		MapNode<V>* head = bucket[bucketIndex];
		if(head == NULL){
			return;
		}
		MapNode<V>* temp = head;
		MapNode<V>* prev = NULL;
		while(temp != NULL){
			if(temp->key == key){
				if(prev == NULL){
					bucket[bucketIndex] = temp->next;
				}else{
					prev->next = temp->next;
				}	
				count--;
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		}

	}
	
	void rehash(){

		MapNode<V>** temp = bucket;
		bucket = new MapNode<V>*[2 * bucketSize];
		
		bucketSize = bucketSize * 2;
		for(int i = 0; i < bucketSize; i++){
			bucket[i] = NULL;
		}
		count = 0;
		for(int i = 0; i < bucketSize / 2; i++){
			MapNode<V>* head = temp[i];
			while(head != NULL){
				insert(head->key, head->value);
				MapNode<V>* temp2 = head;
				head = head->next;
				delete temp2;	
			}
		}
	}
};


