#include "stdafx.h"
#include "LRUCache.h"

LRUCache::LRUCache(int capacity) {
	LRUcapacity = capacity;
}

int LRUCache::get2(int key)
{
	if (LRUmap[key] > 0)
	{
		if (firstKey == key)
		{ 
			return LRUmap[key];
		}
		else if (lastKey == key)
		{
			lastKey = LRUHead[lastKey];
			LRUHead[LRUTail[lastKey]] = 0;
			LRUTail[lastKey] = 0;
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;	// key Head to 0
		}
		else
		{
			LRUTail[LRUHead[key]] = LRUTail[key];
			LRUHead[LRUTail[key]] = LRUHead[key];
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;
		}
		
		return LRUmap[key];
	}
	return -1;
}

void LRUCache::put2(int key, int value)
{
	if (LRUmap[key] == 0)	// New Key
	{
		LRUmap[key] = value;
		if (size < LRUcapacity) // Has Position can put
		{
			// first Key head
			if (firstKey == 0)	// The first Key
			{
				firstKey = key;
				lastKey = key;
				LRUHead[key] = 0;
				LRUTail[key] = 0;
			}
			else				// Not the first
			{
				LRUHead[firstKey] = key;
				// record key tail to whom
				LRUTail[key] = firstKey;
				firstKey = key;
				LRUHead[key] = 0;	// key Head to 0
			}
			size++;
		}
		else					// Full Position has to remove the last one
		{
			if (LRUcapacity == 1)
			{
				LRUmap[lastKey] = 0;
				firstKey = key;
				lastKey = key;
				LRUHead[key] = 0;
				LRUTail[key] = 0;
			}
			else
			{
				// remove Last one 
				LRUmap[lastKey] = 0;
				lastKey = LRUHead[lastKey];
				LRUHead[LRUTail[lastKey]] = 0;
				LRUTail[lastKey] = 0;
				// insert to First one
				LRUHead[firstKey] = key;
				// record key tail to whom
				LRUTail[key] = firstKey;
				firstKey = key;
				LRUHead[key] = 0;	// key Head to 0
			}
		}
	}
	else					// Exist Key
	{
		LRUmap[key] = value;
		if (firstKey == key)
		{
			return;
		}
		else if (lastKey == key)
		{
			lastKey = LRUHead[lastKey];
			LRUHead[LRUTail[lastKey]] = 0;
			LRUTail[lastKey] = 0;
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;	// key Head to 0
		}
		else
		{
			LRUTail[LRUHead[key]] = LRUTail[key];
			LRUHead[LRUTail[key]] = LRUHead[key];
			// insert to First one
			LRUHead[firstKey] = key;
			// record key tail to whom
			LRUTail[key] = firstKey;
			firstKey = key;
			LRUHead[key] = 0;
		}
	}
}

void LRUCache::put3(int key, int value)
{
	if (size < LRUcapacity)
	{
		if (LRUmap[key] != 0)
		{
			LRUmap[key] = value;
			
			if (lastKey != key)
			{
				LRUTail[LRUHead[key]] = LRUTail[key];
				LRUHead[LRUTail[key]] = LRUHead[key];
				LRUHead[firstKey] = key;
				LRUHead[key] = 0;
				LRUTail[key] = firstKey;
				firstKey = key;
				lastKey = LRUHead[lastKey];
			}
		}
		else
		{
			LRUmap[key] = value;
			if (size == 0)
			{
				LRUHead[key] = 0;
				LRUTail[key] = 0;
				firstKey = key;
				preKey = key;
				lastKey = key;
			}
			else
			{
				LRUHead[preKey] = key;
				LRUTail[key] = preKey;
				firstKey = key;
				preKey = key;
			}
			size++;
		}
		
	}
	else
	{
		if (LRUmap[key] != 0)
		{
			if (lastKey == key)
			{
				lastKey = LRUHead[lastKey];
				LRUTail[LRUHead[key]] = LRUTail[key];
				LRUHead[firstKey] = key;
				LRUHead[key] = 0;
				LRUTail[key] = firstKey;
				firstKey = key;
			}
			else
			{
				LRUTail[LRUHead[key]] = LRUTail[key];
				LRUHead[LRUTail[key]] = LRUHead[key];
				LRUHead[firstKey] = key;
				LRUHead[key] = 0;
				LRUTail[key] = firstKey;
				firstKey = key;
			}
		}
		else
		{
			LRUmap[lastKey] = 0;
			lastKey = LRUHead[lastKey];
			LRUTail[lastKey] = 0;
			LRUHead[firstKey] = key;
			LRUHead[key] = 0;
			LRUTail[key] = firstKey;
			firstKey = key;
		}
		LRUmap[key] = value;
	}
}

int LRUCache::get(int key) 
{
	for (list<LRU>::iterator it = LRUlist->begin(); it != LRUlist->end(); it++)
	{
		if (it->key == key)
		{
			int result = it->value;
			LRU temp = LRU(it->key, it->value);
			LRUlist->erase(it);
			LRUlist->push_front(temp);
			return result;
		}
	}
	return -1;
}

void LRUCache::put(int key, int value) {

	if (LRUlist->size() < LRUcapacity)
	{
		for (list<LRU>::iterator it = LRUlist->begin(); it != LRUlist->end(); it++)
		{
			if (it->key == key)
			{
				it->value = value;
				LRU temp = LRU(it->key, it->value);
				LRUlist->erase(it);
				LRUlist->push_front(temp);
				return;
			}
		}
		LRUlist->push_front(LRU(key, value));
	}
	else
	{
		for (list<LRU>::iterator it = LRUlist->begin(); it != LRUlist->end(); it++)
		{
			if (it->key == key)
			{
				it->value = value;
				LRU temp = LRU(it->key, it->value);
				LRUlist->erase(it);
				LRUlist->push_front(temp);
				return;
			}
		}
		LRUlist->pop_back();
		LRUlist->push_front(LRU(key, value));
	}
}
