class HashEntry:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class Dictionary:
    def __init__(self, capacity):
        self.capacity = capacity
        self.table = [[] for _ in range(capacity)]

    def hash_function(self, key):
        # Compute the hash value based on the key
        # You can use any hash function suitable for your keys
        # Here, we use the built-in hash function and modulo operator
        return hash(key) % self.capacity

    def insert(self, key, value):
        index = self.hash_function(key)
        for entry in self.table[index]:
            if entry.key == key:
                # Key already exists, update the value
                entry.value = value
                return
        # Key does not exist, add a new entry
        self.table[index].append(HashEntry(key, value))

    def find(self, key):
        index = self.hash_function(key)
        for entry in self.table[index]:
            if entry.key == key:
                # Key found, return the corresponding value
                return entry.value
        # Key not found, raise an exception
        raise KeyError("Key not found in the dictionary.")

    def delete(self, key):
        index = self.hash_function(key)
        for entry in self.table[index]:
            if entry.key == key:
                # Key found, remove the entry
                self.table[index].remove(entry)
                return
        # Key not found, do nothing or raise an exception


# Create a dictionary with capacity 10
dict = Dictionary(10)

# Insert key-value pairs
dict.insert("apple", 5)
dict.insert("banana", 3)
dict.insert("orange", 7)

# Find values by keys
try:
    value1 = dict.find("apple")
    value2 = dict.find("banana")
    value3 = dict.find("orange")
    print(f"Values: {value1}, {value2}, {value3}")
except KeyError as e:
    print(e)

# Delete a key-value pair
dict.delete("banana")

# Try to find the deleted key (should raise an exception)
try:
    dict.find("banana")
except KeyError as e:
    print(e)