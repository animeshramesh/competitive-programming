/*
Operations :
 - Insert an item 
 - Search for item
 - Delete item

 Linear Probing -> Searching next empty location in hashtable
*/

int SIZE = 20;


struct Item{
	int data, key;
}

int getHashIndex(int key)
{
	return key % SIZE;
}

void initHashTable(struct Item * arr)
{	
	Item dummy;
	dummy -> key = -1;

	for (int i = 0; i < SIZE; i++)
		arr[i] = dummy;
}

void insertItem(struct Item * arr, int data, int key)
{
	Item newItem;
	newItem -> data = data;
	newItem -> key = key;

	int hashIndex = getHashIndex(key);
	
	//move in array until an empty cell
   while(arr[hashIndex]->key != -1){
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   arr[hashIndex] = newItem;
}

// Find by key
struct Item search(struct Item * arr, int key)
{
	int hashIndex = getHashIndex(key);

	while(arr[hashIndex]->key != -1)
	{
		if (arr[hashIndex]->key == key) return arr[hashIndex];
		hashIndex++;

		hashIndex %= SIZE;
	}

	return NULL;
}

struct Item delete(struct Item * arr, struct Item item){
   int key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty 
   while(arr[hashIndex]->key != -1){
	
      if(arr[hashIndex]->key == key){
         struct Item temp = arr[hashIndex]; 
			
         //assign a dummy at deleted position
         arr[hashIndex]->key = -1; 
         return temp;
      } 

      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }  	
   return NULL;        
}


