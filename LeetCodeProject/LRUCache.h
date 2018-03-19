#pragma once

#include <stdlib.h>
#include <list>
#include <map>
#include <queue>

using namespace std;

class LRUCache
{
private:
	struct LRU
	{
		int key;
		int value;
		LRU(int LRUkey, int LRUvalue) : key(LRUkey), value(LRUvalue)
		{}
	};

	int LRUcapacity = 0;
	list<LRU> *LRUlist = new list<LRU> ();
	map<int, int> LRUmap;
	map<int, int> LRUHead;
	map<int, int> LRUTail;
	int lastKey = 0, firstKey = 0;
	int size = 0;
	//queue<int> *LRUqueue = new queue<int>();

public:

	LRUCache(int capacity);
	int get(int key);
	void put(int key, int value);
	int get2(int key);
	void put2(int key, int value);
	void put3(int key, int value);
};